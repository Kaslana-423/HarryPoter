/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myWidget
{
public:
    QWidget *centralwidget;
    QPushButton *btnOpenFile;
    QPushButton *btnSearch;
    QLineEdit *lePattern;
    QComboBox *cbAlgorithm;
    QTextBrowser *tbLog;
    QTableWidget *tableWidgetResults;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myWidget)
    {
        if (myWidget->objectName().isEmpty())
            myWidget->setObjectName("myWidget");
        myWidget->resize(731, 522);
        centralwidget = new QWidget(myWidget);
        centralwidget->setObjectName("centralwidget");
        btnOpenFile = new QPushButton(centralwidget);
        btnOpenFile->setObjectName("btnOpenFile");
        btnOpenFile->setGeometry(QRect(60, 30, 101, 31));
        btnSearch = new QPushButton(centralwidget);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(60, 90, 101, 31));
        lePattern = new QLineEdit(centralwidget);
        lePattern->setObjectName("lePattern");
        lePattern->setGeometry(QRect(190, 30, 381, 31));
        cbAlgorithm = new QComboBox(centralwidget);
        cbAlgorithm->addItem(QString());
        cbAlgorithm->setObjectName("cbAlgorithm");
        cbAlgorithm->setGeometry(QRect(190, 90, 301, 31));
        tbLog = new QTextBrowser(centralwidget);
        tbLog->setObjectName("tbLog");
        tbLog->setGeometry(QRect(50, 360, 671, 121));
        tableWidgetResults = new QTableWidget(centralwidget);
        tableWidgetResults->setObjectName("tableWidgetResults");
        tableWidgetResults->setGeometry(QRect(40, 140, 671, 201));
        myWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myWidget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 731, 17));
        myWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(myWidget);
        statusbar->setObjectName("statusbar");
        myWidget->setStatusBar(statusbar);

        retranslateUi(myWidget);

        QMetaObject::connectSlotsByName(myWidget);
    } // setupUi

    void retranslateUi(QMainWindow *myWidget)
    {
        myWidget->setWindowTitle(QCoreApplication::translate("myWidget", "myWidget", nullptr));
        btnOpenFile->setText(QCoreApplication::translate("myWidget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        btnSearch->setText(QCoreApplication::translate("myWidget", "\346\220\234\347\264\242", nullptr));
        cbAlgorithm->setItemText(0, QCoreApplication::translate("myWidget", "bruteForce", nullptr));

    } // retranslateUi

};

namespace Ui {
    class myWidget: public Ui_myWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
