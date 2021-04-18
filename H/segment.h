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

uasm_PACK_PUSH_STACK

#define GetSegm( x )     (struct dsym *)x->segment

extern void uasm_ABI            SetSymSegOfs(struct asym*);
extern int uasm_ABI             GetSymOfssize(const struct asym*);
/* Get current segment's offset */
extern uint_32 uasm_ABI         GetCurrOffset(void);
extern ret_code uasm_ABI        SetCurrOffset(struct dsym*, uint_32, bool, bool);
extern struct asym* uasm_ABI    CreateIntSegment(const char*, const char*, uint_8, uint_8, bool);
/* get symbol's segment index, from the symbol itself */
extern unsigned uasm_ABI        GetSegIdx(const struct asym*);
extern void uasm_ABI            SegmentInit(int);     /* init segments */
extern void uasm_ABI            SegmentFini(void);    /* exit segments */
extern struct asym* uasm_ABI    GetGroup(const struct asym*);
extern uint_32 uasm_ABI         GetCurrSegAlign(void);
extern ret_code uasm_ABI        SetOfssize(void);
extern enum seg_type uasm_ABI   TypeFromClassName(const struct dsym*, const struct asym*);
extern void uasm_ABI            DefineFlatGroup(void);
extern ret_code uasm_ABI        SegmentModuleExit(void);
extern void uasm_ABI            DeleteGroup(struct dsym*);
//extern char uasm_ABI             *GetLname( int );
//extern void uasm_ABI             FreeLnameQueue( void );
extern void uasm_ABI            push_seg(struct dsym*);
extern void uasm_ABI            pop_seg(void);

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

extern char* uasm_ABI               SimGetSegName(enum sim_seg segno);
extern char const* const uasm_ABI   GetCodeClass(void);
extern ret_code uasm_ABI            ModelSimSegmInit(int type);
extern void uasm_ABI                ModelSimSegmExit(void);
extern void uasm_ABI                SetModelDefaultSegNames(void);

extern void uasm_ABI                UpdateCurrSegVars(void);

uasm_PACK_POP

#endif
