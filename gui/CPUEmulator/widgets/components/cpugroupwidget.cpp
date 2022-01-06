#include "cpugroupwidget.h"
#include "ui_cpugroupwidget.h"

CpuGroupWidget::CpuGroupWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CpuGroupWidget)
{
    ui->setupUi(this);
}

CpuGroupWidget::~CpuGroupWidget()
{
    delete ui;
}
