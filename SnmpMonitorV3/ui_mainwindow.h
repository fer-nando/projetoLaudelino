/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.7.1
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
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolOpen;
    QFrame *line_3;
    QToolButton *toolSave;
    QFrame *line_2;
    QRadioButton *radioRouter;
    QRadioButton *radioSwitch;
    QRadioButton *radioWire;
    QRadioButton *radioMove;
    QRadioButton *radioEdit;
    QRadioButton *radioLink;
    QRadioButton *radioDel;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolGraph;
    QWidget *tab_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1161, 658);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolOpen = new QToolButton(centralWidget);
        toolOpen->setObjectName(QString::fromUtf8("toolOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("1319490435_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolOpen->setIcon(icon);
        toolOpen->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(toolOpen);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        toolSave = new QToolButton(centralWidget);
        toolSave->setObjectName(QString::fromUtf8("toolSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("1319490457_disk-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolSave->setIcon(icon1);
        toolSave->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(toolSave);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        radioRouter = new QRadioButton(centralWidget);
        radioRouter->setObjectName(QString::fromUtf8("radioRouter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("router.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioRouter->setIcon(icon2);
        radioRouter->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioRouter);

        radioSwitch = new QRadioButton(centralWidget);
        radioSwitch->setObjectName(QString::fromUtf8("radioSwitch"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("switch.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioSwitch->setIcon(icon3);
        radioSwitch->setIconSize(QSize(40, 36));

        horizontalLayout->addWidget(radioSwitch);

        radioWire = new QRadioButton(centralWidget);
        radioWire->setObjectName(QString::fromUtf8("radioWire"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("wire.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioWire->setIcon(icon4);
        radioWire->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioWire);

        radioMove = new QRadioButton(centralWidget);
        radioMove->setObjectName(QString::fromUtf8("radioMove"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("moveDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioMove->setIcon(icon5);
        radioMove->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioMove);

        radioEdit = new QRadioButton(centralWidget);
        radioEdit->setObjectName(QString::fromUtf8("radioEdit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("editDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioEdit->setIcon(icon6);
        radioEdit->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioEdit);

        radioLink = new QRadioButton(centralWidget);
        radioLink->setObjectName(QString::fromUtf8("radioLink"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("deleteWire.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioLink->setIcon(icon7);
        radioLink->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioLink);

        radioDel = new QRadioButton(centralWidget);
        radioDel->setObjectName(QString::fromUtf8("radioDel"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("deleteDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioDel->setIcon(icon8);
        radioDel->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioDel);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 110));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label_6, 2, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolGraph = new QToolButton(tab);
        toolGraph->setObjectName(QString::fromUtf8("toolGraph"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolGraph->sizePolicy().hasHeightForWidth());
        toolGraph->setSizePolicy(sizePolicy2);
        toolGraph->setMinimumSize(QSize(80, 50));
        toolGraph->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Helvetica [Adobe]"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        toolGraph->setFont(font);
        toolGraph->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(toolGraph);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Snmp Monitor V3", 0, QApplication::UnicodeUTF8));
        toolOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        toolOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        toolSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        toolSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        radioRouter->setText(QApplication::translate("MainWindow", "Router", 0, QApplication::UnicodeUTF8));
        radioSwitch->setText(QApplication::translate("MainWindow", "Switch", 0, QApplication::UnicodeUTF8));
        radioWire->setText(QApplication::translate("MainWindow", "Wire", 0, QApplication::UnicodeUTF8));
        radioMove->setText(QApplication::translate("MainWindow", "Move", 0, QApplication::UnicodeUTF8));
        radioEdit->setText(QApplication::translate("MainWindow", "EditDevice", 0, QApplication::UnicodeUTF8));
        radioLink->setText(QApplication::translate("MainWindow", "removeLink", 0, QApplication::UnicodeUTF8));
        radioDel->setText(QApplication::translate("MainWindow", "DeleteDevice", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Hostname:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Uptime:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "BytesIn:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "BytesOut:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Ip:", 0, QApplication::UnicodeUTF8));
        toolGraph->setText(QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
