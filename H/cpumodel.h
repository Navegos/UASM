/****************************************************************************
*
* Description:  prototypes for cpumodel.c
*
****************************************************************************/
#pragma once

#ifndef _CPUMODEL_H_INCLUDED_
#define _CPUMODEL_H_INCLUDED_

#include "basedefs.h"

uasm_PACK_PUSH_STACK

extern ret_code uasm_ABI   SetCPU(enum cpu_info newcpu);
extern void uasm_ABI       SetModel(void);
static struct asym* sym_CodeSize; /* numeric. requires model */
static struct asym* sym_DataSize; /* numeric. requires model */

uasm_PACK_POP

#endif
