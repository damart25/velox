# Setup
## Install Ninja
https://github.com/ninja-build/ninja/releases

## Install GFlags from source
Why install from source? Need to build with BUILD_SHARED_LIBS, coz velox needs it. But unfortunatly it is harder to build that using vcpkg.

AR - In case gflags installed on 

Install Gflags from source. Do this on x64 VS command prompt.
```
git clone https://github.com/gflags/gflags
cd gflags
mkdir _build
cd _build 
cmake .. -G "NMake Makefiles" -DGFLAGS_BUILD_SHARED_LIBS="ON" -DBUILD_SHARED_LIBS="ON"
# NMake
# (admin) nmake install/local
# cmake .. -G "Ninja" -DGFLAGS_BUILD_SHARED_LIBS="ON" -DBUILD_SHARED_LIBS="ON"
# This needs to be run from an x64 VS command prompt.
cmake --build . 
#This command requires elevated.
cmake --build . --target install
```

## Install Bison and flex online:
Download bison executable from https://gnuwin32.sourceforge.net/packages/bison.htm
Download flex executable from https://gnuwin32.sourceforge.net/packages/flex.htm
Exact links
 http://downloads.sourceforge.net/gnuwin32/bison-2.4.1-setup.exe
 https://versaweb.dl.sourceforge.net/project/gnuwin32/flex/2.5.4a-1/flex-2.5.4a-1.exe
Double-click and install. Thats it. 

# Build Velox
```
cmake -B "_build\updateCPP" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL="ON" -DVELOX_BUILD_TESTING="ON" -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17
```

```
cmake --build . --config "Release" > build_2024_01_08_v1.txt
```