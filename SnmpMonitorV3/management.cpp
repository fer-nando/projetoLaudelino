#include "management.h"

Management::Management(){
    counterRedundant = 0;
}

void Management::printRect(){
    cout << "printRect() begin :" << endl;
    vector<Device*>::iterator it;
    for(it = devices.begin();it!=devices.end();++it){
        Device *a = *(it);
        a->printRect();
    }
    cout << "printRect() end :" << endl;
}

void Management::printLinks(){
    cout << "printLinks() begin - :" << endl;
    vector<Link*>::iterator it;
    for(it = links.begin();it!=links.end();++it){
        (*it)->printLink();
    }
    cout << "printLinks() end - :" << endl;
}

bool Management::existInterface(Device* dev, Interface* intf){
    vector<Interface*>::iterator it;
    for(it = dev->getInterfaces().begin();it!=dev->getInterfaces().end();++it){
        if((*it)->getName().compare(intf->getName()) == 0){
            return true;
        }
    }
    return false;
}

bool Management::existHostname(string hostname){
    vector<Device*>::iterator it;
    for(it = devices.begin();it!= devices.end();++it){
        if(((*it)->getHostname().compare(hostname)) == 0){ // se ja existe algum host
            return true;
        }
    }
    return false;
}

void Management::verifyRedundantLink(Link *l){
    vector<Link*>::iterator it;
    for(it = links.begin();it!=links.end();++it){
        if(((l->getDev1()->getHostname().compare((*it)->getDev1()->getHostname()) == 0) && (l->getDev2()->getHostname().compare((*it)->getDev2()->getHostname())) == 0) || ((l->getDev2()->getHostname().compare((*it)->getDev1()->getHostname()) == 0) && (l->getDev1()->getHostname().compare((*it)->getDev2()->getHostname()))==0)){
            counterRedundant += 30;
            l->setLineDeltaX(counterRedundant);
            l->setLineDeltaY(counterRedundant);
        }
    }
}

void Management::createLink(Device *dev1, Interface *intf1, Device *dev2, Interface *intf2){
    Link *l = new Link(dev1,intf1,dev2,intf2);
    verifyRedundantLink(l);
    counterRedundant = 0;
    links.push_back(l);
}

void Management::printDefault(){
    cout << "mgmt - printDefault: -begin " << endl;
    vector<Device*>::iterator it;
    for(it = devices.begin();it!=devices.end();++it){
        Device *a = *(it);
        a->printDefault();
    }
    cout << "mgmt - printDefault: -end " << endl;
}

void Management::createInterface(Device* dev, string name, string type){
    Interface *intf = new Interface(name,type);
    dev->addIntf(intf);
}


void Management::move(Device* dev, int pressedX, int pressedY, int x, int y){
    dev->setPos(pressedX - x, pressedY - y);
}

// funcao que apaga todas os links de um device!
void Management::removeDevice(Device* dev){
    vector<Device*>::iterator it;
    for(it = devices.begin(); it!=devices.end(); ++it){
        if(dev->getHostname().compare((*it)->getHostname()) == 0){
                devices.erase(it);
                break;
        }
    }
    bool remove = true;
    while(remove){
        remove = removeLinkFrom(dev);
    }
}

bool Management::removeLinkFrom(Device *dev){
    vector<Link*>::iterator i;
    for( i= links.begin(); i!=links.end(); ++i){
        // se o device esta em alguma das DUAS pontas do link... APAGUE ESTE LINK!
        if( (dev->getHostname().compare(((*i)->getDev1())->getHostname()) == 0) || (dev->getHostname().compare(((*i)->getDev2())->getHostname()) == 0)){
                (*i)->getIntf1()->setWired(false);
                (*i)->getIntf2()->setWired(false);
                links.erase(i);
                return true;
        }
    }
    return false;
}

bool Management::rectCollision(int x, int y, int height, int width){
    QRect *rect = new QRect(x,y,height,width);
    Device *d;
    vector<Device*>::iterator it;
    for(it = devices.begin();it!=devices.end();++it){
        d = *it;
        if(rect->intersects(*(d->getRect()))){
            //cout << "colisao!" << endl;
            return true;
        }
    }
    return false;
}


bool Management::removeLink(Device *dev1, Interface* intf1, Device* dev2, Interface* intf2){
    // COMO o link eh formado por dev1, intf1, dev2, intf2, e eu nao sei a ordem de qual foi a ordem que o usuario selecionou na tela (o primeiro selecionado eh o dev1) para para criar o link @dev1,@intf1, @dev2, @intf2
    // tem que comparar @dev1 com dev1, @dev1 com dev2 para descobrir se este eh o link escolhido e na sequencia confere as interfaces, JAH QUE CADA LINK EH UNICO (devido a cada interface ser unica em um device)
    // entao a combinacao soh pode ser (@dev1 == dev1 E @dev2 == dev2) || (@dev1 == dev2 E @dev2 = dev1)
    vector<Link*>::iterator it;
    for( it= links.begin(); it!=links.end(); ++it){
        if(((dev1->getHostname().compare((*it)->getDev1()->getHostname()) == 0) && (dev2->getHostname().compare((*it)->getDev2()->getHostname())) == 0)){
            if(((intf1->getName().compare((*it)->getIntf1()->getName()) == 0) && (intf2->getName().compare((*it)->getIntf2()->getName())) == 0)){
                //cout << "first:" << dev1->find(intf1) << endl;
                dev1->setInterfaceWired(intf1,false); // setta a interface como NAO CONECTADA
                dev2->setInterfaceWired(intf2,false); // setta a interface como NAO CONECTADA
                links.erase(it);
                return true;
            }
        }
        if(((dev2->getHostname().compare((*it)->getDev1()->getHostname()) == 0) && (dev1->getHostname().compare((*it)->getDev2()->getHostname()))==0)){
            if(((intf2->getName().compare((*it)->getIntf1()->getName()) == 0) && (intf1->getName().compare((*it)->getIntf2()->getName())) == 0)){
                //cout << "second: " << dev2->find(intf2) << endl;
                dev1->setInterfaceWired(intf1,false); // setta a interface como NAO CONECTADA
                dev2->setInterfaceWired(intf2,false); // setta a interface como NAO CONECTADA
                links.erase(it);
                return true;
            }
        }
    }
    return false;
}

Device* Management::createDevice(string ip, string host, string type, string serie,int x, int y, int height, int width){
    Device *dev = new Device(ip,host,type,serie,x, y, height, width);
    devices.push_back(dev);
    return dev;
}

Device* Management::verifyClickCollision(int x, int y){
    vector<Device*>::iterator it;
    Device *d;
    for(it = devices.begin();it!=devices.end();++it){
        d = *it;
        if((d->getRect())->contains(x,y)){
            //cout << "colisao!" << endl;
            return (*it);
        }
    }
    return 0;
}

vector<Device*>& Management::getDevices(){
    return this->devices;
}

vector<Link*>& Management::getLinks(){
    return this->links;
}
