#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    mgmt = new Management();
    myInit();
    setMouseTracking(true);
    rect = new QRect(X_OFFSET,Y_OFFSET,X_MAX,Y_MAX-RECT_HEIGHT);
    pixmapSwitch = new QPixmap("switch.png");
    pixmapRouter = new QPixmap("router.png");
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
    if(e->text().toStdString().compare("r") == 0){
        mgmt->readTopology();
        repaint();
        //cout << "rect->bottomLeft().x(): " << rect->bottomLeft().x() << " rect->bottomRight().x(): " << rect->bottomRight().x() << " rect->topLeft().y(): " << rect->topLeft().y() << " rect->bottomRight().y(): " << rect->bottomRight().y() << endl;
    }
    if(e->text().toStdString().compare("w") == 0){
        mgmt->writeTopology();
    }
    if(e->text().toStdString().compare("p") == 0){
        repaint();
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
    Y_OFFSET = 100;
    X_OFFSET = 30;
    X_MAX = 1100;
    Y_MAX = 570;
}

bool MainWindow::isInsideArea(){
    if(((x > rect->bottomLeft().x() + RECT_WIDTH) && (x < rect->bottomRight().x() - RECT_WIDTH)) && ((y > rect->topLeft().y() + RECT_HEIGHT) && (y < rect->bottomLeft().y() - RECT_HEIGHT))){
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
         painter.setPen(QPen(Qt::green,3));
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
    if(event->button() == Qt::RightButton){
        cout << "right click at: " << dev->getHostname() << " GERAR GRAFICO!" << endl;
    }
    if(ui->radioEdit->isChecked()){
        //mgmt->printRect();
        if(dev != 0){
            deviceWindow = new DeviceWindow();
            deviceWindow->setDevice(dev);
            deviceWindow->setManagement(mgmt);
            deviceWindow->setIsEdit(true);
            deviceWindow->afterConstructor(); // para ajustar o nome do device na janela, ja q eh um edit!
            deviceWindow->show();
            repaint();
        }
    }if(ui->radioDel->isChecked()){
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

void MainWindow::forceRepaint(){
    repaint();
}
