
/* prototypes of functions defined in elf.c */
#pragma once

#ifndef _ELF_H_INCLUDED_
#define _ELF_H_INCLUDED_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

void UASM_ABI     elf_init(struct module_info*);

UASM_PACK_POP

#endif // _ELF_H_INCLUDED_
