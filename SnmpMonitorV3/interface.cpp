#include "interface.h"

Interface::Interface(string name, string type)
{
    Interface::name = name;
    Interface::type = type;
    Interface::status = 2;
    this->wired = false;
}

void Interface::setName(string name){
    Interface::name = name;
}

void Interface::setWired(bool wired){
    this->wired = wired;
}

bool Interface::getWired(){
    return wired;
}

void Interface::setStatus(int status){
    Interface::status = status;
}

void Interface::setType(string type){
    Interface::type = type;
}

void Interface::setBytesIn(int bytesIn){
    Interface::bytesIn = bytesIn;
}

void Interface::setBytesOut(int bytesOut){
    Interface::bytesOut = bytesOut;
}

int Interface::getStatus(){
    return status;
}

int Interface::getBytesIn(){
    return bytesIn;
}

int Interface::getBytesOut(){
    return bytesOut;
}

string Interface::getName(){
    return name;
}

string Interface::getType(){
    return type;
}
