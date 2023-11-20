:: ______________________
:: PUC-Minas - ICEI - CRC
:: Verilog v.01 -  2023-1
:: ______________________

REM
REM Alterar e remover os comentarios (REM)
REM caso necessario compor o PATH adequado.
REM
REM path|find /i "C:\Icarus_Verilog_v12\bin"         >nul || set path=%path%;C:\Icarus_Verilog_v11b2\bin
REM path|find /i "C:\Icarus_Verilog_v12\gtkwave\bin" >nul || set path=%path%;C:\Icarus_Verilog_v11b2\gtkwave\bin
REM

@echo off
@echo PUCMG - Verilog Batch Compiler v.01
@echo\
if "%1"=="" goto no_file
if not exist %1.v goto no_file
@echo Compiling 
@echo iverilog -o %1.vvp %1.v 
iverilog -o %1.vvp %1.v
@echo\
if not exist %1.vvp goto end 
@echo Executing 
@echo vvp %1.vvp
@echo\
vvp %1.vvp
goto end
:no_file
   echo\
   echo PUC-Minas - ICEI - CRC
   echo Verilog v.01 -  2023-1
   echo\
   echo Usage:
   echo\
   echo compile filename
   echo\
   echo\
:end
