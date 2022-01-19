/********************************************************************************
** Form generated from reading UI file 'memgroupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMGROUPWIDGET_H
#define UI_MEMGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemGroupWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSlider *verticalSlider;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *MemGroupWidget)
    {
        if (MemGroupWidget->objectName().isEmpty())
            MemGroupWidget->setObjectName(QString::fromUtf8("MemGroupWidget"));
        MemGroupWidget->resize(400, 300);
        gridLayout = new QGridLayout(MemGroupWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(MemGroupWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSlider = new QSlider(groupBox);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(verticalSlider, 2, 0, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout_2->addWidget(spinBox, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);


        retranslateUi(MemGroupWidget);

        QMetaObject::connectSlotsByName(MemGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *MemGroupWidget)
    {
        MemGroupWidget->setWindowTitle(QCoreApplication::translate("MemGroupWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MemGroupWidget", "\345\206\205\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("MemGroupWidget", "\345\217\257\344\273\245\351\200\232\350\277\207\346\255\244\346\273\221\345\235\227\346\210\226\350\200\205\350\276\223\345\205\245\346\241\206\347\274\226\350\276\221\345\206\205\345\255\230", nullptr));
        label_2->setText(QCoreApplication::translate("MemGroupWidget", "MB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemGroupWidget: public Ui_MemGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMGROUPWIDGET_H
