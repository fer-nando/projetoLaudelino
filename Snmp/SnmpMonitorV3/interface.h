#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>

using namespace std;
class Interface
{
private:
    int status;
    string name;
    string type;
    int bwIn;
    int bwOut;
public:
    void setStatus(int);
    void setName(string);
    void setType(string);
    void setBwIn(int);
    void setBwOut(int);
    int getBwIn();
    int getBwOut();
    int getStatus();
    string getName();
    string getType();
    Interface(string name, string type);
};
#endif // INTERFACE_H
