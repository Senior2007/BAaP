/********************************************************************************
** Form generated from reading UI file 'queuedemowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUEDEMOWINDOW_H
#define UI_QUEUEDEMOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueueDemoWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QueueDemoWindow)
    {
        if (QueueDemoWindow->objectName().isEmpty())
            QueueDemoWindow->setObjectName("QueueDemoWindow");
        QueueDemoWindow->resize(800, 600);
        centralwidget = new QWidget(QueueDemoWindow);
        centralwidget->setObjectName("centralwidget");
        QueueDemoWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QueueDemoWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        QueueDemoWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(QueueDemoWindow);
        statusbar->setObjectName("statusbar");
        QueueDemoWindow->setStatusBar(statusbar);

        retranslateUi(QueueDemoWindow);

        QMetaObject::connectSlotsByName(QueueDemoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QueueDemoWindow)
    {
        QueueDemoWindow->setWindowTitle(QCoreApplication::translate("QueueDemoWindow", "QueueDemoWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueueDemoWindow: public Ui_QueueDemoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUEDEMOWINDOW_H
