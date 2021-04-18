#include <ctype.h>
#include "globals.h"
#include "memalloc.h"
#include "parser.h"
#include "myassert.h"

#include "orgfixup.h"

uasm_PACK_PUSH_STACK

struct orgFixup* pOrgTable = NULL;

void uasm_ABI AddOrgFixup(int curPos, int orgValue)
{
    struct orgFixup* curPtr = pOrgTable;
    struct orgFixup* pFixup = (struct orgFixup*)malloc(sizeof(struct orgFixup));
    pFixup->startPos = curPos;
    pFixup->orgValue = orgValue;
    pFixup->pNext = NULL;
    if (!curPtr)
    {
        curPtr = pFixup;
        pOrgTable = pFixup;
    }
    else
    {
        while (curPtr->pNext != NULL)
            curPtr = curPtr->pNext;
        curPtr->pNext = pFixup;
    }
    return;
}

void uasm_ABI ResetOrgFixup()
{
    struct orgFixup* curPtr = pOrgTable;
    struct orgFixup* nextPtr;

    if (!curPtr)
        return;

    nextPtr = curPtr->pNext;

    while (curPtr != NULL)
    {
        nextPtr = curPtr->pNext;
        free(curPtr);
        curPtr = nextPtr;
    }
    pOrgTable = NULL;
}

bool uasm_ABI InOrgRange(int position)
{
    struct orgFixup* curPtr = pOrgTable;
    bool retval = FALSE;
    if (curPtr)
    {
        while (curPtr)
        {
            if (position >= curPtr->startPos && position < curPtr->orgValue)
            {
                retval = TRUE;
                break;
            }
            curPtr = curPtr->pNext;
        }
    }
    return(retval);
}

uasm_PACK_POP
