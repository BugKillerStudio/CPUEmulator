#include "memgroupwidget.h"
#include "ui_memgroupwidget.h"

MemGroupWidget::MemGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemGroupWidget)
{
    ui->setupUi(this);
}

MemGroupWidget::~MemGroupWidget()
{
    delete ui;
}

void MemGroupWidget::on_verticalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    emit dataChange(value);
}

void MemGroupWidget::on_spinBox_valueChanged(int arg1)
{
    ui->verticalSlider->setValue(arg1);
    emit dataChange(arg1);
}
