@echo off
setlocal

set EXE=main.exe

gcc -Wall -Wextra main.c queue.c stack.c -o %EXE% 2>&1

if errorlevel 1 (
    echo.
    echo ERRO: Falha na compilacao
    echo.
    exit /b 1
)

%EXE%

endlocal
