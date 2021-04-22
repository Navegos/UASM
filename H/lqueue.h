#pragma once

#ifndef _LQUEUE_H_INCLUDED
#define _LQUEUE_H_INCLUDED

#include "basedefs.h"

UASM_PACK_PUSH_STACK

/* v2.11: line queue functions moved from input.c to lqueue.c */

extern void UASM_ABI     DeleteLineQueue(void);
extern void UASM_ABI     AddLineQueue(const char* line);
extern void UASM_ABI     AddLineQueueX(const char* fmt, ...);
extern void UASM_ABI     RunLineQueue(void);
extern void UASM_ABI     BuildCodeLine(char* buffer, const char* fmt, ...);
//v2.11: replaced by macro
//extern bool   is_linequeue_populated( void );
#define is_linequeue_populated() ModuleInfo.g.line_queue.head

UASM_PACK_POP

#endif
