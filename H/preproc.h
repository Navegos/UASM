#pragma once

#ifndef _PREPROC_H_INCLUDED
#define _PREPROC_H_INCLUDED

/* v2.11: preprocessor functions moved from input.c to preproc.c */

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern int UASM_ABI      PreprocessLine(char*, struct asm_tok[]);
extern ret_code UASM_ABI WriteCodeLabel(char*, struct asm_tok[]);

UASM_PACK_POP

#endif
