/****************************************************************************
*
*                            Open Watcom Project
*
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  prototypes for macro stuff
*
****************************************************************************/
#pragma once

#ifndef _MACRO_H_
#define _MACRO_H_

#define PLACEHOLDER_CHAR '\n' /* "escape" char for macro placeholders */

#include "basedefs.h"

UASM_PACK_PUSH_STACK

enum macro_flags {
#if MACROLABEL
    MF_LABEL = 0x01,   /* a label exists at pos 0 */
#endif
    MF_NOSAVE = 0x02,   /* no need to save/restore input status */
    MF_IGNARGS = 0x04   /* ignore additional arguments (for FOR directive) */
};

/* functions in expans.c */

extern int UASM_ABI      GetLiteralValue(char*, const char*);
extern int UASM_ABI      RunMacro(struct dsym*, int, struct asm_tok[], char*, int, bool*);
extern ret_code UASM_ABI ExpandText(char*, struct asm_tok[], unsigned int);
extern int UASM_ABI      ExpandLineItems(char*, int, struct asm_tok[], int, int);
extern ret_code UASM_ABI ExpandLine(char*, struct asm_tok[]);
extern void UASM_ABI     ExpandLiterals(int i, struct asm_tok[]);

/* functions in macro.c */

extern struct dsym* UASM_ABI CreateMacro(const char*);/* create a macro symbol */

extern void UASM_ABI     ReleaseMacroData(struct dsym*);
extern void UASM_ABI     fill_placeholders(char*, const char*, unsigned, unsigned, char**);
extern void UASM_ABI     SkipCurrentQueue(struct asm_tok[]);
extern ret_code UASM_ABI StoreMacro(struct dsym*, int, struct asm_tok[], bool);  /* store macro content */

extern ret_code UASM_ABI StoreAutoMacro(struct dsym*, int, struct asm_tok[], bool, char* macCode[], int, int);  /* store macro content 1st pass (builtin macros) */

extern ret_code UASM_ABI MacroInit(int);
#ifdef DEBUG_OUT
extern void UASM_ABI     MacroFini(void);
#endif

/* functions in string.c */

extern struct asym* UASM_ABI SetTextMacro(struct asm_tok[], struct asym*, const char*, const char*); /* EQU for texts */
extern struct asym* UASM_ABI AddPredefinedText(const char*, const char*);
extern int UASM_ABI         TextItemError(struct asm_tok*);

extern void UASM_ABI     StringInit(void);
#ifdef DEBUG_OUT
extern void UASM_ABI     StringFini(void);
#endif

UASM_PACK_POP

#endif
