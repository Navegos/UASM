@echo off

7z a -tzip -mx=9 uasm-2.56.0_Windows.zip UASM\

copy ".\..\..\Setup\UASM.32bits.Setup\UASM.32bits.Setup-SetupFiles\UASM.32bits.Setup.msi" ".\UASM.2.56.0.32bits.Setup.msi" /y
copy ".\..\..\Setup\UASM.64bits.Setup\UASM.64bits.Setup-SetupFiles\UASM.64bits.Setup.msi" ".\UASM.2.56.0.64bits.Setup.msi" /y
