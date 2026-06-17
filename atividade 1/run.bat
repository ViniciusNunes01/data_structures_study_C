@echo off
setlocal

gcc main.c geometry.c -o programa.exe -lm
if errorlevel 1 (
    echo Falha na compilacao.
    pause
    exit /b 1
)

programa.exe
pause