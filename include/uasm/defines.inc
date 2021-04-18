
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
; / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /
; / /                                                                               / /
; / /                Copyright 2020 (c) UASM macro assembly library                 / /
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

    IFNDEF DEFINES_INC
    DEFINES_INC EQU 1
    
    IFDEF WITHMACROLIB

    IFNDEF MACROLIB_INC
    .ERR <"DEFINES_INC must be included by MACROLIB_INC">
    ENDIF

    IF @Platform EQ 0
    IFNDEF __WIN32__
    __WIN32__ EQU 1
    ENDIF
    IFNDEF __WIN32
    __WIN32 EQU 1
    ENDIF
    IFNDEF _WIN32_
    _WIN32_ EQU 1
    ENDIF
    IFNDEF _WIN32
    _WIN32 EQU 1
    ENDIF
    IFNDEF WIN32
    WIN32 EQU 1
    ENDIF
    IFNDEF _M_IX86
    _M_IX86 EQU 1
    ENDIF
    IFNDEF __X86__
    __X86__ EQU 1
    ENDIF
    IFNDEF __X86
    __X86 EQU 1
    ENDIF
    IFNDEF _X86_
    _X86_ EQU 1
    ENDIF
    IFNDEF _X86
    _X86 EQU 1
    ENDIF
    IFNDEF X86
    X86 EQU 1
    ENDIF
    IFNDEF __X86ORX64__
    __X86ORX64__ EQU 1
    ENDIF
    IFNDEF __X86ORX64
    __X86ORX64 EQU 1
    ENDIF
    IFNDEF _X86ORX64_
    _X86ORX64_ EQU 1
    ENDIF
    IFNDEF _X86ORX64
    _X86ORX64 EQU 1
    ENDIF
    IFNDEF X86ORX64
    X86ORX64 EQU 1
    ENDIF
    IFNDEF __WINDOWS__
    __WINDOWS__ EQU 1
    ENDIF
    IFNDEF __WINDOWS
    __WINDOWS EQU 1
    ENDIF
    IFNDEF _WINDOWS_
    _WINDOWS_ EQU 1
    ENDIF
    IFNDEF _WINDOWS
    _WINDOWS EQU 1
    ENDIF
    IFNDEF WINDOWS
    WINDOWS EQU 1
    ENDIF
    IFNDEF __X32__
    __X32__ EQU 1
    ENDIF
    IFNDEF __X32
    __X32 EQU 1
    ENDIF
    IFNDEF _X32_
    _X32_ EQU 1
    ENDIF
    IFNDEF _X32
    _X32 EQU 1
    ENDIF
    IFNDEF X32
    X32 EQU 1
    ENDIF
    IFDEF __KNC__
    .ERR <"KNC not available in windows">
    ENDIF
    IFDEF __MIC__
    .ERR <"MIC not available in windows">
    ENDIF
    ENDIF ;@Platform EQ 0

    IF @Platform EQ 1
    IFNDEF __WIN64__
    __WIN64__ EQU 1
    ENDIF
    IFNDEF __WIN64
    __WIN64 EQU 1
    ENDIF
    IFNDEF _WIN64_
    _WIN64_ EQU 1
    ENDIF
    IFNDEF _WIN64
    _WIN64 EQU 1
    ENDIF
    IFNDEF WIN64
    WIN64 EQU 1
    ENDIF
    IFNDEF _M_AMD64
    _M_AMD64 EQU 1
    ENDIF
    IFNDEF _M_IA64
    _M_IA64 EQU 1
    ENDIF
    IFNDEF _AMD64_
    _AMD64_ EQU 1
    ENDIF
    IFNDEF _IA64_
    _IA64_ EQU 1
    ENDIF
    IFNDEF __X86_64__
    __X86_64__ EQU 1
    ENDIF
    IFNDEF __X86_64
    __X86_64 EQU 1
    ENDIF
    IFNDEF _X86_64_
    _X86_64_ EQU 1
    ENDIF
    IFNDEF _X86_64
    _X86_64 EQU 1
    ENDIF
    IFNDEF X86_64
    X86_64 EQU 1
    ENDIF
    IFNDEF __X86ORX64__
    __X86ORX64__ EQU 1
    ENDIF
    IFNDEF __X86ORX64
    __X86ORX64 EQU 1
    ENDIF
    IFNDEF _X86ORX64_
    _X86ORX64_ EQU 1
    ENDIF
    IFNDEF _X86ORX64
    _X86ORX64 EQU 1
    ENDIF
    IFNDEF X86ORX64
    X86ORX64 EQU 1
    ENDIF
    IFNDEF __WINDOWS__
    __WINDOWS__ EQU 1
    ENDIF
    IFNDEF __WINDOWS
    __WINDOWS EQU 1
    ENDIF
    IFNDEF _WINDOWS_
    _WINDOWS_ EQU 1
    ENDIF
    IFNDEF _WINDOWS
    _WINDOWS EQU 1
    ENDIF
    IFNDEF WINDOWS
    WINDOWS EQU 1
    ENDIF
    IFNDEF __X64__
    __X64__ EQU 1
    ENDIF
    IFNDEF __X64
    __X64 EQU 1
    ENDIF
    IFNDEF _X64_
    _X64_ EQU 1
    ENDIF
    IFNDEF _X64
    _X64 EQU 1
    ENDIF
    IFNDEF X64
    X64 EQU 1
    ENDIF
    IFDEF __KNC__
    .ERR <"KNC not available in windows">
    ENDIF
    IFDEF __MIC__
    .ERR <"MIC not available in windows">
    ENDIF
    ENDIF ;@Platform EQ 1

    IF @Platform EQ 2
    IFNDEF __I386__
    __I386__ EQU 1
    ENDIF
    IFNDEF __I386
    __I386 EQU 1
    ENDIF
    IFNDEF _I386_
    _I386_ EQU 1
    ENDIF
    IFNDEF _I386
    _I386 EQU 1
    ENDIF
    IFNDEF I386
    I386 EQU 1
    ENDIF
    IFNDEF __X86__
    __X86__ EQU 1
    ENDIF
    IFNDEF __X86
    __X86 EQU 1
    ENDIF
    IFNDEF _X86_
    _X86_ EQU 1
    ENDIF
    IFNDEF _X86
    _X86 EQU 1
    ENDIF
    IFNDEF X86
    X86 EQU 1
    ENDIF
    IFNDEF __X86ORX64__
    __X86ORX64__ EQU 1
    ENDIF
    IFNDEF __X86ORX64
    __X86ORX64 EQU 1
    ENDIF
    IFNDEF _X86ORX64_
    _X86ORX64_ EQU 1
    ENDIF
    IFNDEF _X86ORX64
    _X86ORX64 EQU 1
    ENDIF
    IFNDEF X86ORX64
    X86ORX64 EQU 1
    ENDIF
    IFNDEF __UNIX32__
    __UNIX32__ EQU 1
    ENDIF
    IFNDEF __UNIX32
    __UNIX32 EQU 1
    ENDIF
    IFNDEF _UNIX32_
    _UNIX32_ EQU 1
    ENDIF
    IFNDEF _UNIX32
    _UNIX32 EQU 1
    ENDIF
    IFNDEF UNIX32
    UNIX32 EQU 1
    ENDIF
    IFNDEF __UNIX__
    __UNIX__ EQU 1
    ENDIF
    IFNDEF __UNIX
    __UNIX EQU 1
    ENDIF
    IFNDEF _UNIX_
    _UNIX_ EQU 1
    ENDIF
    IFNDEF _UNIX
    _UNIX EQU 1
    ENDIF
    IFNDEF UNIX
    UNIX EQU 1
    ENDIF
    IFNDEF __LINUX32__
    __LINUX32__ EQU 1
    ENDIF
    IFNDEF __LINUX32
    __LINUX32 EQU 1
    ENDIF
    IFNDEF _LINUX32_
    _LINUX32_ EQU 1
    ENDIF
    IFNDEF _LINUX32
    _LINUX32 EQU 1
    ENDIF
    IFNDEF LINUX32
    LINUX32 EQU 1
    ENDIF
    IFNDEF __LINUX__
    __LINUX__ EQU 1
    ENDIF
    IFNDEF __LINUX
    __LINUX EQU 1
    ENDIF
    IFNDEF _LINUX_
    _LINUX_ EQU 1
    ENDIF
    IFNDEF _LINUX
    _LINUX EQU 1
    ENDIF
    IFNDEF LINUX
    LINUX EQU 1
    ENDIF
    IFNDEF __X32__
    __X32__ EQU 1
    ENDIF
    IFNDEF __X32
    __X32 EQU 1
    ENDIF
    IFNDEF _X32_
    _X32_ EQU 1
    ENDIF
    IFNDEF _X32
    _X32 EQU 1
    ENDIF
    IFNDEF X32
    X32 EQU 1
    ENDIF
    IFDEF __KNC__
    .ERR <"KNC not available in unix/linux 32-bits">
    ENDIF
    IFDEF __MIC__
    .ERR <"MIC not available in unix/linux 32-bits">
    ENDIF
    ENDIF ;@Platform EQ 2

    IF @Platform EQ 3
    IFNDEF _AMD64_
    _AMD64_ EQU 1
    ENDIF
    IFNDEF _IA64_
    _IA64_ EQU 1
    ENDIF
    IFNDEF __X86_64__
    __X86_64__ EQU 1
    ENDIF
    IFNDEF __X86_64
    __X86_64 EQU 1
    ENDIF
    IFNDEF _X86_64_
    _X86_64_ EQU 1
    ENDIF
    IFNDEF _X86_64
    _X86_64 EQU 1
    ENDIF
    IFNDEF X86_64
    X86_64 EQU 1
    ENDIF
    IFNDEF __X86ORX64__
    __X86ORX64__ EQU 1
    ENDIF
    IFNDEF __X86ORX64
    __X86ORX64 EQU 1
    ENDIF
    IFNDEF _X86ORX64_
    _X86ORX64_ EQU 1
    ENDIF
    IFNDEF _X86ORX64
    _X86ORX64 EQU 1
    ENDIF
    IFNDEF X86ORX64
    X86ORX64 EQU 1
    ENDIF
    IFNDEF __UNIX64__
    __UNIX64__ EQU 1
    ENDIF
    IFNDEF __UNIX64
    __UNIX64 EQU 1
    ENDIF
    IFNDEF _UNIX64_
    _UNIX64_ EQU 1
    ENDIF
    IFNDEF _UNIX64
    _UNIX64 EQU 1
    ENDIF
    IFNDEF UNIX64
    UNIX64 EQU 1
    ENDIF
    IFNDEF __UNIX__
    __UNIX__ EQU 1
    ENDIF
    IFNDEF __UNIX
    __UNIX EQU 1
    ENDIF
    IFNDEF _UNIX_
    _UNIX_ EQU 1
    ENDIF
    IFNDEF _UNIX
    _UNIX EQU 1
    ENDIF
    IFNDEF UNIX
    UNIX EQU 1
    ENDIF
    IFNDEF __LINUX64__
    __LINUX64__ EQU 1
    ENDIF
    IFNDEF __LINUX64
    __LINUX64 EQU 1
    ENDIF
    IFNDEF _LINUX64_
    _LINUX64_ EQU 1
    ENDIF
    IFNDEF _LINUX64
    _LINUX64 EQU 1
    ENDIF
    IFNDEF LINUX64
    LINUX64 EQU 1
    ENDIF
    IFNDEF __LINUX__
    __LINUX__ EQU 1
    ENDIF
    IFNDEF __LINUX
    __LINUX EQU 1
    ENDIF
    IFNDEF _LINUX_
    _LINUX_ EQU 1
    ENDIF
    IFNDEF _LINUX
    _LINUX EQU 1
    ENDIF
    IFNDEF LINUX
    LINUX EQU 1
    ENDIF
    IFNDEF __X64__
    __X64__ EQU 1
    ENDIF
    IFNDEF __X64
    __X64 EQU 1
    ENDIF
    IFNDEF _X64_
    _X64_ EQU 1
    ENDIF
    IFNDEF _X64
    _X64 EQU 1
    ENDIF
    IFNDEF X64
    X64 EQU 1
    ENDIF
    ENDIF ;@Platform EQ 3

    IF @Platform EQ 4
    IFNDEF _AMD64_
    _AMD64_ EQU 1
    ENDIF
    IFNDEF _IA64_
    _IA64_ EQU 1
    ENDIF
    IFNDEF __X86_64__
    __X86_64__ EQU 1
    ENDIF
    IFNDEF __X86_64
    __X86_64 EQU 1
    ENDIF
    IFNDEF _X86_64_
    _X86_64_ EQU 1
    ENDIF
    IFNDEF _X86_64
    _X86_64 EQU 1
    ENDIF
    IFNDEF X86_64
    X86_64 EQU 1
    ENDIF
    IFNDEF __X86ORX64__
    __X86ORX64__ EQU 1
    ENDIF
    IFNDEF __X86ORX64
    __X86ORX64 EQU 1
    ENDIF
    IFNDEF _X86ORX64_
    _X86ORX64_ EQU 1
    ENDIF
    IFNDEF _X86ORX64
    _X86ORX64 EQU 1
    ENDIF
    IFNDEF X86ORX64
    X86ORX64 EQU 1
    ENDIF
    IFNDEF __UNIX64__
    __UNIX64__ EQU 1
    ENDIF
    IFNDEF __UNIX64
    __UNIX64 EQU 1
    ENDIF
    IFNDEF _UNIX64_
    _UNIX64_ EQU 1
    ENDIF
    IFNDEF _UNIX64
    _UNIX64 EQU 1
    ENDIF
    IFNDEF UNIX64
    UNIX64 EQU 1
    ENDIF
    IFNDEF __UNIX__
    __UNIX__ EQU 1
    ENDIF
    IFNDEF __UNIX
    __UNIX EQU 1
    ENDIF
    IFNDEF _UNIX_
    _UNIX_ EQU 1
    ENDIF
    IFNDEF _UNIX
    _UNIX EQU 1
    ENDIF
    IFNDEF UNIX
    UNIX EQU 1
    ENDIF
    IFNDEF __MACH__
    __MACH__ EQU 1
    ENDIF
    IFNDEF __MACH
    __MACH EQU 1
    ENDIF
    IFNDEF _MACH_
    _MACH_ EQU 1
    ENDIF
    IFNDEF _MACH
    _MACH EQU 1
    ENDIF
    IFNDEF MACH
    MACH EQU 1
    ENDIF
    IFNDEF __MAC__
    __MAC__ EQU 1
    ENDIF
    IFNDEF __MAC
    __MAC EQU 1
    ENDIF
    IFNDEF _MAC_
    _MAC_ EQU 1
    ENDIF
    IFNDEF _MAC
    _MAC EQU 1
    ENDIF
    IFNDEF MAC
    MAC EQU 1
    ENDIF
    IFNDEF __APPLE__
    __APPLE__ EQU 1
    ENDIF
    IFNDEF __APPLE
    __APPLE EQU 1
    ENDIF
    IFNDEF _APPLE_
    _APPLE_ EQU 1
    ENDIF
    IFNDEF _APPLE
    _APPLE EQU 1
    ENDIF
    IFNDEF APPLE
    APPLE EQU 1
    ENDIF
    IFNDEF __X64__
    __X64__ EQU 1
    ENDIF
    IFNDEF __X64
    __X64 EQU 1
    ENDIF
    IFNDEF _X64_
    _X64_ EQU 1
    ENDIF
    IFNDEF _X64
    _X64 EQU 1
    ENDIF
    IFNDEF X64
    X64 EQU 1
    ENDIF
    IFDEF __KNC__
    .ERR <"KNC not available in MAC OS">
    ENDIF
    IFDEF __MIC__
    .ERR <"MIC not available in MAC OS">
    ENDIF
    ENDIF ;@Platform EQ 4
    
    IF (@Platform GT 4 OR @Platform LT 0)
    IFNDEF UNDEFINED_PLATFORM
    UNDEFINED_PLATFORM EQU 1
    ENDIF
    ENDIF ;@Platform EQ 4

    IFNDEF ARCH_SSE
    ARCH_SSE EQU 0
    ENDIF
    
    IFNDEF ARCH_AVX
    ARCH_AVX EQU 1
    ENDIF
    
    IFNDEF RET_BYTE
    RET_BYTE EQU 0
    ENDIF

    IFNDEF RET_SBYTE
    RET_SBYTE EQU 0x40
    ENDIF

    IFNDEF RET_WORD
    RET_WORD EQU 1
    ENDIF

    IFNDEF RET_SWORD
    RET_SWORD EQU 0x41
    ENDIF

    IFNDEF RET_DWORD
    RET_DWORD EQU 2
    ENDIF

    IFNDEF RET_SDWORD
    RET_SDWORD EQU 0x42
    ENDIF

    IFNDEF RET_QWORD
    RET_QWORD EQU 3
    ENDIF
    
    IFNDEF RET_SQWORD
    RET_SQWORD EQU 0x43
    ENDIF

    IFNDEF RET_PTR
    RET_PTR EQU 0xc3
    ENDIF

    IFNDEF RET_XMMWORD
    RET_XMMWORD EQU 6
    ENDIF
    IFNDEF RET_XMM
    RET_XMM EQU 6
    ENDIF

    IFNDEF RET_YMMWORD
    RET_YMMWORD EQU 7
    ENDIF
    IFNDEF RET_YMM
    RET_YMM EQU 7
    ENDIF

    IFNDEF RET_ZMMWORD
    RET_ZMMWORD EQU 8
    ENDIF
    IFNDEF RET_ZMM
    RET_ZMM EQU 8
    ENDIF
    
    IFNDEF RET_REAL4
    RET_REAL4 EQU 0x22
    ENDIF

    IFNDEF RET_REAL8
    RET_REAL8 EQU 0x23
    ENDIF

    IFNDEF RET_NONE
    RET_NONE EQU 0x100
    ENDIF
    
    IFNDEF LANG_NONE
    LANG_NONE       EQU 0
    ENDIF
    
    IFNDEF LANG_C
    LANG_C          EQU 1
    ENDIF
    
    IFNDEF LANG_SYSCALL
    LANG_SYSCALL    EQU 2
    ENDIF
    
    IFNDEF LANG_STDCALL
    LANG_STDCALL    EQU 3
    ENDIF
    
    IFNDEF LANG_PASCAL
    LANG_PASCAL     EQU 4
    ENDIF
    
    IFNDEF LANG_FORTRAN
    LANG_FORTRAN    EQU 5
    ENDIF
    
    IFNDEF LANG_BASIC
    LANG_BASIC      EQU 6
    ENDIF
    
    IFNDEF LANG_FASTCALL
    LANG_FASTCALL   EQU 7
    ENDIF
    
    IFNDEF LANG_VECTORCALL
    LANG_VECTORCALL EQU 8
    ENDIF
    
    IFNDEF LANG_SYSVCALL
    LANG_SYSVCALL   EQU 9
    ENDIF
    
    IFNDEF LANG_REGCALL
    LANG_REGCALL    EQU 10
    ENDIF
    
    IFNDEF LANG_THISCALL
    LANG_THISCALL   EQU 11
    ENDIF
    
    IFNDEF LANG_DELPHICALL
    LANG_DELPHICALL EQU 12
    ENDIF
    
    IFDEF __UNICODE__
      IFNDEF __UNICODE
      __UNICODE EQU 1
      ENDIF
      IFNDEF _UNICODE_
      _UNICODE_ EQU 1
      ENDIF
      IFNDEF _UNICODE
      _UNICODE EQU 1
      ENDIF
      IFNDEF UNICODE
      UNICODE EQU 1
      ENDIF
    ENDIF
    
    IFDEF __UNICODE
      IFNDEF __UNICODE__
      __UNICODE__ EQU 1
      ENDIF
      IFNDEF _UNICODE_
      _UNICODE_ EQU 1
      ENDIF
      IFNDEF _UNICODE
      _UNICODE EQU 1
      ENDIF
      IFNDEF UNICODE
      UNICODE EQU 1
      ENDIF
    ENDIF
    
    IFDEF _UNICODE_
      IFNDEF __UNICODE__
      __UNICODE__ EQU 1
      ENDIF
      IFNDEF __UNICODE
      __UNICODE EQU 1
      ENDIF
      IFNDEF _UNICODE
      _UNICODE EQU 1
      ENDIF
      IFNDEF UNICODE
      UNICODE EQU 1
      ENDIF
    ENDIF

    IFDEF _UNICODE
      IFNDEF __UNICODE__
      __UNICODE__ EQU 1
      ENDIF
      IFNDEF __UNICODE
      __UNICODE EQU 1
      ENDIF
      IFNDEF _UNICODE_
      _UNICODE_ EQU 1
      ENDIF
      IFNDEF UNICODE
      UNICODE EQU 1
      ENDIF
    ENDIF

    IFDEF UNICODE
      IFNDEF __UNICODE__
      __UNICODE__ EQU 1
      ENDIF
      IFNDEF __UNICODE
      __UNICODE EQU 1
      ENDIF
      IFNDEF _UNICODE_
      _UNICODE_ EQU 1
      ENDIF
      IFNDEF _UNICODE
      _UNICODE EQU 1
      ENDIF
    ENDIF

    IFDEF CASEMAPNONE

    IFDEF __WINDOWS__
    __windows__ EQU __WINDOWS__
    ENDIF
    IFDEF __WINDOWS
    __windows EQU __WINDOWS
    ENDIF
    IFDEF _WINDOWS_
    _windows_ EQU _WINDOWS_
    ENDIF
    IFDEF _WINDOWS
    _windows EQU _WINDOWS
    ENDIF
    IFDEF WINDOWS
    windows EQU WINDOWS
    ENDIF

    IFDEF __WIN32__
    __win32__ EQU __WIN32__
    ENDIF
    IFDEF __WIN32
    __win32 EQU __WIN32
    ENDIF
    IFDEF _WIN32_
    _win32_ EQU _WIN32_
    ENDIF
    IFDEF _WIN32
    _win32 EQU _WIN32
    ENDIF
    IFDEF WIN32
    win32 EQU WIN32
    ENDIF

    IFDEF _M_IX86
    _m_ix86 EQU _M_IX86
    ENDIF

    IFDEF __WIN64__
    __win64__ EQU __WIN64__
    ENDIF
    IFDEF __WIN64
    __win64 EQU __WIN64
    ENDIF
    IFDEF _WIN64_
    _win64_ EQU _WIN64_
    ENDIF
    IFDEF _WIN64
    _win64 EQU _WIN64
    ENDIF
    IFDEF WIN64
    win64 EQU WIN64
    ENDIF

    IFDEF _M_AMD64
    _m_amd64 EQU _M_AMD64
    ENDIF
    IFDEF _M_IA64
    _m_ia64 EQU 1
    ENDIF
    IFDEF _AMD64_
    _amd64_ EQU 1
    ENDIF
    IFDEF _IA64_
    _ia64_ EQU 1
    ENDIF

    IFDEF __UNIX__
    __unix__ EQU __UNIX__
    ENDIF
    IFDEF __UNIX
    __unix EQU __UNIX
    ENDIF
    IFDEF _UNIX_
    _unix_ EQU _UNIX_
    ENDIF
    IFDEF _UNIX
    _unix EQU _UNIX
    ENDIF
    IFDEF UNIX
    unix EQU UNIX
    ENDIF

    IFDEF __UNIX32__
    __unix32__ EQU __UNIX32__
    ENDIF
    IFDEF __UNIX32
    __unix32 EQU __UNIX32
    ENDIF
    IFDEF _UNIX32_
    _unix32_ EQU _UNIX32_
    ENDIF
    IFDEF _UNIX32
    _unix32 EQU _UNIX32
    ENDIF
    IFDEF UNIX32
    unix32 EQU UNIX32
    ENDIF

    IFDEF __UNIX64__
    __unix64__ EQU __UNIX64__
    ENDIF
    IFDEF __UNIX64
    __unix64 EQU __UNIX64
    ENDIF
    IFDEF _UNIX64_
    _unix64_ EQU _UNIX64_
    ENDIF
    IFDEF _UNIX64
    _unix64 EQU _UNIX64
    ENDIF
    IFDEF UNIX64
    unix64 EQU UNIX64
    ENDIF

    IFDEF __LINUX__
    __linux__ EQU __LINUX__
    ENDIF
    IFDEF __LINUX
    __linux EQU __LINUX
    ENDIF
    IFDEF _LINUX_
    _linux_ EQU _LINUX_
    ENDIF
    IFDEF _LINUX
    _linux EQU _LINUX
    ENDIF
    IFDEF LINUX
    linux EQU LINUX
    ENDIF

    IFDEF __LINUX32__
    __linux32__ EQU __LINUX32__
    ENDIF
    IFDEF __LINUX32
    __linux32 EQU __LINUX32
    ENDIF
    IFDEF _LINUX32_
    _linux32_ EQU _LINUX32_
    ENDIF
    IFDEF _LINUX32
    _linux32 EQU _LINUX32
    ENDIF
    IFDEF LINUX32
    linux32 EQU LINUX32
    ENDIF

    IFDEF __LINUX64__
    __linux64__ EQU __LINUX64__
    ENDIF
    IFDEF __LINUX64
    __linux64 EQU __LINUX64
    ENDIF
    IFDEF _LINUX64_
    _linux64_ EQU _LINUX64_
    ENDIF
    IFDEF _LINUX64
    _linux64 EQU _LINUX64
    ENDIF
    IFDEF LINUX64
    linux64 EQU LINUX64
    ENDIF
    
    IFDEF __MACH__
    __mach__ EQU __MACH__
    ENDIF
    IFDEF __MACH
    __mach EQU __MACH
    ENDIF
    IFDEF _MACH_
    _mach_ EQU _MACH_
    ENDIF
    IFDEF _MACH
    _mach EQU _MACH
    ENDIF
    IFDEF MACH
    mach EQU MACH
    ENDIF
    
    IFDEF __MAC__
    __mac__ EQU __MAC__
    ENDIF
    IFDEF __MAC
    __mac EQU __MAC
    ENDIF
    IFDEF _MAC_
    _mac_ EQU _MAC_
    ENDIF
    IFDEF _MAC
    _mac EQU _MAC
    ENDIF
    IFDEF MAC
    mac EQU MAC
    ENDIF
    
    IFDEF __APPLE__
    __apple__ EQU __APPLE__
    ENDIF
    IFDEF __APPLE
    __apple EQU __APPLE
    ENDIF
    IFDEF _APPLE_
    _apple_ EQU _APPLE_
    ENDIF
    IFDEF _APPLE
    _apple EQU _APPLE
    ENDIF
    IFDEF APPLE
    apple EQU APPLE
    ENDIF

    IFDEF __I386__
    __i386__ EQU __I386__
    ENDIF
    IFDEF __I386
    __i386 EQU __I386
    ENDIF
    IFDEF _I386_
    _i386_ EQU _I386_
    ENDIF
    IFDEF _I386
    _i386 EQU _I386
    ENDIF
    IFDEF I386
    i386 EQU I386
    ENDIF

    IFDEF __X86__
    __x86__ EQU __X86__
    ENDIF
    IFDEF __X86
    __x86 EQU __X86
    ENDIF
    IFDEF _X86_
    _x86_ EQU _X86_
    ENDIF
    IFDEF _X86
    _x86 EQU _X86
    ENDIF
    IFDEF X86
    x86 EQU X86
    ENDIF

    IFDEF __X32__
    __x32__ EQU __X32__
    ENDIF
    IFDEF __X32
    __x32 EQU __X32
    ENDIF
    IFDEF _X32_
    _x32_ EQU _X32_
    ENDIF
    IFDEF _X32
    _x32 EQU _X32
    ENDIF
    IFDEF X32
    x32 EQU X32
    ENDIF

    IFDEF __X86_64__
    __x86_64__ EQU __X86_64__
    ENDIF
    IFDEF __X86_64
    __x86_64 EQU __X86_64
    ENDIF
    IFDEF _X86_64_
    _x86_64_ EQU _X86_64_
    ENDIF
    IFDEF _X86_64
    _x86_64 EQU _X86_64
    ENDIF
    IFDEF X86_64
    x86_64 EQU X86_64
    ENDIF

    IFDEF __X64__
    __x64__ EQU __X64__
    ENDIF
    IFDEF __X64
    __x64 EQU __X64
    ENDIF
    IFDEF _X64_
    _x64_ EQU _X64_
    ENDIF
    IFDEF _X64
    _x64 EQU _X64
    ENDIF
    IFDEF X64
    x64 EQU X64
    ENDIF

    IFDEF __X86ORX64__
    __x86orx64__ EQU __X86ORX64__
    ENDIF
    IFDEF __X86ORX64
    __x86orx64 EQU __X86ORX64
    ENDIF
    IFDEF _X86ORX64_
    _x86orx64_ EQU _X86ORX64_
    ENDIF
    IFDEF _X86ORX64
    _x86orx64 EQU _X86ORX64
    ENDIF
    IFDEF X86ORX64
    x86orx64 EQU X86ORX64
    ENDIF

    IFDEF UNDEFINED_PLATFORM
    undefined_platform EQU UNDEFINED_PLATFORM
    ENDIF

    IFDEF ARCH_SSE
    arch_sse EQU ARCH_SSE
    ENDIF
    IFDEF ARCH_AVX
    arch_avx EQU ARCH_AVX
    ENDIF
    
    IFDEF RET_BYTE
    ret_byte EQU RET_BYTE
    ENDIF

    IFDEF RET_SBYTE
    ret_sbyte EQU RET_SBYTE
    ENDIF

    IFDEF RET_WORD
    ret_word EQU RET_WORD
    ENDIF

    IFDEF RET_SWORD
    ret_sword EQU RET_SWORD
    ENDIF

    IFDEF RET_DWORD
    ret_dword EQU RET_DWORD
    ENDIF

    IFDEF RET_SDWORD
    ret_sdword EQU RET_SDWORD
    ENDIF

    IFDEF RET_QWORD
    ret_qword EQU RET_QWORD
    ENDIF
    
    IFDEF RET_SQWORD
    ret_sqword EQU RET_SQWORD
    ENDIF

    IFDEF RET_PTR
    ret_ptr EQU RET_PTR
    ENDIF

    IFDEF RET_XMMWORD
    ret_xmmword EQU RET_XMMWORD
    ENDIF
    IFDEF RET_XMM
    ret_xmm EQU RET_XMM
    ENDIF

    IFDEF RET_YMMWORD
    ret_ymmword EQU RET_YMMWORD
    ENDIF
    IFDEF RET_YMM
    ret_ymm EQU RET_YMM
    ENDIF

    IFDEF RET_ZMMWORD
    ret_zmmword EQU RET_ZMMWORD
    ENDIF
    IFDEF RET_ZMM
    ret_zmm EQU RET_ZMM
    ENDIF
    
    IFDEF RET_REAL4
    ret_real4 EQU RET_REAL4
    ENDIF

    IFDEF RET_REAL8
    ret_real8 EQU RET_REAL8
    ENDIF

    IFDEF RET_NONE
    ret_none EQU RET_NONE
    ENDIF
    
    IFDEF LANG_NONE
    lang_none       EQU LANG_NONE
    ENDIF
    
    IFDEF LANG_C
    lang_c          EQU LANG_C
    ENDIF
    
    IFDEF LANG_SYSCALL
    lang_syscall    EQU LANG_SYSCALL
    ENDIF
    
    IFDEF LANG_STDCALL
    lang_stdcall    EQU LANG_STDCALL
    ENDIF
    
    IFDEF LANG_PASCAL
    lang_pascall     EQU LANG_PASCAL
    ENDIF
    
    IFDEF LANG_FORTRAN
    lang_fortran    EQU LANG_FORTRAN
    ENDIF
    
    IFDEF LANG_BASIC
    lang_basic      EQU LANG_BASIC
    ENDIF
    
    IFDEF LANG_FASTCALL
    lang_fastcall   EQU LANG_FASTCALL
    ENDIF
    
    IFDEF LANG_VECTORCALL
    lang_vectorcall EQU LANG_VECTORCALL
    ENDIF
    
    IFDEF LANG_SYSVCALL
    lang_sysvcall   EQU LANG_SYSVCALL
    ENDIF
    
    IFDEF LANG_REGCALL
    lang_regcall    EQU LANG_REGCALL
    ENDIF
    
    IFDEF LANG_THISCALL
    lang_thiscall   EQU LANG_THISCALL
    ENDIF
    
    IFDEF LANG_DELPHICALL
    lang_delphicall EQU LANG_DELPHICALL
    ENDIF

    IFDEF __UNICODE__
      __unicode__ EQU __UNICODE__
    ENDIF

    IFDEF __UNICODE
      __unicode EQU __UNICODE
    ENDIF
    
    IFDEF _UNICODE_
      _unicode_ EQU _UNICODE_
    ENDIF

    IFDEF _UNICODE
      _unicode EQU _UNICODE
    ENDIF

    IFDEF UNICODE
      unicode EQU UNICODE
    ENDIF

    ENDIF ;CASEMAPNONE

    ENDIF ;WITHMACROLIB

    ENDIF    ;DEFINES_INC
