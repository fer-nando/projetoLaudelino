#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMouseEvent>
#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QPixmap>
#include <QColor>
#include <QPen>
#include <QLabel>
#include <QPoint>
#include <QKeyEvent>
#include <QString>
#include <vector>
#include <QGraphicsScene>
#include <QRect>
#include <QGraphicsItem>
#include <QPainterPath>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QMouseEvent>
#include "devicewindow.h"
#include "management.h"
#include "linkwindow.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPixmap *pixmapSwitch, *pixmapRouter;
    int x, y, X_MAX, Y_MAX, RECT_WIDTH, RECT_HEIGHT, X_OFFSET, Y_UPPER_OFFSET, Y_LOWER_OFFSET;
    int pressedX, pressedY;
    bool moving;
    bool flagSave;
    QRect *rect;
    Device *moveDevice,*dev,*selectedDevice;
    DeviceWindow* deviceWindow;
    LinkWindow* linkWindow;
    Ui::MainWindow *ui;
    Management *mgmt;
    vector<QLabel*> label_Intf;

    void setupDeviceTab();
public: 
    explicit MainWindow(QWidget *parent = 0);
    bool isInsideArea();
    void myInit();
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);
private slots:
    void forceRepaint();
    void openEvent();
    void saveEvent();
    void editEvent();
    void killTopologyEvent();
};

#endif // MAINWINDOW_H
