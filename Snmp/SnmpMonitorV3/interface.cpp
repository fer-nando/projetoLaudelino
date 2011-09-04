#include "interface.h"

Interface::Interface(string name, string type)
{
    Interface::name = name;
    Interface::type = type;
}

void Interface::setName(string name){
    Interface::name = name;
}

void Interface::setStatus(int status){
    Interface::status = status;
}

void Interface::setType(string type){
    Interface::type = type;
}

void Interface::setBwIn(int bwIn){
    Interface::bwIn = bwIn;
}

void Interface::setBwOut(int bwOut){
    Interface::bwOut = bwOut;
}

int Interface::getStatus(){
    return status;
}

int Interface::getBwIn(){
    return bwIn;
}

int Interface::getBwOut(){
    return bwOut;
}

string Interface::getName(){
    return name;
}

string Interface::getType(){
    return type;
}
