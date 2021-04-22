#pragma once

/* prototypes of TYPES.C */

#ifndef _TYPES_H_INCLUDED_
#define _TYPES_H_INCLUDED_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

/* qualified_type us used for parsing a qualified type. */
struct qualified_type {
    int             size;
    struct asym* symtype;
    enum memtype    mem_type;
    uint_8          is_ptr; /* contains level of indirection */
    uint_8          is_far;
    uint_8          Ofssize;
    enum memtype    ptr_memtype;
};

extern struct dsym* CurrStruct; /* start of current STRUCT list */

extern struct asym* UASM_ABI    CreateTypeSymbol(struct asym*, const char*, bool);
extern struct asym* UASM_ABI    SearchNameInStruct(const struct asym*, const char*, uint_32*, int level);
//extern ret_code UASM_ABI      EndstructDirective( int );
extern ret_code UASM_ABI        GetQualifiedType(int*, struct asm_tok[], struct qualified_type*);
extern struct asym* UASM_ABI    CreateStructField(int, struct asm_tok[], const char*, enum memtype mem_type, struct asym*, uint_32);
extern void UASM_ABI            UpdateStructSize(struct asym*);
extern ret_code UASM_ABI        SetStructCurrentOffset(int_32);
extern ret_code UASM_ABI        AlignInStruct(int);
extern void UASM_ABI            TypesInit(void);
extern void UASM_ABI            DeleteType(struct dsym*);

UASM_PACK_POP

#endif
