#ifndef CORE_UNICORN_PUBLIC_H
#define CORE_UNICORN_PUBLIC_H

#include "core.h"



void InitializeListHead(PLIST_ENTRY listHead);
int InsertHeadList(PLIST_ENTRY listHead, PLIST_ENTRY node);
int InsertTailList(PLIST_ENTRY listHead, PLIST_ENTRY node);
int RemoveEntryList(PLIST_ENTRY node);

#endif // !CORE_UNICORN_PUBLIC_H
