#pragma once

#ifndef _FPFIXUP_H_INCLUDED
#define _FPFIXUP_H_INCLUDED

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern void UASM_ABI AddFloatingPointEmulationFixup(struct code_info*);

UASM_PACK_POP

#endif
