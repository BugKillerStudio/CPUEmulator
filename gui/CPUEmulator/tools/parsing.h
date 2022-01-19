#ifndef PARSING_H
#define PARSING_H
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QVector>
#include <capstone.h>
#include "HeadStructs.h"

union IMAGE_NT_HEADERS32And64{
    IMAGE_NT_HEADERS64 peHeader64;
    IMAGE_NT_HEADERS32 peHeader32;
};
class Parsing
{
private:
    QFile file;
    IMAGE_DOS_HEADER dosHeader;
    IMAGE_NT_HEADERS64 peHeader64;
    union IMAGE_NT_HEADERS32And64 peHeader;
    QVector<QString> list;
    bool machineisX64();
    IMAGE_NT_HEADERS64 parsePeHead64();
public:
    Parsing(QString &_fileName);
    ~Parsing();
    csh handle;
    cs_insn *insn;
    void testPrint();

    IMAGE_DOS_HEADER parseDosHead();
    IMAGE_NT_HEADERS32And64 parsePeHead(bool &is64);
    QVector<QString> getAssemblyCode();

};

#endif // PARSING_H
