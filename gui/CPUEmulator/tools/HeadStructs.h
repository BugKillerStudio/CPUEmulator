#ifndef HEADSTRUCTS_H
#define HEADSTRUCTS_H
typedef unsigned short      WORD;
typedef unsigned long       DWORD;
typedef unsigned char       UCHAR;
typedef unsigned long long ULONGLONG;
typedef char BYTE;
struct IMAGE_DOS_HEADER {
    WORD MZSignature;
    WORD UsedBytesInTheLastPage;
    WORD FileSizeInPages;
    WORD NumberOfRelocationItems;
    WORD HeaderSizeInParagraphs;
    WORD MinimumExtraParagraphs;
    WORD MaximumExtraParagraphs;
    WORD InitialSP;
    WORD Checksum;
    WORD InitialIP;
    WORD InitialRelativeCS;
    WORD AddressOfRelocationTable;
    WORD OverlayNumber;
    WORD Reserved[4];
    WORD OEMid;
    WORD OEMinfo;
    WORD Reserved2[10];
    long AddressOfNewExeHeader;
};
struct IMAGE_NT_HEADERS{
    DWORD Signature;
    struct _IMAGE_FILE_HEADER {
      WORD  Machine;
      WORD  NumberOfSections;
      DWORD TimeDateStamp;
      DWORD PointerToSymbolTable;
      DWORD NumberOfSymbols;
      WORD  SizeOfOptionalHeader;
      WORD  Characteristics;
    } IMAGE_FILE_HEADER;
    struct _IMAGE_OPTIONAL_HEADER64 {
      WORD                 Magic;
      BYTE                 MajorLinkerVersion;
      BYTE                 MinorLinkerVersion;
      DWORD                SizeOfCode;
      DWORD                SizeOfInitializedData;
      DWORD                SizeOfUninitializedData;
      DWORD                AddressOfEntryPoint;
      DWORD                BaseOfCode;
      ULONGLONG            ImageBase;
      DWORD                SectionAlignment;
      DWORD                FileAlignment;
      WORD                 MajorOperatingSystemVersion;
      WORD                 MinorOperatingSystemVersion;
      WORD                 MajorImageVersion;
      WORD                 MinorImageVersion;
      WORD                 MajorSubsystemVersion;
      WORD                 MinorSubsystemVersion;
      DWORD                Win32VersionValue;
      DWORD                SizeOfImage;
      DWORD                SizeOfHeaders;
      DWORD                CheckSum;
      WORD                 Subsystem;
      WORD                 DllCharacteristics;
      ULONGLONG            SizeOfStackReserve;
      ULONGLONG            SizeOfStackCommit;
      ULONGLONG            SizeOfHeapReserve;
      ULONGLONG            SizeOfHeapCommit;
      DWORD                LoaderFlags;
      DWORD                NumberOfRvaAndSizes;
      IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64;
};
struct IMAGE_DOS_STUB{
 UCHAR Data[64];
};


#endif // HEADSTRUCTS_H
