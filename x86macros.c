
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

	AddLineQueue("IFDEF WIN64");
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
	/* 64bits*/
	AddLineQueue("qret TEXTEQU <rax>");
	AddLineQueue("qreturn TEXTEQU <rax>");
	AddLineQueue("qparam1 TEXTEQU <rcx>");
	AddLineQueue("qparam2 TEXTEQU <rdx>");
	AddLineQueue("qparam3 TEXTEQU <r8>");
	AddLineQueue("qparam4 TEXTEQU <r9>");
	AddLineQueue("qparam5 TEXTEQU <[rsp+40]>");
	AddLineQueue("qparam6 TEXTEQU <[rsp+48]>");
	AddLineQueue("qparam7 TEXTEQU <[rsp+56]>");
	AddLineQueue("qparam8 TEXTEQU <[rsp+64]>");
	AddLineQueue("qparam9 TEXTEQU <[rsp+72]>");
	AddLineQueue("qparam10 TEXTEQU <[rsp+80]>");
	AddLineQueue("qparam11 TEXTEQU <[rsp+88]>");
	AddLineQueue("qparam12 TEXTEQU <[rsp+96]>");
	AddLineQueue("qparam13 TEXTEQU <[rsp+104]>");
	AddLineQueue("qparam14 TEXTEQU <[rsp+112]>");
	AddLineQueue("qparam15 TEXTEQU <[rsp+120]>");
	AddLineQueue("qparam16 TEXTEQU <[rsp+128]>");
	AddLineQueue("qparam17 TEXTEQU <[rsp+136]>");
	AddLineQueue("qparam18 TEXTEQU <[rsp+144]>");
	AddLineQueue("qparam19 TEXTEQU <[rsp+152]>");
	AddLineQueue("qparam20 TEXTEQU <[rsp+160]>");
	AddLineQueue("qparam21 TEXTEQU <[rsp+168]>");
	AddLineQueue("qparam22 TEXTEQU <[rsp+176]>");
	AddLineQueue("qparam23 TEXTEQU <[rsp+184]>");
	AddLineQueue("qparam24 TEXTEQU <[rsp+192]>");
	AddLineQueue("qparam25 TEXTEQU <[rsp+200]>");
	AddLineQueue("qparam26 TEXTEQU <[rsp+208]>");
	AddLineQueue("qparam27 TEXTEQU <[rsp+216]>");
	AddLineQueue("qparam28 TEXTEQU <[rsp+224]>");
	AddLineQueue("qparam29 TEXTEQU <[rsp+232]>");
	AddLineQueue("qparam30 TEXTEQU <[rsp+240]>");
	AddLineQueue("qparam31 TEXTEQU <[rsp+248]>");
	AddLineQueue("qparam32 TEXTEQU <[rsp+256]>");
	AddLineQueue("qparam33 TEXTEQU <[rsp+264]>");
	AddLineQueue("qparam34 TEXTEQU <[rsp+272]>");
	AddLineQueue("qparam35 TEXTEQU <[rsp+280]>");
	AddLineQueue("qparam36 TEXTEQU <[rsp+288]>");
	AddLineQueue("qparam37 TEXTEQU <[rsp+296]>");
	AddLineQueue("qparam38 TEXTEQU <[rsp+304]>");
	AddLineQueue("qparam39 TEXTEQU <[rsp+312]>");
	AddLineQueue("qparam40 TEXTEQU <[rsp+320]>");
	AddLineQueue("qparam41 TEXTEQU <[rsp+328]>");
	AddLineQueue("qparam42 TEXTEQU <[rsp+336]>");
	AddLineQueue("qparam43 TEXTEQU <[rsp+344]>");
	AddLineQueue("qparam44 TEXTEQU <[rsp+352]>");
	AddLineQueue("qparam45 TEXTEQU <[rsp+360]>");
	AddLineQueue("qparam46 TEXTEQU <[rsp+368]>");
	AddLineQueue("qparam47 TEXTEQU <[rsp+376]>");
	AddLineQueue("qparam48 TEXTEQU <[rsp+384]>");
	AddLineQueue("qparam49 TEXTEQU <[rsp+392]>");
	AddLineQueue("qparam50 TEXTEQU <[rsp+400]>");
	AddLineQueue("qparam51 TEXTEQU <[rsp+408]>");
	AddLineQueue("qparam52 TEXTEQU <[rsp+416]>");
	AddLineQueue("qparam53 TEXTEQU <[rsp+424]>");
	AddLineQueue("qparam54 TEXTEQU <[rsp+432]>");
	AddLineQueue("qparam55 TEXTEQU <[rsp+440]>");
	AddLineQueue("qparam56 TEXTEQU <[rsp+448]>");
	AddLineQueue("qparam57 TEXTEQU <[rsp+456]>");
	AddLineQueue("qparam58 TEXTEQU <[rsp+464]>");
	AddLineQueue("qparam69 TEXTEQU <[rsp+472]>");
	AddLineQueue("qparam60 TEXTEQU <[rsp+480]>");
	AddLineQueue("qparam61 TEXTEQU <[rsp+488]>");
	AddLineQueue("qparam62 TEXTEQU <[rsp+496]>");
	AddLineQueue("qparam63 TEXTEQU <[rsp+504]>");
	AddLineQueue("qparam64 TEXTEQU <[rsp+512]>");
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
	AddLineQueue("ENDIF"); /*WIN64*/

	AddLineQueue("IFDEF UNIX64");
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
	/* 64bits*/
	AddLineQueue("qret TEXTEQU <rax>");
	AddLineQueue("qreturn TEXTEQU <rax>");
	AddLineQueue("qparam1 TEXTEQU <rdi>");
	AddLineQueue("qparam2 TEXTEQU <rsi>");
	AddLineQueue("qparam3 TEXTEQU <rdx>");
	AddLineQueue("qparam4 TEXTEQU <rcx>");
	AddLineQueue("qparam5 TEXTEQU <r8>");
	AddLineQueue("qparam6 TEXTEQU <r9>");
	AddLineQueue("qparam7 TEXTEQU <[rsp+56]>");
	AddLineQueue("qparam8 TEXTEQU <[rsp+64]>");
	AddLineQueue("qparam9 TEXTEQU <[rsp+72]>");
	AddLineQueue("qparam10 TEXTEQU <[rsp+80]>");
	AddLineQueue("qparam11 TEXTEQU <[rsp+88]>");
	AddLineQueue("qparam12 TEXTEQU <[rsp+96]>");
	AddLineQueue("qparam13 TEXTEQU <[rsp+104]>");
	AddLineQueue("qparam14 TEXTEQU <[rsp+112]>");
	AddLineQueue("qparam15 TEXTEQU <[rsp+120]>");
	AddLineQueue("qparam16 TEXTEQU <[rsp+128]>");
	AddLineQueue("qparam17 TEXTEQU <[rsp+136]>");
	AddLineQueue("qparam18 TEXTEQU <[rsp+144]>");
	AddLineQueue("qparam19 TEXTEQU <[rsp+152]>");
	AddLineQueue("qparam20 TEXTEQU <[rsp+160]>");
	AddLineQueue("qparam21 TEXTEQU <[rsp+168]>");
	AddLineQueue("qparam22 TEXTEQU <[rsp+176]>");
	AddLineQueue("qparam23 TEXTEQU <[rsp+184]>");
	AddLineQueue("qparam24 TEXTEQU <[rsp+192]>");
	AddLineQueue("qparam25 TEXTEQU <[rsp+200]>");
	AddLineQueue("qparam26 TEXTEQU <[rsp+208]>");
	AddLineQueue("qparam27 TEXTEQU <[rsp+216]>");
	AddLineQueue("qparam28 TEXTEQU <[rsp+224]>");
	AddLineQueue("qparam29 TEXTEQU <[rsp+232]>");
	AddLineQueue("qparam30 TEXTEQU <[rsp+240]>");
	AddLineQueue("qparam31 TEXTEQU <[rsp+248]>");
	AddLineQueue("qparam32 TEXTEQU <[rsp+256]>");
	AddLineQueue("qparam33 TEXTEQU <[rsp+264]>");
	AddLineQueue("qparam34 TEXTEQU <[rsp+272]>");
	AddLineQueue("qparam35 TEXTEQU <[rsp+280]>");
	AddLineQueue("qparam36 TEXTEQU <[rsp+288]>");
	AddLineQueue("qparam37 TEXTEQU <[rsp+296]>");
	AddLineQueue("qparam38 TEXTEQU <[rsp+304]>");
	AddLineQueue("qparam39 TEXTEQU <[rsp+312]>");
	AddLineQueue("qparam40 TEXTEQU <[rsp+320]>");
	AddLineQueue("qparam41 TEXTEQU <[rsp+328]>");
	AddLineQueue("qparam42 TEXTEQU <[rsp+336]>");
	AddLineQueue("qparam43 TEXTEQU <[rsp+344]>");
	AddLineQueue("qparam44 TEXTEQU <[rsp+352]>");
	AddLineQueue("qparam45 TEXTEQU <[rsp+360]>");
	AddLineQueue("qparam46 TEXTEQU <[rsp+368]>");
	AddLineQueue("qparam47 TEXTEQU <[rsp+376]>");
	AddLineQueue("qparam48 TEXTEQU <[rsp+384]>");
	AddLineQueue("qparam49 TEXTEQU <[rsp+392]>");
	AddLineQueue("qparam50 TEXTEQU <[rsp+400]>");
	AddLineQueue("qparam51 TEXTEQU <[rsp+408]>");
	AddLineQueue("qparam52 TEXTEQU <[rsp+416]>");
	AddLineQueue("qparam53 TEXTEQU <[rsp+424]>");
	AddLineQueue("qparam54 TEXTEQU <[rsp+432]>");
	AddLineQueue("qparam55 TEXTEQU <[rsp+440]>");
	AddLineQueue("qparam56 TEXTEQU <[rsp+448]>");
	AddLineQueue("qparam57 TEXTEQU <[rsp+456]>");
	AddLineQueue("qparam58 TEXTEQU <[rsp+464]>");
	AddLineQueue("qparam69 TEXTEQU <[rsp+472]>");
	AddLineQueue("qparam60 TEXTEQU <[rsp+480]>");
	AddLineQueue("qparam61 TEXTEQU <[rsp+488]>");
	AddLineQueue("qparam62 TEXTEQU <[rsp+496]>");
	AddLineQueue("qparam63 TEXTEQU <[rsp+504]>");
	AddLineQueue("qparam64 TEXTEQU <[rsp+512]>");
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
	AddLineQueue("ENDIF"); /*UNIX64*/

	AddLineQueue("IFDEF __x64__");
	AddLineQueue("SIZE_T TEXTEQU <QWORD>");
	AddLineQueue("ISIZE_T TEXTEQU <DQ>");
	AddLineQueue("PSIZE_T TEXTEQU <PTR QWORD>");
	AddLineQueue("SIZE_TP TEXTEQU <QWORD PTR>");
	AddLineQueue("SIZE_T_SIZE EQU 8");
	AddLineQueue("PTR_SIZE EQU 8");
	AddLineQueue("REG_SIZE EQU 8");
	AddLineQueue("ENDIF"); /*__x64__*/

	AddLineQueue("IFDEF __x32__");
	AddLineQueue("SIZE_T TEXTEQU <DWORD>");
	AddLineQueue("ISIZE_T TEXTEQU <DD>");
	AddLineQueue("PSIZE_T TEXTEQU <PTR DWORD>");
	AddLineQueue("SIZE_TP TEXTEQU <DWORD PTR>");
	AddLineQueue("SIZE_T_SIZE EQU 4");
	AddLineQueue("PTR_SIZE EQU 4");
	AddLineQueue("REG_SIZE EQU 4");
	AddLineQueue("ENDIF"); /*__x32__*/

	AddLineQueue("BYTE_SIZE EQU 1");
	AddLineQueue("CHAR_SIZE EQU 1");
	AddLineQueue("INT8_SIZE EQU 1");
	AddLineQueue("WORD_SIZE EQU 2");
	AddLineQueue("SHORT_SIZE EQU 2");
	AddLineQueue("INT16_SIZE EQU 2");
	AddLineQueue("DWORD_SIZE EQU 4");
	AddLineQueue("LONG_SIZE EQU 4");
	AddLineQueue("INT_SIZE EQU 4");
	AddLineQueue("INT32_SIZE EQU 4");
	AddLineQueue("QWORD_SIZE EQU 8");
	AddLineQueue("LONGLONG_SIZE EQU 8");
	AddLineQueue("INT64_SIZE EQU 8");
	AddLineQueue("REAL4_SIZE EQU 4");
	AddLineQueue("FLOAT_SIZE EQU 4");
	AddLineQueue("REAL8_SIZE EQU 8");
	AddLineQueue("DOUBLE_SIZE EQU 8");

	AddLineQueue("MM_SIZE EQU 8");
	AddLineQueue("M64_SIZE EQU 8");
	AddLineQueue("XMM_SIZE EQU 16");
	AddLineQueue("M128_SIZE EQU 16");
	AddLineQueue("YMM_SIZE EQU 32");
	AddLineQueue("M256_SIZE EQU 32");
	AddLineQueue("ZMM_SIZE EQU 64");
	AddLineQueue("M512_SIZE EQU 64");

	AddLineQueue("FLOAT TEXTEQU <REAL4>");
	AddLineQueue("DOUBLE TEXTEQU <REAL8>");

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

	/* EFLAGS %eax=00H, %ebx=00H */
	AddLineQueue("bit_CPUID EQU 0x00200000");		/*1 << 21*/

	/* %eax=00H, %ecx %ebx */
	AddLineQueue("bit_ntel EQU 0x6c65746e");		/*'GenuineIntel'*/
	AddLineQueue("bit_cAMD EQU 0x444d4163");		/*'AuthenticAMD'*/

	/* %eax=00H, %ebx */
	AddLineQueue("bit_Cent EQU 0x746e6543");		/*'CentaurHauls'*/
	AddLineQueue("bit_VIA EQU 0x20414956");			/*'VIA VIA VIA'*/
	AddLineQueue("bit_Cyri EQU 0x69727943");		/*'CyrixInstead'*/
	AddLineQueue("bit_NexG EQU 0x4778654e");		/*'NexGenDriven'*/

	/* %eax=01H, %ecx */
	AddLineQueue("bit_SSE3 EQU 0x00000001");		/*1 << 0*/
	AddLineQueue("bit_PCLMULQDQ EQU 0x00000002");	/*1 << 1*/
	AddLineQueue("bit_MONITOR EQU 0x00000008");		/*1 << 3*/
	AddLineQueue("bit_SSSE3 EQU 0x00000200");		/*1 << 9*/
	AddLineQueue("bit_FMA EQU 0x00001000");			/*1 << 12*/
	AddLineQueue("bit_CMPXCHG16B EQU 0x00002000");	/*1 << 13*/
	AddLineQueue("bit_SSE41 EQU 0x00080000");		/*1 << 19*/
	AddLineQueue("bit_SSE42 EQU 0x00100000");		/*1 << 20*/
	AddLineQueue("bit_MOVBE EQU 0x00400000");		/*1 << 22*/
	AddLineQueue("bit_POPCNT EQU 0x00800000");		/*1 << 23*/
	AddLineQueue("bit_AES EQU 0x02000000");			/*1 << 25*/
	AddLineQueue("bit_XSAVE EQU 0x04000000");		/*1 << 26*/
	AddLineQueue("bit_OSXSAVE EQU 0x08000000");		/*1 << 27*/
	AddLineQueue("bit_AVX EQU 0x10000000");			/*1 << 28*/
	AddLineQueue("bit_F16C EQU 0x20000000");		/*1 << 29*/
	AddLineQueue("bit_RDRAND EQU 0x40000000");		/*1 << 30*/

	AddLineQueue("bit_AVX_FMA EQU 0x18001000");		/*1 << 12 | 1 << 27 | 1 << 28*/
	AddLineQueue("bit_OSXS_AVX EQU 0x18000000");	/*1 << 27 | 1 << 28*/
	AddLineQueue("bit_AVX_F16C EQU 0x38000000");	/*1 << 27 | 1 << 28 | 1 << 29*/

	AddLineQueue("bit_SSE3_AES EQU 0x02000001");	/*1 << 0 | 1 << 25*/
	AddLineQueue("bit_SSSE3_AES EQU 0x02000200");	/*1 << 9 | 1 << 25*/
	AddLineQueue("bit_SSE41_AES EQU 0x02080000");	/*1 << 19 | 1 << 25*/
	AddLineQueue("bit_SSE42_AES EQU 0x02100000");	/*1 << 20 | 1 << 25*/

	AddLineQueue("bit_SSE3_PCLMULQDQ EQU 0x00000003");	/*1 << 1 | 1 << 1*/
	AddLineQueue("bit_SSSE3_PCLMULQDQ EQU 0x00000202");	/*1 << 1 | 1 << 9*/
	AddLineQueue("bit_SSE41_PCLMULQDQ EQU 0x00080002");	/*1 << 1 | 1 << 19*/
	AddLineQueue("bit_SSE42_PCLMULQDQ EQU 0x00100002");	/*1 << 1 | 1 << 20*/

	/* %eax=01H, %edx */
	AddLineQueue("bit_FPU EQU 0x00000001");			/*1 << 0*/
	AddLineQueue("bit_TSC EQU 0x00000010");			/*1 << 4*/
	AddLineQueue("bit_MSR EQU 0x00000020");			/*1 << 5*/
	AddLineQueue("bit_CMPXCHG8B EQU 0x00000100");	/*1 << 8*/
	AddLineQueue("bit_SEP EQU 0x00000800");			/*1 << 11*/
	AddLineQueue("bit_CMOV EQU 0x00008000");		/*1 << 15*/
	AddLineQueue("bit_CLFSH EQU 0x00080000");		/*1 << 19*/
	AddLineQueue("bit_MMX EQU 0x00800000");			/*1 << 23*/
	AddLineQueue("bit_FXSR EQU 0x01000000");		/*1 << 24*/
	AddLineQueue("bit_SSE EQU 0x02000000");			/*1 << 25*/
	AddLineQueue("bit_SSE2 EQU 0x04000000");		/*1 << 26*/

	/* %eax=07H, %ebx */
	AddLineQueue("bit_FSGSBASE EQU 0x00000001");	/*1 << 0*/
	AddLineQueue("bit_SGX EQU 0x00000004");			/*1 << 2*/
	AddLineQueue("bit_BMI1 EQU 0x00000008");		/*1 << 3*/
	AddLineQueue("bit_HLE EQU 0x00000010");			/*1 << 4*/
	AddLineQueue("bit_AVX2 EQU 0x00000020");		/*1 << 5*/
	AddLineQueue("bit_SMEP EQU 0x00000080");		/*1 << 7*/
	AddLineQueue("bit_BMI2 EQU 0x00000100");		/*1 << 8*/
	AddLineQueue("bit_ERMS EQU 0x00000200");		/*1 << 9*/
	AddLineQueue("bit_INVPCID EQU 0x00000400");		/*1 << 10*/
	AddLineQueue("bit_RTM EQU 0x00000800");			/*1 << 11*/
	AddLineQueue("bit_MPX EQU 0x00004000");			/*1 << 14*/
	AddLineQueue("bit_AVX512F EQU 0x00010000");		/*1 << 16*/
	AddLineQueue("bit_AVX512DQ EQU 0x00020000");	/*1 << 17*/
	AddLineQueue("bit_RDSEED EQU 0x00040000");		/*1 << 18*/
	AddLineQueue("bit_ADX EQU 0x00080000");			/*1 << 19*/
	AddLineQueue("bit_SMAP EQU 0x00100000");		/*1 << 20*/
	AddLineQueue("bit_AVX512_IFMA EQU 0x00200000");	/*1 << 21*/
	AddLineQueue("bit_CLFLUSHOPT EQU 0x00800000");	/*1 << 23*/
	AddLineQueue("bit_CLWB EQU 0x01000000");		/*1 << 24*/
	AddLineQueue("bit_AVX512PF EQU 0x04000000");	/*1 << 26*/
	AddLineQueue("bit_AVX512ER EQU 0x08000000");	/*1 << 27*/
	AddLineQueue("bit_AVX512CD EQU 0x10000000");	/*1 << 28*/
	AddLineQueue("bit_SHA EQU 0x20000000");			/*1 << 29*/
	AddLineQueue("bit_AVX512BW EQU 0x40000000");	/*1 << 30*/
	AddLineQueue("bit_AVX512VL EQU 0x80000000");	/*1 << 31*/

	AddLineQueue("bit_AVX512F_DQ EQU 0x00030000");		/*1 << 16 | 1 << 17*/
	AddLineQueue("bit_AVX512F_DQ_VL EQU 0x80030000");	/*1 << 16 | 1 << 17 | 1 << 31*/
	AddLineQueue("bit_AVX512F_IFMA EQU 0x00210000");	/*1 << 16 | 1 << 21*/
	AddLineQueue("bit_AVX512F_IFMA_VL EQU 0x80210000");	/*1 << 16 | 1 << 21 | 1 << 31*/
	AddLineQueue("bit_AVX512F_PF EQU 0x04010000");		/*1 << 16 | 1 << 26*/
	AddLineQueue("bit_AVX512F_ER EQU 0x08010000");		/*1 << 16 | 1 << 27*/
	AddLineQueue("bit_AVX512F_CD EQU 0x10010000");		/*1 << 16 | 1 << 28*/
	AddLineQueue("bit_AVX512F_CD_VL EQU 0x90010000");	/*1 << 16 | 1 << 28 | 1 << 31*/
	AddLineQueue("bit_AVX512F_BW EQU 0x40010000");		/*1 << 16 | 1 << 30*/
	AddLineQueue("bit_AVX512F_BW_VL EQU 0xC0010000");	/*1 << 16 | 1 << 30 | 1 << 31*/
	AddLineQueue("bit_AVX512F_VL EQU 0x80010000");		/*1 << 16 | 1 << 31*/

	/* %eax=07H, %ecx */
	AddLineQueue("bit_PREFETCHWT1 EQU 0x00000001");		/*1 << 0*/
	AddLineQueue("bit_AVX512_VBMI EQU 0x00000002");		/*1 << 1*/
	AddLineQueue("bit_UMIP EQU 0x00000004");			/*1 << 2*/
	AddLineQueue("bit_PKU EQU 0x00000008");				/*1 << 3*/
	AddLineQueue("bit_OSPKE EQU 0x00000010");			/*1 << 4*/
	AddLineQueue("bit_AVX512_VBMI2 EQU 0x00000040");	/*1 << 6*/
	AddLineQueue("bit_GFNI EQU 0x00000100");			/*1 << 8*/
	AddLineQueue("bit_VAES EQU 0x00000200");			/*1 << 9*/
	AddLineQueue("bit_VPCLMULQDQ EQU 0x00000400");		/*1 << 10*/
	AddLineQueue("bit_AVX512_VNNI EQU 0x00000800");		/*1 << 11*/
	AddLineQueue("bit_AVX512_BITALG EQU 0x00001000");	/*1 << 12*/
	AddLineQueue("bit_AVX512_VPOPCNTDQ EQU 0x00004000");/*1 << 14*/
	AddLineQueue("bit_RDPID EQU 0x00400000");			/*1 << 22*/

	/* %eax=07H, %edx */
	AddLineQueue("bit_AVX512_4VNNIW EQU 0x00000004");	/*1 << 2*/
	AddLineQueue("bit_AVX512_4FMAPS EQU 0x00000008");	/*1 << 3*/

	/* %eax=80000001H, %ecx */
	AddLineQueue("bit_LAHF EQU 0x00000001");			/*1 << 0*/
	AddLineQueue("bit_LZCNT EQU 0x00000020");			/*1 << 5*/
	AddLineQueue("bit_ABM EQU 0x00000020");				/*1 << 5*/
	AddLineQueue("bit_SSE4a EQU 0x00000040");			/*1 << 6*/
	AddLineQueue("bit_PREFETCHW EQU 0x00000100");		/*1 << 8*/
	AddLineQueue("bit_XOP EQU 0x00000800");				/*1 << 11*/
	AddLineQueue("bit_LWP EQU 0x00008000");				/*1 << 15*/
	AddLineQueue("bit_FMA4 EQU 0x00010000");			/*1 << 16*/
	AddLineQueue("bit_TBM EQU 0x00200000");				/*1 << 21*/
	AddLineQueue("bit_MWAITX EQU 0x20000000");			/*1 << 29*/

	/* %eax=80000001H, %edx */
	AddLineQueue("bit_SYSCALL EQU 0x00000800");			/*1 << 11*/
	AddLineQueue("bit_MMXEXT EQU 0x00400000");			/*1 << 22*/
	AddLineQueue("bit_RDTSCP EQU 0x08000000");			/*1 << 27*/
	AddLineQueue("bit_3DNOWEXT EQU 0x40000000");		/*1 << 30*/
	AddLineQueue("bit_3DNOW EQU 0x80000000");			/*1 << 31*/

	AddLineQueue("CMPP_EQ EQU 0x0");
	AddLineQueue("CMPP_LT EQU 0x1");
	AddLineQueue("CMPP_LE EQU 0x2");
	AddLineQueue("CMPP_UNORD EQU 0x3");
	AddLineQueue("CMPP_NEQ EQU 0x4");
	AddLineQueue("CMPP_NLT EQU 0x5");
	AddLineQueue("CMPP_NLE EQU 0x6");
	AddLineQueue("CMPP_ORD EQU 0x7");

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

#define X86MACRO_COUNT64 45

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
	"V64CE",
	"V64CE64",
	"V32CE",
	"V32CE32",
	"V16CE",
	"V16CE16",
	"V8CE",
	"V8CE8",
	"V4CE",
	"V4CE4",
	"V2CE",
	"V2CE2"
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
	"V64CE MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V64CE64 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ, V17:REQ, V18:REQ, V19:REQ, V20:REQ, V21:REQ, V22:REQ, V23:REQ, V24:REQ, V25:REQ, V26:REQ, V27:REQ, V28:REQ, V29:REQ, V30:REQ, V31:REQ, V32:REQ, V33:REQ, V34:REQ, V35:REQ, V36:REQ, V37:REQ, V38:REQ, V39:REQ, V40:REQ, V41:REQ, V42:REQ, V43:REQ, V44:REQ, V45:REQ, V46:REQ, V47:REQ, V48:REQ, V49:REQ, V50:REQ, V51:REQ, V52:REQ, V53:REQ, V54:REQ, V55:REQ, V56:REQ, V57:REQ, V58:REQ, V59:REQ, V60:REQ, V61:REQ, V62:REQ, V63:REQ, V64:REQ",
	"V32CE MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V32CE32 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ, V17:REQ, V18:REQ, V19:REQ, V20:REQ, V21:REQ, V22:REQ, V23:REQ, V24:REQ, V25:REQ, V26:REQ, V27:REQ, V28:REQ, V29:REQ, V30:REQ, V31:REQ, V32:REQ",
	"V16CE MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V16CE16 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ, V9:REQ, V10:REQ, V11:REQ, V12:REQ, V13:REQ, V14:REQ, V15:REQ, V16:REQ",
	"V8CE MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V8CE8 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ, V5:REQ, V6:REQ, V7:REQ, V8:REQ",
	"V4CE MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V4CE4 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ, V3:REQ, V4:REQ",
	"V2CE MACRO functionName:REQ, vectorType:REQ, V1:REQ",
	"V2CE2 MACRO functionName:REQ, vectorType:REQ, V1:REQ, V2:REQ"
};

void x86CreateMacroLibCases(void)
{
	/* Create case alternative names for macrolib functions */
	if (ModuleInfo.case_sensitive && !ModuleInfo.convert_uppercase)
	{
		AddLineQueue("callconv TEXTEQU <CALLCONV>");
		AddLineQueue("callconvopt TEXTEQU <CALLCONVOPT>");

		AddLineQueue("size_t TEXTEQU <SIZE_T>");
		AddLineQueue("isize_t TEXTEQU <ISIZE_T>");
		AddLineQueue("psize_t TEXTEQU <PSIZE_T>");
		AddLineQueue("size_tp TEXTEQU <SIZE_TP>");
		AddLineQueue("size_t_size EQU SIZE_T_SIZE");
		AddLineQueue("ptr_size EQU PTR_SIZE");
		AddLineQueue("reg_size EQU REG_SIZE");

		AddLineQueue("byte_size EQU BYTE_SIZE");
		AddLineQueue("char_size EQU CHAR_SIZE");
		AddLineQueue("int8_size EQU INT8_SIZE");
		AddLineQueue("word_size EQU WORD_SIZE");
		AddLineQueue("short_size EQU SHORT_SIZE");
		AddLineQueue("int16_size EQU INT16_SIZE");
		AddLineQueue("dword_size EQU DWORD_SIZE");
		AddLineQueue("long_size EQU LONG_SIZE");
		AddLineQueue("int_size EQU INT_SIZE");
		AddLineQueue("int32_size EQU INT32_SIZE");
		AddLineQueue("qword_size EQU QWORD_SIZE");
		AddLineQueue("longlong_size EQU LONGLONG_SIZE");
		AddLineQueue("int64_size EQU INT64_SIZE");
		AddLineQueue("real4_size EQU REAL4_SIZE");
		AddLineQueue("float_size EQU FLOAT_SIZE");
		AddLineQueue("real8_size EQU REAL8_SIZE");
		AddLineQueue("double_size EQU DOUBLE_SIZE");

		AddLineQueue("mm_size EQU MM_SIZE");
		AddLineQueue("m64_size EQU M64_SIZE");
		AddLineQueue("xmm_size EQU XMM_SIZE");
		AddLineQueue("m128_size EQU M128_SIZE");
		AddLineQueue("ymm_size EQU YMM_SIZE");
		AddLineQueue("m256_size EQU M256_SIZE");
		AddLineQueue("zmm_size EQU ZMM_SIZE");
		AddLineQueue("m512_size EQU M512_SIZE");

		AddLineQueue("float TEXTEQU <FLOAT>");
		AddLineQueue("double TEXTEQU <DOUBLE>");

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

		AddLineQueue("v64ce EQU V64CE");
		AddLineQueue("v64ce64 EQU V64CE64");
		AddLineQueue("v32ce EQU V32CE");
		AddLineQueue("v32ce32 EQU V32CE32");
		AddLineQueue("v16ce EQU V16CE");
		AddLineQueue("v16ce16 EQU V16CE16");
		AddLineQueue("v8ce EQU V8CE");
		AddLineQueue("v8ce8 EQU V8CE8");
		AddLineQueue("v4ce EQU V4CE");
		AddLineQueue("v4ce4 EQU V4CE4");
		AddLineQueue("v2ce EQU V2CE");
		AddLineQueue("v2ce2 EQU V2CE2");

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

		/*AddLineQueue(" EQU ");
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

	   //						 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22  23  24 25 26 27 28  29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45  46  47  48  49  50 51  52  53  54 55 56 57 58  59 60 61  62   63   64
	uint_32 x86macroLen[] =		{9, 9, 4, 4, 4, 4, 4, 9, 9, 4, 4, 4, 4, 4, 9, 9, 4, 4, 4, 4, 7, 13, 13, 7, 7, 7, 7, 10, 5, 2, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6/*, 38, 11, 45, 91, 6, 10, 10, 37, 1, 1, 1, 1, 256, 10, 6, 6, 106, 137, 7*/}; // Count of individual lines of macro-body code.
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
	/*34 V64CE*/				"mm64fnex TEXTEQU <>","mm64fnex CATSTR mm64fnex, <&functionName&>","public mm64fnex","mm64fnex CATSTR mm64fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1 } >","mm64fnex","ENDM",NULL,
	/*35 V64CE64*/				"mm64fnex64 TEXTEQU <>","mm64fnex64 CATSTR mm64fnex64, <&functionName&>","public mm64fnex64","mm64fnex64 CATSTR mm64fnex64, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16, V17, V18, V19, V20, V21, V22, V23, V24, V25, V26, V27, V28, V29, V30, V31, V32, V33, V34, V35, V36, V37, V38, V39, V40, V41, V42, V43, V44, V45, V46, V47, V48, V49, V50, V51, V52, V53, V54, V55, V56, V57, V58, V59, V60, V61, V62, V63, V64 } >","mm64fnex64","ENDM",NULL,
	/*36 V32CE*/				"mm32fnex TEXTEQU <>","mm32fnex CATSTR mm32fnex, <&functionName&>","public mm32fnex","mm32fnex CATSTR mm32fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1 } >","mm32fnex","ENDM",NULL,
	/*37 V32CE32*/				"mm32fnex32 TEXTEQU <>","mm32fnex32 CATSTR mm32fnex32, <&functionName&>","public mm32fnex32","mm32fnex32 CATSTR mm32fnex32, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16, V17, V18, V19, V20, V21, V22, V23, V24, V25, V26, V27, V28, V29, V30, V31, V32 } >","mm32fnex32","ENDM",NULL,
	/*38 V16CE*/				"mm16fnex TEXTEQU <>","mm16fnex CATSTR mm16fnex, <&functionName&>","public mm16fnex","mm16fnex CATSTR mm16fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1, V1 } >","mm16fnex","ENDM",NULL,
	/*39 V16CE16*/				"mm16fnex16 TEXTEQU <>","mm16fnex16 CATSTR mm16fnex16, <&functionName&>","public mm16fnex16","mm16fnex16 CATSTR mm16fnex16, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13, V14, V15, V16 } >","mm16fnex16","ENDM",NULL,
	/*40 V8CE*/					"mm8fnex TEXTEQU <>","mm8fnex CATSTR mm8fnex, <&functionName&>","public mm8fnex","mm8fnex CATSTR mm8fnex, < vectorType>,  < { V1, V1, V1, V1, V1, V1, V1, V1 } >","mm8fnex","ENDM",NULL,
	/*41 V8CE8*/				"mm8fnex8 TEXTEQU <>","mm8fnex8 CATSTR mm8fnex8, <&functionName&>","public mm8fnex8","mm8fnex8 CATSTR mm8fnex8, < vectorType>, < { V1, V2, V3, V4, V5, V6, V7, V8 } >","mm8fnex8","ENDM",NULL,
	/*42 V4CE*/					"mm4fnex TEXTEQU <>","mm4fnex CATSTR mm4fnex, <&functionName&>","public mm4fnex","mm4fnex CATSTR mm4fnex, < vectorType>,  < { V1, V1, V1, V1 } >","mm4fnex","ENDM",NULL,
	/*43 V4CE4*/				"mm4fnex4 TEXTEQU <>","mm4fnex4 CATSTR mm4fnex4, <&functionName&>","public mm4fnex4","mm4fnex4 CATSTR mm4fnex4, < vectorType>, < { V1, V2, V3, V4 } >","mm4fnex4","ENDM",NULL,
	/*44 V2CE*/					"mm2fnex TEXTEQU <>","mm2fnex CATSTR mm2fnex, <&functionName&>","public mm2fnex","mm2fnex CATSTR mm2fnex, < vectorType>,  < { V1, V1 } >","mm2fnex","ENDM",NULL,
	/*45 V2CE2*/				"mm2fnex2 TEXTEQU <>","mm2fnex2 CATSTR mm2fnex2, <&functionName&>","public mm2fnex2","mm2fnex2 CATSTR mm2fnex2, < vectorType>, < { V1, V2 } >","mm2fnex2","ENDM",NULL/*,*/
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
