@echo off

del uasm.exe
del uasmd.exe
del uasmd.pdb

if "%1"=="avx512" goto AVX512
if "%1"=="AVX512" goto AVX512
if "%1"=="avx2" goto AVX2
if "%1"=="AVX2" goto AVX2
if "%1"=="avx" goto AVX
if "%1"=="AVX" goto AVX
if "%1"=="sse" goto SSE2
if "%1"=="SSE" goto SSE2
if "%1"=="sse2" goto SSE2
if "%1"=="SSE2" goto SSE2
if "%1"=="" goto SSE2

goto UNKNOWN

:AVX512
mklink /H uasm.exe uasmavx512.exe
mklink /H uasmd.exe uasmavx512d.exe
mklink /H uasmd.pdb uasmavx512d.pdb
goto DONE

:AVX2
mklink /H uasm.exe uasmavx2.exe
mklink /H uasmd.exe uasmavx2d.exe
mklink /H uasmd.pdb uasmavx2d.pdb
goto DONE

:AVX
mklink /H uasm.exe uasmavx.exe
mklink /H uasmd.exe uasmavxd.exe
mklink /H uasmd.pdb uasmavxd.pdb
goto DONE

:UNKNOWN

:SSE2
mklink /H uasm.exe uasmsse2.exe
mklink /H uasmd.exe uasmsse2d.exe
mklink /H uasmd.pdb uasmsse2d.pdb
goto DONE

:DONE
