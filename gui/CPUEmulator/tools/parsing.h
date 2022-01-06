#ifndef PARSING_H
#define PARSING_H
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QByteArray>
#include <capstone.h>
#include "HeadStructs.h"


class Parsing
{
public:
    Parsing();
    csh handle;
    cs_insn *insn;
    void testPrint();

};

#endif // PARSING_H
