#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include <string>
#include "device.h"

using namespace std;

class Management
{
private:
    vector<Device*> devices;
public:
    void createDevice(string ip, string host, string type, string serie);
    void verifyCord(int x, int y);
    void printDefault();
    Management();
};

#endif // MANAGEMENT_H
