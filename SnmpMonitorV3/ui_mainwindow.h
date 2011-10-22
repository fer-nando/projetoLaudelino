/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 22 12:37:00 2011
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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioRouter;
    QRadioButton *radioSwitch;
    QRadioButton *radioWire;
    QRadioButton *radioMove;
    QRadioButton *radioEdit;
    QRadioButton *radioLink;
    QRadioButton *radioDel;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1161, 658);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 1141, 51));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1141, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioRouter = new QRadioButton(horizontalLayoutWidget);
        radioRouter->setObjectName(QString::fromUtf8("radioRouter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("router.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        icon3.addFile(QString::fromUtf8("moveDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioMove->setIcon(icon3);
        radioMove->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioMove);

        radioEdit = new QRadioButton(horizontalLayoutWidget);
        radioEdit->setObjectName(QString::fromUtf8("radioEdit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("editDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioEdit->setIcon(icon4);
        radioEdit->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioEdit);

        radioLink = new QRadioButton(horizontalLayoutWidget);
        radioLink->setObjectName(QString::fromUtf8("radioLink"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("deleteWire.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioLink->setIcon(icon5);
        radioLink->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioLink);

        radioDel = new QRadioButton(horizontalLayoutWidget);
        radioDel->setObjectName(QString::fromUtf8("radioDel"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("deleteDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioDel->setIcon(icon6);
        radioDel->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioDel);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 50, 1171, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1161, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Snmp Monitor V3", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        radioRouter->setText(QApplication::translate("MainWindow", "Router", 0, QApplication::UnicodeUTF8));
        radioSwitch->setText(QApplication::translate("MainWindow", "Switch", 0, QApplication::UnicodeUTF8));
        radioWire->setText(QApplication::translate("MainWindow", "Wire", 0, QApplication::UnicodeUTF8));
        radioMove->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        radioEdit->setText(QApplication::translate("MainWindow", "EditDevice", 0, QApplication::UnicodeUTF8));
        radioLink->setText(QApplication::translate("MainWindow", "removeLink", 0, QApplication::UnicodeUTF8));
        radioDel->setText(QApplication::translate("MainWindow", "DeleteDevice", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
