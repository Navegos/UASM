#pragma once

#include "codegenv2.h"

struct Mem_Def MemTable32[] = {
    /* INDEX---> AX CX DX BX SP BP  SI DI R8 R9 R10 R11 R12  R13 R14 R15 RIP NONE																  */
    /* BASE																																		  */
    /*  |																																		  */
    /*  v																																		  */
    /* AX */
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_AX | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_AX | SIB_IDX_RIP) },
    { (MRM_AX),   (MEMF_MODRM), (NO_SIB) },
    /* CX */
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_CX | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_CX | SIB_IDX_RIP) },
    { (MRM_CX),   (MEMF_MODRM), (NO_SIB) },
    /* DX */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DX | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_DX | SIB_IDX_RIP) },
    { (MRM_DX),   (MEMF_MODRM), (NO_SIB) },
    /* BX */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_BX | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_BX | SIB_IDX_RIP) },
    { (MRM_BX),   (MEMF_MODRM), (NO_SIB) },
    /* SP */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SP | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_SP | SIB_IDX_RIP) },
    { (MRM_SP),   (MEMF_MODRM | MEMF_SIB), 0x24 },

    /* BP */
    {  SIB_ONLY,  (MEMF_MODRM | MEMF_SIB) | MEMF_DSP, (SIB_BASE_BP | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP), (SIB_BASE_BP | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_BP | SIB_IDX_RIP) },
    { (MRM_BP),  (MEMF_MODRM | MEMF_DSP), (NO_SIB) },

    /* SI */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_SI | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_SI | SIB_IDX_RIP) },
    { (MRM_SI),   (MEMF_MODRM), (NO_SIB) },
    /* DI */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_DI | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_DI | SIB_IDX_RIP) },
    { (MRM_DI),   (MEMF_MODRM), (NO_SIB) },
    /* R8 */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R8 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R8 | SIB_IDX_RIP) },
    { (MRM_R8),   (MEMF_MODRM), (NO_SIB) },
    /* R9 */     { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R9 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R9 | SIB_IDX_RIP) },
    { (MRM_R9),   (MEMF_MODRM), (NO_SIB) },
    /* R10 */    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R10 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R10 | SIB_IDX_RIP) },
    { (MRM_R10),  (MEMF_MODRM), (NO_SIB) },
    /* R11 */    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R11 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R11 | SIB_IDX_RIP) },
    { (MRM_R11),  (MEMF_MODRM), (NO_SIB) },
    /* R12 */    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R12 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R12 | SIB_IDX_RIP) },
    { (MRM_R12),  (MEMF_MODRM | MEMF_SIB), 0x24            },
    /* R13 */    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R13 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R13 | SIB_IDX_RIP) },
    { (MRM_R13),  (MEMF_MODRM | MEMF_DSP), (NO_SIB) },
    /* R14 */    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R14 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R14 | SIB_IDX_RIP) },
    { (MRM_R14),  (MEMF_MODRM), (NO_SIB) },
    /* R15 */    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB), (SIB_BASE_R15 | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | NO_ENCODE), (SIB_BASE_R15 | SIB_IDX_RIP) },
    { (MRM_R15),  (MEMF_MODRM), (NO_SIB) },
    /* RIP */    { SIB_ONLY,  (NO_ENCODE)            , 0x00 },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { SIB_ONLY,  (NO_ENCODE), (NO_SIB) },
    { (MRM_RIP),  (MEMF_MODRM | MEMF_DSP32), (NO_SIB) },

    /* NONE */
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32) , (SIB_BASE_BP | SIB_IDX_AX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_CX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_DX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_BX) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_SP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_BP) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_SI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_DI) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R8) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R9) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R10) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R11) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R12) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R13) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R14) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_R15) },
    { SIB_ONLY,  (MEMF_MODRM | MEMF_SIB | MEMF_DSP32), (SIB_BASE_BP | SIB_IDX_RIP) },
    { MRM_RIP,  (MEMF_MODRM | MEMF_DSP32), (NO_SIB) }, /* [none+none] == disp32 */
};
