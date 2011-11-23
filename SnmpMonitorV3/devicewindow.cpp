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

void DeviceWindow::setType(string t){
    ui->lineType->setText(QString::fromStdString(t));
}

DeviceWindow::~DeviceWindow()
{
    delete ui;
}

void DeviceWindow::on_buttonBoxCancel(){
    if(!isEdit){
         mgmt->removeDevice(dev); // se o cara nao estava editando.. ele se arrependeu de criar o device e vai ser removido!
    }
    this->close();
}

void DeviceWindow::setDevice(Device *dev){
    this->dev = dev;
}

void DeviceWindow::setManagement(Management *mgmt){
    this->mgmt = mgmt;
}

void DeviceWindow::on_buttonBoxOk(){
        bool thereIsAnyError = false; // FLAG
        serie = ui->lineSerie->text().toStdString();
        type = ui->lineType->text().toStdString();
        ip = ui->lineIP->text().toStdString();
        hostname = ui->lineHostname->text().toStdString();
        ui->textWarning->clear();
        if(!(mgmt->existHostname(hostname)) || isEdit){
            QString qstr = ui->textEditInterfaces->toPlainText();
            QStringList qsltr = qstr.split("\n");
            QStringList::const_iterator constIterator;
            for (constIterator = qsltr.constBegin(); constIterator != qsltr.constEnd();++constIterator){
                    qstr = (*constIterator).toLocal8Bit().constData();
                    if(qstr.toStdString().size() >= 5){ // pog p/ evitar o "";
                            Interface *intf = new Interface(qstr.toStdString(),mgmt->subStrInterfaceType(qstr.toStdString()));
                            if(mgmt->regexInterfaceName(intf)){ // VALIDA PARA NAO INSERIR DUAS INTERFACES IGUAIS! e faz o regex!
                                if(!(mgmt->existInterface(dev,intf))){
                                    dev->addInterface(intf);
                                }
                            }else{
                                thereIsAnyError = true;
                                QString warningStr("Interface name error: ");
                                warningStr.append(QString::fromStdString(intf->getName()));
                                ui->textWarning->setText(ui->textWarning->toPlainText().append(warningStr).append("\n"));
                                delete intf;
                            }
                    }
            }
            // VERIFICA SE EH SWITCH OU ROUTER
            if(( type.compare("Router")!=0 && type.compare("Switch")!=0)){
                thereIsAnyError = true;
                QString warningStr("Type name error: ");
                ui->textWarning->setText(ui->textWarning->toPlainText().append(warningStr).append(ui->lineType->text()));
            }
            if(!mgmt->regexIP(ip) || mgmt->existIP(ip)){ // se nao passou passou pelo regex || se existe o ip
                QString warningStr("");
                if(mgmt->existIP(ip) && !isEdit){ // se ja existia alguem EE se nao estiver editando
                    thereIsAnyError = true;
                    warningStr.append("IP duplicated error: ");
                    ui->textWarning->setText(ui->textWarning->toPlainText().append(warningStr).append(ui->lineIP->text()));
                }else if(!mgmt->regexIP(ip)){ // se nao passou pelo regex! independente se estiver editando ou nao!
                    thereIsAnyError = true;
                    warningStr.append("IP error: ");
                    ui->textWarning->setText(ui->textWarning->toPlainText().append(warningStr).append(ui->lineIP->text()));
                }
            }
            if(!thereIsAnyError){
                dev->setHostname(hostname);
                dev->setIp(ip);
                dev->setSerie(serie);
                dev->setType(type);
                emit windowClosed();
                this->close();
            }
        }else{
            ui->textWarning->setText("Duplicated host name!");
        }
}
