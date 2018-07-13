/* 
Vitor change, vectorcall name manglin and gcc / clang build fixes
For

v2.47.0
 		john-terraspace committed on Mar 28
 update pie
  		commit eb6477d06e3d9ce32c7887479508a61092de91f5


Files:
 */
 
/* **************************************VECTORCALL NAME MANGLIN CHANGES START***************************************** */

/* 
UASM\H\globals.h
lines:
added:
494
to
499
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* vitor-add option for vectorcall name manglin */
enum vectorcall_decoration
{
	VECTORCALL_FULL,
	VECTORCALL_NONE,
	VECTORCALL_HALF
};

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\globals.h
change:
659
to
661
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */
 
	uint_8      stdcall_decoration;      /* -zt<0|1|2> option */
	uint_8      vectorcall_decoration;   /* -zv<0|1|2> option */ /* vitor-add option for vectorcall name manglin */
	bool        no_export_decoration;    /* -zze option */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\globals.h
change:
67
to
71
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#define MAX_LINE_LEN            25600  /* no restriction for this number */ /* vitor-change revamp to 100*256 max line capacity for macros and multiline uses as one line */
#define MAX_TOKEN  MAX_LINE_LEN - 32  /* max tokens in one line */
#define MAX_STRING_LEN          MAX_LINE_LEN - 32 /* must be < MAX_LINE_LEN */
#define MAX_ID_LEN              MAX_LINE_LEN - 32 /*247*/  /* must be < MAX_LINE_LEN */  /* vitor-change multiline as one fix */
#define MAX_STRUCT_ALIGN        64 	  /* vitor-change max alignment for __m512 data types */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\ltext.h
lines:
add:
65
66
67
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* language order must match enum lang_type in globals.h */
ltext(VOID, "")
ltext(C, "C")
ltext(SYSCALL, "SYSCALL")
ltext(STDCALL, "STDCALL")
ltext(PASCAL, "PASCAL")
ltext(FORTRAN, "FORTRAN")
ltext(BASIC, "BASIC")
ltext(FASTCALL, "FASTCALL")
ltext(VECTORCALL, "VECTORCALL")  // vitor add, necessary for the module know at build time, vectorcall mangle
ltext(SYSVCALL, "SYSVCALL")  // vitor add, necessary for the module know at build time, mangle, future work on gcc mangler for exported c functions
ltext(DELPHICALL, "DELPHICALL")  // vitor add, necessary for the module know at build time, if necessary ?

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\usage.h

lines:
modified:
31
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

"-G<c|d|r|z|v>\0"   "Use Pascal, C, Fastcall, Stdcall, Vectorcall calling convention\0" // vitor-change, add vectorcall option

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\usage.h
add:
79
80
*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

"-zv<0|1|2>\0"      "Set VECTORCALL symbol decoration: 0=No name decoration,\0" // vitor-added, for limiting globaly vectorcall name mangling, default for 64bits if vectorcall present in proto and proc definition
"\0"                "1=No '@size' suffix for functions, 2=Full (default)\0" // vitor-added, 		 ''

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\cmdline.c
lines:
added:
117
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

	/* vectorcall_decoration    */  VECTORCALL_FULL, /* vitor-add options for vectorcall name mangling*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\cmdline.c
added:
541
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

static void OPTQUAL Set_zv(void){	Options.vectorcall_decoration = OptValue; } /* vitor-add options for vectorcall name mangling*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\cmdline.c
added:
665
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

	{ "Gv",     LANG_VECTORCALL, Set_G },  /* vitor-add options for vectorcall name mangling*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\cmdline.c
added:
751
752
753
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

	{ "zv0",    VECTORCALL_NONE, Set_zv }, /* vitor-add options for vectorcall name mangling*/
	{ "zv1",    VECTORCALL_HALF, Set_zv }, /* vitor-add  '' 		'' 		*/
	{ "zv2",    VECTORCALL_FULL, Set_zv }, /* vitor-add  '' 		'' 		*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\listing.c
line:
changed:
from
859
to
867
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

	/* for PROCs, list parameters and locals */
    if ( sym->state == SYM_INTERNAL ) {
		/* print the procedure's parameters */
		if (sym->langtype == LANG_C ||
			sym->langtype == LANG_VECTORCALL || /* vitor-add options for vectorcall name mangling*/
			sym->langtype == LANG_SYSCALL ||
			sym->langtype == LANG_STDCALL ||
      sym->langtype == LANG_FASTCALL ) {
			int cnt;
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\mangle.c
lines:
changed:
from:
113
to
129
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* vitor-change add option for vetorcall name manglin*/
/* MS FASTCALL || VECTORCALL 32bit */

/* MS FASTCALL || VECTORCALL 32bit */

static int ms32_decorate( const struct asym *sym, char *buffer )
/**************************************************************/
{
	const struct dsym *dir = (struct dsym *)sym;
	if ((sym->langtype == LANG_VECTORCALL) && (Options.vectorcall_decoration == VECTORCALL_FULL) && sym->isproc) {
		return(sprintf(buffer, "%s@@%d", sym->name, dir->e.procinfo->parasize));
	}
	else if (Options.fctype == FCT_MSC && sym->isproc) {
    		return ( sprintf( buffer, "@%s@%u", sym->name, ((struct dsym *)sym)->e.procinfo->parasize ) );
	} else {
		memcpy(buffer, sym->name, sym->name_size + 1);
		return(sym->name_size);
	}
}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\mangle.c
from:
180
to
192
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* vitor-change add option for vetorcall name manglin*/
/* MS FASTCALL || VECTORCALL 64bit */

static int ms64_decorate( const struct asym *sym, char *buffer )
/**************************************************************/
{
	const struct dsym *dir = (struct dsym *)sym;
	if ((sym->langtype == LANG_VECTORCALL) && (Options.vectorcall_decoration == VECTORCALL_FULL) && sym->isproc) {
		return(sprintf(buffer, "%s@@%d", sym->name, dir->e.procinfo->parasize));
	} else {
    		memcpy( buffer, sym->name, sym->name_size + 1 );
    		return( sym->name_size );
	}
}
#endif

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\mangle.c
added:
246
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

	case LANG_VECTORCALL: /* vitor-change add option for vetorcall name manglin*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\proc.c
lines:
changed:
from
929
to
968
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* vitor-change add option for vectorcall name manglin, know ptr types declared as ptr oword, ptr ymmword, ptr zmmword*/

					tn != to))) {

				/* UASM 2.46.10 prevent symbols that are moved to stack whose size is turned from ptr to machine word size from breaking the proto vs proc defition of a ptr type */
				if (ti.mem_type == MT_PTR && paracurr->sym.state == SYM_STACK && 
					(paracurr->sym.mem_type == MT_QWORD && CurrWordSize == 8) || 
					(paracurr->sym.mem_type == MT_OWORD && CurrWordSize == 8) ||
					(paracurr->sym.mem_type == MT_YMMWORD && CurrWordSize == 8) ||
					(paracurr->sym.mem_type == MT_ZMMWORD && CurrWordSize == 8) ||
					(paracurr->sym.mem_type == MT_DWORD && CurrWordSize == 4) ||
					(paracurr->sym.mem_type == MT_OWORD && CurrWordSize == 4) ||
					(paracurr->sym.mem_type == MT_YMMWORD && CurrWordSize == 4) ||
					(paracurr->sym.mem_type == MT_ZMMWORD && CurrWordSize == 4))
				{
				}
				else if (paracurr->sym.mem_type == MT_PTR && paracurr->sym.state == SYM_STACK &&
					(ti.mem_type == MT_QWORD && CurrWordSize == 8) ||
					(ti.mem_type == MT_OWORD && CurrWordSize == 8) ||
					(ti.mem_type == MT_YMMWORD && CurrWordSize == 8) ||
					(ti.mem_type == MT_ZMMWORD && CurrWordSize == 8) ||
					(ti.mem_type == MT_DWORD && CurrWordSize == 4) ||
					(ti.mem_type == MT_OWORD && CurrWordSize == 4) ||
					(ti.mem_type == MT_YMMWORD && CurrWordSize == 4) ||
					(ti.mem_type == MT_ZMMWORD && CurrWordSize == 4))
				{
				}
				else
				{
					DebugMsg(("ParseParams: old-new memtype=%X-%X type=%X(%s)-%X(%s) far=%u-%u ind=%u-%u ofss=%d-%d pmt=%X-%X\n",
						paracurr->sym.mem_type, ti.mem_type,
						(paracurr->sym.mem_type == MT_TYPE) ? paracurr->sym.type : paracurr->sym.target_type,
						(paracurr->sym.mem_type == MT_TYPE) ? paracurr->sym.type->name : paracurr->sym.target_type ? paracurr->sym.target_type->name : "",
						ti.symtype, ti.symtype ? ti.symtype->name : "",
						paracurr->sym.isfar, ti.is_far,
						paracurr->sym.is_ptr, ti.is_ptr,
						paracurr->sym.Ofssize, ti.Ofssize,
						paracurr->sym.ptr_memtype, ti.ptr_memtype));
					EmitErr(CONFLICTING_PARAMETER_DEFINITION, name);
				}
			}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\proc.c
changed:
1024
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

						/* vitor-change add option for vectorcall name manglin, know mem type for module knows to select the correct type to print*/
						ti.mem_type == MT_OWORD || ti.mem_type == MT_YMMWORD || ti.mem_type == MT_ZMMWORD) {

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\proc.c
change:
from:
1058
to
1122
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

			/* vitor-change add option for vectorcall name manglin, know mem type for module knows to select the correct type to print*/
			if (paranode->sym.is_vararg == FALSE)
			{
				/* v2.11: CurrWordSize does reflect the default parameter size only for PROCs.
				* For PROTOs and TYPEs use member seg_ofssize.
				*/
				//proc->e.procinfo->parasize += ROUND_UP( ti.size, CurrWordSize );

				if (proc->sym.langtype == LANG_VECTORCALL)
				{
					switch (CurrWordSize)
					{
						case 8:
							switch (ti.mem_type)
							{
								case MT_OWORD:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? 2 * CurrWordSize : 2 * (2 << proc->sym.seg_ofssize));
									break;

								case MT_YMMWORD:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? 4 * CurrWordSize : 4 * (2 << proc->sym.seg_ofssize));
									break;

								case MT_ZMMWORD:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? 8 * CurrWordSize : 8 * (2 << proc->sym.seg_ofssize));
									break;

								default:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? CurrWordSize : (2 << proc->sym.seg_ofssize));
									break;
							}
							break;

						case 4:
							switch (ti.mem_type)
							{
								case MT_OWORD:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? 4 * CurrWordSize : 4 * (2 << proc->sym.seg_ofssize));
									break;

								case MT_YMMWORD:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? 8 * CurrWordSize : 8 * (2 << proc->sym.seg_ofssize));
									break;

								case MT_ZMMWORD:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? 16 * CurrWordSize : 16 * (2 << proc->sym.seg_ofssize));
									break;

								default:
									proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? CurrWordSize : (2 << proc->sym.seg_ofssize));
									break;
							}
							break;

						default:
							proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? CurrWordSize : (2 << proc->sym.seg_ofssize));
							break;
					}

				} else {
					proc->e.procinfo->parasize += ROUND_UP(ti.size, IsPROC ? CurrWordSize : (2 << proc->sym.seg_ofssize));
				}

			}

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\proc.c
added:
5377
to
5382
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

			/* vitor-change add option for vectorcall name manglin, select only vectorcall option using mudule.fctype this way wen selecting FASTCALL the vectorcall its not mangled, defense for call types */
			case LANG_FASTCALL:
				fastcall_tab[ModuleInfo.fctype].handlereturn(CurrProc, buffer);
				break;
			case LANG_VECTORCALL:
				vectorcall_tab[ModuleInfo.fctype].handlereturn(CurrProc, buffer);
				break;
				
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


/* **************************************VECTORCALL NAME MANGLIN CHANGES END***************************************** */





/* **************************************FIXES CHANGES START ***************************************** */

/* 
UASM\H\memalloc.h
lines:
add:
49
to
51
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#ifndef alloca // vitor add, gcc 8+ complains alloca already defined in gcc, defence double definition its equal in gcc 8+
	#define alloca(x)  __builtin_alloca(x)
#endif

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\msgdef.h
line:
modified:
277
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

pick(STRUCT_ALIGN_TOO_HIGH, "Struct alignment must be 1, 2, 4, 8, 16, 32 or 64") // add alignment info for __m512 types

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* 
UASM\H\opndcls.h
lines:
add:
239
to
242
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#if !INTELMOVQ // defend for double definition if INTELMOVQ selected for moves using only MOVQ, ? My last test INTELMOVQ breaks regressions test if defined 1 ? added but not imperative.
OpCls( R32_M32,   XMM,   NONE )
OpCls( R64_M64,   XMM,   NONE )
#endif

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\H\winconsole.h

lines:
added:
1
2
3
4
5
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#ifndef _MSC_VER  // defenses for gcc and or clang builds, this defs not present with the compilers
# define __in
# define _In_
# define _Out_
#endif

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\assemble.c

lines:
added:
11
12
13
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#ifdef __GNUC__ // vitor-added, defense against multy includes for defined types, gcc 8+ complains
#define _BITS_FLOATN_COMMON_H
#endif

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\branch.c

lines:
added:
11
12
13
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#ifdef __GNUC__ // vitor-added, defense against multy includes for defined types, gcc 8+ complains
#define _BITS_FLOATN_COMMON_H
#endif

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\codegen.c

lines:
changed:
237
to
385
 */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

case T_PSLL to T_PSRL types invalidates SSE instrunctions

      switch (CodeInfo->token){
        case   T_VADDPD:
        case   T_VADDSD:
        case   T_VDIVPD:
        case   T_VDIVSD:
        case   T_VMAXPD:
        case   T_VMAXSD:
        case   T_VMINPD:
        case   T_VMINSD:
        case   T_VMULPD:
        case   T_VMULSD:
        case   T_VSQRTSD:
        case   T_VSUBPD:
        case   T_VSUBSD:
        case   T_VADDPS:
        case   T_VADDSS:
        case   T_VDIVPS:
        case   T_VDIVSS:
        case   T_VMAXPS:
        case   T_VMAXSS:
        case   T_VMINPS:
        case   T_VMINSS:
        case   T_VMULPS:
        case   T_VMULSS:
        case   T_VSQRTSS:
        case   T_VSUBPS:
        case   T_VSUBSS:
        case   T_VCMPPD:
        case   T_VCMPSD:
        case   T_VCMPPS:
        case   T_VCMPSS:
        case   T_VXORPD: 
        case   T_VORPS: 
        case   T_VXORPS:
        case   T_PSLLDQ:
        case   T_PSRLDQ:
        case   T_PSLLW:
        case   T_PSLLD:
        case   T_PSLLQ:
        case   T_PSRAW:
        case   T_PSRAD:
        case   T_PSRAQ:
        case   T_PSRLW:
        case   T_PSRLD:
        case   T_PSRLQ:
        if (CodeInfo->r2type == OP_XMM || CodeInfo->r2type == OP_YMM || CodeInfo->r2type == OP_ZMM)
          break;
          EmitError(INVALID_INSTRUCTION_OPERANDS);
        }

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\ltype.c

line:
changed:
1
 */
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

#include "globals.h" /* vitor-change to local include, stranges things apens with clang compiles if declared external include and undef all types in the #include <globals.h> */

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\simd.c

lines:
add:
182
to
351
 */
 
		/* __m512 data types add*/	
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

	AddLineQueue("__m512b struct");
	AddLineQueue("b0 BYTE ?");
	AddLineQueue("b1 BYTE ?");
	AddLineQueue("b2 BYTE ?");
	AddLineQueue("b3 BYTE ?");
	AddLineQueue("b4 BYTE ?");
	AddLineQueue("b5 BYTE ?");
	AddLineQueue("b6 BYTE ?");
	AddLineQueue("b7 BYTE ?");
	AddLineQueue("b8 BYTE ?");
	AddLineQueue("b9 BYTE ?");
	AddLineQueue("b10 BYTE ?");
	AddLineQueue("b11 BYTE ?");
	AddLineQueue("b12 BYTE ?");
	AddLineQueue("b13 BYTE ?");
	AddLineQueue("b14 BYTE ?");
	AddLineQueue("b15 BYTE ?");
	AddLineQueue("b16 BYTE ?");
	AddLineQueue("b17 BYTE ?");
	AddLineQueue("b18 BYTE ?");
	AddLineQueue("b19 BYTE ?");
	AddLineQueue("b20 BYTE ?");
	AddLineQueue("b21 BYTE ?");
	AddLineQueue("b22 BYTE ?");
	AddLineQueue("b23 BYTE ?");
	AddLineQueue("b24 BYTE ?");
	AddLineQueue("b25 BYTE ?");
	AddLineQueue("b26 BYTE ?");
	AddLineQueue("b27 BYTE ?");
	AddLineQueue("b28 BYTE ?");
	AddLineQueue("b29 BYTE ?");
	AddLineQueue("b30 BYTE ?");
	AddLineQueue("b31 BYTE ?");
	AddLineQueue("b32 BYTE ?");
	AddLineQueue("b33 BYTE ?");
	AddLineQueue("b34 BYTE ?");
	AddLineQueue("b35 BYTE ?");
	AddLineQueue("b36 BYTE ?");
	AddLineQueue("b37 BYTE ?");
	AddLineQueue("b38 BYTE ?");
	AddLineQueue("b39 BYTE ?");
	AddLineQueue("b40 BYTE ?");
	AddLineQueue("b41 BYTE ?");
	AddLineQueue("b42 BYTE ?");
	AddLineQueue("b43 BYTE ?");
	AddLineQueue("b44 BYTE ?");
	AddLineQueue("b45 BYTE ?");
	AddLineQueue("b46 BYTE ?");
	AddLineQueue("b47 BYTE ?");
	AddLineQueue("b48 BYTE ?");
	AddLineQueue("b49 BYTE ?");
	AddLineQueue("b50 BYTE ?");
	AddLineQueue("b51 BYTE ?");
	AddLineQueue("b52 BYTE ?");
	AddLineQueue("b53 BYTE ?");
	AddLineQueue("b54 BYTE ?");
	AddLineQueue("b55 BYTE ?");
	AddLineQueue("b56 BYTE ?");
	AddLineQueue("b57 BYTE ?");
	AddLineQueue("b58 BYTE ?");
	AddLineQueue("b59 BYTE ?");
	AddLineQueue("b60 BYTE ?");
	AddLineQueue("b61 BYTE ?");
	AddLineQueue("b62 BYTE ?");
	AddLineQueue("b63 BYTE ?");
	AddLineQueue("__m512b ends");

	AddLineQueue("__m512w struct");
	AddLineQueue("w0 WORD ?");
	AddLineQueue("w1 WORD ?");
	AddLineQueue("w2 WORD ?");
	AddLineQueue("w3 WORD ?");
	AddLineQueue("w4 WORD ?");
	AddLineQueue("w5 WORD ?");
	AddLineQueue("w6 WORD ?");
	AddLineQueue("w7 WORD ?");
	AddLineQueue("w8 WORD ?");
	AddLineQueue("w9 WORD ?");
	AddLineQueue("w10 WORD ?");
	AddLineQueue("w11 WORD ?");
	AddLineQueue("w12 WORD ?");
	AddLineQueue("w13 WORD ?");
	AddLineQueue("w14 WORD ?");
	AddLineQueue("w15 WORD ?");
	AddLineQueue("w16 WORD ?");
	AddLineQueue("w17 WORD ?");
	AddLineQueue("w18 WORD ?");
	AddLineQueue("w19 WORD ?");
	AddLineQueue("w20 WORD ?");
	AddLineQueue("w21 WORD ?");
	AddLineQueue("w22 WORD ?");
	AddLineQueue("w23 WORD ?");
	AddLineQueue("w24 WORD ?");
	AddLineQueue("w25 WORD ?");
	AddLineQueue("w26 WORD ?");
	AddLineQueue("w27 WORD ?");
	AddLineQueue("w28 WORD ?");
	AddLineQueue("w29 WORD ?");
	AddLineQueue("w30 WORD ?");
	AddLineQueue("w31 WORD ?");
	AddLineQueue("__m512w ends");

	AddLineQueue("__m512i struct");
	AddLineQueue("i0 DWORD ?");
	AddLineQueue("i1 DWORD ?");
	AddLineQueue("i2 DWORD ?");
	AddLineQueue("i3 DWORD ?");
	AddLineQueue("i4 DWORD ?");
	AddLineQueue("i5 DWORD ?");
	AddLineQueue("i6 DWORD ?");
	AddLineQueue("i7 DWORD ?");
	AddLineQueue("i8 DWORD ?");
	AddLineQueue("i9 DWORD ?");
	AddLineQueue("i10 DWORD ?");
	AddLineQueue("i11 DWORD ?");
	AddLineQueue("i12 DWORD ?");
	AddLineQueue("i13 DWORD ?");
	AddLineQueue("i14 DWORD ?");
	AddLineQueue("i15 DWORD ?");
	AddLineQueue("__m512i ends");

	AddLineQueue("__m512f struct");
	AddLineQueue("f0 real4 ?");
	AddLineQueue("f1 real4 ?");
	AddLineQueue("f2 real4 ?");
	AddLineQueue("f3 real4 ?");
	AddLineQueue("f4 real4 ?");
	AddLineQueue("f5 real4 ?");
	AddLineQueue("f6 real4 ?");
	AddLineQueue("f7 real4 ?");
	AddLineQueue("f8 real4 ?");
	AddLineQueue("f9 real4 ?");
	AddLineQueue("f10 real4 ?");
	AddLineQueue("f11 real4 ?");
	AddLineQueue("f12 real4 ?");
	AddLineQueue("f13 real4 ?");
	AddLineQueue("f14 real4 ?");
	AddLineQueue("f15 real4 ?");
	AddLineQueue("__m512f ends");

	AddLineQueue("__m512d struct");
	AddLineQueue("d0 real8 ?");
	AddLineQueue("d1 real8 ?");
	AddLineQueue("d2 real8 ?");
	AddLineQueue("d3 real8 ?");
	AddLineQueue("d4 real8 ?");
	AddLineQueue("d5 real8 ?");
	AddLineQueue("d6 real8 ?");
	AddLineQueue("d7 real8 ?");
	AddLineQueue("__m512d ends");

	AddLineQueue("__m512q struct");
	AddLineQueue("q0 QWORD ?");
	AddLineQueue("q1 QWORD ?");
	AddLineQueue("q2 QWORD ?");
	AddLineQueue("q3 QWORD ?");
	AddLineQueue("q4 QWORD ?");
	AddLineQueue("q5 QWORD ?");
	AddLineQueue("q6 QWORD ?");
	AddLineQueue("q7 QWORD ?");
	AddLineQueue("__m512q ends");

	AddLineQueue("__m512 union");
	AddLineQueue("f32 __m512f <>");
	AddLineQueue("i8  __m512b <>");
	AddLineQueue("i16 __m512w <>");
	AddLineQueue("i32 __m512i <>");
	AddLineQueue("d64 __m512d <>");
	AddLineQueue("q64 __m512q <>");
	AddLineQueue("__m512 ends");
			
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/*
UASM\trmem.c

add:
 */
 		
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* vitor-add missing include for gcc 8+ gcc build complains*/
#ifdef __GNUC__
#include <errno.h>
#endif
		
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */


/* **************************************FIXES CHANGES END***************************************** */

