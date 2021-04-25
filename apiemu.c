/****************************************************************************
*
*  This code is Public Domain.
*
*  ========================================================================
*
*  Description: API emulations:
*               gcc:     strupr()
*               OW:      CharUpperA()
*
****************************************************************************/

#include "basedefs.h"

#if defined(__unix__)

UASM_PACK_PUSH_STACK

/* v2.12: _splitpath()/_makepath() removed */

char* UASM_ABI strupr(char* str)
/***********************/
{
    char* p;
    unsigned char   c;

    p = str;
    while ((c = *p))
    {
        c -= 'a';
        if (c <= 'z' - 'a')
        {
            c += 'A';
            *p = c;
        }
        ++p;
    }
    return(str);
}

UASM_PACK_POP

#endif

/* emulations for Open Watcom */

#if defined(__WATCOMC__) && !defined(__unix__)
#ifdef __FLAT__
#ifndef DEBUG_OUT /* OW v1.8 WDW has a problem with locally defined imports */

UASM_PACK_PUSH_STACK

union cu
{
    int c;
    char* p;
};

/* this is an emulation of the Win32 function which is called
 * by the OW runtime. It's the only USER32 function used.
 * By defining it here the binary will just need KERNEL32 to load.
 */
char* _stdcall CharUpperA(char* lpsz)
/**************************************/
{
    union cu p;
    p.p = lpsz;

    if (p.c < 0x10000)
        if (p.c >= 'a')
            return((char*)p.c - 0x20);
        else
            return((char*)p.c);
    else
        for (; *p.p; p.p++)
            if (*p.p >= 'a')
                *p.p = *p.p - 0x20;
    return(lpsz);
}
UASM_PACK_POP

#endif
#endif
#endif
