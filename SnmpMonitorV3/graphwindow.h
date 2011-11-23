#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>
#include <vector>
#include "qwt/qwt_plot_curve.h"
#include "qwt/qwt_legend_item.h"
#include "device.h"
#include "management.h"
#include "interface.h"

namespace Ui {
    class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(Device *d, Management *m, QWidget *parent = 0);
    ~GraphWindow();
    void displayGraph();

private:
    QVector<double> bytesIn;
    QVector<double> bytesOut;
    QVector<double> interval;
    QVector<QDateTime> dates;
    QColor c;
    QwtPlotCurve *curveBI;
    QwtPlotCurve *curveBO;
    Device *dev;
    Management *mgmt;
    Ui::GraphWindow *ui;

private slots:
    void redraw();
};

#endif // GRAPHWINDOW_H
