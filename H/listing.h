#pragma once

/****************************************************************************
*
* Description:  listing interface.
*
****************************************************************************/


#ifndef _LISTING_H_INCLUDED
#define _LISTING_H_INCLUDED

#include "basedefs.h"

uasm_PACK_PUSH_STACK

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

extern void uasm_ABI LstInit(void);
extern void uasm_ABI LstWrite(enum lsttype type, uint_32 ofs, void* sym);
extern void uasm_ABI LstWriteSrcLine(void);
extern void uasm_ABI LstWriteCRef(void);
extern void uasm_ABI LstPrintf(const char* format, ...);
extern void uasm_ABI LstNL(void);
#if FASTPASS
extern void uasm_ABI LstSetPosition(void);
#endif

uasm_PACK_POP

#endif
