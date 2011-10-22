#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <QRect>
#include "interface.h"

using namespace std;

class Device{
private:
    string ip,hostname,upTime,type,serie;
    map<string,Device*> neighbors; // hash "neighbors[string] = device" util para mostrar as adjacencias!!!!!
    QRect *rect;    // Retangulo para detectar colisao e moves
    vector<Interface*> interfaces;
public:
    Device(string ip, string hostname,string type,string serie,int x, int y, int height, int width);
    void setInterfaceWired(Interface*,bool);
    void setPos(int x, int y);
    void setIp(string ip);
    void setHostname(string hostname);
    void setUpTime(string upTime);
    void setType(string type);
    void setSerie(string serie);
    void addDev(Interface* intf,Device* dev); // add no hash
    void addIntf(Interface* intf);
    void printDefault();
    void print();
    void printRect();
    void printInterfaces();
    string find(Interface* intf);
    string getIp();
    string getHostname();
    string getUpTime();
    string getType();
    string getSerie();
    vector<Interface*>& getInterfaces();
    QRect* getRect();
};

#endif // DEVICE_H
