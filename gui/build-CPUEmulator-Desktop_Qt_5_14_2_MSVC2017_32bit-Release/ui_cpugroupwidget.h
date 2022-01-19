/********************************************************************************
** Form generated from reading UI file 'cpugroupwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPUGROUPWIDGET_H
#define UI_CPUGROUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CpuGroupWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *archSeletion;
    QComboBox *CpuNumSelection;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QComboBox *coreNumSelection;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLabel *totalCoreNumLabel;

    void setupUi(QWidget *CpuGroupWidget)
    {
        if (CpuGroupWidget->objectName().isEmpty())
            CpuGroupWidget->setObjectName(QString::fromUtf8("CpuGroupWidget"));
        CpuGroupWidget->resize(400, 300);
        gridLayout_2 = new QGridLayout(CpuGroupWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(CpuGroupWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        archSeletion = new QComboBox(groupBox);
        archSeletion->setObjectName(QString::fromUtf8("archSeletion"));

        gridLayout->addWidget(archSeletion, 0, 1, 1, 1);

        CpuNumSelection = new QComboBox(groupBox);
        CpuNumSelection->setObjectName(QString::fromUtf8("CpuNumSelection"));

        gridLayout->addWidget(CpuNumSelection, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        coreNumSelection = new QComboBox(groupBox);
        coreNumSelection->setObjectName(QString::fromUtf8("coreNumSelection"));

        gridLayout->addWidget(coreNumSelection, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        totalCoreNumLabel = new QLabel(groupBox);
        totalCoreNumLabel->setObjectName(QString::fromUtf8("totalCoreNumLabel"));

        gridLayout->addWidget(totalCoreNumLabel, 4, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(CpuGroupWidget);

        QMetaObject::connectSlotsByName(CpuGroupWidget);
    } // setupUi

    void retranslateUi(QWidget *CpuGroupWidget)
    {
        CpuGroupWidget->setWindowTitle(QCoreApplication::translate("CpuGroupWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CpuGroupWidget", "\345\244\204\347\220\206\345\231\250", nullptr));
        label_3->setText(QCoreApplication::translate("CpuGroupWidget", "\346\257\217\344\270\252\345\244\204\347\220\206\345\231\250\345\206\205\346\240\270\346\225\260\351\207\217", nullptr));
        label->setText(QCoreApplication::translate("CpuGroupWidget", "\346\236\266\346\236\204", nullptr));
        label_2->setText(QCoreApplication::translate("CpuGroupWidget", "\345\244\204\347\220\206\345\231\250\346\225\260\351\207\217", nullptr));
        label_4->setText(QCoreApplication::translate("CpuGroupWidget", "\345\244\204\347\220\206\345\231\250\345\206\205\346\240\270\346\200\273\346\225\260:", nullptr));
        totalCoreNumLabel->setText(QCoreApplication::translate("CpuGroupWidget", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CpuGroupWidget: public Ui_CpuGroupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPUGROUPWIDGET_H
