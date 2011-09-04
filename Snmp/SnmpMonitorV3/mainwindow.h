#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QString>
#include "management.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //bool routerBool, switchBool, delBool, wireBool, moveBool;
    Ui::MainWindow *ui;
    Management *mgmt;
private slots:
    void on_radioRouter();
    void on_radioSwitch();
    void on_radioMove();
    void on_radioWire();
    void on_radioDel();
    void on_buttonBoxOk();
    void on_buttonBoxCancel();
};

#endif // MAINWINDOW_H
