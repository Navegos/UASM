#pragma once

#ifndef _PSEUDOFILTER_H_INCLUDED
#define _PSEUDOFILTER_H_INCLUDED

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern int UASM_ABI get_pseudoCMPXX(char*, char*, int);
extern int UASM_ABI get_pseudoVCMPXX(char*, char*, int);
extern int UASM_ABI get_pseudoPCLMULXX(char*, char*, int);
extern int UASM_ABI get_pseudoVPCLMULXX(char*, char*, int);

UASM_PACK_POP

#endif // _PSEUDOFILTER_H_INCLUDED
