set CPPVER=c++latest

set APP=libSkinux.dll

set OUTDIR=out
set BINDIR=bin

set LIBDIR=lib
set LIBS=SDL2main.lib SDL2.lib

set COMPOPT=/nologo /EHa /MD /MP /bigobj /W2
set LINKOPT=/nologo /DLL

set DBGCOMPOPT=/Zi
set DBGLINKOPT=/DEBUG

set RELCOMPOPT=/DNDEBUG
set RELLINKOPT=

set SOURCES=src

set src_SRC=src
set src_OBJ=skinux.cpp
set src_INC=include include/SDL

if not "%1"=="x64" if not "%1"=="x86" goto :eof

call vcvarsall.bat %1