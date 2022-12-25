# cpp_20_module

Modules and compilers: A small experiment


MSVC 19.34.31933 (call vcvars64.bat to initialize the envinronment first):

> cl /exportHeader /headerName:angle cstdio /std:c++20

> cl /TP /interface a.cppm /headerUnit:angle cstdio=cstdio.ifc main.cpp /std:c++20 /Fe:main.exe

GCC 12.2.0:

> gcc -std=c++20 -fmodules-ts -x c++-system-header cstdio -x c++ a.cppm main.cpp -o main

Clang 15.0.6:

> clang-15 -std=c++20 -x c++-system-header cstdio --precompile -o cstdio.pcm

> clang-15 -std=c++20 -fmodule-file=cstdio.pcm -x c++-module a.cppm --precompile -o b.pcm

> clang-15 -std=c++20 main.cpp -fprebuilt-module-path=. b.pcm -o main