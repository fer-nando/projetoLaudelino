#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(Device* d, Management *m, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

    mgmt = m;
    dev = d;

    ui->qwtPlot->setTitle("Fluxo de dados");
    ui->qwtPlot->setAxisTitle( QwtPlot::xBottom, "Tempo");
    ui->qwtPlot->setAxisTitle(QwtPlot:: yLeft, "Bytes");

    QwtLegend *legend = new QwtLegend;
    legend->setItemMode(QwtLegend::ReadOnlyItem);
    ui->qwtPlot->insertLegend(legend, QwtPlot::RightLegend);

    vector<Interface*>::iterator it;
    for(it = dev->getInterfaces().begin(); it != dev->getInterfaces().end(); ++it){
        ui->cb_intf->addItem(QString::fromStdString((*it)->getName()));
    }

    displayGraph();

    ui->qwtPlot->setAutoReplot(true);

    connect(ui->cb_intf, SIGNAL(currentIndexChanged(QString)), this, SLOT(redraw()));
}

void GraphWindow::displayGraph() {
    QString beginDate = "2010-01-01"; // tem que ser nesse formato "yyyy-mm-dd HH:MM:ss" OU entao somente "2009-01-01" sem as HH:MM:SS
    QString endDate = "2015-01-01";
    QString host = QString::fromStdString(dev->getHostname());
    QString intfName = ui->cb_intf->currentText();
    mgmt->query(beginDate, endDate, host, intfName);

    bytesIn = mgmt->getBytesIn();
    bytesOut = mgmt->getBytesOut();
    dataTime.clear();
    for(int i = 0; i < bytesIn.size(); i++) {
        dataTime.push_back(i);
    }

    c = QColor(0, 0, 255, 150);
    curve_bi = new QwtPlotCurve(ui->cb_intf->currentText());
    curve_bi->setPen(c);
    curve_bi->setBrush(c);
    curve_bi->setData(dataTime, bytesIn);
    curve_bi->attach(ui->qwtPlot);

    c = QColor(255, 0, 0, 150);
    curve_bo = new QwtPlotCurve(ui->cb_intf->currentText());
    curve_bo->setPen(c);
    curve_bo->setBrush(c);
    curve_bo->setData(dataTime, bytesOut);
    curve_bo->attach(ui->qwtPlot);
}

void GraphWindow::redraw() {
    displayGraph();
}


GraphWindow::~GraphWindow()
{
    delete ui;
}
