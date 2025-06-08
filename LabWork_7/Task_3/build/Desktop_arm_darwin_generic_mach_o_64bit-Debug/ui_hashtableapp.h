/********************************************************************************
** Form generated from reading UI file 'hashtableapp.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASHTABLEAPP_H
#define UI_HASHTABLEAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HashTableApp
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HashTableApp)
    {
        if (HashTableApp->objectName().isEmpty())
            HashTableApp->setObjectName("HashTableApp");
        HashTableApp->resize(800, 600);
        centralwidget = new QWidget(HashTableApp);
        centralwidget->setObjectName("centralwidget");
        HashTableApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HashTableApp);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        HashTableApp->setMenuBar(menubar);
        statusbar = new QStatusBar(HashTableApp);
        statusbar->setObjectName("statusbar");
        HashTableApp->setStatusBar(statusbar);

        retranslateUi(HashTableApp);

        QMetaObject::connectSlotsByName(HashTableApp);
    } // setupUi

    void retranslateUi(QMainWindow *HashTableApp)
    {
        HashTableApp->setWindowTitle(QCoreApplication::translate("HashTableApp", "HashTableApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HashTableApp: public Ui_HashTableApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHTABLEAPP_H
