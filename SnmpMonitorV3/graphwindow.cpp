#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <qwt/qwt_scale_draw.h>


class TimeScaleDraw: public QwtScaleDraw
{
public:
    TimeScaleDraw(const QDateTime &base):
        baseTime(base)
    {
    }
    virtual QwtText label(double v) const
    {
        QDateTime upTime = baseTime.addSecs((int)v);
        return upTime.toString("yyyy-MM-dd \n hh:mm:ss");
    }
private:
    QDateTime baseTime;
};

GraphWindow::GraphWindow(Device* d, Management *m, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

    mgmt = m;
    dev = d;

    // Configura o titulo e eixos esquerdo
    ui->qwtPlot->setTitle("Fluxo de dados");
    ui->qwtPlot->setAxisTitle(QwtPlot:: yLeft, " Bytes ");

    // Configura eixo inferior
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, " System Uptime ");
    ui->qwtPlot->setAxisLabelRotation(QwtPlot::xBottom, -50.0);
    ui->qwtPlot->setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);

    // Insere legenda
    QwtLegend *legend = new QwtLegend;
    legend->setItemMode(QwtLegend::ReadOnlyItem);
    ui->qwtPlot->insertLegend(legend, QwtPlot::RightLegend);

    // Adiciona itens no combo box
    vector<Interface*>::iterator it;
    for(it = dev->getInterfaces().begin(); it != dev->getInterfaces().end(); ++it){
        ui->cb_intf->addItem(QString::fromStdString((*it)->getName()));
    }

    // Configura curva de bytes in e adiciona no plot
    curveBI = new QwtPlotCurve("Bytes in");
    c = QColor(0, 0, 255, 150);
    curveBI->setPen(c);
    curveBI->setBrush(c);
    curveBI->attach(ui->qwtPlot);

    // Configura curva de bytes out e adiciona no plot
    curveBO = new QwtPlotCurve("Bytes out");
    c = QColor(255, 0, 0, 150);
    curveBO->setPen(c);
    curveBO->setBrush(c);
    curveBO->attach(ui->qwtPlot);

    // Configura a data de inicio e fim
    ui->dateBegin->setDate(QDate(2010, 01, 01));
    ui->dateEnd->setDate(QDate().currentDate());

    displayGraph();

    connect(ui->cb_intf, SIGNAL(currentIndexChanged(QString)), this, SLOT(redraw()));
    connect(ui->dateBegin, SIGNAL(dateChanged(QDate)), this, SLOT(redraw()));
    connect(ui->dateEnd, SIGNAL(dateChanged(QDate)), this, SLOT(redraw()));
}

void GraphWindow::displayGraph() {
    QString beginDate = ui->dateBegin->text();// tem que ser nesse formato "yyyy-mm-dd HH:MM:ss" OU entao somente "2009-01-01" sem as HH:MM:SS
    QString endDate = ui->dateEnd->text();
    QString host = QString::fromStdString(dev->getHostname());
    QString intfName = ui->cb_intf->currentText();
    mgmt->query(beginDate, endDate, host, intfName);

    bytesIn.clear();
    bytesOut.clear();
    dates.clear();
    interval.clear();

    bytesIn = mgmt->getBytesIn();
    bytesOut = mgmt->getBytesOut();
    dates = mgmt->getDate();
    interval.push_back(0);
    for(int i = 0; i < bytesIn.size()-1; i++) {
        cout << "interval: " << dates.at(0).secsTo(dates.at(i)) << endl;
        interval.push_back(double(dates.at(0).secsTo(dates.at(i))));
    }

    if(bytesIn.size() > 0) {
        ui->qwtPlot->setAxisScaleDraw(QwtPlot::xBottom,
            new TimeScaleDraw(dates.at(0)));
    }

    curveBI->setData(interval, bytesIn);
    curveBO->setData(interval, bytesOut);

    ui->qwtPlot->replot();

}

void GraphWindow::redraw() {
    displayGraph();
}


GraphWindow::~GraphWindow()
{
    delete ui;
}
