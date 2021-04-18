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
* Description:  prototypes for input queueing/processing procedures
*
****************************************************************************/
#pragma once

#ifndef _INPUT_H_INCLUDED
#define _INPUT_H_INCLUDED

#include "basedefs.h"

uasm_PACK_PUSH_STACK

struct macro_instance {
    struct srcline* currline;
    struct srcline* startline;
    uint_32 localstart;
    char** parm_array;
    struct asym* macro;
    unsigned parmcnt;
};

/* for line numbers, the source files have to be stored
 * in a list in the very same order as they appear in
 * the input stream.
 */
struct file_seq {
    struct file_seq* next;
    uint_16         file;  /* index of file in FNames */
};

struct input_status {
    char* token_stringbuf;
    char* currsource;
    char* CurrComment;
    int token_count;
    char line_flags;/* v2.08: added */
#ifdef __I86__
    char* stringbufferend;
    struct asm_tok* tokenarray;
#endif
};

extern uint_32 uasm_ABI  GetLineNumber(void);
//#define LineNumber GetLineNumber()

extern char const* const uasm_ABI GetFNamePart(const char* fname);
extern char const* const uasm_ABI GetExtPart(const char* fname);

extern struct src_item* uasm_ABI PushSrcItem(char type, void* pv);

extern FILE* uasm_ABI   SearchFile(char* path, bool);
extern char* uasm_ABI   GetTextLine(char* buffer);
extern void uasm_ABI    PushMacro(struct macro_instance*);
extern void uasm_ABI    SetLineNumber(unsigned);
#if FASTMEM==0
extern bool uasm_ABI    MacroInUse(struct dsym*);
#endif
extern void uasm_ABI    AddStringToIncludePath(const char* string);
extern void uasm_ABI    InputInit(void);
extern void uasm_ABI    InputPassInit(void);
extern void uasm_ABI    InputFini(void);
extern struct asm_tok* uasm_ABI PushInputStatus(struct input_status*);
extern void  uasm_ABI   PopInputStatus(struct input_status*);
extern int uasm_ABI     GetCurrSrcPos(char*);
extern void  uasm_ABI   ClearSrcStack(void);
extern unsigned uasm_ABI get_curr_srcfile(void);
#if FASTPASS
extern void uasm_ABI    set_curr_srcfile(unsigned, uint_32);
#endif
extern struct fname_item const* const uasm_ABI GetFName(unsigned);
#ifdef DEBUG_OUT
extern char* uasm_ABI   GetTopLine(char*);
extern char* uasm_ABI   GetTopSrcName(void);
#endif

#define GetAlignedPointer( x, size ) ( x + ( ( size + 1 + sizeof(void *) - 1 ) & ~( sizeof(void *) - 1 ) ) )

uasm_PACK_POP

#endif
