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
* Description:  segment related prototypes & externals
*
****************************************************************************/
#pragma once

#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

#define GetSegm( x )     (struct dsym *)x->segment

extern void UASM_ABI            SetSymSegOfs(struct asym*);
extern int UASM_ABI             GetSymOfssize(const struct asym*);
/* Get current segment's offset */
extern uint_32 UASM_ABI         GetCurrOffset(void);
extern ret_code UASM_ABI        SetCurrOffset(struct dsym*, uint_32, bool, bool);
extern struct asym* UASM_ABI    CreateIntSegment(const char*, const char*, uint_8, uint_8, bool);
/* get symbol's segment index, from the symbol itself */
extern unsigned UASM_ABI        GetSegIdx(const struct asym*);
extern void UASM_ABI            SegmentInit(int);     /* init segments */
extern void UASM_ABI            SegmentFini(void);    /* exit segments */
extern struct asym* UASM_ABI    GetGroup(const struct asym*);
extern uint_32 UASM_ABI         GetCurrSegAlign(void);
extern ret_code UASM_ABI        SetOfssize(void);
extern enum seg_type UASM_ABI   TypeFromClassName(const struct dsym*, const struct asym*);
extern void UASM_ABI            DefineFlatGroup(void);
extern ret_code UASM_ABI        SegmentModuleExit(void);
extern void UASM_ABI            DeleteGroup(struct dsym*);
//extern char UASM_ABI             *GetLname( int );
//extern void UASM_ABI             FreeLnameQueue( void );
extern void UASM_ABI            push_seg(struct dsym*);
extern void UASM_ABI            pop_seg(void);

/* simplified segment functions */

enum sim_seg {
    SIM_CODE = 0,
    SIM_STACK,
    SIM_DATA,
    SIM_DATA_UN,            /* .DATA? */
    SIM_FARDATA,
    SIM_FARDATA_UN,         /* .FARDATA? */
    SIM_CONST,
    SIM_LAST
};

extern char* UASM_ABI               SimGetSegName(enum sim_seg segno);
extern char const* const UASM_ABI   GetCodeClass(void);
extern ret_code UASM_ABI            ModelSimSegmInit(int type);
extern void UASM_ABI                ModelSimSegmExit(void);
extern void UASM_ABI                SetModelDefaultSegNames(void);

extern void UASM_ABI                UpdateCurrSegVars(void);

UASM_PACK_POP

#endif
