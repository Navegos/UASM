#pragma once

#ifndef _PSEUDOFILTER_H_INCLUDED
#define _PSEUDOFILTER_H_INCLUDED

#include "basedefs.h"

uasm_PACK_PUSH_STACK

extern int uasm_ABI get_pseudoCMPXX(char*, char*, int);
extern int uasm_ABI get_pseudoVCMPXX(char*, char*, int);
extern int uasm_ABI get_pseudoPCLMULXX(char*, char*, int);
extern int uasm_ABI get_pseudoVPCLMULXX(char*, char*, int);

uasm_PACK_POP

#endif // _PSEUDOFILTER_H_INCLUDED
