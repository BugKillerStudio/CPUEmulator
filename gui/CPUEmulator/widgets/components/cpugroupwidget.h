#ifndef CPUGROUPWIDGET_H
#define CPUGROUPWIDGET_H

#include <QWidget>

namespace Ui {
class CpuGroupWidget;
}

class CpuGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CpuGroupWidget(QWidget *parent = nullptr);
    ~CpuGroupWidget();

private:
    Ui::CpuGroupWidget *ui;
};

#endif // CPUGROUPWIDGET_H
