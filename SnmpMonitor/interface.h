#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>

using namespace std;
class Interface
{
private:
    bool wired;
    int status;
    string name;
    string type;
    int bytesIn;
    int bytesOut;
public:
    void setWired(bool);
    void setStatus(int);
    void setName(string);
    void setType(string);
    void setBytesIn(int);
    void setBytesOut(int);
    int getBytesIn();
    int getBytesOut();
    int getStatus();
    bool getWired();
    string getName();
    string getType();
    Interface(string name, string type);
};
#endif // INTERFACE_H
