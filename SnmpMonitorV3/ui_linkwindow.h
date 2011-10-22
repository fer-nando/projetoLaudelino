/********************************************************************************
** Form generated from reading UI file 'linkwindow.ui'
**
** Created: Sat Oct 22 11:22:18 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKWINDOW_H
#define UI_LINKWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinkWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelDevice1;
    QLabel *labelDevice2;
    QLabel *labelIntf1;
    QLabel *label_4;
    QLineEdit *lineDevice1;
    QLineEdit *lineDevice2;
    QDialogButtonBox *buttonBox;
    QComboBox *comboIntf1;
    QComboBox *comboIntf2;
    QLabel *label;
    QTextEdit *textWarning;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LinkWindow)
    {
        if (LinkWindow->objectName().isEmpty())
            LinkWindow->setObjectName(QString::fromUtf8("LinkWindow"));
        LinkWindow->resize(331, 301);
        centralwidget = new QWidget(LinkWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 301, 241));
        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(9, 10, 281, 231));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelDevice1 = new QLabel(formLayoutWidget);
        labelDevice1->setObjectName(QString::fromUtf8("labelDevice1"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDevice1);

        labelDevice2 = new QLabel(formLayoutWidget);
        labelDevice2->setObjectName(QString::fromUtf8("labelDevice2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelDevice2);

        labelIntf1 = new QLabel(formLayoutWidget);
        labelIntf1->setObjectName(QString::fromUtf8("labelIntf1"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelIntf1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineDevice1 = new QLineEdit(formLayoutWidget);
        lineDevice1->setObjectName(QString::fromUtf8("lineDevice1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineDevice1);

        lineDevice2 = new QLineEdit(formLayoutWidget);
        lineDevice2->setObjectName(QString::fromUtf8("lineDevice2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineDevice2);

        buttonBox = new QDialogButtonBox(formLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::FieldRole, buttonBox);

        comboIntf1 = new QComboBox(formLayoutWidget);
        comboIntf1->setObjectName(QString::fromUtf8("comboIntf1"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboIntf1);

        comboIntf2 = new QComboBox(formLayoutWidget);
        comboIntf2->setObjectName(QString::fromUtf8("comboIntf2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboIntf2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        textWarning = new QTextEdit(formLayoutWidget);
        textWarning->setObjectName(QString::fromUtf8("textWarning"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textWarning);

        LinkWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LinkWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 331, 25));
        LinkWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LinkWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LinkWindow->setStatusBar(statusbar);

        retranslateUi(LinkWindow);

        QMetaObject::connectSlotsByName(LinkWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LinkWindow)
    {
        LinkWindow->setWindowTitle(QApplication::translate("LinkWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        labelDevice1->setText(QApplication::translate("LinkWindow", "Device1:", 0, QApplication::UnicodeUTF8));
        labelDevice2->setText(QApplication::translate("LinkWindow", "Device2:", 0, QApplication::UnicodeUTF8));
        labelIntf1->setText(QApplication::translate("LinkWindow", "Intf1:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LinkWindow", "Intf2:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LinkWindow", "Warning:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LinkWindow: public Ui_LinkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKWINDOW_H
