#include "widgets/mainwindow.h"
#include <QApplication>
#include "tools/parsing.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Parsing p;
    p.testPrint();
    return a.exec();
}
