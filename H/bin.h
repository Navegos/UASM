/****************************************************************************
*
* Description:  header for BIN output format
*
****************************************************************************/
#pragma once

#ifndef _BIN_H_INCLUDED_
#define _BIN_H_INCLUDED_

#include "basedefs.h"

uasm_PACK_PUSH_STACK

void uasm_ABI     bin_init(struct module_info*);

#if PE_SUPPORT
void uasm_ABI     pe_create_PE_header(void);
#endif

uasm_PACK_POP

#endif // _BIN_H_INCLUDED_
