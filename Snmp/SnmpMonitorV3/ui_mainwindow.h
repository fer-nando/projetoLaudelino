/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Sep 4 11:12:31 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_3;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioRouter;
    QRadioButton *radioSwitch;
    QRadioButton *radioWire;
    QRadioButton *radioMove;
    QRadioButton *radioDel;
    QFrame *line;
    QLabel *label_2;
    QWidget *widget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelHostname;
    QLineEdit *lineHostname;
    QLabel *labelIP;
    QLineEdit *lineIP;
    QLabel *labelType;
    QLineEdit *lineType;
    QLabel *labelType_2;
    QLineEdit *lineSerie;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(760, 428);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 761, 361));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setAutoFillBackground(false);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 120, 201, 41));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 10, 741, 81));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, -10, 631, 71));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 601, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioRouter = new QRadioButton(horizontalLayoutWidget);
        radioRouter->setObjectName(QString::fromUtf8("radioRouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("rx.gif"), QSize(), QIcon::Normal, QIcon::Off);
        radioRouter->setIcon(icon);
        radioRouter->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioRouter);

        radioSwitch = new QRadioButton(horizontalLayoutWidget);
        radioSwitch->setObjectName(QString::fromUtf8("radioSwitch"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("switch.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioSwitch->setIcon(icon1);
        radioSwitch->setIconSize(QSize(40, 36));

        horizontalLayout->addWidget(radioSwitch);

        radioWire = new QRadioButton(horizontalLayoutWidget);
        radioWire->setObjectName(QString::fromUtf8("radioWire"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("wire.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioWire->setIcon(icon2);
        radioWire->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioWire);

        radioMove = new QRadioButton(horizontalLayoutWidget);
        radioMove->setObjectName(QString::fromUtf8("radioMove"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("move.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioMove->setIcon(icon3);
        radioMove->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioMove);

        radioDel = new QRadioButton(horizontalLayoutWidget);
        radioDel->setObjectName(QString::fromUtf8("radioDel"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioDel->setIcon(icon4);
        radioDel->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioDel);

        line = new QFrame(tab_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 771, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 140, 331, 91));
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(510, 100, 221, 191));
        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 221, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelHostname = new QLabel(formLayoutWidget);
        labelHostname->setObjectName(QString::fromUtf8("labelHostname"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelHostname);

        lineHostname = new QLineEdit(formLayoutWidget);
        lineHostname->setObjectName(QString::fromUtf8("lineHostname"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineHostname);

        labelIP = new QLabel(formLayoutWidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelIP);

        lineIP = new QLineEdit(formLayoutWidget);
        lineIP->setObjectName(QString::fromUtf8("lineIP"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineIP);

        labelType = new QLabel(formLayoutWidget);
        labelType->setObjectName(QString::fromUtf8("labelType"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelType);

        lineType = new QLineEdit(formLayoutWidget);
        lineType->setObjectName(QString::fromUtf8("lineType"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineType);

        labelType_2 = new QLabel(formLayoutWidget);
        labelType_2->setObjectName(QString::fromUtf8("labelType_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelType_2);

        lineSerie = new QLineEdit(formLayoutWidget);
        lineSerie->setObjectName(QString::fromUtf8("lineSerie"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineSerie);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 150, 176, 27));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 760, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Snmp Monitor V3", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab->setToolTip(QApplication::translate("MainWindow", "Monitor", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        tab->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label->setText(QApplication::translate("MainWindow", "AREA DE MONITORAMENTO", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "NA TAB1 SERIA O MONITORAMENTO, GRAFICOS E TUDO  MAIS E NA TAB2 O CARA SETTA A TOPOLOGIA", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tab_2->setToolTip(QApplication::translate("MainWindow", "SetConfig", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QString());
        radioRouter->setText(QApplication::translate("MainWindow", "Router", 0, QApplication::UnicodeUTF8));
        radioSwitch->setText(QApplication::translate("MainWindow", "Switch", 0, QApplication::UnicodeUTF8));
        radioWire->setText(QApplication::translate("MainWindow", "Wire", 0, QApplication::UnicodeUTF8));
        radioMove->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        radioDel->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "SETTAR TOPOLOGIA AREA DE MONITORAMENTO", 0, QApplication::UnicodeUTF8));
        labelHostname->setText(QApplication::translate("MainWindow", "Hostname:", 0, QApplication::UnicodeUTF8));
        lineHostname->setText(QApplication::translate("MainWindow", "hostname", 0, QApplication::UnicodeUTF8));
        labelIP->setText(QApplication::translate("MainWindow", "IPv4:", 0, QApplication::UnicodeUTF8));
        lineIP->setText(QApplication::translate("MainWindow", "255.255.255.255", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        lineType->setText(QApplication::translate("MainWindow", "Router", 0, QApplication::UnicodeUTF8));
        labelType_2->setText(QApplication::translate("MainWindow", "Serie:", 0, QApplication::UnicodeUTF8));
        lineSerie->setText(QApplication::translate("MainWindow", "1841", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
