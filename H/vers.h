
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

#ifndef UASM_VERSION_H
#define UASM_VERSION_H 1

#ifndef UASM_PREPROCESSOR_H
#include "preprocessor.h"
#endif  /* UASM_PREPROCESSOR_H */

#define UASM_VERSION_DATE "2021.04.21"

//#define UASM_VERSION_BUILD 20210421

#define UASM_BUILD_DATE  "2021-04-21 10:08:00 UTC"
#define UASM_BUILD_YYYY 2021
#define UASM_BUILD_MMDD 0421

#define UASM_VERSION_MAJOR 2
#define UASM_VERSION_MINOR 54
#define UASM_VERSION_PATCH 0
#define UASM_VERSION_BUILD 2021921
#define UASM_VERSION_REVISION UASM_VERSION_PATCH
#define UASM_VERSION_SUBREVISION UASM_VERSION_BUILD
#define UASM_RELEASE_NAME "Release candidate"
#define UASM_VERSION_HEX  0x5EB29A0F5
#define UASM_VERSION_INT  2540
#define UASM_VERSION 254020210921

#define UASM_VERSION_CST UASM_VERSION_MAJOR , UASM_VERSION_MINOR , UASM_BUILD_YYYY, UASM_BUILD_MMDD

#define UASM_VERSION_STR UASM_Stringer(UASM_VERSION_MAJOR) "." UASM_Stringer(UASM_VERSION_MINOR) "." UASM_Stringer(UASM_VERSION_REVISION) "." UASM_Stringer(UASM_VERSION_SUBREVISION)

#define UASM_VERSION_MAJOR_STR       UASM_Stringer(UASM_VERSION_MAJOR)
#define UASM_VERSION_MINOR_STR       UASM_Stringer(UASM_VERSION_MINOR)
#define UASM_VERSION_PATCH_STR       UASM_Stringer(UASM_VERSION_REVISION)
#define UASM_VERSION_BUILD_STR       UASM_Stringer(UASM_VERSION_SUBREVISION)

#define UASM_FULL_VERSION_STR     UASM_VERSION_MAJOR_STR "." UASM_VERSION_MINOR_STR "." UASM_VERSION_PATCH_STR "." UASM_VERSION_BUILD_STR " (" UASM_RELEASE_NAME ")"


// The constant UASM_VERSION_ALT is used when creating certain UASMOAMP module objects
// This is to ensure that the application is using the same header version as the library was built with

#define UASM_VERSION_ALT ((UASM_VERSION_MAJOR<<24) + (UASM_VERSION_MINOR<<16) + (UASM_VERSION_REVISION<<8) + UASM_VERSION_SUBREVISION<<4))

#include "exports.h"

#define UASM_FILE UASM_LIB_NAME UASM_LIB_TYPE

// Finally, define strings.
#ifdef UASM_DEBUG
#define UASM_LIBRARY   UASM_LINK_TYPE_STR " " UASM_BUILD_TYPE " console application "
#else
#define UASM_LIBRARY   UASM_LINK_TYPE_STR " console application "
#endif
#define UASM_COPYRIGHT "Copyright (C) Terraspace (R) 2021. All rights reserved. UASM a free MASM - compatible assembler."
#define UASM_COMPANY "(C) Terraspace (R) 2021. UASM a free MASM - compatible assembler."

#define UASM_VERSION_MAGIC_STR   "\x00@(#) "
#define UASM_VERSION_MAGIC_LEN   6                // Length of UASM_VERSION_MAGIC_STR.
#define UASM_VERSION_PREF_STR    "(C) Terraspace (R) UASM"
#define UASM_VERSION_PREFIX      UASM_VERSION_MAGIC_STR UASM_VERSION_PREF_STR

#define UASM_FILE_DESCRIPTION UASM_VERSION_PREF_STR " " UASM_FULL_VERSION_STR "" UASM_FAMILY_STR " " UASM_ARCH_STR " " UASM_COMPILER " " UASM_LIBRARY "of " UASM_BUILD_DATE "\0"
#define UASM_PRODUCT_NAME UASM_VERSION_PREF_STR " " UASM_FAMILY_STR " " UASM_ARCH_STR " " UASM_LIBRARY "\0"
#define UASM_COMMENTS UASM_VERSION_PREF_STR " " UASM_LIBRARY "version " UASM_FULL_VERSION_STR " for " UASM_FAMILY_STR " " UASM_ARCH_STR " " UASM_COMPILER " build on " UASM_BUILD_DATE ". " "For more information visit http://www.terraspace.co.uk/uasm.html" "\0"

#endif // UASM_VERSION_H
