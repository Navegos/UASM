@echo off

7z a -tzip -mx=9 UASM_WIN_AVX.zip AVX\
7z a -tzip -mx=9 UASM_WIN_AVX2.zip AVX2\
7z a -tzip -mx=9 UASM_WIN_AVX512.zip AVX\
7z a -tzip -mx=9 UASM_WIN_SSE.zip SSE\
7z a -tzip -mx=9 UASM_WIN_SSE2.zip SSE2\

copy ".\..\..\Setup\UASM SSE 32bits Setup\UASM SSE 32bits Setup-SetupFiles\UASM SSE 32bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM SSE2 32bits Setup\UASM SSE2 32bits Setup-SetupFiles\UASM SSE2 32bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM AVX 32bits Setup\UASM AVX 32bits Setup-SetupFiles\UASM AVX 32bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM AVX2 32bits Setup\UASM AVX2 32bits Setup-SetupFiles\UASM AVX2 32bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM AVX512 32bits Setup\UASM AVX512 32bits Setup-SetupFiles\UASM AVX512 32bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM AVX 64bits Setup\UASM AVX 64bits Setup-SetupFiles\UASM AVX 64bits Setup.msi" .\
copy ".\..\..\Setup\UASM AVX2 64bits Setup\UASM AVX2 64bits Setup-SetupFiles\UASM AVX2 64bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM AVX512 64bits Setup\UASM AVX512 64bits Setup-SetupFiles\UASM AVX512 64bits Setup.msi" .\ /y
copy ".\..\..\Setup\UASM SSE2 64bits Setup\UASM SSE2 64bits Setup-SetupFiles\UASM SSE2 64bits Setup.msi" .\ /y
