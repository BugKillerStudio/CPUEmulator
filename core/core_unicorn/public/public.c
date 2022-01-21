#include "public.h"

void InitializeListHead(PLIST_ENTRY listHead)
{
    listHead->Flink = listHead->Blink = listHead;

    return;
}

int InsertHeadList(PLIST_ENTRY listHead, PLIST_ENTRY node)
{
    PLIST_ENTRY nextNode = NULL;

    if (listHead->Blink != listHead)
    {
        // Bad LIST_ENTRY struct
        return -1;
    }

    nextNode = listHead->Flink;
    node->Flink = nextNode;
    node->Blink = listHead;
    nextNode->Blink = node;
    listHead->Flink = node;

    return 0;
}

int InsertTailList(PLIST_ENTRY listHead, PLIST_ENTRY node)
{
    PLIST_ENTRY prevNode = NULL;

    if (listHead->Flink != listHead)
    {
        // Bad LIST_ENTRY struct
        return -1;
    }

    prevNode = listHead->Blink;
    node->Flink = listHead;
    node->Blink = prevNode;
    prevNode->Flink = node;
    listHead->Blink = node;

    return 0;
}

int RemoveEntryList(PLIST_ENTRY node)
{
    PLIST_ENTRY PrevEntry = NULL;
    PLIST_ENTRY NextEntry = NULL;

    NextEntry = node->Flink;
    PrevEntry = node->Blink;
    if ((NextEntry->Blink != node) || (PrevEntry->Flink != node))
    {
        // Bad LIST_ENTRY struct
        return -1;
    }

    PrevEntry->Flink = NextEntry;
    NextEntry->Blink = PrevEntry;
    
    return 0;
}


