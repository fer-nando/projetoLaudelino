#include "link.h"

Link::Link(Device *dev1, Interface *intf1, Device *dev2, Interface *intf2)
{
    this->dev1 = dev1;
    this->dev2 = dev2;
    this->intf1 = intf1;
    this->intf2 = intf2;
    this->lineDeltaX = 0;
    this->lineDeltaY = 0;
}

void Link::printLink(){
    cout << "\t Dev1: " << dev1->getHostname() << " Intf1: " << intf1->getName() << " Dev2: " << dev2->getHostname() << " Intf2: " << intf2->getName() << endl;
}

void Link::setLineDeltaX(int deltaX){
    lineDeltaX = deltaX;
}

void Link::setLineDeltaY(int deltaY){
    lineDeltaY = deltaY;
}

int Link::getLineDeltaX(){
    return lineDeltaX;
}

int Link::getLineDeltaY(){
    return lineDeltaY;
}

Device* Link::getDev1(){
    return dev1;
}

Device* Link::getDev2(){
    return dev2;
}

Interface* Link::getIntf1(){
    return intf1;
}

Interface* Link::getIntf2(){
    return intf2;
}
