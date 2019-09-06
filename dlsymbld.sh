#!/bin/sh -v
g++ --std=c++11 -Isetpath -fPIC -fvisibility=hidden -c setpath/setpath.cpp -o setpath/setpath.o
mkdir -p lib.so
g++ -fPIC -fvisibility=hidden -shared -Wl,-soname,libsetpath.so.1 -o lib.so/libsetpath.so.1.0.0 setpath/setpath.o
cd lib.so; ln -sf libsetpath.so.1.0.0 libsetpath.so.1; ln -sf libsetpath.so.1 libsetpath.so; cd ..
g++ --std=c++11 dlsymcall.c -o dlsymcall -ldl
echo "Test"
./dlsymcall lib.so/libsetpath.so
