#!/bin/bash
# ______________________
# PUC-Minas - ICEI - CRC
# Verilog v.01 -  2023-1
# ______________________

echo PUCMG - Verilog Batch Compiler v.01
if [ $# -eq 0 ]; then
    echo
    echo "ERROR: No filename provided."
    echo
    echo Usage:
    echo
    echo ./compile.sh filename
    echo
    exit 1
fi
echo
FILESRC=$1.v
FILEEXE=$1.vvp
if [ -f "$FILESRC" ]; then
 echo Compiling 
 echo iverilog -o $1.vvp $1.v 
 iverilog -o $1.vvp $1.v
 echo
 if [ -f "$FILEEXE" ]; then
  echo Executing 
  echo vvp $1.vvp
  vvp $1.vvp
  echo
 fi
else 
  echo "File $FILESRC does not exist."
  echo
fi
