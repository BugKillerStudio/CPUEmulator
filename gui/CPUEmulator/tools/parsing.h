#ifndef PARSING_H
#define PARSING_H
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <QVector>
#include <capstone.h>
#include "HeadStructs.h"


class Parsing
{
public:
    Parsing(QString &_fileName);
    ~Parsing();
    csh handle;
    cs_insn *insn;
    void testPrint();
    IMAGE_DOS_HEADER parseDosHead();
    IMAGE_NT_HEADERS64 parsePeHead64();
    IMAGE_NT_HEADERS32 parsePeHead32();
    bool machineisX64();
    QVector<QString> getAssemblyCode();
private:
    QFile file;
    IMAGE_DOS_HEADER dosHeader;
    IMAGE_NT_HEADERS64 peHeader64;
    IMAGE_NT_HEADERS32 peHeader32;
    QVector<QString> list;
};

#endif // PARSING_H
