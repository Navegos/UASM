@echo off

7z a -tzip -mx=9 uasm-2.54.0_Linux64_AVX.zip AVX\
7z a -tzip -mx=9 uasm-2.54.0_Linux64_AVX2.zip AVX2\
7z a -tzip -mx=9 uasm-2.54.0_Linux64_AVX512.zip AVX\
7z a -tzip -mx=9 uasm-2.54.0_Linux64_SSE.zip SSE\
7z a -tzip -mx=9 uasm-2.54.0_Linux64_SSE2.zip SSE2\
