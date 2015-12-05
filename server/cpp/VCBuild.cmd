mkdir build
cd build
cmake -G "Visual Studio 14" ..
mkdir bin
mkdir bin\Debug
copy /y ..\deps\win32\lib\*.* bin\Debug
cd ..
