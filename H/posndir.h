/****************************************************************************
*
* Description:  interface posndir.c - handles ORG, ALIGN, EVEN directives
*
****************************************************************************/
#pragma once

#ifndef _POSNDIR_H_
#define _POSNDIR_H_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern void UASM_ABI AlignCurrOffset(int);

UASM_PACK_POP

#endif
