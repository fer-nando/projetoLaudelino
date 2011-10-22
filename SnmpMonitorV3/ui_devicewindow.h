/********************************************************************************
** Form generated from reading UI file 'devicewindow.ui'
**
** Created: Sat Oct 22 10:37:43 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEWINDOW_H
#define UI_DEVICEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_DeviceWindow
{
public:
    QWidget *centralwidget;
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
    QLabel *labelInterfaces;
    QDialogButtonBox *buttonBox;
    QLabel *labelWarning;
    QTextEdit *textWarning;
    QTextEdit *textEditInterfaces;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DeviceWindow)
    {
        if (DeviceWindow->objectName().isEmpty())
            DeviceWindow->setObjectName(QString::fromUtf8("DeviceWindow"));
        DeviceWindow->resize(364, 436);
        centralwidget = new QWidget(DeviceWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 0, 341, 401));
        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 3, 321, 371));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
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

        formLayout->setWidget(4, QFormLayout::LabelRole, labelType_2);

        lineSerie = new QLineEdit(formLayoutWidget);
        lineSerie->setObjectName(QString::fromUtf8("lineSerie"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineSerie);

        labelInterfaces = new QLabel(formLayoutWidget);
        labelInterfaces->setObjectName(QString::fromUtf8("labelInterfaces"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelInterfaces);

        buttonBox = new QDialogButtonBox(formLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(8, QFormLayout::FieldRole, buttonBox);

        labelWarning = new QLabel(formLayoutWidget);
        labelWarning->setObjectName(QString::fromUtf8("labelWarning"));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelWarning);

        textWarning = new QTextEdit(formLayoutWidget);
        textWarning->setObjectName(QString::fromUtf8("textWarning"));

        formLayout->setWidget(6, QFormLayout::FieldRole, textWarning);

        textEditInterfaces = new QTextEdit(formLayoutWidget);
        textEditInterfaces->setObjectName(QString::fromUtf8("textEditInterfaces"));

        formLayout->setWidget(5, QFormLayout::FieldRole, textEditInterfaces);

        DeviceWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DeviceWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 364, 25));
        DeviceWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DeviceWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DeviceWindow->setStatusBar(statusbar);

        retranslateUi(DeviceWindow);

        QMetaObject::connectSlotsByName(DeviceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DeviceWindow)
    {
        DeviceWindow->setWindowTitle(QApplication::translate("DeviceWindow", "Create Router/Switch", 0, QApplication::UnicodeUTF8));
        labelHostname->setText(QApplication::translate("DeviceWindow", "Hostname:", 0, QApplication::UnicodeUTF8));
        lineHostname->setText(QApplication::translate("DeviceWindow", "hostname", 0, QApplication::UnicodeUTF8));
        labelIP->setText(QApplication::translate("DeviceWindow", "IPv4:", 0, QApplication::UnicodeUTF8));
        lineIP->setText(QApplication::translate("DeviceWindow", "10.10.10.10", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("DeviceWindow", "Type:", 0, QApplication::UnicodeUTF8));
        lineType->setText(QApplication::translate("DeviceWindow", "Router/Switch", 0, QApplication::UnicodeUTF8));
        labelType_2->setText(QApplication::translate("DeviceWindow", "Serie:", 0, QApplication::UnicodeUTF8));
        lineSerie->setText(QApplication::translate("DeviceWindow", "XXXX", 0, QApplication::UnicodeUTF8));
        labelInterfaces->setText(QApplication::translate("DeviceWindow", "Interfaces:", 0, QApplication::UnicodeUTF8));
        labelWarning->setText(QApplication::translate("DeviceWindow", "Warning:", 0, QApplication::UnicodeUTF8));
        textEditInterfaces->setHtml(QApplication::translate("DeviceWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Fa0/0</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DeviceWindow: public Ui_DeviceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEWINDOW_H
