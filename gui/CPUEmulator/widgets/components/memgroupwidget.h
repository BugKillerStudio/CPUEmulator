#ifndef MEMGROUPWIDGET_H
#define MEMGROUPWIDGET_H

#include <QWidget>

namespace Ui {
class MemGroupWidget;
}

class MemGroupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MemGroupWidget(QWidget *parent = nullptr);
    ~MemGroupWidget();

private slots:
    void on_verticalSlider_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);

signals:
    void dataChange(int value);
private:
    Ui::MemGroupWidget *ui;
};

#endif // MEMGROUPWIDGET_H
