/****************************************************************************
*
* Description:  prototypes for cpumodel.c
*
****************************************************************************/
#pragma once

#ifndef _CPUMODEL_H_INCLUDED_
#define _CPUMODEL_H_INCLUDED_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern ret_code UASM_ABI   SetCPU(enum cpu_info newcpu);
extern void UASM_ABI       SetModel(void);
static struct asym* sym_CodeSize; /* numeric. requires model */
static struct asym* sym_DataSize; /* numeric. requires model */

UASM_PACK_POP

#endif
