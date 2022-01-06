#include "parsing.h"

Parsing::Parsing()
{

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
}
