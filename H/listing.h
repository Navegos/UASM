#pragma once

/****************************************************************************
*
* Description:  listing interface.
*
****************************************************************************/


#ifndef _LISTING_H_INCLUDED
#define _LISTING_H_INCLUDED

#include "basedefs.h"

UASM_PACK_PUSH_STACK

enum lsttype {
    LSTTYPE_DATA,
    LSTTYPE_CODE,
    LSTTYPE_EQUATE,
    LSTTYPE_TMACRO,
    LSTTYPE_DIRECTIVE,
    LSTTYPE_MACRO,
    LSTTYPE_STRUCT,
    LSTTYPE_LABEL,
    LSTTYPE_MACROLINE,
};

extern void UASM_ABI LstInit(void);
extern void UASM_ABI LstWrite(enum lsttype type, uint_32 ofs, void* sym);
extern void UASM_ABI LstWriteSrcLine(void);
extern void UASM_ABI LstWriteCRef(void);
extern void UASM_ABI LstPrintf(const char* format, ...);
extern void UASM_ABI LstNL(void);
#if FASTPASS
extern void UASM_ABI LstSetPosition(void);
#endif

UASM_PACK_POP

#endif
