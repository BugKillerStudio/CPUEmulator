#include "configer.h"
#include "ui_configer.h"

Configer::Configer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Configer)
{
    ui->setupUi(this);
}

Configer::~Configer()
{
    delete ui;
}
