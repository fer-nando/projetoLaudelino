#ifndef LINKWINDOW_H
#define LINKWINDOW_H

#include <QMainWindow>
#include <vector>
#include "management.h"
#include "device.h"
#include "interface.h"

using namespace std;

namespace Ui {
    class LinkWindow;
}

class LinkWindow : public QMainWindow
{
    Q_OBJECT
private:
    Device *dev1, *dev2;
    Interface *intf1, *intf2;
    Management* mgmt;
    Ui::LinkWindow *ui;
    bool removeLink;
public:
    explicit LinkWindow(QWidget *parent = 0);
    void setManagement(Management *mgmt);
    void setDevices(Device* dev1, Device* dev2);
    void setRemoveLink(bool remove);
    ~LinkWindow();
private slots:
    void on_buttonBoxOk();
    void on_buttonBoxCancel();
};

#endif // LINKWINDOW_H
