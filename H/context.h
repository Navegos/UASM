/****************************************************************************
*
* Description:  PUSHCONTEXT/POPCONTEXT interface
*
****************************************************************************/
#pragma once

#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

/*---------------------------------------------------------------------------*/

extern void UASM_ABI      ContextInit(int);
#if FASTMEM==0
extern void UASM_ABI      ContextFini(void);
#endif

UASM_PACK_POP

#endif
