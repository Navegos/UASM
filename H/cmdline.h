/****************************************************************************
*
* Description:  prototypes of cmdline.c
*
****************************************************************************/
#pragma once

#ifndef _CMDLINE_H_INCLUDED_
#define _CMDLINE_H_INCLUDED_

#ifdef __SW_BD
#define EXPQUAL __stdcall
#else
#define EXPQUAL
#endif

#include "basedefs.h"

UASM_PACK_PUSH_STACK

extern char* UASM_ABI ParseCmdline(char** cmdline, int*);
extern void UASM_ABI CmdlineFini(void);

UASM_PACK_POP

#endif // _CMDLINE_H_INCLUDED_
