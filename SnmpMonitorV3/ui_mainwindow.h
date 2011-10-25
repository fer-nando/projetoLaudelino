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
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
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
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolGraph;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QTextEdit *hostnameEdit;
    QTextEdit *ipEdit;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_14;
    QTextEdit *typeEdit;
    QTextEdit *serieEdit;
    QGridLayout *gridLayout_8;
    QLabel *label_16;
    QTextEdit *interfaceEdit;
    QLabel *label_35;
    QTextEdit *label_warning;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *editButton;

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

        radioLink = new QRadioButton(centralWidget);
        radioLink->setObjectName(QString::fromUtf8("radioLink"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("deleteWire.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioLink->setIcon(icon6);
        radioLink->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(radioLink);

        radioDel = new QRadioButton(centralWidget);
        radioDel->setObjectName(QString::fromUtf8("radioDel"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("deleteDevice.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioDel->setIcon(icon7);
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(70, 30));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(textEdit_2, 1, 1, 1, 1);

        textEdit_3 = new QTextEdit(tab);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(textEdit_3, 2, 1, 1, 1);

        textEdit_4 = new QTextEdit(tab);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(textEdit_4, 0, 3, 1, 1);

        textEdit_5 = new QTextEdit(tab);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(textEdit_5, 1, 3, 1, 1);

        textEdit_6 = new QTextEdit(tab);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));
        textEdit_6->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(textEdit_6, 2, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolGraph = new QToolButton(tab);
        toolGraph->setObjectName(QString::fromUtf8("toolGraph"));
        sizePolicy1.setHeightForWidth(toolGraph->sizePolicy().hasHeightForWidth());
        toolGraph->setSizePolicy(sizePolicy1);
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
        horizontalLayout_4 = new QHBoxLayout(tab_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 1, 0, 1, 1);

        hostnameEdit = new QTextEdit(tab_2);
        hostnameEdit->setObjectName(QString::fromUtf8("hostnameEdit"));
        sizePolicy1.setHeightForWidth(hostnameEdit->sizePolicy().hasHeightForWidth());
        hostnameEdit->setSizePolicy(sizePolicy1);
        hostnameEdit->setMaximumSize(QSize(200, 30));

        gridLayout_3->addWidget(hostnameEdit, 0, 1, 1, 1);

        ipEdit = new QTextEdit(tab_2);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        sizePolicy1.setHeightForWidth(ipEdit->sizePolicy().hasHeightForWidth());
        ipEdit->setSizePolicy(sizePolicy1);
        ipEdit->setMaximumSize(QSize(200, 30));

        gridLayout_3->addWidget(ipEdit, 1, 1, 1, 1);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 2, 0, 1, 1);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 3, 0, 1, 1);

        typeEdit = new QTextEdit(tab_2);
        typeEdit->setObjectName(QString::fromUtf8("typeEdit"));
        sizePolicy1.setHeightForWidth(typeEdit->sizePolicy().hasHeightForWidth());
        typeEdit->setSizePolicy(sizePolicy1);
        typeEdit->setMaximumSize(QSize(200, 30));

        gridLayout_3->addWidget(typeEdit, 2, 1, 1, 1);

        serieEdit = new QTextEdit(tab_2);
        serieEdit->setObjectName(QString::fromUtf8("serieEdit"));
        sizePolicy1.setHeightForWidth(serieEdit->sizePolicy().hasHeightForWidth());
        serieEdit->setSizePolicy(sizePolicy1);
        serieEdit->setMaximumSize(QSize(200, 30));

        gridLayout_3->addWidget(serieEdit, 3, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_3);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_8->addWidget(label_16, 0, 0, 1, 1);

        interfaceEdit = new QTextEdit(tab_2);
        interfaceEdit->setObjectName(QString::fromUtf8("interfaceEdit"));
        sizePolicy1.setHeightForWidth(interfaceEdit->sizePolicy().hasHeightForWidth());
        interfaceEdit->setSizePolicy(sizePolicy1);
        interfaceEdit->setMaximumSize(QSize(200, 120));

        gridLayout_8->addWidget(interfaceEdit, 0, 1, 1, 1);

        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_8->addWidget(label_35, 0, 2, 1, 1);

        label_warning = new QTextEdit(tab_2);
        label_warning->setObjectName(QString::fromUtf8("label_warning"));
        sizePolicy1.setHeightForWidth(label_warning->sizePolicy().hasHeightForWidth());
        label_warning->setSizePolicy(sizePolicy1);
        label_warning->setMaximumSize(QSize(200, 120));
        label_warning->setReadOnly(true);

        gridLayout_8->addWidget(label_warning, 0, 3, 1, 1);


        horizontalLayout_4->addLayout(gridLayout_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        editButton = new QPushButton(tab_2);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setMinimumSize(QSize(50, 40));

        horizontalLayout_4->addWidget(editButton);

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
        radioLink->setText(QApplication::translate("MainWindow", "removeLink", 0, QApplication::UnicodeUTF8));
        radioDel->setText(QApplication::translate("MainWindow", "DeleteDevice", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Hostname:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Uptime:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "BytesIn:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "BytesOut:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "IPv4:", 0, QApplication::UnicodeUTF8));
        toolGraph->setText(QApplication::translate("MainWindow", "Graph", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "IPv4:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Hostname:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Serie:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Interfaces:", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "Warning:", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
