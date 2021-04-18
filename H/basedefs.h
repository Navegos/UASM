
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

#ifndef uasm_BASEDEFS_H
#define uasm_BASEDEFS_H 1

#ifndef uasm_PREPROCESSOR_H
#include "preprocessor.h"
#endif  /* uasm_PREPROCESSOR_H */

#ifndef uasm_EXPORTS_H
#include "exports.h"
#endif  /* uasm_EXPORTS_H */

/**
Calling convention  // currently defined for windows only for (MSVC / Intel ICW) & (GCC compatible compiler / Intel ICU), needs researching for other compilers implementation
*/
#if defined(uasm_MSVC_COMPATIBLE_COMPILER) && !defined(uasm_MIC)
#  if defined(uasm_X86_OR_X64_CPU)
#     define uasm_cdecl __cdecl
#     define uasm_stdcall __stdcall
#     define uasm_fastcall __fastcall
#    ifndef uasm_callconv
#      if defined(uasm_VECTORCALL_SUPPORT)
#        if defined(uasm_VC) || defined(uasm_CLANGW) || defined(uasm_ICW)
#           define uasm_callconv __vectorcall
#        else
#           define uasm_callconv __fastcall
#        endif
#      else
#           define uasm_callconv __fastcall
#      endif
#    endif //uasm_callconv
#    ifndef uasm_veccall
#      if defined(uasm_VECTORCALL_SUPPORT)
#        if defined(uasm_VC) || defined(uasm_CLANGW) || defined(uasm_ICW)
#           define uasm_veccall __vectorcall
#        else
#           define uasm_veccall
#        endif
#      else
#           define uasm_veccall
#      endif
#    endif //uasm_veccall
#    ifndef uasm_regcall
#      if defined(uasm_REGCALL_SUPPORT)
#        if defined(uasm_CLANGW) || defined(uasm_ICW) && !defined(uasm_VC)
#           define uasm_regcall __regcall
#        else
#           define uasm_regcall
#        endif
#      else
#           define uasm_regcall
#      endif
#    endif //uasm_regcall
#  else
#       define uasm_cdecl
#       define uasm_stdcall
#       define uasm_fastcall
#       define uasm_callconv
#       define uasm_veccall
#       define uasm_regcall
#   endif //uasm_X86_OR_X64_CPU
#elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#  if defined(uasm_X86_OR_X64_CPU)
#   if defined(uasm_WINDOWS)
#    ifndef uasm_callconv
#      if defined(uasm_VECTORCALL_SUPPORT)
#        if defined(uasm_CLANG) || defined(uasm_ICC)
#           define uasm_callconv __attribute__((vectorcall))
#        elif defined(uasm_GCC)
#           define uasm_callconv __attribute__((ms_abi))
#        else
#           define uasm_callconv __attribute__((fastcall))
#        endif
#      else
#           define uasm_callconv __attribute__((fastcall))
#      endif
#    endif //uasm_callconv
#    ifndef uasm_veccall
#      if defined(uasm_VECTORCALL_SUPPORT)
#        if defined(uasm_CLANG) || defined(uasm_ICC)
#           define uasm_veccall __attribute__((vectorcall))
#        elif defined(uasm_GCC)
#           define uasm_veccall __attribute__((ms_abi))
#        else
#           define uasm_veccall
#        endif
#      else
#           define uasm_veccall
#      endif
#    endif //uasm_veccall
#    ifndef uasm_regcall
#      if defined(uasm_REGCALL_SUPPORT)
#        if defined(uasm_CLANG) || defined(uasm_ICC) && !defined(uasm_VC)
#           define uasm_regcall __attribute__((regcall))
#        else
#           define uasm_regcall
#        endif
#      else
#           define uasm_regcall
#      endif
#    endif //uasm_regcall
/*
# if defined(uasm_ICREGCALL)
#   define uasm_callconv(T) __attribute__((regcall)) T
#   define uasm_veccall(T) __attribute__((regcall)) T
#else*/
#  if defined(uasm_X86_OR_X64_CPU) && !defined(uasm_MIC)
#   define uasm_callconv __attribute__((sysv_abi))
#   define uasm_veccall __attribute__((sysv_abi))
#  else
#   define uasm_callconv
#   define uasm_veccall
#  endif
/*# endif*/
#   if defined(uasm_X86_OR_X64_CPU) && !defined(uasm_MIC)
#   define uasm_cdecl __attribute__((cdecl))
#   define uasm_fastcall __attribute__((fastcall))
#   define uasm_stdcall  __attribute__((stdcall))
# else
#   define uasm_cdecl
#   define uasm_fastcall
#   define uasm_stdcall
# endif
#    endif //uasm_WINDOWS
#   endif //uasm_X86_OR_X64_CPU
#else
#   define uasm_callconv
#   define uasm_veccall
#   define uasm_cdecl
#   define uasm_stdcall
#   define uasm_fastcall
#endif

#if defined(uasm_X86_OR_X64_ABI) && (defined(uasm_MSVC_COMPATIBLE_COMPILER))
#   define uasm_ABI uasm_callconv
//#   define uasm_ABI 
#elif defined(uasm_X86_OR_X64_ABI) && (defined(uasm_GCC_COMPATIBLE_COMPILER))
#   define uasm_ABI uasm_callconv
#else
#   define uasm_ABI
#endif

#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_PACK_PUSH_DEF(X)          __pragma(pack(push, X) )
#   define uasm_PACK_PUSH_1                __pragma(pack(push, 1) )
#   define uasm_PACK_PUSH_2                __pragma(pack(push, 2) )
#   define uasm_PACK_PUSH_4                __pragma(pack(push, 4) )
#   define uasm_PACK_PUSH_8                __pragma(pack(push, 8) )
#   define uasm_PACK_PUSH_16               __pragma(pack(push, 16) )
#   define uasm_PACK_DEF(X)           __pragma(pack(X) )
#   define uasm_PACK_1                 __pragma(pack(1) )
#   define uasm_PACK_2                 __pragma(pack(2) )
#   define uasm_PACK_4                 __pragma(pack(4) )
#   define uasm_PACK_8                 __pragma(pack(8) )
#   define uasm_PACK_16                __pragma(pack(16) )
# if (defined(_MSC_VER) && (_MSC_VER >= 1600)) || (defined(_MSC_VER) && (__INTEL_COMPILER >= 1300))
#   define uasm_PACK_PUSH_32               __pragma(pack(push, 32) )
#   define uasm_PACK_PUSH_64               __pragma(pack(push, 64) )
#   define uasm_PACK_PUSH_128              __pragma(pack(push, 128) )
#   define uasm_PACK_PUSH_256              __pragma(pack(push, 256) )
#   define uasm_PACK_PUSH_512              __pragma(pack(push, 512) )
#   define uasm_PACK_32                __pragma(pack(32) )
#   define uasm_PACK_64                __pragma(pack(64) )
#   define uasm_PACK_128               __pragma(pack(128) )
#   define uasm_PACK_256               __pragma(pack(256) )
#   define uasm_PACK_512               __pragma(pack(512) )
#else
#   define uasm_PACK_PUSH_32               __pragma(pack(push, 16) )
#   define uasm_PACK_PUSH_64               __pragma(pack(push, 16) )
#   define uasm_PACK_PUSH_128              __pragma(pack(push, 16) )
#   define uasm_PACK_PUSH_256              __pragma(pack(push, 16) )
#   define uasm_PACK_PUSH_512              __pragma(pack(push, 16) )
#   define uasm_PACK_32                __pragma(pack(16) )
#   define uasm_PACK_64                __pragma(pack(16) )
#   define uasm_PACK_128               __pragma(pack(16) )
#   define uasm_PACK_256               __pragma(pack(16) )
#   define uasm_PACK_512               __pragma(pack(16) )
# endif
#   define uasm_PACK_PUSH_STACK           __pragma(pack(push, uasm_STACK_SIZE) )
#   define uasm_PACK_PUSH_SIZE_T          __pragma(pack(push, uasm_SIZE_T_SIZE) )
#   define uasm_PACK_PUSH_PTR             __pragma(pack(push, uasm_PTR_SIZE) )
#   define uasm_PACK_STACK                __pragma(pack(uasm_STACK_SIZE) )
#   define uasm_PACK_SIZE_T               __pragma(pack(uasm_SIZE_T_SIZE) )
#   define uasm_PACK_PTR                  __pragma(pack(uasm_PTR_SIZE) )
#   define uasm_PACK_POP                  __pragma(pack(pop) )
#   define uasm_PRAGMA_ONCE               __pragma(once)
#   define uasm_PRAGMA(exprs)             __pragma(exprs)
#   define uasm_PRAGMA_OPTIMIZE_OFF           __pragma(optimize("", off))
#   define uasm_PRAGMA_OPTIMIZE_ON            __pragma(optimize("", on))
#elif (uasm_GCC_COMPATIBLE_COMPILER) && !defined(__SPU__)
#   define uasm_PACK_PUSH_DEF(X)          _Pragma("pack(push, X)")
#   define uasm_PACK_PUSH_1               _Pragma("pack(push, 1)")
#   define uasm_PACK_PUSH_2               _Pragma("pack(push, 2)")
#   define uasm_PACK_PUSH_4               _Pragma("pack(push, 4)")
#   define uasm_PACK_PUSH_8               _Pragma("pack(push, 8)")
#   define uasm_PACK_PUSH_16              _Pragma("pack(push, 16)")
#   define uasm_PACK_PUSH_32              _Pragma("pack(push, 32)")
#   define uasm_PACK_PUSH_64              _Pragma("pack(push, 64)")
#   define uasm_PACK_PUSH_128             _Pragma("pack(push, 128)")
#   define uasm_PACK_PUSH_256             _Pragma("pack(push, 256)")
#   define uasm_PACK_PUSH_512             _Pragma("pack(push, 512)")
#   define uasm_PACK_PUSH_STACK           _Pragma("pack(push, uasm_STACK_SIZE)")
#   define uasm_PACK_PUSH_SIZE_T          _Pragma("pack(push, uasm_SIZE_T_SIZE)")
#   define uasm_PACK_PUSH_PTR         _Pragma("pack(push, uasm_PTR_SIZE)")
#   define uasm_PACK_DEF(X)           _Pragma("pack(X)")
#   define uasm_PACK_1                _Pragma("pack(1)")
#   define uasm_PACK_2                _Pragma("pack(2)")
#   define uasm_PACK_4                _Pragma("pack(4)")
#   define uasm_PACK_8                _Pragma("pack(8)")
#   define uasm_PACK_16               _Pragma("pack(16)")
#   define uasm_PACK_32               _Pragma("pack(32)")
#   define uasm_PACK_64               _Pragma("pack(64)")
#   define uasm_PACK_128              _Pragma("pack(128)")
#   define uasm_PACK_256              _Pragma("pack(256)")
#   define uasm_PACK_512              _Pragma("pack(512)")
#   define uasm_PACK_STACK            _Pragma("pack(uasm_STACK_SIZE)")
#   define uasm_PACK_SIZE_T           _Pragma("pack(uasm_SIZE_T_SIZE)")
#   define uasm_PACK_PTR              _Pragma("pack(uasm_PTR_SIZE)")
#   define uasm_PACK_POP                  _Pragma("pack(pop)")
#   define uasm_PRAGMA_ONCE               _Pragma("once")
#   define uasm_PRAGMA(exprs)             _Pragma(uasm_Stringer(exprs))
# if defined(__clang__)
#   define _PRAGMA_OPTIMIZE_OFF     _Pragma("clang optimize(off)")
#   define _PRAGMA_OPTIMIZE_ON      _Pragma("clang optimize(on)")
# elif defined(__GNUC__)
#   define _PRAGMA_OPTIMIZE_OFF     _Pragma("gcc optimize(off)")
#   define _PRAGMA_OPTIMIZE_ON      _Pragma("gcc optimize(on)")
# endif
#elif defined(uasm_IBMC)
#   define uasm_PACK_PUSH_DEF(X)          _Pragma("pack(X)")
#   define uasm_PACK_PUSH_1                _Pragma("pack(1)")
#   define uasm_PACK_PUSH_2                _Pragma("pack(2)")
#   define uasm_PACK_PUSH_4                _Pragma("pack(4)")
#   define uasm_PACK_PUSH_8                _Pragma("pack(8)")
#   define uasm_PACK_PUSH_16               _Pragma("pack(16)")
#   define uasm_PACK_PUSH_32               _Pragma("pack(32)")
#   define uasm_PACK_PUSH_64               _Pragma("pack(64)")
#   define uasm_PACK_PUSH_128              _Pragma("pack(128)")
#   define uasm_PACK_PUSH_256              _Pragma("pack(256)")
#   define uasm_PACK_PUSH_512              _Pragma("pack(512)")
#   define uasm_PACK_PUSH_STACK            _Pragma("pack(uasm_STACK_SIZE)")
#   define uasm_PACK_PUSH_SIZE_T           _Pragma("pack(uasm_SIZE_T_SIZE)")
#   define uasm_PACK_PUSH_PTR         _Pragma("pack(uasm_PTR_SIZE)")
#   define uasm_PACK_DEF(X)           _Pragma("pack(X)")
#   define uasm_PACK_1                 _Pragma("pack(1)")
#   define uasm_PACK_2                 _Pragma("pack(2)")
#   define uasm_PACK_4                 _Pragma("pack(4)")
#   define uasm_PACK_8                 _Pragma("pack(8)")
#   define uasm_PACK_16                _Pragma("pack(16)")
#   define uasm_PACK_32                _Pragma("pack(32)")
#   define uasm_PACK_64                _Pragma("pack(64)")
#   define uasm_PACK_128               _Pragma("pack(128)")
#   define uasm_PACK_256               _Pragma("pack(256)")
#   define uasm_PACK_512               _Pragma("pack(512)")
#   define uasm_PACK_STACK            _Pragma("pack(uasm_STACK_SIZE)")
#   define uasm_PACK_SIZE_T           _Pragma("pack(uasm_SIZE_T_SIZE)")
#   define uasm_PACK_PTR              _Pragma("pack(uasm_PTR_SIZE)")
#   define uasm_PACK_POP                  _Pragma("pack(pop)")
#   define uasm_PRAGMA_ONCE               _Pragma("once")
#   define uasm_PRAGMA(exprs)             _Pragma(uasm_Stringer(exprs))
#   define _PRAGMA_OPTIMIZE_OFF     _Pragma("ibmc optimize(off)")
#   define _PRAGMA_OPTIMIZE_ON      _Pragma("ibmc optimize(on)")
#else
#   define uasm_PACK_PUSH_DEF(X)
#   define uasm_PACK_PUSH_1
#   define uasm_PACK_PUSH_2
#   define uasm_PACK_PUSH_4
#   define uasm_PACK_PUSH_8
#   define uasm_PACK_PUSH_16
#   define uasm_PACK_PUSH_32
#   define uasm_PACK_PUSH_64
#   define uasm_PACK_PUSH_128
#   define uasm_PACK_PUSH_256
#   define uasm_PACK_PUSH_512
#   define uasm_PACK_PUSH_STACK
#   define uasm_PACK_PUSH_SIZE_T
#   define uasm_PACK_PUSH_PTR
#   define uasm_PACK_DEF(X)
#   define uasm_PACK_1
#   define uasm_PACK_2
#   define uasm_PACK_4
#   define uasm_PACK_8
#   define uasm_PACK_16
#   define uasm_PACK_32
#   define uasm_PACK_64
#   define uasm_PACK_128
#   define uasm_PACK_256
#   define uasm_PACK_512
#   define uasm_PACK_STACK
#   define uasm_PACK_SIZE_T
#   define uasm_PACK_PTR
#   define uasm_PACK_POP
#   define uasm_PRAGMA_ONCE
#   define uasm_PRAGMAERROR(exprs)
#   define uasm_PRAGMA(exprs)
#   define _PRAGMA_OPTIMIZE_OFF
#   define _PRAGMA_OPTIMIZE_ON
#endif

#   define uasm_PACK_PUSH_MM      uasm_PACK_PUSH_8
#   define uasm_PACK_PUSH_XMM     uasm_PACK_PUSH_16
#   define uasm_PACK_PUSH_YMM     uasm_PACK_PUSH_32
#   define uasm_PACK_PUSH_ZMM     uasm_PACK_PUSH_64
#   define uasm_PACK_PUSH_M64      uasm_PACK_PUSH_8
#   define uasm_PACK_PUSH_M128     uasm_PACK_PUSH_16
#   define uasm_PACK_PUSH_M256     uasm_PACK_PUSH_32
#   define uasm_PACK_PUSH_M512     uasm_PACK_PUSH_64

#   define uasm_PACK_MM      uasm_PACK_8
#   define uasm_PACK_XMM     uasm_PACK_16
#   define uasm_PACK_YMM     uasm_PACK_32
#   define uasm_PACK_ZMM     uasm_PACK_64
#   define uasm_PACK_M64      uasm_PACK_8
#   define uasm_PACK_M128     uasm_PACK_16
#   define uasm_PACK_M256     uasm_PACK_32
#   define uasm_PACK_M512     uasm_PACK_64

/**
Inline macro
*/
# if defined(uasm_MSVC_COMPATIBLE_COMPILER)
uasm_PRAGMA(inline_depth(255))
//# pragma inline_depth( 255 )
#   ifndef uasm_INLINE
#     ifndef uasm_DEBUG
// inline on in release build for static inline
#       define __uasm_S_INLINE(T) static __inline T
// inline on in release build for static inline
#       define _uasm_S_INLINE(T) static __inline T

// inline on in release build for static inline
#       define __uasm_S_INLINEART(T) static __inline T
// inline on in release build for static inline
#       define _uasm_S_INLINEART(T) static __inline T

// forceinline on in release build for static forceinline
#       define __uasm_S_FINLINE(T) static __forceinline T
// forceinline on in release build for static forceinline
#       define __uasm_S_FINLINEART(T) static __forceinline T

// inline on in release build for inline only
#       define __uasm_INLINE(T) __inline T
// inline on in release build for inline only
#       define _uasm_INLINE(T) __inline T

// inline on in release build for inline only
#       define __uasm_INLINEART(T) __inline T
// inline on in release build for inline only
#       define _uasm_INLINEART(T) __inline T

// forceinline on release build for forceinline only
#       define __uasm_FINLINE(T) __forceinline T
// forceinline on release build for forceinline only
#       define __uasm_FINLINEART(T) __forceinline T

// inline on in release build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static __inline uasm_veccall(T)
// inline on in release build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static __inline uasm_veccall(T)

// inline on in release build for static inline with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static __inline uasm_veccall(T)
// inline on in release build for static inline with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static __inline uasm_veccall(T)

// forceinline on in release build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static __forceinline uasm_veccall(T)
// forceinline on in release build for static forceinline with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static __forceinline uasm_veccall(T)

// inline on in release build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) __inline uasm_veccall(T)
// inline on in release build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) __inline uasm_veccall(T)

// inline on in release build for inline only with veccall
#       define __uasm_INLINEART_VECCALL(T) __inline uasm_veccall(T)
// inline on in release build for inline only with veccall
#       define _uasm_INLINEART_VECCALL(T) __inline uasm_veccall(T)

// forceinline on in release build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) __forceinline uasm_veccall(T)
// forceinline on in release build for forceinline only with veccall
#       define __uasm_FINLINEART_VECCALL(T) __forceinline uasm_veccall(T)
#     else
// inline of in debug build for static inline
#       define __uasm_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _uasm_S_INLINE(T) static T

// inline of in debug build for static inline
#       define __uasm_S_INLINEART(T) static T
// inline of in debug build for static inline
#       define _uasm_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __uasm_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline
#       define __uasm_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __uasm_INLINE(T) T
// inline of in debug build for inline only
#       define _uasm_INLINE(T) T

// inline of in debug build for inline only
#       define __uasm_INLINEART(T) T
// inline of in debug build for inline only
#       define _uasm_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __uasm_FINLINE(T) T
// forceinline of in debug build for forceinline only
#       define __uasm_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for static inline with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static uasm_veccall(T)
// forceinline of in debug build for static forceinline with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) uasm_veccall(T)

// inline of in debug build for inline only with veccall
#       define __uasm_INLINEART_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only with veccall
#       define _uasm_INLINEART_VECCALL(T) uasm_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) uasm_veccall(T)
// forceinline of in debug build for forceinline only with veccall
#       define __uasm_FINLINEART_VECCALL(T) uasm_veccall(T)
#     endif // uasm_DEBUG

// inline hallways on for static inline
#       define uasm_S_INLINE(T) static __inline T
// inline hallways on for static inline
#       define uasm_S_INLINEART(T) static __inline T

// forceinline hallways on for static forceinline
#       define uasm_S_FINLINE(T) static __forceinline T
// forceinline hallways on for static forceinline
#       define uasm_S_FINLINEART(T) static __forceinline T

// inline hallways on for inline only
#       define uasm_INLINE(T) __inline T
// inline hallways on for inline only
#       define uasm_INLINEART(T) __inline T

// forceinline hallways on for forceinline only
#       define uasm_FINLINE(T) __forceinline T
// forceinline hallways on for forceinline only
#       define uasm_FINLINEART(T) __forceinline T

// inline hallways on for static inline with veccall
#       define uasm_S_INLINE_VECCALL(T) static __inline uasm_veccall(T)
// inline hallways on for static inline with veccall
#       define uasm_S_INLINEART_VECCALL(T) static __inline uasm_veccall(T)

// forceinline hallways on for static forceinline with veccall
#       define uasm_S_FINLINE_VECCALL(T) static __forceinline uasm_veccall(T)
// forceinline hallways on for static forceinline with veccall
#       define uasm_S_FINLINEART_VECCALL(T) static __forceinline uasm_veccall(T)

// inline hallways on for inline only with veccall
#       define uasm_INLINE_VECCALL(T) __inline uasm_veccall(T)
// inline hallways on for inline only with veccall
#       define uasm_INLINEART_VECCALL(T) __inline uasm_veccall(T)

// forceinline hallways on for forceinline only with veccall
#       define uasm_FINLINE_VECCALL(T) __forceinline uasm_veccall(T)
// forceinline hallways on for forceinline only with veccall
#       define uasm_FINLINEART_VECCALL(T) __forceinline uasm_veccall(T)
#   endif // uasm_INLINE
#elif defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_IBMC)
#  if defined(uasm_GNUC) && !defined(uasm_CLANG)
uasm_PRAGMA(inline_depth(255))
#   ifndef uasm_INLINE
#     ifndef uasm_DEBUG
// inline on in release build for static inline
#       define __uasm_S_INLINE(T) static  inline T __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for static inline
#       define _uasm_S_INLINE(T) static  inline T __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for static inline artificial
#       define __uasm_S_INLINEART(T) static  inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for static inline artificial
#       define _uasm_S_INLINEART(T) static  inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for static forceinline
#       define __uasm_S_FINLINE(T) static inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline on in release build for inline only
#       define __uasm_INLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for inline only
#       define _uasm_INLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for inline only artificial
#       define __uasm_INLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for inline only artificial
#       define _uasm_INLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for forceinline only
#       define __uasm_FINLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for forceinline only artificial
#       define __uasm_FINLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline on in release build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline on in release build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline on in release build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))

// inline on in release build for static inline artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
// inline on in release build for static inline artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline on in release build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline on in release build for forceinline artificial only with veccall
#       define __uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
#     else
// inline of in debug build for static inline
#       define __uasm_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _uasm_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __uasm_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _uasm_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __uasm_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __uasm_INLINE(T) T
// inline of in debug build for inline only
#       define _uasm_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __uasm_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _uasm_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __uasm_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __uasm_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static uasm_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) uasm_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) uasm_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) uasm_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __uasm_FINLINEART_VECCALL(T) uasm_veccall(T)
#     endif // uasm_DEBUG

// inline hallways on for static inline
#       define uasm_S_INLINE(T)  static inline T __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for static inline artificial
#       define uasm_S_INLINEART(T) static inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for static forceinline
#       define uasm_S_FINLINE(T) static inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for static forceinline artificial
#       define uasm_S_FINLINEART(T) static inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline hallways on for inline only
#       define uasm_INLINE(T)  inline T __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for inline only artificial
#       define uasm_INLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for forceinline only
#       define uasm_FINLINE(T) inline T __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for forceinline only artificial
#       define uasm_FINLINEART(T) inline T __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline hallways on for static inline with veccall
#       define uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for static inline artificial with veccall
#       define uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for static forceinline with veccall
#       define uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for static forceinline artificial with veccall
#       define uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// inline hallways on for inline only with veccall
#       define uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// inline hallways on for inline only artificial with veccall
#       define uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))

// forceinline hallways on for forceinline only with veccall
#       define uasm_FINLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__))
// forceinline hallways on for forceinline only artificial with veccall
#       define uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__gnu_inline__, __always_inline__, __artificial__))
#   endif // uasm_INLINE
#  elif defined(uasm_CLANG)
uasm_PRAGMA(inline_depth(255))
#   ifndef uasm_INLINE
#     ifndef uasm_DEBUG
// inline on in release build for static inline
#       define __uasm_S_INLINE(T) static  inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline
#       define _uasm_S_INLINE(T) static  inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline artificial
#       define __uasm_S_INLINEART(T) static  inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline artificial
#       define _uasm_S_INLINEART(T) static  inline T __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for static forceinline
#       define __uasm_S_FINLINE(T) static inline T __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for inline only
#       define __uasm_INLINE(T) inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for inline only
#       define _uasm_INLINE(T) inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for inline only artificial
#       define __uasm_INLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))
// inline on in release build for inline only artificial
#       define _uasm_INLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for forceinline only
#       define __uasm_FINLINE(T) inline T __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for forceinline only artificial
#       define __uasm_FINLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline on in release build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline on in release build for static inline artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline on in release build for static inline artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline on in release build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline on in release build for forceinline artificial only with veccall
#       define __uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
#     else
// inline of in debug build for static inline
#       define __uasm_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _uasm_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __uasm_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _uasm_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __uasm_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __uasm_INLINE(T) T
// inline of in debug build for inline only
#       define _uasm_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __uasm_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _uasm_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __uasm_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __uasm_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static uasm_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) uasm_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) uasm_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) uasm_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __uasm_FINLINEART_VECCALL(T) uasm_veccall(T)
#     endif // uasm_DEBUG

// inline hallways on for static inline
#       define uasm_S_INLINE(T)  static inline T __attribute__((__always_inline__, __nodebug__))
// inline hallways on for static inline artificial
#       define uasm_S_INLINEART(T) static inline T __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for static forceinline
#       define uasm_S_FINLINE(T) static inline T __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for static forceinline artificial
#       define uasm_S_FINLINEART(T) static inline T __attribute__((__always_inline__, __nodebug__))

// inline hallways on for inline only
#       define uasm_INLINE(T)  inline T __attribute__((__always_inline__, __nodebug__))
// inline hallways on for inline only artificial
#       define uasm_INLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for forceinline only
#       define uasm_FINLINE(T) inline T __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for forceinline only artificial
#       define uasm_FINLINEART(T) inline T __attribute__((__always_inline__, __nodebug__))

// inline hallways on for static inline with veccall
#       define uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline hallways on for static inline artificial with veccall
#       define uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for static forceinline with veccall
#       define uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for static forceinline artificial with veccall
#       define uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// inline hallways on for inline only with veccall
#       define uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// inline hallways on for inline only artificial with veccall
#       define uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))

// forceinline hallways on for forceinline only with veccall
#       define uasm_FINLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
// forceinline hallways on for forceinline only artificial with veccall
#       define uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((__always_inline__, __nodebug__))
#   endif // uasm_INLINE
#  else
uasm_PRAGMA(inline_depth(255))
#   ifndef uasm_INLINE
#     ifndef uasm_DEBUG
// inline on in release build for static inline
#       define __uasm_S_INLINE(T) static  inline T __attribute__((always_inline))
// inline on in release build for static inline
#       define _uasm_S_INLINE(T) static  inline T __attribute__((always_inline))

// inline on in release build for static inline artificial
#       define __uasm_S_INLINEART(T) static  inline T __attribute__((always_inline))
// inline on in release build for static inline artificial
#       define _uasm_S_INLINEART(T) static  inline T __attribute__((always_inline))

// forceinline on in release build for static forceinline
#       define __uasm_S_FINLINE(T) static inline T __attribute__((always_inline))
// forceinline on in release build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static inline T __attribute__((always_inline))

// inline on in release build for inline only
#       define __uasm_INLINE(T) inline T __attribute__((always_inline))
// inline on in release build for inline only
#       define _uasm_INLINE(T) inline T __attribute__((always_inline))

// inline on in release build for inline only artificial
#       define __uasm_INLINEART(T) inline T __attribute__((always_inline))
// inline on in release build for inline only artificial
#       define _uasm_INLINEART(T) inline T __attribute__((always_inline))

// forceinline on in release build for forceinline only
#       define __uasm_FINLINE(T) inline T __attribute__((always_inline))
// forceinline on in release build for forceinline only artificial
#       define __uasm_FINLINEART(T) inline T __attribute__((always_inline))

// inline on in release build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))
// inline on in release build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))

// inline on in release build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))
// inline on in release build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))

// forceinline on in release build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))
// forceinline on in release build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))

// inline on in release build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
// inline on in release build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))

// inline on in release build for static inline artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
// inline on in release build for static inline artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))

// forceinline on in release build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
// forceinline on in release build for forceinline artificial only with veccall
#       define __uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
#     else
// inline of in debug build for static inline
#       define __uasm_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _uasm_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __uasm_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _uasm_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __uasm_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __uasm_INLINE(T) T
// inline of in debug build for inline only
#       define _uasm_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __uasm_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _uasm_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __uasm_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __uasm_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static uasm_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) uasm_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) uasm_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) uasm_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __uasm_FINLINEART_VECCALL(T) uasm_veccall(T)
#     endif // uasm_DEBUG

// inline hallways on for static inline
#       define uasm_S_INLINE(T)  static inline T __attribute__((always_inline))
// inline hallways on for static inline artificial
#       define uasm_S_INLINEART(T) static inline T __attribute__((always_inline))

// forceinline hallways on for static forceinline
#       define uasm_S_FINLINE(T) static inline T __attribute__((always_inline))
// forceinline hallways on for static forceinline artificial
#       define uasm_S_FINLINEART(T) static inline T __attribute__((always_inline))

// inline hallways on for inline only
#       define uasm_INLINE(T)  inline T __attribute__((always_inline))
// inline hallways on for inline only artificial
#       define uasm_INLINEART(T) inline T __attribute__((always_inline))

// forceinline hallways on for forceinline only
#       define uasm_FINLINE(T) inline T __attribute__((always_inline))
// forceinline hallways on for forceinline only artificial
#       define uasm_FINLINEART(T) inline T __attribute__((always_inline))

// inline hallways on for static inline with veccall
#       define uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))
// inline hallways on for static inline artificial with veccall
#       define uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))

// forceinline hallways on for static forceinline with veccall
#       define uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))
// forceinline hallways on for static forceinline artificial with veccall
#       define uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T) __attribute__((always_inline))

// inline hallways on for inline only with veccall
#       define uasm_INLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
// inline hallways on for inline only artificial with veccall
#       define uasm_INLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))

// forceinline hallways on for forceinline only with veccall
#       define uasm_FINLINE_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
// forceinline hallways on for forceinline only artificial with veccall
#       define uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T) __attribute__((always_inline))
#   endif // uasm_INLINE
#  endif // uasm_GNUC
#else
//uasm_PRAGMA(inline_depth(255))
#   ifndef uasm_INLINE
#     ifndef uasm_DEBUG
// inline on in release build for static inline
#       define __uasm_S_INLINE(T) static  inline T
// inline on in release build for static inline
#       define _uasm_S_INLINE(T) static  inline T

// inline on in release build for static inline artificial
#       define __uasm_S_INLINEART(T) static  inline T
// inline on in release build for static inline artificial
#       define _uasm_S_INLINEART(T) static  inline T

// forceinline on in release build for static forceinline
#       define __uasm_S_FINLINE(T) static inline T
// forceinline on in release build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static inline T

// inline on in release build for inline only
#       define __uasm_INLINE(T) inline T
// inline on in release build for inline only
#       define _uasm_INLINE(T) inline T

// inline on in release build for inline only artificial
#       define __uasm_INLINEART(T) inline T
// inline on in release build for inline only artificial
#       define _uasm_INLINEART(T) inline T

// forceinline on in release build for forceinline only
#       define __uasm_FINLINE(T) inline T
// forceinline on in release build for forceinline only artificial
#       define __uasm_FINLINEART(T) inline T

// inline on in release build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T)
// inline on in release build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T)

// inline on in release build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T)
// inline on in release build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T)

// forceinline on in release build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T)
// forceinline on in release build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T)

// inline on in release build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) inline uasm_veccall(T)
// inline on in release build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) inline uasm_veccall(T)

// inline on in release build for static inline artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) inline uasm_veccall(T)
// inline on in release build for static inline artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) inline uasm_veccall(T)

// forceinline on in release build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) inline uasm_veccall(T)
// forceinline on in release build for forceinline artificial only with veccall
#       define __uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T)
#     else
// inline of in debug build for static inline
#       define __uasm_S_INLINE(T) static T
// inline of in debug build for static inline
#       define _uasm_S_INLINE(T) static T

// inline of in debug build for static inline artificial
#       define __uasm_S_INLINEART(T) static T
// inline of in debug build for static inline artificial
#       define _uasm_S_INLINEART(T) static T

// forceinline of in debug build for static forceinline
#       define __uasm_S_FINLINE(T) static T
// forceinline of in debug build for static forceinline artificial
#       define __uasm_S_FINLINEART(T) static T

// inline of in debug build for inline only
#       define __uasm_INLINE(T) T
// inline of in debug build for inline only
#       define _uasm_INLINE(T) T

// inline of in debug build for inline only artificial
#       define __uasm_INLINEART(T) T
// inline of in debug build for inline only artificial
#       define _uasm_INLINEART(T) T

// forceinline of in debug build for forceinline only
#       define __uasm_FINLINE(T) T
// forceinline of in debug build for forceinline only artificial
#       define __uasm_FINLINEART(T) T

// inline of in debug build for static inline with veccall
#       define __uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline with veccall
#       define _uasm_S_INLINE_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for static inline artificial with veccall
#       define __uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)
// inline of in debug build for static inline artificial with veccall
#       define _uasm_S_INLINEART_VECCALL(T) static uasm_veccall(T)

// forceinline of in debug build for static forceinline with veccall
#       define __uasm_S_FINLINE_VECCALL(T) static uasm_veccall(T)
// forceinline of in debug build for static forceinline artificial with veccall
#       define __uasm_S_FINLINEART_VECCALL(T) static uasm_veccall(T)

// inline of in debug build for inline only with veccall
#       define __uasm_INLINE_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only with veccall
#       define _uasm_INLINE_VECCALL(T) uasm_veccall(T)

// inline of in debug build for inline only artificial with veccall
#       define __uasm_INLINEART_VECCALL(T) uasm_veccall(T)
// inline of in debug build for inline only artificial with veccall
#       define _uasm_INLINEART_VECCALL(T) uasm_veccall(T)

// forceinline of in debug build for forceinline only with veccall
#       define __uasm_FINLINE_VECCALL(T) uasm_veccall(T)
// forceinline of in debug build for forceinline only artificial with veccall
#       define __uasm_FINLINEART_VECCALL(T) uasm_veccall(T)
#     endif // uasm_DEBUG

// inline hallways on for static inline
#       define uasm_S_INLINE(T)  static inline T
// inline hallways on for static inline artificial
#       define uasm_S_INLINEART(T) static inline T

// forceinline hallways on for static forceinline
#       define uasm_S_FINLINE(T) static inline T
// forceinline hallways on for static forceinline artificial
#       define uasm_S_FINLINEART(T) static inline T

// inline hallways on for inline only
#       define uasm_INLINE(T)  inline T
// inline hallways on for inline only artificial
#       define uasm_INLINEART(T) inline T

// forceinline hallways on for forceinline only
#       define uasm_FINLINE(T) inline T
// forceinline hallways on for forceinline only artificial
#       define uasm_FINLINEART(T) inline T

// inline hallways on for static inline with veccall
#       define uasm_S_INLINE_VECCALL(T) static inline uasm_veccall(T)
// inline hallways on for static inline artificial with veccall
#       define uasm_S_INLINEART_VECCALL(T) static inline uasm_veccall(T)

// forceinline hallways on for static forceinline with veccall
#       define uasm_S_FINLINE_VECCALL(T) static inline uasm_veccall(T)
// forceinline hallways on for static forceinline artificial with veccall
#       define uasm_S_FINLINEART_VECCALL(T) static inline uasm_veccall(T)

// inline hallways on for inline only with veccall
#       define uasm_INLINE_VECCALL(T) inline uasm_veccall(T)
// inline hallways on for inline only artificial with veccall
#       define uasm_INLINEART_VECCALL(T) inline uasm_veccall(T)

// forceinline hallways on for forceinline only with veccall
#       define uasm_FINLINE_VECCALL(T) inline uasm_veccall(T)
// forceinline hallways on for forceinline only artificial with veccall
#       define uasm_FINLINEART_VECCALL(T) inline uasm_veccall(T)
#   endif // uasm_INLINE
# endif

/**
Nullptr macro
*/
# if (defined(__cplusplus) && (__cplusplus >= 201103L)) || defined(_MSC_VER)
#   if defined(_MSC_VER) && (_MSC_VER >= 1800)
#       define uasm_NULLPTR nullptr
#   else
#       define uasm_NULLPTR NULL
#   endif
#elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#  if defined(uasm_GNUC) || defined(uasm_CLANGU)
#       define uasm_NULLPTR __null
#  elif defined(__cplusplus)
#       define uasm_NULLPTR 0
#  else
#       define uasm_NULLPTR ((void*)0)
#  endif
#else
#       define uasm_NULLPTR
#endif

#ifdef uasm_CUDACC
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
#if defined(uasm_CUDACC)
#   define uasm_NOINLINE __noinline__
#elif defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_NOINLINE __declspec(noinline)
#elif defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_IBMC)
#   define uasm_NOINLINE __attribute__((noinline))
#else
#   define uasm_NOINLINE
#endif

/**
Constexpr macro
*/
#if defined(uasm_CONSTEXPR_SUPPORT)
#   define uasm_constexpr constexpr
#   define uasm_const constexpr
#else
#   define uasm_constexpr
#   define uasm_const const
#endif

/**
Empty function class body macro
*/
#if defined(uasm_DEFAULT_CTOR_SUPPORT)
#   define uasm_default =default
#else
#   define uasm_default
#endif

/**
No exception function class body macro
*/
#if defined(uasm_NOEXCEPT_SUPPORT)
#   define uasm_noexcept noexcept
#else
#   define uasm_noexcept
#endif

/*! restrict macro */
#if defined(uasm_CUDACC)
# if defined(uasm_MSVC_COMPATIBLE_COMPILER) && (_MSC_VER >= 1400))
#   define __uasm_RESTRICT __declspec(restrict)
# elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#   define __uasm_RESTRICT __attribute__((restrict))
# else
#   define __uasm_RESTRICT
# endif
#   define uasm_RESTRICT __restrict__
#elif (defined(uasm_MSVC_COMPATIBLE_COMPILER) && (_MSC_VER >= 1400))
#   define __uasm_RESTRICT __declspec(restrict)
#   define uasm_RESTRICT __restrict
#elif (defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_IBMC)) && !defined(uasm_PS4) // ps4 doesn't like restricted functions
#   define __uasm_RESTRICT __attribute__((restrict))
#   define uasm_RESTRICT __restrict__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#   define uasm_RESTRICT restrict
#else
#   define __uasm_RESTRICT
#   define uasm_RESTRICT
#endif

/* noalias macro */
#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_NOALIAS __declspec(noalias)
#elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#   define uasm_NOALIAS __attribute__((noalias))
#else
#   define uasm_NOALIAS
#endif

/* property macro */
#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define __uasm_PROPERTY(exa,exb) __declspec(property(exa, exb))
#else
#   define __uasm_PROPERTY(exa,exb) __attribute__((property(exa, exb)))
#endif

/* notrow macro */
#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#ifdef  __cplusplus
#ifndef uasm_NOTHROW
# define uasm_NOTHROW __declspec(nothrow)
#endif
#else
#ifndef uasm_NOTHROW
# define uasm_NOTHROW
#endif
#endif
#else
#ifndef uasm_NOTHROW
# define uasm_NOTHROW
#endif
#endif

/* noreturn macro */
#if defined(uasm_CUDACC)
#   define uasm_NORETURN __attribute__((noreturn))
#elif defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_NORETURN __declspec(noreturn)
#elif defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_IBMC)
#   define uasm_NORETURN __attribute__((noreturn))
#else
#   define uasm_NORETURN
#endif

#   define uasm_COUNT_OF(x) (sizeof(x) / sizeof(x[0]))

/* alignof macro */
#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_ALIGN_OF(X) __alignof(X)
#elif defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_IBMC)
#   define uasm_ALIGN_OF(X) __alignof__(X)
#elif defined(uasm_MWERKS)
#   define uasm_ALIGN_OF(X) __builtin_align(X)
#elif defined(uasm_ARMCC)
#   define uasm_ALIGN_OF(X) __ALIGNOF__(X)
#else
#   define uasm_ALIGN_OF(x)
#endif

#if defined(uasm_GCC_COMPATIBLE_COMPILER)
#   define uasm_LIKELY(x) (__builtin_expect(!!(x), 1))
#   define uasm_UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else
#   define uasm_LIKELY(x) (!!(x))
#   define uasm_UNLIKELY(x) (!!(x))
#endif

/* override and final macro */
#if defined(uasm_MSVC_COMPATIBLE_COMPILER) && defined(__cplusplus)
#   if (_MSC_VER >= 1700)
#       define uasm_OVERRIDE override
#       define uasm_FINAL final
#       define uasm_FINAL_OVERRIDE final override
#   elif (_MSC_VER >= 1600)
#       define uasm_OVERRIDE override
#       define uasm_FINAL sealed
#       define uasm_FINAL_OVERRIDE sealed override
#endif
#endif

/* intrin_type macro and vector size*/
# if defined(uasm_MSVC_COMPATIBLE_COMPILER) && (_MSC_VER >= 1400)
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

#       define uasm_VEC_SIZE_INTRINTYPE(Type,Name,size) __declspec(align(size)) Type Name[size]
#       define uasm_VEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) __declspec(align(size)) Type Name[size]

#       define uasm_NEONVEC_SIZE_INTRINTYPE(Type,Name,size) __declspec(align(size)) Type Name[size]
#       define uasm_NEONVEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) __declspec(align(size)) Type Name[size]

#       define uasm_VEC_SIZE(Type,Name,size) __declspec(align(size)) Type Name[size]
#       define uasm_VEC_SIZE_ALIAS(Type,Name,size) __declspec(align(size)) Type Name[size]

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
# elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#       define uXGC_VEC_INTRINTYPE(X) __attribute__((__vector_size__(4), __aligned__(X)))
#       define uXGC_VEC_INTRINTYPE_ALIAS(X) __attribute__((__vector_size__(4), __aligned__(X), __may_alias__))

#       define uasm_VEC_SIZE_INTRINTYPE(Type,Name,size) Type Name __attribute__((__vector_size__(size), __aligned__(X)))
#       define uasm_VEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name __attribute__((__vector_size__(size), __aligned__(X), __may_alias__))

#       define uasm_NEONVEC_SIZE_INTRINTYPE(Type,Name,size) Type Name __attribute__((neon_vector_type(size), __aligned__(X)))
#       define uasm_NEONVEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name __attribute__((neon_vector_type(size), __aligned__(X), __may_alias__))

#       define uasm_VEC_SIZE(Type,Name,size) Type Name[size] __attribute__((__aligned__(size)))
#       define uasm_VEC_SIZE_ALIAS(Type,Name,size) Type Name[size] __attribute__((__aligned__(size), __may_alias__))

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

#       define uasm_VEC_SIZE_INTRINTYPE(Type,Name,size) Type Name[size]
#       define uasm_VEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name[size]

#       define uasm_NEONVEC_SIZE_INTRINTYPE(Type,Name,size) Type Name[size]
#       define uasm_NEONVEC_SIZE_INTRINTYPE_ALIAS(Type,Name,size) Type Name[size]

#       define uasm_VEC_SIZE(Type,Name,size) Type Name[size]
#       define uasm_VEC_SIZE_ALIAS(Type,Name,size) Type Name[size]

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
// typedef uasm_VEC_SIZE_INTRINTYPE(int, __v8si, 32); // = to VC: typedef __declspec(align(32)) int __v8si[32], or GNUC: typedef int __v8si __attribute__((__vector_size__(32)))

/* virtual macro */
#if !defined(uasm_NO_VIRTUAL) && defined(__cplusplus)
#   define uasm_virtual virtual
#   define uasm_virtualinit = 0
#else
#   define uasm_virtual
#   define uasm_virtualinit
#endif

/* explicit macro */
#if !defined(uasm_NO_EXPLICIT) && defined(__cplusplus)
#   define uasm_explicit explicit
#else
#   define uasm_explicit
#endif

#if defined(uasm_INTELCC_GFX)
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

#if defined(uasm_CUDACC)
#   define __Cuda_host__                __host__
#   define __Cuda_device__              __device__
#   define __Cuda_device_builtin__      __device_builtin__
#else
#   define __Cuda_host__
#   define __Cuda_device__
#   define __Cuda_device_builtin__
#endif

#if defined(uasm_CUDACC)
#   define uasm_TARGET_CPU_GPU                        __Cuda_host__ __Cuda_device__
#   define uasm_TARGET_CPU_ONLY                       __Cuda_host__
#   define uasm_TARGET_GPU_ONLY                       __Cuda_device__
#   define uasm_TARGET_DEVICE_BUILTIN             __Cuda_device_builtin__
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN        __Cuda_device__ __Cuda_device_builtin__
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN         __Cuda_host__ __Cuda_device__ __Cuda_device_builtin__
#elif defined(uasm_INTELCC_GFX)
#   define uasm_TARGET_CPU_GPU                        __Intel_host__ __Intel_device__
#   define uasm_TARGET_CPU_ONLY                       __Intel_host__
#   define uasm_TARGET_GPU_ONLY                       __Intel_device__
#   define uasm_TARGET_DEVICE_BUILTIN             __Intel_device_builtin__
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN        __Intel_device__ __Intel_device_builtin__
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN         __Intel_host__ __Intel_device__ __Intel_device_builtin__
#else
#   define uasm_TARGET_CPU_GPU
#   define uasm_TARGET_CPU_ONLY
#   define uasm_TARGET_GPU_ONLY
#   define uasm_TARGET_DEVICE_BUILTIN
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN
#endif

#if defined(uasm_CC_PDEF_GPU_SUPPORT)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_INLINE(T) uasm_S_INLINE(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_FINLINE(T) uasm_S_FINLINE(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_INLINE(T) uasm_INLINE(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_FINLINE(T) uasm_FINLINE(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)

#   define uasm_TARGET_GPU_ONLY_S_INLINE(T) uasm_S_INLINE(uasm_TARGET_GPU_ONLY T)
#   define uasm_TARGET_GPU_ONLY_S_FINLINE(T) uasm_S_FINLINE(uasm_TARGET_GPU_ONLY T)
#   define uasm_TARGET_GPU_ONLY_INLINE(T) uasm_INLINE(uasm_TARGET_GPU_ONLY T)
#   define uasm_TARGET_GPU_ONLY_FINLINE(T) uasm_FINLINE(uasm_TARGET_GPU_ONLY T)

#   define uasm_TARGET_CPU_ONLY_S_INLINE(T) uasm_S_INLINE(uasm_TARGET_CPU_ONLY T)
#   define uasm_TARGET_CPU_ONLY_S_FINLINE(T) uasm_S_FINLINE(uasm_TARGET_CPU_ONLY T)
#   define uasm_TARGET_CPU_ONLY_INLINE(T) uasm_INLINE(uasm_TARGET_CPU_ONLY T)
#   define uasm_TARGET_CPU_ONLY_FINLINE(T) uasm_FINLINE(uasm_TARGET_CPU_ONLY T)

#   define uasm_TARGET_CPU_ONLY_S_INLINE_VECCALL(T) uasm_S_INLINE(uasm_TARGET_CPU_ONLY T)
#   define uasm_TARGET_CPU_ONLY_S_FINLINE_VECCALL(T) uasm_S_FINLINE(uasm_TARGET_CPU_ONLY T)
#   define uasm_TARGET_CPU_ONLY_INLINE_VECCALL(T) uasm_INLINE(uasm_TARGET_CPU_ONLY T)
#   define uasm_TARGET_CPU_ONLY_FINLINE_VECCALL(T) uasm_FINLINE(uasm_TARGET_CPU_ONLY T)

#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE(T) uasm_S_INLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE(T) uasm_S_FINLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE(T) uasm_INLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_FINLINE(T) uasm_FINLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)

#   define uasm_TARGET_CPU_GPU_S_INLINE(T) uasm_S_INLINE(uasm_TARGET_CPU_GPU T)
#   define uasm_TARGET_CPU_GPU_S_FINLINE(T) uasm_S_FINLINE(uasm_TARGET_CPU_GPU T)
#   define uasm_TARGET_CPU_GPU_INLINE(T) uasm_INLINE(uasm_TARGET_CPU_GPU T)
#   define uasm_TARGET_CPU_GPU_FINLINE(T) uasm_FINLINE(uasm_TARGET_CPU_GPU T)

#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE_VECCALL(T) uasm_S_INLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE_VECCALL(T) uasm_S_FINLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE_VECCALL(T) uasm_INLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)
#   define uasm_TARGET_CPU_GP_DEVICE_BUILTINU_FINLINE_VECCALL(T) uasm_FINLINE(uasm_TARGET_CPU_GPU_DEVICE_BUILTIN T)

#   define uasm_TARGET_CPU_GPU_S_INLINE_VECCALL(T) uasm_S_INLINE(uasm_TARGET_CPU_GPU T)
#   define uasm_TARGET_CPU_GPU_S_FINLINE_VECCALL(T) uasm_S_FINLINE(uasm_TARGET_CPU_GPU T)
#   define uasm_TARGET_CPU_GPU_INLINE_VECCALL(T) uasm_INLINE(uasm_TARGET_CPU_GPU T)
#   define uasm_TARGET_CPU_GPU_FINLINE_VECCALL(T) uasm_FINLINE(uasm_TARGET_CPU_GPU T)
#else
# if defined(uasm_INTRINSICS_SUPPORT)

#   define uasm_TARGET_CPU_ONLY_S_INLINE_VECCALL(T) uasm_S_INLINE_VECCALL(T)
#   define uasm_TARGET_CPU_ONLY_S_FINLINE_VECCALL(T) uasm_S_FINLINE_VECCALL(T)
#   define uasm_TARGET_CPU_ONLY_INLINE_VECCALL(T) uasm_INLINE_VECCALL(T)
#   define uasm_TARGET_CPU_ONLY_FINLINE_VECCALL(T) uasm_FINLINE_VECCALL(T)

#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE_VECCALL(T) uasm_S_INLINE_VECCALL(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE_VECCALL(T) uasm_S_FINLINE_VECCALL(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE_VECCALL(T) uasm_INLINE_VECCALL(T)
#   define uasm_TARGET_CPU_GP_DEVICE_BUILTINU_FINLINE_VECCALL(T) uasm_FINLINE_VECCALL(T)

#   define uasm_TARGET_CPU_GPU_S_INLINE_VECCALL(T) uasm_S_INLINE_VECCALL(T)
#   define uasm_TARGET_CPU_GPU_S_FINLINE_VECCALL(T) uasm_S_FINLINE_VECCALL(T)
#   define uasm_TARGET_CPU_GPU_INLINE_VECCALL(T) uasm_INLINE_VECCALL(T)
#   define uasm_TARGET_CPU_GPU_FINLINE_VECCALL(T) uasm_FINLINE_VECCALL(T)
# else

#   define uasm_TARGET_CPU_ONLY_S_INLINE_VECCALL(T) uasm_S_INLINE(T)
#   define uasm_TARGET_CPU_ONLY_S_FINLINE_VECCALL(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_CPU_ONLY_INLINE_VECCALL(T) uasm_INLINE(T)
#   define uasm_TARGET_CPU_ONLY_FINLINE_VECCALL(T) uasm_FINLINE(T)

#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE_VECCALL(T) uasm_S_INLINE(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE_VECCALL(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE_VECCALL(T) uasm_INLINE(T)
#   define uasm_TARGET_CPU_GP_DEVICE_BUILTINU_FINLINE_VECCALL(T) uasm_FINLINE(T)

#   define uasm_TARGET_CPU_GPU_S_INLINE_VECCALL(T) uasm_S_INLINE(T)
#   define uasm_TARGET_CPU_GPU_S_FINLINE_VECCALL(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_CPU_GPU_INLINE_VECCALL(T) uasm_INLINE(T)
#   define uasm_TARGET_CPU_GPU_FINLINE_VECCALL(T) uasm_FINLINE(T)
# endif

#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_INLINE(T) uasm_S_INLINE(T)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_S_FINLINE(T) uasm_S_FINLINE( T)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_INLINE(T) uasm_INLINE(T)
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_FINLINE(T) uasm_FINLINE(T)

#   define uasm_TARGET_GPU_ONLY_S_INLINE(T) uasm_S_INLINE(T)
#   define uasm_TARGET_GPU_ONLY_S_FINLINE(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_GPU_ONLY_INLINE(T) uasm_INLINE(T)
#   define uasm_TARGET_GPU_ONLY_FINLINE(T) uasm_FINLINE(T)

#   define uasm_TARGET_CPU_ONLY_S_INLINE(T) uasm_S_INLINE(T)
#   define uasm_TARGET_CPU_ONLY_S_FINLINE(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_CPU_ONLY_INLINE(T) uasm_INLINE(T)
#   define uasm_TARGET_CPU_ONLY_FINLINE(T) uasm_FINLINE(T)

#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_INLINE(T) uasm_S_INLINE(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_S_FINLINE(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_INLINE(T) uasm_INLINE(T)
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_FINLINE(T) uasm_FINLINE(T)

#   define uasm_TARGET_CPU_GPU_S_INLINE(T) uasm_S_INLINE(T)
#   define uasm_TARGET_CPU_GPU_S_FINLINE(T) uasm_S_FINLINE(T)
#   define uasm_TARGET_CPU_GPU_INLINE(T) uasm_INLINE(T)
#   define uasm_TARGET_CPU_GPU_FINLINE(T) uasm_FINLINE(T)
#endif

#if defined(uasm_AMP_SUPPORT)
//#include <amp.h>
#   define uasm_CPU_AMP       restrict(amp,cpu)
#   define uasm_AMP_ONLY      restrict(amp)
#   define uasm_AMP           restrict(amp)
#   define uasm_CPU_ONLY      restrict(cpu)
#   define uasm_CPU
#else
#   define uasm_CPU_AMP
#   define uasm_AMP_ONLY
#   define uasm_AMP
#   define uasm_CPU_ONLY
#   define uasm_CPU
#endif // uasm_AMP_SUPPORT

#if defined(uasm_AMP_SUPPORT)
#   define uasm_EXTERN_BEGIN EXTERN_CC_BEGIN
#   define uasm_EXTERN_END EXTERN_CC_END
#else
#   define uasm_EXTERN_BEGIN EXTERN_C_BEGIN
#   define uasm_EXTERN_END EXTERN_C_END
#endif

#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#  if defined( uasm_LIB_DLL)
# ifndef uasm_GLOBAL_CONST
#   define uasm_GLOBAL_CONST _EXTERN const __declspec(selectany)
#   define uasm_CGLOBAL_CONST _EXTERNC const __declspec(selectany)
#   define uasm_CGLOBAL _EXTERNC __declspec(selectany)
#   define uasm_CCGLOBAL_CONST _EXTERNCC const __declspec(selectany)
#   define uasm_CCGLOBAL _EXTERNCC __declspec(selectany)
#   define uasm_AMP_GLOBAL_CONST _EXTERN const __declspec(selectany)
#   define uasm_AMP_CCGLOBAL_CONST _EXTERNCC const __declspec(selectany)
#   define uasm_AMP_CCGLOBAL _EXTERNCC __declspec(selectany)
#   define uasm_STATIC_CONST static const
#   define uasm_C_STATIC_CONST _EXTERNC static const
#   define uasm_CC_STATIC_CONST _EXTERNCC static const
// static inline
#   define uasm_CGLOBAL_API(T) _EXTERNC uasm_S_INLINE(T)
// inline only
#   define __uasm_CGLOBAL_API(T) _EXTERNC __uasm_INLINE(T)
// static inline
#   define uasm_CCGLOBAL_API(T) _EXTERNCC uasm_S_INLINE(T)
// inline only
#   define __uasm_CCGLOBAL_API(T) _EXTERNCC __uasm_INLINE(T)

// static inline
#   define uasm_CGLOBAL_CALLCONV_API(T) _EXTERNC uasm_S_INLINE(uasm_callconv(T))
// inline only
#   define __uasm_CGLOBAL_CALLCONV_API(T) _EXTERNC __uasm_INLINE(uasm_callconv(T))
// static inline
#   define uasm_CCGLOBAL_CALLCONV_API(T) _EXTERNCC uasm_S_INLINE(uasm_callconv(T))
// inline only
#   define __uasm_CCGLOBAL_CALLCONV_API(T) _EXTERNCC __uasm_INLINE(uasm_callconv(T))

// static inline
#   define uasm_CGLOBAL_VECCALL_API(T) _EXTERNC uasm_S_INLINE(uasm_veccall(T))
// inline only
#   define __uasm_CGLOBAL_VECCALL_API(T) _EXTERNC __uasm_INLINE(uasm_veccall(T))
// static inline
#   define uasm_CCGLOBAL_VECCALL_API(T) _EXTERNCC uasm_S_INLINE(uasm_veccall(T))
// inline only
#   define __uasm_CCGLOBAL_VECCALL_API(T) _EXTERNCC __uasm_INLINE(uasm_veccall(T))
# endif
# elif defined(uasm_LIB_STATIC)
# ifndef uasm_GLOBAL_CONST
#   define uasm_GLOBAL_CONST _EXTERN const
#   define uasm_CGLOBAL_CONST _EXTERNC const
#   define uasm_CGLOBAL _EXTERNC
#   define uasm_CCGLOBAL_CONST _EXTERNCC const
#   define uasm_CCGLOBAL _EXTERNCC
#   define uasm_AMP_GLOBAL_CONST _EXTERN const
#   define uasm_AMP_CCGLOBAL_CONST _EXTERNCC const
#   define uasm_AMP_CCGLOBAL _EXTERNCC
#   define uasm_STATIC_CONST static const
#   define uasm_C_STATIC_CONST _EXTERNC static const
#   define uasm_CC_STATIC_CONST _EXTERNCC static const
// static inline
#   define uasm_CGLOBAL_API(T) _EXTERNC uasm_S_INLINE(T)
// inline only
#   define __uasm_CGLOBAL_API(T) _EXTERNC __uasm_INLINE(T)
// static inline
#   define uasm_CCGLOBAL_API(T) _EXTERNCC uasm_S_INLINE(T)
// inline only
#   define __uasm_CCGLOBAL_API(T) _EXTERNCC __uasm_INLINE(T)

// static inline
#   define uasm_CGLOBAL_CALLCONV_API(T) _EXTERNC uasm_S_INLINE(uasm_callconv(T))
// inline only
#   define __uasm_CGLOBAL_CALLCONV_API(T) _EXTERNC __uasm_INLINE(uasm_callconv(T))
// static inline
#   define uasm_CCGLOBAL_CALLCONV_API(T) _EXTERNCC uasm_S_INLINE(uasm_callconv(T))
// inline only
#   define __uasm_CCGLOBAL_CALLCONV_API(T) _EXTERNCC __uasm_INLINE(uasm_callconv(T))

// static inline
#   define uasm_CGLOBAL_VECCALL_API(T) _EXTERNC uasm_S_INLINE(uasm_veccall(T))
// inline only
#   define __uasm_CGLOBAL_VECCALL_API(T) _EXTERNC __uasm_INLINE(uasm_veccall(T))
// static inline
#   define uasm_CCGLOBAL_VECCALL_API(T) _EXTERNCC uasm_S_INLINE(uasm_veccall(T))
// inline only
#   define __uasm_CCGLOBAL_VECCALL_API(T) _EXTERNCC __uasm_INLINE(uasm_veccall(T))
# endif
# endif
#else
# ifndef uasm_GLOBAL_CONST
#   define uasm_GLOBAL_CONST _EXTERN const
#   define uasm_CGLOBAL_CONST _EXTERNC const
#   define uasm_CGLOBAL _EXTERNC
#   define uasm_CCGLOBAL_CONST _EXTERNCC const
#   define uasm_CCGLOBAL _EXTERNCC
#   define uasm_AMP_GLOBAL_CONST _EXTERN const
#   define uasm_AMP_CCGLOBAL_CONST _EXTERNCC const
#   define uasm_AMP_CCGLOBAL _EXTERNCC
#   define uasm_STATIC_CONST static const
#   define uasm_C_STATIC_CONST _EXTERNC static const
#   define uasm_CC_STATIC_CONST _EXTERNCC static const
// static inline
#   define uasm_CGLOBAL_API(T) _EXTERNC uasm_S_INLINE(T)
// inline only
#   define __uasm_CGLOBAL_API(T) _EXTERNC __uasm_INLINE(T)
// static inline
#   define uasm_CCGLOBAL_API(T) _EXTERNCC uasm_S_INLINE(T)
// inline only
#   define __uasm_CCGLOBAL_API(T) _EXTERNCC __uasm_INLINE(T)

// static inline
#   define uasm_CGLOBAL_CALLCONV_API(T) _EXTERNC uasm_S_INLINE(uasm_callconv(T))
// inline only
#   define __uasm_CGLOBAL_CALLCONV_API(T) _EXTERNC __uasm_INLINE(uasm_callconv(T))
// static inline
#   define uasm_CCGLOBAL_CALLCONV_API(T) _EXTERNCC uasm_S_INLINE(uasm_callconv(T))
// inline only
#   define __uasm_CCGLOBAL_CALLCONV_API(T) _EXTERNCC __uasm_INLINE(uasm_callconv(T))

// static inline
#   define uasm_CGLOBAL_VECCALL_API(T) _EXTERNC uasm_S_INLINE(uasm_veccall(T))
// inline only
#   define __uasm_CGLOBAL_VECCALL_API(T) _EXTERNC __uasm_INLINE(uasm_veccall(T))
// static inline
#   define uasm_CCGLOBAL_VECCALL_API(T) _EXTERNCC uasm_S_INLINE(uasm_veccall(T))
// inline only
#   define __uasm_CCGLOBAL_VECCALL_API(T) _EXTERNCC __uasm_INLINE(uasm_veccall(T))
# endif
#endif

#if defined(uasm_AMP_SUPPORT)
#   define uasm_NMGLOBAL_CONST  uasm_AMP_GLOBAL_CONST
#else
#   define uasm_NMGLOBAL_CONST  uasm_GLOBAL_CONST
#endif

#  if defined(uasm_CC_PDEF_GPU_SUPPORT)
// static inline
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) uasm_CGLOBAL_API(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) __uasm_CGLOBAL_API(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)
// static inline
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) uasm_CCGLOBAL_API(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(uasm_TARGET_GPU_ONLY uasm_TARGET_DEVICE_BUILTIN T)

// static inline
#   define uasm_TARGET_GPU_ONLY_CGLOBALAPI(T) uasm_CGLOBAL_API(uasm_TARGET_GPU_ONLY T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_CGLOBALAPI(T) __uasm_CGLOBAL_API(uasm_TARGET_GPU_ONLY T)
// static inline
#   define uasm_TARGET_GPU_ONLY_CCGLOBALAPI(T) uasm_CCGLOBAL_API(uasm_TARGET_GPU_ONLY T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(uasm_TARGET_GPU_ONLY T)

// static inline
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) uasm_CGLOBAL_API(uasm_TARGET_CPU_GPU uasm_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) __uasm_CGLOBAL_API(uasm_TARGET_CPU_GPU uasm_TARGET_DEVICE_BUILTIN T)
// static inline
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) uasm_CCGLOBAL_API(uasm_TARGET_CPU_GPU uasm_TARGET_DEVICE_BUILTIN T)
// inline only
#   define __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(uasm_TARGET_CPU_GPU uasm_TARGET_DEVICE_BUILTIN T)

// static inline
#   define uasm_TARGET_CPU_GPU_CGLOBALAPI(T) uasm_CGLOBAL_API(uasm_TARGET_CPU_GPU T)
// inline only
#   define __uasm_TARGET_CPU_GPU_CGLOBALAPI(T) __uasm_CGLOBAL_API(uasm_TARGET_CPU_GPU T)
// static inline
#   define uasm_TARGET_CPU_GPU_CCGLOBALAPI(T) uasm_CCGLOBAL_API(uasm_TARGET_CPU_GPU T)
// inline only
#   define __uasm_TARGET_CPU_GPU_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(uasm_TARGET_CPU_GPU T)

// static inline
#   define uasm_TARGET_CPU_ONLY_CGLOBALAPI(T) uasm_CGLOBAL_API(uasm_TARGET_CPU_ONLY T)
// inline only
#   define __uasm_TARGET_CPU_ONLY_CGLOBALAPI(T) __uasm_CGLOBAL_API(uasm_TARGET_CPU_ONLY T)
// static inline
#   define uasm_TARGET_CPU_ONLY_CCGLOBALAPI(T) uasm_CCGLOBAL_API(uasm_TARGET_CPU_ONLY T)
// inline only
#   define __uasm_TARGET_CPU_ONLY_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(uasm_TARGET_CPU_ONLY T)
#  else

// static inline
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) uasm_CGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T) __uasm_CGLOBAL_API(T)
// static inline
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) uasm_CCGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(T)

// static inline
#   define uasm_TARGET_GPU_ONLY_CGLOBALAPI(T) uasm_CGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_CGLOBALAPI(T) __uasm_CGLOBAL_API(T)
// static inline
#   define uasm_TARGET_GPU_ONLY_CCGLOBALAPI(T) uasm_CCGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(T)

// static inline
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) uasm_CGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T) __uasm_CGLOBAL_API(T)
// static inline
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) uasm_CCGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(T)

// static inline
#   define uasm_TARGET_CPU_GPU_CGLOBALAPI(T) uasm_CGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_CGLOBALAPI(T) __uasm_CGLOBAL_API(T)
// static inline
#   define uasm_TARGET_CPU_GPU_CCGLOBALAPI(T) uasm_CCGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(T)

// static inline
#   define uasm_TARGET_CPU_ONLY_CGLOBALAPI(T) uasm_CGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_CPU_ONLY_CGLOBALAPI(T) __uasm_CGLOBAL_API(T)
// static inline
#   define uasm_TARGET_CPU_ONLY_CCGLOBALAPI(T) uasm_CCGLOBAL_API(T)
// inline only
#   define __uasm_TARGET_CPU_ONLY_CCGLOBALAPI(T) __uasm_CCGLOBAL_API(T)
#  endif

# if defined(uasm_AMP_SUPPORT)
// static inline
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CCGLOBALAPI(T)
// static inline
#   define uasm_TARGET_GPU_ONLY_NMGLOBALAPI(T) uasm_TARGET_GPU_ONLY_CCGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_GPU_ONLY_CCGLOBALAPI(T)
// static inline
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CCGLOBALAPI(T)
// static inline
#   define uasm_TARGET_CPU_GPU_NMGLOBALAPI(T) uasm_TARGET_CPU_GPU_CCGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_NMGLOBALAPI(T) __uasm_TARGET_CPU_GPU_CCGLOBALAPI(T)
// static inline
#   define uasm_TARGET_CPU_ONLY_NMGLOBALAPI(T) uasm_TARGET_CPU_ONLY_CCGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_CPU_ONLY_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_CPU_ONLY_CCGLOBALAPI(T)
# else
// static inline
#   define uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_GPU_ONLY_DEVICE_BUILTIN_CGLOBALAPI(T)
// static inline
#   define uasm_TARGET_GPU_ONLY_NMGLOBALAPI(T) uasm_TARGET_GPU_ONLY_CGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_GPU_ONLY_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_GPU_ONLY_CGLOBALAPI(T)
// static inline
#   define uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_NMGLOBALAPI(T) __uasm_TARGET_CPU_GPU_DEVICE_BUILTIN_CGLOBALAPI(T)
// static inline
#   define uasm_TARGET_CPU_GPU_NMGLOBALAPI(T) uasm_TARGET_CPU_GPU_CGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_CPU_GPU_NMGLOBALAPI(T) __uasm_TARGET_CPU_GPU_CGLOBALAPI(T)
// static inline
#   define uasm_TARGET_CPU_ONLY_NMGLOBALAPI(T) uasm_TARGET_CPU_ONLY_CGLOBALAPI(T)
// inline only
#   define __uasm_TARGET_CPU_ONLY_NMGLOBALAPI(T) __uasm_TARGET_CPU_ONLY_CGLOBALAPI(T)
# endif

/**
Alignment macros

uasm_ALIGNPREFIX and uasm_ALIGNSUFFIX can be used for type alignment instead of aligning individual variables as follows:
uasm_ALIGNPREFIX(16)
struct A {
...
} uasm_ALIGNSUFFIX(16);
This declaration style is parsed correctly by Visual Assist.
*/

#if defined(uasm_MSVC_COMPATIBLE_COMPILER) && !defined(uasm_NO_ALIGN)

#       define uasm_DECLALIGN(alignment, decl) __declspec(align(alignment)) decl
#       define uasm_ALIGNPREFIX(alignment) __declspec(align(alignment))
#       define uasm_ALIGNSUFFIX(alignment)

#       define uasm_ALIGNDECL(decl, alignment) __declspec(align(alignment)) decl
#       define uasm_ALIGN1DECL(decl) __declspec(align(1)) decl
#       define uasm_ALIGN2DECL(decl) __declspec(align(2)) decl
#       define uasm_ALIGN3DECL(decl) __declspec(align(3)) decl
#       define uasm_ALIGN4DECL(decl) __declspec(align(4)) decl
#       define uasm_ALIGN6DECL(decl) __declspec(align(6)) decl
#       define uasm_ALIGN8DECL(decl) __declspec(align(8)) decl
#       define uasm_ALIGN9DECL(decl) __declspec(align(9)) decl
#       define uasm_ALIGN12DECL(decl) __declspec(align(12)) decl
#       define uasm_ALIGN16DECL(decl) __declspec(align(16)) decl
#       define uasm_ALIGN18DECL(decl) __declspec(align(18)) decl
#       define uasm_ALIGN24DECL(decl) __declspec(align(24)) decl
#       define uasm_ALIGN32DECL(decl) __declspec(align(32)) decl
#       define uasm_ALIGN36DECL(decl) __declspec(align(36)) decl
#       define uasm_ALIGN48DECL(decl) __declspec(align(48)) decl
#       define uasm_ALIGN64DECL(decl) __declspec(align(64)) decl
#       define uasm_ALIGN72DECL(decl) __declspec(align(72)) decl
#       define uasm_ALIGN96DECL(decl) __declspec(align(96)) decl
#       define uasm_ALIGN128DECL(decl) __declspec(align(128)) decl
#       define uasm_ALIGN256DECL(decl) __declspec(align(256)) decl
#       define uasm_ALIGN512DECL(decl) __declspec(align(512)) decl

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

#       define uasm_PREFIXALIGN(alignment) uasm_ALIGNPREFIX(alignment)
#       define uasm_SUFFIXALIGN(alignment) uasm_ALIGNSUFFIX(alignment)

#       define uasm_DECL_ALIGN(alignment, decl) uasm_DECLALIGN(alignment, decl)
#       define uasm_ALIGN_DECL(decl, alignment) uasm_ALIGNDECL(decl, alignment)

#elif defined(uasm_GNUC_TYPE_ALIGNMENT) && !defined(uasm_NO_ALIGN)
#       define uasm_DECLALIGN(alignment, decl) decl __attribute__((aligned(alignment)))
#       define uasm_ALIGNPREFIX(alignment)
#       define uasm_ALIGNSUFFIX(alignment) __attribute__((aligned(alignment)))

#       define uasm_ALIGNDECL(decl, alignment) decl  __attribute__((aligned(alignment)))
#       define uasm_ALIGN1DECL(decl) decl __attribute__((aligned(1)))
#       define uasm_ALIGN2DECL(decl) decl __attribute__((aligned(2)))
#       define uasm_ALIGN3DECL(decl) decl __attribute__((aligned(3)))
#       define uasm_ALIGN4DECL(decl) decl __attribute__((aligned(4)))
#       define uasm_ALIGN6DECL(decl) decl __attribute__((aligned(6)))
#       define uasm_ALIGN8DECL(decl) decl __attribute__((aligned(8)))
#       define uasm_ALIGN9DECL(decl) decl __attribute__((aligned(9)))
#       define uasm_ALIGN12DECL(decl) decl __attribute__((aligned(12)))
#       define uasm_ALIGN16DECL(decl) decl __attribute__((aligned(16)))
#       define uasm_ALIGN18DECL(decl) decl __attribute__((aligned(18)))
#       define uasm_ALIGN24DECL(decl) decl __attribute__((aligned(24)))
#       define uasm_ALIGN32DECL(decl) decl __attribute__((aligned(32)))
#       define uasm_ALIGN36DECL(decl) decl __attribute__((aligned(36)))
#       define uasm_ALIGN48DECL(decl) decl __attribute__((aligned(48)))
#       define uasm_ALIGN64DECL(decl) decl __attribute__((aligned(64)))
#       define uasm_ALIGN72DECL(decl) decl __attribute__((aligned(72)))
#       define uasm_ALIGN96DECL(decl) decl __attribute__((aligned(96)))
#       define uasm_ALIGN128DECL(decl) decl __attribute__((aligned(128)))
#       define uasm_ALIGN256DECL(decl) decl __attribute__((aligned(256)))
#       define uasm_ALIGN512DECL(decl) decl __attribute__((aligned(512)))

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

#       define uasm_PREFIXALIGN(alignment) uasm_ALIGNPREFIX(alignment)
#       define uasm_SUFFIXALIGN(alignment) uasm_ALIGNSUFFIX(alignment)

#       define uasm_DECL_ALIGN(alignment, decl) uasm_DECLALIGN(alignment, decl)
#       define uasm_ALIGN_DECL(decl, alignment) uasm_ALIGNDECL(decl, alignment)

#elif defined(uasm_NO_ALIGN)
#       define uasm_DECLALIGN(alignment, decl)
#       define uasm_ALIGNPREFIX(alignment)
#       define uasm_ALIGNSUFFIX(alignment)

#       define uasm_ALIGNDECL(decl, alignment)
#       define uasm_ALIGN1DECL(decl)
#       define uasm_ALIGN2DECL(decl)
#       define uasm_ALIGN3DECL(decl)
#       define uasm_ALIGN4DECL(decl)
#       define uasm_ALIGN6DECL(decl)
#       define uasm_ALIGN8DECL(decl)
#       define uasm_ALIGN9DECL(decl)
#       define uasm_ALIGN12DECL(decl)
#       define uasm_ALIGN16DECL(decl)
#       define uasm_ALIGN18DECL(decl)
#       define uasm_ALIGN24DECL(decl)
#       define uasm_ALIGN32DECL(decl)
#       define uasm_ALIGN36DECL(decl)
#       define uasm_ALIGN48DECL(decl)
#       define uasm_ALIGN64DECL(decl)
#       define uasm_ALIGN72DECL(decl)
#       define uasm_ALIGN96DECL(decl)
#       define uasm_ALIGN128DECL(decl)
#       define uasm_ALIGN256DECL(decl)
#       define uasm_ALIGN512DECL(decl)

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

#       define uasm_PREFIXALIGN(alignment) uasm_ALIGNPREFIX(alignment)
#       define uasm_SUFFIXALIGN(alignment) uasm_ALIGNSUFFIX(alignment)

#       define uasm_DECL_ALIGN(alignment, decl) uasm_DECLALIGN(alignment, decl)
#       define uasm_ALIGN_DECL(decl, alignment) uasm_ALIGNDECL(decl, alignment)

#else
#       define uasm_DECLALIGN(alignment, decl)
#       define uasm_ALIGNPREFIX(alignment)
#       define uasm_ALIGNSUFFIX(alignment)

#       define uasm_ALIGNDECL(decl, alignment)
#       define uasm_ALIGN1DECL(decl)
#       define uasm_ALIGN2DECL(decl)
#       define uasm_ALIGN3DECL(decl)
#       define uasm_ALIGN4DECL(decl)
#       define uasm_ALIGN6DECL(decl)
#       define uasm_ALIGN8DECL(decl)
#       define uasm_ALIGN9DECL(decl)
#       define uasm_ALIGN12DECL(decl)
#       define uasm_ALIGN16DECL(decl)
#       define uasm_ALIGN18DECL(decl)
#       define uasm_ALIGN24DECL(decl)
#       define uasm_ALIGN32DECL(decl)
#       define uasm_ALIGN36DECL(decl)
#       define uasm_ALIGN48DECL(decl)
#       define uasm_ALIGN64DECL(decl)
#       define uasm_ALIGN72DECL(decl)
#       define uasm_ALIGN96DECL(decl)
#       define uasm_ALIGN128DECL(decl)
#       define uasm_ALIGN256DECL(decl)
#       define uasm_ALIGN512DECL(decl)

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

#       define uasm_PREFIXALIGN(alignment) uasm_ALIGNPREFIX(alignment)
#       define uasm_SUFFIXALIGN(alignment) uasm_ALIGNSUFFIX(alignment)

#       define uasm_DECL_ALIGN(alignment, decl) uasm_DECLALIGN(alignment, decl)
#       define uasm_ALIGN_DECL(decl, alignment) uasm_ALIGNDECL(decl, alignment)

#endif

# define uasm_F64_ALGN 8
# define uasm_I64_ALGN 8
# define uasm_F32_ALGN 4
# define uasm_I32_ALGN 4
# define uasm_I16_ALGN 2
# define uasm_I8_ALGN 1

# define uasm_F64_SIZE 8
# define uasm_I64_SIZE 8
# define uasm_F32_SIZE 4
# define uasm_I32_SIZE 4
# define uasm_I16_SIZE 2
# define uasm_I8_SIZE 1

#if (defined(uasm_X86_OR_X64_CPU) || defined(uasm_XBOXONE))  && !defined(uasm_NO_ALIGN)
# if (defined(uasm_MMX_INTRINSICS) || defined(uasm_3DNOW_INTRINSICS)) && (defined(uasm_INTRINSET) && (uasm_INTRINSET >= 2) && (uasm_INTRINSET <= 9)) && \
                                                !defined(uasm_AVX256_INTRINSICS) && !defined(uasm_AVX512_INTRINSICS) && !defined(uasm_SSE_INTRINSICS)
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_8
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN8DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN8DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN8DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN8DECL(decl)
# elif defined(uasm_SSE_INTRINSICS) && (defined(uasm_INTRINSET) && (uasm_INTRINSET >= 10) && (uasm_INTRINSET <= 42)) && !defined(uasm_AVX256_INTRINSICS) && !defined(uasm_AVX512_INTRINSICS)
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_16
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN16DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN16DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN16DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN16DECL(decl)
# elif defined(uasm_AVX256_INTRINSICS) && (defined(uasm_INTRINSET) && (uasm_INTRINSET >= 50) && (uasm_INTRINSET <= 52)) && !defined(uasm_AVX512_INTRINSICS) && !defined(uasm_SSE_INTRINSICS)
#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_16
#else
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_32
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN32DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN32DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN32DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN32DECL(decl)
# elif defined(uasm_AVX512_INTRINSICS) && (defined(uasm_INTRINSET) && (uasm_INTRINSET >= 60)) && !defined(uasm_AVX256_INTRINSICS) && !defined(uasm_SSE_INTRINSICS)
#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_16
#else
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_64
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN64DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN64DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN64DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN64DECL(decl)
#else  /* building all x86/x64 intrinsics sizes, defaults to SSE compatibility size, defend your code against sizes accidentally mixing*/
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_16
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN16DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN16DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN16DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN16DECL(decl)
# endif
#elif defined(uasm_ARM) && !defined(uasm_NO_ALIGN)
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_8
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN8DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN8DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN8DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN8DECL(decl)
#elif defined(uasm_PS3) && !defined(uasm_NO_ALIGN)
#           define uasm_PACK_PUSH_ uasm_PACK_PUSH_128
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN128DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN128DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN128DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN128DECL(decl)
#elif defined(uasm_NO_ALIGN)
#           define uasm_PACK_PUSH_
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN4DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN4DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN4DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN4DECL(decl)
#else
#           define uasm_PACK_PUSH_
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

#           define uasm_ALIGN_F32DECL(decl) uasm_ALIGN4DECL(decl)
#           define uasm_ALIGN_F64DECL(decl) uasm_ALIGN4DECL(decl)
#           define uasm_ALIGN_REALDECL(decl) uasm_ALIGN4DECL(decl)
#           define uasm_ALIGNDECLN(decl) uasm_ALIGN4DECL(decl)
#endif

//////////////////////////////////////////////////////////////////////////
// Math and constants align macro

// sample use uasm_NMALIGN(valor)
#if defined(uasm_UNALIGNED_MATH_CONST_ALIGN) && !defined(uasm_NO_ALIGN_MATH_INITIALIZED_CONST)
// unaligned initialized constants
#   define uasm_NMALIGN(decl) uasm_ALIGNDECLN(decl)
#else
#   define uasm_NMALIGN(decl) decl
#endif

// aligned initialized constants
#if !defined(uasm_NO_ALIGN_MATH_INITIALIZED_CONST)

#       define uasm_NMALIGN1(decl) uasm_ALIGN1DECL(decl)
#       define uasm_NMALIGN2(decl) uasm_ALIGN2DECL(decl)
#       define uasm_NMALIGN4(decl) uasm_ALIGN4DECL(decl)
#       define uasm_NMALIGN8(decl) uasm_ALIGN8DECL(decl)
#       define uasm_NMALIGN16(decl) uasm_ALIGN16DECL(decl)
#       define uasm_NMALIGN32(decl) uasm_ALIGN32DECL(decl)
#       define uasm_NMALIGN64(decl) uasm_ALIGN64DECL(decl)

#       define uasm_NMPACK_PUSH uasm_PACK_PUSH_
#       define uasm_NMPACK_PUSH1 uasm_PACK_PUSH_1
#       define uasm_NMPACK_PUSH2 uasm_PACK_PUSH_2
#       define uasm_NMPACK_PUSH4 uasm_PACK_PUSH_4
#       define uasm_NMPACK_PUSH8 uasm_PACK_PUSH_8
#       define uasm_NMPACK_PUSH16 uasm_PACK_PUSH_16
#       define uasm_NMPACK_PUSH32 uasm_PACK_PUSH_32
#       define uasm_NMPACK_PUSH64 uasm_PACK_PUSH_64

#else
#       define uasm_NMALIGN1(decl) decl
#       define uasm_NMALIGN2(decl) decl
#       define uasm_NMALIGN4(decl) decl
#       define uasm_NMALIGN8(decl) decl
#       define uasm_NMALIGN16(decl) decl
#       define uasm_NMALIGN32(decl) decl
#       define uasm_NMALIGN64(decl) decl
#endif
//////////////////////////////////////////////////////////////////////////

#   define  uasm_4x4ARRAY_2LOOP_UNROLL4(remval, unroll1, unroll2, refval) \
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
- To deprecate a function: Place uasm_DEPRECATED at the start of the function header (leftmost word).
- To deprecate a 'typedef, a 'struct' or a 'class': Place uasm_DEPRECATED directly after the keywords ('typdef', 'struct', 'class').
*/
#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   if (defined(uasm_WINDOWS) || defined(uasm_XBOXONE) || defined(uasm_ARM)) && (_MSC_VER >= 1300) && !defined(MIDL_PASS)
#       define uasm_DEPRECATED(T) __declspec(deprecated) T
#       define uasm_DEPRECATED2(T,MSG) __declspec(deprecated(MSG)) T
#   else
#       define uasm_DEPRECATED /* nothing */
#       define uasm_DEPRECATED2(MSG) /* nothing */
#   endif
#elif defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_IBMC)
#       define uasm_DEPRECATED(T) __attribute__((deprecated)) T
#       define uasm_DEPRECATED2(T,MSG) __attribute__((deprecated)(MSG)) T
#else
#       define uasm_DEPRECATED(T) T
#       define uasm_DEPRECATED2(T,MSG) T
#endif

// VC6 no '__FUNCTION__' workaround
#if defined(uasm_VC6) && !defined(__FUNCTION__)
#   define __FUNCTION__ "Undefined"
#endif

#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_OFFSET_OF(X, Y) offsetof(X, Y)
#elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#   define uasm_OFFSET_OF(X, Y) __builtin_offsetof(X, Y)
#else
#   define uasm_OFFSET_OF(X, Y)
#endif

#define uasm_OFFSETOF_BASE 0x100 // casting the null ptr takes a special-case code path, which we don't want
#define uasm_OFFSET_OF_RT(Class, Member)                                                                                 \
    (reinterpret_cast<uXsize_t>(&reinterpret_cast<Class*>(uasm_OFFSETOF_BASE)->Member) - uXsize_t(uasm_OFFSETOF_BASE))

// use the compiler friendly but programmer ugly version for release only
#ifdef uasm_DEBUG
#   define uasm_MULTILINE_MACRO_BEGIN do {
#   define uasm_MULTILINE_MACRO_END       } while(0)
#else
#       define uasm_MULTILINE_MACRO_BEGIN if(1) {
#       define uasm_MULTILINE_MACRO_END       } else
#endif

#if  defined(uasm_CUDACC)
#       define uasm_BREAKPOINT(ID) _builtin_trap();
#elif defined(uasm_X86_OR_X64_CPU) || defined(uasm_XBOXONE)
#   if defined(uasm_VC)
#       define uasm_BREAKPOINT(ID) __debugbreak();
#   elif defined(uasm_NACL) // not allowed raise interrupts
#       define uasm_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#       define uasm_BREAKPOINT(ID) __builtin_trap();
#   else
#       define uasm_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   endif
#elif defined(uasm_XBOX360)
#   if defined(uasm_VC)
#       define uasm_BREAKPOINT(ID) __debugbreak();
#   else
#       define uasm_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   endif
#elif defined(uasm_PS3_PPU)
#       define uasm_BREAKPOINT(ID) __asm__ volatile ( "tw 31,1,1" )
#elif defined(uasm_PS3_SPU)
#       define uasm_BREAKPOINT(ID) __asm__ volatile ("ilhu $0, %0\n\tiohl $0, %1\n\tstopd $0,$0,$0" : : "i"(ID>>16), "i"(ID&0xFFFF) );
#elif defined(uasm_WIIU)
#       define uasm_BREAKPOINT(ID) OSDebug();
#elif defined(uasm_GEKKO)
#       define uasm_BREAKPOINT(ID)    uasm_MULTILINE_MACRO_BEGIN                        \
                                                                                                                                {                                               \
                                    register unsigned int uasm_ORIGINAL_MSR;      \
                                    register unsigned int uasm_NEW_MSR;           \
                                    asm volatile                                \
                                                                                                                                                {                                           \
                                        mfmsr uasm_ORIGINAL_MSR;                  /* Grab the original value of the MSR */ \
                                        ori uasm_NEW_MSR, uasm_ORIGINAL_MSR, 0x400; /* or the original MSR with 0x400 and store it */ \
                                        mtmsr uasm_NEW_MSR;                       /* Set the MSR to the new value - this will throw exception 0xD00 */ \
                                        mtmsr uasm_ORIGINAL_MSR;                  /* This puts the MSR back to its original state; required for*/\
                                                                                /* getting out of single-step mode (when the user resumes) */\
                                                                                                                                                }                                           \
                                                                                                                                }                                               \
                                uasm_MULTILINE_MACRO_END

#elif defined(uasm_ARM)
#   if defined(uasm_VC)
#       define uasm_BREAKPOINT(ID) __debugbreak();
#   elif defined(uasm_SNC)
#       define uasm_BREAKPOINT(ID) __breakpoint(0);
#   elif defined(uasm_GCC_COMPATIBLE_COMPILER)
#       define uasm_BREAKPOINT(ID) __builtin_trap();
#   else
#       define uasm_BREAKPOINT(ID) ((*((int*)0)) = ID);
#   endif
#elif defined(uasm_CTR)
#   include <nn/dbg.h>
#       define uasm_BREAKPOINT(ID) ::nn::dbg::Break(nn::dbg::BREAK_REASON_ASSERT);
#else
#       define uasm_BREAKPOINT(ID) ((*((int*)0)) = ID);
#endif

#if (defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_ARM_COMPILER)) && defined(__ELF__)
#       define uasm_USE_DISPATCH_POINTER_SECTION  __attribute__((section(".data.DispatchPointer")))
#       define uasm_USE_DISPATCH_FUNCTION_SECTION __attribute__((section(".text.DispatchFunction")))
#  if defined(uasm_ARCH_ARM)
#       define uasm_USE_DISPATCH_TABLE_SECTION __attribute__((section(".rodata.DispatchTable,\"a\",%progbits @")))
#  else
#       define uasm_USE_DISPATCH_TABLE_SECTION __attribute__((section(".rodata.DispatchTable,\"a\",@progbits #")))
#  endif
#elif (defined(uasm_GCC_COMPATIBLE_COMPILER) || defined(uasm_ARM_COMPILER)) && defined(__MACH__)
#       define uasm_USE_DISPATCH_POINTER_SECTION  __attribute__((section("__DATA,__data.DispPtr")))
#       define uasm_USE_DISPATCH_FUNCTION_SECTION __attribute__((section("__TEXT,__text.DispFun")))
#       define uasm_USE_DISPATCH_TABLE_SECTION    __attribute__((section("__DATA,__const.DispTbl")))
#elif defined(uasm_MSVC_COMPATIBLE_COMPILER)
#       define uasm_USE_DISPATCH_POINTER_SECTION __declspec(allocate(".data$DispatchPointer"))
/* __declspec(allocate(...)) works with data only. Use pragma for code. */
#       define uasm_USE_DISPATCH_FUNCTION_SECTION
#       define uasm_USE_DISPATCH_TABLE_SECTION   __declspec(allocate(".rdata$DispatchTable"))
#else
#error "Unsupported compiler or output format"
#endif

/// Note that alignment must be a power of two for this to work.
/// Note: to use this macro you must cast your pointer to a byte pointer or to an integer value.
#   define uasm_NEXT_MULTIPLE_OF(Alignment, Value)  ( ((Value) + ((Alignment)-1)) & (~((Alignment)+(Value)*0-1)) )

/// The offset of a member within a structure
#   define uasm_OFFSET_OFCLASS(Class, Member) int(reinterpret_cast<long>(&(reinterpret_cast<Class*>(16)->Member))-16)

/// A check for whether the offset of a member within a structure is as expected
#   define uasm_OFFSET_EQUALS(Class, Member, Offset) (uasm_OFFSET_OFCLASS(Class,Member)==Offset)

//
// Helper macro THRUST_JOIN (based on BOOST_JOIN):
// The following piece of macro magic joins the two
// arguments together, even when one of the arguments is
// itself a macro (see 16.3.1 in C++ standard).  The key
// is that macro expansion of macro arguments does not
// occur in THRUST_DO_JOIN2 but does in THRUST_DO_JOIN.
//
/// Join two preprocessor tokens, even when a token is itself a macro.
#   define uasm_JOIN(A,B) uasm_JOIN2(A,B)
#   define uasm_JOIN2(A,B) uasm_JOIN3(A,B)
#   define uasm_JOIN3(A,B) A##B

/// Creates an uninitialized buffer large enough for object of type TYPE to fit in while aligned to ALIGN boundary. Creates a pointer VAR to this aligned address.
#   define uasm_DECLARE_ALIGNED_LOCAL_PTR( TYPE, VAR, ALIGN  )                                        \
    const int VAR ## BufferSize = ALIGN + sizeof(TYPE);                                             \
    char VAR ## Buffer[VAR ## BufferSize];                                                          \
    TYPE* VAR = reinterpret_cast<TYPE*>(uasm_NEXT_MULTIPLE_OF(ALIGN, unsigned long(VAR ## Buffer)));  

#   define uasm_SIZE_OF(Class, Member)            sizeof(((Class*)0)->Member)

#ifdef __cplusplus
// avoid unreferenced parameter warning
// preferred solution: omit the parameter's name from the declaration
template <class T>
uasm_TARGET_CPU_GPU_INLINE(void) uasm_UNREFPAR_UNUSED(T const&) uasm_CPU_AMP {}
#   define uasm_UNUSED(_P) uasm_UNREFPAR_UNUSED(_P)
#else
#   define uasm_UNUSED(_P) (void)(_P)
#endif //__cplusplus

// An expression that should expand to nothing in non uasm_DEBUG builds.
// currently use this only for tagging the purpose of containers for memory use tracking.
#if defined(uasm_DEBUG)
#   define uasm_DEBUG_EXP(x) (x)
#   define uasm_DEBUG_EXP_C(x) x,
#else
#   define uasm_DEBUG_EXP(x)
#   define uasm_DEBUG_EXP_C(x)
#endif

#if defined(uasm_INTRIN_DEBUG)
/*
#   define uasm_INTRIN_VEC_DEBUG 1
#include <iostream>
/ * Figure out whether and how to define the output operators * /
#if defined(_IOSTREAM_) || defined(_CPP_IOSTREAM) || defined(_GLIBCXX_IOSTREAM) || defined(_LIBCPP_IOSTREAM)
#   define uasm_INTRINVEC_OUTPUT_OPERATORS 1
#   define uasm_STDOSTREAM std::ostream
#elif defined(_INC_IOSTREAM) || defined(_IOSTREAM_H_)
#   define uasm_INTRINVEC_OUTPUT_OPERATORS 1
#   define uasm_STDOSTREAM ostream
#endif*/

#endif

#   define uasm_SIGN_BITMASK      0x80000000

// Macro for avoiding default assignment and copy
// because NoCopy inheritance can increase class size on some platforms.
#   define uasm_NOCOPY(Class) \
    Class(const Class &); \
    Class &operator=(const Class &);

// use in a cpp file to suppress LNK4221
#if defined(uasm_MSVC_COMPATIBLE_COMPILER)
#   define uasm_DUMMY_SYMBOL namespace { char uXDummySymbol; }
#else
#   define uasm_DUMMY_SYMBOL
#endif

#if defined(uasm_GCC_COMPATIBLE_COMPILER)
#   define uasm_WEAK_SYMBOL __attribute__((weak)) // this is to support SIMD constant merging in template specialization
#else
#   define uasm_WEAK_SYMBOL
#endif

#ifndef uasm_USE_DOUBLE_PRECISION

# if defined(uasm_AMP_USE_PRECISE_PRECISION)
#   define ampmath(Name) __dp_math_##Name
# elif defined(uasm_AMP_USE_FAST_PRECISION)
#   define ampmath(Name) __dp_d3d_##Name
# endif

# if defined(uasm_CUDA_SUPPORT)
// gets expanded to __nv_Name
#   define nvmath(Name)   __nv_##Name
# endif
#else

# if defined(uasm_AMP_USE_PRECISE_PRECISION)
#   define ampmath(Name) __dp_math_##Name
# elif defined(uasm_AMP_SUPPORT) && defined(uasm_AMP_USE_FAST_PRECISION)
#error : AMP concurrency fast_math don't have double precision and double precision cannot be used with fast math in all situations
# endif

# if defined(uasm_CUDA_SUPPORT)
// gets expanded to __nv_Name
#   define nvmath(Name)   __nv_##Name
# elif defined(uasm_CUDA_SUPPORT) && defined(uasm_CUDA_USE_FAST_PRECISION)
#error : CUDA fast math don't have double precision and double precision cannot be used with fast math in all situations
# endif
#endif /* uasm_USE_DOUBLE_PRECISION */

//#if defined(uasm_DIRECTXMATH_SUPPORT)
#   define namespace_DirectX namespace DirectX {
#   define namespace_DirectX_end }
//#endif

#   define namespace_uX namespace uX {
#   define namespace_uasm_end }

#   define namespace_CPU namespace CPU {
#   define namespace_CPU_end }

#   define namespace_internal namespace _internal {
#   define namespace_internal_end }

#   define namespace_uXOAMP namespace uXOAMP {
#   define namespace_uXOAMP_end }

#   define namespace_Math namespace Math {
#   define namespace_Math_end }

#if defined(uasm_AMP_SUPPORT)
#   define namespace_AMP namespace AMP {
#   define namespace_AMP_end }

#   define namespace_AMPMath namespace AMPMath {
#   define namespace_AMPMath_end }
#endif

#   define namespace_uXTemplate namespace uXTemplate {
#   define namespace_uXTemplate_end }

#   define namespace_uXTMath namespace uXTMath {
#   define namespace_uXTMath_end }

#if defined(uasm_SSE_INTRINSICS)
#   define namespace_uXSSE namespace uXSSE {
#   define namespace_uXSSE_end }
#endif

#if defined(uasm_CUDA_SUPPORT)
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

# if !defined(uasm_NO_DIRECTXMATH_SUPPORT)
/*
namespace_DirectX
namespace_DirectX_end*/
/*namespace DX = DirectX;*/
# endif

#endif // uasm_BASEDEFS_H
