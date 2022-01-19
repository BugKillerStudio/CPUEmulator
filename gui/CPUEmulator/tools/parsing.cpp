#include "parsing.h"



Parsing::Parsing(QString &_fileName)
{
    file.setFileName(_fileName);
}

Parsing::~Parsing()
{
    if(file.isOpen())
        file.close();
}



void Parsing::testPrint()
{

    QFile file("D:/test.dat");
    file.open(QIODevice::ReadOnly);
    QByteArray byteArr = file.readAll();

    size_t count;
    if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
            qDebug()<<"CS_ERR_OK";

        count = cs_disasm(handle, (unsigned char*)byteArr.data(),byteArr.size(), 0x0000/*指令首地址*/, 0, &insn);
        if (count > 0) {
            size_t j;
            for (j = 0; j < count; j++) {
                qDebug()<<insn[j].address<<"\t" <<insn[j].mnemonic<<"\t"<<insn[j].op_str;
            }

            cs_free(insn, count);
        } else
            qDebug()<<"ERROR: Failed to disassemble given code!\n";

        cs_close(&handle);
        file.close();
        parsePeHead64();
}

IMAGE_DOS_HEADER Parsing::parseDosHead()
{
    file.open(QIODevice::ReadOnly);
    file.read((char *)&dosHeader,sizeof(IMAGE_DOS_HEADER));
    file.close();
    return dosHeader;
}

IMAGE_NT_HEADERS32And64 Parsing::parsePeHead(bool &is64)
{
    if(machineisX64()){
        peHeader.peHeader64 = peHeader64;
        is64 = true;
    }
    else{
        parseDosHead();
        file.open(QIODevice::ReadOnly);
        file.seek(dosHeader.e_lfanew);
        file.read((char *)&peHeader.peHeader32,sizeof(IMAGE_NT_HEADERS32));
        qDebug()<<"imageBase:"<<peHeader64.OptionalHeader.ImageBase;
        is64 = false;
    }
    return peHeader;

}

IMAGE_NT_HEADERS64 Parsing::parsePeHead64()
{
    parseDosHead();
    file.open(QIODevice::ReadOnly);
    file.seek(dosHeader.e_lfanew);
    file.read((char *)&peHeader64,sizeof(IMAGE_NT_HEADERS64));
    qDebug()<<"imageBase:"<<peHeader64.OptionalHeader.ImageBase;
    return peHeader64;
}

bool Parsing::machineisX64()
{
    parsePeHead64();
    if(peHeader64.FileHeader.Machine == IMAGE_FILE_MACHINE_AMD64){
        return true;
    }
    return false;
}

QVector<QString> Parsing::getAssemblyCode()
{
    size_t count;
    bool is64;
    parsePeHead(is64);

    if(is64){
        if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
                qDebug()<<"error";
        file.seek(peHeader64.OptionalHeader.BaseOfCode);
        QByteArray byteArr = file.read(peHeader64.OptionalHeader.SizeOfCode);
        count = cs_disasm(handle, (unsigned char*)byteArr.data(),byteArr.size(), peHeader.peHeader64.OptionalHeader.ImageBase+peHeader.peHeader64.OptionalHeader.BaseOfCode/*指令首地址*/, 0, &insn);
    }
    else{
        if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK)
                qDebug()<<"error";
        file.seek(peHeader.peHeader32.OptionalHeader.BaseOfCode);
        QByteArray byteArr = file.read(peHeader.peHeader32.OptionalHeader.SizeOfCode);
        count = cs_disasm(handle, (unsigned char*)byteArr.data(),byteArr.size(), peHeader.peHeader32.OptionalHeader.ImageBase+peHeader.peHeader32.OptionalHeader.BaseOfCode/*指令首地址*/, 0, &insn);
    }



        list.clear();
        if (count > 0) {
            size_t j;
            for (j = 0; j < count; j++) {
                QString str;
                str.sprintf("0x%-8x\t%0s\t%-32s\t%s\n",insn[j].address,insn[j].mnemonic,insn[j].op_str);
                qDebug()<<str;
            }

            cs_free(insn, count);
        } else
            qDebug()<<"ERROR: Failed to disassemble given code!\n";

        cs_close(&handle);
        return list;
}
