#ifndef LINK_H
#define LINK_H

#include <iostream>
#include "interface.h"
#include "device.h"

using namespace std;

class Link
{
private:
    int lineDeltaX, lineDeltaY; // variaveis para incrementar um delta no x e y, para que o links reduntantes nao se sobreponham quando for desenhar as linhas!
    Device *dev1, *dev2;
    Interface *intf1, *intf2;
public:
    Link(Device *dev1, Interface* intf1, Device *dev2, Interface *intf2);
    void printLink();
    void setLineDeltaX(int deltaX);
    void setLineDeltaY(int deltaY);
    int getLineDeltaX();
    int getLineDeltaY();
    Device* getDev1();
    Device* getDev2();
    Interface* getIntf1();
    Interface* getIntf2();
};

#endif // LINK_H
