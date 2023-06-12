/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *startGameButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName("widget");
        widget->resize(434, 572);
        centralwidget = new QWidget(widget);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 431, 481));
        startGameButton = new QPushButton(centralwidget);
        startGameButton->setObjectName("startGameButton");
        startGameButton->setGeometry(QRect(0, 480, 431, 41));
        widget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(widget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 434, 24));
        widget->setMenuBar(menubar);
        statusbar = new QStatusBar(widget);
        statusbar->setObjectName("statusbar");
        widget->setStatusBar(statusbar);

        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QMainWindow *widget)
    {
        widget->setWindowTitle(QCoreApplication::translate("widget", "widget", nullptr));
        startGameButton->setText(QCoreApplication::translate("widget", "Start Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
