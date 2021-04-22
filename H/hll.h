/****************************************************************************
*
* Description:  hll constructs .IF, ...
*
****************************************************************************/
#pragma once

#ifndef _HLL_H_
#define _HLL_H_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern void UASM_ABI HllInit( int );    /* reset counter for hll labels */
#if FASTMEM==0
extern void UASM_ABI HllFini( void );
#endif
extern void UASM_ABI HllCheckOpen( void );

extern uint_32 UASM_ABI GetHllLabel(void);

UASM_PACK_POP

#endif
