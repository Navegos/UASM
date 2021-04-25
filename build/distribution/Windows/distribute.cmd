@echo off

7z a -tzip -mx=9 uasm-2.54.0_Windows_AVX.zip AVX\
7z a -tzip -mx=9 uasm-2.54.0_Windows_AVX2.zip AVX2\
7z a -tzip -mx=9 uasm-2.54.0_Windows_AVX512.zip AVX\
7z a -tzip -mx=9 uasm-2.54.0_Windows_SSE.zip SSE\
7z a -tzip -mx=9 uasm-2.54.0_Windows_SSE2.zip SSE2\

copy ".\..\..\Setup\UASM SSE 32bits Setup\UASM SSE 32bits Setup-SetupFiles\UASM SSE 32bits Setup.msi" ".\UASM 2.54.0 SSE 32bits Setup.msi" /y
copy ".\..\..\Setup\UASM SSE2 32bits Setup\UASM SSE2 32bits Setup-SetupFiles\UASM SSE2 32bits Setup.msi" ".\UASM 2.54.0 SSE2 32bits Setup.msi" /y
copy ".\..\..\Setup\UASM AVX 32bits Setup\UASM AVX 32bits Setup-SetupFiles\UASM AVX 32bits Setup.msi" ".\UASM 2.54.0 AVX 32bits Setup.msi" /y
copy ".\..\..\Setup\UASM AVX2 32bits Setup\UASM AVX2 32bits Setup-SetupFiles\UASM AVX2 32bits Setup.msi" ".\UASM 2.54.0 AVX2 32bits Setup.msi" /y
copy ".\..\..\Setup\UASM AVX512 32bits Setup\UASM AVX512 32bits Setup-SetupFiles\UASM AVX512 32bits Setup.msi" ".\UASM 2.54.0 AVX512 32bits Setup.msi" /y
copy ".\..\..\Setup\UASM AVX 64bits Setup\UASM AVX 64bits Setup-SetupFiles\UASM AVX 64bits Setup.msi" ".\UASM 2.54.0 AVX 64bits Setup.msi"
copy ".\..\..\Setup\UASM AVX2 64bits Setup\UASM AVX2 64bits Setup-SetupFiles\UASM AVX2 64bits Setup.msi" ".\UASM 2.54.0 AVX2 64bits Setup.msi" /y
copy ".\..\..\Setup\UASM AVX512 64bits Setup\UASM AVX512 64bits Setup-SetupFiles\UASM AVX512 64bits Setup.msi" ".\UASM 2.54.0 AVX512 64bits Setup.msi" /y
copy ".\..\..\Setup\UASM SSE2 64bits Setup\UASM SSE2 64bits Setup-SetupFiles\UASM SSE2 64bits Setup.msi" ".\UASM 2.54.0 SSE2 64bits Setup.msi" /y
