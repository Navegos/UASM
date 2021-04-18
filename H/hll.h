/****************************************************************************
*
* Description:  hll constructs .IF, ...
*
****************************************************************************/
#pragma once

#ifndef _HLL_H_
#define _HLL_H_

#include "basedefs.h"

uasm_PACK_PUSH_STACK

extern void uasm_ABI HllInit( int );    /* reset counter for hll labels */
#if FASTMEM==0
extern void uasm_ABI HllFini( void );
#endif
extern void uasm_ABI HllCheckOpen( void );

extern uint_32 uasm_ABI GetHllLabel(void);

uasm_PACK_POP

#endif
