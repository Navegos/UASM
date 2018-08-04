
#include <ctype.h>
#include <time.h>
#include "globals.h"
#include "memalloc.h"
#include "input.h"
#include "parser.h"
#include "reswords.h"
#include "tokenize.h"
#include "condasm.h"
#include "segment.h"
#include "assume.h"
#include "proc.h"
#include "expreval.h"
#include "hll.h"
#include "context.h"
#include "types.h"
#include "label.h"
#include "macro.h"
#include "extern.h"
#include "fixup.h"
#include "omf.h"
#include "fastpass.h"
#include "listing.h"
#include "msgtext.h"
#include "myassert.h"
#include "linnum.h"
#include "cpumodel.h"
#include "lqueue.h"
#include "orgfixup.h"
#include "symbols.h"
#include "x86macros.h"

extern void     AddLineQueue(const char *line);
extern void     AddLineQueueX(const char *fmt, ...);

void Addx86defs()
{
	struct asym* sym = 0;

	AddLineQueue("IF @Platform EQ 0");
	AddLineQueue("IFNDEF WIN32");
	AddLineQueue("DEFINE WIN32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF _WIN32");
	AddLineQueue("DEFINE _WIN32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WIN32");
	AddLineQueue("DEFINE __WIN32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WIN32__");
	AddLineQueue("DEFINE __WIN32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF _M_IX86");
	AddLineQueue("DEFINE _M_IX86");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86__");
	AddLineQueue("DEFINE __x86__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86");
	AddLineQueue("DEFINE __x86");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF WINDOWS");
	AddLineQueue("DEFINE WINDOWS");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF _WINDOWS");
	AddLineQueue("DEFINE _WINDOWS");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WINDOWS");
	AddLineQueue("DEFINE __WINDOWS");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WINDOWS__");
	AddLineQueue("DEFINE __WINDOWS__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x32__");
	AddLineQueue("DEFINE __x32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x32");
	AddLineQueue("DEFINE __x32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __KNC__");
	AddLineQueue(".ERR <KNC not available in windows>");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __MIC__");
	AddLineQueue(".ERR <MIC not available in windows>");
	AddLineQueue("ENDIF");
	AddLineQueue("ENDIF");

	AddLineQueue("IF @Platform EQ 1");
	AddLineQueue("IFNDEF WIN64");
	AddLineQueue("DEFINE WIN64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF _WIN64");
	AddLineQueue("DEFINE _WIN64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WIN64");
	AddLineQueue("DEFINE __WIN64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WIN64__");
	AddLineQueue("DEFINE __WIN64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF _M_AMD64");
	AddLineQueue("DEFINE _M_AMD64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86_64__");
	AddLineQueue("DEFINE __x86_64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86_64");
	AddLineQueue("DEFINE __x86_64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF WINDOWS");
	AddLineQueue("DEFINE WINDOWS");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF _WINDOWS");
	AddLineQueue("DEFINE _WINDOWS");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WINDOWS");
	AddLineQueue("DEFINE __WINDOWS");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __WINDOWS__");
	AddLineQueue("DEFINE __WINDOWS__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x64__");
	AddLineQueue("DEFINE __x64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x64");
	AddLineQueue("DEFINE __x64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __KNC__");
	AddLineQueue(".ERR <KNC not available in windows>");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __MIC__");
	AddLineQueue(".ERR <MIC not available in windows>");
	AddLineQueue("ENDIF");
	AddLineQueue("ENDIF");

	AddLineQueue("IF @Platform EQ 2");
	AddLineQueue("IFNDEF __i386__");
	AddLineQueue("DEFINE __i386__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __i386");
	AddLineQueue("DEFINE __i386");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86__");
	AddLineQueue("DEFINE __x86__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86");
	AddLineQueue("DEFINE __x86");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF UNIX32");
	AddLineQueue("DEFINE UNIX32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF unix32");
	AddLineQueue("DEFINE unix32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX32__");
	AddLineQueue("DEFINE __UNIX32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix32__");
	AddLineQueue("DEFINE __unix32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX32");
	AddLineQueue("DEFINE __UNIX32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix32");
	AddLineQueue("DEFINE __unix32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF UNIX");
	AddLineQueue("DEFINE UNIX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF unix");
	AddLineQueue("DEFINE unix");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX__");
	AddLineQueue("DEFINE __UNIX__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix__");
	AddLineQueue("DEFINE __unix__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX");
	AddLineQueue("DEFINE __UNIX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix");
	AddLineQueue("DEFINE __unix");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF LINUX32");
	AddLineQueue("DEFINE LINUX32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF linux32");
	AddLineQueue("DEFINE linux32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX32__");
	AddLineQueue("DEFINE __LINUX32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux32__");
	AddLineQueue("DEFINE __linux32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX32");
	AddLineQueue("DEFINE __LINUX32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux32");
	AddLineQueue("DEFINE __linux32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF LINUX");
	AddLineQueue("DEFINE LINUX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF linux");
	AddLineQueue("DEFINE linux");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX__");
	AddLineQueue("DEFINE __LINUX__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux__");
	AddLineQueue("DEFINE __linux__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX");
	AddLineQueue("DEFINE __LINUX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux");
	AddLineQueue("DEFINE __linux");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x32__");
	AddLineQueue("DEFINE __x32__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x32");
	AddLineQueue("DEFINE __x32");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __KNC__");
	AddLineQueue(".ERR <KNC not available in unix/linux 32-bits>");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __MIC__");
	AddLineQueue(".ERR <MIC not available in unix/linux 32-bits>");
	AddLineQueue("ENDIF");
	AddLineQueue("ENDIF");

	AddLineQueue("IF @Platform EQ 3");
	AddLineQueue("IFNDEF __x86_64__");
	AddLineQueue("DEFINE __x86_64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86_64");
	AddLineQueue("DEFINE __x86_64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF UNIX64");
	AddLineQueue("DEFINE UNIX64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF unix64");
	AddLineQueue("DEFINE unix64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX64__");
	AddLineQueue("DEFINE __UNIX64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix64__");
	AddLineQueue("DEFINE __unix64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX64");
	AddLineQueue("DEFINE __UNIX64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix64");
	AddLineQueue("DEFINE __unix64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF UNIX");
	AddLineQueue("DEFINE UNIX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF unix");
	AddLineQueue("DEFINE unix");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX__");
	AddLineQueue("DEFINE __UNIX__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix__");
	AddLineQueue("DEFINE __unix__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX");
	AddLineQueue("DEFINE __UNIX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix");
	AddLineQueue("DEFINE __unix");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF LINUX64");
	AddLineQueue("DEFINE LINUX64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF linux64");
	AddLineQueue("DEFINE linux64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX64__");
	AddLineQueue("DEFINE __LINUX64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux64__");
	AddLineQueue("DEFINE __linux64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX64");
	AddLineQueue("DEFINE __LINUX64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux64");
	AddLineQueue("DEFINE __linux64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF LINUX");
	AddLineQueue("DEFINE LINUX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF linux");
	AddLineQueue("DEFINE linux");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX__");
	AddLineQueue("DEFINE __LINUX__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux__");
	AddLineQueue("DEFINE __linux__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __LINUX");
	AddLineQueue("DEFINE __LINUX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __linux");
	AddLineQueue("DEFINE __linux");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x64__");
	AddLineQueue("DEFINE __x64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x64");
	AddLineQueue("DEFINE __x64");
	AddLineQueue("ENDIF");
	AddLineQueue("ENDIF");

	AddLineQueue("IF @Platform EQ 4");
	AddLineQueue("IFNDEF __x86_64__");
	AddLineQueue("DEFINE __x86_64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x86_64");
	AddLineQueue("DEFINE __x86_64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF UNIX64");
	AddLineQueue("DEFINE UNIX64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF unix64");
	AddLineQueue("DEFINE unix64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX64__");
	AddLineQueue("DEFINE __UNIX64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix64__");
	AddLineQueue("DEFINE __unix64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX64");
	AddLineQueue("DEFINE __UNIX64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix64");
	AddLineQueue("DEFINE __unix64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF UNIX");
	AddLineQueue("DEFINE UNIX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF unix");
	AddLineQueue("DEFINE unix");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX__");
	AddLineQueue("DEFINE __UNIX__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix__");
	AddLineQueue("DEFINE __unix__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __UNIX");
	AddLineQueue("DEFINE __UNIX");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __unix");
	AddLineQueue("DEFINE __unix");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF MACH");
	AddLineQueue("DEFINE MACH");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __MACH");
	AddLineQueue("DEFINE __MACH");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __MACH__");
	AddLineQueue("DEFINE __MACH__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF APPLE");
	AddLineQueue("DEFINE APPLE");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __APPLE");
	AddLineQueue("DEFINE __APPLE");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __APPLE__");
	AddLineQueue("DEFINE __APPLE__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x64__");
	AddLineQueue("DEFINE __x64__");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF __x64");
	AddLineQueue("DEFINE __x64");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __KNC__");
	AddLineQueue(".ERR <KNC not available in MAC OS>");
	AddLineQueue("ENDIF");
	AddLineQueue("IFDEF __MIC__");
	AddLineQueue(".ERR <MIC not available in MAC OS>");
	AddLineQueue("ENDIF");
	AddLineQueue("ENDIF");

	AddLineQueue("IFDEF __WIN64__");
	AddLineQueue("IFNDEF DEFINED_VECTORCALL");
	AddLineQueue("DEFINE DEFINED_VECTORCALL");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF CALLCONV");
	AddLineQueue("CALLCONV TEXTEQU <VECTORCALL>");
	AddLineQueue("ENDIF");
	AddLineQueue("CALLCONVOPT TEXTEQU <option language:VECTORCALL>");
	/* 64bits*/
	AddLineQueue("rret TEXTEQU <rax>");
	AddLineQueue("rreturn TEXTEQU <rax>");
	AddLineQueue("rparam1 TEXTEQU <rcx>");
	AddLineQueue("rparam2 TEXTEQU <rdx>");
	AddLineQueue("rparam3 TEXTEQU <r8>");
	AddLineQueue("rparam4 TEXTEQU <r9>");
	AddLineQueue("rparam5 TEXTEQU <[rsp+40]>");
	AddLineQueue("rparam6 TEXTEQU <[rsp+48]>");
	AddLineQueue("rparam7 TEXTEQU <[rsp+56]>");
	AddLineQueue("rparam8 TEXTEQU <[rsp+64]>");
	AddLineQueue("rparam9 TEXTEQU <[rsp+72]>");
	AddLineQueue("rparam10 TEXTEQU <[rsp+80]>");
	AddLineQueue("rparam11 TEXTEQU <[rsp+88]>");
	AddLineQueue("rparam12 TEXTEQU <[rsp+96]>");
	AddLineQueue("rparam13 TEXTEQU <[rsp+104]>");
	AddLineQueue("rparam14 TEXTEQU <[rsp+112]>");
	AddLineQueue("rparam15 TEXTEQU <[rsp+120]>");
	AddLineQueue("rparam16 TEXTEQU <[rsp+128]>");
	AddLineQueue("rparam17 TEXTEQU <[rsp+136]>");
	AddLineQueue("rparam18 TEXTEQU <[rsp+144]>");
	AddLineQueue("rparam19 TEXTEQU <[rsp+152]>");
	AddLineQueue("rparam20 TEXTEQU <[rsp+160]>");
	AddLineQueue("rparam21 TEXTEQU <[rsp+168]>");
	AddLineQueue("rparam22 TEXTEQU <[rsp+176]>");
	AddLineQueue("rparam23 TEXTEQU <[rsp+184]>");
	AddLineQueue("rparam24 TEXTEQU <[rsp+192]>");
	AddLineQueue("rparam25 TEXTEQU <[rsp+200]>");
	AddLineQueue("rparam26 TEXTEQU <[rsp+208]>");
	AddLineQueue("rparam27 TEXTEQU <[rsp+216]>");
	AddLineQueue("rparam28 TEXTEQU <[rsp+224]>");
	AddLineQueue("rparam29 TEXTEQU <[rsp+232]>");
	AddLineQueue("rparam30 TEXTEQU <[rsp+240]>");
	AddLineQueue("rparam31 TEXTEQU <[rsp+248]>");
	AddLineQueue("rparam32 TEXTEQU <[rsp+256]>");
	AddLineQueue("rparam33 TEXTEQU <[rsp+264]>");
	AddLineQueue("rparam34 TEXTEQU <[rsp+272]>");
	AddLineQueue("rparam35 TEXTEQU <[rsp+280]>");
	AddLineQueue("rparam36 TEXTEQU <[rsp+288]>");
	AddLineQueue("rparam37 TEXTEQU <[rsp+296]>");
	AddLineQueue("rparam38 TEXTEQU <[rsp+304]>");
	AddLineQueue("rparam39 TEXTEQU <[rsp+312]>");
	AddLineQueue("rparam40 TEXTEQU <[rsp+320]>");
	AddLineQueue("rparam41 TEXTEQU <[rsp+328]>");
	AddLineQueue("rparam42 TEXTEQU <[rsp+336]>");
	AddLineQueue("rparam43 TEXTEQU <[rsp+344]>");
	AddLineQueue("rparam44 TEXTEQU <[rsp+352]>");
	AddLineQueue("rparam45 TEXTEQU <[rsp+360]>");
	AddLineQueue("rparam46 TEXTEQU <[rsp+368]>");
	AddLineQueue("rparam47 TEXTEQU <[rsp+376]>");
	AddLineQueue("rparam48 TEXTEQU <[rsp+384]>");
	AddLineQueue("rparam49 TEXTEQU <[rsp+392]>");
	AddLineQueue("rparam50 TEXTEQU <[rsp+400]>");
	AddLineQueue("rparam51 TEXTEQU <[rsp+408]>");
	AddLineQueue("rparam52 TEXTEQU <[rsp+416]>");
	AddLineQueue("rparam53 TEXTEQU <[rsp+424]>");
	AddLineQueue("rparam54 TEXTEQU <[rsp+432]>");
	AddLineQueue("rparam55 TEXTEQU <[rsp+440]>");
	AddLineQueue("rparam56 TEXTEQU <[rsp+448]>");
	AddLineQueue("rparam57 TEXTEQU <[rsp+456]>");
	AddLineQueue("rparam58 TEXTEQU <[rsp+464]>");
	AddLineQueue("rparam69 TEXTEQU <[rsp+472]>");
	AddLineQueue("rparam60 TEXTEQU <[rsp+480]>");
	AddLineQueue("rparam61 TEXTEQU <[rsp+488]>");
	AddLineQueue("rparam62 TEXTEQU <[rsp+496]>");
	AddLineQueue("rparam63 TEXTEQU <[rsp+504]>");
	AddLineQueue("rparam64 TEXTEQU <[rsp+512]>");
	/* 32bits*/
	AddLineQueue("dret TEXTEQU <eax>");
	AddLineQueue("dreturn TEXTEQU <eax>");
	AddLineQueue("dparam1 TEXTEQU <ecx>");
	AddLineQueue("dparam2 TEXTEQU <edx>");
	AddLineQueue("dparam3 TEXTEQU <r8d>");
	AddLineQueue("dparam4 TEXTEQU <r9d>");
	AddLineQueue("dparam5 TEXTEQU <[esp+20]>");
	AddLineQueue("dparam6 TEXTEQU <[esp+24]>");
	AddLineQueue("dparam7 TEXTEQU <[esp+28]>");
	AddLineQueue("dparam8 TEXTEQU <[esp+32]>");
	AddLineQueue("dparam9 TEXTEQU <[esp+36]>");
	AddLineQueue("dparam10 TEXTEQU <[esp+40]>");
	AddLineQueue("dparam11 TEXTEQU <[esp+44]>");
	AddLineQueue("dparam12 TEXTEQU <[esp+48]>");
	AddLineQueue("dparam13 TEXTEQU <[esp+52]>");
	AddLineQueue("dparam14 TEXTEQU <[esp+56]>");
	AddLineQueue("dparam15 TEXTEQU <[esp+60]>");
	AddLineQueue("dparam16 TEXTEQU <[esp+64]>");
	AddLineQueue("dparam17 TEXTEQU <[esp+68]>");
	AddLineQueue("dparam18 TEXTEQU <[esp+72]>");
	AddLineQueue("dparam19 TEXTEQU <[esp+76]>");
	AddLineQueue("dparam20 TEXTEQU <[esp+80]>");
	AddLineQueue("dparam21 TEXTEQU <[esp+84]>");
	AddLineQueue("dparam22 TEXTEQU <[esp+88]>");
	AddLineQueue("dparam23 TEXTEQU <[esp+92]>");
	AddLineQueue("dparam24 TEXTEQU <[esp+96]>");
	AddLineQueue("dparam25 TEXTEQU <[esp+100]>");
	AddLineQueue("dparam26 TEXTEQU <[esp+104]>");
	AddLineQueue("dparam27 TEXTEQU <[esp+108]>");
	AddLineQueue("dparam28 TEXTEQU <[esp+112]>");
	AddLineQueue("dparam29 TEXTEQU <[esp+116]>");
	AddLineQueue("dparam30 TEXTEQU <[esp+120]>");
	AddLineQueue("dparam31 TEXTEQU <[esp+124]>");
	AddLineQueue("dparam32 TEXTEQU <[esp+128]>");
	AddLineQueue("dparam33 TEXTEQU <[esp+132]>");
	AddLineQueue("dparam34 TEXTEQU <[esp+136]>");
	AddLineQueue("dparam35 TEXTEQU <[esp+140]>");
	AddLineQueue("dparam36 TEXTEQU <[esp+144]>");
	AddLineQueue("dparam37 TEXTEQU <[esp+148]>");
	AddLineQueue("dparam38 TEXTEQU <[esp+152]>");
	AddLineQueue("dparam39 TEXTEQU <[esp+156]>");
	AddLineQueue("dparam40 TEXTEQU <[esp+160]>");
	AddLineQueue("dparam41 TEXTEQU <[esp+164]>");
	AddLineQueue("dparam42 TEXTEQU <[esp+168]>");
	AddLineQueue("dparam43 TEXTEQU <[esp+172]>");
	AddLineQueue("dparam44 TEXTEQU <[esp+176]>");
	AddLineQueue("dparam45 TEXTEQU <[esp+180]>");
	AddLineQueue("dparam46 TEXTEQU <[esp+184]>");
	AddLineQueue("dparam47 TEXTEQU <[esp+188]>");
	AddLineQueue("dparam48 TEXTEQU <[esp+192]>");
	AddLineQueue("dparam49 TEXTEQU <[esp+196]>");
	AddLineQueue("dparam50 TEXTEQU <[esp+200]>");
	AddLineQueue("dparam51 TEXTEQU <[esp+204]>");
	AddLineQueue("dparam52 TEXTEQU <[esp+208]>");
	AddLineQueue("dparam53 TEXTEQU <[esp+212]>");
	AddLineQueue("dparam54 TEXTEQU <[esp+216]>");
	AddLineQueue("dparam55 TEXTEQU <[esp+220]>");
	AddLineQueue("dparam56 TEXTEQU <[esp+224]>");
	AddLineQueue("dparam57 TEXTEQU <[esp+228]>");
	AddLineQueue("dparam58 TEXTEQU <[esp+232]>");
	AddLineQueue("dparam69 TEXTEQU <[esp+236]>");
	AddLineQueue("dparam60 TEXTEQU <[esp+240]>");
	AddLineQueue("dparam61 TEXTEQU <[esp+244]>");
	AddLineQueue("dparam62 TEXTEQU <[esp+248]>");
	AddLineQueue("dparam63 TEXTEQU <[esp+252]>");
	AddLineQueue("dparam64 TEXTEQU <[esp+256]>");
	AddLineQueue("ENDIF"); /*__WIN64__*/

	AddLineQueue("IFDEF __WIN32__");
	AddLineQueue("IFDEF __WIN32_VECTORCALL__"); /*not available with uasm macrolib*/
	AddLineQueue("IFNDEF DEFINED_VECTORCALL");
	AddLineQueue("DEFINE DEFINED_VECTORCALL");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF CALLCONV");
	AddLineQueue("CALLCONV TEXTEQU <VECTORCALL>");
	AddLineQueue("ENDIF");
	AddLineQueue("CALLCONVOPT TEXTEQU <option language:VECTORCALL>");
	AddLineQueue("ELSE");
	AddLineQueue("IFNDEF CALLCONV");
	AddLineQueue("CALLCONV TEXTEQU <FASTCALL>");
	AddLineQueue("ENDIF");
	AddLineQueue("CALLCONVOPT TEXTEQU <option language:FASTCALL>");
	AddLineQueue("ENDIF");
	/* 64bits*/
	AddLineQueue("rret TEXTEQU <eax>");
	AddLineQueue("rreturn TEXTEQU <eax>");
	AddLineQueue("rparam1 TEXTEQU <ecx>");
	AddLineQueue("rparam2 TEXTEQU <edx>");
	AddLineQueue("rparam3 TEXTEQU <[esp+12]>");
	AddLineQueue("rparam4 TEXTEQU <[esp+16]>");
	AddLineQueue("rparam5 TEXTEQU <[esp+20]>");
	AddLineQueue("rparam6 TEXTEQU <[esp+24]>");
	AddLineQueue("rparam7 TEXTEQU <[esp+28]>");
	AddLineQueue("rparam8 TEXTEQU <[esp+32]>");
	AddLineQueue("rparam9 TEXTEQU <[esp+36]>");
	AddLineQueue("rparam10 TEXTEQU <[esp+40]>");
	AddLineQueue("rparam11 TEXTEQU <[esp+44]>");
	AddLineQueue("rparam12 TEXTEQU <[esp+48]>");
	AddLineQueue("rparam13 TEXTEQU <[esp+52]>");
	AddLineQueue("rparam14 TEXTEQU <[esp+56]>");
	AddLineQueue("rparam15 TEXTEQU <[esp+60]>");
	AddLineQueue("rparam16 TEXTEQU <[esp+64]>");
	AddLineQueue("rparam17 TEXTEQU <[esp+68]>");
	AddLineQueue("rparam18 TEXTEQU <[esp+72]>");
	AddLineQueue("rparam19 TEXTEQU <[esp+76]>");
	AddLineQueue("rparam20 TEXTEQU <[esp+80]>");
	AddLineQueue("rparam21 TEXTEQU <[esp+84]>");
	AddLineQueue("rparam22 TEXTEQU <[esp+88]>");
	AddLineQueue("rparam23 TEXTEQU <[esp+92]>");
	AddLineQueue("rparam24 TEXTEQU <[esp+96]>");
	AddLineQueue("rparam25 TEXTEQU <[esp+100]>");
	AddLineQueue("rparam26 TEXTEQU <[esp+104]>");
	AddLineQueue("rparam27 TEXTEQU <[esp+108]>");
	AddLineQueue("rparam28 TEXTEQU <[esp+112]>");
	AddLineQueue("rparam29 TEXTEQU <[esp+116]>");
	AddLineQueue("rparam30 TEXTEQU <[esp+120]>");
	AddLineQueue("rparam31 TEXTEQU <[esp+124]>");
	AddLineQueue("rparam32 TEXTEQU <[esp+128]>");
	AddLineQueue("rparam33 TEXTEQU <[esp+132]>");
	AddLineQueue("rparam34 TEXTEQU <[esp+136]>");
	AddLineQueue("rparam35 TEXTEQU <[esp+140]>");
	AddLineQueue("rparam36 TEXTEQU <[esp+144]>");
	AddLineQueue("rparam37 TEXTEQU <[esp+148]>");
	AddLineQueue("rparam38 TEXTEQU <[esp+152]>");
	AddLineQueue("rparam39 TEXTEQU <[esp+156]>");
	AddLineQueue("rparam40 TEXTEQU <[esp+160]>");
	AddLineQueue("rparam41 TEXTEQU <[esp+164]>");
	AddLineQueue("rparam42 TEXTEQU <[esp+168]>");
	AddLineQueue("rparam43 TEXTEQU <[esp+172]>");
	AddLineQueue("rparam44 TEXTEQU <[esp+176]>");
	AddLineQueue("rparam45 TEXTEQU <[esp+180]>");
	AddLineQueue("rparam46 TEXTEQU <[esp+184]>");
	AddLineQueue("rparam47 TEXTEQU <[esp+188]>");
	AddLineQueue("rparam48 TEXTEQU <[esp+192]>");
	AddLineQueue("rparam49 TEXTEQU <[esp+196]>");
	AddLineQueue("rparam50 TEXTEQU <[esp+200]>");
	AddLineQueue("rparam51 TEXTEQU <[esp+204]>");
	AddLineQueue("rparam52 TEXTEQU <[esp+208]>");
	AddLineQueue("rparam53 TEXTEQU <[esp+212]>");
	AddLineQueue("rparam54 TEXTEQU <[esp+216]>");
	AddLineQueue("rparam55 TEXTEQU <[esp+220]>");
	AddLineQueue("rparam56 TEXTEQU <[esp+224]>");
	AddLineQueue("rparam57 TEXTEQU <[esp+228]>");
	AddLineQueue("rparam58 TEXTEQU <[esp+232]>");
	AddLineQueue("rparam69 TEXTEQU <[esp+236]>");
	AddLineQueue("rparam60 TEXTEQU <[esp+240]>");
	AddLineQueue("rparam61 TEXTEQU <[esp+244]>");
	AddLineQueue("rparam62 TEXTEQU <[esp+248]>");
	AddLineQueue("rparam63 TEXTEQU <[esp+252]>");
	AddLineQueue("rparam64 TEXTEQU <[esp+256]>");
	/* 32bits*/
	AddLineQueue("dret TEXTEQU <eax>");
	AddLineQueue("dreturn TEXTEQU <eax>");
	AddLineQueue("dparam1 TEXTEQU <ecx>");
	AddLineQueue("dparam2 TEXTEQU <edx>");
	AddLineQueue("dparam3 TEXTEQU <r8d>");
	AddLineQueue("dparam4 TEXTEQU <r9d>");
	AddLineQueue("dparam5 TEXTEQU <[esp+20]>");
	AddLineQueue("dparam6 TEXTEQU <[esp+24]>");
	AddLineQueue("dparam7 TEXTEQU <[esp+28]>");
	AddLineQueue("dparam8 TEXTEQU <[esp+32]>");
	AddLineQueue("dparam9 TEXTEQU <[esp+36]>");
	AddLineQueue("dparam10 TEXTEQU <[esp+40]>");
	AddLineQueue("dparam11 TEXTEQU <[esp+44]>");
	AddLineQueue("dparam12 TEXTEQU <[esp+48]>");
	AddLineQueue("dparam13 TEXTEQU <[esp+52]>");
	AddLineQueue("dparam14 TEXTEQU <[esp+56]>");
	AddLineQueue("dparam15 TEXTEQU <[esp+60]>");
	AddLineQueue("dparam16 TEXTEQU <[esp+64]>");
	AddLineQueue("dparam17 TEXTEQU <[esp+68]>");
	AddLineQueue("dparam18 TEXTEQU <[esp+72]>");
	AddLineQueue("dparam19 TEXTEQU <[esp+76]>");
	AddLineQueue("dparam20 TEXTEQU <[esp+80]>");
	AddLineQueue("dparam21 TEXTEQU <[esp+84]>");
	AddLineQueue("dparam22 TEXTEQU <[esp+88]>");
	AddLineQueue("dparam23 TEXTEQU <[esp+92]>");
	AddLineQueue("dparam24 TEXTEQU <[esp+96]>");
	AddLineQueue("dparam25 TEXTEQU <[esp+100]>");
	AddLineQueue("dparam26 TEXTEQU <[esp+104]>");
	AddLineQueue("dparam27 TEXTEQU <[esp+108]>");
	AddLineQueue("dparam28 TEXTEQU <[esp+112]>");
	AddLineQueue("dparam29 TEXTEQU <[esp+116]>");
	AddLineQueue("dparam30 TEXTEQU <[esp+120]>");
	AddLineQueue("dparam31 TEXTEQU <[esp+124]>");
	AddLineQueue("dparam32 TEXTEQU <[esp+128]>");
	AddLineQueue("dparam33 TEXTEQU <[esp+132]>");
	AddLineQueue("dparam34 TEXTEQU <[esp+136]>");
	AddLineQueue("dparam35 TEXTEQU <[esp+140]>");
	AddLineQueue("dparam36 TEXTEQU <[esp+144]>");
	AddLineQueue("dparam37 TEXTEQU <[esp+148]>");
	AddLineQueue("dparam38 TEXTEQU <[esp+152]>");
	AddLineQueue("dparam39 TEXTEQU <[esp+156]>");
	AddLineQueue("dparam40 TEXTEQU <[esp+160]>");
	AddLineQueue("dparam41 TEXTEQU <[esp+164]>");
	AddLineQueue("dparam42 TEXTEQU <[esp+168]>");
	AddLineQueue("dparam43 TEXTEQU <[esp+172]>");
	AddLineQueue("dparam44 TEXTEQU <[esp+176]>");
	AddLineQueue("dparam45 TEXTEQU <[esp+180]>");
	AddLineQueue("dparam46 TEXTEQU <[esp+184]>");
	AddLineQueue("dparam47 TEXTEQU <[esp+188]>");
	AddLineQueue("dparam48 TEXTEQU <[esp+192]>");
	AddLineQueue("dparam49 TEXTEQU <[esp+196]>");
	AddLineQueue("dparam50 TEXTEQU <[esp+200]>");
	AddLineQueue("dparam51 TEXTEQU <[esp+204]>");
	AddLineQueue("dparam52 TEXTEQU <[esp+208]>");
	AddLineQueue("dparam53 TEXTEQU <[esp+212]>");
	AddLineQueue("dparam54 TEXTEQU <[esp+216]>");
	AddLineQueue("dparam55 TEXTEQU <[esp+220]>");
	AddLineQueue("dparam56 TEXTEQU <[esp+224]>");
	AddLineQueue("dparam57 TEXTEQU <[esp+228]>");
	AddLineQueue("dparam58 TEXTEQU <[esp+232]>");
	AddLineQueue("dparam69 TEXTEQU <[esp+236]>");
	AddLineQueue("dparam60 TEXTEQU <[esp+240]>");
	AddLineQueue("dparam61 TEXTEQU <[esp+244]>");
	AddLineQueue("dparam62 TEXTEQU <[esp+248]>");
	AddLineQueue("dparam63 TEXTEQU <[esp+252]>");
	AddLineQueue("dparam64 TEXTEQU <[esp+256]>");
	AddLineQueue("ENDIF"); /*__WIN32__*/

	AddLineQueue("IFDEF __UNIX64__");
	AddLineQueue("IFNDEF DEFINED_SYSTEMV");
	AddLineQueue("DEFINE DEFINED_SYSTEMV");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF CALLCONV");
	AddLineQueue("CALLCONV TEXTEQU <SYSTEMV>");
	AddLineQueue("ENDIF");
	AddLineQueue("CALLCONVOPT TEXTEQU <option language:SYSTEMV>");
	/* 64bits*/
	AddLineQueue("rret TEXTEQU <rax>");
	AddLineQueue("rreturn TEXTEQU <rax>");
	AddLineQueue("rparam1 TEXTEQU <rdi>");
	AddLineQueue("rparam2 TEXTEQU <rsi>");
	AddLineQueue("rparam3 TEXTEQU <rdx>");
	AddLineQueue("rparam4 TEXTEQU <rcx>");
	AddLineQueue("rparam5 TEXTEQU <r8>");
	AddLineQueue("rparam6 TEXTEQU <r9>");
	AddLineQueue("rparam7 TEXTEQU <[rsp+56]>");
	AddLineQueue("rparam8 TEXTEQU <[rsp+64]>");
	AddLineQueue("rparam9 TEXTEQU <[rsp+72]>");
	AddLineQueue("rparam10 TEXTEQU <[rsp+80]>");
	AddLineQueue("rparam11 TEXTEQU <[rsp+88]>");
	AddLineQueue("rparam12 TEXTEQU <[rsp+96]>");
	AddLineQueue("rparam13 TEXTEQU <[rsp+104]>");
	AddLineQueue("rparam14 TEXTEQU <[rsp+112]>");
	AddLineQueue("rparam15 TEXTEQU <[rsp+120]>");
	AddLineQueue("rparam16 TEXTEQU <[rsp+128]>");
	AddLineQueue("rparam17 TEXTEQU <[rsp+136]>");
	AddLineQueue("rparam18 TEXTEQU <[rsp+144]>");
	AddLineQueue("rparam19 TEXTEQU <[rsp+152]>");
	AddLineQueue("rparam20 TEXTEQU <[rsp+160]>");
	AddLineQueue("rparam21 TEXTEQU <[rsp+168]>");
	AddLineQueue("rparam22 TEXTEQU <[rsp+176]>");
	AddLineQueue("rparam23 TEXTEQU <[rsp+184]>");
	AddLineQueue("rparam24 TEXTEQU <[rsp+192]>");
	AddLineQueue("rparam25 TEXTEQU <[rsp+200]>");
	AddLineQueue("rparam26 TEXTEQU <[rsp+208]>");
	AddLineQueue("rparam27 TEXTEQU <[rsp+216]>");
	AddLineQueue("rparam28 TEXTEQU <[rsp+224]>");
	AddLineQueue("rparam29 TEXTEQU <[rsp+232]>");
	AddLineQueue("rparam30 TEXTEQU <[rsp+240]>");
	AddLineQueue("rparam31 TEXTEQU <[rsp+248]>");
	AddLineQueue("rparam32 TEXTEQU <[rsp+256]>");
	AddLineQueue("rparam33 TEXTEQU <[rsp+264]>");
	AddLineQueue("rparam34 TEXTEQU <[rsp+272]>");
	AddLineQueue("rparam35 TEXTEQU <[rsp+280]>");
	AddLineQueue("rparam36 TEXTEQU <[rsp+288]>");
	AddLineQueue("rparam37 TEXTEQU <[rsp+296]>");
	AddLineQueue("rparam38 TEXTEQU <[rsp+304]>");
	AddLineQueue("rparam39 TEXTEQU <[rsp+312]>");
	AddLineQueue("rparam40 TEXTEQU <[rsp+320]>");
	AddLineQueue("rparam41 TEXTEQU <[rsp+328]>");
	AddLineQueue("rparam42 TEXTEQU <[rsp+336]>");
	AddLineQueue("rparam43 TEXTEQU <[rsp+344]>");
	AddLineQueue("rparam44 TEXTEQU <[rsp+352]>");
	AddLineQueue("rparam45 TEXTEQU <[rsp+360]>");
	AddLineQueue("rparam46 TEXTEQU <[rsp+368]>");
	AddLineQueue("rparam47 TEXTEQU <[rsp+376]>");
	AddLineQueue("rparam48 TEXTEQU <[rsp+384]>");
	AddLineQueue("rparam49 TEXTEQU <[rsp+392]>");
	AddLineQueue("rparam50 TEXTEQU <[rsp+400]>");
	AddLineQueue("rparam51 TEXTEQU <[rsp+408]>");
	AddLineQueue("rparam52 TEXTEQU <[rsp+416]>");
	AddLineQueue("rparam53 TEXTEQU <[rsp+424]>");
	AddLineQueue("rparam54 TEXTEQU <[rsp+432]>");
	AddLineQueue("rparam55 TEXTEQU <[rsp+440]>");
	AddLineQueue("rparam56 TEXTEQU <[rsp+448]>");
	AddLineQueue("rparam57 TEXTEQU <[rsp+456]>");
	AddLineQueue("rparam58 TEXTEQU <[rsp+464]>");
	AddLineQueue("rparam69 TEXTEQU <[rsp+472]>");
	AddLineQueue("rparam60 TEXTEQU <[rsp+480]>");
	AddLineQueue("rparam61 TEXTEQU <[rsp+488]>");
	AddLineQueue("rparam62 TEXTEQU <[rsp+496]>");
	AddLineQueue("rparam63 TEXTEQU <[rsp+504]>");
	AddLineQueue("rparam64 TEXTEQU <[rsp+512]>");
	/* 32bits*/
	AddLineQueue("dret TEXTEQU <eax>");
	AddLineQueue("dreturn TEXTEQU <eax>");
	AddLineQueue("dparam1 TEXTEQU <edi>");
	AddLineQueue("dparam2 TEXTEQU <esi>");
	AddLineQueue("dparam3 TEXTEQU <edx>");
	AddLineQueue("dparam4 TEXTEQU <ecx>");
	AddLineQueue("dparam5 TEXTEQU <r8d>");
	AddLineQueue("dparam6 TEXTEQU <r9d>");
	AddLineQueue("dparam7 TEXTEQU <[esp+28]>");
	AddLineQueue("dparam8 TEXTEQU <[esp+32]>");
	AddLineQueue("dparam9 TEXTEQU <[esp+36]>");
	AddLineQueue("dparam10 TEXTEQU <[esp+40]>");
	AddLineQueue("dparam11 TEXTEQU <[esp+44]>");
	AddLineQueue("dparam12 TEXTEQU <[esp+48]>");
	AddLineQueue("dparam13 TEXTEQU <[esp+52]>");
	AddLineQueue("dparam14 TEXTEQU <[esp+56]>");
	AddLineQueue("dparam15 TEXTEQU <[esp+60]>");
	AddLineQueue("dparam16 TEXTEQU <[esp+64]>");
	AddLineQueue("dparam17 TEXTEQU <[esp+68]>");
	AddLineQueue("dparam18 TEXTEQU <[esp+72]>");
	AddLineQueue("dparam19 TEXTEQU <[esp+76]>");
	AddLineQueue("dparam20 TEXTEQU <[esp+80]>");
	AddLineQueue("dparam21 TEXTEQU <[esp+84]>");
	AddLineQueue("dparam22 TEXTEQU <[esp+88]>");
	AddLineQueue("dparam23 TEXTEQU <[esp+92]>");
	AddLineQueue("dparam24 TEXTEQU <[esp+96]>");
	AddLineQueue("dparam25 TEXTEQU <[esp+100]>");
	AddLineQueue("dparam26 TEXTEQU <[esp+104]>");
	AddLineQueue("dparam27 TEXTEQU <[esp+108]>");
	AddLineQueue("dparam28 TEXTEQU <[esp+112]>");
	AddLineQueue("dparam29 TEXTEQU <[esp+116]>");
	AddLineQueue("dparam30 TEXTEQU <[esp+120]>");
	AddLineQueue("dparam31 TEXTEQU <[esp+124]>");
	AddLineQueue("dparam32 TEXTEQU <[esp+128]>");
	AddLineQueue("dparam33 TEXTEQU <[esp+132]>");
	AddLineQueue("dparam34 TEXTEQU <[esp+136]>");
	AddLineQueue("dparam35 TEXTEQU <[esp+140]>");
	AddLineQueue("dparam36 TEXTEQU <[esp+144]>");
	AddLineQueue("dparam37 TEXTEQU <[esp+148]>");
	AddLineQueue("dparam38 TEXTEQU <[esp+152]>");
	AddLineQueue("dparam39 TEXTEQU <[esp+156]>");
	AddLineQueue("dparam40 TEXTEQU <[esp+160]>");
	AddLineQueue("dparam41 TEXTEQU <[esp+164]>");
	AddLineQueue("dparam42 TEXTEQU <[esp+168]>");
	AddLineQueue("dparam43 TEXTEQU <[esp+172]>");
	AddLineQueue("dparam44 TEXTEQU <[esp+176]>");
	AddLineQueue("dparam45 TEXTEQU <[esp+180]>");
	AddLineQueue("dparam46 TEXTEQU <[esp+184]>");
	AddLineQueue("dparam47 TEXTEQU <[esp+188]>");
	AddLineQueue("dparam48 TEXTEQU <[esp+192]>");
	AddLineQueue("dparam49 TEXTEQU <[esp+196]>");
	AddLineQueue("dparam50 TEXTEQU <[esp+200]>");
	AddLineQueue("dparam51 TEXTEQU <[esp+204]>");
	AddLineQueue("dparam52 TEXTEQU <[esp+208]>");
	AddLineQueue("dparam53 TEXTEQU <[esp+212]>");
	AddLineQueue("dparam54 TEXTEQU <[esp+216]>");
	AddLineQueue("dparam55 TEXTEQU <[esp+220]>");
	AddLineQueue("dparam56 TEXTEQU <[esp+224]>");
	AddLineQueue("dparam57 TEXTEQU <[esp+228]>");
	AddLineQueue("dparam58 TEXTEQU <[esp+232]>");
	AddLineQueue("dparam69 TEXTEQU <[esp+236]>");
	AddLineQueue("dparam60 TEXTEQU <[esp+240]>");
	AddLineQueue("dparam61 TEXTEQU <[esp+244]>");
	AddLineQueue("dparam62 TEXTEQU <[esp+248]>");
	AddLineQueue("dparam63 TEXTEQU <[esp+252]>");
	AddLineQueue("dparam64 TEXTEQU <[esp+256]>");
	AddLineQueue("ENDIF"); /*__UNIX64__*/

	AddLineQueue("IFNDEF __MACH__");
	AddLineQueue("IFDEF __UNIX32__");
	AddLineQueue("IFNDEF DEFINED_SYSTEMV");
	AddLineQueue("DEFINE DEFINED_SYSTEMV");
	AddLineQueue("ENDIF");
	AddLineQueue("IFNDEF CALLCONV");
	AddLineQueue("CALLCONV TEXTEQU <SYSTEMV>");
	AddLineQueue("ENDIF");
	AddLineQueue("CALLCONVOPT TEXTEQU <option language:SYSTEMV>");
	/* 32bits*/
	AddLineQueue("rret TEXTEQU <eax>");
	AddLineQueue("rreturn TEXTEQU <eax>");
	AddLineQueue("rparam1 TEXTEQU <edi>");
	AddLineQueue("rparam2 TEXTEQU <esi>");
	AddLineQueue("rparam3 TEXTEQU <edx>");
	AddLineQueue("rparam4 TEXTEQU <ecx>");
	AddLineQueue("rparam5 TEXTEQU <[esp+20]>");
	AddLineQueue("rparam6 TEXTEQU <[esp+24]>");
	AddLineQueue("rparam7 TEXTEQU <[esp+28]>");
	AddLineQueue("rparam8 TEXTEQU <[esp+32]>");
	AddLineQueue("rparam9 TEXTEQU <[esp+36]>");
	AddLineQueue("rparam10 TEXTEQU <[esp+40]>");
	AddLineQueue("rparam11 TEXTEQU <[esp+44]>");
	AddLineQueue("rparam12 TEXTEQU <[esp+48]>");
	AddLineQueue("rparam13 TEXTEQU <[esp+52]>");
	AddLineQueue("rparam14 TEXTEQU <[esp+56]>");
	AddLineQueue("rparam15 TEXTEQU <[esp+60]>");
	AddLineQueue("rparam16 TEXTEQU <[esp+64]>");
	AddLineQueue("rparam17 TEXTEQU <[esp+68]>");
	AddLineQueue("rparam18 TEXTEQU <[esp+72]>");
	AddLineQueue("rparam19 TEXTEQU <[esp+76]>");
	AddLineQueue("rparam20 TEXTEQU <[esp+80]>");
	AddLineQueue("rparam21 TEXTEQU <[esp+84]>");
	AddLineQueue("rparam22 TEXTEQU <[esp+88]>");
	AddLineQueue("rparam23 TEXTEQU <[esp+92]>");
	AddLineQueue("rparam24 TEXTEQU <[esp+96]>");
	AddLineQueue("rparam25 TEXTEQU <[esp+100]>");
	AddLineQueue("rparam26 TEXTEQU <[esp+104]>");
	AddLineQueue("rparam27 TEXTEQU <[esp+108]>");
	AddLineQueue("rparam28 TEXTEQU <[esp+112]>");
	AddLineQueue("rparam29 TEXTEQU <[esp+116]>");
	AddLineQueue("rparam30 TEXTEQU <[esp+120]>");
	AddLineQueue("rparam31 TEXTEQU <[esp+124]>");
	AddLineQueue("rparam32 TEXTEQU <[esp+128]>");
	AddLineQueue("rparam33 TEXTEQU <[esp+132]>");
	AddLineQueue("rparam34 TEXTEQU <[esp+136]>");
	AddLineQueue("rparam35 TEXTEQU <[esp+140]>");
	AddLineQueue("rparam36 TEXTEQU <[esp+144]>");
	AddLineQueue("rparam37 TEXTEQU <[esp+148]>");
	AddLineQueue("rparam38 TEXTEQU <[esp+152]>");
	AddLineQueue("rparam39 TEXTEQU <[esp+156]>");
	AddLineQueue("rparam40 TEXTEQU <[esp+160]>");
	AddLineQueue("rparam41 TEXTEQU <[esp+164]>");
	AddLineQueue("rparam42 TEXTEQU <[esp+168]>");
	AddLineQueue("rparam43 TEXTEQU <[esp+172]>");
	AddLineQueue("rparam44 TEXTEQU <[esp+176]>");
	AddLineQueue("rparam45 TEXTEQU <[esp+180]>");
	AddLineQueue("rparam46 TEXTEQU <[esp+184]>");
	AddLineQueue("rparam47 TEXTEQU <[esp+188]>");
	AddLineQueue("rparam48 TEXTEQU <[esp+192]>");
	AddLineQueue("rparam49 TEXTEQU <[esp+196]>");
	AddLineQueue("rparam50 TEXTEQU <[esp+200]>");
	AddLineQueue("rparam51 TEXTEQU <[esp+204]>");
	AddLineQueue("rparam52 TEXTEQU <[esp+208]>");
	AddLineQueue("rparam53 TEXTEQU <[esp+212]>");
	AddLineQueue("rparam54 TEXTEQU <[esp+216]>");
	AddLineQueue("rparam55 TEXTEQU <[esp+220]>");
	AddLineQueue("rparam56 TEXTEQU <[esp+224]>");
	AddLineQueue("rparam57 TEXTEQU <[esp+228]>");
	AddLineQueue("rparam58 TEXTEQU <[esp+232]>");
	AddLineQueue("rparam69 TEXTEQU <[esp+236]>");
	AddLineQueue("rparam60 TEXTEQU <[esp+240]>");
	AddLineQueue("rparam61 TEXTEQU <[esp+244]>");
	AddLineQueue("rparam62 TEXTEQU <[esp+248]>");
	AddLineQueue("rparam63 TEXTEQU <[esp+252]>");
	AddLineQueue("rparam64 TEXTEQU <[esp+256]>");
	/* 32bits*/
	AddLineQueue("dret TEXTEQU <eax>");
	AddLineQueue("dreturn TEXTEQU <eax>");
	AddLineQueue("dparam1 TEXTEQU <edi>");
	AddLineQueue("dparam2 TEXTEQU <esi>");
	AddLineQueue("dparam3 TEXTEQU <edx>");
	AddLineQueue("dparam4 TEXTEQU <ecx>");
	AddLineQueue("dparam5 TEXTEQU <[esp+20]>");
	AddLineQueue("dparam6 TEXTEQU <[esp+24]>");
	AddLineQueue("dparam7 TEXTEQU <[esp+28]>");
	AddLineQueue("dparam8 TEXTEQU <[esp+32]>");
	AddLineQueue("dparam9 TEXTEQU <[esp+36]>");
	AddLineQueue("dparam10 TEXTEQU <[esp+40]>");
	AddLineQueue("dparam11 TEXTEQU <[esp+44]>");
	AddLineQueue("dparam12 TEXTEQU <[esp+48]>");
	AddLineQueue("dparam13 TEXTEQU <[esp+52]>");
	AddLineQueue("dparam14 TEXTEQU <[esp+56]>");
	AddLineQueue("dparam15 TEXTEQU <[esp+60]>");
	AddLineQueue("dparam16 TEXTEQU <[esp+64]>");
	AddLineQueue("dparam17 TEXTEQU <[esp+68]>");
	AddLineQueue("dparam18 TEXTEQU <[esp+72]>");
	AddLineQueue("dparam19 TEXTEQU <[esp+76]>");
	AddLineQueue("dparam20 TEXTEQU <[esp+80]>");
	AddLineQueue("dparam21 TEXTEQU <[esp+84]>");
	AddLineQueue("dparam22 TEXTEQU <[esp+88]>");
	AddLineQueue("dparam23 TEXTEQU <[esp+92]>");
	AddLineQueue("dparam24 TEXTEQU <[esp+96]>");
	AddLineQueue("dparam25 TEXTEQU <[esp+100]>");
	AddLineQueue("dparam26 TEXTEQU <[esp+104]>");
	AddLineQueue("dparam27 TEXTEQU <[esp+108]>");
	AddLineQueue("dparam28 TEXTEQU <[esp+112]>");
	AddLineQueue("dparam29 TEXTEQU <[esp+116]>");
	AddLineQueue("dparam30 TEXTEQU <[esp+120]>");
	AddLineQueue("dparam31 TEXTEQU <[esp+124]>");
	AddLineQueue("dparam32 TEXTEQU <[esp+128]>");
	AddLineQueue("dparam33 TEXTEQU <[esp+132]>");
	AddLineQueue("dparam34 TEXTEQU <[esp+136]>");
	AddLineQueue("dparam35 TEXTEQU <[esp+140]>");
	AddLineQueue("dparam36 TEXTEQU <[esp+144]>");
	AddLineQueue("dparam37 TEXTEQU <[esp+148]>");
	AddLineQueue("dparam38 TEXTEQU <[esp+152]>");
	AddLineQueue("dparam39 TEXTEQU <[esp+156]>");
	AddLineQueue("dparam40 TEXTEQU <[esp+160]>");
	AddLineQueue("dparam41 TEXTEQU <[esp+164]>");
	AddLineQueue("dparam42 TEXTEQU <[esp+168]>");
	AddLineQueue("dparam43 TEXTEQU <[esp+172]>");
	AddLineQueue("dparam44 TEXTEQU <[esp+176]>");
	AddLineQueue("dparam45 TEXTEQU <[esp+180]>");
	AddLineQueue("dparam46 TEXTEQU <[esp+184]>");
	AddLineQueue("dparam47 TEXTEQU <[esp+188]>");
	AddLineQueue("dparam48 TEXTEQU <[esp+192]>");
	AddLineQueue("dparam49 TEXTEQU <[esp+196]>");
	AddLineQueue("dparam50 TEXTEQU <[esp+200]>");
	AddLineQueue("dparam51 TEXTEQU <[esp+204]>");
	AddLineQueue("dparam52 TEXTEQU <[esp+208]>");
	AddLineQueue("dparam53 TEXTEQU <[esp+212]>");
	AddLineQueue("dparam54 TEXTEQU <[esp+216]>");
	AddLineQueue("dparam55 TEXTEQU <[esp+220]>");
	AddLineQueue("dparam56 TEXTEQU <[esp+224]>");
	AddLineQueue("dparam57 TEXTEQU <[esp+228]>");
	AddLineQueue("dparam58 TEXTEQU <[esp+232]>");
	AddLineQueue("dparam69 TEXTEQU <[esp+236]>");
	AddLineQueue("dparam60 TEXTEQU <[esp+240]>");
	AddLineQueue("dparam61 TEXTEQU <[esp+244]>");
	AddLineQueue("dparam62 TEXTEQU <[esp+248]>");
	AddLineQueue("dparam63 TEXTEQU <[esp+252]>");
	AddLineQueue("dparam64 TEXTEQU <[esp+256]>");
	AddLineQueue("ENDIF"); /*__UNIX32__*/
	AddLineQueue("ENDIF"); /*__MACH__*/

	AddLineQueue("INT8 TEXTEQU <BYTE>");
	AddLineQueue("UINT8 TEXTEQU <BYTE>");
	AddLineQueue("SINT8 TEXTEQU <SBYTE>");
	AddLineQueue("INT16 TEXTEQU <WORD>");
	AddLineQueue("UINT16 TEXTEQU <WORD>");
	AddLineQueue("SINT16 TEXTEQU <SWORD>");
	/*AddLineQueue("INT TEXTEQU <DWORD>"); cannot be used instruction type*/
	AddLineQueue("BOOL TEXTEQU <DWORD>");
	AddLineQueue("INT32 TEXTEQU <DWORD>");
	AddLineQueue("UINT32 TEXTEQU <DWORD>");
	AddLineQueue("SINT32 TEXTEQU <SDWORD>");
	AddLineQueue("INT64 TEXTEQU <QWORD>");
	AddLineQueue("UINT64 TEXTEQU <QWORD>");
	AddLineQueue("SINT64 TEXTEQU <SQWORD>");
	AddLineQueue("FLOAT TEXTEQU <REAL4>");
	AddLineQueue("DOUBLE TEXTEQU <REAL8>");

	AddLineQueue("BYTE_SIZE EQU 1");
	AddLineQueue("UBYTE_SIZE EQU 1");
	AddLineQueue("SBYTE_SIZE EQU 1");
	AddLineQueue("CHAR_SIZE EQU 1");
	AddLineQueue("UCHAR_SIZE EQU 1");
	AddLineQueue("SCHAR_SIZE EQU 1");
	AddLineQueue("INT8_SIZE EQU 1");
	AddLineQueue("UINT8_SIZE EQU 1");
	AddLineQueue("SINT8_SIZE EQU 1");
	AddLineQueue("WORD_SIZE EQU 2");
	AddLineQueue("UWORD_SIZE EQU 2");
	AddLineQueue("SWORD_SIZE EQU 2");
	AddLineQueue("SHORT_SIZE EQU 2");
	AddLineQueue("USHORT_SIZE EQU 2");
	AddLineQueue("SSHORT_SIZE EQU 2");
	AddLineQueue("INT16_SIZE EQU 2");
	AddLineQueue("UINT16_SIZE EQU 2");
	AddLineQueue("SINT16_SIZE EQU 2");
	AddLineQueue("DWORD_SIZE EQU 4");
	AddLineQueue("UDWORD_SIZE EQU 4");
	AddLineQueue("SDWORD_SIZE EQU 4");
	AddLineQueue("LONG_SIZE EQU 4");
	AddLineQueue("ULONG_SIZE EQU 4");
	AddLineQueue("SLONG_SIZE EQU 4");
	AddLineQueue("BOOL_SIZE EQU 4");
	AddLineQueue("INT_SIZE EQU 4");
	AddLineQueue("UINT_SIZE EQU 4");
	AddLineQueue("SINT_SIZE EQU 4");
	AddLineQueue("INT32_SIZE EQU 4");
	AddLineQueue("UINT32_SIZE EQU 4");
	AddLineQueue("SINT32_SIZE EQU 4");
	AddLineQueue("QWORD_SIZE EQU 8");
	AddLineQueue("UQWORD_SIZE EQU 8");
	AddLineQueue("SQWORD_SIZE EQU 8");
	AddLineQueue("LONGLONG_SIZE EQU 8");
	AddLineQueue("ULONGLONG_SIZE EQU 8");
	AddLineQueue("SLONGLONG_SIZE EQU 8");
	AddLineQueue("INT64_SIZE EQU 8");
	AddLineQueue("UINT64_SIZE EQU 8");
	AddLineQueue("SINT64_SIZE EQU 8");
	AddLineQueue("REAL4_SIZE EQU 4");
	AddLineQueue("FLOAT_SIZE EQU 4");
	AddLineQueue("FLT_SIZE EQU 4");
	AddLineQueue("REAL8_SIZE EQU 8");
	AddLineQueue("DOUBLE_SIZE EQU 8");
	AddLineQueue("DBL_SIZE EQU 8");

	AddLineQueue("UBYTE_MAX EQU 0xff");
	AddLineQueue("UCHAR_MAX EQU UBYTE_MAX");
	AddLineQueue("UINT8_MAX EQU UBYTE_MAX");
	AddLineQueue("UBYTE_MIN EQU 0x0");
	AddLineQueue("UCHAR_MIN EQU UBYTE_MIN");
	AddLineQueue("UINT8_MIN EQU UBYTE_MIN");
	AddLineQueue("SBYTE_MAX EQU 0x7f");
	AddLineQueue("SCHAR_MAX EQU SBYTE_MAX");
	AddLineQueue("SINT8_MAX EQU SBYTE_MAX");
	AddLineQueue("SBYTE_MIN EQU (-0x7f - 0x1)");
	AddLineQueue("SCHAR_MIN EQU SBYTE_MIN");
	AddLineQueue("SINT8_MIN EQU SBYTE_MIN");
	AddLineQueue("UWORD_MAX EQU 0xffff");
	AddLineQueue("USHORT_MAX EQU UWORD_MAX");
	AddLineQueue("UINT16_MAX EQU UWORD_MAX");
	AddLineQueue("UWORD_MIN EQU 0x0");
	AddLineQueue("USHORT_MIN EQU UWORD_MIN");
	AddLineQueue("UINT16_MIN EQU UWORD_MIN");
	AddLineQueue("SWORD_MAX EQU 0x7fff");
	AddLineQueue("SSHORT_MAX EQU SWORD_MAX");
	AddLineQueue("SINT16_MAX EQU SWORD_MAX");
	AddLineQueue("SWORD_MIN EQU (-0x7fff - 0x1)");
	AddLineQueue("SSHORT_MIN EQU SWORD_MIN");
	AddLineQueue("SINT16_MIN EQU SWORD_MIN");
	AddLineQueue("BOOL_MAX EQU 0x1");
	AddLineQueue("BOOL_MIN EQU 0x0");
	AddLineQueue("UDWORD_MAX EQU 0xffffffff");
	AddLineQueue("ULONG_MAX EQU UDWORD_MAX");
	AddLineQueue("UINT_MAX EQU UDWORD_MAX");
	AddLineQueue("UINT32_MAX EQU UDWORD_MAX");
	AddLineQueue("UDWORD_MIN EQU 0x0");
	AddLineQueue("ULONG_MIN EQU UDWORD_MIN");
	AddLineQueue("UINT_MIN EQU UDWORD_MIN");
	AddLineQueue("UINT32_MIN EQU UDWORD_MIN");
	AddLineQueue("SDWORD_MAX EQU 0x7fffffff");
	AddLineQueue("SLONG_MAX EQU SDWORD_MAX");
	AddLineQueue("SINT_MAX EQU SDWORD_MAX");
	AddLineQueue("SINT32_MAX EQU SDWORD_MAX");
	AddLineQueue("SDWORD_MIN EQU (-0x7fffffff - 0x1)");
	AddLineQueue("SLONG_MIN EQU SDWORD_MIN");
	AddLineQueue("SINT_MIN EQU SDWORD_MIN");
	AddLineQueue("SINT32_MIN EQU SDWORD_MIN");
	AddLineQueue("UQWORD_MAX EQU 0xffffffffffffffff");
	AddLineQueue("ULONGLONG_MAX EQU UQWORD_MAX");
	AddLineQueue("UINT64_MAX EQU UQWORD_MAX");
	AddLineQueue("UQWORD_MIN EQU 0x0");
	AddLineQueue("ULONGLONG_MIN EQU UQWORD_MIN");
	AddLineQueue("UINT64_MIN EQU UQWORD_MIN");
	AddLineQueue("SQWORD_MAX EQU 0x7fffffffffffffff");
	AddLineQueue("SLONGLONG_MAX EQU SQWORD_MAX");
	AddLineQueue("SINT64_MAX EQU SQWORD_MAX");
	AddLineQueue("SQWORD_MIN EQU (-0x7fffffffffffffff - 0x1)");
	AddLineQueue("SLONGLONG_MIN EQU SQWORD_MIN");
	AddLineQueue("SINT64_MIN EQU SQWORD_MIN");

	AddLineQueue("IFDEF __x64__");
	AddLineQueue("SIZE_T TEXTEQU <QWORD>");
	AddLineQueue("ISIZE_T TEXTEQU <DQ>");
	AddLineQueue("PSIZE_T TEXTEQU <PTR QWORD>");
	AddLineQueue("SIZE_TP TEXTEQU <QWORD PTR>");
	AddLineQueue("SIZE_T_SIZE EQU 8");
	AddLineQueue("PTR_SIZE EQU 8");
	AddLineQueue("REG_SIZE EQU 8");
	AddLineQueue("SINTSIZE_T_MAX EQU SQWORD_MAX");
	AddLineQueue("SINTSIZE_T_MIN EQU SQWORD_MIN");
	AddLineQueue("UINTSIZE_T_MAX EQU UQWORD_MAX");
	AddLineQueue("UINTSIZE_T_MIN EQU UQWORD_MIN");
	AddLineQueue("SINTPTR_MAX EQU SQWORD_MAX");
	AddLineQueue("SINTPTR_MIN EQU SQWORD_MIN");
	AddLineQueue("UINTPTR_MAX EQU UQWORD_MAX");
	AddLineQueue("UINTPTR_MIN EQU UQWORD_MIN");
	AddLineQueue("ENDIF"); /*__x64__*/

	AddLineQueue("IFDEF __x32__");
	AddLineQueue("SIZE_T TEXTEQU <DWORD>");
	AddLineQueue("ISIZE_T TEXTEQU <DD>");
	AddLineQueue("PSIZE_T TEXTEQU <PTR DWORD>");
	AddLineQueue("SIZE_TP TEXTEQU <DWORD PTR>");
	AddLineQueue("SIZE_T_SIZE EQU 4");
	AddLineQueue("PTR_SIZE EQU 4");
	AddLineQueue("REG_SIZE EQU 4");
	AddLineQueue("SINTSIZE_T_MAX EQU SDWORD_MAX");
	AddLineQueue("SINTSIZE_T_MIN EQU SDWORD_MIN");
	AddLineQueue("UINTSIZE_T_MAX EQU UDWORD_MAX");
	AddLineQueue("UINTSIZE_T_MIN EQU UDWORD_MIN");
	AddLineQueue("SINTPTR_MAX EQU SDWORD_MAX");
	AddLineQueue("SINTPTR_MIN EQU SDWORD_MIN");
	AddLineQueue("UINTPTR_MAX EQU UDWORD_MAX");
	AddLineQueue("UINTPTR_MIN EQU UDWORD_MIN");
	AddLineQueue("ENDIF"); /*__x32__*/

	/*mm types*/
	AddLineQueue("MM_SIZE EQU 8");
	AddLineQueue("M64_SIZE EQU 8");
	AddLineQueue("XMM_SIZE EQU 16");
	AddLineQueue("M128_SIZE EQU 16");
	AddLineQueue("YMM_SIZE EQU 32");
	AddLineQueue("M256_SIZE EQU 32");
	AddLineQueue("ZMM_SIZE EQU 64");
	AddLineQueue("M512_SIZE EQU 64");

	/*bool*/
	AddLineQueue("FALSE EQU 0x0");
	AddLineQueue("TRUE EQU 0x1");

	/*byte*/
	AddLineQueue("M8_FALSE EQU 0x00");
	AddLineQueue("M8_TRUE EQU 0xff");
	AddLineQueue("I8_FALSE EQU 0x00");
	AddLineQueue("I8_TRUE EQU 0xff");
	/*word*/
	AddLineQueue("M16_FALSE EQU 0x0000");
	AddLineQueue("M16_TRUE EQU 0xffff");
	AddLineQueue("I16_FALSE EQU 0x0000");
	AddLineQueue("I16_TRUE EQU 0xffff");
	/*dword*/
	AddLineQueue("M32_FALSE EQU 0x00000000");
	AddLineQueue("M32_TRUE EQU 0xffffffff");
	AddLineQueue("I32_FALSE EQU 0x00000000");
	AddLineQueue("I32_TRUE EQU 0xffffffff");
	/*qword*/
	AddLineQueue("M64_FALSE EQU 0x0000000000000000");
	AddLineQueue("M64_TRUE EQU 0xffffffffffffffff");
	AddLineQueue("I64_FALSE EQU 0x0000000000000000");
	AddLineQueue("I64_TRUE EQU 0xffffffffffffffff");

	/*float mask*/
	AddLineQueue("FLT_1LSHL12_MSK EQU 0x00001000");
	AddLineQueue("FLT_1LSHL23_MSK EQU 0x00800000");
	AddLineQueue("FLT_1LSHL24_MSK EQU 0x01000000");
	AddLineQueue("FLT_1LSHL31_MSK EQU 0x80000000");

	AddLineQueue("FLT_NEG1LSHL12_MSK EQU 0xfffff000");
	AddLineQueue("FLT_NEG1LSHL23_MSK EQU 0xff800000");
	AddLineQueue("FLT_NEG1LSHL24_MSK EQU 0xff000000");

	AddLineQueue("FLT_FALSE_MSK EQU 0x00000000");
	AddLineQueue("FLT_TRUE_MSK EQU 0xffffffff");

	AddLineQueue("FLT_MAGIC_MSK EQU 0x4b000000");
	AddLineQueue("FLT_SIGN_MSK EQU 0x80000000");
	AddLineQueue("FLT_INVSIGN_MSK EQU 0x7fffffff");

	AddLineQueue("FLT_INF_MSK EQU 0x7f800000");
	AddLineQueue("FLT_FIN_MSK EQU 0xff000000");
	AddLineQueue("FLT_INVINF_MSK EQU 0x807fffff");
	AddLineQueue("FLT_NEGINF_MSK EQU 0xff800000");
	AddLineQueue("FLT_NAN_MSK EQU 0x7fffffff");
	AddLineQueue("FLT_QNAN_MSK EQU 0x7fc00000");
	AddLineQueue("FLT_NEGQNAN_MSK EQU 0xffc00000");
	AddLineQueue("FLT_NANTEST_MSK EQU 0x007fffff");
	AddLineQueue("FLT_ABS_MSK EQU 0x7fffffff");
	AddLineQueue("FLT_MIN_MSK EQU 0x00800000");
	AddLineQueue("FLT_MAX_MSK EQU 0x7f7fffff");
	AddLineQueue("FLT_NOFRACTION_MSK EQU 0x00800000");
	AddLineQueue("FLT_MINDENORM_MSK EQU 0x00000001");
	AddLineQueue("FLT_DENORMLIMIT_MSK EQU 0x00800000");
	AddLineQueue("FLT_MINNORMAL_MSK EQU 0x00800000");
	AddLineQueue("FLT_MAXNORMAL_MSK EQU 0x7f7fffff");

	AddLineQueue("FLT_DECDIG_MSK EQU 0x00000009");
	AddLineQueue("FLT_DIG_MSK EQU 0x00000006");
	AddLineQueue("FLT_NEGDECDIG_MSK EQU 0xfffffff7");
	AddLineQueue("FLT_NEGDIG_MSK EQU 0xfffffffa");
	AddLineQueue("FLT_EPS_MSK EQU 0x34000000");
	AddLineQueue("FLT_EPSILON_MSK EQU 0x34000000");
	AddLineQueue("FLT_NORMEPS_MSK EQU 0x1e3ce508");
	AddLineQueue("FLT_GUARD_MSK EQU 0x00000000");
	AddLineQueue("FLT_MANTPOW2_MSK EQU 0x00800000");
	AddLineQueue("FLT_MAXMANTPOW2_MSK EQU 0x7f7fffff");
	AddLineQueue("FLT_MANTDIG_MSK EQU 0x00000018");
	AddLineQueue("FLT_MANT_MSK EQU 0x00000017");
	AddLineQueue("FLT_NEGMANTDIG_MSK EQU 0xffffffe8");
	AddLineQueue("FLT_NEGMANT_MSK EQU 0xffffffe9");
	AddLineQueue("FLT_MAXEXP_MSK EQU 0x00000080");
	AddLineQueue("FLT_EXPSIGN_MSK EQU 0x00000080");
	AddLineQueue("FLT_EXP_MSK EQU 0x0000007f");
	AddLineQueue("FLT_NEGMAXEXP_MSK EQU 0xffffff80");
	AddLineQueue("FLT_NEGEXPSIGN_MSK EQU 0xffffff80");
	AddLineQueue("FLT_NEGEXP_MSK EQU 0xffffff81");
	AddLineQueue("FLT_SUBNORMALEXP_MSK EQU 0xffffff82");
	AddLineQueue("FLT_MINEXP_MSK EQU 0xffffff83");
	AddLineQueue("FLT_MAXDECEXP_MSK EQU 0x00000026");
	AddLineQueue("FLT_NEGMAXDECEXP_MSK EQU 0xffffffda");
	AddLineQueue("FLT_MINDECEXP_MSK EQU 0xffffffd8");
	AddLineQueue("FLT_EXPFIELD_MSK EQU 0xff000000");
	AddLineQueue("FLT_MANTFIELD_MSK EQU 0x00ffffff");
	AddLineQueue("FLT_NORM_MSK EQU 0x00000000");
	AddLineQueue("FLT_RADIX_MSK EQU 0x00000002");
	AddLineQueue("FLT_ROUNDS_MSK EQU 0x00000001");
	AddLineQueue("FLT_SUBDEC_MSK EQU 0x0000000a");
	AddLineQueue("FLT_SQRTMAX_MSK EQU 0x5f7ffff0");
	AddLineQueue("FLT_SMALNORMAL_MSK EQU 0x00800000");

	AddLineQueue("FLT_HALFMINUSEPS_MSK EQU 0x3efffffd");
	AddLineQueue("FLT_TRUEINT_MSK EQU 0x00000001");

	AddLineQueue("FLT_BYTE_MSK EQU 0x000000ff");
	AddLineQueue("FLT_4LOW_MSK EQU 0x0fffffff");
	AddLineQueue("FLT_4HIGH_MSK EQU 0xfffffff0");
	AddLineQueue("FLT_FLIP4_MSK EQU 0x00000008");
	AddLineQueue("FLT_8LOW_MSK EQU 0x00ffffff");
	AddLineQueue("FLT_8HIGH_MSK EQU 0xffffff00");
	AddLineQueue("FLT_FLIP8_MSK EQU 0x00000080");
	AddLineQueue("FLT_16LOW_MSK EQU 0x0000ffff");
	AddLineQueue("FLT_16HIGH_MSK EQU 0xffff0000");
	AddLineQueue("FLT_FLIP16_MSK EQU 0x00008000");
	AddLineQueue("FLT_24LOW_MSK EQU 0x000000ff");
	AddLineQueue("FLT_24HIGH_MSK EQU 0xff000000");
	AddLineQueue("FLT_FLIP24_MSK EQU 0x00800000");
	AddLineQueue("FLT_28LOW_MSK EQU 0x0000000f");
	AddLineQueue("FLT_28HIGH_MSK EQU 0xf0000000");
	AddLineQueue("FLT_FLIP28_MSK EQU 0x08000000");
	AddLineQueue("FLT_LOW_MSK EQU 0x00000000");
	AddLineQueue("FLT_HIGH_MSK EQU 0x00000000");
	AddLineQueue("FLT_FLIP_MSK EQU 0x80000000");

	AddLineQueue("FLT_0_MSK EQU 0x00000000");
	AddLineQueue("FLT_0D5_MSK EQU 0x3f000000");
	AddLineQueue("FLT_1_MSK EQU 0x3f800000");
	AddLineQueue("FLT_1D5_MSK EQU 0x3fc00000");
	AddLineQueue("FLT_2_MSK EQU 0x40000000");
	AddLineQueue("FLT_2D5_MSK EQU 0x40200000");
	AddLineQueue("FLT_3_MSK EQU 0x40400000");
	AddLineQueue("FLT_4_MSK EQU 0x40800000");
	AddLineQueue("FLT_5_MSK EQU 0x40a00000");
	AddLineQueue("FLT_6_MSK EQU 0x40c00000");
	AddLineQueue("FLT_7_MSK EQU 0x40e00000");
	AddLineQueue("FLT_8_MSK EQU 0x41000000");
	AddLineQueue("FLT_9_MSK EQU 0x41100000");
	AddLineQueue("FLT_10_MSK EQU 0x41200000");
	AddLineQueue("FLT_20_MSK EQU 0x41a00000");
	AddLineQueue("FLT_23_MSK EQU 0x41b80000");
	AddLineQueue("FLT_23D5_MSK EQU 0x41bc0000");
	AddLineQueue("FLT_24_MSK EQU 0x41c00000");
	AddLineQueue("FLT_24D5_MSK EQU 0x41c40000");
	AddLineQueue("FLT_25_MSK EQU 0x41c80000");

	AddLineQueue("FLT_128_MSK EQU 0x43000000");

	AddLineQueue("FLT_253_MSK EQU 0x437d0000");

	AddLineQueue("FLT_NEG0_MSK EQU 0x80000000");
	AddLineQueue("FLT_NEG1_MSK EQU 0xbf800000");

	AddLineQueue("FLT_NEG150_MSK EQU 0xc3160000");
	
	AddLineQueue("FLT_A8_MSK EQU 0x00ff0000");
	AddLineQueue("FLT_R8_MSK EQU 0x0000ff00");
	AddLineQueue("FLT_G8_MSK EQU 0x000000ff");
	AddLineQueue("FLT_B8_MSK EQU 0xff000000");

	AddLineQueue("FLT_FLIPA8_MSK EQU FLT_0_MSK");
	AddLineQueue("FLT_FLIPR8_MSK EQU FLT_0_MSK");
	AddLineQueue("FLT_FLIPG8_MSK EQU FLT_0_MSK");
	AddLineQueue("FLT_FLIPB8_MSK EQU FLT_NEG0_MSK");

	AddLineQueue("FLT_A2_MSK EQU 0x000003ff");
	AddLineQueue("FLT_B10_MSK EQU 0x000ffc00");
	AddLineQueue("FLT_G10_MSK EQU 0x3ff00000");
	AddLineQueue("FLT_R10_MSK EQU 0xc0000000");

	AddLineQueue("FLT_FLIPA2_MSK EQU 0x00000200");
	AddLineQueue("FLT_FLIPB10_MSK EQU 0x00080000");
	AddLineQueue("FLT_FLIPG10_MSK EQU 0x20000000");
	AddLineQueue("FLT_FLIPR10_MSK EQU 0x80000000");

	AddLineQueue("FLT_BIN128_MSK EQU FLT_128_MSK");
	AddLineQueue("FLT_BINNEG150_MSK EQU FLT_NEG150_MSK");

	AddLineQueue("FLT_MAXRAND_MSK EQU 0x00007fff");

	AddLineQueue("FLT_MAXI8_MSK EQU 0x0000007f");
	AddLineQueue("FLT_MINI8_MSK EQU 0xffffff80");
	AddLineQueue("FLT_MAXU8_MSK EQU 0x000000ff");

	AddLineQueue("FLT_MAXI16_MSK EQU 0x00007fff");
	AddLineQueue("FLT_MINI16_MSK EQU 0xffff8000");
	AddLineQueue("FLT_MAXU16_MSK EQU 0x0000ffff");

	AddLineQueue("FLT_MAXI32_MSK EQU 0x7fffffff");
	AddLineQueue("FLT_MINI32_MSK EQU 0x80000000");
	AddLineQueue("FLT_MAXU32_MSK EQU 0xffffffff");

	AddLineQueue("FLT_MAXI8XU8_MSK EQU 0x00008000");
	AddLineQueue("FLT_MINI8XU8_MSK EQU 0xffff8000");
	AddLineQueue("FLT_MAXI8XU16_MSK EQU 0x00800000");
	AddLineQueue("FLT_MINI8XU16_MSK EQU 0xff800000");

	AddLineQueue("FLT_MAXI16XU16_MSK EQU 0x80000000");
	AddLineQueue("FLT_MINI16XU16_MSK EQU 0x80000000");

	AddLineQueue("FLT_FIXUNSIGNED_MSK EQU 0x80000000");
	AddLineQueue("FLT_FIXMAXI32_MSK EQU 0x7fffff80");
	AddLineQueue("FLT_FIXMAXU32_MSK EQU 0xffffff00");

	/*float int*/
	AddLineQueue("FLT_1LSHL12_INT EQU 4096");
	AddLineQueue("FLT_1LSHL23_INT EQU 8388608");
	AddLineQueue("FLT_1LSHL24_INT EQU 16777216");
	AddLineQueue("FLT_1LSHL31_INT EQU (-2147483648)");

	AddLineQueue("FLT_NEG1LSHL12_INT EQU (-4096)");
	AddLineQueue("FLT_NEG1LSHL23_INT EQU (-8388608)");
	AddLineQueue("FLT_NEG1LSHL24_INT EQU (-16777216)");

	AddLineQueue("FLT_FALSE_INT EQU 0");
	AddLineQueue("FLT_TRUE_INT EQU (-1)");

	AddLineQueue("FLT_MAGIC_INT EQU 1258291200");
	AddLineQueue("FLT_SIGN_INT EQU (-2147483648)");
	AddLineQueue("FLT_INVSIGN_INT EQU 2147483647");

	AddLineQueue("FLT_INF_INT EQU 2139095040");
	AddLineQueue("FLT_FIN_INT EQU (-16777216)");
	AddLineQueue("FLT_INVINF_INT EQU (-2139095041)");
	AddLineQueue("FLT_NEGINF_INT EQU (-8388608)");
	AddLineQueue("FLT_NAN_INT EQU 2147483647");
	AddLineQueue("FLT_QNAN_INT EQU 2143289344");
	AddLineQueue("FLT_NEGQNAN_INT EQU (-4194304)");
	AddLineQueue("FLT_NANTEST_INT EQU 8388607");
	AddLineQueue("FLT_ABS_INT EQU 2147483647");
	AddLineQueue("FLT_MIN_INT EQU 8388608");
	AddLineQueue("FLT_MAX_INT EQU 2139095039");
	AddLineQueue("FLT_NOFRACTION_INT EQU 8388608");
	AddLineQueue("FLT_MINDENORM_INT EQU 1");
	AddLineQueue("FLT_DENORMLIMIT_INT EQU 8388608");
	AddLineQueue("FLT_MINNORMAL_INT EQU 8388608");
	AddLineQueue("FLT_MAXNORMAL_INT EQU 2139095039");

	AddLineQueue("FLT_DECDIG_INT EQU 9");
	AddLineQueue("FLT_DIG_INT EQU 6");
	AddLineQueue("FLT_NEGDECDIG_INT EQU (-9)");
	AddLineQueue("FLT_NEGDIG_INT EQU (-6)");
	AddLineQueue("FLT_EPS_INT EQU 872415232");
	AddLineQueue("FLT_EPSILON_INT EQU 872415232");
	AddLineQueue("FLT_NORMEPS_INT EQU 507307272");
	AddLineQueue("FLT_GUARD_INT EQU 0");
	AddLineQueue("FLT_MANTPOW2_INT EQU 8388608");
	AddLineQueue("FLT_MAXMANTPOW2_INT EQU 2139095039");
	AddLineQueue("FLT_MANTDIG_INT EQU 24");
	AddLineQueue("FLT_MANT_INT EQU 23");
	AddLineQueue("FLT_NEGMANTDIG_INT EQU (-24)");
	AddLineQueue("FLT_NEGMANT_INT EQU (-23)");
	AddLineQueue("FLT_MAXEXP_INT EQU 128");
	AddLineQueue("FLT_EXPSIGN_INT EQU 128");
	AddLineQueue("FLT_EXP_INT EQU 127");
	AddLineQueue("FLT_NEGMAXEXP_INT EQU (-128)");
	AddLineQueue("FLT_NEGEXPSIGN_INT EQU (-128)");
	AddLineQueue("FLT_NEGEXP_INT EQU (-127)");
	AddLineQueue("FLT_SUBNORMALEXP_INT EQU (-126)");
	AddLineQueue("FLT_MINEXP_INT EQU (-125)");
	AddLineQueue("FLT_MAXDECEXP_INT EQU 38");
	AddLineQueue("FLT_NEGMAXDECEXP_INT EQU (-38)");
	AddLineQueue("FLT_MINDECEXP_INT EQU (-37)");
	AddLineQueue("FLT_EXPFIELD_INT EQU (-16777216)");
	AddLineQueue("FLT_MANTFIELD_INT EQU 16777215");
	AddLineQueue("FLT_NORM_INT EQU 0");
	AddLineQueue("FLT_RADIX_INT EQU 2");
	AddLineQueue("FLT_ROUNDS_INT EQU 1");
	AddLineQueue("FLT_SUBDEC_INT EQU 10");
	AddLineQueue("FLT_SQRTMAX_INT EQU 1602224112");
	AddLineQueue("FLT_SMALNORMAL_INT EQU 8388608");

	AddLineQueue("FLT_HALFMINUSEPS_INT EQU 1056964605");
	AddLineQueue("FLT_TRUEINT_INT EQU 1");

	AddLineQueue("FLT_BYTE_INT EQU 255");
	AddLineQueue("FLT_4LOW_INT EQU 268435455");
	AddLineQueue("FLT_4HIGH_INT EQU (-16)");
	AddLineQueue("FLT_FLIP4_INT EQU 8");
	AddLineQueue("FLT_8LOW_INT EQU 16777215");
	AddLineQueue("FLT_8HIGH_INT EQU (-256)");
	AddLineQueue("FLT_FLIP8_INT EQU 128");
	AddLineQueue("FLT_16LOW_INT EQU 65535");
	AddLineQueue("FLT_16HIGH_INT EQU (-65536)");
	AddLineQueue("FLT_FLIP16_INT EQU 32768");
	AddLineQueue("FLT_24LOW_INT EQU 255");
	AddLineQueue("FLT_24HIGH_INT EQU (-16777216)");
	AddLineQueue("FLT_FLIP24_INT EQU 8388608");
	AddLineQueue("FLT_28LOW_INT EQU 15");
	AddLineQueue("FLT_28HIGH_INT EQU (-268435456)");
	AddLineQueue("FLT_FLIP28_INT EQU 134217728");
	AddLineQueue("FLT_LOW_INT EQU 0");
	AddLineQueue("FLT_HIGH_INT EQU 0");
	AddLineQueue("FLT_FLIP_INT EQU (-2147483648)");

	AddLineQueue("FLT_0_INT EQU 0x00000000");
	AddLineQueue("FLT_0D5_INT EQU 1056964608");
	AddLineQueue("FLT_1_INT EQU 1065353216");
	AddLineQueue("FLT_1D5_INT EQU 1069547520");
	AddLineQueue("FLT_2_INT EQU 1073741824");
	AddLineQueue("FLT_2D5_INT EQU 1075838976");
	AddLineQueue("FLT_3_INT EQU 1077936128");
	AddLineQueue("FLT_4_INT EQU 1082130432");
	AddLineQueue("FLT_5_INT EQU 1084227584");
	AddLineQueue("FLT_6_INT EQU 1086324736");
	AddLineQueue("FLT_7_INT EQU 1088421888");
	AddLineQueue("FLT_8_INT EQU 1090519040");
	AddLineQueue("FLT_9_INT EQU 1091567616");
	AddLineQueue("FLT_10_INT EQU 1092616192");
	AddLineQueue("FLT_20_INT EQU 1101004800");
	AddLineQueue("FLT_23_INT EQU 1102577664");
	AddLineQueue("FLT_23D5_INT EQU 1102839808");
	AddLineQueue("FLT_24_INT EQU 1103101952");
	AddLineQueue("FLT_24D5_INT EQU 1103364096");
	AddLineQueue("FLT_25_INT EQU 1103626240");

	AddLineQueue("FLT_128_INT EQU 1124073472");

	AddLineQueue("FLT_253_INT EQU 1132265472");

	AddLineQueue("FLT_NEG0_INT EQU (-2147483648)");
	AddLineQueue("FLT_NEG1_INT EQU (-1082130432)");

	AddLineQueue("FLT_NEG150_INT EQU (-1021968384)");

	AddLineQueue("FLT_A8_INT EQU 16711680");
	AddLineQueue("FLT_R8_INT EQU 65280");
	AddLineQueue("FLT_G8_INT EQU 255");
	AddLineQueue("FLT_B8_INT EQU (-16777216)");

	AddLineQueue("FLT_FLIPA8_INT EQU FLT_0_INT");
	AddLineQueue("FLT_FLIPR8_INT EQU FLT_0_INT");
	AddLineQueue("FLT_FLIPG8_INT EQU FLT_0_INT");
	AddLineQueue("FLT_FLIPB8_INT EQU FLT_NEG0_INT");

	AddLineQueue("FLT_A2_INT EQU 1023");
	AddLineQueue("FLT_B10_INT EQU 1047552");
	AddLineQueue("FLT_G10_INT EQU 1072693248");
	AddLineQueue("FLT_R10_INT EQU (-1073741824)");

	AddLineQueue("FLT_FLIPA2_INT EQU 512");
	AddLineQueue("FLT_FLIPB10_INT EQU 524288");
	AddLineQueue("FLT_FLIPG10_INT EQU 536870912");
	AddLineQueue("FLT_FLIPR10_INT EQU (-2147483648)");

	AddLineQueue("FLT_BIN128_INT EQU FLT_128_INT");
	AddLineQueue("FLT_BINNEG150_INT EQU FLT_NEG150_INT");

	AddLineQueue("FLT_MAXRAND_INT EQU 32767");

	AddLineQueue("FLT_MAXI8_INT EQU 127");
	AddLineQueue("FLT_MINI8_INT EQU (-128)");
	AddLineQueue("FLT_MAXU8_INT EQU 255");

	AddLineQueue("FLT_MAXI16_INT EQU 32767");
	AddLineQueue("FLT_MINI16_INT EQU (-32768)");
	AddLineQueue("FLT_MAXU16_INT EQU 65535");

	AddLineQueue("FLT_MAXI32_INT EQU 2147483647");
	AddLineQueue("FLT_MINI32_INT EQU (-2147483648)");
	AddLineQueue("FLT_MAXU32_INT EQU (-1)");

	AddLineQueue("FLT_MAXI8XU8_INT EQU 32768");
	AddLineQueue("FLT_MINI8XU8_INT EQU (-32768)");
	AddLineQueue("FLT_MAXI8XU16_INT EQU 8388608");
	AddLineQueue("FLT_MINI8XU16_INT EQU (-8388608)");

	AddLineQueue("FLT_MAXI16XU16_INT EQU (-2147483648)");
	AddLineQueue("FLT_MINI16XU16_INT EQU (-2147483648)");

	AddLineQueue("FLT_FIXUNSIGNED_INT EQU (-2147483648)");
	AddLineQueue("FLT_FIXMAXI32_INT EQU 2147483520");
	AddLineQueue("FLT_FIXMAXU32_INT EQU (-256)");

	/*float*/
	AddLineQueue("FLT_1LSHL12 EQU 4096.0");
	AddLineQueue("FLT_1LSHL23 EQU 8388608.0");
	AddLineQueue("FLT_1LSHL24 EQU 16777216.0");
	AddLineQueue("FLT_1LSHL31 EQU (-2147483648.0)");

	AddLineQueue("FLT_NEG1LSHL12 EQU (-4096.0)");
	AddLineQueue("FLT_NEG1LSHL23 EQU (-8388608.0)");
	AddLineQueue("FLT_NEG1LSHL24 EQU (-16777216.0)");

	AddLineQueue("FLT_FALSE EQU 0.0");
	AddLineQueue("FLT_TRUE EQU FLT_TRUE_MSK");

	AddLineQueue("FLT_MAGIC EQU FLT_MAGIC_MSK");
	AddLineQueue("FLT_SIGN EQU FLT_SIGN_MSK");
	AddLineQueue("FLT_INVSIGN EQU FLT_INVSIGN_MSK");

	AddLineQueue("FLT_INF EQU FLT_INF_MSK");
	AddLineQueue("FLT_FIN EQU FLT_FIN_MSK");
	AddLineQueue("FLT_INVINF EQU FLT_INVINF_MSK");
	AddLineQueue("FLT_NEGINF EQU FLT_NEGINF_MSK");
	AddLineQueue("FLT_NAN EQU FLT_NAN_MSK");
	AddLineQueue("FLT_QNAN EQU FLT_QNAN_MSK");
	AddLineQueue("FLT_NEGQNAN EQU FLT_NEGQNAN_MSK");
	AddLineQueue("FLT_NANTEST EQU FLT_NANTEST_MSK");
	AddLineQueue("FLT_ABS EQU FLT_ABS_MSK");
	AddLineQueue("FLT_MIN EQU 1.175494351e-38");
	AddLineQueue("FLT_MAX EQU 3.402823457175904428664032e+38");
	AddLineQueue("FLT_NOFRACTION EQU 8388608.0");
	AddLineQueue("FLT_MINDENORM EQU 1.401298463344573974609375e-45");
	AddLineQueue("FLT_DENORMLIMIT EQU 1.175494351e-38");
	AddLineQueue("FLT_MINNORMAL EQU 1.175494351e-38");
	AddLineQueue("FLT_MAXNORMAL EQU 3.402823457175904428664032e+38");

	AddLineQueue("FLT_DECDIG EQU 9.0");
	AddLineQueue("FLT_DIG EQU 6.0");
	AddLineQueue("FLT_NEGDECDIG EQU (-9.0)");
	AddLineQueue("FLT_NEGDIG EQU (-6.0)");
	AddLineQueue("FLT_EPS EQU 1.192092896e-07");
	AddLineQueue("FLT_EPSILON EQU 1.192092896e-07");
	AddLineQueue("FLT_NORMEPS EQU 1e-20");
	AddLineQueue("FLT_GUARD EQU 0.0");
	AddLineQueue("FLT_MANTPOW2 EQU 1.175494351e-38");
	AddLineQueue("FLT_MAXMANTPOW2 EQU 3.402823457175904428664032e+38");
	AddLineQueue("FLT_MANTDIG EQU 24.0");
	AddLineQueue("FLT_MANT EQU 23.0");
	AddLineQueue("FLT_NEGMANTDIG EQU (-24.0)");
	AddLineQueue("FLT_NEGMANT EQU (-23.0)");
	AddLineQueue("FLT_MAXEXP EQU 128.0");
	AddLineQueue("FLT_EXPSIGN EQU 128.0");
	AddLineQueue("FLT_EXP EQU 127.0");
	AddLineQueue("FLT_NEGMAXEXP EQU (-128.0)");
	AddLineQueue("FLT_NEGEXPSIGN EQU (-128.0)");
	AddLineQueue("FLT_NEGEXP EQU (-127.0)");
	AddLineQueue("FLT_SUBNORMALEXP EQU (-126.0)");
	AddLineQueue("FLT_MINEXP EQU (-125.0)");
	AddLineQueue("FLT_MAXDECEXP EQU 38.0");
	AddLineQueue("FLT_NEGMAXDECEXP EQU (-38.0)");
	AddLineQueue("FLT_MINDECEXP EQU (-37.0)");
	AddLineQueue("FLT_EXPFIELD EQU (-16777216.0)");
	AddLineQueue("FLT_MANTFIELD EQU 16777215.0");
	AddLineQueue("FLT_NORM EQU 0.0");
	AddLineQueue("FLT_RADIX EQU 2.0");
	AddLineQueue("FLT_ROUNDS EQU 1.0");
	AddLineQueue("FLT_SUBDEC EQU 10.0");
	AddLineQueue("FLT_SQRTMAX EQU 1.8446726e+019");
	AddLineQueue("FLT_SMALNORMAL EQU 1.175494351e-38");

	AddLineQueue("FLT_HALFMINUSEPS EQU 0.499999910593032825");
	AddLineQueue("FLT_TRUEINT EQU 1.0");

	AddLineQueue("FLT_BYTE EQU 255.0");
	AddLineQueue("FLT_4LOW EQU 268435455.0");
	AddLineQueue("FLT_4HIGH EQU (-16.0)");
	AddLineQueue("FLT_FLIP4 EQU 8.0");
	AddLineQueue("FLT_8LOW EQU 16777215.0");
	AddLineQueue("FLT_8HIGH EQU (-256.0)");
	AddLineQueue("FLT_FLIP8 EQU 128.0");
	AddLineQueue("FLT_16LOW EQU 65535.0");
	AddLineQueue("FLT_16HIGH EQU (-65536.0)");
	AddLineQueue("FLT_FLIP16 EQU 32768.0");
	AddLineQueue("FLT_24LOW EQU 255.0");
	AddLineQueue("FLT_24HIGH EQU (-16777216.0)");
	AddLineQueue("FLT_FLIP24 EQU 8388608.0");
	AddLineQueue("FLT_28LOW EQU 15.0");
	AddLineQueue("FLT_28HIGH EQU (-268435456.0)");
	AddLineQueue("FLT_FLIP28 EQU 134217728.0");
	AddLineQueue("FLT_LOW EQU 0.0");
	AddLineQueue("FLT_HIGH EQU 0.0");
	AddLineQueue("FLT_FLIP EQU (-2147483648.0)");

	AddLineQueue("FLT_0 EQU 0.0");
	AddLineQueue("FLT_0D0001 EQU 0.0001");
	AddLineQueue("FLT_0D0002 EQU 0.0002");
	AddLineQueue("FLT_0D0003 EQU 0.0003");
	AddLineQueue("FLT_0D0004 EQU 0.0004");
	AddLineQueue("FLT_0D0005 EQU 0.0005");
	AddLineQueue("FLT_0D0006 EQU 0.0006");
	AddLineQueue("FLT_0D0007 EQU 0.0007");
	AddLineQueue("FLT_0D0008 EQU 0.0008");
	AddLineQueue("FLT_0D0009 EQU 0.0009");
	AddLineQueue("FLT_0D001 EQU 0.001");
	AddLineQueue("FLT_0D002 EQU 0.002");
	AddLineQueue("FLT_0D003 EQU 0.003");
	AddLineQueue("FLT_0D004 EQU 0.004");
	AddLineQueue("FLT_0D005 EQU 0.005");
	AddLineQueue("FLT_0D006 EQU 0.006");
	AddLineQueue("FLT_0D007 EQU 0.007");
	AddLineQueue("FLT_0D008 EQU 0.008");
	AddLineQueue("FLT_0D009 EQU 0.009");
	AddLineQueue("FLT_0D01 EQU 0.01");
	AddLineQueue("FLT_0D02 EQU 0.02");
	AddLineQueue("FLT_0D025 EQU 0.025");
	AddLineQueue("FLT_0D03 EQU 0.03");
	AddLineQueue("FLT_0D04 EQU 0.04");
	AddLineQueue("FLT_0D05 EQU 0.05");
	AddLineQueue("FLT_0D06 EQU 0.06");
	AddLineQueue("FLT_0D07 EQU 0.07");
	AddLineQueue("FLT_0D08 EQU 0.08");
	AddLineQueue("FLT_0D09 EQU 0.09");
	AddLineQueue("FLT_0D1 EQU 0.1");
	AddLineQueue("FLT_0D2 EQU 0.2");
	AddLineQueue("FLT_0D25 EQU 0.25");
	AddLineQueue("FLT_0D3 EQU 0.3");
	AddLineQueue("FLT_0D4 EQU 0.4");
	AddLineQueue("FLT_0D5 EQU 0.5");
	AddLineQueue("FLT_0D6 EQU 0.6");
	AddLineQueue("FLT_0D7 EQU 0.7");
	AddLineQueue("FLT_0D8 EQU 0.8");
	AddLineQueue("FLT_0D9 EQU 0.9");
	AddLineQueue("FLT_1 EQU 1.0");
	AddLineQueue("FLT_1D25 EQU 1.25");
	AddLineQueue("FLT_1D5 EQU 1.5");
	AddLineQueue("FLT_2 EQU 2.0");
	AddLineQueue("FLT_2D25 EQU 2.25");
	AddLineQueue("FLT_2D5 EQU 2.5");
	AddLineQueue("FLT_3 EQU 3.0");
	AddLineQueue("FLT_3D25 EQU 3.25");
	AddLineQueue("FLT_3D5 EQU 3.5");
	AddLineQueue("FLT_4 EQU 4.0");
	AddLineQueue("FLT_4D25 EQU 4.25");
	AddLineQueue("FLT_4D5 EQU 4.5");
	AddLineQueue("FLT_5 EQU 5.0");
	AddLineQueue("FLT_5D25 EQU 5.25");
	AddLineQueue("FLT_5D5 EQU 5.5");
	AddLineQueue("FLT_6 EQU 6.0");
	AddLineQueue("FLT_6D25 EQU 6.25");
	AddLineQueue("FLT_6D5 EQU 6.5");
	AddLineQueue("FLT_7 EQU 7.0");
	AddLineQueue("FLT_7D25 EQU 7.25");
	AddLineQueue("FLT_7D5 EQU 7.5");
	AddLineQueue("FLT_8 EQU 8.0");
	AddLineQueue("FLT_8D25 EQU 8.25");
	AddLineQueue("FLT_8D5 EQU 8.5");
	AddLineQueue("FLT_9 EQU 9.0");
	AddLineQueue("FLT_9D25 EQU 9.25");
	AddLineQueue("FLT_9D5 EQU 9.5");
	AddLineQueue("FLT_10 EQU 10.0");
	AddLineQueue("FLT_11 EQU 11.0");
	AddLineQueue("FLT_12 EQU 12.0");
	AddLineQueue("FLT_13 EQU 13.0");
	AddLineQueue("FLT_14 EQU 14.0");
	AddLineQueue("FLT_15 EQU 15.0");
	AddLineQueue("FLT_16 EQU 16.0");
	AddLineQueue("FLT_17 EQU 17.0");
	AddLineQueue("FLT_18 EQU 18.0");
	AddLineQueue("FLT_19 EQU 19.0");
	AddLineQueue("FLT_20 EQU 20.0");
	AddLineQueue("FLT_21 EQU 21.0");
	AddLineQueue("FLT_22 EQU 22.0");
	AddLineQueue("FLT_23 EQU 23.0");
	AddLineQueue("FLT_24 EQU 24.0");
	AddLineQueue("FLT_24D5 EQU 24.5");
	AddLineQueue("FLT_25 EQU 25.0");
	AddLineQueue("FLT_26 EQU 26.0");
	AddLineQueue("FLT_27 EQU 27.0");
	AddLineQueue("FLT_28 EQU 28.0");
	AddLineQueue("FLT_29 EQU 29.0");
	AddLineQueue("FLT_30 EQU 30.0");
	AddLineQueue("FLT_31 EQU 31.0");
	AddLineQueue("FLT_32 EQU 32.0");
	AddLineQueue("FLT_33 EQU 33.0");
	AddLineQueue("FLT_34 EQU 34.0");
	AddLineQueue("FLT_35 EQU 35.0");
	AddLineQueue("FLT_36 EQU 36.0");
	AddLineQueue("FLT_37 EQU 37.0");
	AddLineQueue("FLT_38 EQU 38.0");
	AddLineQueue("FLT_39 EQU 39.0");
	AddLineQueue("FLT_40 EQU 40.0");
	AddLineQueue("FLT_41 EQU 41.0");
	AddLineQueue("FLT_42 EQU 42.0");
	AddLineQueue("FLT_43 EQU 43.0");
	AddLineQueue("FLT_44 EQU 44.0");
	AddLineQueue("FLT_45 EQU 45.0");
	AddLineQueue("FLT_46 EQU 46.0");
	AddLineQueue("FLT_47 EQU 47.0");
	AddLineQueue("FLT_48 EQU 48.0");
	AddLineQueue("FLT_49 EQU 49.0");
	AddLineQueue("FLT_50 EQU 50.0");
	AddLineQueue("FLT_51 EQU 51.0");
	AddLineQueue("FLT_52 EQU 52.0");
	AddLineQueue("FLT_53 EQU 53.0");
	AddLineQueue("FLT_54 EQU 54.0");
	AddLineQueue("FLT_55 EQU 55.0");
	AddLineQueue("FLT_56 EQU 56.0");
	AddLineQueue("FLT_57 EQU 57.0");
	AddLineQueue("FLT_58 EQU 58.0");
	AddLineQueue("FLT_59 EQU 59.0");
	AddLineQueue("FLT_60 EQU 60.0");
	AddLineQueue("FLT_61 EQU 61.0");
	AddLineQueue("FLT_62 EQU 62.0");
	AddLineQueue("FLT_63 EQU 63.0");
	AddLineQueue("FLT_64 EQU 64.0");
	AddLineQueue("FLT_65 EQU 65.0");
	AddLineQueue("FLT_66 EQU 66.0");
	AddLineQueue("FLT_67 EQU 67.0");
	AddLineQueue("FLT_68 EQU 68.0");
	AddLineQueue("FLT_69 EQU 69.0");
	AddLineQueue("FLT_70 EQU 70.0");
	AddLineQueue("FLT_71 EQU 71.0");
	AddLineQueue("FLT_72 EQU 72.0");
	AddLineQueue("FLT_73 EQU 73.0");
	AddLineQueue("FLT_74 EQU 74.0");
	AddLineQueue("FLT_75 EQU 75.0");
	AddLineQueue("FLT_76 EQU 76.0");
	AddLineQueue("FLT_77 EQU 77.0");
	AddLineQueue("FLT_78 EQU 78.0");
	AddLineQueue("FLT_79 EQU 79.0");
	AddLineQueue("FLT_80 EQU 80.0");
	AddLineQueue("FLT_81 EQU 81.0");
	AddLineQueue("FLT_82 EQU 82.0");
	AddLineQueue("FLT_83 EQU 83.0");
	AddLineQueue("FLT_84 EQU 84.0");
	AddLineQueue("FLT_85 EQU 85.0");
	AddLineQueue("FLT_86 EQU 86.0");
	AddLineQueue("FLT_87 EQU 87.0");
	AddLineQueue("FLT_88 EQU 88.0");
	AddLineQueue("FLT_89 EQU 89.0");
	AddLineQueue("FLT_90 EQU 90.0");
	AddLineQueue("FLT_91 EQU 91.0");
	AddLineQueue("FLT_92 EQU 92.0");
	AddLineQueue("FLT_93 EQU 93.0");
	AddLineQueue("FLT_94 EQU 94.0");
	AddLineQueue("FLT_95 EQU 95.0");
	AddLineQueue("FLT_96 EQU 96.0");
	AddLineQueue("FLT_97 EQU 97.0");
	AddLineQueue("FLT_98 EQU 98.0");
	AddLineQueue("FLT_99 EQU 99.0");
	AddLineQueue("FLT_100 EQU 100.0");
	AddLineQueue("FLT_125 EQU 125.0");
	AddLineQueue("FLT_126 EQU 126.0");
	AddLineQueue("FLT_127 EQU 127.0");
	AddLineQueue("FLT_128 EQU 128.0");
	AddLineQueue("FLT_140 EQU 140.0");
	AddLineQueue("FLT_145 EQU 145.0");
	AddLineQueue("FLT_150 EQU 150.0");
	AddLineQueue("FLT_180 EQU 180.0");
	AddLineQueue("FLT_253 EQU 253.0");
	AddLineQueue("FLT_254 EQU 254.0");
	AddLineQueue("FLT_255 EQU 255.0");
	AddLineQueue("FLT_256 EQU 256.0");
	AddLineQueue("FLT_360 EQU 360.0");
	AddLineQueue("FLT_511 EQU 511.0");
	AddLineQueue("FLT_512 EQU 512.0");
	AddLineQueue("FLT_513 EQU 513.0");
	AddLineQueue("FLT_1023 EQU 1023.0");
	AddLineQueue("FLT_1024 EQU 1024.0");
	AddLineQueue("FLT_1025 EQU 1025.0");

	AddLineQueue("FLT_32767 EQU 32767.0");
	AddLineQueue("FLT_32768 EQU 32768.0");
	AddLineQueue("FLT_65535 EQU 65535.0");
	AddLineQueue("FLT_65536 EQU 65536.0");
	AddLineQueue("FLT_2147483647 EQU 2147483647.0");
	AddLineQueue("FLT_2147483648 EQU 2147483648.0");
	AddLineQueue("FLT_4294967295 EQU 4294967295.0");
	AddLineQueue("FLT_4294967296 EQU 4294967296.0");

	AddLineQueue("FLT_NEG0 EQU (-0.0)");
	AddLineQueue("FLT_NEG0D0001 EQU (-0.0001)");
	AddLineQueue("FLT_NEG0D0002 EQU (-0.0002)");
	AddLineQueue("FLT_NEG0D0003 EQU (-0.0003)");
	AddLineQueue("FLT_NEG0D0004 EQU (-0.0004)");
	AddLineQueue("FLT_NEG0D0005 EQU (-0.0005)");
	AddLineQueue("FLT_NEG0D0006 EQU (-0.0006)");
	AddLineQueue("FLT_NEG0D0007 EQU (-0.0007)");
	AddLineQueue("FLT_NEG0D0008 EQU (-0.0008)");
	AddLineQueue("FLT_NEG0D0009 EQU (-0.0009)");
	AddLineQueue("FLT_NEG0D001 EQU (-0.001)");
	AddLineQueue("FLT_NEG0D002 EQU (-0.002)");
	AddLineQueue("FLT_NEG0D003 EQU (-0.003)");
	AddLineQueue("FLT_NEG0D004 EQU (-0.004)");
	AddLineQueue("FLT_NEG0D005 EQU (-0.005)");
	AddLineQueue("FLT_NEG0D006 EQU (-0.006)");
	AddLineQueue("FLT_NEG0D007 EQU (-0.007)");
	AddLineQueue("FLT_NEG0D008 EQU (-0.008)");
	AddLineQueue("FLT_NEG0D009 EQU (-0.009)");
	AddLineQueue("FLT_NEG0D01 EQU (-0.01)");
	AddLineQueue("FLT_NEG0D02 EQU (-0.02)");
	AddLineQueue("FLT_NEG0D025 EQU (-0.025)");
	AddLineQueue("FLT_NEG0D03 EQU (-0.03)");
	AddLineQueue("FLT_NEG0D04 EQU (-0.04)");
	AddLineQueue("FLT_NEG0D05 EQU (-0.05)");
	AddLineQueue("FLT_NEG0D06 EQU (-0.06)");
	AddLineQueue("FLT_NEG0D07 EQU (-0.07)");
	AddLineQueue("FLT_NEG0D08 EQU (-0.08)");
	AddLineQueue("FLT_NEG0D09 EQU (-0.09)");
	AddLineQueue("FLT_NEG0D1 EQU (-0.1)");
	AddLineQueue("FLT_NEG0D2 EQU (-0.2)");
	AddLineQueue("FLT_NEG0D25 EQU (-0.25)");
	AddLineQueue("FLT_NEG0D3 EQU (-0.3)");
	AddLineQueue("FLT_NEG0D4 EQU (-0.4)");
	AddLineQueue("FLT_NEG0D5 EQU (-0.5)");
	AddLineQueue("FLT_NEG0D6 EQU (-0.6)");
	AddLineQueue("FLT_NEG0D7 EQU (-0.7)");
	AddLineQueue("FLT_NEG0D8 EQU (-0.8)");
	AddLineQueue("FLT_NEG0D9 EQU (-0.9)");
	AddLineQueue("FLT_NEG1 EQU (-1.0)");
	AddLineQueue("FLT_NEG1D25 EQU (-1.25)");
	AddLineQueue("FLT_NEG2 EQU (-2.0)");
	AddLineQueue("FLT_NEG2D25 EQU (-2.25)");
	AddLineQueue("FLT_NEG3 EQU (-3.0)");
	AddLineQueue("FLT_NEG3D25 EQU (-3.25)");
	AddLineQueue("FLT_NEG4 EQU (-4.0)");
	AddLineQueue("FLT_NEG4D25 EQU (-4.25)");
	AddLineQueue("FLT_NEG5 EQU (-5.0)");
	AddLineQueue("FLT_NEG5D25 EQU (-5.25)");
	AddLineQueue("FLT_NEG6 EQU (-6.0)");
	AddLineQueue("FLT_NEG6D25 EQU (-6.25)");
	AddLineQueue("FLT_NEG7 EQU (-7.0)");
	AddLineQueue("FLT_NEG7D25 EQU (-7.25)");
	AddLineQueue("FLT_NEG8 EQU (-8.0)");
	AddLineQueue("FLT_NEG8D25 EQU (-8.25)");
	AddLineQueue("FLT_NEG9 EQU (-9.0)");
	AddLineQueue("FLT_NEG9D25 EQU (-9.25)");
	AddLineQueue("FLT_NEG10 EQU (-10.0)");
	AddLineQueue("FLT_NEG11 EQU (-11.0)");
	AddLineQueue("FLT_NEG12 EQU (-12.0)");
	AddLineQueue("FLT_NEG13 EQU (-13.0)");
	AddLineQueue("FLT_NEG14 EQU (-14.0)");
	AddLineQueue("FLT_NEG15 EQU (-15.0)");
	AddLineQueue("FLT_NEG16 EQU (-16.0)");
	AddLineQueue("FLT_NEG17 EQU (-17.0)");
	AddLineQueue("FLT_NEG18 EQU (-18.0)");
	AddLineQueue("FLT_NEG19 EQU (-19.0)");
	AddLineQueue("FLT_NEG20 EQU (-20.0)");
	AddLineQueue("FLT_NEG21 EQU (-21.0)");
	AddLineQueue("FLT_NEG22 EQU (-22.0)");
	AddLineQueue("FLT_NEG23 EQU (-23.0)");
	AddLineQueue("FLT_NEG24 EQU (-24.0)");
	AddLineQueue("FLT_NEG24D5 EQU (-24.5)");
	AddLineQueue("FLT_NEG25 EQU (-25.0)");
	AddLineQueue("FLT_NEG26 EQU (-26.0)");
	AddLineQueue("FLT_NEG27 EQU (-27.0)");
	AddLineQueue("FLT_NEG28 EQU (-28.0)");
	AddLineQueue("FLT_NEG29 EQU (-29.0)");
	AddLineQueue("FLT_NEG30 EQU (-30.0)");
	AddLineQueue("FLT_NEG31 EQU (-31.0)");
	AddLineQueue("FLT_NEG32 EQU (-32.0)");
	AddLineQueue("FLT_NEG33 EQU (-33.0)");
	AddLineQueue("FLT_NEG34 EQU (-34.0)");
	AddLineQueue("FLT_NEG35 EQU (-35.0)");
	AddLineQueue("FLT_NEG36 EQU (-36.0)");
	AddLineQueue("FLT_NEG37 EQU (-37.0)");
	AddLineQueue("FLT_NEG38 EQU (-38.0)");
	AddLineQueue("FLT_NEG39 EQU (-39.0)");
	AddLineQueue("FLT_NEG40 EQU (-40.0)");
	AddLineQueue("FLT_NEG41 EQU (-41.0)");
	AddLineQueue("FLT_NEG42 EQU (-42.0)");
	AddLineQueue("FLT_NEG43 EQU (-43.0)");
	AddLineQueue("FLT_NEG44 EQU (-44.0)");
	AddLineQueue("FLT_NEG45 EQU (-45.0)");
	AddLineQueue("FLT_NEG46 EQU (-46.0)");
	AddLineQueue("FLT_NEG47 EQU (-47.0)");
	AddLineQueue("FLT_NEG48 EQU (-48.0)");
	AddLineQueue("FLT_NEG49 EQU (-49.0)");
	AddLineQueue("FLT_NEG50 EQU (-50.0)");
	AddLineQueue("FLT_NEG51 EQU (-51.0)");
	AddLineQueue("FLT_NEG52 EQU (-52.0)");
	AddLineQueue("FLT_NEG53 EQU (-53.0)");
	AddLineQueue("FLT_NEG54 EQU (-54.0)");
	AddLineQueue("FLT_NEG55 EQU (-55.0)");
	AddLineQueue("FLT_NEG56 EQU (-56.0)");
	AddLineQueue("FLT_NEG57 EQU (-57.0)");
	AddLineQueue("FLT_NEG58 EQU (-58.0)");
	AddLineQueue("FLT_NEG59 EQU (-59.0)");
	AddLineQueue("FLT_NEG60 EQU (-60.0)");
	AddLineQueue("FLT_NEG61 EQU (-61.0)");
	AddLineQueue("FLT_NEG62 EQU (-62.0)");
	AddLineQueue("FLT_NEG63 EQU (-63.0)");
	AddLineQueue("FLT_NEG64 EQU (-64.0)");
	AddLineQueue("FLT_NEG65 EQU (-65.0)");
	AddLineQueue("FLT_NEG66 EQU (-66.0)");
	AddLineQueue("FLT_NEG67 EQU (-67.0)");
	AddLineQueue("FLT_NEG68 EQU (-68.0)");
	AddLineQueue("FLT_NEG69 EQU (-69.0)");
	AddLineQueue("FLT_NEG70 EQU (-70.0)");
	AddLineQueue("FLT_NEG71 EQU (-71.0)");
	AddLineQueue("FLT_NEG72 EQU (-72.0)");
	AddLineQueue("FLT_NEG73 EQU (-73.0)");
	AddLineQueue("FLT_NEG74 EQU (-74.0)");
	AddLineQueue("FLT_NEG75 EQU (-75.0)");
	AddLineQueue("FLT_NEG76 EQU (-76.0)");
	AddLineQueue("FLT_NEG77 EQU (-77.0)");
	AddLineQueue("FLT_NEG78 EQU (-78.0)");
	AddLineQueue("FLT_NEG79 EQU (-79.0)");
	AddLineQueue("FLT_NEG80 EQU (-80.0)");
	AddLineQueue("FLT_NEG81 EQU (-81.0)");
	AddLineQueue("FLT_NEG82 EQU (-82.0)");
	AddLineQueue("FLT_NEG83 EQU (-83.0)");
	AddLineQueue("FLT_NEG84 EQU (-84.0)");
	AddLineQueue("FLT_NEG85 EQU (-85.0)");
	AddLineQueue("FLT_NEG86 EQU (-86.0)");
	AddLineQueue("FLT_NEG87 EQU (-87.0)");
	AddLineQueue("FLT_NEG88 EQU (-88.0)");
	AddLineQueue("FLT_NEG89 EQU (-89.0)");
	AddLineQueue("FLT_NEG90 EQU (-90.0)");
	AddLineQueue("FLT_NEG91 EQU (-91.0)");
	AddLineQueue("FLT_NEG92 EQU (-92.0)");
	AddLineQueue("FLT_NEG93 EQU (-93.0)");
	AddLineQueue("FLT_NEG94 EQU (-94.0)");
	AddLineQueue("FLT_NEG95 EQU (-95.0)");
	AddLineQueue("FLT_NEG96 EQU (-96.0)");
	AddLineQueue("FLT_NEG97 EQU (-97.0)");
	AddLineQueue("FLT_NEG98 EQU (-98.0)");
	AddLineQueue("FLT_NEG99 EQU (-99.0)");
	AddLineQueue("FLT_NEG100 EQU (-100.0)");
	AddLineQueue("FLT_NEG125 EQU (-125.0)");
	AddLineQueue("FLT_NEG126 EQU (-126.0)");
	AddLineQueue("FLT_NEG127 EQU (-127.0)");
	AddLineQueue("FLT_NEG128 EQU (-128.0)");
	AddLineQueue("FLT_NEG140 EQU (-140.0)");
	AddLineQueue("FLT_NEG145 EQU (-145.0)");
	AddLineQueue("FLT_NEG150 EQU (-150.0)");
	AddLineQueue("FLT_NEG180 EQU (-180.0)");
	AddLineQueue("FLT_NEG253 EQU (-253.0)");
	AddLineQueue("FLT_NEG254 EQU (-254.0)");
	AddLineQueue("FLT_NEG255 EQU (-255.0)");
	AddLineQueue("FLT_NEG256 EQU (-256.0)");
	AddLineQueue("FLT_NEG360 EQU (-360.0)");
	AddLineQueue("FLT_NEG511 EQU (-511.0)");
	AddLineQueue("FLT_NEG512 EQU (-512.0)");
	AddLineQueue("FLT_NEG513 EQU (-513.0)");
	AddLineQueue("FLT_NEG1023 EQU (-1023.0)");
	AddLineQueue("FLT_NEG1024 EQU (-1024.0)");
	AddLineQueue("FLT_NEG1025 EQU (-1025.0)");

	AddLineQueue("FLT_NEG32767 EQU (-32767.0)");
	AddLineQueue("FLT_NEG32768 EQU (-32768.0)");
	AddLineQueue("FLT_NEG65535 EQU (-65535.0)");
	AddLineQueue("FLT_NEG65536 EQU (-65536.0)");
	AddLineQueue("FLT_NEG2147483647 EQU (-2147483647.0)");
	AddLineQueue("FLT_NEG2147483648 EQU (-2147483648.0)");
	AddLineQueue("FLT_NEG4294967295 EQU (-4294967295.0)");
	AddLineQueue("FLT_NEG4294967296 EQU (-4294967296.0)");

	AddLineQueue("FLT_BIN128 EQU FLT_128");
	AddLineQueue("FLT_BINNEG150 EQU FLT_NEG150");

	AddLineQueue("FLT_MAXRAND EQU FLT_32767");

	AddLineQueue("FLT_MAXI8 EQU 127.0");
	AddLineQueue("FLT_MINI8 EQU (-128.0)");
	AddLineQueue("FLT_MAXU8 EQU 255.0");
	AddLineQueue("FLT_MINU8 EQU 0.0");

	AddLineQueue("FLT_MAXI16 EQU 32767.0");
	AddLineQueue("FLT_MINI16 EQU (-32768.0)");
	AddLineQueue("FLT_MAXU16 EQU 65535.0");
	AddLineQueue("FLT_MINU16 EQU 0.0");

	AddLineQueue("FLT_MAXI32 EQU 2147483647.0");
	AddLineQueue("FLT_MINI32 EQU (-2147483648.0)");
	AddLineQueue("FLT_MAXU32 EQU 4294967295.0");
	AddLineQueue("FLT_MINU32 EQU 0.0");

	AddLineQueue("FLT_MAXI8XU8 EQU 32768.0");
	AddLineQueue("FLT_MINI8XU8 EQU (-32768.0)");
	AddLineQueue("FLT_MAXI8XU16 EQU 8388608.0");
	AddLineQueue("FLT_MINI8XU16 EQU (-8388608.0)");

	AddLineQueue("FLT_MAXI16XU16 EQU 2147483648.0");
	AddLineQueue("FLT_MINI16XU16 EQU (-2147483648.0)");

	AddLineQueue("FLT_FIXUNSIGNED EQU 2147483648.0");
	AddLineQueue("FLT_FIXMAXI32 EQU 2147483520.0");
	AddLineQueue("FLT_FIXMAXU32 EQU 4294967040.0");

	AddLineQueue("FLT_RCPI16 EQU 3.0518509475997192297128208258309e-5");
	AddLineQueue("FLT_RCPU16 EQU 0.0000152587890625");
	AddLineQueue("FLT_RCPI16XU16 EQU 4.656754985961485641041291543321e-10");

	AddLineQueue("FLT_FIXAA8 EQU FLT_0");
	AddLineQueue("FLT_FIXR8 EQU FLT_0");
	AddLineQueue("FLT_FIXG8 EQU FLT_0");
	AddLineQueue("FLT_FIXB8 EQU FLT_2147483648");

	AddLineQueue("FLT_NORMA8 EQU 257.00392156862745098039215686275");
	AddLineQueue("FLT_NORMR8 EQU 1.0039215686274509803921568627451");
	AddLineQueue("FLT_NORMG8 EQU 0.0039215686274509803921568627451");
	AddLineQueue("FLT_NORMB8 EQU 65793.003921568627450980392156863");

	AddLineQueue("FLT_FIXAA2 EQU (-512.0)");
	AddLineQueue("FLT_FIXB10 EQU (-524288.0)");
	AddLineQueue("FLT_FIXG10 EQU (-536870912.0)");
	AddLineQueue("FLT_FIXR10 EQU FLT_2147483648");

	AddLineQueue("FLT_NORMA2 EQU 0.00195694716242661448140900195695");
	AddLineQueue("FLT_NORMB10 EQU 2.0039138943248532289628180039139");
	AddLineQueue("FLT_NORMG10 EQU 4.0156708958681990341642380352403");
	AddLineQueue("FLT_NORMR10 EQU 357913941.33333333333333333333333");

	AddLineQueue("FLT_MG EQU 1024.0");
	AddLineQueue("FLT_NEGMG EQU (-1024.0)");
	AddLineQueue("FLT_HALFMG EQU 512.0");
	AddLineQueue("FLT_NEGHALFMG EQU (-512.0)");
	AddLineQueue("FLT_MGDIV4 EQU 256.0");
	AddLineQueue("FLT_NEGMGDIV4 EQU (-256.0)");
	AddLineQueue("FLT_HALFMGXMG EQU 524288.0");
	AddLineQueue("FLT_HALFMGXSQRMG EQU 536870912.0");
	AddLineQueue("FLT_HALFMGXCUBEMG EQU 549755813888.0");
	AddLineQueue("FLT_NEGHALFMGXMG EQU (-524288.0)");
	AddLineQueue("FLT_NEGHALFMGXSQRMG EQU (-536870912.0)");
	AddLineQueue("FLT_NEGHALFMGXCUBEMG EQU (-549755813888.0)");
	AddLineQueue("FLT_SQRMG EQU 1048576.0");
	AddLineQueue("FLT_CUBEMG EQU 1073741824.0");
	AddLineQueue("FLT_SQRTMG EQU 32.0");
	AddLineQueue("FLT_CBRTMG EQU 10.0793683991589853181");
	AddLineQueue("FLT_RCPMG EQU 0.0009765625");
	AddLineQueue("FLT_RCPSQRMG EQU 0.00000095367431640625");
	AddLineQueue("FLT_RCPCUBEMG EQU 0.00000000093132257462");
	AddLineQueue("FLT_RCPSQRTMG EQU 0.03125");
	AddLineQueue("FLT_RCPCBRTMG EQU 0.09921256574801246717");

	AddLineQueue("FLT_2MG EQU 2048.0");
	AddLineQueue("FLT_NEG2MG EQU (-2048.0)");
	AddLineQueue("FLT_SQR2MG EQU 4194304.0");
	AddLineQueue("FLT_CUBE2MG EQU 8589934592.0");
	AddLineQueue("FLT_SQRT2MG EQU 45.25483399593904156165403917471");
	AddLineQueue("FLT_CBRT2MG EQU 12.699208415745595798013645114178");
	AddLineQueue("FLT_4MG EQU 4096.0");
	AddLineQueue("FLT_NEG4MG EQU (-4096.0)");
	AddLineQueue("FLT_SQR4MG EQU 16777216.0");
	AddLineQueue("FLT_CUBE4MG EQU 68719476736.0");
	AddLineQueue("FLT_SQRT4MG EQU 64.0");
	AddLineQueue("FLT_CBRT4MG EQU 16.0");
	AddLineQueue("FLT_RCP2MG EQU 0.00048828125");
	AddLineQueue("FLT_RCP4MG EQU 0.000244140625");

	AddLineQueue("FLT_E EQU 2.71828182845904523536");
	AddLineQueue("FLT_EXP EQU 2.71828182845904523536");
	AddLineQueue("FLT_LOGE EQU 0.434294481903251827651");
	AddLineQueue("FLT_LOGEHIGH EQU 0.434294481903251827651");
	AddLineQueue("FLT_LOG2E EQU 1.44269504088896340736");
	AddLineQueue("FLT_LOG2EHIGH EQU 1.44269504088896340736");
	AddLineQueue("FLT_LOG10E EQU 0.434294481903251827651");
	AddLineQueue("FLT_RCPLOG2E EQU 0.693147180559945309417");
	AddLineQueue("FLT_RCPLOG10E EQU 2.30258509299404568402");
	AddLineQueue("FLT_LOG2T EQU 3.3219280948873622");
	AddLineQueue("FLT_LOG2 EQU 0.301029995663981195214");
	AddLineQueue("FLT_LOG2HIGH EQU 0.301029995663981195214");
	AddLineQueue("FLT_LN2 EQU 0.693147180559945309417");
	AddLineQueue("FLT_LN2HIGH EQU 0.693147180559945309417");
	AddLineQueue("FLT_1DIVLN2 EQU 1.44269504088896340736");
	AddLineQueue("FLT_2DIVLN2 EQU 2.88539008177792681472");
	AddLineQueue("FLT_LNT EQU 2.3025850929940459");
	AddLineQueue("FLT_LNTHIGH EQU 2.3025850929940459");
	AddLineQueue("FLT_LN10 EQU 2.302585092994045684018");
	AddLineQueue("FLT_SQRT2 EQU 1.414213562373095048802");
	AddLineQueue("FLT_RCPSQRT2 EQU 0.707106781186547524401");
	AddLineQueue("FLT_SQRT2DIV2 EQU 0.707106781186547524401");
	AddLineQueue("FLT_SQRT2DIV2HIGH EQU 0.707106781186547524401");
	AddLineQueue("FLT_SQRT2DIV2LOW EQU 1.210161749e-08");
	AddLineQueue("FLT_SQRTHALF EQU 0.707106781186547524401");
	AddLineQueue("FLT_SQRTHALFHIGH EQU 0.707106781186547524401");
	AddLineQueue("FLT_SQRTHALFLOW EQU 1.210161749e-08");
	AddLineQueue("FLT_POW2 EQU 7.389056098930650227230");
	AddLineQueue("FLT_RCPPOW2 EQU 0.135335283236612691893");
	AddLineQueue("FLT_CBRT2 EQU 1.259921049894873164767");
	AddLineQueue("FLT_RCPCBRT2 EQU 0.793700525984099737375");
	AddLineQueue("FLT_1DIV3 EQU 0.333333333333333333333");
	AddLineQueue("FLT_1DIV7 EQU 0.142857142857142857142");
	AddLineQueue("FLT_1DIV9 EQU 0.111111111111111111111");
	AddLineQueue("FLT_2DIV3 EQU 0.666666666666666666667");
	AddLineQueue("FLT_2DIV7 EQU 0.285714285714285714285");
	AddLineQueue("FLT_2DIV9 EQU 0.222222222222222222222");
	AddLineQueue("FLT_4DIV3 EQU 1.333333333333333333333");
	AddLineQueue("FLT_4DIV7 EQU 0.571428571428571428571");
	AddLineQueue("FLT_4DIV9 EQU 0.444444444444444444444");

	AddLineQueue("FLT_PI EQU 3.14159265358979323846");
	AddLineQueue("FLT_PIHIGH EQU 3.14159265358979323846");
	AddLineQueue("FLT_HALFPI EQU 1.57079632679489661923");
	AddLineQueue("FLT_2PI EQU 6.28318530717958647692");
	AddLineQueue("FLT_NEGPI EQU (-3.14159265358979323846)");
	AddLineQueue("FLT_NEGHALFPI EQU (-1.57079632679489661923)");
	AddLineQueue("FLT_NEG2PI EQU (-6.28318530717958647692)");
	AddLineQueue("FLT_RCPPI EQU 0.31830988618379067154");
	AddLineQueue("FLT_INVPI EQU 0.31830988618379067154");
	AddLineQueue("FLT_RCP2PI EQU 0.15915494309189533577");
	AddLineQueue("FLT_INV2PI EQU 0.15915494309189533577");
	AddLineQueue("FLT_PIDIV2 EQU 1.57079632679489661923");
	AddLineQueue("FLT_PIDIV2HIGH EQU 1.57079632679489661923");
	AddLineQueue("FLT_PIDIV4 EQU 0.78539816339744830962");
	AddLineQueue("FLT_PIDIV4HIGH EQU 0.78539816339744830962");
	AddLineQueue("FLT_PIX3DIV4 EQU 2.35619449019234492884");
	AddLineQueue("FLT_SQRTPI EQU 1.77245385090551602729");
	AddLineQueue("FLT_SQRT2PI EQU 2.50662827463100050242");
	AddLineQueue("FLT_SQRT2PIHIGH EQU 2.50662827463100050242");
	AddLineQueue("FLT_RCPSQRTPI EQU 0.56418958354775628695");
	AddLineQueue("FLT_RCPSQRT2PI EQU 0.39894228040143267794");
	AddLineQueue("FLT_SQRTPIDIV2 EQU 0.88622692545275801365");
	AddLineQueue("FLT_SQRTPIDIV2HIGH EQU 0.88622692545275801365");
	AddLineQueue("FLT_SQRT2PIDIV2 EQU 1.25331413731550025121");
	AddLineQueue("FLT_SQRT2PIDIV2HIGH EQU 1.25331413731550025121");
	AddLineQueue("FLT_2DIVPI EQU 0.63661977236758134308");
	AddLineQueue("FLT_2DIV2PI EQU 0.31830988618379067154");
	AddLineQueue("FLT_2DIVSQRTPI EQU 1.12837916709551257389");
	AddLineQueue("FLT_2DIVSQRT2PI EQU 0.79788456080286535588");
	AddLineQueue("FLT_SQRT2DIVPI EQU 0.45015815807855303477");
	AddLineQueue("FLT_LOGPI EQU 0.49714987269413385435");
	AddLineQueue("FLT_LOG2PI EQU 0.79817986835811504957");
	AddLineQueue("FLT_LNPI EQU 1.14472988584940017415");
	AddLineQueue("FLT_LN2PI EQU 1.83787706640934548356");
	AddLineQueue("FLT_POWPI EQU 23.1406926327792690057");
	AddLineQueue("FLT_RCPPOWPI EQU 0.04321391826377224977");
	AddLineQueue("FLT_POW2PI EQU 535.491655524764736503");
	AddLineQueue("FLT_RCPPOW2PI EQU 0.00186744273170798881");
	AddLineQueue("FLT_CBRTPI EQU 1.46459188756152326302");
	AddLineQueue("FLT_RCPCBRTPI EQU 0.68278406325529568148");
	AddLineQueue("FLT_CBRT2PI EQU 1.84527014864402841910");
	AddLineQueue("FLT_RCPCBRT2PI EQU 0.54192607013928900874");

	AddLineQueue("FLT_POW2TOM126 EQU 1.175494351e-38");
	AddLineQueue("FLT_POW2TO126 EQU 8.507059173e37");
	AddLineQueue("FLT_NORMHUGE EQU 3.402823466e38");
	AddLineQueue("FLT_POW2TO23 EQU 8388608.0");
	AddLineQueue("FLT_POW2TO24 EQU 16777216.0");
	AddLineQueue("FLT_MAXI32POW2TO23 EQU 2139095039.0");
	AddLineQueue("FLT_POW2TO31 EQU 2147483648.0");
	AddLineQueue("FLT_POW2TO32 EQU 4294967296.0");

	AddLineQueue("FLT_REMQUOBITS EQU 3");
	AddLineQueue("FLT_REMQUOMASK EQU (~((~0)<<FLT_REMQUOBITS))");

	AddLineQueue("FLT_TRIGPLOSS EQU 105615.0");

	AddLineQueue("FLT_DEGTORAD EQU 0.017453292519943295769");
	AddLineQueue("FLT_RADTODEG EQU 57.29577951308232087679");

	AddLineQueue("FLT_DEGTOGRAD EQU 1.111111111111111111111");
	AddLineQueue("FLT_GRADTODEG EQU 0.9");

	AddLineQueue("FLT_RADTOGRAD EQU 63.66197723675813430755");
	AddLineQueue("FLT_GRADTORAD EQU 0.015707963267948966192");

	AddLineQueue("FLT_SUNGRAVITY EQU 274.13");
	AddLineQueue("FLT_JUPITERGRAVITY EQU 25.95");
	AddLineQueue("FLT_NEPTUNEGRAVITY EQU 14.07");
	AddLineQueue("FLT_SATURNGRAVITY EQU 11.08");
	AddLineQueue("FLT_URANUSGRAVITY EQU 10.67");
	AddLineQueue("FLT_EARTHGRAVITY EQU 9.81");
	AddLineQueue("FLT_VENUSGRAVITY EQU 8.87");
	AddLineQueue("FLT_MARSGRAVITY EQU 3.77");
	AddLineQueue("FLT_MERCURYGRAVITY EQU 3.59");
	AddLineQueue("FLT_MOONGRAVITY EQU 1.62");
	AddLineQueue("FLT_PLUTO EQU 0.42");

	AddLineQueue("FLT_KMTOINCH EQU 39370.08");
	AddLineQueue("FLT_KMTOFEET EQU 3280.84");
	AddLineQueue("FLT_KMTOYARDS EQU 1093.613");
	AddLineQueue("FLT_KMTOMILES EQU 0.000621371");

	AddLineQueue("FLT_METOINCH EQU 39.37008");
	AddLineQueue("FLT_METOFEET EQU 3.28084");
	AddLineQueue("FLT_METOYARDS EQU 1.093613");
	AddLineQueue("FLT_METOMILES EQU 0.000621371");

	AddLineQueue("FLT_CMTOINCH EQU 0.3937008");
	AddLineQueue("FLT_CMTOFEET EQU 0.0328084");
	AddLineQueue("FLT_CMTOYARDS EQU 0.01093613");
	AddLineQueue("FLT_CMTOMILES EQU 0.00000621371");

	AddLineQueue("FLT_MILLTOINCH EQU 0.03937008");
	AddLineQueue("FLT_MILLTOFEET EQU 0.00328084");
	AddLineQueue("FLT_MILLTOYARDS EQU 0.001093613");
	AddLineQueue("FLT_MILLTOMILES EQU 0.000000621371");

	AddLineQueue("FLT_INCHTOMILL EQU 25.4");
	AddLineQueue("FLT_INCHTOCM EQU 2.54");
	AddLineQueue("FLT_INCHTOME EQU 0.0254");
	AddLineQueue("FLT_INCHTOKM EQU 0.0000254");
	AddLineQueue("FLT_INCHTOFEET EQU 0.083333");
	AddLineQueue("FLT_INCHTOYARDS EQU 0.027778");
	AddLineQueue("FLT_INCHTOMILES EQU 0.000016");

	AddLineQueue("FLT_FEETTOMILL EQU 304.8");
	AddLineQueue("FLT_FEETTOCM EQU 30.48");
	AddLineQueue("FLT_FEETTOME EQU 0.3048");
	AddLineQueue("FLT_FEETTOKM EQU 0.0003048");
	AddLineQueue("FLT_FEETTOINCH EQU 12.0");
	AddLineQueue("FLT_FEETTOYARDS EQU 0.333333");
	AddLineQueue("FLT_FEETOMILES EQU 0.000189");

	AddLineQueue("FLT_YARDSTOMILL EQU 914.4");
	AddLineQueue("FLT_YARDSTOCM EQU 91.44");
	AddLineQueue("FLT_YARDSTOME EQU 0.9144");
	AddLineQueue("FLT_YARDSTOKM EQU 0.0009144");
	AddLineQueue("FLT_YARDSTOINCH EQU 36.0");
	AddLineQueue("FLT_YARDSTOFEET EQU 3.0");
	AddLineQueue("FLT_YARDSTOMILES EQU 0.000568");

	AddLineQueue("FLT_MILESTOMILL EQU 1609344.0");
	AddLineQueue("FLT_MILESTOCM EQU 160934.4");
	AddLineQueue("FLT_MILESTOME EQU 1609.344");
	AddLineQueue("FLT_MILESTOKM EQU 1.609344");
	AddLineQueue("FLT_MILESTOINCH EQU 63360.0");
	AddLineQueue("FLT_MILESTOFEET EQU 5280.0");
	AddLineQueue("FLT_MILESTOYARDS EQU 1760.0");

	AddLineQueue("FLT_KMPHTOMEPS EQU 0.27777777777778");
	AddLineQueue("FLT_KMPHTOKMPS EQU 0.00027777777777778");
	AddLineQueue("FLT_KMPHTOMEPM EQU 16.666666666667");
	AddLineQueue("FLT_KMPHTOMILESPH EQU 0.62137119223733");
	AddLineQueue("FLT_KMPHTOMILESPS EQU 0.00017260310895481");
	AddLineQueue("FLT_KMPHTOFOOTPS EQU 0.91134444444444");
	AddLineQueue("FLT_KMPHTOFOOTPM EQU 54.680666666667");

	AddLineQueue("FLT_KMPSTOMEPS EQU 1000.0");
	AddLineQueue("FLT_KMPSTOKMPH EQU 3600.0");
	AddLineQueue("FLT_KMPSTOMEPM EQU 60000.0");
	AddLineQueue("FLT_KMPSTOMILESPH EQU 2236.9362920544");
	AddLineQueue("FLT_KMPSTOMILESPS EQU 0.62137119223733");
	AddLineQueue("FLT_KMPSTOFOOTPS EQU 3280.84");
	AddLineQueue("FLT_KMPSTOFOOTPM EQU 196850.4");

	AddLineQueue("FLT_MEPSTOKMPH EQU 3.6");
	AddLineQueue("FLT_MEPSTOKMPS EQU 0.001");
	AddLineQueue("FLT_MEPSTOMEPM EQU 60.0");
	AddLineQueue("FLT_MEPSTOMILESPH EQU 2.2369362920544");
	AddLineQueue("FLT_MEPSTOMILESPS EQU 0.00062137119223733");
	AddLineQueue("FLT_MEPSTOFOOTPS EQU 3.28084");
	AddLineQueue("FLT_MEPSTOFOOTPM EQU 196.8504");

	AddLineQueue("FLT_MEPMTOKMPH EQU 0.06");
	AddLineQueue("FLT_MEPMTOKMPS EQU 1.6666666666667e-5");
	AddLineQueue("FLT_MEPMTOMEPS EQU 0.016666666666667");
	AddLineQueue("FLT_MEPMTOMILESPH EQU 0.03728227153424");
	AddLineQueue("FLT_MEPMTOMILESPS EQU 1.0356186537289e-5");
	AddLineQueue("FLT_MEPMTOFOOTPS EQU 0.054680666666667");
	AddLineQueue("FLT_MEPMTOFOOTPM EQU 3.28084");

	AddLineQueue("FLT_MILESPHTOKMPH EQU 1.609344");
	AddLineQueue("FLT_MILESPHTOKMPS EQU 0.00044704");
	AddLineQueue("FLT_MILESPHTOMEPS EQU 0.44704");
	AddLineQueue("FLT_MILESPHTOMEPM EQU 26.8224");
	AddLineQueue("FLT_MILESPHTOMILESPS EQU 0.00027777777777778");
	AddLineQueue("FLT_MILESPHTOFOOTPS EQU 1.4666667136");
	AddLineQueue("FLT_MILESPHTOFOOTPM EQU 88.000002816");

	AddLineQueue("FLT_MILESPSTOKMPH EQU 5793.6384");
	AddLineQueue("FLT_MILESPSTOKMPS EQU 1.609344");
	AddLineQueue("FLT_MILESPSTOMEPS EQU 1609.344");
	AddLineQueue("FLT_MILESPSTOMEPM EQU 96560.64");
	AddLineQueue("FLT_MILESPSTOMILESPM EQU 3600.0");
	AddLineQueue("FLT_MILESPSTOFOOTPS EQU 5280.00016896");
	AddLineQueue("FLT_MILESPSTOFOOTPM EQU 316800.0101376");

	AddLineQueue("FLT_FOOTPSTOKMPH EQU 1.097279964887");
	AddLineQueue("FLT_FOOTPSTOKMPS EQU 0.0003047999902464");
	AddLineQueue("FLT_FOOTPSTOMEPS EQU 0.3047999902464");
	AddLineQueue("FLT_FOOTPSTOMEPM EQU 18.287999414784");
	AddLineQueue("FLT_FOOTPSTOMILESPH EQU 0.68181816");
	AddLineQueue("FLT_FOOTPSTOMILESPS EQU 0.00018939393333333");
	AddLineQueue("FLT_FOOTPSTOFOOTPM EQU 60.0");

	AddLineQueue("FLT_FOOTPMTOKMPH EQU 0.018287999414784");
	AddLineQueue("FLT_FOOTPMTOKMPS EQU 5.07999983744e-6");
	AddLineQueue("FLT_FOOTPMTOMEPS EQU 0.00507999983744");
	AddLineQueue("FLT_FOOTPMTOMEPM EQU 0.3047999902464");
	AddLineQueue("FLT_FOOTPMTOMILESPH EQU 0.011363636");
	AddLineQueue("FLT_FOOTPMTOMILESPS EQU 3.1565655555556e-6");
	AddLineQueue("FLT_FOOTPMTOFOOTPS EQU 0.016666666666667");

	AddLineQueue("FLT_SOUNDSPEED50C EQU 360.35");
	AddLineQueue("FLT_SOUNDSPEED45C EQU 357.551");
	AddLineQueue("FLT_SOUNDSPEED40C EQU 354.73");
	AddLineQueue("FLT_SOUNDSPEED35C EQU 351.887");
	AddLineQueue("FLT_SOUNDSPEED30C EQU 349.02");
	AddLineQueue("FLT_SOUNDSPEED25C EQU 346.13");
	AddLineQueue("FLT_SOUNDSPEED20C EQU 343.216");
	AddLineQueue("FLT_SOUNDSPEED15C EQU 340.276");
	AddLineQueue("FLT_SOUNDSPEED10C EQU 337.311");
	AddLineQueue("FLT_SOUNDSPEED5C EQU 334.319");
	AddLineQueue("FLT_SOUNDSPEED0C EQU 331.301");
	AddLineQueue("FLT_SOUNDSPEEDN5C EQU 328.255");
	AddLineQueue("FLT_SOUNDSPEEDN10C EQU 325.18");
	AddLineQueue("FLT_SOUNDSPEEDN15C EQU 322.076");
	AddLineQueue("FLT_SOUNDSPEEDN20C EQU 318.942");
	AddLineQueue("FLT_SOUNDSPEEDN25C EQU 315.776");
	AddLineQueue("FLT_SOUNDSPEEDN30C EQU 312.579");
	AddLineQueue("FLT_SOUNDSPEEDN35C EQU 309.348");
	AddLineQueue("FLT_SOUNDSPEEDN40C EQU 306.083");
	AddLineQueue("FLT_SOUNDSPEEDN45C EQU 302.784");
	AddLineQueue("FLT_SOUNDSPEEDN50C EQU 299.447");

	AddLineQueue("FLT_SCHSCALE EQU FLT_1DIVLN2");
	AddLineQueue("FLT_THSCALE EQU FLT_2DIVLN2");

	AddLineQueue("FLT_EXPEST1 EQU (-6.93147182e-1)");
	AddLineQueue("FLT_EXPEST2 EQU (2.40226462e-1)");
	AddLineQueue("FLT_EXPEST3 EQU (-5.55036440e-2)");
	AddLineQueue("FLT_EXPEST4 EQU (9.61597636e-3)");
	AddLineQueue("FLT_EXPEST5 EQU (-1.32823968e-3)");
	AddLineQueue("FLT_EXPEST6 EQU (1.47491097e-4)");
	AddLineQueue("FLT_EXPEST7 EQU (-1.08635004e-5)");
	AddLineQueue("FLT_LOGEST0 EQU (1.442693)");
	AddLineQueue("FLT_LOGEST1 EQU (-0.721242)");
	AddLineQueue("FLT_LOGEST2 EQU (0.479384)");
	AddLineQueue("FLT_LOGEST3 EQU (-0.350295)");
	AddLineQueue("FLT_LOGEST4 EQU (0.248590)");
	AddLineQueue("FLT_LOGEST5 EQU (-0.145700)");
	AddLineQueue("FLT_LOGEST6 EQU (0.057148)");
	AddLineQueue("FLT_LOGEST7 EQU (-0.010578)");
	
	/*double mask*/
	AddLineQueue("REAL8_MAX_MSK EQU 0x7fefffffffffffff");
	AddLineQueue("REAL8_MIN_MSK EQU 0x0010000000000000");

	AddLineQueue("DOUBLE_MAX_MSK EQU REAL8_MAX_MSK");
	AddLineQueue("DOUBLE_MIN_MSK EQU REAL8_MIN_MSK");

	AddLineQueue("DBL_MAX_MSK EQU REAL8_MAX_MSK");
	AddLineQueue("DBL_MIN_MSK EQU REAL8_MIN_MSK");

	/*double*/
	AddLineQueue("REAL8_MAX EQU 1.7976931348623158e+308");
	AddLineQueue("REAL8_MIN EQU 2.2250738585072014e-308");

	AddLineQueue("DOUBLE_MAX EQU REAL8_MAX");
	AddLineQueue("DOUBLE_MIN EQU REAL8_MIN");

	AddLineQueue("DBL_MAX EQU REAL8_MAX");
	AddLineQueue("DBL_MIN EQU REAL8_MIN");

	/* EFLAGS %eax=00H, %ebx=00H */
	AddLineQueue("BIT_CPUID EQU 0x00200000");		/*1 << 21*/

	/* %eax=00H, %ecx %ebx */
	AddLineQueue("BIT_NTEL EQU 0x6c65746e");		/*'GenuineIntel'*/
	AddLineQueue("BIT_CAMD EQU 0x444d4163");		/*'AuthenticAMD'*/

	/* %eax=00H, %ebx */
	AddLineQueue("BIT_CENT EQU 0x746e6543");		/*'CentaurHauls'*/
	AddLineQueue("BIT_VIA EQU 0x20414956");			/*'VIA VIA VIA'*/
	AddLineQueue("BIT_CYRI EQU 0x69727943");		/*'CyrixInstead'*/
	AddLineQueue("BIT_NEXG EQU 0x4778654e");		/*'NexGenDriven'*/

	/* %eax=01H, %ecx */
	AddLineQueue("BIT_SSE3 EQU 0x00000001");			/*1 << 0*/
	AddLineQueue("BIT_PCLMULQDQ EQU 0x00000002");		/*1 << 1*/
	AddLineQueue("BIT_MONITOR EQU 0x00000008");			/*1 << 3*/
	AddLineQueue("BIT_SSSE3 EQU 0x00000200");			/*1 << 9*/
	AddLineQueue("BIT_FMA EQU 0x00001000");			/*1 << 12*/
	AddLineQueue("BIT_CMPXCHG16B EQU 0x00002000");		/*1 << 13*/
	AddLineQueue("BIT_SSE41 EQU 0x00080000");		/*1 << 19*/
	AddLineQueue("BIT_SSE42 EQU 0x00100000");		/*1 << 20*/
	AddLineQueue("BIT_MOVBE EQU 0x00400000");		/*1 << 22*/
	AddLineQueue("BIT_POPCNT EQU 0x00800000");		/*1 << 23*/
	AddLineQueue("BIT_AES EQU 0x02000000");			/*1 << 25*/
	AddLineQueue("BIT_XSAVE EQU 0x04000000");		/*1 << 26*/
	AddLineQueue("BIT_OSXSAVE EQU 0x08000000");		/*1 << 27*/
	AddLineQueue("BIT_AVX EQU 0x10000000");			/*1 << 28*/
	AddLineQueue("BIT_F16C EQU 0x20000000");		/*1 << 29*/
	AddLineQueue("BIT_RDRAND EQU 0x40000000");		/*1 << 30*/

	AddLineQueue("BIT_AVX_FMA EQU 0x18001000");		/*1 << 12 | 1 << 27 | 1 << 28*/
	AddLineQueue("BIT_OSXSAVE_AVX EQU 0x18000000");	/*1 << 27 | 1 << 28*/
	AddLineQueue("BIT_AVX_F16C EQU 0x38000000");	/*1 << 27 | 1 << 28 | 1 << 29*/

	AddLineQueue("BIT_SSE3_AES EQU 0x02000001");	/*1 << 0 | 1 << 25*/
	AddLineQueue("BIT_SSSE3_AES EQU 0x02000200");	/*1 << 9 | 1 << 25*/
	AddLineQueue("BIT_SSE41_AES EQU 0x02080000");	/*1 << 19 | 1 << 25*/
	AddLineQueue("BIT_SSE42_AES EQU 0x02100000");	/*1 << 20 | 1 << 25*/

	AddLineQueue("BIT_SSE3_PCLMULQDQ EQU 0x00000003");		/*1 << 1 | 1 << 1*/
	AddLineQueue("BIT_SSSE3_PCLMULQDQ EQU 0x00000202");		/*1 << 1 | 1 << 9*/
	AddLineQueue("BIT_SSE41_PCLMULQDQ EQU 0x00080002");	/*1 << 1 | 1 << 19*/
	AddLineQueue("BIT_SSE42_PCLMULQDQ EQU 0x00100002");	/*1 << 1 | 1 << 20*/

	/* %eax=01H, %edx */
	AddLineQueue("BIT_FPU EQU 0x00000001");				/*1 << 0*/
	AddLineQueue("BIT_TSC EQU 0x00000010");				/*1 << 4*/
	AddLineQueue("BIT_MSR EQU 0x00000020");				/*1 << 5*/
	AddLineQueue("BIT_CMPXCHG8B EQU 0x00000100");		/*1 << 8*/
	AddLineQueue("BIT_SEP EQU 0x00000800");				/*1 << 11*/
	AddLineQueue("BIT_CMOV EQU 0x00008000");			/*1 << 15*/
	AddLineQueue("BIT_CLFSH EQU 0x00080000");		/*1 << 19*/
	AddLineQueue("BIT_MMX EQU 0x00800000");			/*1 << 23*/
	AddLineQueue("BIT_FXSR EQU 0x01000000");		/*1 << 24*/
	AddLineQueue("BIT_SSE EQU 0x02000000");			/*1 << 25*/
	AddLineQueue("BIT_SSE2 EQU 0x04000000");		/*1 << 26*/

	/* %eax=07H, %ebx */
	AddLineQueue("BIT_FSGSBASE EQU 0x00000001");		/*1 << 0*/
	AddLineQueue("BIT_SGX EQU 0x00000004");				/*1 << 2*/
	AddLineQueue("BIT_BMI1 EQU 0x00000008");			/*1 << 3*/
	AddLineQueue("BIT_HLE EQU 0x00000010");				/*1 << 4*/
	AddLineQueue("BIT_AVX2 EQU 0x00000020");			/*1 << 5*/
	AddLineQueue("BIT_SMEP EQU 0x00000080");			/*1 << 7*/
	AddLineQueue("BIT_BMI2 EQU 0x00000100");			/*1 << 8*/
	AddLineQueue("BIT_ERMS EQU 0x00000200");			/*1 << 9*/
	AddLineQueue("BIT_INVPCID EQU 0x00000400");			/*1 << 10*/
	AddLineQueue("BIT_RTM EQU 0x00000800");				/*1 << 11*/
	AddLineQueue("BIT_MPX EQU 0x00004000");			/*1 << 14*/
	AddLineQueue("BIT_AVX512F EQU 0x00010000");		/*1 << 16*/
	AddLineQueue("BIT_AVX512DQ EQU 0x00020000");		/*1 << 17*/
	AddLineQueue("BIT_RDSEED EQU 0x00040000");		/*1 << 18*/
	AddLineQueue("BIT_ADX EQU 0x00080000");			/*1 << 19*/
	AddLineQueue("BIT_SMAP EQU 0x00100000");			/*1 << 20*/
	AddLineQueue("BIT_AVX512_IFMA EQU 0x00200000");	/*1 << 21*/
	AddLineQueue("BIT_CLFLUSHOPT EQU 0x00800000");	/*1 << 23*/
	AddLineQueue("BIT_CLWB EQU 0x01000000");		/*1 << 24*/
	AddLineQueue("BIT_AVX512PF EQU 0x04000000");	/*1 << 26*/
	AddLineQueue("BIT_AVX512ER EQU 0x08000000");	/*1 << 27*/
	AddLineQueue("BIT_AVX512CD EQU 0x10000000");	/*1 << 28*/
	AddLineQueue("BIT_SHA EQU 0x20000000");			/*1 << 29*/
	AddLineQueue("BIT_AVX512BW EQU 0x40000000");	/*1 << 30*/
	AddLineQueue("BIT_AVX512VL EQU 0x80000000");	/*1 << 31*/

	AddLineQueue("BIT_AVX512F_DQ EQU 0x00030000");		/*1 << 16 | 1 << 17*/
	AddLineQueue("BIT_AVX512F_DQ_VL EQU 0x80030000");	/*1 << 16 | 1 << 17 | 1 << 31*/
	AddLineQueue("BIT_AVX512F_IFMA EQU 0x00210000");		/*1 << 16 | 1 << 21*/
	AddLineQueue("BIT_AVX512F_IFMA_VL EQU 0x80210000");	/*1 << 16 | 1 << 21 | 1 << 31*/
	AddLineQueue("BIT_AVX512F_PF EQU 0x04010000");		/*1 << 16 | 1 << 26*/
	AddLineQueue("BIT_AVX512F_ER EQU 0x08010000");		/*1 << 16 | 1 << 27*/
	AddLineQueue("BIT_AVX512F_CD EQU 0x10010000");		/*1 << 16 | 1 << 28*/
	AddLineQueue("BIT_AVX512F_CD_VL EQU 0x90010000");	/*1 << 16 | 1 << 28 | 1 << 31*/
	AddLineQueue("BIT_AVX512F_BW EQU 0x40010000");		/*1 << 16 | 1 << 30*/
	AddLineQueue("BIT_AVX512F_BW_VL EQU 0xC0010000");	/*1 << 16 | 1 << 30 | 1 << 31*/
	AddLineQueue("BIT_AVX512F_VL EQU 0x80010000");		/*1 << 16 | 1 << 31*/

	/* %eax=07H, %ecx */
	AddLineQueue("BIT_PREFETCHWT1 EQU 0x00000001");		/*1 << 0*/
	AddLineQueue("BIT_AVX512_VBMI EQU 0x00000002");		/*1 << 1*/
	AddLineQueue("BIT_UMIP EQU 0x00000004");			/*1 << 2*/
	AddLineQueue("BIT_PKU EQU 0x00000008");				/*1 << 3*/
	AddLineQueue("BIT_OSPKE EQU 0x00000010");			/*1 << 4*/
	AddLineQueue("BIT_AVX512_VBMI2 EQU 0x00000040");	/*1 << 6*/
	AddLineQueue("BIT_GFNI EQU 0x00000100");			/*1 << 8*/
	AddLineQueue("BIT_VAES EQU 0x00000200");			/*1 << 9*/
	AddLineQueue("BIT_VPCLMULQDQ EQU 0x00000400");		/*1 << 10*/
	AddLineQueue("BIT_AVX512_VNNI EQU 0x00000800");		/*1 << 11*/
	AddLineQueue("BIT_AVX512_BITALG EQU 0x00001000");	/*1 << 12*/
	AddLineQueue("BIT_AVX512_VPOPCNTDQ EQU 0x00004000");	/*1 << 14*/
	AddLineQueue("BIT_RDPID EQU 0x00400000");			/*1 << 22*/

	/* %eax=07H, %edx */
	AddLineQueue("BIT_AVX512_4VNNIW EQU 0x00000004");	/*1 << 2*/
	AddLineQueue("BIT_AVX512_4FMAPS EQU 0x00000008");	/*1 << 3*/

	/* %eax=80000001H, %ecx */
	AddLineQueue("BIT_LAHF EQU 0x00000001");			/*1 << 0*/
	AddLineQueue("BIT_LZCNT EQU 0x00000020");			/*1 << 5*/
	AddLineQueue("BIT_ABM EQU 0x00000020");				/*1 << 5*/
	AddLineQueue("BIT_SSE4a EQU 0x00000040");			/*1 << 6*/
	AddLineQueue("BIT_PREFETCHW EQU 0x00000100");		/*1 << 8*/
	AddLineQueue("BIT_XOP EQU 0x00000800");				/*1 << 11*/
	AddLineQueue("BIT_LWP EQU 0x00008000");			/*1 << 15*/
	AddLineQueue("BIT_FMA4 EQU 0x00010000");			/*1 << 16*/
	AddLineQueue("BIT_TBM EQU 0x00200000");			/*1 << 21*/
	AddLineQueue("BIT_MWAITX EQU 0x20000000");		/*1 << 29*/

	/* %eax=80000001H, %edx */
	AddLineQueue("BIT_SYSCALL EQU 0x00000800");				/*1 << 11*/
	AddLineQueue("BIT_MMXEXT EQU 0x00400000");			/*1 << 22*/
	AddLineQueue("BIT_RDTSCP EQU 0x08000000");			/*1 << 27*/
	AddLineQueue("BIT_3DNOWEXT EQU 0x40000000");		/*1 << 30*/
	AddLineQueue("BIT_3DNOW EQU 0x80000000");			/*1 << 31*/
	
/*
 * Compare predicates for scalar and packed compare intrinsic functions
 */
	/*No AVX*/
	AddLineQueue("CMPP_EQ EQU 0x0");
	AddLineQueue("CMPP_LT EQU 0x1");
	AddLineQueue("CMPP_LE EQU 0x2");
	AddLineQueue("CMPP_UNORD EQU 0x3");
	AddLineQueue("CMPP_NEQ EQU 0x4");
	AddLineQueue("CMPP_NLT EQU 0x5");
	AddLineQueue("CMPP_NLE EQU 0x6");
	AddLineQueue("CMPP_ORD EQU 0x7");

	/*With AVX*/
	AddLineQueue("CMP_EQ_OQ EQU 0x00");		/* Equal (ordered, nonsignaling)               */
	AddLineQueue("CMP_LT_OS EQU 0x01");		/* Less-than (ordered, signaling)              */
	AddLineQueue("CMP_LE_OS EQU 0x02");		/* Less-than-or-equal (ordered, signaling)     */
	AddLineQueue("CMP_UNORD_Q EQU 0x03");	/* Unordered (nonsignaling)                    */
	AddLineQueue("CMP_NEQ_UQ EQU 0x04");	/* Not-equal (unordered, nonsignaling)         */
	AddLineQueue("CMP_NLT_US EQU 0x05");	/* Not-less-than (unordered, signaling)        */
	AddLineQueue("CMP_NLE_US EQU 0x06");	/* Not-less-than-or-equal (unordered, signaling) */
	AddLineQueue("CMP_ORD_Q EQU 0x07");		/* Ordered (nonsignaling)                      */
	AddLineQueue("CMP_EQ_UQ EQU 0x08");		/* Equal (unordered, non-signaling)            */
	AddLineQueue("CMP_NGE_US EQU 0x09");	/* Not-greater-than-or-equal (unordered, signaling) */
	AddLineQueue("CMP_NGT_US EQU 0x0A");	/* Not-greater-than (unordered, signaling)     */
	AddLineQueue("CMP_FALSE_OQ EQU 0x0B");	/* False (ordered, nonsignaling)               */
	AddLineQueue("CMP_NEQ_OQ EQU 0x0C");	/* Not-equal (ordered, non-signaling)          */
	AddLineQueue("CMP_GE_OS EQU 0x0D");		/* Greater-than-or-equal (ordered, signaling)  */
	AddLineQueue("CMP_GT_OS EQU 0x0E");		/* Greater-than (ordered, signaling)           */
	AddLineQueue("CMP_TRUE_UQ EQU 0x0F");	/* True (unordered, non-signaling)             */
	AddLineQueue("CMP_EQ_OS EQU 0x10");		/* Equal (ordered, signaling)                  */
	AddLineQueue("CMP_LT_OQ EQU 0x11");		/* Less-than (ordered, nonsignaling)           */
	AddLineQueue("CMP_LE_OQ EQU 0x12");		/* Less-than-or-equal (ordered, nonsignaling)  */
	AddLineQueue("CMP_UNORD_S EQU 0x13");	/* Unordered (signaling)                       */
	AddLineQueue("CMP_NEQ_US EQU 0x14");	/* Not-equal (unordered, signaling)            */
	AddLineQueue("CMP_NLT_UQ EQU 0x15");	/* Not-less-than (unordered, nonsignaling)     */
	AddLineQueue("CMP_NLE_UQ EQU 0x16");	/* Not-less-than-or-equal (unordered, nonsignaling) */
	AddLineQueue("CMP_ORD_S EQU 0x17");		/* Ordered (signaling)                         */
	AddLineQueue("CMP_EQ_US EQU 0x18");		/* Equal (unordered, signaling)                */
	AddLineQueue("CMP_NGE_UQ EQU 0x19");	/* Not-greater-than-or-equal (unordered, nonsignaling) */
	AddLineQueue("CMP_NGT_UQ EQU 0x1A");	/* Not-greater-than (unordered, nonsignaling)  */
	AddLineQueue("CMP_FALSE_OS EQU 0x1B");	/* False (ordered, signaling)                  */
	AddLineQueue("CMP_NEQ_OS EQU 0x1C");	/* Not-equal (ordered, signaling)              */
	AddLineQueue("CMP_GE_OQ EQU 0x1D");		/* Greater-than-or-equal (ordered, nonsignaling) */
	AddLineQueue("CMP_GT_OQ EQU 0x1E");		/* Greater-than (ordered, nonsignaling)        */
	AddLineQueue("CMP_TRUE_US EQU 0x1F");	/* True (unordered, signaling)                 */

	/*AddLineQueue(" EQU ");*/

	RunLineQueue();
}

#define X86MACRO_COUNT64 57

/* MACRO names  */
char *x86macName64[] = {
	"ALIGNSIZE_T", 
	"ALIGNPTR", 
	"ALIGNMM", 
	"ALIGNXMM", 
	"ALIGNYMM", 
	"ALIGNZMM",
	"ALIGNFIELD",
	"ALIGNSIZE_TFIELD",
	"ALIGNPTRFIELD",
	"ALIGNMMFIELD",
	"ALIGNXMMFIELD", 
	"ALIGNYMMFIELD", 
	"ALIGNZMMFIELD", 
	"ALIGNPROC", 
	"ALIGNSIZE_TPROC", 
	"ALIGNPTRPROC", 
	"ALIGNMMPROC", 
	"ALIGNXMMPROC", 
	"ALIGNYMMPROC", 
	"ALIGNZMMPROC", 
	"ALIGNFIELDPROC", 
	"ALIGNSIZE_TFIELDPROC",
	"ALIGNPTRFIELDPROC",
	"ALIGNMMFIELDPROC",
	"ALIGNXMMFIELDPROC",
	"ALIGNYMMFIELDPROC",
	"ALIGNZMMFIELDPROC",
	"FUNCSTART",
	"FUNCEND",
	"SHUFFLE4",
	"SHUFFLER4",
	"SHUFFLE2",
	"SHUFFLER2",
	"V64CI",
	"V64CI64",
	"V32CI",
	"V32CI32",
	"V16CI",
	"V16CI16",
	"V8CI",
	"V8CI8",
	"V4CI",
	"V4CI4",
	"V2CI",
	"V2CI2",
	"VV64CI",
	"VV64CI64",
	"VV32CI",
	"VV32CI32",
	"VV16CI",
	"VV16CI16",
	"VV8CI",
	"VV8CI8",
	"VV4CI",
	"VV4CI4",
	"VV2CI",
	"VV2CI2"
};

/* MACRO definitions */
char *x86macDef64[] = {
	"ALIGNSIZE_T MACRO",
	"ALIGNPTR MACRO",
	"ALIGNMM MACRO",
	"ALIGNXMM MACRO",
	"ALIGNYMM MACRO",
	"ALIGNZMM MACRO",
	"ALIGNFIELD MACRO AlignSize",
	"ALIGNSIZE_TFIELD MACRO",
	"ALIGNPTRFIELD MACRO",
	"ALIGNMMFIELD MACRO",
	"ALIGNXMMFIELD MACRO",
	"ALIGNYMMFIELD MACRO",
	"ALIGNZMMFIELD MACRO",
	"ALIGNPROC MACRO AlignSize",
	"ALIGNSIZE_TPROC MACRO",
	"ALIGNPTRPROC MACRO",
	"ALIGNMMPROC MACRO",
	"ALIGNXMMPROC MACRO",
	"ALIGNYMMPROC MACRO",
	"ALIGNZMMPROC MACRO",
	"ALIGNFIELDPROC MACRO AlignSize",
	"ALIGNSIZE_TFIELDPROC MACRO",
	"ALIGNPTRFIELDPROC MACRO",
	"ALIGNMMFIELDPROC MACRO",
	"ALIGNXMMFIELDPROC MACRO",
	"ALIGNYMMFIELDPROC MACRO",
	"ALIGNZMMFIELDPROC MACRO",
	"FUNCSTART MACRO functionName:REQ, callconvType:REQ, retType:REQ, usesStr:REQ, args:VARARG",
	"FUNCEND MACRO",
	"SHUFFLE4 MACRO V3, V2, V1, V0",
	"SHUFFLER4 MACRO V0, V1, V2, V3",
	"SHUFFLE2 MACRO V1, V0",
	"SHUFFLER2 MACRO V0, V1",
	"V64CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V64CI64 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ, V17:REQ, V18:REQ, V19:REQ, V20:REQ, V21:REQ, V22:REQ, V23:REQ, V24:REQ, V25:REQ, V26:REQ, V27:REQ, V28:REQ, V29:REQ, V30:REQ, V31:REQ, V32:REQ, V33:REQ, V34:REQ, V35:REQ, V36:REQ, V37:REQ, V38:REQ, V39:REQ, V40:REQ, V41:REQ, V42:REQ, V43:REQ, V44:REQ, V45:REQ, V46:REQ, V47:REQ, V48:REQ, V49:REQ, V50:REQ, V51:REQ, V52:REQ, V53:REQ, V54:REQ, V55:REQ, V56:REQ, V57:REQ, V58:REQ, V59:REQ, V60:REQ, V61:REQ, V62:REQ, V63:REQ, V64:REQ",
	"V32CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V32CI32 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ, V17:REQ, V18:REQ, V19:REQ, V20:REQ, V21:REQ, V22:REQ, V23:REQ, V24:REQ, V25:REQ, V26:REQ, V27:REQ, V28:REQ, V29:REQ, V30:REQ, V31:REQ, V32:REQ",
	"V16CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V16CI16 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ",
	"V8CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V8CI8 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ",
	"V4CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V4CI4 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ",
	"V2CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V2CI2 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ",
	"VV64CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"VV64CI64 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ, V17:REQ, V18:REQ, V19:REQ, V20:REQ, V21:REQ, V22:REQ, V23:REQ, V24:REQ, V25:REQ, V26:REQ, V27:REQ, V28:REQ, V29:REQ, V30:REQ, V31:REQ, V32:REQ, V33:REQ, V34:REQ, V35:REQ, V36:REQ, V37:REQ, V38:REQ, V39:REQ, V40:REQ, V41:REQ, V42:REQ, V43:REQ, V44:REQ, V45:REQ, V46:REQ, V47:REQ, V48:REQ, V49:REQ, V50:REQ, V51:REQ, V52:REQ, V53:REQ, V54:REQ, V55:REQ, V56:REQ, V57:REQ, V58:REQ, V59:REQ, V60:REQ, V61:REQ, V62:REQ, V63:REQ, V64:REQ",
	"VV32CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"VV32CI32 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ, V17:REQ, V18:REQ, V19:REQ, V20:REQ, V21:REQ, V22:REQ, V23:REQ, V24:REQ, V25:REQ, V26:REQ, V27:REQ, V28:REQ, V29:REQ, V30:REQ, V31:REQ, V32:REQ",
	"VV16CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"VV16CI16 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ",
	"VV8CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"VV8CI8 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ",
	"VV4CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"VV4CI4 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ",
	"VV2CI MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"VV2CI2 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ"
};

void x86CreateMacroLibCases(void)
{
	/* Create case alternative names for macrolib functions */
	if (ModuleInfo.case_sensitive && !ModuleInfo.convert_uppercase)
	{
		AddLineQueue("callconv TEXTEQU <CALLCONV>");
		AddLineQueue("callconvopt TEXTEQU <CALLCONVOPT>");

		AddLineQueue("alignsize_t EQU ALIGNSIZE_T");
		AddLineQueue("alignptr EQU ALIGNPTR");
		AddLineQueue("alignmm EQU ALIGNMM");
		AddLineQueue("alignxmm EQU ALIGNXMM");
		AddLineQueue("alignymm EQU ALIGNYMM");
		AddLineQueue("alignzmm EQU ALIGNZMM");
		AddLineQueue("alignfield EQU ALIGNFIELD");
		AddLineQueue("alignsize_tfield EQU ALIGNSIZE_TFIELD");
		AddLineQueue("alignptrfield EQU ALIGNPTRFIELD");
		AddLineQueue("alignmmfield EQU ALIGNMMFIELD");
		AddLineQueue("alignxmmfield EQU ALIGNXMMFIELD");
		AddLineQueue("alignymmfield EQU ALIGNYMMFIELD");
		AddLineQueue("alignzmmfield EQU ALIGNZMMFIELD");
		AddLineQueue("alignproc EQU ALIGNPROC");
		AddLineQueue("alignsize_tproc EQU ALIGNSIZE_TPROC");
		AddLineQueue("alignptrproc EQU ALIGNPTRPROC");
		AddLineQueue("alignmmproc EQU ALIGNMMPROC");
		AddLineQueue("alignxmmproc EQU ALIGNXMMPROC");
		AddLineQueue("alignymmproc EQU ALIGNYMMPROC");
		AddLineQueue("alignzmmproc EQU ALIGNZMMPROC");
		AddLineQueue("alignfieldproc EQU ALIGNFIELDPROC");
		AddLineQueue("alignsize_tfieldproc EQU ALIGNSIZE_TFIELDPROC");
		AddLineQueue("alignptrfieldproc EQU ALIGNPTRFIELDPROC");
		AddLineQueue("alignmmfieldproc EQU ALIGNMMFIELDPROC");
		AddLineQueue("alignxmmfieldproc EQU <ALIGNXMMFIELDPROC>");
		AddLineQueue("alignymmfieldproc EQU ALIGNYMMFIELDPROC");
		AddLineQueue("alignzmmfieldproc EQU ALIGNZMMFIELDPROC");
		AddLineQueue("funcstart EQU FUNCSTART");
		AddLineQueue("funcend EQU FUNCEND");

		AddLineQueue("shuffle4 EQU SHUFFLE4");
		AddLineQueue("shuffler4 EQU SHUFFLER4");
		AddLineQueue("shuffle2 EQU SHUFFLE2");
		AddLineQueue("shuffler2 EQU SHUFFLER2");

		AddLineQueue("v64ci EQU V64CI");
		AddLineQueue("v64ci64 EQU V64CI64");
		AddLineQueue("v32ci EQU V32CI");
		AddLineQueue("v32ci32 EQU V32CI32");
		AddLineQueue("v16ci EQU V16CI");
		AddLineQueue("v16ci16 EQU V16CI16");
		AddLineQueue("v8ci EQU V8CI");
		AddLineQueue("v8ci8 EQU V8CI8");
		AddLineQueue("v4ci EQU V4CI");
		AddLineQueue("v4ci4 EQU V4CI4");
		AddLineQueue("v2ci EQU V2CI");
		AddLineQueue("v2ci2 EQU V2CI2");
		AddLineQueue("vv64ci EQU VV64CI");
		AddLineQueue("vv64ci64 EQU VV64CI64");
		AddLineQueue("vv32ci EQU VV32CI");
		AddLineQueue("vv32ci32 EQU VV32CI32");
		AddLineQueue("vv16ci EQU VV16CI");
		AddLineQueue("vv16ci16 EQU VV16CI16");
		AddLineQueue("vv8ci EQU VV8CI");
		AddLineQueue("vv8ci8 EQU VV8CI8");
		AddLineQueue("vv4ci EQU VV4CI");
		AddLineQueue("vv4ci4 EQU VV4CI4");
		AddLineQueue("vv2ci EQU VV2CI");
		AddLineQueue("vv2ci2 EQU VV2CI2");

		AddLineQueue("int8 TEXTEQU INT8");
		AddLineQueue("uint8 TEXTEQU UINT8");
		AddLineQueue("sint8 TEXTEQU SINT8");
		AddLineQueue("int16 TEXTEQU INT16");
		AddLineQueue("uint16 TEXTEQU UINT16");
		AddLineQueue("sint16 TEXTEQU SINT16");
		/*AddLineQueue("int TEXTEQU INT"); cannot be used instruction type*/
		AddLineQueue("bool TEXTEQU BOOL");
		AddLineQueue("int32 TEXTEQU INT32");
		AddLineQueue("uint32 TEXTEQU UINT32");
		AddLineQueue("sint32 TEXTEQU SINT32");
		AddLineQueue("int64 TEXTEQU INT64");
		AddLineQueue("uint64 TEXTEQU UINT64");
		AddLineQueue("sint64 TEXTEQU SINT64");
		AddLineQueue("float TEXTEQU <FLOAT>");
		AddLineQueue("double TEXTEQU <DOUBLE>");

		AddLineQueue("byte_size EQU BYTE_SIZE");
		AddLineQueue("ubyte_size EQU UBYTE_SIZE");
		AddLineQueue("sbyte_size EQU SBYTE_SIZE");
		AddLineQueue("char_size EQU CHAR_SIZE");
		AddLineQueue("uchar_size EQU UCHAR_SIZE");
		AddLineQueue("schar_size EQU SCHAR_SIZE");
		AddLineQueue("int8_size EQU INT8_SIZE");
		AddLineQueue("uint8_size EQU UINT8_SIZE");
		AddLineQueue("sint8_size EQU SINT8_SIZE");
		AddLineQueue("word_size EQU WORD_SIZE");
		AddLineQueue("uword_size EQU UWORD_SIZE");
		AddLineQueue("sword_size EQU SWORD_SIZE");
		AddLineQueue("short_size EQU SHORT_SIZE");
		AddLineQueue("ushort_size EQU USHORT_SIZE");
		AddLineQueue("sshort_size EQU SSHORT_SIZE");
		AddLineQueue("int16_size EQU INT16_SIZE");
		AddLineQueue("uint16_size EQU UINT16_SIZE");
		AddLineQueue("sint16_size EQU SINT16_SIZE");
		AddLineQueue("dword_size EQU DWORD_SIZE");
		AddLineQueue("udword_size EQU UDWORD_SIZE");
		AddLineQueue("sdword_size EQU SDWORD_SIZE");
		AddLineQueue("long_size EQU LONG_SIZE");
		AddLineQueue("ulong_size EQU ULONG_SIZE");
		AddLineQueue("slong_size EQU SLONG_SIZE");
		AddLineQueue("bool_size EQU BOOL_SIZE");
		AddLineQueue("int_size EQU INT_SIZE");
		AddLineQueue("uint_size EQU UINT_SIZE");
		AddLineQueue("sint_size EQU SINT_SIZE");
		AddLineQueue("int32_size EQU INT32_SIZE");
		AddLineQueue("uint32_size EQU UINT32_SIZE");
		AddLineQueue("sint32_size EQU SINT32_SIZE");
		AddLineQueue("qword_size EQU QWORD_SIZE");
		AddLineQueue("uqword_size EQU UQWORD_SIZE");
		AddLineQueue("sqword_size EQU SQWORD_SIZE");
		AddLineQueue("longlong_size EQU LONGLONG_SIZE");
		AddLineQueue("ulonglong_size EQU ULONGLONG_SIZE");
		AddLineQueue("slonglong_size EQU SLONGLONG_SIZE");
		AddLineQueue("int64_size EQU INT64_SIZE");
		AddLineQueue("uint64_size EQU UINT64_SIZE");
		AddLineQueue("sint64_size EQU SINT64_SIZE");
		AddLineQueue("real4_size EQU REAL4_SIZE");
		AddLineQueue("float_size EQU FLOAT_SIZE");
		AddLineQueue("flt_size EQU FLT_SIZE");
		AddLineQueue("real8_size EQU REAL8_SIZE");
		AddLineQueue("double_size EQU DOUBLE_SIZE");
		AddLineQueue("dbl_size EQU DBL_SIZE");

		AddLineQueue("ubyte_max EQU UBYTE_MAX");
		AddLineQueue("uchar_max EQU UCHAR_MAX");
		AddLineQueue("uint8_max EQU UINT8_MAX");
		AddLineQueue("ubyte_min EQU UBYTE_MIN");
		AddLineQueue("uchar_min EQU UCHAR_MIN");
		AddLineQueue("uint8_min EQU UINT8_MIN");
		AddLineQueue("sbyte_max EQU SBYTE_MAX");
		AddLineQueue("schar_max EQU SCHAR_MAX");
		AddLineQueue("sint8_max EQU SINT8_MAX");
		AddLineQueue("sbyte_min EQU SBYTE_MIN");
		AddLineQueue("schar_min EQU SCHAR_MIN");
		AddLineQueue("sint8_min EQU SINT8_MIN");
		AddLineQueue("uword_max EQU UWORD_MAX");
		AddLineQueue("ushort_max EQU USHORT_MAX");
		AddLineQueue("uint16_max EQU UINT16_MAX");
		AddLineQueue("uword_min EQU UWORD_MIN");
		AddLineQueue("ushort_min EQU USHORT_MIN");
		AddLineQueue("uint16_min EQU UINT16_MIN");
		AddLineQueue("sword_max EQU SWORD_MAX");
		AddLineQueue("sshort_max EQU SSHORT_MAX");
		AddLineQueue("sint16_max EQU SINT16_MAX");
		AddLineQueue("sword_min EQU SWORD_MIN");
		AddLineQueue("sshort_min EQU SSHORT_MIN");
		AddLineQueue("sint16_min EQU SINT16_MIN");
		AddLineQueue("bool_max EQU BOOL_MAX");
		AddLineQueue("bool_min EQU BOOL_MIN");
		AddLineQueue("udword_max EQU UDWORD_MAX");
		AddLineQueue("ulong_max EQU ULONG_MAX");
		AddLineQueue("uint_max EQU UINT_MAX");
		AddLineQueue("uint32_max EQU UINT32_MAX");
		AddLineQueue("udword_min EQU UDWORD_MIN");
		AddLineQueue("ulong_min EQU ULONG_MIN");
		AddLineQueue("uint_min EQU UINT_MIN");
		AddLineQueue("uint32_min EQU UINT32_MIN");
		AddLineQueue("sdword_max EQU SDWORD_MAX");
		AddLineQueue("slong_max EQU SLONG_MAX");
		AddLineQueue("sint_max EQU SINT_MAX");
		AddLineQueue("sint32_max EQU SINT32_MAX");
		AddLineQueue("sdword_min EQU SDWORD_MIN");
		AddLineQueue("slong_min EQU SLONG_MIN");
		AddLineQueue("sint_min EQU SINT_MIN");
		AddLineQueue("sint32_min EQU SINT32_MIN");
		AddLineQueue("uqword_max EQU UQWORD_MAX");
		AddLineQueue("ulonglong_max EQU ULONGLONG_MAX");
		AddLineQueue("uint64_max EQU UINT64_MAX");
		AddLineQueue("uqword_min EQU UQWORD_MIN");
		AddLineQueue("ulonglong_min EQU ULONGLONG_MIN");
		AddLineQueue("uint64_min EQU UINT64_MIN");
		AddLineQueue("sqword_max EQU SQWORD_MAX");
		AddLineQueue("slonglong_max EQU SLONGLONG_MAX");
		AddLineQueue("sint64_max EQU SINT64_MAX");
		AddLineQueue("sqword_min EQU SQWORD_MIN");
		AddLineQueue("slonglong_min EQU SLONGLONG_MIN");
		AddLineQueue("sint64_min EQU SINT64_MIN");

		AddLineQueue("size_t TEXTEQU <SIZE_T>");
		AddLineQueue("isize_t TEXTEQU <ISIZE_T>");
		AddLineQueue("psize_t TEXTEQU <PSIZE_T>");
		AddLineQueue("size_tp TEXTEQU <SIZE_TP>");
		AddLineQueue("size_t_size EQU SIZE_T_SIZE");
		AddLineQueue("ptr_size EQU PTR_SIZE");
		AddLineQueue("reg_size EQU REG_SIZE");
		AddLineQueue("sintsize_t_max EQU SINTSIZE_T_MAX");
		AddLineQueue("sintsize_t_min EQU SINTSIZE_T_MIN");
		AddLineQueue("uintsize_t_max EQU UINTSIZE_T_MAX");
		AddLineQueue("uintsize_t_min EQU UINTSIZE_T_MIN");
		AddLineQueue("sintptr_max EQU SINTPTR_MAX");
		AddLineQueue("sintptr_min EQU SINTPTR_MIN");
		AddLineQueue("uintptr_max EQU UINTPTR_MAX");
		AddLineQueue("uintptr_min EQU UINTPTR_MIN");

		AddLineQueue("mm_size EQU MM_SIZE");
		AddLineQueue("m64_size EQU M64_SIZE");
		AddLineQueue("xmm_size EQU XMM_SIZE");
		AddLineQueue("m128_size EQU M128_SIZE");
		AddLineQueue("ymm_size EQU YMM_SIZE");
		AddLineQueue("m256_size EQU M256_SIZE");
		AddLineQueue("zmm_size EQU ZMM_SIZE");
		AddLineQueue("m512_size EQU M512_SIZE");

		AddLineQueue("false EQU FALSE");
		AddLineQueue("true EQU TRUE");

		AddLineQueue("m8_false EQU M8_FALSE");
		AddLineQueue("m8_true EQU M8_TRUE");
		AddLineQueue("i8_false EQU I8_FALSE");
		AddLineQueue("i8_true EQU I8_TRUE");

		AddLineQueue("m16_false EQU M16_FALSE");
		AddLineQueue("m16_true EQU M16_TRUE");
		AddLineQueue("i16_false EQU I16_FALSE");
		AddLineQueue("i16_true EQU I16_TRUE");

		AddLineQueue("m32_false EQU M32_FALSE");
		AddLineQueue("m32_true EQU M32_TRUE");
		AddLineQueue("i32_false EQU I32_FALSE");
		AddLineQueue("i32_true EQU I32_TRUE");

		AddLineQueue("m64_false EQU M64_FALSE");
		AddLineQueue("m64_true EQU M64_TRUE");
		AddLineQueue("i64_false EQU I64_FALSE");
		AddLineQueue("i64_true EQU I64_TRUE");

		/*float mask*/
		AddLineQueue("flt_1lshl12_msk EQU FLT_1LSHL12_MSK");
		AddLineQueue("flt_1lshl23_msk EQU FLT_1LSHL23_MSK");
		AddLineQueue("flt_1lshl24_msk EQU FLT_1LSHL24_MSK");
		AddLineQueue("flt_1lshl31_msk EQU FLT_1LSHL31_MSK");

		AddLineQueue("flt_neg1lshl12_msk EQU FLT_NEG1LSHL12_MSK");
		AddLineQueue("flt_neg1lshl23_msk EQU FLT_NEG1LSHL23_MSK");
		AddLineQueue("flt_neg1lshl24_msk EQU FLT_NEG1LSHL24_MSK");

		AddLineQueue("flt_false_msk EQU FLT_FALSE_MSK");
		AddLineQueue("flt_true_msk EQU FLT_TRUE_MSK");

		AddLineQueue("flt_magic_msk EQU FLT_MAGIC_MSK");
		AddLineQueue("flt_sign_msk EQU FLT_SIGN_MSK");
		AddLineQueue("flt_invsign_msk EQU FLT_INVSIGN_MSK");

		AddLineQueue("flt_inf_msk EQU FLT_INF_MSK");
		AddLineQueue("flt_fin_msk EQU FLT_FIN_MSK");
		AddLineQueue("flt_invinf_msk EQU FLT_INVINF_MSK");
		AddLineQueue("flt_neginf_msk EQU FLT_NEGINF_MSK");
		AddLineQueue("flt_nan_msk EQU FLT_NAN_MSK");
		AddLineQueue("flt_qnan_msk EQU FLT_QNAN_MSK");
		AddLineQueue("flt_negqnan_msk EQU FLT_NEGQNAN_MSK");
		AddLineQueue("flt_nantest_msk EQU FLT_NANTEST_MSK");
		AddLineQueue("flt_abs_msk EQU FLT_ABS_MSK");
		AddLineQueue("flt_min_msk EQU FLT_MIN_MSK");
		AddLineQueue("flt_max_msk EQU FLT_MAX_MSK");
		AddLineQueue("flt_nofraction_msk EQU FLT_NOFRACTION_MSK");
		AddLineQueue("flt_mindenorm_msk EQU FLT_MINDENORM_MSK");
		AddLineQueue("flt_denormlimit_msk EQU FLT_DENORMLIMIT_MSK");
		AddLineQueue("flt_minnormal_msk EQU FLT_MINNORMAL_MSK");
		AddLineQueue("flt_maxnormal_msk EQU FLT_MAXNORMAL_MSK");

		AddLineQueue("flt_decdig_msk EQU FLT_DECDIG_MSK");
		AddLineQueue("flt_dig_msk EQU FLT_DIG_MSK");
		AddLineQueue("flt_negdecdig_msk EQU FLT_NEGDECDIG_MSK");
		AddLineQueue("flt_negdig_msk EQU FLT_NEGDIG_MSK");
		AddLineQueue("flt_eps_msk EQU FLT_EPS_MSK");
		AddLineQueue("flt_epsilon_msk EQU FLT_EPSILON_MSK");
		AddLineQueue("flt_normeps_msk EQU FLT_NORMEPS_MSK");
		AddLineQueue("flt_guard_msk EQU FLT_GUARD_MSK");
		AddLineQueue("flt_mantpow2_msk EQU FLT_MANTPOW2_MSK");
		AddLineQueue("flt_maxmantpow2_msk EQU FLT_MAXMANTPOW2_MSK");
		AddLineQueue("flt_mantdig_msk EQU FLT_MANTDIG_MSK");
		AddLineQueue("flt_mant_msk EQU FLT_MANT_MSK");
		AddLineQueue("flt_negmantdig_msk EQU FLT_NEGMANTDIG_MSK");
		AddLineQueue("flt_negmant_msk EQU FLT_NEGMANT_MSK");
		AddLineQueue("flt_maxexp_msk EQU FLT_MAXEXP_MSK");
		AddLineQueue("flt_expsign_msk EQU FLT_EXPSIGN_MSK");
		AddLineQueue("flt_exp_msk EQU FLT_EXP_MSK");
		AddLineQueue("flt_negmaxexp_msk EQU FLT_NEGMAXEXP_MSK");
		AddLineQueue("flt_negexpsign_msk EQU FLT_NEGEXPSIGN_MSK");
		AddLineQueue("flt_negexp_msk EQU FLT_NEGEXP_MSK");
		AddLineQueue("flt_subnormalexp_msk EQU FLT_SUBNORMALEXP_MSK");
		AddLineQueue("flt_minexp_msk EQU FLT_MINEXP_MSK");
		AddLineQueue("flt_maxdecexp_msk EQU FLT_MAXDECEXP_MSK");
		AddLineQueue("flt_negmaxdecexp_msk EQU FLT_NEGMAXDECEXP_MSK");
		AddLineQueue("flt_mindecexp_msk EQU FLT_MINDECEXP_MSK");
		AddLineQueue("flt_expfield_msk EQU FLT_EXPFIELD_MSK");
		AddLineQueue("flt_mantfield_msk EQU FLT_MANTFIELD_MSK");
		AddLineQueue("flt_norm_msk EQU FLT_NORM_MSK");
		AddLineQueue("flt_radix_msk EQU FLT_RADIX_MSK");
		AddLineQueue("flt_rounds_msk EQU FLT_ROUNDS_MSK");
		AddLineQueue("flt_subdec_msk EQU FLT_SUBDEC_MSK");
		AddLineQueue("flt_sqrtmax_msk EQU FLT_SQRTMAX_MSK");
		AddLineQueue("flt_smalnormal_msk EQU FLT_SMALNORMAL_MSK");

		AddLineQueue("flt_halfminuseps_msk EQU FLT_HALFMINUSEPS_MSK");
		AddLineQueue("flt_trueint_msk EQU FLT_TRUEINT_MSK");

		AddLineQueue("flt_byte_msk EQU FLT_BYTE_MSK");
		AddLineQueue("flt_4low_msk EQU FLT_4LOW_MSK");
		AddLineQueue("flt_4high_msk EQU FLT_4HIGH_MSK");
		AddLineQueue("flt_flip4_msk EQU FLT_FLIP4_MSK");
		AddLineQueue("flt_8low_msk EQU FLT_8LOW_MSK");
		AddLineQueue("flt_8high_msk EQU FLT_8HIGH_MSK");
		AddLineQueue("flt_flip8_msk EQU FLT_FLIP8_MSK");
		AddLineQueue("flt_16low_msk EQU FLT_16LOW_MSK");
		AddLineQueue("flt_16high_msk EQU FLT_16HIGH_MSK");
		AddLineQueue("flt_flip16_msk EQU FLT_FLIP16_MSK");
		AddLineQueue("flt_24low_msk EQU FLT_24LOW_MSK");
		AddLineQueue("flt_24high_msk EQU FLT_24HIGH_MSK");
		AddLineQueue("flt_flip24_msk EQU FLT_FLIP24_MSK");
		AddLineQueue("flt_28low_msk EQU FLT_28LOW_MSK");
		AddLineQueue("flt_28high_msk EQU FLT_28HIGH_MSK");
		AddLineQueue("flt_flip28_msk EQU FLT_FLIP28_MSK");
		AddLineQueue("flt_low_msk EQU FLT_LOW_MSK");
		AddLineQueue("flt_high_msk EQU FLT_HIGH_MSK");
		AddLineQueue("flt_flip_msk EQU FLT_FLIP_MSK");

		AddLineQueue("flt_0_msk EQU FLT_0_MSK");
		AddLineQueue("flt_0d5_msk EQU FLT_0D5_MSK");
		AddLineQueue("flt_1_msk EQU FLT_1_MSK");
		AddLineQueue("flt_1d5_msk EQU FLT_1D5_MSK");
		AddLineQueue("flt_2_msk EQU FLT_2_MSK");
		AddLineQueue("flt_2d5_msk EQU FLT_2D5_MSK");
		AddLineQueue("flt_3_msk EQU FLT_3_MSK");
		AddLineQueue("flt_4_msk EQU FLT_4_MSK");
		AddLineQueue("flt_5_msk EQU FLT_5_MSK");
		AddLineQueue("flt_6_msk EQU FLT_6_MSK");
		AddLineQueue("flt_7_msk EQU FLT_7_MSK");
		AddLineQueue("flt_8_msk EQU FLT_8_MSK");
		AddLineQueue("flt_9_msk EQU FLT_9_MSK");
		AddLineQueue("flt_10_msk EQU FLT_10_MSK");
		AddLineQueue("flt_20_msk EQU FLT_20_MSK");
		AddLineQueue("flt_23_msk EQU FLT_23_MSK");
		AddLineQueue("flt_23d5_msk EQU FLT_23D5_MSK");
		AddLineQueue("flt_24_msk EQU FLT_24_MSK");
		AddLineQueue("flt_24d5_msk EQU FLT_24D5_MSK");
		AddLineQueue("flt_25_msk EQU FLT_25_MSK");

		AddLineQueue("flt_128_msk EQU FLT_128_MSK");

		AddLineQueue("flt_253_msk EQU FLT_253_MSK");

		AddLineQueue("flt_neg0_msk EQU FLT_NEG0_MSK");
		AddLineQueue("flt_neg1_msk EQU FLT_NEG1_MSK");

		AddLineQueue("flt_neg150_msk EQU FLT_NEG150_MSK");

		AddLineQueue("flt_a8_msk EQU FLT_A8_MSK");
		AddLineQueue("flt_r8_msk EQU FLT_R8_MSK");
		AddLineQueue("flt_g8_msk EQU FLT_G8_MSK");
		AddLineQueue("flt_b8_msk EQU FLT_B8_MSK");

		AddLineQueue("flt_flipa8_msk EQU FLT_FLIPA8_MSK");
		AddLineQueue("flt_flipr8_msk EQU FLT_FLIPR8_MSK");
		AddLineQueue("flt_flipg8_msk EQU FLT_FLIPG8_MSK");
		AddLineQueue("flt_flipb8_msk EQU FLT_FLIPB8_MSK");

		AddLineQueue("flt_a2_msk EQU FLT_A2_MSK");
		AddLineQueue("flt_b10_msk EQU FLT_B10_MSK");
		AddLineQueue("flt_g10_msk EQU FLT_G10_MSK");
		AddLineQueue("flt_r10_msk EQU FLT_R10_MSK");

		AddLineQueue("flt_flipa2_msk EQU FLT_FLIPA2_MSK");
		AddLineQueue("flt_flipb10_msk EQU FLT_FLIPB10_MSK");
		AddLineQueue("flt_flipg10_msk EQU FLT_FLIPG10_MSK");
		AddLineQueue("flt_flipr10_msk EQU FLT_FLIPR10_MSK");

		AddLineQueue("flt_bin128_msk EQU FLT_BIN128_MSK");
		AddLineQueue("flt_binneg150_msk EQU FLT_BINNEG150_MSK");

		AddLineQueue("flt_maxrand_msk EQU FLT_MAXRAND_MSK");

		AddLineQueue("flt_maxi8_msk EQU FLT_MAXI8_MSK");
		AddLineQueue("flt_mini8_msk EQU FLT_MINI8_MSK");
		AddLineQueue("flt_maxu8_msk EQU FLT_MAXU8_MSK");

		AddLineQueue("flt_maxi16_msk EQU FLT_MAXI16_MSK");
		AddLineQueue("flt_mini16_msk EQU FLT_MINI16_MSK");
		AddLineQueue("flt_maxu16_msk EQU FLT_MAXU16_MSK");

		AddLineQueue("flt_maxi32_msk EQU FLT_MAXI32_MSK");
		AddLineQueue("flt_mini32_msk EQU FLT_MINI32_MSK");
		AddLineQueue("flt_maxu32_msk EQU FLT_MAXU32_MSK");

		AddLineQueue("flt_maxi8xu8_msk EQU FLT_MAXI8XU8_MSK");
		AddLineQueue("flt_mini8xu8_msk EQU FLT_MINI8XU8_MSK");
		AddLineQueue("flt_maxi8xu16_msk EQU FLT_MAXI8XU16_MSK");
		AddLineQueue("flt_mini8xu16_msk EQU FLT_MINI8XU16_MSK");

		AddLineQueue("flt_maxi16xu16_msk EQU FLT_MAXI16XU16_MSK");
		AddLineQueue("flt_mini16xu16_msk EQU FLT_MINI16XU16_MSK");

		AddLineQueue("flt_fixunsigned_msk EQU FLT_FIXUNSIGNED_MSK");
		AddLineQueue("flt_fixmaxi32_msk EQU FLT_FIXMAXI32_MSK");
		AddLineQueue("flt_fixmaxu32_msk EQU FLT_FIXMAXU32_MSK");

		/*float int*/
		AddLineQueue("flt_1lshl12_int EQU FLT_1LSHL12_INT");
		AddLineQueue("flt_1lshl23_int EQU FLT_1LSHL23_INT");
		AddLineQueue("flt_1lshl24_int EQU FLT_1LSHL24_INT");
		AddLineQueue("flt_1lshl31_int EQU FLT_1LSHL31_INT");

		AddLineQueue("flt_neg1lshl12_int EQU FLT_NEG1LSHL12_INT");
		AddLineQueue("flt_neg1lshl23_int EQU FLT_NEG1LSHL23_INT");
		AddLineQueue("flt_neg1lshl24_int EQU FLT_NEG1LSHL24_INT");
		
		AddLineQueue("flt_false_int EQU FLT_FALSE_INT");
		AddLineQueue("flt_true_int EQU FLT_TRUE_INT");

		AddLineQueue("flt_magic_int EQU FLT_MAGIC_INT");
		AddLineQueue("flt_sign_int EQU FLT_SIGN_INT");
		AddLineQueue("flt_invsign_int EQU FLT_INVSIGN_INT");

		AddLineQueue("flt_inf_int EQU FLT_INF_INT");
		AddLineQueue("flt_fin_int EQU FLT_FIN_INT");
		AddLineQueue("flt_invinf_int EQU FLT_INVINF_INT");
		AddLineQueue("flt_neginf_int EQU FLT_NEGINF_INT");
		AddLineQueue("flt_nan_int EQU FLT_NAN_INT");
		AddLineQueue("flt_qnan_int EQU FLT_QNAN_INT");
		AddLineQueue("flt_negqnan_int EQU FLT_NEGQNAN_INT");
		AddLineQueue("flt_nantest_int EQU FLT_NANTEST_INT");
		AddLineQueue("flt_abs_int EQU FLT_ABS_INT");
		AddLineQueue("flt_min_int EQU FLT_MIN_INT");
		AddLineQueue("flt_max_int EQU FLT_MAX_INT");
		AddLineQueue("flt_nofraction_int EQU FLT_NOFRACTION_INT");
		AddLineQueue("flt_mindenorm_int EQU FLT_MINDENORM_INT");
		AddLineQueue("flt_denormlimit_int EQU FLT_DENORMLIMIT_INT");
		AddLineQueue("flt_minnormal_int EQU FLT_MINNORMAL_INT");
		AddLineQueue("flt_maxnormal_int EQU FLT_MAXNORMAL_INT");

		AddLineQueue("flt_decdig_int EQU FLT_DECDIG_INT");
		AddLineQueue("flt_dig_int EQU FLT_DIG_INT");
		AddLineQueue("flt_negdecdig_int EQU FLT_NEGDECDIG_INT");
		AddLineQueue("flt_negdig_int EQU FLT_NEGDIG_INT");
		AddLineQueue("flt_eps_int EQU FLT_EPS_INT");
		AddLineQueue("flt_epsilon_int EQU FLT_EPSILON_INT");
		AddLineQueue("flt_normeps_int EQU FLT_NORMEPS_INT");
		AddLineQueue("flt_guard_int EQU FLT_GUARD_INT");
		AddLineQueue("flt_mantpow2_int EQU FLT_MANTPOW2_INT");
		AddLineQueue("flt_maxmantpow2_int EQU FLT_MAXMANTPOW2_INT");
		AddLineQueue("flt_mantdig_int EQU FLT_MANTDIG_INT");
		AddLineQueue("flt_mant_int EQU FLT_MANT_INT");
		AddLineQueue("flt_negmantdig_int EQU FLT_NEGMANTDIG_INT");
		AddLineQueue("flt_negmant_int EQU FLT_NEGMANT_INT");
		AddLineQueue("flt_maxexp_int EQU FLT_MAXEXP_INT");
		AddLineQueue("flt_expsign_int EQU FLT_EXPSIGN_INT");
		AddLineQueue("flt_exp_int EQU FLT_EXP_INT");
		AddLineQueue("flt_negmaxexp_int EQU FLT_NEGMAXEXP_INT");
		AddLineQueue("flt_negexpsign_int EQU FLT_NEGEXPSIGN_INT");
		AddLineQueue("flt_negexp_int EQU FLT_NEGEXP_INT");
		AddLineQueue("flt_subnormalexp_int EQU FLT_SUBNORMALEXP_INT");
		AddLineQueue("flt_minexp_int EQU FLT_MINEXP_INT");
		AddLineQueue("flt_maxdecexp_int EQU FLT_MAXDECEXP_INT");
		AddLineQueue("flt_negmaxdecexp_int EQU FLT_NEGMAXDECEXP_INT");
		AddLineQueue("flt_mindecexp_int EQU FLT_MINDECEXP_INT");
		AddLineQueue("flt_expfield_int EQU FLT_EXPFIELD_INT");
		AddLineQueue("flt_mantfield_int EQU FLT_MANTFIELD_INT");
		AddLineQueue("flt_norm_int EQU FLT_NORM_INT");
		AddLineQueue("flt_radix_int EQU FLT_RADIX_INT");
		AddLineQueue("flt_rounds_int EQU FLT_ROUNDS_INT");
		AddLineQueue("flt_subdec_int EQU FLT_SUBDEC_INT");
		AddLineQueue("flt_sqrtmax_int EQU FLT_SQRTMAX_INT");
		AddLineQueue("flt_smalnormal_int EQU FLT_SMALNORMAL_INT");

		AddLineQueue("flt_halfminuseps_int EQU FLT_HALFMINUSEPS_INT");
		AddLineQueue("flt_trueint_int EQU FLT_TRUEINT_INT");

		AddLineQueue("flt_byte_int EQU FLT_BYTE_INT");
		AddLineQueue("flt_4low_int EQU FLT_4LOW_INT");
		AddLineQueue("flt_4high_int EQU FLT_4HIGH_INT");
		AddLineQueue("flt_flip4_int EQU FLT_FLIP4_INT");
		AddLineQueue("flt_8low_int EQU FLT_8LOW_INT");
		AddLineQueue("flt_8high_int EQU FLT_8HIGH_INT");
		AddLineQueue("flt_flip8_int EQU FLT_FLIP8_INT");
		AddLineQueue("flt_16low_int EQU FLT_16LOW_INT");
		AddLineQueue("flt_16high_int EQU FLT_16HIGH_INT");
		AddLineQueue("flt_flip16_int EQU FLT_FLIP16_INT");
		AddLineQueue("flt_24low_int EQU FLT_24LOW_INT");
		AddLineQueue("flt_24high_int EQU FLT_24HIGH_INT");
		AddLineQueue("flt_flip24_int EQU FLT_FLIP24_INT");
		AddLineQueue("flt_28low_int EQU FLT_28LOW_INT");
		AddLineQueue("flt_28high_int EQU FLT_28HIGH_INT");
		AddLineQueue("flt_flip28_int EQU FLT_FLIP28_INT");
		AddLineQueue("flt_low_int EQU FLT_LOW_INT");
		AddLineQueue("flt_high_int EQU FLT_HIGH_INT");
		AddLineQueue("flt_flip_int EQU FLT_FLIP_INT");

		AddLineQueue("flt_0_int EQU FLT_0_INT");
		AddLineQueue("flt_0d5_int EQU FLT_0D5_INT");
		AddLineQueue("flt_1_int EQU FLT_1_INT");
		AddLineQueue("flt_1d5_int EQU FLT_1D5_INT");
		AddLineQueue("flt_2_int EQU FLT_2_INT");
		AddLineQueue("flt_2d5_int EQU FLT_2D5_INT");
		AddLineQueue("flt_3_int EQU FLT_3_INT");
		AddLineQueue("flt_4_int EQU FLT_4_INT");
		AddLineQueue("flt_5_int EQU FLT_5_INT");
		AddLineQueue("flt_6_int EQU FLT_6_INT");
		AddLineQueue("flt_7_int EQU FLT_7_INT");
		AddLineQueue("flt_8_int EQU FLT_8_INT");
		AddLineQueue("flt_9_int EQU FLT_9_INT");
		AddLineQueue("flt_10_int EQU FLT_10_INT");
		AddLineQueue("flt_20_int EQU FLT_20_INT");
		AddLineQueue("flt_23_int EQU FLT_23_INT");
		AddLineQueue("flt_23d5_int EQU FLT_23D5_INT");
		AddLineQueue("flt_24_int EQU FLT_24_INT");
		AddLineQueue("flt_24d5_int EQU FLT_24D5_INT");
		AddLineQueue("flt_25_int EQU FLT_25_INT");

		AddLineQueue("flt_128_int EQU FLT_128_INT");

		AddLineQueue("flt_253_int EQU FLT_253_INT");

		AddLineQueue("flt_neg0_int EQU FLT_NEG0_INT");
		AddLineQueue("flt_neg1_int EQU FLT_NEG1_INT");

		AddLineQueue("flt_neg150_int EQU FLT_NEG150_INT");

		AddLineQueue("flt_a8_int EQU FLT_A8_INT");
		AddLineQueue("flt_r8_int EQU FLT_R8_INT");
		AddLineQueue("flt_g8_int EQU FLT_G8_INT");
		AddLineQueue("flt_b8_int EQU FLT_B8_INT");

		AddLineQueue("flt_flipa8_int EQU FLT_FLIPA8_INT");
		AddLineQueue("flt_flipr8_int EQU FLT_FLIPR8_INT");
		AddLineQueue("flt_flipg8_int EQU FLT_FLIPG8_INT");
		AddLineQueue("flt_flipb8_int EQU FLT_FLIPB8_INT");

		AddLineQueue("flt_a2_int EQU FLT_A2_INT");
		AddLineQueue("flt_b10_int EQU FLT_B10_INT");
		AddLineQueue("flt_g10_int EQU FLT_G10_INT");
		AddLineQueue("flt_r10_int EQU FLT_R10_INT");

		AddLineQueue("flt_flipa2_int EQU FLT_FLIPA2_INT");
		AddLineQueue("flt_flipb10_int EQU FLT_FLIPB10_INT");
		AddLineQueue("flt_flipg10_int EQU FLT_FLIPG10_INT");
		AddLineQueue("flt_flipr10_int EQU FLT_FLIPR10_INT");

		AddLineQueue("flt_bin128_int EQU FLT_BIN128_INT");
		AddLineQueue("flt_binneg150_int EQU FLT_BINNEG150_INT");

		AddLineQueue("flt_maxrand_int EQU FLT_MAXRAND_INT");

		AddLineQueue("flt_maxi8_int EQU FLT_MAXI8_INT");
		AddLineQueue("flt_mini8_int EQU FLT_MINI8_INT");
		AddLineQueue("flt_maxu8_int EQU FLT_MAXU8_INT");

		AddLineQueue("flt_maxi16_int EQU FLT_MAXI16_INT");
		AddLineQueue("flt_mini16_int EQU FLT_MINI16_INT");
		AddLineQueue("flt_maxu16_int EQU FLT_MAXU16_INT");

		AddLineQueue("flt_maxi32_int EQU FLT_MAXI32_INT");
		AddLineQueue("flt_mini32_int EQU FLT_MINI32_INT");
		AddLineQueue("flt_maxu32_int EQU FLT_MAXU32_INT");

		AddLineQueue("flt_maxi8xu8_int EQU FLT_MAXI8XU8_INT");
		AddLineQueue("flt_mini8xu8_int EQU FLT_MINI8XU8_INT");
		AddLineQueue("flt_maxi8xu16_int EQU FLT_MAXI8XU16_INT");
		AddLineQueue("flt_mini8xu16_int EQU FLT_MINI8XU16_INT");

		AddLineQueue("flt_maxi16xu16_int EQU FLT_MAXI16XU16_INT");
		AddLineQueue("flt_mini16xu16_int EQU FLT_MINI16XU16_INT");

		AddLineQueue("flt_fixunsigned_int EQU FLT_FIXUNSIGNED_INT");
		AddLineQueue("flt_fixmaxi32_int EQU FLT_FIXMAXI32_INT");
		AddLineQueue("flt_fixmaxu32_int EQU FLT_FIXMAXU32_INT");

		/*float*/
		AddLineQueue("flt_1lshl12 EQU FLT_1LSHL12");
		AddLineQueue("flt_1lshl23 EQU FLT_1LSHL23");
		AddLineQueue("flt_1lshl24 EQU FLT_1LSHL24");
		AddLineQueue("flt_1lshl31 EQU FLT_1LSHL31");

		AddLineQueue("flt_neg1lshl12 EQU FLT_NEG1LSHL12");
		AddLineQueue("flt_neg1lshl23 EQU FLT_NEG1LSHL23");
		AddLineQueue("flt_neg1lshl24 EQU FLT_NEG1LSHL24");

		AddLineQueue("flt_false EQU FLT_FALSE");
		AddLineQueue("flt_true EQU FLT_TRUE");

		AddLineQueue("flt_magic EQU FLT_MAGIC");
		AddLineQueue("flt_sign EQU FLT_SIGN");
		AddLineQueue("flt_invsign EQU FLT_INVSIGN");

		AddLineQueue("flt_inf EQU FLT_INF");
		AddLineQueue("flt_fin EQU FLT_FIN");
		AddLineQueue("flt_invinf EQU FLT_INVINF");
		AddLineQueue("flt_neginf EQU FLT_NEGINF");
		AddLineQueue("flt_nan EQU FLT_NAN");
		AddLineQueue("flt_qnan EQU FLT_QNAN");
		AddLineQueue("flt_negqnan EQU FLT_NEGQNAN");
		AddLineQueue("flt_nantest EQU FLT_NANTEST");
		AddLineQueue("flt_abs EQU FLT_ABS");
		AddLineQueue("flt_min EQU FLT_MIN");
		AddLineQueue("flt_max EQU FLT_MAX");
		AddLineQueue("flt_nofraction EQU FLT_NOFRACTION");
		AddLineQueue("flt_mindenorm EQU FLT_MINDENORM");
		AddLineQueue("flt_denormlimit EQU FLT_DENORMLIMIT");
		AddLineQueue("flt_minnormal EQU FLT_MINNORMAL");
		AddLineQueue("flt_maxnormal EQU FLT_MAXNORMAL");

		AddLineQueue("flt_decdig EQU FLT_DECDIG");
		AddLineQueue("flt_dig EQU FLT_DIG");
		AddLineQueue("flt_negdecdig EQU FLT_NEGDECDIG");
		AddLineQueue("flt_negdig EQU FLT_NEGDIG");
		AddLineQueue("flt_eps EQU FLT_EPS");
		AddLineQueue("flt_epsilon EQU FLT_EPSILON");
		AddLineQueue("flt_normeps EQU FLT_NORMEPS");
		AddLineQueue("flt_guard EQU FLT_GUARD");
		AddLineQueue("flt_mantpow2 EQU FLT_MANTPOW2");
		AddLineQueue("flt_maxmantpow2 EQU FLT_MAXMANTPOW2");
		AddLineQueue("flt_mantdig EQU FLT_MANTDIG");
		AddLineQueue("flt_mant EQU FLT_MANT");
		AddLineQueue("flt_negmantdig EQU FLT_NEGMANTDIG");
		AddLineQueue("flt_negmant EQU FLT_NEGMANT");
		AddLineQueue("flt_maxexp EQU FLT_MAXEXP");
		AddLineQueue("flt_expsign EQU FLT_EXPSIGN");
		AddLineQueue("flt_exp EQU FLT_EXP");
		AddLineQueue("flt_negmaxexp EQU FLT_NEGMAXEXP");
		AddLineQueue("flt_negexpsign EQU FLT_NEGEXPSIGN");
		AddLineQueue("flt_negexp EQU FLT_NEGEXP");
		AddLineQueue("flt_subnormalexp EQU FLT_SUBNORMALEXP");
		AddLineQueue("flt_minexp EQU FLT_MINEXP");
		AddLineQueue("flt_maxdecexp EQU FLT_MAXDECEXP");
		AddLineQueue("flt_negmaxdecexp EQU FLT_NEGMAXDECEXP");
		AddLineQueue("flt_mindecexp EQU FLT_MINDECEXP");
		AddLineQueue("flt_expfield EQU FLT_EXPFIELD");
		AddLineQueue("flt_mantfield EQU FLT_MANTFIELD");
		AddLineQueue("flt_norm EQU FLT_NORM");
		AddLineQueue("flt_radix EQU FLT_RADIX");
		AddLineQueue("flt_rounds EQU FLT_ROUNDS");
		AddLineQueue("flt_subdec EQU FLT_SUBDEC");
		AddLineQueue("flt_sqrtmax EQU FLT_SQRTMAX");
		AddLineQueue("flt_smalnormal EQU FLT_SMALNORMAL");

		AddLineQueue("flt_halfminuseps EQU FLT_HALFMINUSEPS");
		AddLineQueue("flt_trueint EQU FLT_TRUEINT");

		AddLineQueue("flt_byte EQU FLT_BYTE");
		AddLineQueue("flt_4low EQU FLT_4LOW");
		AddLineQueue("flt_4high EQU FLT_4HIGH");
		AddLineQueue("flt_flip4 EQU FLT_FLIP4");
		AddLineQueue("flt_8low EQU FLT_8LOW");
		AddLineQueue("flt_8high EQU FLT_8HIGH");
		AddLineQueue("flt_flip8 EQU FLT_FLIP8");
		AddLineQueue("flt_16low EQU FLT_16LOW");
		AddLineQueue("flt_16high EQU FLT_16HIGH");
		AddLineQueue("flt_flip16 EQU FLT_FLIP16");
		AddLineQueue("flt_24low EQU FLT_24LOW");
		AddLineQueue("flt_24high EQU FLT_24HIGH");
		AddLineQueue("flt_flip24 EQU FLT_FLIP24");
		AddLineQueue("flt_28low EQU FLT_28LOW");
		AddLineQueue("flt_28high EQU FLT_28HIGH");
		AddLineQueue("flt_flip28 EQU FLT_FLIP28");
		AddLineQueue("flt_low EQU FLT_LOW");
		AddLineQueue("flt_high EQU FLT_HIGH");
		AddLineQueue("flt_flip EQU FLT_FLIP");

		AddLineQueue("flt_0 EQU FLT_0");
		AddLineQueue("flt_0d0001 EQU FLT_0D0001");
		AddLineQueue("flt_0d0002 EQU FLT_0D0002");
		AddLineQueue("flt_0d0003 EQU FLT_0D0003");
		AddLineQueue("flt_0d0004 EQU FLT_0D0004");
		AddLineQueue("flt_0d0005 EQU FLT_0D0005");
		AddLineQueue("flt_0d0006 EQU FLT_0D0006");
		AddLineQueue("flt_0d0007 EQU FLT_0D0007");
		AddLineQueue("flt_0d0008 EQU FLT_0D0008");
		AddLineQueue("flt_0d0009 EQU FLT_0D0009");
		AddLineQueue("flt_0d001 EQU FLT_0D001");
		AddLineQueue("flt_0d002 EQU FLT_0D002");
		AddLineQueue("flt_0d003 EQU FLT_0D003");
		AddLineQueue("flt_0d004 EQU FLT_0D004");
		AddLineQueue("flt_0d005 EQU FLT_0D005");
		AddLineQueue("flt_0d006 EQU FLT_0D006");
		AddLineQueue("flt_0d007 EQU FLT_0D007");
		AddLineQueue("flt_0d008 EQU FLT_0D008");
		AddLineQueue("flt_0d009 EQU FLT_0D009");
		AddLineQueue("flt_0d01 EQU FLT_0D01");
		AddLineQueue("flt_0d02 EQU FLT_0D02");
		AddLineQueue("flt_0d025 EQU FLT_0D025");
		AddLineQueue("flt_0d03 EQU FLT_0D03");
		AddLineQueue("flt_0d04 EQU FLT_0D04");
		AddLineQueue("flt_0d05 EQU FLT_0D05");
		AddLineQueue("flt_0d06 EQU FLT_0D06");
		AddLineQueue("flt_0d07 EQU FLT_0D07");
		AddLineQueue("flt_0d08 EQU FLT_0D08");
		AddLineQueue("flt_0d09 EQU FLT_0D09");
		AddLineQueue("flt_0d1 EQU FLT_0D1");
		AddLineQueue("flt_0d2 EQU FLT_0D2");
		AddLineQueue("flt_0d25 EQU FLT_0D25");
		AddLineQueue("flt_0d3 EQU FLT_0D3");
		AddLineQueue("flt_0d4 EQU FLT_0D4");
		AddLineQueue("flt_0d5 EQU FLT_0D5");
		AddLineQueue("flt_0d6 EQU FLT_0D6");
		AddLineQueue("flt_0d7 EQU FLT_0D7");
		AddLineQueue("flt_0d8 EQU FLT_0D8");
		AddLineQueue("flt_0d9 EQU FLT_0D9");
		AddLineQueue("flt_1 EQU FLT_1");
		AddLineQueue("flt_1d25 EQU FLT_1D25");
		AddLineQueue("flt_1d5 EQU FLT_1D5");
		AddLineQueue("flt_2 EQU FLT_2");
		AddLineQueue("flt_2d25 EQU FLT_2D25");
		AddLineQueue("flt_2d5 EQU FLT_2D5");
		AddLineQueue("flt_3 EQU FLT_3");
		AddLineQueue("flt_3d25 EQU FLT_3D25");
		AddLineQueue("flt_3d5 EQU FLT_3D5");
		AddLineQueue("flt_4 EQU FLT_4");
		AddLineQueue("flt_4d25 EQU FLT_4D25");
		AddLineQueue("flt_4d5 EQU FLT_4D5");
		AddLineQueue("flt_5 EQU FLT_5");
		AddLineQueue("flt_5d25 EQU FLT_5D25");
		AddLineQueue("flt_5d5 EQU FLT_5D5");
		AddLineQueue("flt_6 EQU FLT_6");
		AddLineQueue("flt_6d25 EQU FLT_6D25");
		AddLineQueue("flt_6d5 EQU FLT_6D5");
		AddLineQueue("flt_7 EQU FLT_7");
		AddLineQueue("flt_7d25 EQU FLT_7D25");
		AddLineQueue("flt_7d5 EQU FLT_7D5");
		AddLineQueue("flt_8 EQU FLT_8");
		AddLineQueue("flt_8d25 EQU FLT_8D25");
		AddLineQueue("flt_8d5 EQU FLT_8D5");
		AddLineQueue("flt_9 EQU FLT_9");
		AddLineQueue("flt_9d25 EQU FLT_9D25");
		AddLineQueue("flt_9d5 EQU FLT_9D5");
		AddLineQueue("flt_10 EQU FLT_10");
		AddLineQueue("flt_11 EQU FLT_11");
		AddLineQueue("flt_12 EQU FLT_12");
		AddLineQueue("flt_13 EQU FLT_13");
		AddLineQueue("flt_14 EQU FLT_14");
		AddLineQueue("flt_15 EQU FLT_15");
		AddLineQueue("flt_16 EQU FLT_16");
		AddLineQueue("flt_17 EQU FLT_17");
		AddLineQueue("flt_18 EQU FLT_18");
		AddLineQueue("flt_19 EQU FLT_19");
		AddLineQueue("flt_20 EQU FLT_20");
		AddLineQueue("flt_21 EQU FLT_21");
		AddLineQueue("flt_22 EQU FLT_22");
		AddLineQueue("flt_23 EQU FLT_23");
		AddLineQueue("flt_24 EQU FLT_24");
		AddLineQueue("flt_24d5 EQU FLT_24D5");
		AddLineQueue("flt_25 EQU FLT_25");
		AddLineQueue("flt_26 EQU FLT_26");
		AddLineQueue("flt_27 EQU FLT_27");
		AddLineQueue("flt_28 EQU FLT_28");
		AddLineQueue("flt_29 EQU FLT_29");
		AddLineQueue("flt_30 EQU FLT_30");
		AddLineQueue("flt_31 EQU FLT_31");
		AddLineQueue("flt_32 EQU FLT_32");
		AddLineQueue("flt_33 EQU FLT_33");
		AddLineQueue("flt_34 EQU FLT_34");
		AddLineQueue("flt_35 EQU FLT_35");
		AddLineQueue("flt_36 EQU FLT_36");
		AddLineQueue("flt_37 EQU FLT_37");
		AddLineQueue("flt_38 EQU FLT_38");
		AddLineQueue("flt_39 EQU FLT_39");
		AddLineQueue("flt_40 EQU FLT_40");
		AddLineQueue("flt_41 EQU FLT_41");
		AddLineQueue("flt_42 EQU FLT_42");
		AddLineQueue("flt_43 EQU FLT_43");
		AddLineQueue("flt_44 EQU FLT_44");
		AddLineQueue("flt_45 EQU FLT_45");
		AddLineQueue("flt_46 EQU FLT_46");
		AddLineQueue("flt_47 EQU FLT_47");
		AddLineQueue("flt_48 EQU FLT_48");
		AddLineQueue("flt_49 EQU FLT_49");
		AddLineQueue("flt_50 EQU FLT_50");
		AddLineQueue("flt_51 EQU FLT_51");
		AddLineQueue("flt_52 EQU FLT_52");
		AddLineQueue("flt_53 EQU FLT_53");
		AddLineQueue("flt_54 EQU FLT_54");
		AddLineQueue("flt_55 EQU FLT_55");
		AddLineQueue("flt_56 EQU FLT_56");
		AddLineQueue("flt_57 EQU FLT_57");
		AddLineQueue("flt_58 EQU FLT_58");
		AddLineQueue("flt_59 EQU FLT_59");
		AddLineQueue("flt_60 EQU FLT_60");
		AddLineQueue("flt_61 EQU FLT_61");
		AddLineQueue("flt_62 EQU FLT_62");
		AddLineQueue("flt_63 EQU FLT_63");
		AddLineQueue("flt_64 EQU FLT_64");
		AddLineQueue("flt_65 EQU FLT_65");
		AddLineQueue("flt_66 EQU FLT_66");
		AddLineQueue("flt_67 EQU FLT_67");
		AddLineQueue("flt_68 EQU FLT_68");
		AddLineQueue("flt_69 EQU FLT_69");
		AddLineQueue("flt_70 EQU FLT_70");
		AddLineQueue("flt_71 EQU FLT_71");
		AddLineQueue("flt_72 EQU FLT_72");
		AddLineQueue("flt_73 EQU FLT_73");
		AddLineQueue("flt_74 EQU FLT_74");
		AddLineQueue("flt_75 EQU FLT_75");
		AddLineQueue("flt_76 EQU FLT_76");
		AddLineQueue("flt_77 EQU FLT_77");
		AddLineQueue("flt_78 EQU FLT_78");
		AddLineQueue("flt_79 EQU FLT_79");
		AddLineQueue("flt_80 EQU FLT_80");
		AddLineQueue("flt_81 EQU FLT_81");
		AddLineQueue("flt_82 EQU FLT_82");
		AddLineQueue("flt_83 EQU FLT_83");
		AddLineQueue("flt_84 EQU FLT_84");
		AddLineQueue("flt_85 EQU FLT_85");
		AddLineQueue("flt_86 EQU FLT_86");
		AddLineQueue("flt_87 EQU FLT_87");
		AddLineQueue("flt_88 EQU FLT_88");
		AddLineQueue("flt_89 EQU FLT_89");
		AddLineQueue("flt_90 EQU FLT_90");
		AddLineQueue("flt_91 EQU FLT_91");
		AddLineQueue("flt_92 EQU FLT_92");
		AddLineQueue("flt_93 EQU FLT_93");
		AddLineQueue("flt_94 EQU FLT_94");
		AddLineQueue("flt_95 EQU FLT_95");
		AddLineQueue("flt_96 EQU FLT_96");
		AddLineQueue("flt_97 EQU FLT_97");
		AddLineQueue("flt_98 EQU FLT_98");
		AddLineQueue("flt_99 EQU FLT_99");
		AddLineQueue("flt_100 EQU FLT_100");
		AddLineQueue("flt_125 EQU FLT_125");
		AddLineQueue("flt_126 EQU FLT_126");
		AddLineQueue("flt_127 EQU FLT_127");
		AddLineQueue("flt_128 EQU FLT_128");
		AddLineQueue("flt_140 EQU FLT_140");
		AddLineQueue("flt_145 EQU FLT_145");
		AddLineQueue("flt_150 EQU FLT_150");
		AddLineQueue("flt_180 EQU FLT_180");
		AddLineQueue("flt_253 EQU FLT_253");
		AddLineQueue("flt_254 EQU FLT_254");
		AddLineQueue("flt_255 EQU FLT_255");
		AddLineQueue("flt_256 EQU FLT_256");
		AddLineQueue("flt_360 EQU FLT_360");
		AddLineQueue("flt_511 EQU FLT_511");
		AddLineQueue("flt_512 EQU FLT_512");
		AddLineQueue("flt_513 EQU FLT_513");
		AddLineQueue("flt_1023 EQU FLT_1023");
		AddLineQueue("flt_1024 EQU FLT_1024");
		AddLineQueue("flt_1025 EQU FLT_1025");

		AddLineQueue("flt_32767 EQU FLT_32767");
		AddLineQueue("flt_32768 EQU FLT_32768");
		AddLineQueue("flt_65535 EQU FLT_65535");
		AddLineQueue("flt_65536 EQU FLT_65536");
		AddLineQueue("flt_2147483647 EQU FLT_2147483647");
		AddLineQueue("flt_2147483648 EQU FLT_2147483648");
		AddLineQueue("flt_4294967295 EQU FLT_4294967295");
		AddLineQueue("flt_4294967296 EQU FLT_4294967296");

		AddLineQueue("flt_neg0 EQU FLT_NEG0");
		AddLineQueue("flt_neg0d0001 EQU FLT_NEG0D0001");
		AddLineQueue("flt_neg0d0002 EQU FLT_NEG0D0002");
		AddLineQueue("flt_neg0d0003 EQU FLT_NEG0D0003");
		AddLineQueue("flt_neg0d0004 EQU FLT_NEG0D0004");
		AddLineQueue("flt_neg0d0005 EQU FLT_NEG0D0005");
		AddLineQueue("flt_neg0d0006 EQU FLT_NEG0D0006");
		AddLineQueue("flt_neg0d0007 EQU FLT_NEG0D0007");
		AddLineQueue("flt_neg0d0008 EQU FLT_NEG0D0008");
		AddLineQueue("flt_neg0d0009 EQU FLT_NEG0D0009");
		AddLineQueue("flt_neg0d001 EQU FLT_NEG0D001");
		AddLineQueue("flt_neg0d002 EQU FLT_NEG0D002");
		AddLineQueue("flt_neg0d003 EQU FLT_NEG0D003");
		AddLineQueue("flt_neg0d004 EQU FLT_NEG0D004");
		AddLineQueue("flt_neg0d005 EQU FLT_NEG0D005");
		AddLineQueue("flt_neg0d006 EQU FLT_NEG0D006");
		AddLineQueue("flt_neg0d007 EQU FLT_NEG0D007");
		AddLineQueue("flt_neg0d008 EQU FLT_NEG0D008");
		AddLineQueue("flt_neg0d009 EQU FLT_NEG0D009");
		AddLineQueue("flt_neg0d01 EQU FLT_NEG0D01");
		AddLineQueue("flt_neg0d02 EQU FLT_NEG0D02");
		AddLineQueue("flt_neg0d025 EQU FLT_NEG0D025");
		AddLineQueue("flt_neg0d03 EQU FLT_NEG0D03");
		AddLineQueue("flt_neg0d04 EQU FLT_NEG0D04");
		AddLineQueue("flt_neg0d05 EQU FLT_NEG0D05");
		AddLineQueue("flt_neg0d06 EQU FLT_NEG0D06");
		AddLineQueue("flt_neg0d07 EQU FLT_NEG0D07");
		AddLineQueue("flt_neg0d08 EQU FLT_NEG0D08");
		AddLineQueue("flt_neg0d09 EQU FLT_NEG0D09");
		AddLineQueue("flt_neg0d1 EQU FLT_NEG0D1");
		AddLineQueue("flt_neg0d2 EQU FLT_NEG0D2");
		AddLineQueue("flt_neg0d25 EQU FLT_NEG0D25");
		AddLineQueue("flt_neg0d3 EQU FLT_NEG0D3");
		AddLineQueue("flt_neg0d4 EQU FLT_NEG0D4");
		AddLineQueue("flt_neg0d5 EQU FLT_NEG0D5");
		AddLineQueue("flt_neg0d6 EQU FLT_NEG0D6");
		AddLineQueue("flt_neg0d7 EQU FLT_NEG0D7");
		AddLineQueue("flt_neg0d8 EQU FLT_NEG0D8");
		AddLineQueue("flt_neg0d9 EQU FLT_NEG0D9");
		AddLineQueue("flt_neg1 EQU FLT_NEG1");
		AddLineQueue("flt_neg1d25 EQU FLT_NEG1D25");
		AddLineQueue("flt_neg2 EQU FLT_NEG2");
		AddLineQueue("flt_neg2d25 EQU FLT_NEG2D25");
		AddLineQueue("flt_neg3 EQU FLT_NEG3");
		AddLineQueue("flt_neg3d25 EQU FLT_NEG3D25");
		AddLineQueue("flt_neg4 EQU FLT_NEG4");
		AddLineQueue("flt_neg4d25 EQU FLT_NEG4D25");
		AddLineQueue("flt_neg5 EQU FLT_NEG5");
		AddLineQueue("flt_neg5d25 EQU FLT_NEG5D25");
		AddLineQueue("flt_neg6 EQU FLT_NEG6");
		AddLineQueue("flt_neg6d25 EQU FLT_NEG6D25");
		AddLineQueue("flt_neg7 EQU FLT_NEG7");
		AddLineQueue("flt_neg7d25 EQU FLT_NEG7D25");
		AddLineQueue("flt_neg8 EQU FLT_NEG8");
		AddLineQueue("flt_neg8d25 EQU FLT_NEG8D25");
		AddLineQueue("flt_neg9 EQU FLT_NEG9");
		AddLineQueue("flt_neg9d25 EQU FLT_NEG9D25");
		AddLineQueue("flt_neg10 EQU FLT_NEG10");
		AddLineQueue("flt_neg11 EQU FLT_NEG11");
		AddLineQueue("flt_neg12 EQU FLT_NEG12");
		AddLineQueue("flt_neg13 EQU FLT_NEG13");
		AddLineQueue("flt_neg14 EQU FLT_NEG14");
		AddLineQueue("flt_neg15 EQU FLT_NEG15");
		AddLineQueue("flt_neg16 EQU FLT_NEG16");
		AddLineQueue("flt_neg17 EQU FLT_NEG17");
		AddLineQueue("flt_neg18 EQU FLT_NEG18");
		AddLineQueue("flt_neg19 EQU FLT_NEG19");
		AddLineQueue("flt_neg20 EQU FLT_NEG20");
		AddLineQueue("flt_neg21 EQU FLT_NEG21");
		AddLineQueue("flt_neg22 EQU FLT_NEG22");
		AddLineQueue("flt_neg23 EQU FLT_NEG23");
		AddLineQueue("flt_neg24 EQU FLT_NEG24");
		AddLineQueue("flt_neg24d5 EQU FLT_NEG24D5");
		AddLineQueue("flt_neg25 EQU FLT_NEG25");
		AddLineQueue("flt_neg26 EQU FLT_NEG26");
		AddLineQueue("flt_neg27 EQU FLT_NEG27");
		AddLineQueue("flt_neg28 EQU FLT_NEG28");
		AddLineQueue("flt_neg29 EQU FLT_NEG29");
		AddLineQueue("flt_neg30 EQU FLT_NEG30");
		AddLineQueue("flt_neg31 EQU FLT_NEG31");
		AddLineQueue("flt_neg32 EQU FLT_NEG32");
		AddLineQueue("flt_neg33 EQU FLT_NEG33");
		AddLineQueue("flt_neg34 EQU FLT_NEG34");
		AddLineQueue("flt_neg35 EQU FLT_NEG35");
		AddLineQueue("flt_neg36 EQU FLT_NEG36");
		AddLineQueue("flt_neg37 EQU FLT_NEG37");
		AddLineQueue("flt_neg38 EQU FLT_NEG38");
		AddLineQueue("flt_neg39 EQU FLT_NEG39");
		AddLineQueue("flt_neg40 EQU FLT_NEG40");
		AddLineQueue("flt_neg41 EQU FLT_NEG41");
		AddLineQueue("flt_neg42 EQU FLT_NEG42");
		AddLineQueue("flt_neg43 EQU FLT_NEG43");
		AddLineQueue("flt_neg44 EQU FLT_NEG44");
		AddLineQueue("flt_neg45 EQU FLT_NEG45");
		AddLineQueue("flt_neg46 EQU FLT_NEG46");
		AddLineQueue("flt_neg47 EQU FLT_NEG47");
		AddLineQueue("flt_neg48 EQU FLT_NEG48");
		AddLineQueue("flt_neg49 EQU FLT_NEG49");
		AddLineQueue("flt_neg50 EQU FLT_NEG50");
		AddLineQueue("flt_neg51 EQU FLT_NEG51");
		AddLineQueue("flt_neg52 EQU FLT_NEG52");
		AddLineQueue("flt_neg53 EQU FLT_NEG53");
		AddLineQueue("flt_neg54 EQU FLT_NEG54");
		AddLineQueue("flt_neg55 EQU FLT_NEG55");
		AddLineQueue("flt_neg56 EQU FLT_NEG56");
		AddLineQueue("flt_neg57 EQU FLT_NEG57");
		AddLineQueue("flt_neg58 EQU FLT_NEG58");
		AddLineQueue("flt_neg59 EQU FLT_NEG59");
		AddLineQueue("flt_neg60 EQU FLT_NEG60");
		AddLineQueue("flt_neg61 EQU FLT_NEG61");
		AddLineQueue("flt_neg62 EQU FLT_NEG62");
		AddLineQueue("flt_neg63 EQU FLT_NEG63");
		AddLineQueue("flt_neg64 EQU FLT_NEG64");
		AddLineQueue("flt_neg65 EQU FLT_NEG65");
		AddLineQueue("flt_neg66 EQU FLT_NEG66");
		AddLineQueue("flt_neg67 EQU FLT_NEG67");
		AddLineQueue("flt_neg68 EQU FLT_NEG68");
		AddLineQueue("flt_neg69 EQU FLT_NEG69");
		AddLineQueue("flt_neg70 EQU FLT_NEG70");
		AddLineQueue("flt_neg71 EQU FLT_NEG71");
		AddLineQueue("flt_neg72 EQU FLT_NEG72");
		AddLineQueue("flt_neg73 EQU FLT_NEG73");
		AddLineQueue("flt_neg74 EQU FLT_NEG74");
		AddLineQueue("flt_neg75 EQU FLT_NEG75");
		AddLineQueue("flt_neg76 EQU FLT_NEG76");
		AddLineQueue("flt_neg77 EQU FLT_NEG77");
		AddLineQueue("flt_neg78 EQU FLT_NEG78");
		AddLineQueue("flt_neg79 EQU FLT_NEG79");
		AddLineQueue("flt_neg80 EQU FLT_NEG80");
		AddLineQueue("flt_neg81 EQU FLT_NEG81");
		AddLineQueue("flt_neg82 EQU FLT_NEG82");
		AddLineQueue("flt_neg83 EQU FLT_NEG83");
		AddLineQueue("flt_neg84 EQU FLT_NEG84");
		AddLineQueue("flt_neg85 EQU FLT_NEG85");
		AddLineQueue("flt_neg86 EQU FLT_NEG86");
		AddLineQueue("flt_neg87 EQU FLT_NEG87");
		AddLineQueue("flt_neg88 EQU FLT_NEG88");
		AddLineQueue("flt_neg89 EQU FLT_NEG89");
		AddLineQueue("flt_neg90 EQU FLT_NEG90");
		AddLineQueue("flt_neg91 EQU FLT_NEG91");
		AddLineQueue("flt_neg92 EQU FLT_NEG92");
		AddLineQueue("flt_neg93 EQU FLT_NEG93");
		AddLineQueue("flt_neg94 EQU FLT_NEG94");
		AddLineQueue("flt_neg95 EQU FLT_NEG95");
		AddLineQueue("flt_neg96 EQU FLT_NEG96");
		AddLineQueue("flt_neg97 EQU FLT_NEG97");
		AddLineQueue("flt_neg98 EQU FLT_NEG98");
		AddLineQueue("flt_neg99 EQU FLT_NEG99");
		AddLineQueue("flt_neg100 EQU FLT_NEG100");
		AddLineQueue("flt_neg125 EQU FLT_NEG125");
		AddLineQueue("flt_neg126 EQU FLT_NEG126");
		AddLineQueue("flt_neg127 EQU FLT_NEG127");
		AddLineQueue("flt_neg128 EQU FLT_NEG128");
		AddLineQueue("flt_neg140 EQU FLT_NEG140");
		AddLineQueue("flt_neg145 EQU FLT_NEG145");
		AddLineQueue("flt_neg150 EQU FLT_NEG150");
		AddLineQueue("flt_neg180 EQU FLT_NEG180");
		AddLineQueue("flt_neg253 EQU FLT_NEG253");
		AddLineQueue("flt_neg254 EQU FLT_NEG254");
		AddLineQueue("flt_neg255 EQU FLT_NEG255");
		AddLineQueue("flt_neg256 EQU FLT_NEG256");
		AddLineQueue("flt_neg360 EQU FLT_NEG360");
		AddLineQueue("flt_neg511 EQU FLT_NEG511");
		AddLineQueue("flt_neg512 EQU FLT_NEG512");
		AddLineQueue("flt_neg513 EQU FLT_NEG513");
		AddLineQueue("flt_neg1023 EQU FLT_NEG1023");
		AddLineQueue("flt_neg1024 EQU FLT_NEG1024");
		AddLineQueue("flt_neg1025 EQU FLT_NEG1025");

		AddLineQueue("flt_neg32767 EQU FLT_NEG32767");
		AddLineQueue("flt_neg32768 EQU FLT_NEG32768");
		AddLineQueue("flt_neg65535 EQU FLT_NEG65535");
		AddLineQueue("flt_neg65536 EQU FLT_NEG65536");
		AddLineQueue("flt_neg2147483647 EQU FLT_NEG2147483647");
		AddLineQueue("flt_neg2147483648 EQU FLT_NEG2147483648");
		AddLineQueue("flt_neg4294967295 EQU FLT_NEG4294967295");
		AddLineQueue("flt_neg4294967296 EQU FLT_NEG4294967296");

		AddLineQueue("flt_bin128 EQU FLT_BIN128");
		AddLineQueue("flt_binneg150 EQU FLT_BINNEG150");

		AddLineQueue("flt_maxrand EQU FLT_MAXRAND");

		AddLineQueue("flt_maxi8 EQU FLT_MAXI8");
		AddLineQueue("flt_mini8 EQU FLT_MINI8");
		AddLineQueue("flt_maxu8 EQU FLT_MAXU8");
		AddLineQueue("flt_minu8 EQU FLT_MINU8");

		AddLineQueue("flt_maxi16 EQU FLT_MAXI16");
		AddLineQueue("flt_mini16 EQU FLT_MINI16");
		AddLineQueue("flt_maxu16 EQU FLT_MAXU16");
		AddLineQueue("flt_minu16 EQU FLT_MINU16");

		AddLineQueue("flt_maxi32 EQU FLT_MAXI32");
		AddLineQueue("flt_mini32 EQU FLT_MINI32");
		AddLineQueue("flt_maxu32 EQU FLT_MAXU32");
		AddLineQueue("flt_minu32 EQU FLT_MINU32");

		AddLineQueue("flt_maxi8xu8 EQU FLT_MAXI8XU8");
		AddLineQueue("flt_mini8xu8 EQU FLT_MINI8XU8");
		AddLineQueue("flt_maxi8xu16 EQU FLT_MAXI8XU16");
		AddLineQueue("flt_mini8xu16 EQU FLT_MINI8XU16");

		AddLineQueue("flt_maxi16xu16 EQU FLT_MAXI16XU16");
		AddLineQueue("flt_mini16xu16 EQU FLT_MINI16XU16");

		AddLineQueue("flt_fixunsigned EQU FLT_FIXUNSIGNED");
		AddLineQueue("flt_fixmaxi32 EQU FLT_FIXMAXI32");
		AddLineQueue("flt_fixmaxu32 EQU FLT_FIXMAXU32");

		AddLineQueue("flt_rcpi16 EQU FLT_RCPI16");
		AddLineQueue("flt_rcpu16 EQU FLT_RCPU16");
		AddLineQueue("flt_rcpi16xu16 EQU FLT_RCPI16XU16");

		AddLineQueue("flt_fixaa8 EQU FLT_FIXAA8");
		AddLineQueue("flt_fixr8 EQU FLT_FIXR8");
		AddLineQueue("flt_fixg8 EQU FLT_FIXG8");
		AddLineQueue("flt_fixb8 EQU FLT_FIXB8");

		AddLineQueue("flt_norma8 EQU FLT_NORMA8");
		AddLineQueue("flt_normr8 EQU FLT_NORMR8");
		AddLineQueue("flt_normg8 EQU FLT_NORMG8");
		AddLineQueue("flt_normb8 EQU FLT_NORMB8");

		AddLineQueue("flt_fixaa2 EQU FLT_FIXAA2");
		AddLineQueue("flt_fixb10 EQU FLT_FIXB10");
		AddLineQueue("flt_fixg10 EQU FLT_FIXG10");
		AddLineQueue("flt_fixr10 EQU FLT_FIXR10");

		AddLineQueue("flt_norma2 EQU FLT_NORMA2");
		AddLineQueue("flt_normb10 EQU FLT_NORMB10");
		AddLineQueue("flt_normg10 EQU FLT_NORMG10");
		AddLineQueue("flt_normr10 EQU FLT_NORMR10");

		AddLineQueue("flt_mg EQU FLT_MG");
		AddLineQueue("flt_negmg EQU FLT_NEGMG");
		AddLineQueue("flt_halfmg EQU FLT_HALFMG");
		AddLineQueue("flt_neghalfmg EQU FLT_NEGHALFMG");
		AddLineQueue("flt_mgdiv4 EQU FLT_MGDIV4");
		AddLineQueue("flt_negmgdiv4 EQU FLT_NEGMGDIV4");
		AddLineQueue("flt_halfmgxmg EQU FLT_HALFMGXMG");
		AddLineQueue("flt_halfmgxsqrmg EQU FLT_HALFMGXSQRMG");
		AddLineQueue("flt_halfmgxcubemg EQU FLT_HALFMGXCUBEMG");
		AddLineQueue("flt_neghalfmgxmg EQU FLT_NEGHALFMGXMG");
		AddLineQueue("flt_neghalfmgxsqrmg EQU FLT_NEGHALFMGXSQRMG");
		AddLineQueue("flt_neghalfmgxcubemg EQU FLT_NEGHALFMGXCUBEMG");
		AddLineQueue("flt_sqrmg EQU FLT_SQRMG");
		AddLineQueue("flt_cubemg EQU FLT_CUBEMG");
		AddLineQueue("flt_sqrtmg EQU FLT_SQRTMG");
		AddLineQueue("flt_cbrtmg EQU FLT_CBRTMG");
		AddLineQueue("flt_rcpmg EQU FLT_RCPMG");
		AddLineQueue("flt_rcpsqrmg EQU FLT_RCPSQRMG");
		AddLineQueue("flt_rcpcubemg EQU FLT_RCPCUBEMG");
		AddLineQueue("flt_rcpsqrtmg EQU FLT_RCPSQRTMG");
		AddLineQueue("flt_rcpcbrtmg EQU FLT_RCPCBRTMG");

		AddLineQueue("flt_2mg EQU FLT_2MG");
		AddLineQueue("flt_neg2mg EQU FLT_NEG2MG");
		AddLineQueue("flt_sqr2mg EQU FLT_SQR2MG");
		AddLineQueue("flt_cube2mg EQU FLT_CUBE2MG");
		AddLineQueue("flt_sqrt2mg EQU FLT_SQRT2MG");
		AddLineQueue("flt_cbrt2mg EQU FLT_CBRT2MG");
		AddLineQueue("flt_4mg EQU FLT_4MG");
		AddLineQueue("flt_neg4mg EQU FLT_NEG4MG");
		AddLineQueue("flt_sqr4mg EQU FLT_SQR4MG");
		AddLineQueue("flt_cube4mg EQU FLT_CUBE4MG");
		AddLineQueue("flt_sqrt4mg EQU FLT_SQRT4MG");
		AddLineQueue("flt_cbrt4mg EQU FLT_CBRT4MG");
		AddLineQueue("flt_rcp2mg EQU FLT_RCP2MG");
		AddLineQueue("flt_rcp4mg EQU FLT_RCP4MG");

		AddLineQueue("flt_e EQU FLT_E");
		AddLineQueue("flt_exp EQU FLT_EXP");
		AddLineQueue("flt_loge EQU FLT_LOGE");
		AddLineQueue("flt_logehigh EQU FLT_LOGEHIGH");
		AddLineQueue("flt_log2e EQU FLT_LOG2E");
		AddLineQueue("flt_log2ehigh EQU FLT_LOG2EHIGH");
		AddLineQueue("flt_log10e EQU FLT_LOG10E");
		AddLineQueue("flt_rcplog2e EQU FLT_RCPLOG2E");
		AddLineQueue("flt_rcplog10e EQU FLT_RCPLOG10E");
		AddLineQueue("flt_log2t EQU FLT_LOG2T");
		AddLineQueue("flt_log2 EQU FLT_LOG2");
		AddLineQueue("flt_log2high EQU FLT_LOG2HIGH");
		AddLineQueue("flt_ln2 EQU FLT_LN2");
		AddLineQueue("flt_ln2high EQU FLT_LN2HIGH");
		AddLineQueue("flt_1divln2 EQU FLT_1DIVLN2");
		AddLineQueue("flt_2divln2 EQU FLT_2DIVLN2");
		AddLineQueue("flt_lnt EQU FLT_LNT");
		AddLineQueue("flt_lnthigh EQU FLT_LNTHIGH");
		AddLineQueue("flt_ln10 EQU FLT_LN10");
		AddLineQueue("flt_sqrt2 EQU FLT_SQRT2");
		AddLineQueue("flt_rcpsqrt2 EQU FLT_RCPSQRT2");
		AddLineQueue("flt_sqrt2div2 EQU FLT_SQRT2DIV2");
		AddLineQueue("flt_sqrt2div2high EQU FLT_SQRT2DIV2HIGH");
		AddLineQueue("flt_sqrt2div2low EQU FLT_SQRT2DIV2LOW");
		AddLineQueue("flt_sqrthalf EQU FLT_SQRTHALF");
		AddLineQueue("flt_sqrthalfhigh EQU FLT_SQRTHALFHIGH");
		AddLineQueue("flt_sqrthalflow EQU FLT_SQRTHALFLOW");
		AddLineQueue("flt_pow2 EQU FLT_POW2");
		AddLineQueue("flt_rcppow2 EQU FLT_RCPPOW2");
		AddLineQueue("flt_cbrt2 EQU FLT_CBRT2");
		AddLineQueue("flt_rcpcbrt2 EQU FLT_RCPCBRT2");
		AddLineQueue("flt_1div3 EQU FLT_1DIV3");
		AddLineQueue("flt_1div7 EQU FLT_1DIV7");
		AddLineQueue("flt_1div9 EQU FLT_1DIV9");
		AddLineQueue("flt_2div3 EQU FLT_2DIV3");
		AddLineQueue("flt_2div7 EQU FLT_2DIV7");
		AddLineQueue("flt_2div9 EQU FLT_2DIV9");
		AddLineQueue("flt_4div3 EQU FLT_4DIV3");
		AddLineQueue("flt_4div7 EQU FLT_4DIV7");
		AddLineQueue("flt_4div9 EQU FLT_4DIV9");

		AddLineQueue("flt_pi EQU FLT_PI");
		AddLineQueue("flt_pihigh EQU FLT_PIHIGH");
		AddLineQueue("flt_halfpi EQU FLT_HALFPI");
		AddLineQueue("flt_2pi EQU FLT_2PI");
		AddLineQueue("flt_negpi EQU FLT_NEGPI");
		AddLineQueue("flt_neghalfpi EQU FLT_NEGHALFPI");
		AddLineQueue("flt_neg2pi EQU FLT_NEG2PI");
		AddLineQueue("flt_rcppi EQU FLT_RCPPI");
		AddLineQueue("flt_invpi EQU FLT_INVPI");
		AddLineQueue("flt_rcp2pi EQU FLT_RCP2PI");
		AddLineQueue("flt_inv2pi EQU FLT_INV2PI");
		AddLineQueue("flt_pidiv2 EQU FLT_PIDIV2");
		AddLineQueue("flt_pidiv2high EQU FLT_PIDIV2HIGH");
		AddLineQueue("flt_pidiv4 EQU FLT_PIDIV4");
		AddLineQueue("flt_pidiv4high EQU FLT_PIDIV4HIGH");
		AddLineQueue("flt_pix3div4 EQU FLT_PIX3DIV4");
		AddLineQueue("flt_sqrtpi EQU FLT_SQRTPI");
		AddLineQueue("flt_sqrt2pi EQU FLT_SQRT2PI");
		AddLineQueue("flt_sqrt2pihigh EQU FLT_SQRT2PIHIGH");
		AddLineQueue("flt_rcpsqrtpi EQU FLT_RCPSQRTPI");
		AddLineQueue("flt_rcpsqrt2pi EQU FLT_RCPSQRT2PI");
		AddLineQueue("flt_sqrtpidiv2 EQU FLT_SQRTPIDIV2");
		AddLineQueue("flt_sqrtpidiv2high EQU FLT_SQRTPIDIV2HIGH");
		AddLineQueue("flt_sqrt2pidiv2 EQU FLT_SQRT2PIDIV2");
		AddLineQueue("flt_sqrt2pidiv2high EQU FLT_SQRT2PIDIV2HIGH");
		AddLineQueue("flt_2divpi EQU FLT_2DIVPI");
		AddLineQueue("flt_2div2pi EQU FLT_2DIV2PI");
		AddLineQueue("flt_2divsqrtpi EQU FLT_2DIVSQRTPI");
		AddLineQueue("flt_2divsqrt2pi EQU FLT_2DIVSQRT2PI");
		AddLineQueue("flt_sqrt2divpi EQU FLT_SQRT2DIVPI");
		AddLineQueue("flt_logpi EQU FLT_LOGPI");
		AddLineQueue("flt_log2pi EQU FLT_LOG2PI");
		AddLineQueue("flt_lnpi EQU FLT_LNPI");
		AddLineQueue("flt_ln2pi EQU FLT_LN2PI");
		AddLineQueue("flt_powpi EQU FLT_POWPI");
		AddLineQueue("flt_rcppowpi EQU FLT_RCPPOWPI");
		AddLineQueue("flt_pow2pi EQU FLT_POW2PI");
		AddLineQueue("flt_rcppow2pi EQU FLT_RCPPOW2PI");
		AddLineQueue("flt_cbrtpi EQU FLT_CBRTPI");
		AddLineQueue("flt_rcpcbrtpi EQU FLT_RCPCBRTPI");
		AddLineQueue("flt_cbrt2pi EQU FLT_CBRT2PI");
		AddLineQueue("flt_rcpcbrt2pi EQU FLT_RCPCBRT2PI");

		AddLineQueue("flt_pow2tom126 EQU FLT_POW2TOM126");
		AddLineQueue("flt_pow2to126 EQU FLT_POW2TO126");
		AddLineQueue("flt_normhuge EQU FLT_NORMHUGE");
		AddLineQueue("flt_pow2to23 EQU FLT_POW2TO23");
		AddLineQueue("flt_pow2to24 EQU FLT_POW2TO24");
		AddLineQueue("flt_maxi32pow2to23 EQU FLT_MAXI32POW2TO23");
		AddLineQueue("flt_pow2to31 EQU FLT_POW2TO31");
		AddLineQueue("flt_pow2to32 EQU FLT_POW2TO32");

		AddLineQueue("flt_remquobits EQU FLT_REMQUOBITS");
		AddLineQueue("flt_remquomask EQU FLT_REMQUOMASK");

		AddLineQueue("flt_trigploss EQU FLT_TRIGPLOSS");

		AddLineQueue("flt_degtorad EQU FLT_DEGTORAD");
		AddLineQueue("flt_radtodeg EQU FLT_RADTODEG");

		AddLineQueue("flt_degtograd EQU FLT_DEGTOGRAD");
		AddLineQueue("flt_gradtodeg EQU FLT_GRADTODEG");

		AddLineQueue("flt_radtograd EQU FLT_RADTOGRAD");
		AddLineQueue("flt_gradtorad EQU FLT_GRADTORAD");

		AddLineQueue("flt_sungravity EQU FLT_SUNGRAVITY");
		AddLineQueue("flt_jupitergravity EQU FLT_JUPITERGRAVITY");
		AddLineQueue("flt_neptunegravity EQU FLT_NEPTUNEGRAVITY");
		AddLineQueue("flt_saturngravity EQU FLT_SATURNGRAVITY");
		AddLineQueue("flt_uranusgravity EQU FLT_URANUSGRAVITY");
		AddLineQueue("flt_earthgravity EQU FLT_EARTHGRAVITY");
		AddLineQueue("flt_venusgravity EQU FLT_VENUSGRAVITY");
		AddLineQueue("flt_marsgravity EQU FLT_MARSGRAVITY");
		AddLineQueue("flt_mercurygravity EQU FLT_MERCURYGRAVITY");
		AddLineQueue("flt_moongravity EQU FLT_MOONGRAVITY");
		AddLineQueue("flt_pluto EQU FLT_PLUTO");

		AddLineQueue("flt_kmtoinch EQU FLT_KMTOINCH");
		AddLineQueue("flt_kmtofeet EQU FLT_KMTOFEET");
		AddLineQueue("flt_kmtoyards EQU FLT_KMTOYARDS");
		AddLineQueue("flt_kmtomiles EQU FLT_KMTOMILES");

		AddLineQueue("flt_metoinch EQU FLT_METOINCH");
		AddLineQueue("flt_metofeet EQU FLT_METOFEET");
		AddLineQueue("flt_metoyards EQU FLT_METOYARDS");
		AddLineQueue("flt_metomiles EQU FLT_METOMILES");

		AddLineQueue("flt_cmtoinch EQU FLT_CMTOINCH");
		AddLineQueue("flt_cmtofeet EQU FLT_CMTOFEET");
		AddLineQueue("flt_cmtoyards EQU FLT_CMTOYARDS");
		AddLineQueue("flt_cmtomiles EQU FLT_CMTOMILES");

		AddLineQueue("flt_milltoinch EQU FLT_MILLTOINCH");
		AddLineQueue("flt_milltofeet EQU FLT_MILLTOFEET");
		AddLineQueue("flt_milltoyards EQU FLT_MILLTOYARDS");
		AddLineQueue("flt_milltomiles EQU FLT_MILLTOMILES");

		AddLineQueue("flt_inchtomill EQU FLT_INCHTOMILL");
		AddLineQueue("flt_inchtocm EQU FLT_INCHTOCM");
		AddLineQueue("flt_inchtome EQU FLT_INCHTOME");
		AddLineQueue("flt_inchtokm EQU FLT_INCHTOKM");
		AddLineQueue("flt_inchtofeet EQU FLT_INCHTOFEET");
		AddLineQueue("flt_inchtoyards EQU FLT_INCHTOYARDS");
		AddLineQueue("flt_inchtomiles EQU FLT_INCHTOMILES");

		AddLineQueue("flt_feettomill EQU FLT_FEETTOMILL");
		AddLineQueue("flt_feettocm EQU FLT_FEETTOCM");
		AddLineQueue("flt_feettome EQU FLT_FEETTOME");
		AddLineQueue("flt_feettokm EQU FLT_FEETTOKM");
		AddLineQueue("flt_feettoinch EQU FLT_FEETTOINCH");
		AddLineQueue("flt_feettoyards EQU FLT_FEETTOYARDS");
		AddLineQueue("flt_FEETOmiles EQU FLT_FEETOMILES");

		AddLineQueue("flt_yardstomill EQU FLT_YARDSTOMILL");
		AddLineQueue("flt_yardstocm EQU FLT_YARDSTOCM");
		AddLineQueue("flt_yardstome EQU FLT_YARDSTOME");
		AddLineQueue("flt_yardstokm EQU FLT_YARDSTOKM");
		AddLineQueue("flt_yardstoinch EQU FLT_YARDSTOINCH");
		AddLineQueue("flt_yardstofeet EQU FLT_YARDSTOFEET");
		AddLineQueue("flt_yardstomiles EQU FLT_YARDSTOMILES");

		AddLineQueue("flt_milestomill EQU FLT_MILESTOMILL");
		AddLineQueue("flt_milestocm EQU FLT_MILESTOCM");
		AddLineQueue("flt_milestome EQU FLT_MILESTOME");
		AddLineQueue("flt_milestokm EQU FLT_MILESTOKM");
		AddLineQueue("flt_milestoinch EQU FLT_MILESTOINCH");
		AddLineQueue("flt_milestofeet EQU FLT_MILESTOFEET");
		AddLineQueue("flt_milestoyards EQU FLT_MILESTOYARDS");

		AddLineQueue("flt_kmphtomeps EQU FLT_KMPHTOMEPS");
		AddLineQueue("flt_kmphtokmps EQU FLT_KMPHTOKMPS");
		AddLineQueue("flt_kmphtomepm EQU FLT_KMPHTOMEPM");
		AddLineQueue("flt_kmphtomilesph EQU FLT_KMPHTOMILESPH");
		AddLineQueue("flt_kmphtomilesps EQU FLT_KMPHTOMILESPS");
		AddLineQueue("flt_kmphtofootps EQU FLT_KMPHTOFOOTPS");
		AddLineQueue("flt_kmphtofootpm EQU FLT_KMPHTOFOOTPM");

		AddLineQueue("flt_kmpstomeps EQU FLT_KMPSTOMEPS");
		AddLineQueue("flt_kmpstokmph EQU FLT_KMPSTOKMPH");
		AddLineQueue("flt_kmpstomepm EQU FLT_KMPSTOMEPM");
		AddLineQueue("flt_kmpstomilesph EQU FLT_KMPSTOMILESPH");
		AddLineQueue("flt_kmpstomilesps EQU FLT_KMPSTOMILESPS");
		AddLineQueue("flt_kmpstofootps EQU FLT_KMPSTOFOOTPS");
		AddLineQueue("flt_kmpstofootpm EQU FLT_KMPSTOFOOTPM");

		AddLineQueue("flt_mepstokmph EQU FLT_MEPSTOKMPH");
		AddLineQueue("flt_mepstokmps EQU FLT_MEPSTOKMPS");
		AddLineQueue("flt_mepstomepm EQU FLT_MEPSTOMEPM");
		AddLineQueue("flt_mepstomilesph EQU FLT_MEPSTOMILESPH");
		AddLineQueue("flt_mepstomilesps EQU FLT_MEPSTOMILESPS");
		AddLineQueue("flt_mepstofootps EQU FLT_MEPSTOFOOTPS");
		AddLineQueue("flt_mepstofootpm EQU FLT_MEPSTOFOOTPM");

		AddLineQueue("flt_mepmtokmph EQU FLT_MEPMTOKMPH");
		AddLineQueue("flt_mepmtokmps EQU FLT_MEPMTOKMPS");
		AddLineQueue("flt_mepmtomeps EQU FLT_MEPMTOMEPS");
		AddLineQueue("flt_mepmtomilesph EQU FLT_MEPMTOMILESPH");
		AddLineQueue("flt_mepmtomilesps EQU FLT_MEPMTOMILESPS");
		AddLineQueue("flt_mepmtofootps EQU FLT_MEPMTOFOOTPS");
		AddLineQueue("flt_mepmtofootpm EQU FLT_MEPMTOFOOTPM");

		AddLineQueue("flt_milesphtokmph EQU FLT_MILESPHTOKMPH");
		AddLineQueue("flt_milesphtokmps EQU FLT_MILESPHTOKMPS");
		AddLineQueue("flt_milesphtomeps EQU FLT_MILESPHTOMEPS");
		AddLineQueue("flt_milesphtomepm EQU FLT_MILESPHTOMEPM");
		AddLineQueue("flt_milesphtomilesps EQU FLT_MILESPHTOMILESPS");
		AddLineQueue("flt_milesphtofootps EQU FLT_MILESPHTOFOOTPS");
		AddLineQueue("flt_milesphtofootpm EQU FLT_MILESPHTOFOOTPM");

		AddLineQueue("flt_milespstokmph EQU FLT_MILESPSTOKMPH");
		AddLineQueue("flt_milespstokmps EQU FLT_MILESPSTOKMPS");
		AddLineQueue("flt_milespstomeps EQU FLT_MILESPSTOMEPS");
		AddLineQueue("flt_milespstomepm EQU FLT_MILESPSTOMEPM");
		AddLineQueue("flt_milespstoMILESPM EQU FLT_MILESPSTOMILESPM");
		AddLineQueue("flt_milespstofootps EQU FLT_MILESPSTOFOOTPS");
		AddLineQueue("flt_milespstofootpm EQU FLT_MILESPSTOFOOTPM");

		AddLineQueue("flt_footpstokmph EQU FLT_FOOTPSTOKMPH");
		AddLineQueue("flt_footpstokmps EQU FLT_FOOTPSTOKMPS");
		AddLineQueue("flt_footpstomeps EQU FLT_FOOTPSTOMEPS");
		AddLineQueue("flt_footpstomepm EQU FLT_FOOTPSTOMEPM");
		AddLineQueue("flt_footpstomilesph EQU FLT_FOOTPSTOMILESPH");
		AddLineQueue("flt_footpstomilesps EQU FLT_FOOTPSTOMILESPS");
		AddLineQueue("flt_footpstofootpm EQU FLT_FOOTPSTOFOOTPM");

		AddLineQueue("flt_footpmtokmph EQU FLT_FOOTPMTOKMPH");
		AddLineQueue("flt_footpmtokmps EQU FLT_FOOTPMTOKMPS");
		AddLineQueue("flt_footpmtomeps EQU FLT_FOOTPMTOMEPS");
		AddLineQueue("flt_footpmtomepm EQU FLT_FOOTPMTOMEPM");
		AddLineQueue("flt_footpmtomilesph EQU FLT_FOOTPMTOMILESPH");
		AddLineQueue("flt_footpmtomilesps EQU FLT_FOOTPMTOMILESPS");
		AddLineQueue("flt_footpmtofootps EQU FLT_FOOTPMTOFOOTPS");

		AddLineQueue("flt_soundspeed50c EQU FLT_SOUNDSPEED50C");
		AddLineQueue("flt_soundspeed45c EQU FLT_SOUNDSPEED45C");
		AddLineQueue("flt_soundspeed40c EQU FLT_SOUNDSPEED40C");
		AddLineQueue("flt_soundspeed35c EQU FLT_SOUNDSPEED35C");
		AddLineQueue("flt_soundspeed30c EQU FLT_SOUNDSPEED30C");
		AddLineQueue("flt_soundspeed25c EQU FLT_SOUNDSPEED25C");
		AddLineQueue("flt_soundspeed20c EQU FLT_SOUNDSPEED20C");
		AddLineQueue("flt_soundspeed15c EQU FLT_SOUNDSPEED15C");
		AddLineQueue("flt_soundspeed10c EQU FLT_SOUNDSPEED10C");
		AddLineQueue("flt_soundspeed5c EQU FLT_SOUNDSPEED5C");
		AddLineQueue("flt_soundspeed0c EQU FLT_SOUNDSPEED0C");
		AddLineQueue("flt_soundspeedN5c EQU FLT_SOUNDSPEEDN5C");
		AddLineQueue("flt_soundspeedN10c EQU FLT_SOUNDSPEEDN10C");
		AddLineQueue("flt_soundspeedN15c EQU FLT_SOUNDSPEEDN15C");
		AddLineQueue("flt_soundspeedN20c EQU FLT_SOUNDSPEEDN20C");
		AddLineQueue("flt_soundspeedN25c EQU FLT_SOUNDSPEEDN25C");
		AddLineQueue("flt_soundspeedN30c EQU FLT_SOUNDSPEEDN30C");
		AddLineQueue("flt_soundspeedN35c EQU FLT_SOUNDSPEEDN35C");
		AddLineQueue("flt_soundspeedN40c EQU FLT_SOUNDSPEEDN40C");
		AddLineQueue("flt_soundspeedN45c EQU FLT_SOUNDSPEEDN45C");
		AddLineQueue("flt_soundspeedN50c EQU FLT_SOUNDSPEEDN50C");

		AddLineQueue("flt_schscale EQU FLT_SCHSCALE");
		AddLineQueue("flt_thscale EQU FLT_THSCALE");

		AddLineQueue("flt_expest1 EQU FLT_EXPEST1");
		AddLineQueue("flt_expest2 EQU FLT_EXPEST2");
		AddLineQueue("flt_expest3 EQU FLT_EXPEST3");
		AddLineQueue("flt_expest4 EQU FLT_EXPEST4");
		AddLineQueue("flt_expest5 EQU FLT_EXPEST5");
		AddLineQueue("flt_expest6 EQU FLT_EXPEST6");
		AddLineQueue("flt_expest7 EQU FLT_EXPEST7");
		AddLineQueue("flt_logest0 EQU FLT_LOGESTO");
		AddLineQueue("flt_logest1 EQU FLT_LOGEST1");
		AddLineQueue("flt_logest2 EQU FLT_LOGEST2");
		AddLineQueue("flt_logest3 EQU FLT_LOGEST3");
		AddLineQueue("flt_logest4 EQU FLT_LOGEST4");
		AddLineQueue("flt_logest5 EQU FLT_LOGEST5");
		AddLineQueue("flt_logest6 EQU FLT_LOGEST6");
		AddLineQueue("flt_logest7 EQU FLT_LOGEST7");
		
		/* EFLAGS %eax=00H, %ebx=00H */
		AddLineQueue("bit_cpuid EQU BIT_CPUID");		/*1 << 21*/

		/* %eax=00H, %ecx %ebx */
		AddLineQueue("bit_ntel EQU BIT_NTEL");			/*'GenuineIntel'*/
		AddLineQueue("bit_camd EQU BIT_CAMD");			/*'AuthenticAMD'*/

		/* %eax=00H, %ebx */
		AddLineQueue("bit_cent EQU BIT_CENT");			/*'CentaurHauls'*/
		AddLineQueue("bit_via EQU BIT_VIA");			/*'VIA VIA VIA'*/
		AddLineQueue("bit_cyri EQU BIT_CYRI");			/*'CyrixInstead'*/
		AddLineQueue("bit_nexg EQU BIT_NEXG");			/*'NexGenDriven'*/

		/* %eax=01H, %ecx */
		AddLineQueue("bit_sse3 EQU BIT_SSE3");			/*1 << 0*/
		AddLineQueue("bit_pclmulqdq EQU BIT_PCLMULQDQ");/*1 << 1*/
		AddLineQueue("bit_monitor EQU BIT_MONITOR");	/*1 << 3*/
		AddLineQueue("bit_ssse3 EQU BIT_SSSE3");		/*1 << 9*/
		AddLineQueue("bit_fma EQU BIT_FMA");			/*1 << 12*/
		AddLineQueue("bit_cmpxchg16b EQU BIT_CMPXCHG16B");/*1 << 13*/
		AddLineQueue("bit_sse41 EQU BIT_SSE41");		/*1 << 19*/
		AddLineQueue("bit_sse42 EQU BIT_SSE42");		/*1 << 20*/
		AddLineQueue("bit_movbe EQU BIT_MOVBE");		/*1 << 22*/
		AddLineQueue("bit_popcnt EQU BIT_POPCNT");		/*1 << 23*/
		AddLineQueue("bit_aes EQU BIT_AES");			/*1 << 25*/
		AddLineQueue("bit_xsave EQU BIT_XSAVE");		/*1 << 26*/
		AddLineQueue("bit_osxsave EQU BIT_OSXSAVE");	/*1 << 27*/
		AddLineQueue("bit_avx EQU BIT_AVX");			/*1 << 28*/
		AddLineQueue("bit_f16c EQU BIT_F16C");			/*1 << 29*/
		AddLineQueue("bit_rdrand EQU BIT_RDRAND");		/*1 << 30*/

		AddLineQueue("bit_avx_fma EQU BIT_AVX_FMA");	/*1 << 12 | 1 << 27 | 1 << 28*/
		AddLineQueue("bit_osxsave_avx EQU BIT_OSXSAVE_AVX");	/*1 << 27 | 1 << 28*/
		AddLineQueue("bit_avx_f16c EQU BIT_AVX_F16C");	/*1 << 27 | 1 << 28 | 1 << 29*/

		AddLineQueue("bit_sse3_aes EQU BIT_SSE3_AES");	/*1 << 0 | 1 << 25*/
		AddLineQueue("bit_ssse3_aes EQU BIT_SSSE3_AES");	/*1 << 9 | 1 << 25*/
		AddLineQueue("bit_sse41_aes EQU BIT_SSE41_AES");	/*1 << 19 | 1 << 25*/
		AddLineQueue("bit_sse42_aes EQU BIT_SSE42_AES");	/*1 << 20 | 1 << 25*/

		AddLineQueue("bit_sse3_pclmulqdq EQU BIT_SSE3_PCLMULQDQ");		/*1 << 1 | 1 << 1*/
		AddLineQueue("bit_ssse3_pclmulqdq EQU BIT_SSSE3_PCLMULQDQ");	/*1 << 1 | 1 << 9*/
		AddLineQueue("bit_sse41_pclmulqdq EQU BIT_SSE41_PCLMULQDQ");	/*1 << 1 | 1 << 19*/
		AddLineQueue("bit_sse42_pclmulqdq EQU BIT_SSE42_PCLMULQDQ");	/*1 << 1 | 1 << 20*/

		/* %eax=01H, %edx */
		AddLineQueue("bit_fpu EQU BIT_FPU");				/*1 << 0*/
		AddLineQueue("bit_tsc EQU BIT_TSC");				/*1 << 4*/
		AddLineQueue("bit_msr EQU BIT_MSR");				/*1 << 5*/
		AddLineQueue("bit_cmpxchg8b EQU BIT_CMPXCHG8B");	/*1 << 8*/
		AddLineQueue("bit_sep EQU BIT_SEP");				/*1 << 11*/
		AddLineQueue("bit_cmov EQU BIT_CMOV");			/*1 << 15*/
		AddLineQueue("bit_clfsh EQU BIT_CLFSH");		/*1 << 19*/
		AddLineQueue("bit_mmx EQU BIT_MMX");			/*1 << 23*/
		AddLineQueue("bit_fxsr EQU BIT_FXSR");			/*1 << 24*/
		AddLineQueue("bit_sse EQU BIT_SSE");			/*1 << 25*/
		AddLineQueue("bit_sse2 EQU BIT_SSE2");			/*1 << 26*/

		/* %eax=07H, %ebx */
		AddLineQueue("bit_fsgsbase EQU BIT_FSGSBASE");	/*1 << 0*/
		AddLineQueue("bit_sgx EQU BIT_SGX");			/*1 << 2*/
		AddLineQueue("bit_bmi1 EQU BIT_BMI1");			/*1 << 3*/
		AddLineQueue("bit_hle EQU BIT_HLE");			/*1 << 4*/
		AddLineQueue("bit_avx2 EQU BIT_AVX2");			/*1 << 5*/
		AddLineQueue("bit_smep EQU BIT_SMEP");			/*1 << 7*/
		AddLineQueue("bit_bmi2 EQU BIT_BMI2");			/*1 << 8*/
		AddLineQueue("bit_erms EQU BIT_ERMS");			/*1 << 9*/
		AddLineQueue("bit_invpcid EQU BIT_INVPCID");	/*1 << 10*/
		AddLineQueue("bit_rtm EQU BIT_RTM");			/*1 << 11*/
		AddLineQueue("bit_mpx EQU BIT_MPX");			/*1 << 14*/
		AddLineQueue("bit_avx512f EQU BIT_AVX512F");	/*1 << 16*/
		AddLineQueue("bit_avx512DQ EQU BIT_AVX512DQ");	/*1 << 17*/
		AddLineQueue("bit_rdseed EQU BIT_RDSEED");		/*1 << 18*/
		AddLineQueue("bit_adx EQU BIT_ADX");			/*1 << 19*/
		AddLineQueue("bit_smap EQU BIT_SMAP");			/*1 << 20*/
		AddLineQueue("bit_avx512_Ifma EQU BIT_AVX512_IFMA");/*1 << 21*/
		AddLineQueue("bit_clflushopt EQU BIT_CLFLUSHOPT");	/*1 << 23*/
		AddLineQueue("bit_clwb EQU BIT_CLWB");				/*1 << 24*/
		AddLineQueue("bit_avx512pf EQU BIT_AVX512PF");		/*1 << 26*/
		AddLineQueue("bit_avx512er EQU BIT_AVX512ER");		/*1 << 27*/
		AddLineQueue("bit_avx512cd EQU BIT_AVX512CD");		/*1 << 28*/
		AddLineQueue("bit_sha EQU BIT_SHA");				/*1 << 29*/
		AddLineQueue("bit_avx512bw EQU BIT_AVX512BW");		/*1 << 30*/
		AddLineQueue("bit_avx512vl EQU BIT_AVX512VL");		/*1 << 31*/

		AddLineQueue("bit_avx512f_dq EQU BIT_AVX512F_DQ");			/*1 << 16 | 1 << 17*/
		AddLineQueue("bit_avx512f_dq_vl EQU BIT_AVX512F_DQ_VL");	/*1 << 16 | 1 << 17 | 1 << 31*/
		AddLineQueue("bit_avx512f_ifma EQU BIT_AVX512F_IFMA");		/*1 << 16 | 1 << 21*/
		AddLineQueue("bit_avx512f_ifma_vl EQU BIT_AVX512F_IFMA_VL");/*1 << 16 | 1 << 21 | 1 << 31*/
		AddLineQueue("bit_avx512f_pf EQU BIT_AVX512F_PF");			/*1 << 16 | 1 << 26*/
		AddLineQueue("bit_avx512f_er EQU BIT_AVX512F_ER");			/*1 << 16 | 1 << 27*/
		AddLineQueue("bit_avx512f_cd EQU BIT_AVX512F_CD");			/*1 << 16 | 1 << 28*/
		AddLineQueue("bit_avx512f_cd_vl EQU BIT_AVX512F_CD_VL");	/*1 << 16 | 1 << 28 | 1 << 31*/
		AddLineQueue("bit_avx512f_bw EQU BIT_AVX512F_BW");			/*1 << 16 | 1 << 30*/
		AddLineQueue("bit_avx512f_bw_vl EQU BIT_AVX512F_BW_VL");	/*1 << 16 | 1 << 30 | 1 << 31*/
		AddLineQueue("bit_avx512f_vl EQU BIT_AVX512F_VL");			/*1 << 16 | 1 << 31*/

		/* %eax=07H, %ecx */
		AddLineQueue("bit_prefetchwt1 EQU BIT_PREFETCHWT1");	/*1 << 0*/
		AddLineQueue("bit_avx512_vbmi EQU BIT_AVX512_VBMI");	/*1 << 1*/
		AddLineQueue("bit_unip EQU BIT_UMIP");					/*1 << 2*/
		AddLineQueue("bit_pku EQU BIT_PKU");					/*1 << 3*/
		AddLineQueue("bit_ospke EQU BIT_OSPKE");				/*1 << 4*/
		AddLineQueue("bit_avx512_vbmi2 EQU BIT_AVX512_VBMI2");	/*1 << 6*/
		AddLineQueue("bit_gfni EQU BIT_GFNI");					/*1 << 8*/
		AddLineQueue("bit_vaes EQU BIT_VAES");					/*1 << 9*/
		AddLineQueue("bit_vpclmulqdq EQU BIT_VPCLMULQDQ");		/*1 << 10*/
		AddLineQueue("bit_avx512_vnni EQU BIT_AVX512_VNNI");		/*1 << 11*/
		AddLineQueue("bit_avx512_bitalg EQU BIT_AVX512_BITALG");	/*1 << 12*/
		AddLineQueue("bit_avx512_vpopcntdq EQU BIT_AVX512_VPOPCNTDQ");/*1 << 14*/
		AddLineQueue("bit_rdpid EQU BIT_RDPID");					/*1 << 22*/

		/* %eax=07H, %edx */
		AddLineQueue("bit_avx512_4vnniw EQU BIT_AVX512_4VNNIW");	/*1 << 2*/
		AddLineQueue("bit_avx512_4fmaps EQU BIT_AVX512_4FMAPS");	/*1 << 3*/

		/* %eax=80000001H, %ecx */
		AddLineQueue("bit_lahf EQU BIT_LAHF");				/*1 << 0*/
		AddLineQueue("bit_lzcnt EQU BIT_LZCNT");			/*1 << 5*/
		AddLineQueue("bit_abm EQU BIT_ABM");				/*1 << 5*/
		AddLineQueue("bit_sse4a EQU BIT_SSE4a");			/*1 << 6*/
		AddLineQueue("bit_prefetchw EQU BIT_PREFETCHW");	/*1 << 8*/
		AddLineQueue("bit_xop EQU BIT_XOP");				/*1 << 11*/
		AddLineQueue("bit_lwp EQU BIT_LWP");				/*1 << 15*/
		AddLineQueue("bit_fma4 EQU BIT_FMA4");				/*1 << 16*/
		AddLineQueue("bit_tbm EQU BIT_TBM");				/*1 << 21*/
		AddLineQueue("bit_mwaitx EQU BIT_MWAITX");			/*1 << 29*/

		/* %eax=80000001H, %edx */
		AddLineQueue("bit_syscall EQU BIT_SYSCALL");		/*1 << 11*/
		AddLineQueue("bit_mmxext EQU BIT_MMXEXT");			/*1 << 22*/
		AddLineQueue("bit_rdtscp EQU BIT_RDTSCP");			/*1 << 27*/
		AddLineQueue("bit_3dnowext EQU BIT_3DNOWEXT");		/*1 << 30*/
		AddLineQueue("bit_3dnow EQU BIT_3DNOW");			/*1 << 31*/
	
		/*
		 * Compare predicates for scalar and packed compare intrinsic functions
		 */
		/*No AVX*/
		AddLineQueue("cmpp_eq EQU CMPP_EQ");
		AddLineQueue("cmpp_lt EQU CMPP_LT");
		AddLineQueue("cmpp_le EQU CMPP_LE");
		AddLineQueue("cmpp_unord EQU CMPP_UNORD");
		AddLineQueue("cmpp_neq EQU CMPP_NEQ");
		AddLineQueue("cmpp_nlt EQU CMPP_NLT");
		AddLineQueue("cmpp_nle EQU CMPP_NLE");
		AddLineQueue("cmpp_ord EQU CMPP_ORD");

		/*With AVX*/
		AddLineQueue("cmp_eq_oq EQU CMP_EQ_OQ");		/* Equal (ordered, nonsignaling)               */
		AddLineQueue("cmp_lt_os EQU CMP_LT_OS");		/* Less-than (ordered, signaling)              */
		AddLineQueue("cmp_le_os EQU CMP_LE_OS");		/* Less-than-or-equal (ordered, signaling)     */
		AddLineQueue("cmp_unord_q EQU CMP_UNORD_Q");	/* Unordered (nonsignaling)                    */
		AddLineQueue("cmp_neq_uq EQU CMP_NEQ_UQ");		/* Not-equal (unordered, nonsignaling)         */
		AddLineQueue("cmp_nlt_us EQU CMP_NLT_US");		/* Not-less-than (unordered, signaling)        */
		AddLineQueue("cmp_nle_us EQU CMP_NLE_US");		/* Not-less-than-or-equal (unordered, signaling) */
		AddLineQueue("cmp_ord_q EQU CMP_ORD_Q");		/* Ordered (nonsignaling)                      */
		AddLineQueue("cmp_eq_uq EQU CMP_EQ_UQ");		/* Equal (unordered, non-signaling)            */
		AddLineQueue("cmp_nge_us EQU CMP_NGE_US");		/* Not-greater-than-or-equal (unordered, signaling) */
		AddLineQueue("cmp_ngt_us EQU CMP_NGT_US");		/* Not-greater-than (unordered, signaling)     */
		AddLineQueue("cmp_false_oq EQU CMP_FALSE_OQ");	/* False (ordered, nonsignaling)               */
		AddLineQueue("cmp_neq_oq EQU CMP_NEQ_OQ");		/* Not-equal (ordered, non-signaling)          */
		AddLineQueue("cmp_ge_os EQU CMP_GE_OS");		/* Greater-than-or-equal (ordered, signaling)  */
		AddLineQueue("cmp_gt_os EQU CMP_GT_OS");		/* Greater-than (ordered, signaling)           */
		AddLineQueue("cmp_true_uq EQU CMP_TRUE_UQ");	/* True (unordered, non-signaling)             */
		AddLineQueue("cmp_eq_os EQU CMP_EQ_OS");		/* Equal (ordered, signaling)                  */
		AddLineQueue("cmp_lt_oq EQU CMP_LT_OQ");		/* Less-than (ordered, nonsignaling)           */
		AddLineQueue("cmp_le_oq EQU CMP_LE_OQ");		/* Less-than-or-equal (ordered, nonsignaling)  */
		AddLineQueue("cmp_unord_s EQU CMP_UNORD_S");	/* Unordered (signaling)                       */
		AddLineQueue("cmp_neq_us EQU CMP_NEQ_US");		/* Not-equal (unordered, signaling)            */
		AddLineQueue("cmp_nlt_uq EQU CMP_NLT_UQ");		/* Not-less-than (unordered, nonsignaling)     */
		AddLineQueue("cmp_nle_uq EQU CMP_NLE_UQ");		/* Not-less-than-or-equal (unordered, nonsignaling) */
		AddLineQueue("cmp_ord_s EQU CMP_ORD_S");		/* Ordered (signaling)                         */
		AddLineQueue("cmp_eq_us EQU CMP_EQ_US");		/* Equal (unordered, signaling)                */
		AddLineQueue("cmp_nge_uq EQU CMP_NGE_UQ");		/* Not-greater-than-or-equal (unordered, nonsignaling) */
		AddLineQueue("cmp_ngt_uq EQU CMP_NGT_UQ");		/* Not-greater-than (unordered, nonsignaling)  */
		AddLineQueue("cmp_false_os EQU CMP_FALSE_OS");	/* False (ordered, signaling)                  */
		AddLineQueue("cmp_neq_os EQU CMP_NEQ_OS");		/* Not-equal (ordered, signaling)              */
		AddLineQueue("cmp_ge_oq EQU CMP_GE_OQ");		/* Greater-than-or-equal (ordered, nonsignaling) */
		AddLineQueue("cmp_gt_oq EQU CMP_GT_OQ");		/* Greater-than (ordered, nonsignaling)        */
		AddLineQueue("cmp_true_us EQU CMP_TRUE_US");	/* True (unordered, signaling)                 */

		/*AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");
		AddLineQueue(" EQU ");*/

	}
}

/*
Create the built-in 64bit macro library
This is called once initially as the macros always exist
*/
void Initx86AutoMacros64(void)
{
	struct dsym *mac;
	uint_32 i = 0;
	uint_32 j = 0;
	uint_32 start_pos = 0;
	char  *srcLines[512]; // NB: 512 is the max number of lines of macro code per macro.

	   //						 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22  23  24 25 26 27 28  29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58  59 60 61  62   63   64
	uint_32 x86macroLen[] =		{9, 9, 4, 4, 4, 4, 4, 9, 9, 4, 4, 4, 4, 4, 9, 9, 4, 4, 4, 4, 7, 13, 13, 7, 7, 7, 7, 10, 5, 2, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6/*, 256, 10, 6, 6, 106, 137, 7*/}; // Count of individual lines of macro-body code.
	char *x86macCode[] = {
	/*1 ALIGNSIZE_T*/			"size_talignment TEXTEQU <>","IFDEF __x64__","size_talignment CATSTR size_talignment, <ALIGN 8>","ENDIF","IFDEF __x32__","size_talignment CATSTR size_talignment, <ALIGN 4>","ENDIF","size_talignment","ENDM",NULL,
	/*2 ALIGNPTR*/				"ptr_talignment TEXTEQU <>","IFDEF __x64__","ptr_talignment CATSTR ptr_talignment, <ALIGN 8>","ENDIF","IFDEF __x32__","ptr_talignment CATSTR ptr_talignment, <ALIGN 4>","ENDIF","ptr_talignment","ENDM",NULL,
	/*3 ALIGNMM*/				"mmalignment TEXTEQU <>","mmalignment CATSTR mmalignment, <ALIGN 8>","mmalignment","ENDM",NULL,
	/*4 ALIGNXMM*/				"xmmalignment TEXTEQU <>","xmmalignment CATSTR xmmalignment, <ALIGN 16>","xmmalignment","ENDM",NULL,
	/*5 ALIGNYMM*/				"ymmalignment TEXTEQU <>","ymmalignment CATSTR ymmalignment, <ALIGN 32>","ymmalignment","ENDM",NULL,
	/*6 ALIGNZMM*/				"zmmalignment TEXTEQU <>","zmmalignment CATSTR zmmalignment, <ALIGN 64>","zmmalignment","ENDM",NULL,
	/*7 ALIGNFIELD*/			"field_option_alignment TEXTEQU <>","field_option_alignment CATSTR field_option_alignment, <option fieldalign:AlignSize>","field_option_alignment","ENDM",NULL,
	/*8 ALIGNSIZE_TFIELD*/		"size_tfield_option_alignment TEXTEQU <>","IFDEF __x64__","size_tfield_option_alignment CATSTR size_tfield_option_alignment, <option fieldalign:8>","ENDIF","IFDEF __x32__","size_tfield_option_alignment CATSTR size_tfield_option_alignment, <option fieldalign:4>","ENDIF","size_tfield_option_alignment","ENDM",NULL,
	/*9 ALIGNPTRFIELD*/			"ptr_field_option_alignment TEXTEQU <>","IFDEF __x64__","ptr_field_option_alignment CATSTR ptr_field_option_alignment, <option fieldalign:8>","ENDIF","IFDEF __x32__","ptr_field_option_alignment CATSTR ptr_field_option_alignment, <option fieldalign:4>","ENDIF","ptr_field_option_alignment","ENDM",NULL,
	/*10 ALIGNMMFIELD*/			"mm_field_option_alignment TEXTEQU <>","mm_field_option_alignment CATSTR mm_field_option_alignment, <option fieldalign:MM_SIZE>","mm_field_option_alignment","ENDM",NULL,
	/*11 ALIGNXMMFIELD*/		"xmm_field_option_alignment TEXTEQU <>","xmm_field_option_alignment CATSTR xmm_field_option_alignment, <option fieldalign:XMM_SIZE>","xmm_field_option_alignment","ENDM",NULL,
	/*12 ALIGNYMMFIELD*/		"ymm_field_option_alignment TEXTEQU <>","ymm_field_option_alignment CATSTR ymm_field_option_alignment, <option fieldalign:YMM_SIZE>","ymm_field_option_alignment","ENDM",NULL,
	/*13 ALIGNZMMFIELD*/		"zmm_field_option_alignment TEXTEQU <>","zmm_field_option_alignment CATSTR zmm_field_option_alignment, <option fieldalign:ZMM_SIZE>","zmm_field_option_alignment","ENDM",NULL,
	/*14 ALIGNPROC*/			"proc_option_alignment TEXTEQU <>","proc_option_alignment CATSTR proc_option_alignment, <option procalign:AlignSize>","proc_option_alignment","ENDM",NULL,
	/*15 ALIGNSIZE_TPROC*/		"size_tproc_option_alignment TEXTEQU <>","IFDEF __x64__","size_tproc_option_alignment CATSTR size_tproc_option_alignment, <option procalign:8>","ENDIF","IFDEF __x32__","size_tproc_option_alignment CATSTR size_tproc_option_alignment, <option procalign:4>","ENDIF","size_tproc_option_alignment","ENDM",NULL,
	/*16 ALIGNPTRPROC*/			"ptr_proc_option_alignment TEXTEQU <>","IFDEF __x64__","ptr_proc_option_alignment CATSTR ptr_proc_option_alignment, <option procalign:8>","ENDIF","IFDEF __x32__","ptr_proc_option_alignment CATSTR ptr_proc_option_alignment, <option procalign:4>","ENDIF","ptr_proc_option_alignment","ENDM",NULL,
	/*17 ALIGNMMPROC*/			"mm_proc_option_alignment TEXTEQU <>","mm_proc_option_alignment CATSTR mm_proc_option_alignment, <option procalign:MM_SIZE>","mm_proc_option_alignment","ENDM",NULL,
	/*18 ALIGNXMMPROC*/			"xmm_proc_option_alignment TEXTEQU <>","xmm_proc_option_alignment CATSTR xmm_proc_option_alignment, <option procalign:XMM_SIZE>","xmm_proc_option_alignment","ENDM",NULL,
	/*19 ALIGNYMMPROC*/			"ymm_proc_option_alignment TEXTEQU <>","ymm_proc_option_alignment CATSTR ymm_proc_option_alignment, <option procalign:YMM_SIZE>","ymm_proc_option_alignment","ENDM",NULL,
	/*20 ALIGNZMMPROC*/			"zmm_proc_option_alignment TEXTEQU <>","zmm_proc_option_alignment CATSTR zmm_proc_option_alignment, <option procalign:ZMM_SIZE>","zmm_proc_option_alignment","ENDM",NULL,
	/*21 ALIGNFIELDPROC*/		"pfield_option_alignment TEXTEQU <>","fproc_option_alignment TEXTEQU <>","pfield_option_alignment CATSTR pfield_option_alignment, <option fieldalign:AlignSize>","fproc_option_alignment CATSTR fproc_option_alignment, <option procalign:AlignSize>","pfield_option_alignment","fproc_option_alignment","ENDM",NULL,
	/*22 ALIGNSIZE_TFIELDPROC*/	"size_tpfield_option_alignment TEXTEQU <>","size_tfproc_option_alignment TEXTEQU <>","IFDEF __x64__","size_tpfield_option_alignment CATSTR size_tpfield_option_alignment, <option fieldalign:8>","size_tfproc_option_alignment CATSTR size_tfproc_option_alignment, <option procalign:8>","ENDIF","IFDEF __x32__","size_tpfield_option_alignment CATSTR size_tpfield_option_alignment, <option fieldalign:4>","size_tfproc_option_alignment CATSTR size_tfproc_option_alignment, <option procalign:4>","ENDIF","size_tpfield_option_alignment","size_tfproc_option_alignment","ENDM",NULL,
	/*23 ALIGNPTRFIELDPROC*/	"ptr_pfield_option_alignment TEXTEQU <>","ptr_fproc_option_alignment TEXTEQU <>","IFDEF __x64__","ptr_pfield_option_alignment CATSTR ptr_pfield_option_alignment, <option fieldalign:8>","ptr_fproc_option_alignment CATSTR ptr_fproc_option_alignment, <option procalign:8>","ENDIF","IFDEF __x32__","ptr_pfield_option_alignment CATSTR ptr_pfield_option_alignment, <option fieldalign:4>","ptr_fproc_option_alignment CATSTR ptr_fproc_option_alignment, <option procalign:4>","ENDIF","ptr_pfield_option_alignment","ptr_fproc_option_alignment","ENDM",NULL,
	/*24 ALIGNMMFIELDPROC*/		"mm_pfield_option_alignment TEXTEQU <>","mm_fproc_option_alignment TEXTEQU <>","mm_pfield_option_alignment CATSTR mm_pfield_option_alignment, <option fieldalign:MM_SIZE>","mm_fproc_option_alignment CATSTR mm_fproc_option_alignment, <option procalign:MM_SIZE>","mm_pfield_option_alignment","mm_fproc_option_alignment","ENDM",NULL,
	/*25 ALIGNXMMFIELDPROC*/	"xmm_pfield_option_alignment TEXTEQU <>","xmm_fproc_option_alignment TEXTEQU <>","xmm_pfield_option_alignment CATSTR xmm_pfield_option_alignment, <option fieldalign:XMM_SIZE>","xmm_fproc_option_alignment CATSTR xmm_fproc_option_alignment, <option procalign:XMM_SIZE>","xmm_pfield_option_alignment","xmm_fproc_option_alignment","ENDM",NULL,
	/*26 ALIGNYMMFIELDPROC*/	"ymm_pfield_option_alignment TEXTEQU <>","ymm_fproc_option_alignment TEXTEQU <>","ymm_pfield_option_alignment CATSTR ymm_pfield_option_alignment, <option fieldalign:YMM_SIZE>","ymm_fproc_option_alignment CATSTR ymm_fproc_option_alignment, <option procalign:YMM_SIZE>","ymm_pfield_option_alignment","ymm_fproc_option_alignment","ENDM",NULL,
	/*27 ALIGNZMMFIELDPROC*/	"zmm_pfield_option_alignment TEXTEQU <>","zmm_fproc_option_alignment TEXTEQU <>","zmm_pfield_option_alignment CATSTR zmm_pfield_option_alignment, <option fieldalign:ZMM_SIZE>","zmm_fproc_option_alignment CATSTR zmm_fproc_option_alignment, <option procalign:ZMM_SIZE>","zmm_pfield_option_alignment","zmm_fproc_option_alignment","ENDM",NULL,
	/*28 FUNCSTART*/			"_curfunctionName_ TEXTEQU <functionName>","fnexproto TEXTEQU <>","fnexproto CATSTR fnexproto, <&functionName&>","fnexproto CATSTR fnexproto, < PROTO >, <&callconvType&>, < >, <(&retType&)>, < >, <&args&>","fnexproc TEXTEQU <>","fnexproc CATSTR fnexproc, <&functionName&>","fnexproc CATSTR fnexproc, < PROC >, <&callconvType&>, < >, <(&retType&)>, < >, <FRAME>, < >, <&usesStr&>, < >, <&args&>","fnexproto","fnexproc","ENDM",NULL,
	/*29 FUNCEND*/				"fnexfuncend TEXTEQU <>","fnexfuncend CATSTR fnexfuncend, _curfunctionName_","fnexfuncend CATSTR fnexfuncend, < ENDP>","fnexfuncend","ENDM",NULL,
	/*30 SHUFFLE4*/				"EXITM %((V3 shl 6) or (V2 shl 4) or (V1 shl 2) or (V0))","ENDM",NULL,
	/*31 SHUFFLER4*/			"EXITM %((V0) or (V1 shl 2) or (V2 shl 4) or (V3 shl 6))","ENDM",NULL,
	/*32 SHUFFLE2*/				"EXITM %((V1 shl 1) or (V0))","ENDM",NULL,
	/*33 SHUFFLER2*/			"EXITM %((V0) or (V1 shl 1))","ENDM",NULL,
	/*34 V64CI*/				"mm64fnex TEXTEQU <>","mm64fnex CATSTR mm64fnex, <&functionName&>","public mm64fnex","mm64fnex CATSTR mm64fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1 } >","mm64fnex","ENDM",NULL,
	/*35 V64CI64*/				"mm64fnex64 TEXTEQU <>","mm64fnex64 CATSTR mm64fnex64, <&functionName&>","public mm64fnex64","mm64fnex64 CATSTR mm64fnex64, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16, V17, V18, V19, V20, V21, V22, V23, V24, V25, V26, V27, V28, V29, V30, V31, V32, V33, V34, V35, V36, V37, V38, V39, V40, V41, V42, V43, V44, V45, V46, V47, V48, V49, V50, V51, V52, V53, V54, V55, V56, V57, V58, V59, V60, V61, V62, V63, V64 } >","mm64fnex64","ENDM",NULL,
	/*36 V32CI*/				"mm32fnex TEXTEQU <>","mm32fnex CATSTR mm32fnex, <&functionName&>","public mm32fnex","mm32fnex CATSTR mm32fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1 } >","mm32fnex","ENDM",NULL,
	/*37 V32CI32*/				"mm32fnex32 TEXTEQU <>","mm32fnex32 CATSTR mm32fnex32, <&functionName&>","public mm32fnex32","mm32fnex32 CATSTR mm32fnex32, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16, V17, V18, V19, V20, V21, V22, V23, V24, V25, V26, V27, V28, V29, V30, V31, V32 } >","mm32fnex32","ENDM",NULL,
	/*38 V16CI*/				"mm16fnex TEXTEQU <>","mm16fnex CATSTR mm16fnex, <&functionName&>","public mm16fnex","mm16fnex CATSTR mm16fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1 } >","mm16fnex","ENDM",NULL,
	/*39 V16CI16*/				"mm16fnex16 TEXTEQU <>","mm16fnex16 CATSTR mm16fnex16, <&functionName&>","public mm16fnex16","mm16fnex16 CATSTR mm16fnex16, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16 } >","mm16fnex16","ENDM",NULL,
	/*40 V8CI*/					"mm8fnex TEXTEQU <>","mm8fnex CATSTR mm8fnex, <&functionName&>","public mm8fnex","mm8fnex CATSTR mm8fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1 } >","mm8fnex","ENDM",NULL,
	/*41 V8CI8*/				"mm8fnex8 TEXTEQU <>","mm8fnex8 CATSTR mm8fnex8, <&functionName&>","public mm8fnex8","mm8fnex8 CATSTR mm8fnex8, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8 } >","mm8fnex8","ENDM",NULL,
	/*42 V4CI*/					"mm4fnex TEXTEQU <>","mm4fnex CATSTR mm4fnex, <&functionName&>","public mm4fnex","mm4fnex CATSTR mm4fnex, < vectorType>,  < { V1, V1, V1, V1 } >","mm4fnex","ENDM",NULL,
	/*43 V4CI4*/				"mm4fnex4 TEXTEQU <>","mm4fnex4 CATSTR mm4fnex4, <&functionName&>","public mm4fnex4","mm4fnex4 CATSTR mm4fnex4, < vectorType>, < { V1, V2, V3, V4 } >","mm4fnex4","ENDM",NULL,
	/*44 V2CI*/					"mm2fnex TEXTEQU <>","mm2fnex CATSTR mm2fnex, <&functionName&>","public mm2fnex","mm2fnex CATSTR mm2fnex, < vectorType>,  < { V1, V1 } >","mm2fnex","ENDM",NULL,
	/*45 V2CI2*/				"mm2fnex2 TEXTEQU <>","mm2fnex2 CATSTR mm2fnex2, <&functionName&>","public mm2fnex2","mm2fnex2 CATSTR mm2fnex2, < vectorType>, < { V1, V2 } >","mm2fnex2","ENDM",NULL,
	/*46 VV64CI*/				"mm64fnex TEXTEQU <>","mm64fnex CATSTR mm64fnex, <&functionName&>","public mm64fnex","mm64fnex CATSTR mm64fnex, < vectorType>,  < { <V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1> } >","mm64fnex","ENDM",NULL,
	/*47 VV64CI64*/				"mm64fnex64 TEXTEQU <>","mm64fnex64 CATSTR mm64fnex64, <&functionName&>","public mm64fnex64","mm64fnex64 CATSTR mm64fnex64, < vectorType>, < { <V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16, V17, V18, V19, V20, V21, V22, V23, V24, V25, V26, V27, V28, V29, V30, V31, V32, V33, V34, V35, V36, V37, V38, V39, V40, V41, V42, V43, V44, V45, V46, V47, V48, V49, V50, V51, V52, V53, V54, V55, V56, V57, V58, V59, V60, V61, V62, V63, V64> } >","mm64fnex64","ENDM",NULL,
	/*48 VV32CI*/				"mm32fnex TEXTEQU <>","mm32fnex CATSTR mm32fnex, <&functionName&>","public mm32fnex","mm32fnex CATSTR mm32fnex, < vectorType>,  < { <V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1> } >","mm32fnex","ENDM",NULL,
	/*49 VV32CI32*/				"mm32fnex32 TEXTEQU <>","mm32fnex32 CATSTR mm32fnex32, <&functionName&>","public mm32fnex32","mm32fnex32 CATSTR mm32fnex32, < vectorType>, < { <V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16, V17, V18, V19, V20, V21, V22, V23, V24, V25, V26, V27, V28, V29, V30, V31, V32> } >","mm32fnex32","ENDM",NULL,
	/*50 VV16CI*/				"mm16fnex TEXTEQU <>","mm16fnex CATSTR mm16fnex, <&functionName&>","public mm16fnex","mm16fnex CATSTR mm16fnex, < vectorType>,  < { <V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1> } >","mm16fnex","ENDM",NULL,
	/*51 VV16CI16*/				"mm16fnex16 TEXTEQU <>","mm16fnex16 CATSTR mm16fnex16, <&functionName&>","public mm16fnex16","mm16fnex16 CATSTR mm16fnex16, < vectorType>, < { <V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16> } >","mm16fnex16","ENDM",NULL,
	/*52 VV8CI*/				"mm8fnex TEXTEQU <>","mm8fnex CATSTR mm8fnex, <&functionName&>","public mm8fnex","mm8fnex CATSTR mm8fnex, < vectorType>,  < { <V1, V1, V1, V1, V1, V1, V1, V1> } >","mm8fnex","ENDM",NULL,
	/*53 VV8CI8*/				"mm8fnex8 TEXTEQU <>","mm8fnex8 CATSTR mm8fnex8, <&functionName&>","public mm8fnex8","mm8fnex8 CATSTR mm8fnex8, < vectorType>, < { <V1, V2, V3, V4, V5, V6, V7, V8> } >","mm8fnex8","ENDM",NULL,
	/*54 VV4CI*/				"mm4fnex TEXTEQU <>","mm4fnex CATSTR mm4fnex, <&functionName&>","public mm4fnex","mm4fnex CATSTR mm4fnex, < vectorType>,  < { <V1, V1, V1, V1> } >","mm4fnex","ENDM",NULL,
	/*55 VV4CI4*/				"mm4fnex4 TEXTEQU <>","mm4fnex4 CATSTR mm4fnex4, <&functionName&>","public mm4fnex4","mm4fnex4 CATSTR mm4fnex4, < vectorType>, < { <V1, V2, V3, V4> } >","mm4fnex4","ENDM",NULL,
	/*56 VV2CI*/				"mm2fnex TEXTEQU <>","mm2fnex CATSTR mm2fnex, <&functionName&>","public mm2fnex","mm2fnex CATSTR mm2fnex, < vectorType>,  < { <V1, V1> } >","mm2fnex","ENDM",NULL,
	/*57 VV2CI2*/				"mm2fnex2 TEXTEQU <>","mm2fnex2 CATSTR mm2fnex2, <&functionName&>","public mm2fnex2","mm2fnex2 CATSTR mm2fnex2, < vectorType>, < { <V1, V2> } >","mm2fnex2","ENDM",NULL/*,*/
	/* */			/*"","","","","","","","",NULL,*/
	};

	/* Compile Macros */
	for (i = 0; i < X86MACRO_COUNT64; i++)
	{
		for (j = 0; j < x86macroLen[i]; j++)
		{
			srcLines[j] = (char *)malloc(MAX_LINE_LEN);
			if (srcLines[j])
				strcpy(srcLines[j], x86macCode[(start_pos + j)]);
		}
		mac = CreateMacro(x86macName64[i]);
		ModuleInfo.token_count = Tokenize(x86macDef64[i], 0, ModuleInfo.tokenarray, 0);
		StoreAutoMacro(mac, 2, ModuleInfo.tokenarray, TRUE, srcLines, 0, x86macroLen[i]);
		start_pos += x86macroLen[i] + 1;
	}
}
