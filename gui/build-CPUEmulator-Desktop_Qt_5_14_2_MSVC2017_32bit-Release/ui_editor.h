/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QGridLayout *gridLayout;
    QWidget *breakPointWidget;
    QPlainTextEdit *addressEditor;
    QPlainTextEdit *binaryEditor;
    QPlainTextEdit *assemblyEditor;
    QPlainTextEdit *noteEditor;

    void setupUi(QWidget *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->setEnabled(true);
        Editor->resize(903, 515);
        gridLayout = new QGridLayout(Editor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        breakPointWidget = new QWidget(Editor);
        breakPointWidget->setObjectName(QString::fromUtf8("breakPointWidget"));

        gridLayout->addWidget(breakPointWidget, 0, 0, 1, 1);

        addressEditor = new QPlainTextEdit(Editor);
        addressEditor->setObjectName(QString::fromUtf8("addressEditor"));

        gridLayout->addWidget(addressEditor, 0, 1, 1, 1);

        binaryEditor = new QPlainTextEdit(Editor);
        binaryEditor->setObjectName(QString::fromUtf8("binaryEditor"));

        gridLayout->addWidget(binaryEditor, 0, 2, 1, 1);

        assemblyEditor = new QPlainTextEdit(Editor);
        assemblyEditor->setObjectName(QString::fromUtf8("assemblyEditor"));

        gridLayout->addWidget(assemblyEditor, 0, 3, 1, 1);

        noteEditor = new QPlainTextEdit(Editor);
        noteEditor->setObjectName(QString::fromUtf8("noteEditor"));

        gridLayout->addWidget(noteEditor, 0, 4, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 3);
        gridLayout->setColumnStretch(3, 3);
        gridLayout->setColumnStretch(4, 1);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QWidget *Editor)
    {
        Editor->setWindowTitle(QCoreApplication::translate("Editor", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
