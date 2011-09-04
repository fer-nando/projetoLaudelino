#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    mgmt = new Management();
    ui->widget->setVisible(false);
    connect(ui->radioMove,SIGNAL(clicked()),this,SLOT(on_radioMove()));
    connect(ui->radioDel,SIGNAL(clicked()),this,SLOT(on_radioDel()));
    connect(ui->radioRouter,SIGNAL(clicked()),this,SLOT(on_radioRouter()));
    connect(ui->radioSwitch,SIGNAL(clicked()),this,SLOT(on_radioSwitch()));
    connect(ui->radioWire,SIGNAL(clicked()),this,SLOT(on_radioWire()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(on_buttonBoxOk()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(on_buttonBoxCancel()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_buttonBoxOk(){
    mgmt->createDevice(ui->lineHostname->text().toStdString(),ui->lineIP->text().toStdString(),ui->lineType->text().toStdString(),ui->lineSerie->text().toStdString());
    cout << "ok!" << endl;
    mgmt->printDefault();
}

void MainWindow::on_buttonBoxCancel(){
    ui->widget->setVisible(false);
    cout << "cancel!" << endl;
}

void MainWindow::on_radioDel(){
    cout << "del!" << endl;
}

void MainWindow::on_radioMove(){
    cout << "move!" << endl;
}

void MainWindow::on_radioRouter(){
    ui->lineType->setText("Router");
    ui->lineSerie->setText("1841");
    ui->widget->setVisible(true);
    cout << "router!" << endl;
}

void MainWindow::on_radioSwitch(){
    ui->lineType->setText("Switch");
    ui->lineSerie->setText("2960");
    ui->widget->setVisible(true);
    cout << "switch!" << endl;
}

void MainWindow::on_radioWire(){
    cout << "wire!" << endl;
}

