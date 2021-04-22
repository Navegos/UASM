/****************************************************************************
*
* Description:  prototypes of extern.c
*
****************************************************************************/
#pragma once

#ifndef _EXTERN_H_
#define _EXTERN_H_

/*---------------------------------------------------------------------------*/

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern struct asym* UASM_ABI MakeExtern(const char*, enum memtype mem_type, struct asym*, struct asym*, uint_8);
extern void UASM_ABI        AddPublicData(struct asym*);
extern void UASM_ABI        FreePubQueue(void);

UASM_PACK_POP

#endif
