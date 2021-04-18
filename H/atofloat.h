#pragma once

#ifndef ATOFLOAT_H
#define ATOFLOAT_H

#include "basedefs.h"

uasm_PACK_PUSH_STACK

extern void uasm_ABI atofloat(void*, const char*, unsigned, bool, uint_8);

uasm_PACK_POP

#endif
