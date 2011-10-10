#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include <string>
#include "device.h"
#include "link.h"

using namespace std;

class Management
{
private:
    int counterRedundant;
    vector<Device*> devices;
    vector<Link*> links;
public:
    Management();
    void move(Device* dev, int pressedX, int pressedY, int x, int y);
    bool removeLinkFrom(Device* dev);
    void createInterface(Device* dev, string name, string type);
    void removeDevice(Device *dev);
    bool rectCollision(int x, int y, int height, int width);
    bool removeLink(Device *dev1, Interface* intf1, Device* dev2, Interface* intf2);
    bool removeDeviceFrom(Device *dev);
    bool existInterface(Device* dev, Interface* intf);
    bool existHostname(string hostname);
    void verifyRedundantLink(Link *l);
    void setManagement(Management* mgmt);
    void printDefault();
    void printRect();
    void printLinks();
    void createLink(Device *dev1, Interface *intf1, Device *dev2, Interface *intf2);
    Device* verifyClickCollision(int x, int y);
    Device* createDevice(string ip, string host, string type, string serie, int x, int y, int height, int width);
    vector<Device*>& getDevices();
    vector<Link*>& getLinks();
};

#endif // MANAGEMENT_H
