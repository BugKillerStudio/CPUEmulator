#ifndef CORE_UNICORN_PUBLIC_H
#define CORE_UNICORN_PUBLIC_H

#include "core.h"

typedef struct _LIST_ENTRY
{
    struct _LIST_ENTRY* Flink;
    struct _LIST_ENTRY* Blink;

}LIST_ENTRY, * PLIST_ENTRY;

void InitializeListHead(PLIST_ENTRY listHead);
int InsertHeadList(PLIST_ENTRY listHead, PLIST_ENTRY node);
int InsertTailList(PLIST_ENTRY listHead, PLIST_ENTRY node);

#endif // !CORE_UNICORN_PUBLIC_H
