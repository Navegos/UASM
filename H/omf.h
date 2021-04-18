#pragma once

/* interface to OMF format output functions */

#ifndef _OMF_H_INCLUDED_
#define _OMF_H_INCLUDED_

/* max size of LEDATA data is 1024 - (1+2+1/2+2/4+1) = 1014 */

#define MAX_LEDATA_THRESHOLD    (1024 - 10)

#include "basedefs.h"

uasm_PACK_PUSH_STACK

struct line_num_info;

void uasm_ABI      omf_init(struct module_info*);

void uasm_ABI      omf_set_filepos(void);
//void uasm_ABI      omf_write_ledata( struct dsym * );
void uasm_ABI      omf_OutSelect(bool);
void uasm_ABI      omf_FlushCurrSeg(void);
void uasm_ABI      omf_check_flush(const struct line_num_info*);

uasm_PACK_POP

#endif // _OMF_H_INCLUDED_
