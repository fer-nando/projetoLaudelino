#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    mgmt = new Management();
    myInit();
    setMouseTracking(true);
    rect = new QRect(X_OFFSET,Y_UPPER_OFFSET,X_MAX,Y_MAX);
    pixmapSwitch = new QPixmap("switch.png");
    pixmapRouter = new QPixmap("router.png");

    loopSeconds = 3;
    flagSave = false;
    thread = new DbThread(0,loopSeconds,mgmt); // thread

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(forceRepaint()));
    timer->start((1000*loopSeconds)+1); // 1 milisegundo a mais apos a thread executar, POG pq nao tem como eu ativar um repaint
    // no mainwindow atraves da classe DbThread, eu tentei passar MainWindow no construtor mais da zica pq MainWindow ja tem referencia
    // para Thread e entao nao tem como, seria uma contradicao vc instanciar uma classe que tem referencia da outra e vice-versa.
    thread->start();

    selectedDevice = 0;

    connect(ui->toolOpen, SIGNAL(clicked()), this, SLOT(openEvent()));
    connect(ui->toolSave, SIGNAL(clicked()), this, SLOT(saveEvent()));
    connect(ui->editButton, SIGNAL(clicked()), this, SLOT(editEvent()));
    connect(ui->toolKill, SIGNAL(clicked()), this, SLOT(killTopologyEvent()));
    connect(ui->toolGraph, SIGNAL(clicked()), this, SLOT(graphEvent()));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
    if(ui->radioWire->isChecked() || ui->radioLink->isChecked()){
         if(dev != 0){
            Device* aux = mgmt->verifyClickCollision(e->x(),e->y());
            if(aux != 0 ){
                if((dev->getHostname().compare(aux->getHostname())) != 0){ // se nao for o mesmo no!
                    linkWindow = new LinkWindow();
                    if(ui->radioLink->isChecked()){
                        linkWindow->setRemoveLink(true);
                    }
                    linkWindow->setDevices(dev,aux);
                    linkWindow->setManagement(mgmt);
                    linkWindow->show();
                    connect(linkWindow, SIGNAL(windowClosed()), this, SLOT(forceRepaint()));
                }
            }
         }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    if(e->text().toStdString().compare("d") == 0){
        mgmt->printDefault();
    }
    if(e->text().toStdString().compare("l") == 0){
        mgmt->printLinks();
    }
    if(e->text().toStdString().compare("p") == 0){
        repaint();
    }
    if(e->text().toStdString().compare("b") == 0){
        // NAO PRECISA MAIS DISSO
        /*if(selectedDevice != 0) {
            for(vector<Interface*>::iterator it = selectedDevice->getInterfaces().begin(); it != selectedDevice->getInterfaces().end(); ++it){
                if((*it)->getStatus() == 2) {
                    (*it)->setStatus(1);
                }
                else {
                    (*it)->setStatus(2);
                }
            }
            repaint();
        }*/
    }
    if(e->text().toStdString().compare("t") == 0){
        if(!thread->isRunning()){
               QTimer *timer = new QTimer(this);
               connect(timer, SIGNAL(timeout()), this, SLOT(forceRepaint()));
               timer->start((1000*loopSeconds)+1); // 1 milisegundo a mais apos a thread executar, POG pq nao tem como eu ativar um repaint
               // no mainwindow atraves da classe DbThread, eu tentei passar MainWindow no construtor mais da zica pq MainWindow ja tem referencia
               // para Thread e entao nao tem como, seria uma contradicao vc instanciar uma classe que tem referencia da outra e vice-versa.
               thread->start();
        }
    }
    if(e->text().toStdString().compare("q") == 0){ // ESSES QSTRING IRAO VAO SER SETTADO PELO USUARIO Na Interface
        QString beginDate = "2010-01-01"; // tem que ser nesse formato "yyyy-mm-dd HH:MM:ss" OU entao somente "2009-01-01" sem as HH:MM:SS
        QString endDate = "2015-01-01";
        QString host = "hostname2";
        QString intfName = "Fa0/0";
        mgmt->query(beginDate,endDate,host,intfName);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e){
    if(moving && ui->radioMove->isChecked()){
        x = e->x();
        y = e->y();
       // cout << "x: "<< x << " y: " << y << endl;
        if(isInsideArea()){
            mgmt->move(moveDevice,pressedX,pressedY,x,y);
            repaint();
            pressedX = x;
            pressedY = y;
        }
    }
}

void MainWindow::myInit(){
    moving = false;
    x = 1000;
    y = 1000;
    RECT_WIDTH = 50;
    RECT_HEIGHT = 50;
    X_OFFSET = 10;
    Y_UPPER_OFFSET = 70;
    Y_LOWER_OFFSET = 210;
    X_MAX = width() - 2 * X_OFFSET;
    Y_MAX = height() - Y_LOWER_OFFSET;
}

bool MainWindow::isInsideArea(){
    if((x > rect->bottomLeft().x() + RECT_WIDTH)  &&
       (x < rect->bottomRight().x() - RECT_WIDTH) &&
       (y > rect->topLeft().y() + RECT_HEIGHT)    &&
       (y < rect->bottomLeft().y() - RECT_HEIGHT)) {
        return true;
    }
    return false;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawRect(*rect);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::yellow));
    //painter.drawText(150,150,"AREA PARA SETTAR A TOPOLOGIA!");
    painter.setBrush(QBrush());
    for(vector<Link*>::iterator it = mgmt->getLinks().begin(); it != mgmt->getLinks().end(); ++it){
         QPainterPath path;
         QPoint pt;
         QString st = QString::fromStdString((*it)->getIntf1()->getName());
         st.append(":");
         st.append(QString::fromStdString((*it)->getIntf2()->getName()));
         pt.setX((((*it)->getDev1())->getRect()->x()+((*it)->getDev2())->getRect()->x())/2 + 20 + (*it)->getLineDeltaX());
         pt.setY((((*it)->getDev1())->getRect()->y()+((*it)->getDev2())->getRect()->y())/2 + 20 + (*it)->getLineDeltaY());

         if((*it)->getIntf1()->getStatus() == 2 && (*it)->getIntf2()->getStatus() == 2) {
            painter.setPen(QPen(Qt::green,3));
         }
         else {
            painter.setPen(QPen(Qt::red,3));
         }
         path.moveTo(((*it)->getDev1())->getRect()->center());
         path.cubicTo((((*it)->getDev1())->getRect()->center()),pt,(((*it)->getDev2())->getRect()->center()));
         painter.drawPath(path);
         painter.setPen(QPen(Qt::black,3));
         pt.setX(pt.x()-10);
         painter.drawText(pt,st);
         pt.setX(pt.x()+10);
    }
    painter.setPen(QPen());
    painter.setBrush(QBrush(Qt::blue));
    for(vector<Device*>::iterator i = mgmt->getDevices().begin(); i != mgmt->getDevices().end(); ++i){
        //cout << ((*i)->getRect())->x() << endl;
        painter.drawText(((*i)->getRect())->x(),((*i)->getRect())->y()-5,(*i)->getHostname().c_str());
        //painter.drawRect(*((*i)->getRect()));
        if((*i)->getType().compare("Router") == 0){ // O DEVICE EH UM ROUTER!
            painter.drawPixmap(*((*i)->getRect()),*pixmapRouter);
        }else{ // EH um SWITCH
            painter.drawPixmap(*((*i)->getRect()),*pixmapSwitch);
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    x = event->x();
    y = event->y();
   // cout  << "x: " << x << " y: " << y << endl;
    dev = mgmt->verifyClickCollision(x,y); // verifica se o click colidiu com algum device, se colidiu a variavel dev ja recebe o ponteiro!

    if(selectedDevice != dev && dev != 0) { // se um novo dispositivo foi selecionado, limpa os campos antes de preencher novamente
        selectedDevice = 0;
        setupDeviceTab();
    }
    selectedDevice = dev;
    setupDeviceTab();

    if(ui->radioDel->isChecked()){
        if(dev != 0){
            mgmt->removeDevice(dev);
            repaint();
        }
    }
    if(ui->radioMove->isChecked()){
        moveDevice = mgmt->verifyClickCollision(x,y);
        if(moveDevice != 0){
            moving = true;
            pressedX = x;
            pressedY = y;
        }else{
            moving = false;
        }
    }
    if(ui->radioRouter->isChecked() || ui->radioSwitch->isChecked()){
         if(isInsideArea()){ // ta dentro da area
             if(!(mgmt->rectCollision(x,y,RECT_HEIGHT,RECT_WIDTH))){ // o click nao colidiu com nenhum no existe
                 deviceWindow = new DeviceWindow();
                 deviceWindow->setManagement(mgmt);
                 if(ui->radioRouter->isChecked()){ // setar a string padrao e criar o desenho com o "Type" correto!
                     deviceWindow->setType("Router");
                     deviceWindow->setDevice(mgmt->createDevice("255.255.255.255","","Router","1841",x,y,RECT_HEIGHT,RECT_WIDTH)); // cria um device padrao!
                 }else{
                     deviceWindow->setType("Switch");
                     deviceWindow->setDevice(mgmt->createDevice("255.255.255.255","","Switch","2960",x,y,RECT_HEIGHT,RECT_WIDTH)); // cria um device padrao!
                 }
                 deviceWindow->show();
                 //repaint(); // sem isso evita que pinte antes de saber se clicou em 'ok' ou 'cancel'
                 connect(deviceWindow, SIGNAL(windowClosed()), this, SLOT(forceRepaint()));
             }
         }
    }
}

void MainWindow::resizeEvent(QResizeEvent *e) {
    myInit();
    rect->setCoords(X_OFFSET,Y_UPPER_OFFSET,X_MAX,Y_MAX);
    repaint();
}

void MainWindow::setupDeviceTab() {
    if(selectedDevice != 0) {
        QString str = "";
        int row = 1;

        ui->label_hostname->setText(QString::fromStdString(selectedDevice->getHostname()));
        ui->label_ip->setText(QString::fromStdString(selectedDevice->getIp()));
        ui->label_type->setText(QString::fromStdString(selectedDevice->getType()));
        ui->label_serie->setText(QString::fromStdString(selectedDevice->getSerie()));
        for(vector<Interface*>::iterator it = selectedDevice->getInterfaces().begin(); it != selectedDevice->getInterfaces().end(); ++ it){
            QLabel * labelTemp;
            QString strTemp;
            bool isNew;

            strTemp = QString::fromStdString((*it)->getName());
            if(label_Intf.size() >= row*5 && strTemp.compare( label_Intf.at( (row-1)*5 )->text() ) == 0) {
                isNew = false;
            }
            else {
                isNew = true;
            }

            // se é uma interface nova, adiciona novos elementos no grid
            if(isNew) {
                labelTemp = new QLabel(ui->tab);
                labelTemp->setText(strTemp);
                ui->gridLayout_4->addWidget(labelTemp, row, 0, 1, 1);
                label_Intf.push_back(labelTemp);

                strTemp = QString::number((*it)->getStatus());
                labelTemp = new QLabel(ui->tab);
                labelTemp->setText(strTemp);
                ui->gridLayout_4->addWidget(labelTemp, row, 1, 1, 1);
                label_Intf.push_back(labelTemp);

                strTemp = QString::fromStdString((*it)->getWired() ? "yes" : "no");
                labelTemp = new QLabel(ui->tab);
                labelTemp->setText(strTemp);
                ui->gridLayout_4->addWidget(labelTemp, row, 2, 1, 1);
                label_Intf.push_back(labelTemp);

                strTemp = QString::number((*it)->getBytesIn());
                labelTemp = new QLabel(ui->tab);
                labelTemp->setText(strTemp);
                ui->gridLayout_4->addWidget(labelTemp, row, 3, 1, 1);
                label_Intf.push_back(labelTemp);

                strTemp = QString::number((*it)->getBytesOut());
                labelTemp = new QLabel(ui->tab);
                labelTemp->setText(strTemp);
                ui->gridLayout_4->addWidget(labelTemp, row, 4, 1, 1);
                label_Intf.push_back(labelTemp);
            }
            else { // senao, somente atualiza os campos
                label_Intf.at( (row-1)*5 )->setText(strTemp);

                strTemp = QString::number((*it)->getStatus());
                label_Intf.at( (row-1)*5+1 )->setText(strTemp);

                strTemp = QString::fromStdString((*it)->getWired() ? "yes" : "no");
                label_Intf.at( (row-1)*5+2 )->setText(strTemp);

                strTemp = QString::number((*it)->getBytesIn());
                label_Intf.at( (row-1)*5+3 )->setText(strTemp);

                strTemp = QString::number((*it)->getBytesOut());
                label_Intf.at( (row-1)*5+4 )->setText(strTemp);
            }

            row++;
        }

        ui->hostnameEdit->setText(QString::fromStdString(selectedDevice->getHostname()));
        ui->ipEdit->setText(QString::fromStdString(selectedDevice->getIp()));
        ui->typeEdit->setText(QString::fromStdString(selectedDevice->getType()));
        ui->serieEdit->setText(QString::fromStdString(selectedDevice->getSerie()));
        for(vector<Interface*>::iterator it = selectedDevice->getInterfaces().begin(); it != selectedDevice->getInterfaces().end(); ++ it){
            QString strTemp = QString::fromStdString((*it)->getName());
            strTemp.append("\n");
            str.append(strTemp);
        }
        ui->interfaceEdit->setText(str);

    }
    else {
        for(int i = 0; i < label_Intf.size(); i++) {
            label_Intf.at(i)->clear();
            ui->gridLayout_4->removeWidget(label_Intf.at(i));
            delete label_Intf.at(i);
        }
        label_Intf.clear();

        ui->hostnameEdit->clear();
        ui->ipEdit->clear();
        ui->typeEdit->clear();
        ui->serieEdit->clear();
        ui->interfaceEdit->clear();
        ui->label_warning->clear();
    }
}

/* SLOTS */

void MainWindow::editEvent(){
    if(selectedDevice != 0) {
        bool thereIsAnyError = false; // FLAG
        QString warningStr("");
        string serie = ui->serieEdit->toPlainText().toStdString();
        string type = ui->typeEdit->toPlainText().toStdString();
        string ip = ui->ipEdit->toPlainText().toStdString();
        string hostname = ui->hostnameEdit->toPlainText().toStdString();
        ui->label_warning->clear();

        if(mgmt->existHostname(hostname, selectedDevice->getHostname())) {
            thereIsAnyError = true;
            ui->label_warning->setText("Duplicated host name!");
        }
        QString qstr = ui->interfaceEdit->toPlainText();
        QStringList qsltr = qstr.split("\n");
        QStringList::const_iterator constIterator;
        for (constIterator = qsltr.constBegin(); constIterator != qsltr.constEnd(); ++constIterator){
                qstr = (*constIterator).toLocal8Bit().constData();
                if(qstr.toStdString().size() >= 5){ // pog p/ evitar o "";
                    Interface *intf = new Interface(qstr.toStdString(),mgmt->subStrInterfaceType(qstr.toStdString()));
                    if(mgmt->regexInterfaceName(intf)){ // VALIDA PARA NAO INSERIR DUAS INTERFACES IGUAIS! e faz o regex!
                        if(!(mgmt->existInterface(selectedDevice,intf))){
                            selectedDevice->addInterface(intf);
                        }
                    }else{
                        thereIsAnyError = true;
                        warningStr = "Interface name error: ";
                        warningStr.append(QString::fromStdString(intf->getName()));
                        ui->label_warning->setText(ui->label_warning->toPlainText().append(warningStr).append("\n"));
                        cout << "Warning: " << warningStr.toStdString()<< endl;
                        delete intf;
                    }
                }
        }
        // VERIFICA SE EH SWITCH OU ROUTER
        if(( type.compare("Router")!=0 && type.compare("Switch")!=0)){
            thereIsAnyError = true;
            warningStr = "Type name error: ";
            ui->label_warning->setText(ui->label_warning->toPlainText().append(warningStr).append(ui->typeEdit->toPlainText()));
        }
        if(!mgmt->regexIP(ip) || mgmt->existIP(ip)){ // se nao passou passou pelo regex || se existe o ip
            if(mgmt->existIP(ip, selectedDevice->getIp())){ // se ja existia alguem
                thereIsAnyError = true;
                warningStr.append("IP duplicated error: ");
                ui->label_warning->setText(ui->label_warning->toPlainText().append(warningStr).append(ui->ipEdit->toPlainText()));
            }else if(!mgmt->regexIP(ip)){ // se nao passou pelo regex
                thereIsAnyError = true;
                warningStr.append("IP error: ");
                ui->label_warning->setText(ui->label_warning->toPlainText().append(warningStr).append(ui->ipEdit->toPlainText()));
            }
        }
        if(!thereIsAnyError){
            selectedDevice->setHostname(hostname);
            selectedDevice->setIp(ip);
            selectedDevice->setSerie(serie);
            selectedDevice->setType(type);
            setupDeviceTab();
            repaint();
        }
    }
}

void MainWindow::forceRepaint(){
    repaint();
}

void MainWindow::killTopologyEvent() {
    flagSave = false;
    mgmt->killTopology();
    repaint();
}

void MainWindow::saveEvent() {
    mgmt->writeTopology();
    flagSave = true;
}

void MainWindow::openEvent() {
    if(!flagSave) {
        mgmt->readTopology();
        flagSave = true;
        repaint();
    }
}

void MainWindow::graphEvent() {
    if(selectedDevice != 0) {
        graphWindow = new GraphWindow(selectedDevice, mgmt);
        graphWindow->setWindowTitle("GraphWindow");
        graphWindow->show();
    }
}
