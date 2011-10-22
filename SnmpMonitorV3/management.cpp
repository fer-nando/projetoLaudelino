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

string Management::subStrInterfaceType(string str){
    return str.substr(0,2); // indice 0 ate 2 (0 e 1 inclusive)
}

bool Management::existStrLinkMismatch(Interface *intf1,Interface* intf2){ // unica incompatibilidade eh serial com fa ou gi
    if(intf1->getType().compare("Se") == 0 && (intf2->getType().compare("Fa") || intf2->getType().compare("Gi"))){ // Serial eh incompativel com Fa e Gi
        return true;
    }else if(intf2->getType().compare("Se") == 0 && (intf1->getType().compare("Fa") || intf1->getType().compare("Gi"))){
        return true;
    }
    return false;
}

void Management::writeTopology(){
    //Device* createDevice(string ip, string host, string type, string serie, int x, int y, int height, int width);
    ofstream myfile ("topology.txt");
    if (myfile.is_open()) {
        vector<Device*>::iterator it;
        for(it = devices.begin();it!=devices.end();++it){
            myfile << "Device\n";
            string str;
            string aux = ",";
            str.append((*it)->getIp());
            str.append(aux);
            str.append((*it)->getHostname());
            str.append(aux);
            str.append((*it)->getType());
            str.append(aux).append((*it)->getSerie());
            str.append(aux);
            str.append(QString::number((*it)->getRect()->x()).toStdString());
            str.append(aux);
            str.append(QString::number((*it)->getRect()->y()).toStdString());
            str.append(aux);
            str.append(QString::number((*it)->getRect()->height()).toStdString());
            str.append(aux);
            str.append(QString::number((*it)->getRect()->width()).toStdString());
            str.append("\n");
            vector<Interface*>::iterator itr;
            for(itr = (*it)->getInterfaces().begin(); itr != (*it)->getInterfaces().end(); ++itr){
                str.append("Interface\n");
                str.append((*itr)->getName());
                str.append("\n");
            }
            myfile << str;
        }
        vector<Link*>::iterator i;
        for(i = links.begin();i!=links.end();++i){
              myfile << "Link\n";
              string str;
              string aux = ",";
              str.append((*i)->getDev1()->getHostname());
              str.append(aux);
              str.append((*i)->getIntf1()->getName());
              str.append(aux);
              str.append((*i)->getDev2()->getHostname());
              str.append(aux);
              str.append((*i)->getIntf2()->getName());
              str.append("\n");
              myfile << str;
        }
        myfile.close();
      }
      else cout << "Unable to open file";
}

void Management::readTopology(){
     string line;
     ifstream myfile ("topology.txt");
     bool flagDevice = false;
     bool flagInterface = false;
     bool flagLink = false;
     Device* dev;
     if (myfile.is_open()){
           while ( myfile.good() ){
                 getline (myfile,line);
                 if(flagDevice){
                      cout << "device: " << line << endl;
                      QString qstr;
                      QString *array = new QString[8];
                      QStringList qsltr = QString::fromStdString(line).split(",");
                      QStringList::const_iterator constIterator;
                      int j=0;
                      for (constIterator = qsltr.constBegin(); constIterator != qsltr.constEnd();++constIterator,j++){
                              qstr = (*constIterator).toLocal8Bit().constData();
                              array[j] = qstr;
                              //cout << qstr.toStdString() << endl;
                      }
                      dev = createDevice(array[0].toStdString(),array[1].toStdString(),array[2].toStdString(),array[3].toStdString(),array[4].toInt(),array[5].toInt(),array[6].toInt(),array[7].toInt());
                 }
                 if(flagInterface){
                      cout << "interface: " << line << endl;
                      Interface *intf = new Interface(line,subStrInterfaceType(line));
                      dev->addIntf(intf);
                 }
                 if(flagLink){
                     cout << line << endl;
                     QString qstr;
                     string *array = new string[4];
                     QStringList qsltr = QString::fromStdString(line).split(",");
                     QStringList::const_iterator constIterator;
                     int j=0;
                     for (constIterator = qsltr.constBegin(); constIterator != qsltr.constEnd();++constIterator,j++){
                             qstr = (*constIterator).toLocal8Bit().constData();
                             array[j] = qstr.toStdString();
                             cout << array[j] << endl;
                             //cout << qstr.toStdString() << endl;
                     }
                     Device *dev1,*dev2;
                     Interface *intf1,*intf2;
                     intf1 = new Interface(array[1],subStrInterfaceType(array[1]));
                     intf2 = new Interface(array[3],subStrInterfaceType(array[3]));
                     vector<Device*>::iterator itt;
                     for(itt = devices.begin();itt!=devices.end();++itt){
                         cout << (*itt)->getHostname() << endl;
                         if((*itt)->getHostname().compare(array[0]) == 0){ //array[0] dev1hostname
                             dev1 = *(itt);
                         }if((*itt)->getHostname().compare(array[2]) == 0){ //array[2] dev2hostname
                             dev2 = *(itt);
                         }
                     }
                     dev1->setInterfaceWired(intf1,true);
                     dev2->setInterfaceWired(intf2,true);
                     dev1->addDev(intf1,dev2); // para mostrar adj dps
                     dev2->addDev(intf2,dev1); // para mostrar adj dps
                     createLink(dev1,intf1,dev2,intf2);
                 }
                 if(line.compare("Device") == 0){
                     flagDevice = true;
                 }else{
                     flagDevice = false;
                 }
                 if(line.compare("Interface") == 0){
                     flagInterface = true;
                 }else{
                     flagInterface = false;
                 }
                 if(line.compare("Link") == 0){
                     flagLink = true;
                 }else{
                     flagLink = false;
                 }
           }
           myfile.close();
     }
     else cout << "Unable to open file";
}

bool Management::regexIP(string ip){
    QRegExp regex("(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)");
    bool isValidRegex = regex.exactMatch(QString::fromStdString(ip));
    bool isValidNumbers = false; // parte do pressuposto que eh false
    QString *array = new QString[4];
    if(isValidRegex){
        for(int i=1;i<=4;i++){
            array[i-1] = regex.cap(i);
            int temp = array[i-1].toInt();
            if(temp >=0  && temp <= 255){
                isValidNumbers = true;
                continue;
            }
            break;
            isValidNumbers = false;
        }
    }
    return isValidNumbers;
}

bool Management::regexInterfaceName(Interface *intf){
    QRegExp regex("(Fa\\d/\\d+)|((Gi\\d/\\d+)|(Se\\d/\\d+)|(Se\\d/\\d/\\d+))");
    return regex.exactMatch(QString::fromStdString(intf->getName()));
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
                (*i)->getDev1()->setInterfaceWired((*i)->getIntf1(),false);
                (*i)->getDev2()->setInterfaceWired((*i)->getIntf2(),false);
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

bool Management::existIP(string ip){
    vector<Device*>::iterator it;
    for(it = devices.begin(); it!=devices.end(); ++it){
        if(ip.compare((*it)->getIp()) == 0){
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
