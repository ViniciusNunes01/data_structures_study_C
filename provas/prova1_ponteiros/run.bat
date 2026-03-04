@echo off
REM Script principal para compilar e executar arquivos .c
REM Pode ser usado de qualquer pasta do projeto
REM Uso: run exercicio_1_1
REM      run exercicios_ponteiros/exercicio_1_1
REM      run ..\outra_pasta\arquivo

setlocal enabledelayedexpansion

if "%1"=="" (
    echo.
    echo =====================================================
    echo  Compilador e Executor de Arquivos C
    echo =====================================================
    echo.
    echo Uso:
    echo   run exercicio_1_1
    echo   run exercicios_ponteiros/exercicio_1_1
    echo   run ..\outra_pasta\meu_arquivo
    echo.
    echo Notas:
    echo   - Nao precisa digitar a extensao .c
    echo   - O executavel sera criado no mesmo diretorio
    echo   - Funciona de qualquer pasta do projeto
    echo.
    exit /b 1
)

REM Remove a extensão se o usuário digitar
set ARQUIVO=%1
set ARQUIVO=!ARQUIVO:.c=!

REM Converte / para \ para compatibilidade
set ARQUIVO=!ARQUIVO:/=\!

REM Verifica se o arquivo .c existe
if not exist "!ARQUIVO!.c" (
    echo.
    echo ERRO: Arquivo "!ARQUIVO!.c" nao encontrado!
    echo.
    exit /b 1
)

REM Obtém o diretório e nome do arquivo
for %%F in ("!ARQUIVO!.c") do (
    set DIR=%%~dpF
    set NOME=%%~nF
)

REM Remove a barra final se existir
if "!DIR:~-1!"=="\" set DIR=!DIR:~0,-1!

REM Caminho completo do executável
set EXE=!DIR!\!NOME!.exe

REM Compila o arquivo
gcc -Wall -Wextra "!ARQUIVO!.c" -o "!EXE!" 2>&1

REM Verifica se compilou com sucesso
if errorlevel 1 (
    echo.
    echo ERRO: Falha na compilacao
    echo.
    exit /b 1
)

REM Executa o arquivo
"!EXE!"

endlocal
