/****************************************************************************
*
* Description:  msgtext.c interface
*
****************************************************************************/
#pragma once

#ifndef _MSGTEXT_H_
#define _MSGTEXT_H_

#include "basedefs.h"

UASM_PACK_PUSH_STACK

//extern const char *MsgGet( int, char * );
extern char const* const UASM_ABI MsgGetEx(int); /* doesn't need a buffer */

UASM_PACK_POP

#endif
