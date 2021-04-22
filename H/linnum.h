#pragma once

#ifndef _LINNUM_H_
#define _LINNUM_H_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

/* internal line number information used if -Zd or -Zi is set */

struct line_num_info {
    struct line_num_info* next;
    uint_32 number; /* source line number (v2.06: changed to 32-bit */
    union {
        uint_32 offset;
        /* the next struct is set if sym is != NULL ( COFF only ) */
        struct {
            uint_32 line_number : 20,
                file : 12;
        };
    };
    union {
        unsigned srcfile;
        struct asym* sym; /* used if number is 0 ( COFF only ) */
    };
};

void UASM_ABI LinnumInit(void);
void UASM_ABI LinnumFini(void);
void UASM_ABI QueueDeleteLinnum(struct qdesc*);

UASM_PACK_POP

#endif // _LINNUM_H_
