#include "linkwindow.h"
#include "ui_linkwindow.h"

LinkWindow::LinkWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::LinkWindow)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(on_buttonBoxOk()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(on_buttonBoxCancel()));
    removeLink = false;
    ui->textWarning->setReadOnly(true);
    ui->textWarning->setTextColor(Qt::red);
}

LinkWindow::~LinkWindow()
{
    delete ui;
}

void LinkWindow::on_buttonBoxCancel(){
    this->close();
}

void LinkWindow::on_buttonBoxOk(){
    bool willRemove = true;
    ui->textWarning->clear();
    if(ui->comboIntf1->currentText().compare("") != 0 && ui->comboIntf2->currentText().compare("") != 0){ // evitar texto null
        intf1 = new Interface(ui->comboIntf1->currentText().toStdString(),mgmt->subStrInterfaceType(ui->comboIntf1->currentText().toStdString()));
        intf2 = new Interface(ui->comboIntf2->currentText().toStdString(),mgmt->subStrInterfaceType(ui->comboIntf2->currentText().toStdString()));
        if(!mgmt->existStrLinkMismatch(intf1,intf2)){
            if(!removeLink){ // se NAO esta no modo remove!
                dev1->setInterfaceWired(intf1,true);
                dev2->setInterfaceWired(intf2,true);
                mgmt->createLink(dev1,intf1,dev2,intf2);
                dev1->addDev(intf1,dev2); // para mostrar adj dps
                dev2->addDev(intf2,dev1); // para mostrar adj dps
            }else{ // modo remove
                willRemove = mgmt->removeLink(dev1,intf1,dev2,intf2);
            }
        }else{
            willRemove = false; // mismatch Serial com FA ou GI
        }
    }else{
        willRemove = false; //setado como false pq se ele entrou aq eh porque tem texto null nos combobox, esta situaco pode ocorrer
        // qndo um device de 2 intf vai conectar a um de 1 intf
    }
    if(willRemove){
         this->close();
    }else{
        ui->textWarning->setText("Error: remove link mismatch!");
    }
}

void LinkWindow::setRemoveLink(bool remove){
    this->removeLink = remove;
}

void LinkWindow::setDevices(Device *dev1, Device *dev2){
    this->dev1 = dev1;
    this->dev2 = dev2;
    ui->lineDevice1->setText(QString::fromStdString(dev1->getHostname()));
    ui->lineDevice2->setText(QString::fromStdString(dev2->getHostname()));
    vector<Interface*>::iterator it;
    for(it = dev1->getInterfaces().begin(); it != dev1->getInterfaces().end() ; ++ it){
        if(!(*it)->getWired() && !removeLink){ // valida as interfaces que NAO estao conectadas!
            ui->comboIntf1->addItem(QString::fromStdString((*it)->getName()));
        }else if(((*it)->getWired()) && removeLink){ // valida as interfaces que ESTAO conectadas e modo remove
            ui->comboIntf1->addItem(QString::fromStdString((*it)->getName()));
        }
    }
    for(it = dev2->getInterfaces().begin(); it != dev2->getInterfaces().end() ; ++ it){
        if(!(*it)->getWired() && !removeLink){ // valida as interfaces que NAO estao conectadas
            ui->comboIntf2->addItem(QString::fromStdString((*it)->getName()));
        }else if(((*it)->getWired()) && removeLink){ // valida as interfaces que ESTAO conectadas e modo remove
            ui->comboIntf2->addItem(QString::fromStdString((*it)->getName()));
        }
    }
}

void LinkWindow::setManagement(Management *mgmt){
    this->mgmt = mgmt;
}
