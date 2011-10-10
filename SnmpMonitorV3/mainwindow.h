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
    QPixmap *pixmapDefault;
    int x, y, X_MAX,Y_MAX, RECT_WIDTH, RECT_HEIGHT, X_OFFSET, Y_OFFSET;
    int pressedX, pressedY;
    bool moving;
    QRect *rect;
    Device *moveDevice,*dev;
    DeviceWindow* deviceWindow;
    LinkWindow* linkWindow;
    Ui::MainWindow *ui;
    Management *mgmt;
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
private slots:
    void on_newDeviceOk();
};

#endif // MAINWINDOW_H
