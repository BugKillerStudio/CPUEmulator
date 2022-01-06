#ifndef CONFIGER_H
#define CONFIGER_H

#include <QWidget>

namespace Ui {
class Configer;
}

class Configer : public QWidget
{
    Q_OBJECT

public:
    explicit Configer(QWidget *parent = nullptr);
    ~Configer();

private:
    Ui::Configer *ui;
};

#endif // CONFIGER_H
