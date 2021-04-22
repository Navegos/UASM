/****************************************************************************
*
* Description:  header for BIN output format
*
****************************************************************************/
#pragma once

#ifndef _BIN_H_INCLUDED_
#define _BIN_H_INCLUDED_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

void UASM_ABI     bin_init(struct module_info*);

#if PE_SUPPORT
void UASM_ABI     pe_create_PE_header(void);
#endif

UASM_PACK_POP

#endif // _BIN_H_INCLUDED_
