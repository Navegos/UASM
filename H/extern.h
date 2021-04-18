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

uasm_PACK_PUSH_STACK

extern struct asym* uasm_ABI MakeExtern(const char*, enum memtype mem_type, struct asym*, struct asym*, uint_8);
extern void uasm_ABI        AddPublicData(struct asym*);
extern void uasm_ABI        FreePubQueue(void);

uasm_PACK_POP

#endif
