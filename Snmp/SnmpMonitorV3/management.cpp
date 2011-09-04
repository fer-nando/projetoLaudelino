#include "management.h"

Management::Management()
{

}

void Management::printDefault(){
    vector<Device*>::iterator it;
    for(it = devices.begin();it!=devices.end();++it){
        Device *a = *(it);
        a->printDefault();
    }
}

void Management::createDevice(string ip, string host, string type, string serie){
    Device *dev = new Device(ip,host,type,serie);
    devices.push_back(dev);
}

void Management::verifyCord(int x, int y){

}
