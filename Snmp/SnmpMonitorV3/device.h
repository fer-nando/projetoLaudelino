#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "link.h"
#include "interface.h"

using namespace std;

class Device{
private:
    string ip,hostname,upTime,type,serie;
    vector<Interface> interfaces;
    map<string,string> neighbors;
    int x,y;
public:
    Device(string ip, string hostname,string type,string serie);
    void setX(int x);
    void setY(int y);
    void setIp(string ip);
    void setHostname(string hostname);
    void setUpTime(string upTime);
    void setType(string type);
    void setSerie(string serie);
    void add(Interface intf,Device dev);
    void rm(Interface intf);
    int getX();
    int getY();
    string find(Interface intf);
    string getIp();
    string getHostname();
    string getUpTime();
    string getType();
    string getSerie();
    vector<Interface> getInterfaces();
    void printDefault();
    void print();
};

#endif // DEVICE_H
