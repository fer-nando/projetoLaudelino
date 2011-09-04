#include "device.h"

Device::Device(string ip, string hostname, string type, string serie)
{
    Device::ip = ip;
    Device::hostname = hostname;
    Device::type = type;
    Device::serie = serie;
}

void Device::printDefault(){
    cout << ip << endl;
    cout << hostname << endl;
    cout << type << endl;
    cout << serie << endl;
    cout << "------" << endl;
}

void Device::print(){
    map<string,string>::iterator it;
    for(it = neighbors.begin();it != neighbors.end();++it){
        cout << it->first << ":" << it->second << endl;
    }
}

void Device::add(Interface intf,Device dev){
    neighbors.insert(pair<string,string>(intf.getName(),dev.getHostname()));
}

void Device::rm(Interface intf){
    map<string,string>::iterator it;
    it = neighbors.find(intf.getName());
    if(it != neighbors.end()){
        neighbors.erase(it);
    }
}

string Device::find(Interface intf){
    map<string,string>::iterator it;
    it = neighbors.find(intf.getName());
    if(it != neighbors.end()){
        return it->second;
    }else{
        return "";
    }
}

void Device::setX(int x){
    Device::x = x;
}

void Device::setY(int y){
    Device::y = y;
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

int Device::getX(){
    return x;
}

int Device::getY(){
    return y;
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

vector<Interface> Device::getInterfaces(){
    return interfaces;
}
