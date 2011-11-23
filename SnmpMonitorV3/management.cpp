#include "management.h"

Management::Management(){
    connectDb(); // NOVO
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

void Management::updateStatusTopology(){ // 2 == Up -> 1 == Down
    int statusFromQuery;
    QString stringFromQuery;
    QSqlQuery query;
    //cout << "updateStatusTopology():" << endl;
    vector<Device*>::iterator it;
    for(it = devices.begin();it!=devices.end();++it){
       vector<Interface*>::iterator itf;
       for(itf = (*it)->getInterfaces().begin(); itf != (*it)->getInterfaces().end(); ++itf){
           QString queryStr = "select status from Interface where id_hostname = ";
           queryStr.append(formatString(QString::fromStdString((*it)->getHostname())));
           queryStr.append(" AND name = ");
           queryStr.append(formatString(QString::fromStdString((*itf)->getName())));
           query.exec(queryStr);
           while (query.next()) { // so entra uma vez.. eh um unico retorno que vem do select!
                stringFromQuery = query.value(0).toString();
           }
           //cout << queryStr.toStdString() << " -> status = " << stringFromQuery.toStdString() << endl;
           statusFromQuery = (stringFromQuery.compare("Down") == 0)? 1:2;
           (*itf)->setStatus(statusFromQuery);
       }
    }
}

bool Management::existStrLinkMismatch(Interface *intf1,Interface* intf2){ // unica incompatibilidade eh serial com fa ou gi
    if(intf1->getType().compare("Se") == 0 && (!intf2->getType().compare("Fa") || !intf2->getType().compare("Gi"))){ // Serial eh incompativel com Fa e Gi
        return true;
    }else if(intf2->getType().compare("Se") == 0 && (!intf1->getType().compare("Fa") || !intf1->getType().compare("Gi"))){
        return true;
    }
    return false;
}

void Management::writeTopology(){
    QSqlQuery query;
    query.prepare("truncate table Device");
    query.exec();
    query.prepare("truncate table Interface");
    query.exec();
    query.prepare("truncate table Link");
    query.exec();
    vector<Device*>::iterator it;
    for(it = devices.begin();it!=devices.end();++it){
        query.prepare("insert into Device (hostname,ip,type,serie,up_time,rect_x,rect_y,rect_height,rect_width) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(QString::fromStdString((*it)->getHostname()));
        query.addBindValue(QString::fromStdString((*it)->getIp()));
        query.addBindValue(QString::fromStdString((*it)->getType()));
        query.addBindValue(QString::fromStdString((*it)->getSerie()));
        query.addBindValue(QString::fromStdString((*it)->getUpTime()).toInt());
        query.addBindValue(QString::number((*it)->getRect()->x()));
        query.addBindValue(QString::number((*it)->getRect()->y()));
        query.addBindValue(QString::number((*it)->getRect()->height()));
        query.addBindValue(QString::number((*it)->getRect()->width()));
        query.exec();

        vector<Interface*>::iterator itr;
        for(itr = (*it)->getInterfaces().begin(); itr != (*it)->getInterfaces().end(); ++itr){
                query.prepare("insert into Interface (type,status,name,id_hostname) VALUES (?, ?, ?, ?)");
                query.addBindValue(QString::fromStdString(subStrInterfaceType((*itr)->getName())));
                if((*itr)->getStatus() == 1){ //Down
                    query.addBindValue("Down");
                }else{
                    query.addBindValue("Up");
                }
                query.addBindValue(QString::fromStdString((*itr)->getName()));
                query.addBindValue(QString::fromStdString((*it)->getHostname()));
                query.exec();
         }
    }
    QSqlQuery query2;
    QString queryStr2;
    vector<Link*>::iterator i;
    for(i = links.begin();i!=links.end();++i){
          QString hostname, intf;
          int link_intf[2];
          hostname = QString::fromStdString((*i)->getDev1()->getHostname());
          intf = QString::fromStdString((*i)->getIntf1()->getName());
          for(int x=0;x<2;x++){
              if(x == 1){
                  hostname = QString::fromStdString((*i)->getDev2()->getHostname());
                  intf = QString::fromStdString((*i)->getIntf2()->getName());
              }
              queryStr2 = "select id from Interface where id_hostname = ";
              queryStr2.append(formatString(hostname));
              queryStr2.append(" AND name = ");
              queryStr2.append(formatString(intf));
              query2.exec(queryStr2);
              while (query2.next()) {
                  link_intf[x] = query2.value(0).toInt();
              }
           }
           query.prepare("insert into Link (hostname_1,hostname_2,intf_1,intf_2) VALUES (?, ?, ?, ?)");
           query.addBindValue(QString::fromStdString((*i)->getDev1()->getHostname()));
           query.addBindValue(QString::fromStdString((*i)->getDev2()->getHostname()));
           query.addBindValue(QString::number(link_intf[0]));
           query.addBindValue(QString::number(link_intf[1]));
           query.exec();
      }
}

void Management::readTopology(){
     QSqlQuery query, query2, query3;
     query.prepare("select * from Device");
     query.exec();
     string hostname, ip,type,serie;
     int up_time, rect_x, rect_y, rect_height, rect_width;
     Device* _dev;
     Interface* _intf;
     while (query.next()) {
        hostname = query.value(0).toString().toStdString();
        ip = query.value(1).toString().toStdString();
        type = query.value(2).toString().toStdString();
        serie =  query.value(3).toString().toStdString();
        up_time = query.value(4).toInt();
        rect_x = query.value(5).toInt();
        rect_y = query.value(6).toInt();
        rect_height = query.value(7).toInt();
        rect_width = query.value(8).toInt();
        cout << hostname << " " << ip << " " << type << " " << serie << " " << up_time << " "<<  rect_x << " " << rect_y << " " << rect_height << " " << rect_width << endl;
        _dev = createDevice(ip,hostname,type,serie,rect_x,rect_y,rect_height,rect_width);
        QString queryStr = "select * from Interface where id_hostname = ";
        queryStr.append(formatString(QString::fromStdString((hostname))));
        query2.prepare(queryStr);
        int id_interface;
        string type, status, name, id_hostname;
        query2.exec();
        while(query2.next()){
            id_interface = query2.value(0).toInt();
            type = query2.value(1).toString().toStdString();
            status = query2.value(2).toString().toStdString();
            name = query2.value(3).toString().toStdString();
            id_hostname = query2.value(4).toString().toStdString();
            cout << id_interface << " " << type << " " << status << " " << name << " "<<  id_hostname << endl;
            _intf = new Interface(name,type);
            if(status.compare("Down") == 0){
                _intf->setStatus(1);
            }else{
                _intf->setStatus(2);
            }
            _dev->addInterface(_intf);
        }
        cout << endl;
     }

     query.prepare("select * from Link");
     query.exec();
     Device *dev1,*dev2;
     Interface *intf1,*intf2;
     string str_hostname1, str_hostname2, str_intf1, str_intf2;
     int int_intf1, int_intf2;
     vector<Device*>::iterator itt;
     while(query.next()){

         QString queryStr2 = "select * from Interface where id_hostname = ";
         QString queryStr3 = "select * from Interface where id_hostname = ";

         str_hostname1 =  query.value(1).toString().toStdString();
         str_hostname2 =  query.value(2).toString().toStdString();
         int_intf1 = query.value(3).toInt();
         int_intf2 = query.value(4).toInt();

         queryStr2.append(formatString(QString::fromStdString((str_hostname1))));
         queryStr2.append(" AND id = ");
         queryStr2.append(QString::number(int_intf1));

         queryStr3.append(formatString(QString::fromStdString((str_hostname2))));
         queryStr3.append(" AND id = ");
         queryStr3.append(QString::number(int_intf2));

         for(itt = devices.begin();itt!=devices.end();++itt){
             if((*itt)->getHostname().compare(str_hostname1) == 0){ //array[0] dev1hostname
                 dev1 = *(itt);
             }if((*itt)->getHostname().compare(str_hostname2) == 0){ //array[2] dev2hostname
                 dev2 = *(itt);
             }
         }

         query2.prepare(queryStr2);
         query2.exec();
         while(query2.next()){
             str_intf1 = query2.value(3).toString().toStdString();
         }

         query3.prepare(queryStr3);
         query3.exec();
         while(query3.next()){
             str_intf2 = query3.value(3).toString().toStdString();
         }

         intf1 = dev1->getInterface(str_intf1);
         intf1->setWired(true);
         intf2 = dev2->getInterface(str_intf2);
         intf2->setWired(true);
         dev1->addDevice(intf1,dev2); // para mostrar adj dps
         dev2->addDevice(intf2,dev1); // para mostrar adj dps
         createLink(dev1,intf1,dev2,intf2);
     }
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

bool Management::existHostname(string hostname, string old_hostname){
    vector<Device*>::iterator it;
    for(it = devices.begin();it!= devices.end();++it){
        if(old_hostname.compare((*it)->getHostname()) == 0) {
            continue;
        }
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
    dev->addInterface(intf);
}


void Management::move(Device* dev, int pressedX, int pressedY, int x, int y){
    dev->setPos(pressedX - x, pressedY - y);
}

void Management::killTopology(){
    vector<Device*>::iterator it;
    while(true){
        for(it = devices.begin(); it!=devices.end(); ++it){
            removeDevice((*it)); // se essa funcao for chamada em sequencia, dentro de um for da erro unexpected, acredito que seja o erase do vector.
            break;
        }
        if(devices.size() == 0)
        break;
    }
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
                (*i)->getIntf1()->setWired(false);
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

bool Management::existIP(string ip, string oldIp){
    vector<Device*>::iterator it;
    for(it = devices.begin(); it!=devices.end(); ++it){
        if(oldIp.compare((*it)->getIp()) == 0) {
            continue;
        }
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
                intf1->setWired(false); // setta a interface como NAO CONECTADA
                intf2->setWired(false); // setta a interface como NAO CONECTADA
                links.erase(it);
                return true;
            }
        }
        if(((dev2->getHostname().compare((*it)->getDev1()->getHostname()) == 0) && (dev1->getHostname().compare((*it)->getDev2()->getHostname()))==0)){
            if(((intf2->getName().compare((*it)->getIntf1()->getName()) == 0) && (intf1->getName().compare((*it)->getIntf2()->getName())) == 0)){
                //cout << "second: " << dev2->find(intf2) << endl;
                intf1->setWired(false); // setta a interface como NAO CONECTADA
                intf2->setWired(false); // setta a interface como NAO CONECTADA
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


QSqlDatabase Management::connectDb(){ // NOVO
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydb");
    db.setUserName("root");
    db.setPassword("root");
    if(!db.open()){
        cout << "Falha na conexao com o banco de dados!" << endl;
    }
    return db;
}
void Management::closeDb(){ // NOVO
    QSqlDatabase::removeDatabase("QMYSQL");
}
void Management::query(QString beginTimeStamp, QString endTimeStamp,QString hostname, QString intfName){ // NOVO
    /*  QUERY
     SELECT HistBw.bw_in, HistBw.bw_out, HistBw.date FROM HistBw RIGHT JOIN Interface ON (HistBw.id_intf = Interface.id)
    WHERE (Interface.id_hostname = 'hostname' AND Interface.name = 'Fa0/0' AND HistBw.date > '2012-1-1' AND HistBw.date < '2015-1-1')
    ORDER BY HistBw.date;

    PARA DEBUG: - seleciona *

    SELECT * FROM HistBw RIGHT JOIN Interface ON (HistBw.id_intf = Interface.id) WHERE
   (Interface.id_hostname = 'hostname' AND Interface.name = 'Fa0/0' AND HistBw.date > '2012-1-1'
   AND HistBw.date < '2015-1-1') ORDER BY HistBw.date;

    */
    bytesIn.clear();
    bytesOut.clear();
    dates.clear();

    beginTimeStamp = formatString(beginTimeStamp);
    endTimeStamp = formatString(endTimeStamp);
    hostname = formatString(hostname);
    intfName = formatString(intfName);
    QString queryStr = "SELECT HistBw.bw_in, HistBw.bw_out, HistBw.date FROM HistBw RIGHT JOIN Interface ON (HistBw.id_intf = Interface.id) WHERE (Interface.id_hostname = ";
    queryStr.append(hostname);
    queryStr.append(" AND  Interface.name = ");
    queryStr.append(intfName);
    queryStr.append(" AND HistBw.date > ");
    queryStr.append(beginTimeStamp);
    queryStr.append(" AND HistBw.date < ");
    queryStr.append(endTimeStamp);
    queryStr.append(") ORDER BY HistBw.date");
    cout << "\t\t\t\t (APAGA ISSO AQUI DEPOIS, SOH PRA VC VER MAIS FACIL!) QUERY : " << endl;
    cout <<queryStr.toStdString() << endl;
    QSqlQuery query;
    query.exec(queryStr);

    while (query.next()) {
        bytesIn.push_back(query.value(0).toDouble());
        bytesOut.push_back(query.value(1).toDouble());
        dates.push_back((query.value(2).toDateTime()));
        cout << "\tdate: \t" << dates.back().toString("yyyy-MM-dd hh:mm:ss").toStdString() << "\tbytes_in: \t" << bytesIn.back() << " \tbytes_out: \t" << bytesOut.back() << endl; //  A PARTIR DAQUI PREENCHE UM ARRAY OU ALGO DO TIPO!
    }
}

QVector<double> Management::getBytesIn() {
    return bytesIn;
}

QVector<double> Management::getBytesOut() {
    return bytesOut;
}

QVector<QDateTime> Management::getDate() {
    return dates;
}

QString Management::formatString(QString s){ // formata a string entre '' (aspas)
    QString temp = "'";
    temp.append(s);
    temp.append("'");
    return temp;
}
