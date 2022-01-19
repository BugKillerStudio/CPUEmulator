/********************************************************************************
** Form generated from reading UI file 'configer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGER_H
#define UI_CONFIGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Configer
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QWidget *tab_2;
    QWidget *tempWidget;

    void setupUi(QWidget *Configer)
    {
        if (Configer->objectName().isEmpty())
            Configer->setObjectName(QString::fromUtf8("Configer"));
        Configer->resize(677, 507);
        gridLayout_2 = new QGridLayout(Configer);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(Configer);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        tempWidget = new QWidget(Configer);
        tempWidget->setObjectName(QString::fromUtf8("tempWidget"));

        gridLayout_2->addWidget(tempWidget, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        retranslateUi(Configer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Configer);
    } // setupUi

    void retranslateUi(QWidget *Configer)
    {
        Configer->setWindowTitle(QCoreApplication::translate("Configer", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Configer", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Configer", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Configer: public Ui_Configer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGER_H
