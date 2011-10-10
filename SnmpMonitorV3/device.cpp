#include "device.h"

Device::Device(string ip, string hostname, string type, string serie,int x, int y, int height, int width)
{
    Device::ip = ip;
    Device::hostname = hostname;
    Device::type = type;
    Device::serie = serie;
    rect = new QRect(x,y,height,width);
}

void Device::printDefault(){
    cout << "\t print Default device - begin " << endl;
    cout << "\t IP: " << ip << endl;
    cout << "\t host:" << hostname << endl;
    cout << "\t type: " << type << endl;
    cout << "\t serie: " << serie << endl;
    printInterfaces();
    cout << "\t print Default device - end " << endl;
    cout << endl;
}

void Device::setInterfaceWired(Interface *intf, bool wired){
    for(vector<Interface*>::iterator it = interfaces.begin(); it != interfaces.end(); ++ it){
        if((*it)->getName().compare(intf->getName()) == 0){
            (*it)->setWired(wired);
            return;
        }
    }
}

void Device::printInterfaces(){
    cout << "\t Interfaces: " << endl;
    for(vector<Interface*>::iterator it = interfaces.begin(); it != interfaces.end(); ++ it){
        cout << "\t " << (*it)->getName() <<  " wired: " << (*it)->getWired() <<endl;
    }
}

void Device::print(){
    map<string,Device*>::iterator it;
    for(it = neighbors.begin();it != neighbors.end();++it){
        cout << (it->first) << ":" << (it->second)->getHostname() << endl;
    }
}

void Device::printRect(){
    cout << "Rect x: " << rect->x() << " y: " << rect->y() << endl;
}

void Device::addDev(Interface* intf,Device* dev){
    neighbors.insert(pair<string,Device*>(intf->getName(),dev));
}

string Device::find(Interface* intf){
    map<string,Device*>::iterator it;
    it = neighbors.find(intf->getName());
    if(it != neighbors.end()){
        return (it->second)->getHostname();
    }else{
        return "";
    }
}

void Device::addIntf(Interface *intf){
    interfaces.push_back(intf);
}

void Device::setPos(int x, int y){
    rect->moveTo(x,y);
}

void Device::setIp(string ip){
    Device::ip = ip;
}

void Device::setHostname(string hostname){
    Device::hostname = hostname;
}

void Device::setUpTime(string upTime){
    Device::upTime = upTime;
}

void Device::setType(string type){
    Device::type = type;
}

void Device::setSerie(string serie){
    Device::serie = serie;
}

QRect* Device::getRect(){
    return rect;
}

string Device::getIp(){
    return ip;
}

string Device::getHostname(){
    return hostname;
}

string Device::getUpTime(){
    return upTime;
}

string Device::getType(){
    return type;
}

string Device::getSerie(){
    return serie;
}

vector<Interface*>& Device::getInterfaces(){
    return this->interfaces;
}
