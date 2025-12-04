@echo off
setlocal enabledelayedexpansion

set total=0
set compiled=0
set warnings=0
set errors=0

echo Checking all .cpp files for compilation...
echo.

for %%f in (*.cpp) do (
    set /a total+=1
    
    REM Try to compile
    g++ -Wall -Wextra -fsyntax-only "%%f" 2>temp_output.txt
    
    if !errorlevel! equ 0 (
        REM Compiled successfully, check for warnings
        findstr /C:"warning:" temp_output.txt >nul
        if !errorlevel! equ 0 (
            set /a warnings+=1
            echo [WARN] %%f - has warnings
        ) else (
            set /a compiled+=1
            echo [OK] %%f - clean
        )
    ) else (
        REM Compilation failed
        findstr /C:"error:" temp_output.txt >nul
        if !errorlevel! equ 0 (
            set /a errors+=1
            echo [ERROR] %%f - compilation error
            type temp_output.txt | findstr /C:"error:"
        )
    )
)

del temp_output.txt 2>nul

echo.
echo ========================================
echo Total files: !total!
echo Clean compiles: !compiled!
echo With warnings: !warnings!
echo Compilation errors: !errors!
echo ========================================

if !errors! gtr 0 (
    echo.
    echo FILES WITH ERRORS need to be fixed!
    exit /b 1
) else (
    echo.
    echo All files compile successfully!
    exit /b 0
)