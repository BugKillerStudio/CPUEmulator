#include "widgets/mainwindow.h"
#include <QApplication>
#include "tools/parsing.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString str("D:/111.exe");
    Parsing p(str);
    p.getAssemblyCode();
    return a.exec();
}
