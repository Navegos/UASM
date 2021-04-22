#pragma once

#ifndef _ORGFIXUP_H_INCLUDED
#define _ORGFIXUP_H_INCLUDED

#include "basedefs.h"

UASM_PACK_PUSH_STACK

struct orgFixup
{
    int startPos;
    int orgValue;
    void* pNext;
};

extern void UASM_ABI AddOrgFixup(int curPos, int orgValue);

extern void UASM_ABI ResetOrgFixup();

extern bool UASM_ABI InOrgRange(int position);

UASM_PACK_POP

#endif
