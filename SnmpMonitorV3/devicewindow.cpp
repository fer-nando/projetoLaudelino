#include "devicewindow.h"
#include "ui_devicewindow.h"

DeviceWindow::DeviceWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::DeviceWindow){
    ui->setupUi(this);
    ui->textWarning->setReadOnly(true);
    ui->textWarning->setTextColor(Qt::red);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(on_buttonBoxOk()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(on_buttonBoxCancel()));
    isEdit = false;
}

void DeviceWindow::afterConstructor(){
    if(isEdit){
        ui->lineHostname->setText(QString::fromStdString(device->getHostname()));
        ui->lineIP->setText(QString::fromStdString(device->getIp()));
        ui->lineSerie->setText(QString::fromStdString(device->getSerie()));
        ui->lineType->setText(QString::fromStdString(device->getType()));
        QString str = "";
        for(vector<Interface*>::iterator it = device->getInterfaces().begin(); it != device->getInterfaces().end(); ++ it){
            QString strTemp = QString::fromStdString((*it)->getName());
            strTemp.append("\n");
            str.append(strTemp);
        }
        ui->textEditInterfaces->setText(str);
    }
}

DeviceWindow::~DeviceWindow()
{
    delete ui;
}

void DeviceWindow::setIsEdit(bool edit){
    this->isEdit = edit;
}

void DeviceWindow::on_buttonBoxCancel(){
    if(!isEdit){
         mgmt->removeDevice(device); // se o cara nao estava editando.. ele se arrependeu de criar o device e vai ser removido!
    }
    this->close();
}

void DeviceWindow::setDevice(Device *dev){
    this->device = dev;
}

void DeviceWindow::setManagement(Management *mgmt){
    this->mgmt = mgmt;
}

void DeviceWindow::on_buttonBoxOk(){
        serie = ui->lineSerie->text().toStdString();
        type = ui->lineType->text().toStdString();
        ip = ui->lineIP->text().toStdString();
        hostname = ui->lineHostname->text().toStdString();
        if(!(mgmt->existHostname(hostname)) || isEdit){
            device->setHostname(hostname);
            device->setIp(ip);
            device->setSerie(serie);
            device->setType(type);
            QString qstr = ui->textEditInterfaces->toPlainText();
            QStringList qsltr = qstr.split("\n");
            QStringList::const_iterator constIterator;
            for (constIterator = qsltr.constBegin(); constIterator != qsltr.constEnd();++constIterator){
                    qstr = (*constIterator).toLocal8Bit().constData();
                    Interface *intf = new Interface(qstr.toStdString(),qstr.toStdString());
                    if(!(mgmt->existInterface(device,intf))){ // VALIDA PARA NAO INSERIR DUAS INTERFACES IGUAIS!
                        device->addIntf(intf);
                    }else{
                        delete intf;
                    }
            }
            this->close();
        }else{
            ui->textWarning->setText("Host Duplicado!");
            // FAZER O TRATAMENTO DE EXCECAO PARA NOME DE INTERFACE, IP, atraves de expressao regular!
        }
}
