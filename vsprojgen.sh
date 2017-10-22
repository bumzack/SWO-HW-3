#!/bin/bash

# visual studio code c/c++ project generator for windows and linux
# V1.1
# Winkler Martin
# 2017-12-09

# usage:
# ./vscodegen -name hello  -> create c project in folder hello, executable name = hello
# ./vscodegen -name hello -type c++ -> create c++ project in folder hello, executable name = hello

#read script parameters
while [[ $# -gt 1 ]]
do
key="$1"

case $key in
    -n|-name)
    NAME="$2"
    shift # past argument
    ;;
    -t|-type)
    TYPE="$2"
    shift # past argument
    ;;
    *)
            # unknown option
    ;;
esac
shift # past argument or value
done

# content settigns.json
settings='{
    "files.associations": {
        "iostream": "cpp",
        "vector": "cpp",
        "*.tcc": "cpp",
        "cmath": "cpp",
        "cctype": "cpp",
        "clocale": "cpp",
        "cstdint": "cpp",
        "cstdio": "cpp",
        "cstdlib": "cpp",
        "cwchar": "cpp",
        "cwctype": "cpp",
        "exception": "cpp",
        "initializer_list": "cpp",
        "iosfwd": "cpp",
        "istream": "cpp",
        "limits": "cpp",
        "new": "cpp",
        "ostream": "cpp",
        "stdexcept": "cpp",
        "streambuf": "cpp",
        "string_view": "cpp",
        "system_error": "cpp",
        "type_traits": "cpp",
        "typeinfo": "cpp",
        "utility": "cpp"

    },

    "C_Cpp.intelliSenseEngine": "Default",
	"C_Cpp.errorSquiggles": "Disabled",

    "terminal.integrated.shell.windows": "cmd.exe",
    "terminal.integrated.shellArgs.windows": ["/c", "msyssh"]
}'

# content tasks.json
tasks='{
    "version": "0.1.0",
    "showOutput": "always",
    "isShellCommand": true,
    "suppressTaskName": true,

    "command": "make",
    "windows": {
        "command": "msys-make"
    },

    "tasks": [{
            "taskName": "build",
            "args": ["all"],
            "problemMatcher": "$gcc"
        },

        {
            "taskName": "clean",
            "args": ["clean"]
        },

        {
            "taskName": "depend",
            "args": ["depend"]
        },

        {
            "taskName": "run",
            "command": "${workspaceRoot}/$PROGRAM_NAME"
        }
    ]
}'

# content launch.json
launch='{
    "version": "0.2.0",
    "configurations": [{
        "name": "(gdb) Launch",
        "type": "cppdbg",
        "request": "launch",
        "program": "${workspaceRoot}/$PROGRAM_NAME",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceRoot}",
        "environment": [],
        "externalConsole": true,
        "MIMode": "gdb",
        "miDebuggerPath": "gdb",
        "setupCommands": [{
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
        }],
        "windows": {
            "miDebuggerPath": "${env:MINGW_HOME}/bin/gdb.exe",
            "program": "${workspaceRoot}/$PROGRAM_NAME.exe"
        }
    }]
}'

# content c_cpp_properties.json
c_cpp_properties='{
    "configurations": [
        {
            "name": "Win32",
            "intelliSenseMode": "clang-x64",
            "includePath": [
                "${workspaceRoot}",
                "${MINGW_HOME}/include/c++/7.2.0",
                "${MINGW_HOME}/include/c++/7.2.0/x86_64-w64-mingw32",
                "${MINGW_HOME}/include/c++/7.2.0/backward",
                "${MINGW_HOME}/lib/gcc/x86_64-w64-mingw32/7.2.0/include",
                "${MINGW_HOME}/include",
                "${MINGW_HOME}/lib/gcc/x86_64-w64-mingw32/7.2.0/include-fixed",
                "${MINGW_HOME}/x86_64-w64-mingw32/include"
            ],
            "defines": [],
            "browse": {
                "path": [
                    "${workspaceRoot}",
                    "${MINGW_HOME}/include/c++/7.2.0",
                    "${MINGW_HOME}/include/c++/7.2.0/x86_64-w64-mingw32",
                    "${MINGW_HOME}/include/c++/7.2.0/backward",
                    "${MINGW_HOME}/lib/gcc/x86_64-w64-mingw32/7.2.0/include",
                    "${MINGW_HOME}/include",
                    "${MINGW_HOME}/lib/gcc/x86_64-w64-mingw32/7.2.0/include-fixed",
                    "${MINGW_HOME}/x86_64-w64-mingw32/include"
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            }
        },
        {
            "name": "Linux",
            "intelliSenseMode": "clang-x64",
            "includePath": [
                "${workspaceRoot}",
                "/usr/local/include/c++/7.2.0",
                "/usr/local/include/c++/7.2.0/x86_64-linux-gnu",
                "/usr/local/include/c++/7.2.0/backward",
                "/usr/local/lib/gcc/x86_64-linux-gnu/7.2.0/include",
                "/usr/local/include",
                "/usr/local/lib/gcc/x86_64-linux-gnu/7.2.0/include-fixed",
                "/usr/include/x86_64-linux-gnu",
                "/usr/include"
            ],
            "defines": [],
            "browse": {
                "path": [
                    "${workspaceRoot}",
                    "/usr/local/include/c++/7.2.0",
                    "/usr/local/include/c++/7.2.0/x86_64-linux-gnu",
                    "/usr/local/include/c++/7.2.0/backward",
                    "/usr/local/lib/gcc/x86_64-linux-gnu/7.2.0/include",
                    "/usr/local/include",
                    "/usr/local/lib/gcc/x86_64-linux-gnu/7.2.0/include-fixed",
                    "/usr/include/x86_64-linux-gnu",
                    "/usr/include"
                    ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            }
        }
    ],
    "version": 3
}'

makefile='ifeq ($(OS),Windows_NT)
  EXEEXT = .exe
else
  EXEEXT =
endif

TARGET = $PROGRAM_NAME$(EXEEXT)

# compiler settings
CC      = $CC
CCFLAGS = -g -pedantic -Wall -Wextra -ggdb

# linker/loader settings
LD      = $LD
LDFLAGS = -static  # link all libraries statically

# names of all .c and .o files
CFILES  = $(wildcard *$FILE_EXT)  # $(..) works for gmake only
OFILES  = $(CFILES:$FILE_EXT=.o)  # $(..) works for gmake only

# name of file containing all generated dependencies
DEPENDFILE = .depend

# rule how to compile .o files from .c files
%.o: %$FILE_EXT
	$(CC) $(CCFLAGS) -c $<

.PHONY: all depend clean

all: $(TARGET)

# main target: prg is the name of the executable to build
$(TARGET): $(OFILES)
	$(LD) -o $@ $(OFILES) $(LDFLAGS)

# clean up directory
clean:
	$(RM) $(TARGET) *.o core *.bak *~

# create dependencies using gcc -MM
depend:
	$(CC) $(CCFLAGS) -MM $(CFILES) > $(DEPENDFILE)

-include $(DEPENDFILE)
'

mainc='#include <stdio.h>

int main(void) {
  printf("Hello World\n");

  return 0;
}'

maincpp='#include <iostream>

int main(void) {
  std::cout << "Hello World" << std::endl;

  return 0;
}
'

#create project folder
mkdir -p $NAME/.vscode

#write settings file
echo "$settings" > $NAME/.vscode/setting.json

#write tasks file
echo "$tasks" | sed -e "s/\$PROGRAM_NAME/$NAME/g" > $NAME/.vscode/tasks.json

#write launch file
echo "$launch" | sed -e "s/\$PROGRAM_NAME/$NAME/g" > $NAME/.vscode/launch.json

#write c_cpp_properties file
echo "$c_cpp_properties"  > $NAME/.vscode/c_cpp_properties.json

#read include paths c
#(echo | gcc -Wp,-v -x c - -fsyntax-only) > incc.temp 2>&1
#CINCLUDE=$(awk -v q="\"" '/#include <...> search starts here:/{flag=1;next;}/End of search list./{flag=0}{if(flag)print ","q$0q}' < incc.temp)
#CINCLUDE=$(echo "$CINCLUDE" | sed 's/\//\//g') #fix path on windows
#CINCLUDE=$(echo "$CINCLUDE" | sed 's/ //g') #remove white spaces
#rm incc.temp

#read include paths cpp
#(echo | gcc -Wp,-v -x c++ - -fsyntax-only) > inccpp.temp 2>&1
#CPPINCLUDE=$(awk -v q="\"" '/#include <...> search starts here:/{flag=1;next}/End of search list./{flag=0}{if(flag)print ","q$0q}' < inccpp.temp)
#CPPINCLUDE=$(echo "$CPPINCLUDE" | sed 's/\//\//g') #fix path on windows
#CPPINCLUDE=$(echo "$CPPINCLUDE" | sed 's/ //g') #remove white spaces
#rm inccpp.temp

if [ "dummy$TYPE" == "dummyc++" ]
then
  echo "C++ Project"
  #write c_cpp_properties
  #echo "$c_cpp_properties"  > $NAME/.vscode/c_cpp_properties.json
  #awk -v r="$CPPINCLUDE" '{gsub(/INCLUDE_PATH/,r)}1'  $NAME/.vscode/c_cpp_properties.json > temp
  #mv temp $NAME/.vscode/c_cpp_properties.json

  #generate makefile
  CC="g++ -std=c++14"
  LD="g++"
  FILE_EXT=".cpp"
  echo "$makefile" | sed -e "s/\$PROGRAM_NAME/$NAME/g" | sed -e "s/\$CC/$CC/g" | sed -e "s/\$LD/$LD/g" | sed -e "s/\$FILE_EXT/$FILE_EXT/g" > $NAME/makefile

  #generate main.cpp
  echo "$maincpp" > $NAME/main.cpp
else
  echo "C Project"
  #write c_cpp_properties
  #echo "$c_cpp_properties"  > $NAME/.vscode/c_cpp_properties.json
  #awk -v r="$CINCLUDE" '{gsub(/INCLUDE_PATH/,r)}1'  $NAME/.vscode/c_cpp_properties.json > temp
  #mv temp $NAME/.vscode/c_cpp_properties.json


  #write makefile
  CC="gcc -std=c11"
  LD="gcc"
  FILE_EXT=".c"
  echo "$makefile" | sed -e "s/\$PROGRAM_NAME/$NAME/g" | sed -e "s/\$CC/$CC/g" | sed -e "s/\$LD/$LD/g" | sed -e "s/\$FILE_EXT/$FILE_EXT/g" > $NAME/makefile

  #generate main.c
  echo "$mainc" > $NAME/main.c
fi
