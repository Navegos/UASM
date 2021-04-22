
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

#ifndef UASM_EXPORTS_H
#define UASM_EXPORTS_H 1

#ifndef UASM_PREPROCESSOR_H
#include "preprocessor.h"
#endif  /* UASM_PREPROCESSOR_H */

#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64) || defined(_M_ARM) || defined(_XBOX_ONE) || defined(_M_PPC)

// Exclude rarely-used stuff from Windows headers
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef STRICT
#define STRICT
#endif


#if !defined(_WINDOWS_)
# pragma warning( push )
#if __INTEL_COMPILER
# pragma warning( disable: 271 310 )
#elif _MSC_VER
#pragma warning(disable : 4005)
#endif
#pragma pack(push)
#pragma pack(8)
//# include <windows.h>
#pragma pack (pop)
# pragma warning( pop )
#endif

// If app hasn't choosen, set to work with Windows 8 and beyond
#if !defined(WINAPI_FAMILY) || (WINAPI_FAMILY != WINAPI_FAMILY_PHONE_APP)
#if defined(_WIN32_WINNT) && (_WIN32_WINNT < _WIN32_WINNT_WIN8)
#undef _WIN32_WINNT
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT   _WIN32_WINNT_WIN8
#endif
#ifndef WINVER
#define WINVER         _WIN32_WINNT
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS _WIN32_WINNT
#endif
#endif

#endif /*defined(_WINDOWS)*/

#ifdef __cplusplus
# ifndef EXTERN_C_BEGIN
#   define EXTERN_C_BEGIN extern "C" {
# endif
# ifndef EXTERN_C_END
#   define EXTERN_C_END };
# endif
# ifndef EXTERN_CC_BEGIN
#   define EXTERN_CC_BEGIN extern "C++" {
# endif
# ifndef EXTERN_CC_END
#   define EXTERN_CC_END };
# endif
#else
# ifndef EXTERN_C_BEGIN
#   define EXTERN_C_BEGIN
# endif
# ifndef EXTERN_C_END
#   define EXTERN_C_END
# endif
# ifndef EXTERN_CC_BEGIN
#   define EXTERN_CC_BEGIN
# endif
# ifndef EXTERN_CC_END
#   define EXTERN_CC_END
# endif
#endif

/*

#ifdef __cplusplus
EXTERN_CC_BEGIN
#endif

#ifdef __cplusplus
EXTERN_CC_END
#endif

*/

#ifdef __cplusplus
# ifndef _EXTERNC
#   define _EXTERNC extern "C"
# endif
# ifndef _EXTERNCC
#   define _EXTERNCC extern "C++"
# endif
# ifndef _EXTERN
#   define _EXTERN extern
# endif
#else
# ifndef _EXTERNC
#   define _EXTERNC
# endif
# ifndef _EXTERNCC
#   define _EXTERNCC
# endif
# ifndef _EXTERN
#   define _EXTERN extern
# endif
#endif

#define UASM_EXTERNC  _EXTERNC
#define UASM_EXTERNCC _EXTERNCC
#define UASM_EXTERN   _EXTERN

#define UASM_EXTERNC_BEGIN    EXTERN_C_BEGIN
#define UASM_EXTERNC_END      EXTERN_C_END
#define UASM_EXTERNCC_BEGIN   EXTERN_CC_BEGIN
#define UASM_EXTERNCC_END     EXTERN_CC_END

#if defined(EXPORTS) || defined(_EXPORTS) || defined(LIB_EXPORTS)
#ifndef UASM_LIB_IMPORTS
#ifndef UASM_LIB_EXPORTS
#define UASM_LIB_EXPORTS 1
#endif
#endif
#endif

#if !defined(UASM_LIB_EXPORTS)
#ifndef UASM_LIB_IMPORTS
#define UASM_LIB_IMPORTS 1
#endif
#endif

#ifdef UASM_GCC_COMPATIBLE_COMPILER
#define _LIB  1
#define LIB_STATIC 1
#elif defined(UASM_MSVC_COMPATIBLE_COMPILER) && (!defined(_DLL) && !defined(_USRDLL) && !defined(_WINDLL) && !defined(LIB_DYNAMIC))
#define _LIB  1
#define LIB_STATIC 1
#endif

#if (defined(LIB_STATIC) || defined(_LIB))
#ifndef UASM_LIB_DLL
#ifndef UASM_LIB_STATIC
#define UASM_LIB_STATIC 1
#endif
#endif
#endif

#if (defined(_DLL) || defined(_USRDLL) || defined(_WINDLL) || defined(LIB_DYNAMIC) || defined(UASM_LIB_DLL)) && !defined(UASM_LIB_STATIC)
#ifndef UASM_LIB_STATIC
#ifndef UASM_LIB_DLL
#define UASM_LIB_DLL 1
#endif
#endif
#endif

#ifdef UASM_LIB_STATIC
#define UASM_LINK_TYPE ""
#define UASM_LINK_PREFIX ""
#define UASM_LINK_TYPE_STR "static"
#define UASM_LIB_TYPE ".exe"
#else
#define UASM_LINK_TYPE ""
#define UASM_LINK_PREFIX ""
#define UASM_LINK_TYPE_STR "dynamic"
#define UASM_LIB_TYPE ".exe"
#endif

#if !defined( UASM_LIB_DLL) && !defined( UASM_LIB_STATIC)
# error ("!!!Your uasm lib type static or dll aren't defined")
#endif

#if defined(UASM_LINUX_OS)
# if defined(UASM_LIB_STATIC)
#       define UASM_VISIBILITY_HIDDEN __attribute__((visibility ("hidden")))
#       define UASM_PRIVATE_SYMBOL __attribute__((visibility ("internal")))
#       define UASM_LOCAL_SYMBOL   __attribute__((visibility ("hidden")))
#       define UASM_EXPORT_SYMBOL  __attribute__((visibility ("hidden")))
#       define UASM_IMPORT_SYMBOL  __attribute__((visibility ("hidden")))
# else
#       define UASM_VISIBILITY_HIDDEN __attribute__((visibility ("hidden")))
#       define UASM_PRIVATE_SYMBOL __attribute__((visibility ("internal")))
#       define UASM_LOCAL_SYMBOL   __attribute__((visibility ("hidden")))
#       define UASM_EXPORT_SYMBOL  __attribute__((visibility ("default")))
#       define UASM_IMPORT_SYMBOL  __attribute__((visibility ("default")))
# endif
#elif defined(UASM_MACOSX_OS)
# if defined(UASM_LIB_STATIC)
#       define UASM_VISIBILITY_HIDDEN __attribute__((visibility ("hidden")))
#       define UASM_PRIVATE_SYMBOL __attribute__((visibility ("hidden")))
#       define UASM_LOCAL_SYMBOL   __attribute__((visibility ("hidden")))
#       define UASM_EXPORT_SYMBOL  __attribute__((visibility ("hidden")))
#       define UASM_IMPORT_SYMBOL  __attribute__((visibility ("hidden")))
# else
#       define UASM_VISIBILITY_HIDDEN __attribute__((visibility ("hidden")))
#       define UASM_PRIVATE_SYMBOL __attribute__((visibility ("hidden")))
#       define UASM_LOCAL_SYMBOL   __attribute__((visibility ("hidden")))
#       define UASM_EXPORT_SYMBOL  __attribute__((visibility ("default")))
#       define UASM_IMPORT_SYMBOL  __attribute__((visibility ("default")))
# endif
#elif defined(UASM_WINDOWS_OS)
# if defined(UASM_LIB_STATIC)
#       define UASM_VISIBILITY_HIDDEN /*empty*/
#       define UASM_PRIVATE_SYMBOL
#       define UASM_LOCAL_SYMBOL
#       define UASM_EXPORT_SYMBOL
#       define UASM_IMPORT_SYMBOL
#else
#       define UASM_VISIBILITY_HIDDEN /*empty*/
#       define UASM_PRIVATE_SYMBOL
#       define UASM_LOCAL_SYMBOL
#       define UASM_EXPORT_SYMBOL __declspec(dllexport)
#       define UASM_IMPORT_SYMBOL __declspec(dllimport)
#endif
#else
#error "Unsupported output format"
#endif

#if defined(UASM_LIB_EXPORTS)
#       define UASM_PUBLIC_SYMBOL UASM_EXPORT_SYMBOL
#elif defined (UASM_LIB_IMPORTS)
#       define UASM_PUBLIC_SYMBOL UASM_IMPORT_SYMBOL
#else
#error "Visibility symbols are not defined"
#endif

/* If building or using uasm lib as a DLL, define UASM_LIB_DLL.
* This is not mandatory, but it offers a little performance increase.
*/

/*#if defined(_WINDOWS) || defined(_WIN32) || defined(_WIN64) || defined(_M_ARM) || defined(_XBOX_ONE) || defined(_M_PPC)*/
#  if defined(UASM_MSVC_COMPATIBLE_COMPILER)
#    if defined(UASM_LIB_DLL) && !defined(UASM_LIB_STATIC)
#      if defined(UASM_LIB_EXPORTS)
#        define UASM_API UASM_EXPORT_SYMBOL
#      elif defined (UASM_LIB_IMPORTS)
#        define UASM_API UASM_IMPORT_SYMBOL
#      else
#        define UASM_API
#      endif
#    else  // UASM_LIB_LIB
#      define UASM_API
#    endif
#  else  // UASM_LIB_LIB
#      if defined(UASM_LIB_EXPORTS)
#           define UASM_API UASM_EXPORT_SYMBOL
#      elif defined (UASM_LIB_IMPORTS)
#        define UASM_API UASM_IMPORT_SYMBOL
#      else // UASM_LIB_STATIC  _LIB
#        define UASM_API
#      endif
#  endif  /* ! UASM_LIB_DLL */

/*
#else
#   define UASM_API
#endif // _WINDOWS*/



//#define DXSTDAPI                  EXTERN_C HRESULT STDAPICALLTYPE
//#define DXSTDAPI_(type)           EXTERN_C type STDAPICALLTYPE

#   define UASM_LIB_NAME /*UASM_COMPILER_STR*/ "uasm" /*UASM_LINK_TYPE_STR UASM_FAMILY_STR UASM_ARCH_STR*/ UASM_LINK_PREFIX UASM_LINK_TYPE UASM_BUILD_PREFIX UASM_BUILD_TYPE

#   define UASM_LIB_NAME_STR UASM_COMPILER_STR "uasm" UASM_LINK_TYPE_STR UASM_FAMILY_STR UASM_ARCH_STR UASM_BUILD_PREFIX UASM_BUILD_TYPE

#ifdef UASM_LIB_IMPORTS
#   //pragma comment( lib, UASM_LIB_NAME ".lib")
#endif

#endif /*UASM_EXPORTS_H*/
