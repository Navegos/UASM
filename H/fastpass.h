#pragma once

/* this is Public Domain.
 fastpass.h defines structures and externals which are needed by the
 "fast pass" feature. This feature speeds Uasm's assembly significantly
 if huge header files containing declarations and definitions are used
 (as it is the case with Win32Inc and Masm32), since the header files are
 then scanned in pass one only.
 */

#ifndef FASTPASS_H
#define FASTPASS_H

#include "basedefs.h"

UASM_PACK_PUSH_STACK

#if FASTPASS

 /* equ_item: used for a linked list of assembly time variables. Any variable
  which is defined or modified after SaveState() has been called is to be stored
  here - once! */

struct equ_item {
    struct equ_item* next;
    struct asym* sym;
    int lvalue;
    int hvalue;
    enum memtype mem_type; /* v2.07: added */
    bool isdefined;
};

/* line_item: used for a linked list of preprocessed lines. After SaveState()
 * has been called, all preprocessed lines are written in pass one and read
 * in further passes
 */

struct line_item {
    struct line_item* next;
    uint_32 lineno : 20, srcfile : 12;
    uint_32 list_pos; /* position .LST file */
    char line[1];
};

extern struct line_item* LineStoreCurr;

/* mod_state: used to store the module state within SaveState()
 */

struct mod_state {
    bool init;           /* is this struct initialized? */
    struct {
        struct equ_item* head; /* the list of modified assembly time variables */
        struct equ_item* tail;
    } Equ;
    uint_8 modinfo[sizeof(struct module_info) - sizeof(struct module_vars)];
};

/* source lines start to be "stored" when one of the following is detected:
 * - an instruction
 * - a data item (but not a struct field)
 * - directives which "generate source": PROC, INVOKE, .IF, .WHILE, .REPEAT
 * - directives ALIGN and ORG (which emit bytes and/or change $)
 * - directive END (to ensure that there is at least 1 line)
 * - directive ASSUME if operand is a forward reference
 */

 //extern struct mod_state modstate;
extern bool StoreState; /* is 1 if states are to be stored in pass one */

/* UseSavedState: is TRUE if preprocessed lines are to be read in pass 2,3,...
 * Currently, this flag is set DURING pass one! That's bad,
 * because it means that the flag itself doesn't tell whether
 * (preprocessed) lines are read.
 * the fix proposal is: set the flag - conditionally - AFTER pass one.
 * Also, rename the flag (perhaps UseSavedLines )!
 */
extern bool UseSavedState;

//void SaveState( void );
void UASM_ABI FastpassInit(void);
void UASM_ABI SegmentSaveState(void);
void UASM_ABI AssumeSaveState(void);
void UASM_ABI ContextSaveState(void);
void UASM_ABI StoreLine(const char*, int, uint_32);
void UASM_ABI SkipSavedState(void);
struct line_item* UASM_ABI RestoreState(void);
void UASM_ABI SaveVariableState(struct asym* sym);
void UASM_ABI FreeLineStore(void);

#define FStoreLine( flags ) if ( Parse_Pass == PASS_1 ) {StoreLine( CurrSource, flags, 0 );} else 

#else

#define FStoreLine( flags )

#endif

UASM_PACK_POP

#endif // FASTPASS_H

