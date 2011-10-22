#ifndef DEVICEWINDOW_H
#define DEVICEWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QFont>
#include <string>
#include <iostream>
#include "device.h"
#include "interface.h"
#include "management.h"

using namespace std;

namespace Ui {
    class DeviceWindow;
}

class DeviceWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void windowClosed();
public:
    explicit DeviceWindow(QWidget *parent = 0);
    ~DeviceWindow();
    void setDevice(Device* dev);
    void setManagement(Management *mgmt);
    void setIsEdit(bool);
    void afterConstructor();
    void setType(string);
private:
    Device* device;
    Management* mgmt;
    bool isEdit;
    string ip, serie, type, hostname;
    Ui::DeviceWindow *ui;
private slots:
    void on_buttonBoxOk();
    void on_buttonBoxCancel();
};
#endif // DEVICEWINDOW_H
