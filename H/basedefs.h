
/*
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
; / /                                                                               / /
; / /         Copyright 2021 (c) UASM a free MASM - compatible assembler            / /
; / /                                                                               / /
; / /    Licensed under the Apache License, Version 2.0 (the "License");            / /
; / /    you may not use this file except in compliance with the License.           / /
; / /    You may obtain a copy of the License at                                    / /
; / /                                                                               / /
; / /        http://www.apache.org/licenses/LICENSE-2.0                             / /
; / /                                                                               / /
; / /    Unless required by applicable law or agreed to in writing, software        / /
; / /    distributed under the License is distributed on an "AS IS" BASIS,          / /
; / /    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   / /
; / /    See the License for the specific language governing permissions and        / /
; / /    limitations under the License.                                             / /
; / /                                                                               / /
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
*/

#pragma once

#ifndef UASM_BASEDEFS_H
#define UASM_BASEDEFS_H 1

#ifndef UASM_PREPROCESSOR_H
#include "preprocessor.h"
#endif  /* UASM_PREPROCESSOR_H */

#ifndef UASM_EXPORTS_H
#include "exports.h"
#endif  /* UASM_EXPORTS_H */

/**
Calling convention  // currently defined for windows only for (MSVC / Intel ICW) & (GCC compatible compiler / Intel ICU), needs researching for other compilers implementation
*/
#if defined(UASM_MSVC_COMPATIBLE_COMPILER) && !defined(UASM_MIC)
#  if defined(UASM_X86_OR_X64_CPU)
#     define UASM_cdecl __cdecl
#     define UASM_stdcall __stdcall
#     define UASM_fastcall __fastcall
#    ifndef UASM_callconv
#      if defined(UASM_VECTORCALL_SUPPORT)
#        if defined(UASM_VC) || defined(UASM_CLANGW) || defined(UASM_ICW)
#           define UASM_callconv __vectorcall
#        else
#           define UASM_callconv __fastcall
#        endif
#      else
#           define UASM_callconv __fastcall
#      endif
#    endif //UASM_callconv
#    ifndef UASM_veccall
#      if defined(UASM_VECTORCALL_SUPPORT)
#        if defined(UASM_VC) || defined(UASM_CLANGW) || defined(UASM_ICW)
#           define UASM_veccall __vectorcall
#        else
#           define UASM_veccall
#        endif
#      else
#           define UASM_veccall
#      endif
#    endif //UASM_veccall
#    ifndef UASM_regcall
#      if defined(UASM_REGCALL_SUPPORT)
#        if defined(UASM_CLANGW) || defined(UASM_ICW) && !defined(UASM_VC)
#           define UASM_regcall __regcall
#        else
#           define UASM_regcall
#        endif
#      else
#           define UASM_regcall
#      endif
#    endif //UASM_regcall
#  else
#       define UASM_cdecl
#       define UASM_stdcall
#       define UASM_fastcall
#       define UASM_callconv
#       define UASM_veccall
#       define UASM_regcall
#   endif //UASM_X86_OR_X64_CPU
#elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#  if defined(UASM_X86_OR_X64_CPU)
#   if defined(UASM_WINDOWS)
#    ifndef UASM_callconv
#      if defined(UASM_VECTORCALL_SUPPORT)
#        if defined(UASM_CLANG) || defined(UASM_ICC)
#           define UASM_callconv __attribute__((vectorcall))
#        elif defined(UASM_GCC)
#           define UASM_callconv __attribute__((ms_abi))
#        else
#           define UASM_callconv __attribute__((fastcall))
#        endif
#      else
#           define UASM_callconv __attribute__((fastcall))
#      endif
#    endif //UASM_callconv
#    ifndef UASM_veccall
#      if defined(UASM_VECTORCALL_SUPPORT)
#        if defined(UASM_CLANG) || defined(UASM_ICC)
#           define UASM_veccall __attribute__((vectorcall))
#        elif defined(UASM_GCC)
#           define UASM_veccall __attribute__((ms_abi))
#        else
#           define UASM_veccall
#        endif
#      else
#           define UASM_veccall
#      endif
#    endif //UASM_veccall
#    ifndef UASM_regcall
#      if defined(UASM_REGCALL_SUPPORT)
#        if defined(UASM_CLANG) || defined(UASM_ICC) && !defined(UASM_VC)
#           define UASM_regcall __attribute__((regcall))
#        else
#           define UASM_regcall
#        endif
#      else
#           define UASM_regcall
#      endif
#    endif //UASM_regcall
/*
# if defined(UASM_ICREGCALL)
#   define UASM_callconv(T) __attribute__((regcall)) T
#   define UASM_veccall(T) __attribute__((regcall)) T
#else*/
#  if defined(UASM_X86_OR_X64_CPU) && !defined(UASM_MIC)
#   define UASM_callconv __attribute__((sysv_abi))
#   define UASM_veccall __attribute__((sysv_abi))
#  else
#   define UASM_callconv
#   define UASM_veccall
#  endif
/*# endif*/
#   if defined(UASM_X86_OR_X64_CPU) && !defined(UASM_MIC)
#   define UASM_cdecl __attribute__((cdecl))
#   define UASM_fastcall __attribute__((fastcall))
#   define UASM_stdcall  __attribute__((stdcall))
# else
#   define UASM_cdecl
#   define UASM_fastcall
#   define UASM_stdcall
# endif
#    endif //UASM_WINDOWS
#   endif //UASM_X86_OR_X64_CPU
#else
#   define UASM_callconv
#   define UASM_veccall
#   define UASM_cdecl
#   define UASM_stdcall
#   define UASM_fastcall
#endif

#if defined(UASM_X86_OR_X64_ABI) && (defined(UASM_MSVC_COMPATIBLE_COMPILER))
#   define UASM_ABI UASM_callconv
//#   define UASM_ABI 
#elif defined(UASM_X86_OR_X64_ABI) && (defined(UASM_GCC_COMPATIBLE_COMPILER))
#   define UASM_ABI UASM_callconv
#else
#   define UASM_ABI
#endif

#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_PACK_PUSH_DEF(X)          __pragma(pack(push, X) )
#   define UASM_PACK_PUSH_1                __pragma(pack(push, 1) )
#   define UASM_PACK_PUSH_2                __pragma(pack(push, 2) )
#   define UASM_PACK_PUSH_4                __pragma(pack(push, 4) )
#   define UASM_PACK_PUSH_8                __pragma(pack(push, 8) )
#   define UASM_PACK_PUSH_16               __pragma(pack(push, 16) )
#   define UASM_PACK_DEF(X)           __pragma(pack(X) )
#   define UASM_PACK_1                 __pragma(pack(1) )
#   define UASM_PACK_2                 __pragma(pack(2) )
#   define UASM_PACK_4                 __pragma(pack(4) )
#   define UASM_PACK_8                 __pragma(pack(8) )
#   define UASM_PACK_16                __pragma(pack(16) )
# if (defined(_MSC_VER) && (_MSC_VER >= 1600)) || (defined(_MSC_VER) && (__INTEL_COMPILER >= 1300))
#   define UASM_PACK_PUSH_32               __pragma(pack(push, 32) )
#   define UASM_PACK_PUSH_64               __pragma(pack(push, 64) )
#   define UASM_PACK_PUSH_128              __pragma(pack(push, 128) )
#   define UASM_PACK_PUSH_256              __pragma(pack(push, 256) )
#   define UASM_PACK_PUSH_512              __pragma(pack(push, 512) )
#   define UASM_PACK_32                __pragma(pack(32) )
#   define UASM_PACK_64                __pragma(pack(64) )
#   define UASM_PACK_128               __pragma(pack(128) )
#   define UASM_PACK_256               __pragma(pack(256) )
#   define UASM_PACK_512               __pragma(pack(512) )
#else
#   define UASM_PACK_PUSH_32               __pragma(pack(push, 16) )
#   define UASM_PACK_PUSH_64               __pragma(pack(push, 16) )
#   define UASM_PACK_PUSH_128              __pragma(pack(push, 16) )
#   define UASM_PACK_PUSH_256              __pragma(pack(push, 16) )
#   define UASM_PACK_PUSH_512              __pragma(pack(push, 16) )
#   define UASM_PACK_32                __pragma(pack(16) )
#   define UASM_PACK_64                __pragma(pack(16) )
#   define UASM_PACK_128               __pragma(pack(16) )
#   define UASM_PACK_256               __pragma(pack(16) )
#   define UASM_PACK_512               __pragma(pack(16) )
# endif
#   define UASM_PACK_PUSH_STACK           __pragma(pack(push, UASM_STACK_SIZE) )
#   define UASM_PACK_PUSH_SIZE_T          __pragma(pack(push, UASM_SIZE_T_SIZE) )
#   define UASM_PACK_PUSH_PTR             __pragma(pack(push, UASM_PTR_SIZE) )
#   define UASM_PACK_STACK                __pragma(pack(UASM_STACK_SIZE) )
#   define UASM_PACK_SIZE_T               __pragma(pack(UASM_SIZE_T_SIZE) )
#   define UASM_PACK_PTR                  __pragma(pack(UASM_PTR_SIZE) )
#   define UASM_PACK_POP                  __pragma(pack(pop) )
#   define UASM_PRAGMA_ONCE               __pragma(once)
#   define UASM_PRAGMA(exprs)             __pragma(exprs)
#   define UASM_PRAGMA_OPTIMIZE_OFF           __pragma(optimize("", off))
#   define UASM_PRAGMA_OPTIMIZE_ON            __pragma(optimize("", on))
#elif (UASM_GCC_COMPATIBLE_COMPILER) && !defined(__SPU__)
#   define UASM_PACK_PUSH_DEF(X)          _Pragma("pack(push, X)")
#   define UASM_PACK_PUSH_1               _Pragma("pack(push, 1)")
#   define UASM_PACK_PUSH_2               _Pragma("pack(push, 2)")
#   define UASM_PACK_PUSH_4               _Pragma("pack(push, 4)")
#   define UASM_PACK_PUSH_8               _Pragma("pack(push, 8)")
#   define UASM_PACK_PUSH_16              _Pragma("pack(push, 16)")
#   define UASM_PACK_PUSH_32              _Pragma("pack(push, 32)")
#   define UASM_PACK_PUSH_64              _Pragma("pack(push, 64)")
#   define UASM_PACK_PUSH_128             _Pragma("pack(push, 128)")
#   define UASM_PACK_PUSH_256             _Pragma("pack(push, 256)")
#   define UASM_PACK_PUSH_512             _Pragma("pack(push, 512)")
#   define UASM_PACK_PUSH_STACK           _Pragma("pack(push, UASM_STACK_SIZE)")
#   define UASM_PACK_PUSH_SIZE_T          _Pragma("pack(push, UASM_SIZE_T_SIZE)")
#   define UASM_PACK_PUSH_PTR         _Pragma("pack(push, UASM_PTR_SIZE)")
#   define UASM_PACK_DEF(X)           _Pragma("pack(X)")
#   define UASM_PACK_1                _Pragma("pack(1)")
#   define UASM_PACK_2                _Pragma("pack(2)")
#   define UASM_PACK_4                _Pragma("pack(4)")
#   define UASM_PACK_8                _Pragma("pack(8)")
#   define UASM_PACK_16               _Pragma("pack(16)")
#   define UASM_PACK_32               _Pragma("pack(32)")
#   define UASM_PACK_64               _Pragma("pack(64)")
#   define UASM_PACK_128              _Pragma("pack(128)")
#   define UASM_PACK_256              _Pragma("pack(256)")
#   define UASM_PACK_512              _Pragma("pack(512)")
#   define UASM_PACK_STACK            _Pragma("pack(UASM_STACK_SIZE)")
#   define UASM_PACK_SIZE_T           _Pragma("pack(UASM_SIZE_T_SIZE)")
#   define UASM_PACK_PTR              _Pragma("pack(UASM_PTR_SIZE)")
#   define UASM_PACK_POP                  _Pragma("pack(pop)")
#   define UASM_PRAGMA_ONCE               _Pragma("once")
#   define UASM_PRAGMA(exprs)             _Pragma(UASM_Stringer(exprs))
# if defined(__clang__)
#   define _PRAGMA_OPTIMIZE_OFF     _Pragma("clang optimize(off)")
#   define _PRAGMA_OPTIMIZE_ON      _Pragma("clang optimize(on)")
# elif defined(__GNUC__)
#   define _PRAGMA_OPTIMIZE_OFF     _Pragma("gcc optimize(off)")
#   define _PRAGMA_OPTIMIZE_ON      _Pragma("gcc optimize(on)")
# endif
#elif defined(UASM_IBMC)
#   define UASM_PACK_PUSH_DEF(X)          _Pragma("pack(X)")
#   define UASM_PACK_PUSH_1                _Pragma("pack(1)")
#   define UASM_PACK_PUSH_2                _Pragma("pack(2)")
#   define UASM_PACK_PUSH_4                _Pragma("pack(4)")
#   define UASM_PACK_PUSH_8                _Pragma("pack(8)")
#   define UASM_PACK_PUSH_16               _Pragma("pack(16)")
#   define UASM_PACK_PUSH_32               _Pragma("pack(32)")
#   define UASM_PACK_PUSH_64               _Pragma("pack(64)")
#   define UASM_PACK_PUSH_128              _Pragma("pack(128)")
#   define UASM_PACK_PUSH_256              _Pragma("pack(256)")
#   define UASM_PACK_PUSH_512              _Pragma("pack(512)")
#   define UASM_PACK_PUSH_STACK            _Pragma("pack(UASM_STACK_SIZE)")
#   define UASM_PACK_PUSH_SIZE_T           _Pragma("pack(UASM_SIZE_T_SIZE)")
#   define UASM_PACK_PUSH_PTR         _Pragma("pack(UASM_PTR_SIZE)")
#   define UASM_PACK_DEF(X)           _Pragma("pack(X)")
#   define UASM_PACK_1                 _Pragma("pack(1)")
#   define UASM_PACK_2                 _Pragma("pack(2)")
#   define UASM_PACK_4                 _Pragma("pack(4)")
#   define UASM_PACK_8                 _Pragma("pack(8)")
#   define UASM_PACK_16                _Pragma("pack(16)")
#   define UASM_PACK_32                _Pragma("pack(32)")
#   define UASM_PACK_64                _Pragma("pack(64)")
#   define UASM_PACK_128               _Pragma("pack(128)")
#   define UASM_PACK_256               _Pragma("pack(256)")
#   define UASM_PACK_512               _Pragma("pack(512)")
#   define UASM_PACK_STACK            _Pragma("pack(UASM_STACK_SIZE)")
#   define UASM_PACK_SIZE_T           _Pragma("pack(UASM_SIZE_T_SIZE)")
#   define UASM_PACK_PTR              _Pragma("pack(UASM_PTR_SIZE)")
#   define UASM_PACK_POP                  _Pragma("pack(pop)")
#   define UASM_PRAGMA_ONCE               _Pragma("once")
#   define UASM_PRAGMA(exprs)             _Pragma(UASM_Stringer(exprs))
#   define _PRAGMA_OPTIMIZE_OFF     _Pragma("ibmc optimize(off)")
#   define _PRAGMA_OPTIMIZE_ON      _Pragma("ibmc optimize(on)")
#else
#   define UASM_PACK_PUSH_DEF(X)
#   define UASM_PACK_PUSH_1
#   define UASM_PACK_PUSH_2
#   define UASM_PACK_PUSH_4
#   define UASM_PACK_PUSH_8
#   define UASM_PACK_PUSH_16
#   define UASM_PACK_PUSH_32
#   define UASM_PACK_PUSH_64
#   define UASM_PACK_PUSH_128
#   define UASM_PACK_PUSH_256
#   define UASM_PACK_PUSH_512
#   define UASM_PACK_PUSH_STACK
#   define UASM_PACK_PUSH_SIZE_T
#   define UASM_PACK_PUSH_PTR
#   define UASM_PACK_DEF(X)
#   define UASM_PACK_1
#   define UASM_PACK_2
#   define UASM_PACK_4
#   define UASM_PACK_8
#   define UASM_PACK_16
#   define UASM_PACK_32
#   define UASM_PACK_64
#   define UASM_PACK_128
#   define UASM_PACK_256
#   define UASM_PACK_512
#   define UASM_PACK_STACK
#   define UASM_PACK_SIZE_T
#   define UASM_PACK_PTR
#   define UASM_PACK_POP
#   define UASM_PRAGMA_ONCE
#   define UASM_PRAGMAERROR(exprs)
#   define UASM_PRAGMA(exprs)
#   define _PRAGMA_OPTIMIZE_OFF
#   define _PRAGMA_OPTIMIZE_ON
#endif

#   define UASM_PACK_PUSH_MM      UASM_PACK_PUSH_8
#   define UASM_PACK_PUSH_XMM     UASM_PACK_PUSH_16
#   define UASM_PACK_PUSH_YMM     UASM_PACK_PUSH_32
#   define UASM_PACK_PUSH_ZMM     UASM_PACK_PUSH_64
#   define UASM_PACK_PUSH_M64      UASM_PACK_PUSH_8
#   define UASM_PACK_PUSH_M128     UASM_PACK_PUSH_16
#   define UASM_PACK_PUSH_M256     UASM_PACK_PUSH_32
#   define UASM_PACK_PUSH_M512     UASM_PACK_PUSH_64

#   define UASM_PACK_MM      UASM_PACK_8
#   define UASM_PACK_XMM     UASM_PACK_16
#   define UASM_PACK_YMM     UASM_PACK_32
#   define UASM_PACK_ZMM     UASM_PACK_64
#   define UASM_PACK_M64      UASM_PACK_8
#   define UASM_PACK_M128     UASM_PACK_16
#   define UASM_PACK_M256     UASM_PACK_32
#   define UASM_PACK_M512     UASM_PACK_64

/**
Inline macro
*/
# if defined(UASM_MSVC_COMPATIBLE_COMPILER)
UASM_PRAGMA(inline_depth(255))
//# pragma inline_depth( 255 )
#   ifndef UASM_INLINE
#     ifndef UASM_DEBUG
// inline on in release build for static inline
#       define __UASM_S_INLINE(T) static __inline T
// inline on in release build for static inline
#       define _UASM_S_INLINE(T) static __inline T

// inline on in release build for static inline
#       define __UASM_S_INLINEART(T) static __inline T
// inline on in release build for static inline
#       define _UASM_S_INLINEART(T) static __inline T

// forceinline on in release build for static forceinline
#       define __UASM_S_FINLINE(T) static __forceinline T
// forceinline on in release build for static forceinline
#       define __UASM_S_FINLINEART(T) static __forceinline T

// inline on in release build for inline only
#       define __UASM_INLINE(T) __inline T
// inline on in release build for inline only
#       define _UASM_INLINE(T) __inline T

// inline on in release build for inline only
#       define __UASM_INLINEART(T) __inline T
// inline on in release build for inline only
#       define _UASM_INLINEART(T) __inline T

// forceinline on release build for forceinline only
#       define __UASM_FINLINE(T) __forceinline T
// forceinline on release build for forceinline only
#       define __UASM_FINLINEART(T) __forceinline T

// inline on in release build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static __inline UASM_veccall(T)
// inline on in release build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static __inline UASM_veccall(T)

// inline on in release build for static inline with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static __inline UASM_veccall(T)
// inline on in release build for static inline with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static __inline UASM_veccall(T)

// forceinline on in release build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static __forceinline UASM_veccall(T)
// forceinline on in release build for static forceinline with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static __forceinline UASM_veccall(T)

// inline on in release build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) __inline UASM_veccall(T)
// inline on in release build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) __inline UASM_veccall(T)

// inline on in release build for inline only with veccall
#       define __UASM_INLINEART_VECCALL(T) __inline UASM_veccall(T)
// inline on in release build for inline only with veccall
#       define _UASM_INLINEART_VECCALL(T) __inline UASM_veccall(T)

// forceinline on in release build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) __forceinline UASM_veccall(T)
// forceinline on in release build for forceinline only with veccall
#       define __UASM_FINLINEART_VECCALL(T) __forceinline UASM_veccall(T)
#     else
// inline of in debug build for static inline
#       define __UASM_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _UASM_S_INLINE(T) static T

// inline of in debug build for static inline
#       define __UASM_S_INLINEART(T) static T
// inline of in debug build for static inline
#       define _UASM_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __UASM_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline
#       define __UASM_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __UASM_INLINE(T) T
// inline of in debug build for inline only
#       define _UASM_INLINE(T) T

// inline of in debug build for inline only
#       define __UASM_INLINEART(T) T
// inline of in debug build for inline only
#       define _UASM_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __UASM_FINLINE(T) T
// forceinline of in debug build for forceinline only
#       define __UASM_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for static inline with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static UASM_veccall(T)
// forceinline of in debug build for static forceinline with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) UASM_veccall(T)

// inline of in debug build for inline only with veccall
#       define __UASM_INLINEART_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only with veccall
#       define _UASM_INLINEART_VECCALL(T) UASM_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) UASM_veccall(T)
// forceinline of in debug build for forceinline only with veccall
#       define __UASM_FINLINEART_VECCALL(T) UASM_veccall(T)
#     endif // UASM_DEBUG

// inline hallways on for static inline
#       define UASM_S_INLINE(T) static __inline T
// inline hallways on for static inline
#       define UASM_S_INLINEART(T) static __inline T

// forceinline hallways on for static forceinline
#       define UASM_S_FINLINE(T) static __forceinline T
// forceinline hallways on for static forceinline
#       define UASM_S_FINLINEART(T) static __forceinline T

// inline hallways on for inline only
#       define UASM_INLINE(T) __inline T
// inline hallways on for inline only
#       define UASM_INLINEART(T) __inline T

// forceinline hallways on for forceinline only
#       define UASM_FINLINE(T) __forceinline T
// forceinline hallways on for forceinline only
#       define UASM_FINLINEART(T) __forceinline T

// inline hallways on for static inline with veccall
#       define UASM_S_INLINE_VECCALL(T) static __inline UASM_veccall(T)
// inline hallways on for static inline with veccall
#       define UASM_S_INLINEART_VECCALL(T) static __inline UASM_veccall(T)

// forceinline hallways on for static forceinline with veccall
#       define UASM_S_FINLINE_VECCALL(T) static __forceinline UASM_veccall(T)
// forceinline hallways on for static forceinline with veccall
#       define UASM_S_FINLINEART_VECCALL(T) static __forceinline UASM_veccall(T)

// inline hallways on for inline only with veccall
#       define UASM_INLINE_VECCALL(T) __inline UASM_veccall(T)
// inline hallways on for inline only with veccall
#       define UASM_INLINEART_VECCALL(T) __inline UASM_veccall(T)

// forceinline hallways on for forceinline only with veccall
#       define UASM_FINLINE_VECCALL(T) __forceinline UASM_veccall(T)
// forceinline hallways on for forceinline only with veccall
#       define UASM_FINLINEART_VECCALL(T) __forceinline UASM_veccall(T)
#   endif // UASM_INLINE
#elif defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_IBMC)
#  if defined(UASM_GNUC) && !defined(UASM_CLANG)
UASM_PRAGMA(inline_depth(255))
#   ifndef UASM_INLINE
#     ifndef UASM_DEBUG
// inline on in release build for static inline
#       define __UASM_S_INLINE(T) static  inline T __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for static inline
#       define _UASM_S_INLINE(T) static  inline T __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for static inline artificial
#       define __UASM_S_INLINEART(T) static  inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for static inline artificial
#       define _UASM_S_INLINEART(T) static  inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for static forceinline
#       define __UASM_S_FINLINE(T) static inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline on in release build for inline only
#       define __UASM_INLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for inline only
#       define _UASM_INLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for inline only artificial
#       define __UASM_INLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for inline only artificial
#       define _UASM_INLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for forceinline only
#       define __UASM_FINLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for forceinline only artificial
#       define __UASM_FINLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline on in release build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline on in release build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for static inline artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for static inline artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for forceinline artificial only with veccall
#       define __UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
#     else
// inline of in debug build for static inline
#       define __UASM_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _UASM_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __UASM_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _UASM_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __UASM_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __UASM_INLINE(T) T
// inline of in debug build for inline only
#       define _UASM_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __UASM_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _UASM_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __UASM_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __UASM_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static UASM_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) UASM_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) UASM_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) UASM_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __UASM_FINLINEART_VECCALL(T) UASM_veccall(T)
#     endif // UASM_DEBUG

// inline hallways on for static inline
#       define UASM_S_INLINE(T)  static inline T __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for static inline artificial
#       define UASM_S_INLINEART(T) static inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for static forceinline
#       define UASM_S_FINLINE(T) static inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for static forceinline artificial
#       define UASM_S_FINLINEART(T) static inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline hallways on for inline only
#       define UASM_INLINE(T)  inline T __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for inline only artificial
#       define UASM_INLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for forceinline only
#       define UASM_FINLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for forceinline only artificial
#       define UASM_FINLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline hallways on for static inline with veccall
#       define UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for static inline artificial with veccall
#       define UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for static forceinline with veccall
#       define UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for static forceinline artificial with veccall
#       define UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline hallways on for inline only with veccall
#       define UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for inline only artificial with veccall
#       define UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for forceinline only with veccall
#       define UASM_FINLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for forceinline only artificial with veccall
#       define UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
#   endif // UASM_INLINE
#  elif defined(UASM_CLANG)
UASM_PRAGMA(inline_depth(255))
#   ifndef UASM_INLINE
#     ifndef UASM_DEBUG
// inline on in release build for static inline
#       define __UASM_S_INLINE(T) static  inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline
#       define _UASM_S_INLINE(T) static  inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline artificial
#       define __UASM_S_INLINEART(T) static  inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline artificial
#       define _UASM_S_INLINEART(T) static  inline T __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for static forceinline
#       define __UASM_S_FINLINE(T) static inline T __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for inline only
#       define __UASM_INLINE(T) inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for inline only
#       define _UASM_INLINE(T) inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for inline only artificial
#       define __UASM_INLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for inline only artificial
#       define _UASM_INLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for forceinline only
#       define __UASM_FINLINE(T) inline T __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for forceinline only artificial
#       define __UASM_FINLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline on in release build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for forceinline artificial only with veccall
#       define __UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
#     else
// inline of in debug build for static inline
#       define __UASM_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _UASM_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __UASM_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _UASM_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __UASM_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __UASM_INLINE(T) T
// inline of in debug build for inline only
#       define _UASM_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __UASM_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _UASM_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __UASM_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __UASM_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static UASM_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) UASM_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) UASM_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) UASM_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __UASM_FINLINEART_VECCALL(T) UASM_veccall(T)
#     endif // UASM_DEBUG

// inline hallways on for static inline
#       define UASM_S_INLINE(T)  static inline T __attribute__((__always_inline__, __nodebug__))
// inline hallways on for static inline artificial
#       define UASM_S_INLINEART(T) static inline T __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for static forceinline
#       define UASM_S_FINLINE(T) static inline T __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for static forceinline artificial
#       define UASM_S_FINLINEART(T) static inline T __attribute__((__always_inline__, __nodebug__))

// inline hallways on for inline only
#       define UASM_INLINE(T)  inline T __attribute__((__always_inline__, __nodebug__))
// inline hallways on for inline only artificial
#       define UASM_INLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for forceinline only
#       define UASM_FINLINE(T) inline T __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for forceinline only artificial
#       define UASM_FINLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// inline hallways on for static inline with veccall
#       define UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline hallways on for static inline artificial with veccall
#       define UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for static forceinline with veccall
#       define UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for static forceinline artificial with veccall
#       define UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline hallways on for inline only with veccall
#       define UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline hallways on for inline only artificial with veccall
#       define UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for forceinline only with veccall
#       define UASM_FINLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for forceinline only artificial with veccall
#       define UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((__always_inline__, __nodebug__))
#   endif // UASM_INLINE
#  else
UASM_PRAGMA(inline_depth(255))
#   ifndef UASM_INLINE
#     ifndef UASM_DEBUG
// inline on in release build for static inline
#       define __UASM_S_INLINE(T) static  inline T __attribute__((always_inline))
// inline on in release build for static inline
#       define _UASM_S_INLINE(T) static  inline T __attribute__((always_inline))

// inline on in release build for static inline artificial
#       define __UASM_S_INLINEART(T) static  inline T __attribute__((always_inline))
// inline on in release build for static inline artificial
#       define _UASM_S_INLINEART(T) static  inline T __attribute__((always_inline))

// forceinline on in release build for static forceinline
#       define __UASM_S_FINLINE(T) static inline T __attribute__((always_inline))
// forceinline on in release build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static inline T __attribute__((always_inline))

// inline on in release build for inline only
#       define __UASM_INLINE(T) inline T __attribute__((always_inline))
// inline on in release build for inline only
#       define _UASM_INLINE(T) inline T __attribute__((always_inline))

// inline on in release build for inline only artificial
#       define __UASM_INLINEART(T) inline T __attribute__((always_inline))
// inline on in release build for inline only artificial
#       define _UASM_INLINEART(T) inline T __attribute__((always_inline))

// forceinline on in release build for forceinline only
#       define __UASM_FINLINE(T) inline T __attribute__((always_inline))
// forceinline on in release build for forceinline only artificial
#       define __UASM_FINLINEART(T) inline T __attribute__((always_inline))

// inline on in release build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))
// inline on in release build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))

// inline on in release build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))
// inline on in release build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))

// forceinline on in release build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))
// forceinline on in release build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))

// inline on in release build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
// inline on in release build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))

// inline on in release build for static inline artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
// inline on in release build for static inline artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))

// forceinline on in release build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
// forceinline on in release build for forceinline artificial only with veccall
#       define __UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
#     else
// inline of in debug build for static inline
#       define __UASM_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _UASM_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __UASM_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _UASM_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __UASM_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __UASM_INLINE(T) T
// inline of in debug build for inline only
#       define _UASM_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __UASM_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _UASM_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __UASM_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __UASM_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static UASM_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) UASM_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) UASM_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) UASM_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __UASM_FINLINEART_VECCALL(T) UASM_veccall(T)
#     endif // UASM_DEBUG

// inline hallways on for static inline
#       define UASM_S_INLINE(T)  static inline T __attribute__((always_inline))
// inline hallways on for static inline artificial
#       define UASM_S_INLINEART(T) static inline T __attribute__((always_inline))

// forceinline hallways on for static forceinline
#       define UASM_S_FINLINE(T) static inline T __attribute__((always_inline))
// forceinline hallways on for static forceinline artificial
#       define UASM_S_FINLINEART(T) static inline T __attribute__((always_inline))

// inline hallways on for inline only
#       define UASM_INLINE(T)  inline T __attribute__((always_inline))
// inline hallways on for inline only artificial
#       define UASM_INLINEART(T) inline T __attribute__((always_inline))

// forceinline hallways on for forceinline only
#       define UASM_FINLINE(T) inline T __attribute__((always_inline))
// forceinline hallways on for forceinline only artificial
#       define UASM_FINLINEART(T) inline T __attribute__((always_inline))

// inline hallways on for static inline with veccall
#       define UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))
// inline hallways on for static inline artificial with veccall
#       define UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))

// forceinline hallways on for static forceinline with veccall
#       define UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))
// forceinline hallways on for static forceinline artificial with veccall
#       define UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T) __attribute__((always_inline))

// inline hallways on for inline only with veccall
#       define UASM_INLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
// inline hallways on for inline only artificial with veccall
#       define UASM_INLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))

// forceinline hallways on for forceinline only with veccall
#       define UASM_FINLINE_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
// forceinline hallways on for forceinline only artificial with veccall
#       define UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T) __attribute__((always_inline))
#   endif // UASM_INLINE
#  endif // UASM_GNUC
#else
//UASM_PRAGMA(inline_depth(255))
#   ifndef UASM_INLINE
#     ifndef UASM_DEBUG
// inline on in release build for static inline
#       define __UASM_S_INLINE(T) static  inline T
// inline on in release build for static inline
#       define _UASM_S_INLINE(T) static  inline T

// inline on in release build for static inline artificial
#       define __UASM_S_INLINEART(T) static  inline T
// inline on in release build for static inline artificial
#       define _UASM_S_INLINEART(T) static  inline T

// forceinline on in release build for static forceinline
#       define __UASM_S_FINLINE(T) static inline T
// forceinline on in release build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static inline T

// inline on in release build for inline only
#       define __UASM_INLINE(T) inline T
// inline on in release build for inline only
#       define _UASM_INLINE(T) inline T

// inline on in release build for inline only artificial
#       define __UASM_INLINEART(T) inline T
// inline on in release build for inline only artificial
#       define _UASM_INLINEART(T) inline T

// forceinline on in release build for forceinline only
#       define __UASM_FINLINE(T) inline T
// forceinline on in release build for forceinline only artificial
#       define __UASM_FINLINEART(T) inline T

// inline on in release build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T)
// inline on in release build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T)

// inline on in release build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T)
// inline on in release build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T)

// forceinline on in release build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T)
// forceinline on in release build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T)

// inline on in release build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) inline UASM_veccall(T)
// inline on in release build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) inline UASM_veccall(T)

// inline on in release build for static inline artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) inline UASM_veccall(T)
// inline on in release build for static inline artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) inline UASM_veccall(T)

// forceinline on in release build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) inline UASM_veccall(T)
// forceinline on in release build for forceinline artificial only with veccall
#       define __UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T)
#     else
// inline of in debug build for static inline
#       define __UASM_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _UASM_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __UASM_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _UASM_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __UASM_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __UASM_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __UASM_INLINE(T) T
// inline of in debug build for inline only
#       define _UASM_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __UASM_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _UASM_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __UASM_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __UASM_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline with veccall
#       define _UASM_S_INLINE_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _UASM_S_INLINEART_VECCALL(T) static UASM_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __UASM_S_FINLINE_VECCALL(T) static UASM_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __UASM_S_FINLINEART_VECCALL(T) static UASM_veccall(T)

// inline of in debug build for inline only with veccall
#       define __UASM_INLINE_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only with veccall
#       define _UASM_INLINE_VECCALL(T) UASM_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __UASM_INLINEART_VECCALL(T) UASM_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _UASM_INLINEART_VECCALL(T) UASM_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __UASM_FINLINE_VECCALL(T) UASM_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __UASM_FINLINEART_VECCALL(T) UASM_veccall(T)
#     endif // UASM_DEBUG

// inline hallways on for static inline
#       define UASM_S_INLINE(T)  static inline T
// inline hallways on for static inline artificial
#       define UASM_S_INLINEART(T) static inline T

// forceinline hallways on for static forceinline
#       define UASM_S_FINLINE(T) static inline T
// forceinline hallways on for static forceinline artificial
#       define UASM_S_FINLINEART(T) static inline T

// inline hallways on for inline only
#       define UASM_INLINE(T)  inline T
// inline hallways on for inline only artificial
#       define UASM_INLINEART(T) inline T

// forceinline hallways on for forceinline only
#       define UASM_FINLINE(T) inline T
// forceinline hallways on for forceinline only artificial
#       define UASM_FINLINEART(T) inline T

// inline hallways on for static inline with veccall
#       define UASM_S_INLINE_VECCALL(T) static inline UASM_veccall(T)
// inline hallways on for static inline artificial with veccall
#       define UASM_S_INLINEART_VECCALL(T) static inline UASM_veccall(T)

// forceinline hallways on for static forceinline with veccall
#       define UASM_S_FINLINE_VECCALL(T) static inline UASM_veccall(T)
// forceinline hallways on for static forceinline artificial with veccall
#       define UASM_S_FINLINEART_VECCALL(T) static inline UASM_veccall(T)

// inline hallways on for inline only with veccall
#       define UASM_INLINE_VECCALL(T) inline UASM_veccall(T)
// inline hallways on for inline only artificial with veccall
#       define UASM_INLINEART_VECCALL(T) inline UASM_veccall(T)

// forceinline hallways on for forceinline only with veccall
#       define UASM_FINLINE_VECCALL(T) inline UASM_veccall(T)
// forceinline hallways on for forceinline only artificial with veccall
#       define UASM_FINLINEART_VECCALL(T) inline UASM_veccall(T)
#   endif // UASM_INLINE
# endif

/**
Nullptr macro
*/
# if (defined(__cplusplus) && (__cplusplus >= 201103L)) || defined(_MSC_VER)
#   if defined(_MSC_VER) && (_MSC_VER >= 1800)
#       define UASM_NULLPTR nullptr
#   else
#       define UASM_NULLPTR NULL
#   endif
#elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#  if defined(UASM_GNUC) || defined(UASM_CLANGU)
#       define UASM_NULLPTR __null
#  elif defined(__cplusplus)
#       define UASM_NULLPTR 0
#  else
#       define UASM_NULLPTR ((void*)0)
#  endif
#else
#       define UASM_NULLPTR
#endif

#ifdef UASM_CUDACC
//#   define _INC_MATH 1  /*  Try some workaround to block math header from mix with CUDA math functions */
#include <host_config.h>
#include <host_defines.h>
#include <cuda.h>
/*
#include <math_functions.h>
#include <device_functions.h>
#include <device_functions_decls.h>*/
//#undef _INC_MATH  /*  Secure the math header to be included after we include the cuda math functions header, >TODO needs directory inclusion fixing with some .props methods */
#endif

/**
Noinline macro
*/
#if defined(UASM_CUDACC)
#   define UASM_NOINLINE __noinline__
#elif defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_NOINLINE __declspec(noinline)
#elif defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_IBMC)
#   define UASM_NOINLINE __attribute__((noinline))
#else
#   define UASM_NOINLINE
#endif

/**
Constexpr macro
*/
#if defined(UASM_CONSTEXPR_SUPPORT)
#   define UASM_constexpr constexpr
#   define UASM_const constexpr
#else
#   define UASM_constexpr
#   define UASM_const const
#endif

/**
Empty function class body macro
*/
#if defined(UASM_DEFAULT_CTOR_SUPPORT)
#   define UASM_default =default
#else
#   define UASM_default
#endif

/**
No exception function class body macro
*/
#if defined(UASM_NOEXCEPT_SUPPORT)
#   define UASM_noexcept noexcept
#else
#   define UASM_noexcept
#endif

/*! restrict macro */
#if defined(UASM_CUDACC)
# if defined(UASM_MSVC_COMPATIBLE_COMPILER) && (_MSC_VER >= 1400))
#   define __UASM_RESTRICT __declspec(restrict)
# elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#   define __UASM_RESTRICT __attribute__((restrict))
# else
#   define __UASM_RESTRICT
# endif
#   define UASM_RESTRICT __restrict__
#elif (defined(UASM_MSVC_COMPATIBLE_COMPILER) && (_MSC_VER >= 1400))
#   define __UASM_RESTRICT __declspec(restrict)
#   define UASM_RESTRICT __restrict
#elif (defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_IBMC)) && !defined(UASM_PS4) // ps4 doesn't like restricted functions
#   define __UASM_RESTRICT __attribute__((restrict))
#   define UASM_RESTRICT __restrict__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#   define UASM_RESTRICT restrict
#else
#   define __UASM_RESTRICT
#   define UASM_RESTRICT
#endif

/* noalias macro */
#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_NOALIAS __declspec(noalias)
#elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#   define UASM_NOALIAS __attribute__((noalias))
#else
#   define UASM_NOALIAS
#endif

/* property macro */
#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define __UASM_PROPERTY(exa,exb) __declspec(property(exa, exb))
#else
#   define __UASM_PROPERTY(exa,exb) __attribute__((property(exa, exb)))
#endif

/* notrow macro */
#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#ifdef  __cplusplus
#ifndef UASM_NOTHROW
# define UASM_NOTHROW __declspec(nothrow)
#endif
#else
#ifndef UASM_NOTHROW
# define UASM_NOTHROW
#endif
#endif
#else
#ifndef UASM_NOTHROW
# define UASM_NOTHROW
#endif
#endif

/* noreturn macro */
#if defined(UASM_CUDACC)
#   define UASM_NORETURN __attribute__((noreturn))
#elif defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_NORETURN __declspec(noreturn)
#elif defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_IBMC)
#   define UASM_NORETURN __attribute__((noreturn))
#else
#   define UASM_NORETURN
#endif

#   define UASM_COUNT_OF(x) (sizeof(x) / sizeof(x[0]))

/* alignof macro */
#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_ALIGN_OF(X) __alignof(X)
#elif defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_IBMC)
#   define UASM_ALIGN_OF(X) __alignof__(X)
#elif defined(UASM_MWERKS)
#   define UASM_ALIGN_OF(X) __builtin_align(X)
#elif defined(UASM_ARMCC)
#   define UASM_ALIGN_OF(X) __ALIGNOF__(X)
#else
#   define UASM_ALIGN_OF(x)
#endif

#if defined(UASM_GCC_COMPATIBLE_COMPILER)
#   define UASM_LIKELY(x) (__builtin_expect(!!(x), 1))
#   define UASM_UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else
#   define UASM_LIKELY(x) (!!(x))
#   define UASM_UNLIKELY(x) (!!(x))
#endif

/* override and final macro */
#if defined(UASM_MSVC_COMPATIBLE_COMPILER) && defined(__cplusplus)
#   if (_MSC_VER >= 1700)
#       define UASM_OVERRIDE override
#       define UASM_FINAL final
#       define UASM_FINAL_OVERRIDE final override
#   elif (_MSC_VER >= 1600)
#       define UASM_OVERRIDE override
#       define UASM_FINAL sealed
#       define UASM_FINAL_OVERRIDE sealed override
#endif
#endif

/* intrin_type macro and vector size*/
# if defined(UASM_MSVC_COMPATIBLE_COMPILER) && (_MSC_VER >= 1400)
#  if !defined(__INTEL_COMPILER) && (_MSC_FULL_VER < 160020506)
#       define uXVC_VEC_INTRINTYPE(X) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE_ALIAS(X) __declspec(intrin_type)

#       define uXVC_VEC_INTRINTYPE4 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE8 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE16 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE32 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE64 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE128 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE256 __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE512 __declspec(intrin_type)

#       define uXVC_VEC_INTRINTYPE4_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE8_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE16_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE32_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE64_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE128_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE256_ALIAS __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE512_ALIAS __declspec(intrin_type)
#  else
#   if !defined(__INTEL_COMPILER)
#       define uXVC_VEC_INTRINTYPE(X) __declspec(intrin_type) __declspec(align(X))
#       define uXVC_VEC_INTRINTYPE_ALIAS(X) __declspec(intrin_type) __declspec(align(X))

#       define uXVC_VEC_INTRINTYPE4 __declspec(intrin_type) __declspec(align(4))
#       define uXVC_VEC_INTRINTYPE8 __declspec(intrin_type) __declspec(align(8))
#       define uXVC_VEC_INTRINTYPE16 __declspec(intrin_type) __declspec(align(16))
#       define uXVC_VEC_INTRINTYPE32 __declspec(intrin_type) __declspec(align(32))
#       define uXVC_VEC_INTRINTYPE64 __declspec(intrin_type) __declspec(align(64))
#       define uXVC_VEC_INTRINTYPE128 __declspec(intrin_type) __declspec(align(128))
#       define uXVC_VEC_INTRINTYPE256 __declspec(intrin_type) __declspec(align(256))
#       define uXVC_VEC_INTRINTYPE512 __declspec(intrin_type) __declspec(align(512))

#       define uXVC_VEC_INTRINTYPE4_ALIAS __declspec(intrin_type) __declspec(align(4))
#       define uXVC_VEC_INTRINTYPE8_ALIAS __declspec(intrin_type) __declspec(align(8))
#       define uXVC_VEC_INTRINTYPE16_ALIAS __declspec(intrin_type) __declspec(align(16))
#       define uXVC_VEC_INTRINTYPE32_ALIAS __declspec(intrin_type) __declspec(align(32))
#       define uXVC_VEC_INTRINTYPE64_ALIAS __declspec(intrin_type) __declspec(align(64))
#       define uXVC_VEC_INTRINTYPE128_ALIAS __declspec(intrin_type) __declspec(align(128))
#       define uXVC_VEC_INTRINTYPE256_ALIAS __declspec(intrin_type) __declspec(align(256))
#       define uXVC_VEC_INTRINTYPE512_ALIAS __declspec(intrin_type) __declspec(align(512))
#   else
#       define uXVC_VEC_INTRINTYPE(X) __declspec(align(X)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE_ALIAS(X) __declspec(align(X)) __declspec(intrin_type)

#       define uXVC_VEC_INTRINTYPE4 __declspec(align(4)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE8 __declspec(align(8)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE16 __declspec(align(16)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE32 __declspec(align(32)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE64 __declspec(align(64)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE128 __declspec(align(128)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE256 __declspec(align(256)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE512 __declspec(align(512)) __declspec(intrin_type)

#       define uXVC_VEC_INTRINTYPE4_ALIAS __declspec(align(4)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE8_ALIAS __declspec(align(8)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE16_ALIAS __declspec(align(16)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE32_ALIAS __declspec(align(32)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE64_ALIAS __declspec(align(64)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE128_ALIAS __declspec(align(128)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE256_ALIAS __declspec(align(256)) __declspec(intrin_type)
#       define uXVC_VEC_INTRINTYPE512_ALIAS __declspec(align(512)) __declspec(intrin_type)
#   endif
#  endif

#       define UASM_VEC_SIZE_INTRINTYPE(Type,Name,size) __declspec(align(size)) Type Name[size]
#       define UASM_VEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) __declspec(align(size)) Type Name[size]

#       define UASM_NEONVEC_SIZE_INTRINTYPE(Type,Name,size) __declspec(align(size)) Type Name[size]
#       define UASM_NEONVEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) __declspec(align(size)) Type Name[size]

#       define UASM_VEC_SIZE(Type,Name,size) __declspec(align(size)) Type Name[size]
#       define UASM_VEC_SIZE_ALIAS(Type,Name,size) __declspec(align(size)) Type Name[size]

#       define uXGC_VEC_INTRINTYPE(X)
#       define uXGC_VEC_INTRINTYPE_ALIAS(X)

#       define uXGC_VEC_INTRINTYPE4
#       define uXGC_VEC_INTRINTYPE8
#       define uXGC_VEC_INTRINTYPE16
#       define uXGC_VEC_INTRINTYPE32
#       define uXGC_VEC_INTRINTYPE64
#       define uXGC_VEC_INTRINTYPE128
#       define uXGC_VEC_INTRINTYPE256
#       define uXGC_VEC_INTRINTYPE512

#       define uXGC_VEC_INTRINTYPE4_ALIAS
#       define uXGC_VEC_INTRINTYPE8_ALIAS
#       define uXGC_VEC_INTRINTYPE16_ALIAS
#       define uXGC_VEC_INTRINTYPE32_ALIAS
#       define uXGC_VEC_INTRINTYPE64_ALIAS
#       define uXGC_VEC_INTRINTYPE128_ALIAS
#       define uXGC_VEC_INTRINTYPE256_ALIAS
#       define uXGC_VEC_INTRINTYPE512_ALIAS
# elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#       define uXGC_VEC_INTRINTYPE(X) __attribute__((__vector_size__(4), __aligned__(X)))
#       define uXGC_VEC_INTRINTYPE_ALIAS(X) __attribute__((__vector_size__(4), __aligned__(X), __may_alias__))

#       define UASM_VEC_SIZE_INTRINTYPE(Type,Name,size) Type Name __attribute__((__vector_size__(size), __aligned__(X)))
#       define UASM_VEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name __attribute__((__vector_size__(size), __aligned__(X), __may_alias__))

#       define UASM_NEONVEC_SIZE_INTRINTYPE(Type,Name,size) Type Name __attribute__((neon_vector_type(size), __aligned__(X)))
#       define UASM_NEONVEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name __attribute__((neon_vector_type(size), __aligned__(X), __may_alias__))

#       define UASM_VEC_SIZE(Type,Name,size) Type Name[size] __attribute__((__aligned__(size)))
#       define UASM_VEC_SIZE_ALIAS(Type,Name,size) Type Name[size] __attribute__((__aligned__(size), __may_alias__))

#       define uXGC_VEC_INTRINTYPE4 __attribute__((__vector_size__(4), __aligned__(4)))
#       define uXGC_VEC_INTRINTYPE8 __attribute__((__vector_size__(8), __aligned__(8)))
#       define uXGC_VEC_INTRINTYPE16 __attribute__((__vector_size__(16), __aligned__(16)))
#       define uXGC_VEC_INTRINTYPE32 __attribute__((__vector_size__(32), __aligned__(32)))
#       define uXGC_VEC_INTRINTYPE64 __attribute__((__vector_size__(64), __aligned__(64)))
#       define uXGC_VEC_INTRINTYPE128 __attribute__((__vector_size__(64), __aligned__(128)))
#       define uXGC_VEC_INTRINTYPE256 __attribute__((__vector_size__(64), __aligned__(256)))
#       define uXGC_VEC_INTRINTYPE512 __attribute__((__vector_size__(64), __aligned__(512)))

#       define uXGC_VEC_INTRINTYPE4_ALIAS __attribute__((__vector_size__(64), __aligned__(4), __may_alias__))
#       define uXGC_VEC_INTRINTYPE8_ALIAS __attribute__((__vector_size__(64), __aligned__(8), __may_alias__))
#       define uXGC_VEC_INTRINTYPE16_ALIAS __attribute__((__vector_size__(64), __aligned__(16), __may_alias__))
#       define uXGC_VEC_INTRINTYPE32_ALIAS __attribute__((__vector_size__(64), __aligned__(32), __may_alias__))
#       define uXGC_VEC_INTRINTYPE64_ALIAS __attribute__((__vector_size__(64), __aligned__(64), __may_alias__))
#       define uXGC_VEC_INTRINTYPE128_ALIAS __attribute__((__vector_size__(64), __aligned__(128), __may_alias__))
#       define uXGC_VEC_INTRINTYPE256_ALIAS __attribute__((__vector_size__(64), __aligned__(256), __may_alias__))
#       define uXGC_VEC_INTRINTYPE512_ALIAS __attribute__((__vector_size__(64), __aligned__(512), __may_alias__))

#   define uXVC_VEC_INTRINTYPE(X)
#   define uXVC_VEC_INTRINTYPE_ALIAS(X)

#       define uXVC_VEC_INTRINTYPE4
#       define uXVC_VEC_INTRINTYPE8
#       define uXVC_VEC_INTRINTYPE16
#       define uXVC_VEC_INTRINTYPE32
#       define uXVC_VEC_INTRINTYPE64
#       define uXVC_VEC_INTRINTYPE128
#       define uXVC_VEC_INTRINTYPE256
#       define uXVC_VEC_INTRINTYPE512

#       define uXVC_VEC_INTRINTYPE4_ALIAS
#       define uXVC_VEC_INTRINTYPE8_ALIAS
#       define uXVC_VEC_INTRINTYPE16_ALIAS
#       define uXVC_VEC_INTRINTYPE32_ALIAS
#       define uXVC_VEC_INTRINTYPE64_ALIAS
#       define uXVC_VEC_INTRINTYPE128_ALIAS
#       define uXVC_VEC_INTRINTYPE256_ALIAS
#       define uXVC_VEC_INTRINTYPE512_ALIAS
# else
#       define uXVC_VEC_INTRINTYPE(X)
#       define uXGC_VEC_INTRINTYPE(X)
#       define uXVC_VEC_INTRINTYPE_ALIAS(X)
#       define uXGC_VEC_INTRINTYPE_ALIAS(X)

#       define UASM_VEC_SIZE_INTRINTYPE(Type,Name,size) Type Name[size]
#       define UASM_VEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name[size]

#       define UASM_NEONVEC_SIZE_INTRINTYPE(Type,Name,size) Type Name[size]
#       define UASM_NEONVEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name[size]

#       define UASM_VEC_SIZE(Type,Name,size) Type Name[size]
#       define UASM_VEC_SIZE_ALIAS(Type,Name,size) Type Name[size]

#       define uXVC_VEC_INTRINTYPE4
#       define uXVC_VEC_INTRINTYPE8
#       define uXVC_VEC_INTRINTYPE16
#       define uXVC_VEC_INTRINTYPE32
#       define uXVC_VEC_INTRINTYPE64
#       define uXVC_VEC_INTRINTYPE128
#       define uXVC_VEC_INTRINTYPE256
#       define uXVC_VEC_INTRINTYPE512

#       define uXVC_VEC_INTRINTYPE4_ALIAS
#       define uXVC_VEC_INTRINTYPE8_ALIAS
#       define uXVC_VEC_INTRINTYPE16_ALIAS
#       define uXVC_VEC_INTRINTYPE32_ALIAS
#       define uXVC_VEC_INTRINTYPE64_ALIAS
#       define uXVC_VEC_INTRINTYPE128_ALIAS
#       define uXVC_VEC_INTRINTYPE256_ALIAS
#       define uXVC_VEC_INTRINTYPE512_ALIAS

#       define uXGC_VEC_INTRINTYPE4
#       define uXGC_VEC_INTRINTYPE8
#       define uXGC_VEC_INTRINTYPE16
#       define uXGC_VEC_INTRINTYPE32
#       define uXGC_VEC_INTRINTYPE64
#       define uXGC_VEC_INTRINTYPE128
#       define uXGC_VEC_INTRINTYPE256
#       define uXGC_VEC_INTRINTYPE512

#       define uXGC_VEC_INTRINTYPE4_ALIAS
#       define uXGC_VEC_INTRINTYPE8_ALIAS
#       define uXGC_VEC_INTRINTYPE16_ALIAS
#       define uXGC_VEC_INTRINTYPE32_ALIAS
#       define uXGC_VEC_INTRINTYPE64_ALIAS
#       define uXGC_VEC_INTRINTYPE128_ALIAS
#       define uXGC_VEC_INTRINTYPE256_ALIAS
#       define uXGC_VEC_INTRINTYPE512_ALIAS
# endif

// example vec size
// typedef UASM_VEC_SIZE_INTRINTYPE(int, __v8si, 32); // = to VC: typedef __declspec(align(32)) int __v8si[32], or GNUC: typedef int __v8si __attribute__((__vector_size__(32)))

/* virtual macro */
#if !defined(UASM_NO_VIRTUAL) && defined(__cplusplus)
#   define UASM_virtual virtual
#   define UASM_virtualinit = 0
#else
#   define UASM_virtual
#   define UASM_virtualinit
#endif

/* explicit macro */
#if !defined(UASM_NO_EXPLICIT) && defined(__cplusplus)
#   define UASM_explicit explicit
#else
#   define UASM_explicit
#endif

#if defined(UASM_INTELCC_GFX)
# if defined(_MSC_VER)
#   define __Intel_host__
#   define __Intel_device__             __declspec(target(gfx))
#   define __Intel_device_builtin__
# else
#   define __Intel_host__
#   define __Intel_device__             __attribute__((target(gfx)))
#   define __Intel_device_builtin__
# endif
#else
#   define __Intel_host__
#   define __Intel_device__
#   define __Intel_device_builtin__
#endif

#if defined(UASM_CUDACC)
#   define __Cuda_host__                __host__
#   define __Cuda_device__              __device__
#   define __Cuda_device_builtin__      __device_builtin__
#else
#   define __Cuda_host__
#   define __Cuda_device__
#   define __Cuda_device_builtin__
#endif

#if defined(UASM_CUDACC)
#   define UASM_TARGET_CPU_GPU                        __Cuda_host__ __Cuda_device__
#   define UASM_TARGET_CPU_ONLY                       __Cuda_host__
#   define UASM_TARGET_GPU_ONLY                       __Cuda_device__
#   define UASM_TARGET_DEVICE_BUILTIN             __Cuda_device_builtin__
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN        __Cuda_device__ __Cuda_device_builtin__
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN         __Cuda_host__ __Cuda_device__ __Cuda_device_builtin__
#elif defined(UASM_INTELCC_GFX)
#   define UASM_TARGET_CPU_GPU                        __Intel_host__ __Intel_device__
#   define UASM_TARGET_CPU_ONLY                       __Intel_host__
#   define UASM_TARGET_GPU_ONLY                       __Intel_device__
#   define UASM_TARGET_DEVICE_BUILTIN             __Intel_device_builtin__
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN        __Intel_device__ __Intel_device_builtin__
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN         __Intel_host__ __Intel_device__ __Intel_device_builtin__
#else
#   define UASM_TARGET_CPU_GPU
#   define UASM_TARGET_CPU_ONLY
#   define UASM_TARGET_GPU_ONLY
#   define UASM_TARGET_DEVICE_BUILTIN
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN
#endif

#if defined(UASM_CC_PDEF_GPU_SUPPORT)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_INLINE(T) UASM_S_INLINE(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_FINLINE(T) UASM_S_FINLINE(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_INLINE(T) UASM_INLINE(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_FINLINE(T) UASM_FINLINE(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)

#   define UASM_TARGET_GPU_ONLY_S_INLINE(T) UASM_S_INLINE(UASM_TARGET_GPU_ONLY T)
#   define UASM_TARGET_GPU_ONLY_S_FINLINE(T) UASM_S_FINLINE(UASM_TARGET_GPU_ONLY T)
#   define UASM_TARGET_GPU_ONLY_INLINE(T) UASM_INLINE(UASM_TARGET_GPU_ONLY T)
#   define UASM_TARGET_GPU_ONLY_FINLINE(T) UASM_FINLINE(UASM_TARGET_GPU_ONLY T)

#   define UASM_TARGET_CPU_ONLY_S_INLINE(T) UASM_S_INLINE(UASM_TARGET_CPU_ONLY T)
#   define UASM_TARGET_CPU_ONLY_S_FINLINE(T) UASM_S_FINLINE(UASM_TARGET_CPU_ONLY T)
#   define UASM_TARGET_CPU_ONLY_INLINE(T) UASM_INLINE(UASM_TARGET_CPU_ONLY T)
#   define UASM_TARGET_CPU_ONLY_FINLINE(T) UASM_FINLINE(UASM_TARGET_CPU_ONLY T)

#   define UASM_TARGET_CPU_ONLY_S_INLINE_VECCALL(T) UASM_S_INLINE(UASM_TARGET_CPU_ONLY T)
#   define UASM_TARGET_CPU_ONLY_S_FINLINE_VECCALL(T) UASM_S_FINLINE(UASM_TARGET_CPU_ONLY T)
#   define UASM_TARGET_CPU_ONLY_INLINE_VECCALL(T) UASM_INLINE(UASM_TARGET_CPU_ONLY T)
#   define UASM_TARGET_CPU_ONLY_FINLINE_VECCALL(T) UASM_FINLINE(UASM_TARGET_CPU_ONLY T)

#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE(T) UASM_S_INLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE(T) UASM_S_FINLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE(T) UASM_INLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_FINLINE(T) UASM_FINLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)

#   define UASM_TARGET_CPU_GPU_S_INLINE(T) UASM_S_INLINE(UASM_TARGET_CPU_GPU T)
#   define UASM_TARGET_CPU_GPU_S_FINLINE(T) UASM_S_FINLINE(UASM_TARGET_CPU_GPU T)
#   define UASM_TARGET_CPU_GPU_INLINE(T) UASM_INLINE(UASM_TARGET_CPU_GPU T)
#   define UASM_TARGET_CPU_GPU_FINLINE(T) UASM_FINLINE(UASM_TARGET_CPU_GPU T)

#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE_VECCALL(T) UASM_S_INLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE_VECCALL(T) UASM_S_FINLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE_VECCALL(T) UASM_INLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define UASM_TARGET_CPU_GP_DEVICE_BUILTINU_FINLINE_VECCALL(T) UASM_FINLINE(UASM_TARGET_CPU_GPU_DEVICE_BUILTIN T)

#   define UASM_TARGET_CPU_GPU_S_INLINE_VECCALL(T) UASM_S_INLINE(UASM_TARGET_CPU_GPU T)
#   define UASM_TARGET_CPU_GPU_S_FINLINE_VECCALL(T) UASM_S_FINLINE(UASM_TARGET_CPU_GPU T)
#   define UASM_TARGET_CPU_GPU_INLINE_VECCALL(T) UASM_INLINE(UASM_TARGET_CPU_GPU T)
#   define UASM_TARGET_CPU_GPU_FINLINE_VECCALL(T) UASM_FINLINE(UASM_TARGET_CPU_GPU T)
#else
# if defined(UASM_INTRINSICS_SUPPORT)

#   define UASM_TARGET_CPU_ONLY_S_INLINE_VECCALL(T) UASM_S_INLINE_VECCALL(T)
#   define UASM_TARGET_CPU_ONLY_S_FINLINE_VECCALL(T) UASM_S_FINLINE_VECCALL(T)
#   define UASM_TARGET_CPU_ONLY_INLINE_VECCALL(T) UASM_INLINE_VECCALL(T)
#   define UASM_TARGET_CPU_ONLY_FINLINE_VECCALL(T) UASM_FINLINE_VECCALL(T)

#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE_VECCALL(T) UASM_S_INLINE_VECCALL(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE_VECCALL(T) UASM_S_FINLINE_VECCALL(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE_VECCALL(T) UASM_INLINE_VECCALL(T)
#   define UASM_TARGET_CPU_GP_DEVICE_BUILTINU_FINLINE_VECCALL(T) UASM_FINLINE_VECCALL(T)

#   define UASM_TARGET_CPU_GPU_S_INLINE_VECCALL(T) UASM_S_INLINE_VECCALL(T)
#   define UASM_TARGET_CPU_GPU_S_FINLINE_VECCALL(T) UASM_S_FINLINE_VECCALL(T)
#   define UASM_TARGET_CPU_GPU_INLINE_VECCALL(T) UASM_INLINE_VECCALL(T)
#   define UASM_TARGET_CPU_GPU_FINLINE_VECCALL(T) UASM_FINLINE_VECCALL(T)
# else

#   define UASM_TARGET_CPU_ONLY_S_INLINE_VECCALL(T) UASM_S_INLINE(T)
#   define UASM_TARGET_CPU_ONLY_S_FINLINE_VECCALL(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_CPU_ONLY_INLINE_VECCALL(T) UASM_INLINE(T)
#   define UASM_TARGET_CPU_ONLY_FINLINE_VECCALL(T) UASM_FINLINE(T)

#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE_VECCALL(T) UASM_S_INLINE(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE_VECCALL(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE_VECCALL(T) UASM_INLINE(T)
#   define UASM_TARGET_CPU_GP_DEVICE_BUILTINU_FINLINE_VECCALL(T) UASM_FINLINE(T)

#   define UASM_TARGET_CPU_GPU_S_INLINE_VECCALL(T) UASM_S_INLINE(T)
#   define UASM_TARGET_CPU_GPU_S_FINLINE_VECCALL(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_CPU_GPU_INLINE_VECCALL(T) UASM_INLINE(T)
#   define UASM_TARGET_CPU_GPU_FINLINE_VECCALL(T) UASM_FINLINE(T)
# endif

#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_INLINE(T) UASM_S_INLINE(T)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_FINLINE(T) UASM_S_FINLINE( T)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_INLINE(T) UASM_INLINE(T)
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_FINLINE(T) UASM_FINLINE(T)

#   define UASM_TARGET_GPU_ONLY_S_INLINE(T) UASM_S_INLINE(T)
#   define UASM_TARGET_GPU_ONLY_S_FINLINE(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_GPU_ONLY_INLINE(T) UASM_INLINE(T)
#   define UASM_TARGET_GPU_ONLY_FINLINE(T) UASM_FINLINE(T)

#   define UASM_TARGET_CPU_ONLY_S_INLINE(T) UASM_S_INLINE(T)
#   define UASM_TARGET_CPU_ONLY_S_FINLINE(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_CPU_ONLY_INLINE(T) UASM_INLINE(T)
#   define UASM_TARGET_CPU_ONLY_FINLINE(T) UASM_FINLINE(T)

#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE(T) UASM_S_INLINE(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE(T) UASM_INLINE(T)
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_FINLINE(T) UASM_FINLINE(T)

#   define UASM_TARGET_CPU_GPU_S_INLINE(T) UASM_S_INLINE(T)
#   define UASM_TARGET_CPU_GPU_S_FINLINE(T) UASM_S_FINLINE(T)
#   define UASM_TARGET_CPU_GPU_INLINE(T) UASM_INLINE(T)
#   define UASM_TARGET_CPU_GPU_FINLINE(T) UASM_FINLINE(T)
#endif

#if defined(UASM_AMP_SUPPORT)
//#include <amp.h>
#   define UASM_CPU_AMP       restrict(amp,cpu)
#   define UASM_AMP_ONLY      restrict(amp)
#   define UASM_AMP           restrict(amp)
#   define UASM_CPU_ONLY      restrict(cpu)
#   define UASM_CPU
#else
#   define UASM_CPU_AMP
#   define UASM_AMP_ONLY
#   define UASM_AMP
#   define UASM_CPU_ONLY
#   define UASM_CPU
#endif // UASM_AMP_SUPPORT

#if defined(UASM_AMP_SUPPORT)
#   define UASM_EXTERN_BEGIN EXTERN_CC_BEGIN
#   define UASM_EXTERN_END EXTERN_CC_END
#else
#   define UASM_EXTERN_BEGIN EXTERN_C_BEGIN
#   define UASM_EXTERN_END EXTERN_C_END
#endif

#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#  if defined( UASM_LIB_DLL)
# ifndef UASM_GLOBAL_CONST
#   define UASM_GLOBAL_CONST _EXTERN const __declspec(selectany)
#   define UASM_CGLOBAL_CONST _EXTERNC const __declspec(selectany)
#   define UASM_CGLOBAL _EXTERNC __declspec(selectany)
#   define UASM_CCGLOBAL_CONST _EXTERNCC const __declspec(selectany)
#   define UASM_CCGLOBAL _EXTERNCC __declspec(selectany)
#   define UASM_AMP_GLOBAL_CONST _EXTERN const __declspec(selectany)
#   define UASM_AMP_CCGLOBAL_CONST _EXTERNCC const __declspec(selectany)
#   define UASM_AMP_CCGLOBAL _EXTERNCC __declspec(selectany)
#   define UASM_STATIC_CONST static const
#   define UASM_C_STATIC_CONST _EXTERNC static const
#   define UASM_CC_STATIC_CONST _EXTERNCC static const
// static inline
#   define UASM_CGLOBAL_API(T) _EXTERNC UASM_S_INLINE(T)
// inline only
#   define __UASM_CGLOBAL_API(T) _EXTERNC __UASM_INLINE(T)
// static inline
#   define UASM_CCGLOBAL_API(T) _EXTERNCC UASM_S_INLINE(T)
// inline only
#   define __UASM_CCGLOBAL_API(T) _EXTERNCC __UASM_INLINE(T)

// static inline
#   define UASM_CGLOBAL_CALLCONV_API(T) _EXTERNC UASM_S_INLINE(UASM_callconv(T))
// inline only
#   define __UASM_CGLOBAL_CALLCONV_API(T) _EXTERNC __UASM_INLINE(UASM_callconv(T))
// static inline
#   define UASM_CCGLOBAL_CALLCONV_API(T) _EXTERNCC UASM_S_INLINE(UASM_callconv(T))
// inline only
#   define __UASM_CCGLOBAL_CALLCONV_API(T) _EXTERNCC __UASM_INLINE(UASM_callconv(T))

// static inline
#   define UASM_CGLOBAL_VECCALL_API(T) _EXTERNC UASM_S_INLINE(UASM_veccall(T))
// inline only
#   define __UASM_CGLOBAL_VECCALL_API(T) _EXTERNC __UASM_INLINE(UASM_veccall(T))
// static inline
#   define UASM_CCGLOBAL_VECCALL_API(T) _EXTERNCC UASM_S_INLINE(UASM_veccall(T))
// inline only
#   define __UASM_CCGLOBAL_VECCALL_API(T) _EXTERNCC __UASM_INLINE(UASM_veccall(T))
# endif
# elif defined(UASM_LIB_STATIC)
# ifndef UASM_GLOBAL_CONST
#   define UASM_GLOBAL_CONST _EXTERN const
#   define UASM_CGLOBAL_CONST _EXTERNC const
#   define UASM_CGLOBAL _EXTERNC
#   define UASM_CCGLOBAL_CONST _EXTERNCC const
#   define UASM_CCGLOBAL _EXTERNCC
#   define UASM_AMP_GLOBAL_CONST _EXTERN const
#   define UASM_AMP_CCGLOBAL_CONST _EXTERNCC const
#   define UASM_AMP_CCGLOBAL _EXTERNCC
#   define UASM_STATIC_CONST static const
#   define UASM_C_STATIC_CONST _EXTERNC static const
#   define UASM_CC_STATIC_CONST _EXTERNCC static const
// static inline
#   define UASM_CGLOBAL_API(T) _EXTERNC UASM_S_INLINE(T)
// inline only
#   define __UASM_CGLOBAL_API(T) _EXTERNC __UASM_INLINE(T)
// static inline
#   define UASM_CCGLOBAL_API(T) _EXTERNCC UASM_S_INLINE(T)
// inline only
#   define __UASM_CCGLOBAL_API(T) _EXTERNCC __UASM_INLINE(T)

// static inline
#   define UASM_CGLOBAL_CALLCONV_API(T) _EXTERNC UASM_S_INLINE(UASM_callconv(T))
// inline only
#   define __UASM_CGLOBAL_CALLCONV_API(T) _EXTERNC __UASM_INLINE(UASM_callconv(T))
// static inline
#   define UASM_CCGLOBAL_CALLCONV_API(T) _EXTERNCC UASM_S_INLINE(UASM_callconv(T))
// inline only
#   define __UASM_CCGLOBAL_CALLCONV_API(T) _EXTERNCC __UASM_INLINE(UASM_callconv(T))

// static inline
#   define UASM_CGLOBAL_VECCALL_API(T) _EXTERNC UASM_S_INLINE(UASM_veccall(T))
// inline only
#   define __UASM_CGLOBAL_VECCALL_API(T) _EXTERNC __UASM_INLINE(UASM_veccall(T))
// static inline
#   define UASM_CCGLOBAL_VECCALL_API(T) _EXTERNCC UASM_S_INLINE(UASM_veccall(T))
// inline only
#   define __UASM_CCGLOBAL_VECCALL_API(T) _EXTERNCC __UASM_INLINE(UASM_veccall(T))
# endif
# endif
#else
# ifndef UASM_GLOBAL_CONST
#   define UASM_GLOBAL_CONST _EXTERN const
#   define UASM_CGLOBAL_CONST _EXTERNC const
#   define UASM_CGLOBAL _EXTERNC
#   define UASM_CCGLOBAL_CONST _EXTERNCC const
#   define UASM_CCGLOBAL _EXTERNCC
#   define UASM_AMP_GLOBAL_CONST _EXTERN const
#   define UASM_AMP_CCGLOBAL_CONST _EXTERNCC const
#   define UASM_AMP_CCGLOBAL _EXTERNCC
#   define UASM_STATIC_CONST static const
#   define UASM_C_STATIC_CONST _EXTERNC static const
#   define UASM_CC_STATIC_CONST _EXTERNCC static const
// static inline
#   define UASM_CGLOBAL_API(T) _EXTERNC UASM_S_INLINE(T)
// inline only
#   define __UASM_CGLOBAL_API(T) _EXTERNC __UASM_INLINE(T)
// static inline
#   define UASM_CCGLOBAL_API(T) _EXTERNCC UASM_S_INLINE(T)
// inline only
#   define __UASM_CCGLOBAL_API(T) _EXTERNCC __UASM_INLINE(T)

// static inline
#   define UASM_CGLOBAL_CALLCONV_API(T) _EXTERNC UASM_S_INLINE(UASM_callconv(T))
// inline only
#   define __UASM_CGLOBAL_CALLCONV_API(T) _EXTERNC __UASM_INLINE(UASM_callconv(T))
// static inline
#   define UASM_CCGLOBAL_CALLCONV_API(T) _EXTERNCC UASM_S_INLINE(UASM_callconv(T))
// inline only
#   define __UASM_CCGLOBAL_CALLCONV_API(T) _EXTERNCC __UASM_INLINE(UASM_callconv(T))

// static inline
#   define UASM_CGLOBAL_VECCALL_API(T) _EXTERNC UASM_S_INLINE(UASM_veccall(T))
// inline only
#   define __UASM_CGLOBAL_VECCALL_API(T) _EXTERNC __UASM_INLINE(UASM_veccall(T))
// static inline
#   define UASM_CCGLOBAL_VECCALL_API(T) _EXTERNCC UASM_S_INLINE(UASM_veccall(T))
// inline only
#   define __UASM_CCGLOBAL_VECCALL_API(T) _EXTERNCC __UASM_INLINE(UASM_veccall(T))
# endif
#endif

#if defined(UASM_AMP_SUPPORT)
#   define UASM_NMGLOBAL_CONST  UASM_AMP_GLOBAL_CONST
#else
#   define UASM_NMGLOBAL_CONST  UASM_GLOBAL_CONST
#endif

#  if defined(UASM_CC_PDEF_GPU_SUPPORT)
// static inline
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) UASM_CGLOBAL_API(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) __UASM_CGLOBAL_API(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)
// static inline
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) UASM_CCGLOBAL_API(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(UASM_TARGET_GPU_ONLY UASM_TARGET_DEVICE_BUILTIN T)

// static inline
#   define UASM_TARGET_GPU_ONLY_CGLOBALAPI(T) UASM_CGLOBAL_API(UASM_TARGET_GPU_ONLY T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_CGLOBALAPI(T) __UASM_CGLOBAL_API(UASM_TARGET_GPU_ONLY T)
// static inline
#   define UASM_TARGET_GPU_ONLY_CCGLOBALAPI(T) UASM_CCGLOBAL_API(UASM_TARGET_GPU_ONLY T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(UASM_TARGET_GPU_ONLY T)

// static inline
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) UASM_CGLOBAL_API(UASM_TARGET_CPU_GPU UASM_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) __UASM_CGLOBAL_API(UASM_TARGET_CPU_GPU UASM_TARGET_DEVICE_BUILTIN T)
// static inline
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) UASM_CCGLOBAL_API(UASM_TARGET_CPU_GPU UASM_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(UASM_TARGET_CPU_GPU UASM_TARGET_DEVICE_BUILTIN T)

// static inline
#   define UASM_TARGET_CPU_GPU_CGLOBALAPI(T) UASM_CGLOBAL_API(UASM_TARGET_CPU_GPU T)
// inline only
#   define __UASM_TARGET_CPU_GPU_CGLOBALAPI(T) __UASM_CGLOBAL_API(UASM_TARGET_CPU_GPU T)
// static inline
#   define UASM_TARGET_CPU_GPU_CCGLOBALAPI(T) UASM_CCGLOBAL_API(UASM_TARGET_CPU_GPU T)
// inline only
#   define __UASM_TARGET_CPU_GPU_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(UASM_TARGET_CPU_GPU T)

// static inline
#   define UASM_TARGET_CPU_ONLY_CGLOBALAPI(T) UASM_CGLOBAL_API(UASM_TARGET_CPU_ONLY T)
// inline only
#   define __UASM_TARGET_CPU_ONLY_CGLOBALAPI(T) __UASM_CGLOBAL_API(UASM_TARGET_CPU_ONLY T)
// static inline
#   define UASM_TARGET_CPU_ONLY_CCGLOBALAPI(T) UASM_CCGLOBAL_API(UASM_TARGET_CPU_ONLY T)
// inline only
#   define __UASM_TARGET_CPU_ONLY_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(UASM_TARGET_CPU_ONLY T)
#  else

// static inline
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) UASM_CGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) __UASM_CGLOBAL_API(T)
// static inline
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) UASM_CCGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(T)

// static inline
#   define UASM_TARGET_GPU_ONLY_CGLOBALAPI(T) UASM_CGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_CGLOBALAPI(T) __UASM_CGLOBAL_API(T)
// static inline
#   define UASM_TARGET_GPU_ONLY_CCGLOBALAPI(T) UASM_CCGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(T)

// static inline
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) UASM_CGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) __UASM_CGLOBAL_API(T)
// static inline
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) UASM_CCGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(T)

// static inline
#   define UASM_TARGET_CPU_GPU_CGLOBALAPI(T) UASM_CGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_CGLOBALAPI(T) __UASM_CGLOBAL_API(T)
// static inline
#   define UASM_TARGET_CPU_GPU_CCGLOBALAPI(T) UASM_CCGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(T)

// static inline
#   define UASM_TARGET_CPU_ONLY_CGLOBALAPI(T) UASM_CGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_CPU_ONLY_CGLOBALAPI(T) __UASM_CGLOBAL_API(T)
// static inline
#   define UASM_TARGET_CPU_ONLY_CCGLOBALAPI(T) UASM_CCGLOBAL_API(T)
// inline only
#   define __UASM_TARGET_CPU_ONLY_CCGLOBALAPI(T) __UASM_CCGLOBAL_API(T)
#  endif

# if defined(UASM_AMP_SUPPORT)
// static inline
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T)
// static inline
#   define UASM_TARGET_GPU_ONLY_NMGLOBALAPI(T) UASM_TARGET_GPU_ONLY_CCGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_GPU_ONLY_CCGLOBALAPI(T)
// static inline
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T)
// static inline
#   define UASM_TARGET_CPU_GPU_NMGLOBALAPI(T) UASM_TARGET_CPU_GPU_CCGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_NMGLOBALAPI(T) __UASM_TARGET_CPU_GPU_CCGLOBALAPI(T)
// static inline
#   define UASM_TARGET_CPU_ONLY_NMGLOBALAPI(T) UASM_TARGET_CPU_ONLY_CCGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_CPU_ONLY_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_CPU_ONLY_CCGLOBALAPI(T)
# else
// static inline
#   define UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T)
// static inline
#   define UASM_TARGET_GPU_ONLY_NMGLOBALAPI(T) UASM_TARGET_GPU_ONLY_CGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_GPU_ONLY_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_GPU_ONLY_CGLOBALAPI(T)
// static inline
#   define UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) __UASM_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T)
// static inline
#   define UASM_TARGET_CPU_GPU_NMGLOBALAPI(T) UASM_TARGET_CPU_GPU_CGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_CPU_GPU_NMGLOBALAPI(T) __UASM_TARGET_CPU_GPU_CGLOBALAPI(T)
// static inline
#   define UASM_TARGET_CPU_ONLY_NMGLOBALAPI(T) UASM_TARGET_CPU_ONLY_CGLOBALAPI(T)
// inline only
#   define __UASM_TARGET_CPU_ONLY_NMGLOBALAPI(T) __UASM_TARGET_CPU_ONLY_CGLOBALAPI(T)
# endif

/**
Alignment macros

UASM_ALIGNPREFIX and UASM_ALIGNSUFFIX can be used for type alignment instead of aligning individual variables as follows:
UASM_ALIGNPREFIX(16)
struct A {
...
} UASM_ALIGNSUFFIX(16);
This declaration style is parsed correctly by Visual Assist.
*/

#if defined(UASM_MSVC_COMPATIBLE_COMPILER) && !defined(UASM_NO_ALIGN)

#       define UASM_DECLALIGN(alignment, decl) __declspec(align(alignment)) decl
#       define UASM_ALIGNPREFIX(alignment) __declspec(align(alignment))
#       define UASM_ALIGNSUFFIX(alignment)

#       define UASM_ALIGNDECL(decl, alignment) __declspec(align(alignment)) decl
#       define UASM_ALIGN1DECL(decl) __declspec(align(1)) decl
#       define UASM_ALIGN2DECL(decl) __declspec(align(2)) decl
#       define UASM_ALIGN3DECL(decl) __declspec(align(3)) decl
#       define UASM_ALIGN4DECL(decl) __declspec(align(4)) decl
#       define UASM_ALIGN6DECL(decl) __declspec(align(6)) decl
#       define UASM_ALIGN8DECL(decl) __declspec(align(8)) decl
#       define UASM_ALIGN9DECL(decl) __declspec(align(9)) decl
#       define UASM_ALIGN12DECL(decl) __declspec(align(12)) decl
#       define UASM_ALIGN16DECL(decl) __declspec(align(16)) decl
#       define UASM_ALIGN18DECL(decl) __declspec(align(18)) decl
#       define UASM_ALIGN24DECL(decl) __declspec(align(24)) decl
#       define UASM_ALIGN32DECL(decl) __declspec(align(32)) decl
#       define UASM_ALIGN36DECL(decl) __declspec(align(36)) decl
#       define UASM_ALIGN48DECL(decl) __declspec(align(48)) decl
#       define UASM_ALIGN64DECL(decl) __declspec(align(64)) decl
#       define UASM_ALIGN72DECL(decl) __declspec(align(72)) decl
#       define UASM_ALIGN96DECL(decl) __declspec(align(96)) decl
#       define UASM_ALIGN128DECL(decl) __declspec(align(128)) decl
#       define UASM_ALIGN256DECL(decl) __declspec(align(256)) decl
#       define UASM_ALIGN512DECL(decl) __declspec(align(512)) decl

#   define uXVC_ALIGNMENT(X) __declspec(align(X))
#   define uXVC_ALIGN1 __declspec(align(1))
#   define uXVC_ALIGN2 __declspec(align(2))
#   define uXVC_ALIGN3 __declspec(align(3))
#   define uXVC_ALIGN4 __declspec(align(4))
#   define uXVC_ALIGN6 __declspec(align(6))
#   define uXVC_ALIGN8 __declspec(align(8))
#   define uXVC_ALIGN9 __declspec(align(9))
#   define uXVC_ALIGN12 __declspec(align(12))
#   define uXVC_ALIGN16 __declspec(align(16))
#   define uXVC_ALIGN18 __declspec(align(18))
#   define uXVC_ALIGN24 __declspec(align(24))
#   define uXVC_ALIGN32 __declspec(align(32))
#   define uXVC_ALIGN36 __declspec(align(36))
#   define uXVC_ALIGN48 __declspec(align(48))
#   define uXVC_ALIGN64 __declspec(align(64))
#   define uXVC_ALIGN72 __declspec(align(72))
#   define uXVC_ALIGN96 __declspec(align(96))
#   define uXVC_ALIGN128 __declspec(align(128))
#   define uXVC_ALIGN256 __declspec(align(256))
#   define uXVC_ALIGN512 __declspec(align(512))

#   define uXVC_ALGN1 1
#   define uXVC_ALGN2 2
#   define uXVC_ALGN3 3
#   define uXVC_ALGN4 4
#   define uXVC_ALGN6 6
#   define uXVC_ALGN8 8
#   define uXVC_ALGN9 9
#   define uXVC_ALGN12 12
#   define uXVC_ALGN16 16
#   define uXVC_ALGN18 18
#   define uXVC_ALGN24 24
#   define uXVC_ALGN32 32
#   define uXVC_ALGN36 36
#   define uXVC_ALGN48 48
#   define uXVC_ALGN64 64
#   define uXVC_ALGN72 72
#   define uXVC_ALGN96 96
#   define uXVC_ALGN128 128
#   define uXVC_ALGN256 256
#   define uXVC_ALGN512 512

#   define uXGC_ALIGNMENT(X)
#   define uXGC_ALIGN1
#   define uXGC_ALIGN2
#   define uXGC_ALIGN3
#   define uXGC_ALIGN4
#   define uXGC_ALIGN6
#   define uXGC_ALIGN8
#   define uXGC_ALIGN9
#   define uXGC_ALIGN12
#   define uXGC_ALIGN16
#   define uXGC_ALIGN18
#   define uXGC_ALIGN24
#   define uXGC_ALIGN32
#   define uXGC_ALIGN36
#   define uXGC_ALIGN48
#   define uXGC_ALIGN64
#   define uXGC_ALIGN72
#   define uXGC_ALIGN96
#   define uXGC_ALIGN128
#   define uXGC_ALIGN256
#   define uXGC_ALIGN512

#   define uXGC_ALGN1
#   define uXGC_ALGN2
#   define uXGC_ALGN3
#   define uXGC_ALGN4
#   define uXGC_ALGN6
#   define uXGC_ALGN8
#   define uXGC_ALGN9
#   define uXGC_ALGN12
#   define uXGC_ALGN16
#   define uXGC_ALGN18
#   define uXGC_ALGN24
#   define uXGC_ALGN32
#   define uXGC_ALGN36
#   define uXGC_ALGN48
#   define uXGC_ALGN64
#   define uXGC_ALGN72
#   define uXGC_ALGN96
#   define uXGC_ALGN128
#   define uXGC_ALGN256
#   define uXGC_ALGN512

#       define UASM_PREFIXALIGN(alignment) UASM_ALIGNPREFIX(alignment)
#       define UASM_SUFFIXALIGN(alignment) UASM_ALIGNSUFFIX(alignment)

#       define UASM_DECL_ALIGN(alignment, decl) UASM_DECLALIGN(alignment, decl)
#       define UASM_ALIGN_DECL(decl, alignment) UASM_ALIGNDECL(decl, alignment)

#elif defined(UASM_GNUC_TYPE_ALIGNMENT) && !defined(UASM_NO_ALIGN)
#       define UASM_DECLALIGN(alignment, decl) decl __attribute__((aligned(alignment)))
#       define UASM_ALIGNPREFIX(alignment)
#       define UASM_ALIGNSUFFIX(alignment) __attribute__((aligned(alignment)))

#       define UASM_ALIGNDECL(decl, alignment) decl  __attribute__((aligned(alignment)))
#       define UASM_ALIGN1DECL(decl) decl __attribute__((aligned(1)))
#       define UASM_ALIGN2DECL(decl) decl __attribute__((aligned(2)))
#       define UASM_ALIGN3DECL(decl) decl __attribute__((aligned(3)))
#       define UASM_ALIGN4DECL(decl) decl __attribute__((aligned(4)))
#       define UASM_ALIGN6DECL(decl) decl __attribute__((aligned(6)))
#       define UASM_ALIGN8DECL(decl) decl __attribute__((aligned(8)))
#       define UASM_ALIGN9DECL(decl) decl __attribute__((aligned(9)))
#       define UASM_ALIGN12DECL(decl) decl __attribute__((aligned(12)))
#       define UASM_ALIGN16DECL(decl) decl __attribute__((aligned(16)))
#       define UASM_ALIGN18DECL(decl) decl __attribute__((aligned(18)))
#       define UASM_ALIGN24DECL(decl) decl __attribute__((aligned(24)))
#       define UASM_ALIGN32DECL(decl) decl __attribute__((aligned(32)))
#       define UASM_ALIGN36DECL(decl) decl __attribute__((aligned(36)))
#       define UASM_ALIGN48DECL(decl) decl __attribute__((aligned(48)))
#       define UASM_ALIGN64DECL(decl) decl __attribute__((aligned(64)))
#       define UASM_ALIGN72DECL(decl) decl __attribute__((aligned(72)))
#       define UASM_ALIGN96DECL(decl) decl __attribute__((aligned(96)))
#       define UASM_ALIGN128DECL(decl) decl __attribute__((aligned(128)))
#       define UASM_ALIGN256DECL(decl) decl __attribute__((aligned(256)))
#       define UASM_ALIGN512DECL(decl) decl __attribute__((aligned(512)))

#   define uXGC_ALIGNMENT(X) __attribute__((aligned(X)))
#   define uXGC_ALIGN1 __attribute__((aligned(1)))
#   define uXGC_ALIGN2 __attribute__((aligned(2)))
#   define uXGC_ALIGN3 __attribute__((aligned(3)))
#   define uXGC_ALIGN4 __attribute__((aligned(4)))
#   define uXGC_ALIGN6 __attribute__((aligned(6)))
#   define uXGC_ALIGN8 __attribute__((aligned(8)))
#   define uXGC_ALIGN9 __attribute__((aligned(9)))
#   define uXGC_ALIGN12 __attribute__((aligned(12)))
#   define uXGC_ALIGN16 __attribute__((aligned(16)))
#   define uXGC_ALIGN18 __attribute__((aligned(18)))
#   define uXGC_ALIGN24 __attribute__((aligned(24)))
#   define uXGC_ALIGN32 __attribute__((aligned(32)))
#   define uXGC_ALIGN36 __attribute__((aligned(36)))
#   define uXGC_ALIGN48 __attribute__((aligned(48)))
#   define uXGC_ALIGN64 __attribute__((aligned(64)))
#   define uXGC_ALIGN72 __attribute__((aligned(72)))
#   define uXGC_ALIGN96 __attribute__((aligned(96)))
#   define uXGC_ALIGN128 __attribute__((aligned(128)))
#   define uXGC_ALIGN256 __attribute__((aligned(256)))
#   define uXGC_ALIGN512 __attribute__((aligned(512)))

#   define uXGC_ALGN1 1
#   define uXGC_ALGN2 2
#   define uXGC_ALGN3 3
#   define uXGC_ALGN4 4
#   define uXGC_ALGN6 6
#   define uXGC_ALGN8 8
#   define uXGC_ALGN9 9
#   define uXGC_ALGN12 12
#   define uXGC_ALGN16 16
#   define uXGC_ALGN18 18
#   define uXGC_ALGN24 24
#   define uXGC_ALGN32 32
#   define uXGC_ALGN36 36
#   define uXGC_ALGN48 48
#   define uXGC_ALGN64 64
#   define uXGC_ALGN72 72
#   define uXGC_ALGN96 96
#   define uXGC_ALGN128 128
#   define uXGC_ALGN256 256
#   define uXGC_ALGN512 512

#   define uXVC_ALIGNMENT(X)
#   define uXVC_ALIGN1
#   define uXVC_ALIGN2
#   define uXVC_ALIGN3
#   define uXVC_ALIGN4
#   define uXVC_ALIGN6
#   define uXVC_ALIGN8
#   define uXVC_ALIGN9
#   define uXVC_ALIGN12
#   define uXVC_ALIGN16
#   define uXVC_ALIGN18
#   define uXVC_ALIGN24
#   define uXVC_ALIGN32
#   define uXVC_ALIGN36
#   define uXVC_ALIGN48
#   define uXVC_ALIGN64
#   define uXVC_ALIGN72
#   define uXVC_ALIGN96
#   define uXVC_ALIGN128
#   define uXVC_ALIGN256
#   define uXVC_ALIGN512

# define uXVC_ALGN1
# define uXVC_ALGN2
# define uXVC_ALGN3
# define uXVC_ALGN4
# define uXVC_ALGN6
# define uXVC_ALGN8
# define uXVC_ALGN9
# define uXVC_ALGN12
# define uXVC_ALGN16
# define uXVC_ALGN18
# define uXVC_ALGN24
# define uXVC_ALGN32
# define uXVC_ALGN36
# define uXVC_ALGN48
# define uXVC_ALGN64
# define uXVC_ALGN72
# define uXVC_ALGN96
# define uXVC_ALGN128
# define uXVC_ALGN256
# define uXVC_ALGN512

#       define UASM_PREFIXALIGN(alignment) UASM_ALIGNPREFIX(alignment)
#       define UASM_SUFFIXALIGN(alignment) UASM_ALIGNSUFFIX(alignment)

#       define UASM_DECL_ALIGN(alignment, decl) UASM_DECLALIGN(alignment, decl)
#       define UASM_ALIGN_DECL(decl, alignment) UASM_ALIGNDECL(decl, alignment)

#elif defined(UASM_NO_ALIGN)
#       define UASM_DECLALIGN(alignment, decl)
#       define UASM_ALIGNPREFIX(alignment)
#       define UASM_ALIGNSUFFIX(alignment)

#       define UASM_ALIGNDECL(decl, alignment)
#       define UASM_ALIGN1DECL(decl)
#       define UASM_ALIGN2DECL(decl)
#       define UASM_ALIGN3DECL(decl)
#       define UASM_ALIGN4DECL(decl)
#       define UASM_ALIGN6DECL(decl)
#       define UASM_ALIGN8DECL(decl)
#       define UASM_ALIGN9DECL(decl)
#       define UASM_ALIGN12DECL(decl)
#       define UASM_ALIGN16DECL(decl)
#       define UASM_ALIGN18DECL(decl)
#       define UASM_ALIGN24DECL(decl)
#       define UASM_ALIGN32DECL(decl)
#       define UASM_ALIGN36DECL(decl)
#       define UASM_ALIGN48DECL(decl)
#       define UASM_ALIGN64DECL(decl)
#       define UASM_ALIGN72DECL(decl)
#       define UASM_ALIGN96DECL(decl)
#       define UASM_ALIGN128DECL(decl)
#       define UASM_ALIGN256DECL(decl)
#       define UASM_ALIGN512DECL(decl)

#   define uXVC_ALIGNMENT(X)
#   define uXVC_ALIGN1
#   define uXVC_ALIGN2
#   define uXVC_ALIGN3
#   define uXVC_ALIGN4
#   define uXVC_ALIGN6
#   define uXVC_ALIGN8
#   define uXVC_ALIGN9
#   define uXVC_ALIGN12
#   define uXVC_ALIGN16
#   define uXVC_ALIGN18
#   define uXVC_ALIGN24
#   define uXVC_ALIGN32
#   define uXVC_ALIGN36
#   define uXVC_ALIGN48
#   define uXVC_ALIGN64
#   define uXVC_ALIGN72
#   define uXVC_ALIGN96
#   define uXVC_ALIGN128
#   define uXVC_ALIGN256
#   define uXVC_ALIGN512

# define uXVC_ALGN1
# define uXVC_ALGN2
# define uXVC_ALGN3
# define uXVC_ALGN4
# define uXVC_ALGN6
# define uXVC_ALGN8
# define uXVC_ALGN9
# define uXVC_ALGN12
# define uXVC_ALGN16
# define uXVC_ALGN18
# define uXVC_ALGN24
# define uXVC_ALGN32
# define uXVC_ALGN36
# define uXVC_ALGN48
# define uXVC_ALGN64
# define uXVC_ALGN72
# define uXVC_ALGN96
# define uXVC_ALGN128
# define uXVC_ALGN256
# define uXVC_ALGN512

#   define uXGC_ALIGNMENT(X)
#   define uXGC_ALIGN1
#   define uXGC_ALIGN2
#   define uXGC_ALIGN3
#   define uXGC_ALIGN4
#   define uXGC_ALIGN6
#   define uXGC_ALIGN8
#   define uXGC_ALIGN9
#   define uXGC_ALIGN12
#   define uXGC_ALIGN16
#   define uXGC_ALIGN18
#   define uXGC_ALIGN24
#   define uXGC_ALIGN32
#   define uXGC_ALIGN36
#   define uXGC_ALIGN48
#   define uXGC_ALIGN64
#   define uXGC_ALIGN72
#   define uXGC_ALIGN96
#   define uXGC_ALIGN128
#   define uXGC_ALIGN256
#   define uXGC_ALIGN512

# define uXGC_ALGN1
# define uXGC_ALGN2
# define uXGC_ALGN3
# define uXGC_ALGN4
# define uXGC_ALGN6
# define uXGC_ALGN8
# define uXGC_ALGN9
# define uXGC_ALGN12
# define uXGC_ALGN16
# define uXGC_ALGN18
# define uXGC_ALGN24
# define uXGC_ALGN32
# define uXGC_ALGN36
# define uXGC_ALGN48
# define uXGC_ALGN64
# define uXGC_ALGN72
# define uXGC_ALGN96
# define uXGC_ALGN128
# define uXGC_ALGN256
# define uXGC_ALGN512

#       define UASM_PREFIXALIGN(alignment) UASM_ALIGNPREFIX(alignment)
#       define UASM_SUFFIXALIGN(alignment) UASM_ALIGNSUFFIX(alignment)

#       define UASM_DECL_ALIGN(alignment, decl) UASM_DECLALIGN(alignment, decl)
#       define UASM_ALIGN_DECL(decl, alignment) UASM_ALIGNDECL(decl, alignment)

#else
#       define UASM_DECLALIGN(alignment, decl)
#       define UASM_ALIGNPREFIX(alignment)
#       define UASM_ALIGNSUFFIX(alignment)

#       define UASM_ALIGNDECL(decl, alignment)
#       define UASM_ALIGN1DECL(decl)
#       define UASM_ALIGN2DECL(decl)
#       define UASM_ALIGN3DECL(decl)
#       define UASM_ALIGN4DECL(decl)
#       define UASM_ALIGN6DECL(decl)
#       define UASM_ALIGN8DECL(decl)
#       define UASM_ALIGN9DECL(decl)
#       define UASM_ALIGN12DECL(decl)
#       define UASM_ALIGN16DECL(decl)
#       define UASM_ALIGN18DECL(decl)
#       define UASM_ALIGN24DECL(decl)
#       define UASM_ALIGN32DECL(decl)
#       define UASM_ALIGN36DECL(decl)
#       define UASM_ALIGN48DECL(decl)
#       define UASM_ALIGN64DECL(decl)
#       define UASM_ALIGN72DECL(decl)
#       define UASM_ALIGN96DECL(decl)
#       define UASM_ALIGN128DECL(decl)
#       define UASM_ALIGN256DECL(decl)
#       define UASM_ALIGN512DECL(decl)

#   define uXVC_ALIGNMENT(X)
#   define uXVC_ALIGN1
#   define uXVC_ALIGN2
#   define uXVC_ALIGN3
#   define uXVC_ALIGN4
#   define uXVC_ALIGN6
#   define uXVC_ALIGN8
#   define uXVC_ALIGN9
#   define uXVC_ALIGN12
#   define uXVC_ALIGN16
#   define uXVC_ALIGN18
#   define uXVC_ALIGN24
#   define uXVC_ALIGN32
#   define uXVC_ALIGN36
#   define uXVC_ALIGN48
#   define uXVC_ALIGN64
#   define uXVC_ALIGN72
#   define uXVC_ALIGN96
#   define uXVC_ALIGN128
#   define uXVC_ALIGN256
#   define uXVC_ALIGN512

# define uXVC_ALGN1
# define uXVC_ALGN2
# define uXVC_ALGN3
# define uXVC_ALGN4
# define uXVC_ALGN6
# define uXVC_ALGN8
# define uXVC_ALGN9
# define uXVC_ALGN12
# define uXVC_ALGN16
# define uXVC_ALGN18
# define uXVC_ALGN24
# define uXVC_ALGN32
# define uXVC_ALGN36
# define uXVC_ALGN48
# define uXVC_ALGN64
# define uXVC_ALGN72
# define uXVC_ALGN96
# define uXVC_ALGN128
# define uXVC_ALGN256
# define uXVC_ALGN512

#   define uXGC_ALIGNMENT(X)
#   define uXGC_ALIGN1
#   define uXGC_ALIGN2
#   define uXGC_ALIGN3
#   define uXGC_ALIGN4
#   define uXGC_ALIGN6
#   define uXGC_ALIGN8
#   define uXGC_ALIGN9
#   define uXGC_ALIGN12
#   define uXGC_ALIGN16
#   define uXGC_ALIGN18
#   define uXGC_ALIGN24
#   define uXGC_ALIGN32
#   define uXGC_ALIGN36
#   define uXGC_ALIGN48
#   define uXGC_ALIGN64
#   define uXGC_ALIGN72
#   define uXGC_ALIGN96
#   define uXGC_ALIGN128
#   define uXGC_ALIGN256
#   define uXGC_ALIGN512

# define uXGC_ALGN1
# define uXGC_ALGN2
# define uXGC_ALGN3
# define uXGC_ALGN4
# define uXGC_ALGN6
# define uXGC_ALGN8
# define uXGC_ALGN9
# define uXGC_ALGN12
# define uXGC_ALGN16
# define uXGC_ALGN18
# define uXGC_ALGN24
# define uXGC_ALGN32
# define uXGC_ALGN36
# define uXGC_ALGN48
# define uXGC_ALGN64
# define uXGC_ALGN72
# define uXGC_ALGN96
# define uXGC_ALGN128
# define uXGC_ALGN256
# define uXGC_ALGN512

#       define UASM_PREFIXALIGN(alignment) UASM_ALIGNPREFIX(alignment)
#       define UASM_SUFFIXALIGN(alignment) UASM_ALIGNSUFFIX(alignment)

#       define UASM_DECL_ALIGN(alignment, decl) UASM_DECLALIGN(alignment, decl)
#       define UASM_ALIGN_DECL(decl, alignment) UASM_ALIGNDECL(decl, alignment)

#endif

# define UASM_F64_ALGN 8
# define UASM_I64_ALGN 8
# define UASM_F32_ALGN 4
# define UASM_I32_ALGN 4
# define UASM_I16_ALGN 2
# define UASM_I8_ALGN 1

# define UASM_F64_SIZE 8
# define UASM_I64_SIZE 8
# define UASM_F32_SIZE 4
# define UASM_I32_SIZE 4
# define UASM_I16_SIZE 2
# define UASM_I8_SIZE 1

#if (defined(UASM_X86_OR_X64_CPU) || defined(UASM_XBOXONE))  && !defined(UASM_NO_ALIGN)
# if (defined(UASM_MMX_INTRINSICS) || defined(UASM_3DNOW_INTRINSICS)) && (defined(UASM_INTRINSET) && (UASM_INTRINSET >= 2) && (UASM_INTRINSET <= 9)) && \
                                                !defined(UASM_AVX256_INTRINSICS) && !defined(UASM_AVX512_INTRINSICS) && !defined(UASM_SSE_INTRINSICS)
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_8
#           define uXVC_ALGN uXVC_ALGN8
#           define uXVC_ALIGN_F32 uXVC_ALIGN8
#           define uXVC_ALIGN_F64 uXVC_ALIGN8
#           define uXVC_ALIGN_REAL uXVC_ALIGN8
#           define uXVC_ALIGN uXVC_ALIGN8

#           define uXGC_ALGN uXGC_ALGN8
#           define uXGC_ALIGN_F32 uXGC_ALIGN8
#           define uXGC_ALIGN_F64 uXGC_ALIGN8
#           define uXGC_ALIGN_REAL uXGC_ALIGN8
#           define uXGC_ALIGN uXGC_ALIGN8

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN8DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN8DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN8DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN8DECL(decl)
# elif defined(UASM_SSE_INTRINSICS) && (defined(UASM_INTRINSET) && (UASM_INTRINSET >= 10) && (UASM_INTRINSET <= 42)) && !defined(UASM_AVX256_INTRINSICS) && !defined(UASM_AVX512_INTRINSICS)
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_16
#           define uXVC_ALGN uXVC_ALGN16
#           define uXVC_ALIGN_F32 uXVC_ALIGN16
#           define uXVC_ALIGN_F64 uXVC_ALIGN16
#           define uXVC_ALIGN_REAL uXVC_ALIGN16
#           define uXVC_ALIGN uXVC_ALIGN16

#           define uXGC_ALGN uXGC_ALGN16
#           define uXGC_ALIGN_F32 uXGC_ALIGN16
#           define uXGC_ALIGN_F64 uXGC_ALIGN16
#           define uXGC_ALIGN_REAL uXGC_ALIGN16
#           define uXGC_ALIGN uXGC_ALIGN16

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN16DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN16DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN16DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN16DECL(decl)
# elif defined(UASM_AVX256_INTRINSICS) && (defined(UASM_INTRINSET) && (UASM_INTRINSET >= 50) && (UASM_INTRINSET <= 52)) && !defined(UASM_AVX512_INTRINSICS) && !defined(UASM_SSE_INTRINSICS)
#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_16
#else
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_32
#endif
#           define uXVC_ALGN uXVC_ALGN32
#           define uXVC_ALIGN_F32 uXVC_ALIGN32
#           define uXVC_ALIGN_F64 uXVC_ALIGN32
#           define uXVC_ALIGN_REAL uXVC_ALIGN32
#           define uXVC_ALIGN uXVC_ALIGN32

#           define uXGC_ALGN uXGC_ALGN32
#           define uXGC_ALIGN_F32 uXGC_ALIGN32
#           define uXGC_ALIGN_F64 uXGC_ALIGN32
#           define uXGC_ALIGN_REAL uXGC_ALIGN32
#           define uXGC_ALIGN uXGC_ALIGN32

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN32DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN32DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN32DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN32DECL(decl)
# elif defined(UASM_AVX512_INTRINSICS) && (defined(UASM_INTRINSET) && (UASM_INTRINSET >= 60)) && !defined(UASM_AVX256_INTRINSICS) && !defined(UASM_SSE_INTRINSICS)
#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_16
#else
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_64
#endif
#           define uXVC_ALGN uXVC_ALGN64
#           define uXVC_ALIGN_F32 uXVC_ALIGN64
#           define uXVC_ALIGN_F64 uXVC_ALIGN64
#           define uXVC_ALIGN_REAL uXVC_ALIGN64
#           define uXVC_ALIGN uXVC_ALIGN64

#           define uXGC_ALGN uXGC_ALGN64
#           define uXGC_ALIGN_F32 uXGC_ALIGN64
#           define uXGC_ALIGN_F64 uXGC_ALIGN64
#           define uXGC_ALIGN_REAL uXGC_ALIGN64
#           define uXGC_ALIGN uXGC_ALIGN64

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN64DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN64DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN64DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN64DECL(decl)
#else  /* building all x86/x64 intrinsics sizes, defaults to SSE compatibility size, defend your code against sizes accidentally mixing*/
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_16
#           define uXVC_ALGN uXVC_ALGN16
#           define uXVC_ALIGN_F32 uXVC_ALIGN16
#           define uXVC_ALIGN_F64 uXVC_ALIGN16
#           define uXVC_ALIGN_REAL uXVC_ALIGN16
#           define uXVC_ALIGN uXVC_ALIGN16

#           define uXGC_ALGN uXGC_ALGN16
#           define uXGC_ALIGN_F32 uXGC_ALIGN16
#           define uXGC_ALIGN_F64 uXGC_ALIGN16
#           define uXGC_ALIGN_REAL uXGC_ALIGN16
#           define uXGC_ALIGN uXGC_ALIGN16

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN16DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN16DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN16DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN16DECL(decl)
# endif
#elif defined(UASM_ARM) && !defined(UASM_NO_ALIGN)
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_8
#           define uXVC_ALGN uXVC_ALGN8
#           define uXVC_ALIGN_F32 uXVC_ALIGN8
#           define uXVC_ALIGN_F64 uXVC_ALIGN8
#           define uXVC_ALIGN_REAL uXVC_ALIGN8
#           define uXVC_ALIGN uXVC_ALIGN8

#           define uXGC_ALGN uXGC_ALGN8
#           define uXGC_ALIGN_F32 uXGC_ALIGN8
#           define uXGC_ALIGN_F64 uXGC_ALIGN8
#           define uXGC_ALIGN_REAL uXGC_ALIGN8
#           define uXGC_ALIGN uXGC_ALIGN8

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN8DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN8DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN8DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN8DECL(decl)
#elif defined(UASM_PS3) && !defined(UASM_NO_ALIGN)
#           define UASM_PACK_PUSH_ UASM_PACK_PUSH_128
#           define uXVC_ALGN uXVC_ALGN128
#           define uXVC_ALIGN_F32 uXVC_ALIGN128
#           define uXVC_ALIGN_F64 uXVC_ALIGN128
#           define uXVC_ALIGN_REAL uXVC_ALIGN128
#           define uXVC_ALIGN uXVC_ALIGN128

#           define uXGC_ALGN uXGC_ALGN128
#           define uXGC_ALIGN_F32 uXGC_ALIGN128
#           define uXGC_ALIGN_F64 uXGC_ALIGN128
#           define uXGC_ALIGN_REAL uXGC_ALIGN128
#           define uXGC_ALIGN uXGC_ALIGN128

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN128DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN128DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN128DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN128DECL(decl)
#elif defined(UASM_NO_ALIGN)
#           define UASM_PACK_PUSH_
#           define uXVC_ALGN uXVC_ALGN4
#           define uXVC_ALIGN_F32 uXVC_ALIGN4
#           define uXVC_ALIGN_F64 uXVC_ALIGN4
#           define uXVC_ALIGN_REAL uXVC_ALIGN4
#           define uXVC_ALIGN uXVC_ALIGN4

#           define uXGC_ALGN uXGC_ALGN4
#           define uXGC_ALIGN_F32 uXGC_ALIGN4
#           define uXGC_ALIGN_F64 uXGC_ALIGN4
#           define uXGC_ALIGN_REAL uXGC_ALIGN4
#           define uXGC_ALIGN uXGC_ALIGN4

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN4DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN4DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN4DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN4DECL(decl)
#else
#           define UASM_PACK_PUSH_
#           define uXVC_ALGN uXVC_ALGN4
#           define uXVC_ALIGN_F32 uXVC_ALIGN4
#           define uXVC_ALIGN_F64 uXVC_ALIGN4
#           define uXVC_ALIGN_REAL uXVC_ALIGN4
#           define uXVC_ALIGN uXVC_ALIGN4

#           define uXGC_ALGN uXGC_ALGN4
#           define uXGC_ALIGN_F32 uXGC_ALIGN4
#           define uXGC_ALIGN_F64 uXGC_ALIGN4
#           define uXGC_ALIGN_REAL uXGC_ALIGN4
#           define uXGC_ALIGN uXGC_ALIGN4

#           define UASM_ALIGN_F32DECL(decl) UASM_ALIGN4DECL(decl)
#           define UASM_ALIGN_F64DECL(decl) UASM_ALIGN4DECL(decl)
#           define UASM_ALIGN_REALDECL(decl) UASM_ALIGN4DECL(decl)
#           define UASM_ALIGNDECLN(decl) UASM_ALIGN4DECL(decl)
#endif

//////////////////////////////////////////////////////////////////////////
// Math and constants align macro

// sample use UASM_NMALIGN(valor)
#if defined(UASM_UNALIGNED_MATH_CONST_ALIGN) && !defined(UASM_NO_ALIGN_MATH_INITIALIZED_CONST)
// unaligned initialized constants
#   define UASM_NMALIGN(decl) UASM_ALIGNDECLN(decl)
#else
#   define UASM_NMALIGN(decl) decl
#endif

// aligned initialized constants
#if !defined(UASM_NO_ALIGN_MATH_INITIALIZED_CONST)

#       define UASM_NMALIGN1(decl) UASM_ALIGN1DECL(decl)
#       define UASM_NMALIGN2(decl) UASM_ALIGN2DECL(decl)
#       define UASM_NMALIGN4(decl) UASM_ALIGN4DECL(decl)
#       define UASM_NMALIGN8(decl) UASM_ALIGN8DECL(decl)
#       define UASM_NMALIGN16(decl) UASM_ALIGN16DECL(decl)
#       define UASM_NMALIGN32(decl) UASM_ALIGN32DECL(decl)
#       define UASM_NMALIGN64(decl) UASM_ALIGN64DECL(decl)

#       define UASM_NMPACK_PUSH UASM_PACK_PUSH_
#       define UASM_NMPACK_PUSH1 UASM_PACK_PUSH_1
#       define UASM_NMPACK_PUSH2 UASM_PACK_PUSH_2
#       define UASM_NMPACK_PUSH4 UASM_PACK_PUSH_4
#       define UASM_NMPACK_PUSH8 UASM_PACK_PUSH_8
#       define UASM_NMPACK_PUSH16 UASM_PACK_PUSH_16
#       define UASM_NMPACK_PUSH32 UASM_PACK_PUSH_32
#       define UASM_NMPACK_PUSH64 UASM_PACK_PUSH_64

#else
#       define UASM_NMALIGN1(decl) decl
#       define UASM_NMALIGN2(decl) decl
#       define UASM_NMALIGN4(decl) decl
#       define UASM_NMALIGN8(decl) decl
#       define UASM_NMALIGN16(decl) decl
#       define UASM_NMALIGN32(decl) decl
#       define UASM_NMALIGN64(decl) decl
#endif
//////////////////////////////////////////////////////////////////////////

#   define  UASM_4x4ARRAY_2LOOP_UNROLL4(remval, unroll1, unroll2, refval) \
                                    remval[unroll1 + 0][unroll2 + 0] refval(unroll1 + 0, unroll2 + 0); \
                                    remval[unroll1 + 0][unroll2 + 1] refval(unroll1 + 0, unroll2 + 1); \
                                    remval[unroll1 + 0][unroll2 + 2] refval(unroll1 + 0, unroll2 + 2); \
                                    remval[unroll1 + 0][unroll2 + 3] refval(unroll1 + 0, unroll2 + 3); \
                                    \
                                    remval[unroll1 + 1][unroll2 + 0] refval(unroll1 + 1, unroll2 + 0); \
                                    remval[unroll1 + 1][unroll2 + 1] refval(unroll1 + 1, unroll2 + 1); \
                                    remval[unroll1 + 1][unroll2 + 2] refval(unroll1 + 1, unroll2 + 2); \
                                    remval[unroll1 + 1][unroll2 + 3] refval(unroll1 + 1, unroll2 + 3); \
                                    \
                                    remval[unroll1 + 2][unroll2 + 0] refval(unroll1 + 2, unroll2 + 0); \
                                    remval[unroll1 + 2][unroll2 + 1] refval(unroll1 + 2, unroll2 + 1); \
                                    remval[unroll1 + 2][unroll2 + 2] refval(unroll1 + 2, unroll2 + 2); \
                                    remval[unroll1 + 2][unroll2 + 3] refval(unroll1 + 2, unroll2 + 3); \
                                    \
                                    remval[unroll1 + 3][unroll2 + 0] refval(unroll1 + 3, unroll2 + 0); \
                                    remval[unroll1 + 3][unroll2 + 1] refval(unroll1 + 3, unroll2 + 1); \
                                    remval[unroll1 + 3][unroll2 + 2] refval(unroll1 + 3, unroll2 + 2); \
                                    remval[unroll1 + 3][unroll2 + 3] refval(unroll1 + 3, unroll2 + 3);

/**
Deprecated macro
- To deprecate a function: Place UASM_DEPRECATED at the start of the function header (leftmost word).
- To deprecate a 'typedef, a 'struct' or a 'class': Place UASM_DEPRECATED directly after the keywords ('typdef', 'struct', 'class').
*/
#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   if (defined(UASM_WINDOWS) || defined(UASM_XBOXONE) || defined(UASM_ARM)) && (_MSC_VER >= 1300) && !defined(MIDL_PASS)
#       define UASM_DEPRECATED(T) __declspec(deprecated) T
#       define UASM_DEPRECATED2(T,MSG) __declspec(deprecated(MSG)) T
#   else
#       define UASM_DEPRECATED /* nothing */
#       define UASM_DEPRECATED2(MSG) /* nothing */
#   endif
#elif defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_IBMC)
#       define UASM_DEPRECATED(T) __attribute__((deprecated)) T
#       define UASM_DEPRECATED2(T,MSG) __attribute__((deprecated)(MSG)) T
#else
#       define UASM_DEPRECATED(T) T
#       define UASM_DEPRECATED2(T,MSG) T
#endif

// VC6 no '__FUNCTION__' workaround
#if defined(UASM_VC6) && !defined(__FUNCTION__)
#   define __FUNCTION__ "Undefined"
#endif

#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_OFFSET_OF(X, Y) offsetof(X, Y)
#elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#   define UASM_OFFSET_OF(X, Y) __builtin_offsetof(X, Y)
#else
#   define UASM_OFFSET_OF(X, Y)
#endif

#define UASM_OFFSETOF_BASE 0x100 // casting the null ptr takes a special-case code path, which we don't want
#define UASM_OFFSET_OF_RT(Class, Member)                                                                                 \
    (reinterpret_cast<uXsize_t>(&reinterpret_cast<Class*>(UASM_OFFSETOF_BASE)->Member) - uXsize_t(UASM_OFFSETOF_BASE))

// use the compiler friendly but programmer ugly version for release only
#ifdef UASM_DEBUG
#   define UASM_MULTILINE_MACRO_BEGIN do {
#   define UASM_MULTILINE_MACRO_END       } while(0)
#else
#       define UASM_MULTILINE_MACRO_BEGIN if(1) {
#       define UASM_MULTILINE_MACRO_END       } else
#endif

#if  defined(UASM_CUDACC)
#       define UASM_BREAKPOINT(ID) _builtin_trap();
#elif defined(UASM_X86_OR_X64_CPU) || defined(UASM_XBOXONE)
#   if defined(UASM_VC)
#       define UASM_BREAKPOINT(ID) __debugbreak();
#   elif defined(UASM_NACL) // not allowed raise interrupts
#       define UASM_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#       define UASM_BREAKPOINT(ID) __builtin_trap();
#   else
#       define UASM_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   endif
#elif defined(UASM_XBOX360)
#   if defined(UASM_VC)
#       define UASM_BREAKPOINT(ID) __debugbreak();
#   else
#       define UASM_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   endif
#elif defined(UASM_PS3_PPU)
#       define UASM_BREAKPOINT(ID) __asm__ volatile ( "tw 31,1,1" )
#elif defined(UASM_PS3_SPU)
#       define UASM_BREAKPOINT(ID) __asm__ volatile ("ilhu $0, %0\n\tiohl $0, %1\n\tstopd $0,$0,$0" : : "i"(ID>>16), "i"(ID&0xFFFF) );
#elif defined(UASM_WIIU)
#       define UASM_BREAKPOINT(ID) OSDebug();
#elif defined(UASM_GEKKO)
#       define UASM_BREAKPOINT(ID)    UASM_MULTILINE_MACRO_BEGIN                        \
                                                                                                                                {                                               \
                                    register unsigned int UASM_ORIGINAL_MSR;      \
                                    register unsigned int UASM_NEW_MSR;           \
                                    asm volatile                                \
                                                                                                                                                {                                           \
                                        mfmsr UASM_ORIGINAL_MSR;                  /* Grab the original value of the MSR */ \
                                        ori UASM_NEW_MSR, UASM_ORIGINAL_MSR, 0x400; /* or the original MSR with 0x400 and store it */ \
                                        mtmsr UASM_NEW_MSR;                       /* Set the MSR to the new value - this will throw exception 0xD00 */ \
                                        mtmsr UASM_ORIGINAL_MSR;                  /* This puts the MSR back to its original state; required for*/\
                                                                                /* getting out of single-step mode (when the user resumes) */\
                                                                                                                                                }                                           \
                                                                                                                                }                                               \
                                UASM_MULTILINE_MACRO_END

#elif defined(UASM_ARM)
#   if defined(UASM_VC)
#       define UASM_BREAKPOINT(ID) __debugbreak();
#   elif defined(UASM_SNC)
#       define UASM_BREAKPOINT(ID) __breakpoint(0);
#   elif defined(UASM_GCC_COMPATIBLE_COMPILER)
#       define UASM_BREAKPOINT(ID) __builtin_trap();
#   else
#       define UASM_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   endif
#elif defined(UASM_CTR)
#   include <nn/dbg.h>
#       define UASM_BREAKPOINT(ID) ::nn::dbg::Break(nn::dbg::BREAK_REASON_ASSERT);
#else
#       define UASM_BREAKPOINT(ID) ((*((int*)0)) = ID);
#endif

#if (defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_ARM_COMPILER)) && defined(__ELF__)
#       define UASM_USE_DISPATCH_POINTER_SECTION  __attribute__((section(".data.DispatchPointer")))
#       define UASM_USE_DISPATCH_FUNCTION_SECTION __attribute__((section(".text.DispatchFunction")))
#  if defined(UASM_ARCH_ARM)
#       define UASM_USE_DISPATCH_TABLE_SECTION __attribute__((section(".rodata.DispatchTable,\"a\",%progbits @")))
#  else
#       define UASM_USE_DISPATCH_TABLE_SECTION __attribute__((section(".rodata.DispatchTable,\"a\",@progbits #")))
#  endif
#elif (defined(UASM_GCC_COMPATIBLE_COMPILER) || defined(UASM_ARM_COMPILER)) && defined(__MACH__)
#       define UASM_USE_DISPATCH_POINTER_SECTION  __attribute__((section("__DATA,__data.DispPtr")))
#       define UASM_USE_DISPATCH_FUNCTION_SECTION __attribute__((section("__TEXT,__text.DispFun")))
#       define UASM_USE_DISPATCH_TABLE_SECTION    __attribute__((section("__DATA,__const.DispTbl")))
#elif defined(UASM_MSVC_COMPATIBLE_COMPILER)
#       define UASM_USE_DISPATCH_POINTER_SECTION __declspec(allocate(".data$DispatchPointer"))
/* __declspec(allocate(...)) works with data only. Use pragma for code. */
#       define UASM_USE_DISPATCH_FUNCTION_SECTION
#       define UASM_USE_DISPATCH_TABLE_SECTION   __declspec(allocate(".rdata$DispatchTable"))
#else
#error "Unsupported compiler or output format"
#endif

/// Note that alignment must be a power of two for this to work.
/// Note: to use this macro you must cast your pointer to a byte pointer or to an integer value.
#   define UASM_NEXT_MULTIPLE_OF(Alignment, Value)  ( ((Value) + ((Alignment)-1)) & (~((Alignment)+(Value)*0-1)) )

/// The offset of a member within a structure
#   define UASM_OFFSET_OFCLASS(Class, Member) int(reinterpret_cast<long>(&(reinterpret_cast<Class*>(16)->Member))-16)

/// A check for whether the offset of a member within a structure is as expected
#   define UASM_OFFSET_EQUALS(Class, Member, Offset) (UASM_OFFSET_OFCLASS(Class,Member)==Offset)

//
// Helper macro THRUST_JOIN (based on BOOST_JOIN):
// The following piece of macro magic joins the two
// arguments together, even when one of the arguments is
// itself a macro (see 16.3.1 in C++ standard).  The key
// is that macro expansion of macro arguments does not
// occur in THRUST_DO_JOIN2 but does in THRUST_DO_JOIN.
//
/// Join two preprocessor tokens, even when a token is itself a macro.
#   define UASM_JOIN(A,B) UASM_JOIN2(A,B)
#   define UASM_JOIN2(A,B) UASM_JOIN3(A,B)
#   define UASM_JOIN3(A,B) A##B

/// Creates an uninitialized buffer large enough for object of type TYPE to fit in while aligned to ALIGN boundary. Creates a pointer VAR to this aligned address.
#   define UASM_DECLARE_ALIGNED_LOCAL_PTR( TYPE, VAR, ALIGN  )                                        \
    const int VAR ## BufferSize = ALIGN + sizeof(TYPE);                                             \
    char VAR ## Buffer[VAR ## BufferSize];                                                          \
    TYPE* VAR = reinterpret_cast<TYPE*>(UASM_NEXT_MULTIPLE_OF(ALIGN, unsigned long(VAR ## Buffer)));  

#   define UASM_SIZE_OF(Class, Member)            sizeof(((Class*)0)->Member)

#ifdef __cplusplus
// avoid unreferenced parameter warning
// preferred solution: omit the parameter's name from the declaration
template <class T>
UASM_TARGET_CPU_GPU_INLINE(void) UASM_UNREFPAR_UNUSED(T const&) UASM_CPU_AMP {}
#   define UASM_UNUSED(_P) UASM_UNREFPAR_UNUSED(_P)
#else
#   define UASM_UNUSED(_P) (void)(_P)
#endif //__cplusplus

// An expression that should expand to nothing in non UASM_DEBUG builds.
// currently use this only for tagging the purpose of containers for memory use tracking.
#if defined(UASM_DEBUG)
#   define UASM_DEBUG_EXP(x) (x)
#   define UASM_DEBUG_EXP_C(x) x,
#else
#   define UASM_DEBUG_EXP(x)
#   define UASM_DEBUG_EXP_C(x)
#endif

#if defined(UASM_INTRIN_DEBUG)
/*
#   define UASM_INTRIN_VEC_DEBUG 1
#include <iostream>
/ * Figure out whether and how to define the output operators * /
#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM) || defined(_GLIBCXX_IOSTREAM) || defined(_LIBCPP_IOSTREAM)
#   define UASM_INTRINVEC_OUTPUT_OPERATORS 1
#   define UASM_STDOSTREAM std::ostream
#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
#   define UASM_INTRINVEC_OUTPUT_OPERATORS 1
#   define UASM_STDOSTREAM ostream
#endif*/

#endif

#   define UASM_SIGN_BITMASK      0x80000000

// Macro for avoiding default assignment and copy
// because NoCopy inheritance can increase class size on some platforms.
#   define UASM_NOCOPY(Class) \
    Class(const Class &); \
    Class &operator=(const Class &);

// use in a cpp file to suppress LNK4221
#if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#   define UASM_DUMMY_SYMBOL namespace { char uXDummySymbol; }
#else
#   define UASM_DUMMY_SYMBOL
#endif

#if defined(UASM_GCC_COMPATIBLE_COMPILER)
#   define UASM_WEAK_SYMBOL __attribute__((weak)) // this is to support SIMD constant merging in template specialization
#else
#   define UASM_WEAK_SYMBOL
#endif

#ifndef UASM_USE_DOUBLE_PRECISION

# if defined(UASM_AMP_USE_PRECISE_PRECISION)
#   define ampmath(Name) __dp_math_##Name
# elif defined(UASM_AMP_USE_FAST_PRECISION)
#   define ampmath(Name) __dp_d3d_##Name
# endif

# if defined(UASM_CUDA_SUPPORT)
// gets expanded to __nv_Name
#   define nvmath(Name)   __nv_##Name
# endif
#else

# if defined(UASM_AMP_USE_PRECISE_PRECISION)
#   define ampmath(Name) __dp_math_##Name
# elif defined(UASM_AMP_SUPPORT) && defined(UASM_AMP_USE_FAST_PRECISION)
#error : AMP concurrency fast_math don't have double precision and double precision cannot be used with fast math in all situations
# endif

# if defined(UASM_CUDA_SUPPORT)
// gets expanded to __nv_Name
#   define nvmath(Name)   __nv_##Name
# elif defined(UASM_CUDA_SUPPORT) && defined(UASM_CUDA_USE_FAST_PRECISION)
#error : CUDA fast math don't have double precision and double precision cannot be used with fast math in all situations
# endif
#endif /* UASM_USE_DOUBLE_PRECISION */

//#if defined(UASM_DIRECTXMATH_SUPPORT)
#   define namespace_DirectX namespace DirectX {
#   define namespace_DirectX_end }
//#endif

#   define namespace_uX namespace uX {
#   define namespace_UASM_end }

#   define namespace_CPU namespace CPU {
#   define namespace_CPU_end }

#   define namespace_internal namespace _internal {
#   define namespace_internal_end }

#   define namespace_uXOAMP namespace uXOAMP {
#   define namespace_uXOAMP_end }

#   define namespace_Math namespace Math {
#   define namespace_Math_end }

#if defined(UASM_AMP_SUPPORT)
#   define namespace_AMP namespace AMP {
#   define namespace_AMP_end }

#   define namespace_AMPMath namespace AMPMath {
#   define namespace_AMPMath_end }
#endif

#   define namespace_uXTemplate namespace uXTemplate {
#   define namespace_uXTemplate_end }

#   define namespace_uXTMath namespace uXTMath {
#   define namespace_uXTMath_end }

#if defined(UASM_SSE_INTRINSICS)
#   define namespace_uXSSE namespace uXSSE {
#   define namespace_uXSSE_end }
#endif

#if defined(UASM_CUDA_SUPPORT)
#   define namespace_CUDA namespace CUDA {
#   define namespace_CUDA_end }

#   define namespace_CUDAMath namespace CUDAMath {
#   define namespace_CUDAMath_end }
#endif

#   define namespace_Intrin namespace Intrin {
#   define namespace_Intrin_end }

#   define namespace_IntrinMath namespace IntrinMath {
#   define namespace_IntrinMath_end }

#   define namespace_std namespace std {
#   define namespace_std_end }

#   define namespace_XMM namespace xmm {
#   define namespace_XMM_end }

#   define namespace_YMM namespace ymm {
#   define namespace_YMM_end }

#   define namespace_ZMM namespace zmm {
#   define namespace_ZMM_end }

/*
namespace_uXOAMP
namespace_uXOAMP_end*/
/*namespace uX = uXOAMP;*/

# if !defined(UASM_NO_DIRECTXMATH_SUPPORT)
/*
namespace_DirectX
namespace_DirectX_end*/
/*namespace DX = DirectX;*/
# endif

#endif // UASM_BASEDEFS_H
