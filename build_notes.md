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

```
PS C:\Users\Administrator\source\repos\gflags\_build> cmake --build . --target install
[ 50%] Built target gflags_shared
[100%] Built target gflags_nothreads_shared
Install the project...
-- Install configuration: "Debug"
-- Up-to-date: C:/Program Files (x86)/gflags/lib/gflags_debug.lib
-- Up-to-date: C:/Program Files (x86)/gflags/bin/gflags_debug.dll
-- Up-to-date: C:/Program Files (x86)/gflags/lib/gflags_nothreads_debug.lib
-- Up-to-date: C:/Program Files (x86)/gflags/bin/gflags_nothreads_debug.dll
-- Up-to-date: C:/Program Files (x86)/gflags/include/gflags/gflags.h
-- Up-to-date: C:/Program Files (x86)/gflags/include/gflags/gflags_declare.h
-- Up-to-date: C:/Program Files (x86)/gflags/include/gflags/gflags_completions.h
-- Up-to-date: C:/Program Files (x86)/gflags/include/gflags/gflags_gflags.h
-- Up-to-date: C:/Program Files (x86)/gflags/lib/cmake/gflags/gflags-config.cmake
-- Up-to-date: C:/Program Files (x86)/gflags/lib/cmake/gflags/gflags-config-version.cmake
-- Up-to-date: C:/Program Files (x86)/gflags/lib/cmake/gflags/gflags-targets.cmake
-- Up-to-date: C:/Program Files (x86)/gflags/lib/cmake/gflags/gflags-targets-debug.cmake
-- Up-to-date: C:/Program Files (x86)/gflags/lib/cmake/gflags/gflags-nonamespace-targets.cmake
-- Up-to-date: C:/Program Files (x86)/gflags/lib/cmake/gflags/gflags-nonamespace-targets-debug.cmake
-- Register:   Added HKEY_CURRENT_USER\Software\Kitware\CMake\Packages\gflags\908ba94ce6a3ee5802fcedd009bc2455
```

## Install Bison and flex online:
Download bison executable from https://gnuwin32.sourceforge.net/packages/bison.htm

Download flex executable from https://gnuwin32.sourceforge.net/packages/flex.htm 

Exact links
 http://downloads.sourceforge.net/gnuwin32/bison-2.4.1-setup.exe 
 
 https://versaweb.dl.sourceforge.net/project/gnuwin32/flex/2.5.4a-1/flex-2.5.4a-1.exe 

 
Double-click and install. Thats it. 

Add the bison and flex folder to the PATH (environment variables)

Update on 1/30
Instead of above, download this instead.
https://sourceforge.net/projects/winflexbison/

Download win_flex_bison-latest.zip and unzip it at C:\Users\Administrator\Downloads\win_flex_bison-latest 
Update that to the PATH 


## Add LZO package
Download lzo-2.10 from `\\amr.corp.intel.com\ec\proj\SSG\Benchmarks\cloud-eng\Working Directories\hsukhwan\lzo-2.10.tar.gz`
Copy it at C:\Users\Administrator\source\repos\lzo-2.10

In file `<repo>/CMake/Findlzo2.cmake`, update 
```
LZO2_LIBRARY -> C:\Users\Administrator\source\repos\lzo-2.10\lzo2.lib
LZO2_INCLUDE_DIR -> C:\Users\Administrator\source\repos\lzo-2.10\include
```

# Build Velox
```
cmake -B "_build\velox-hs" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL="ON" -DVELOX_BUILD_TESTING="ON" -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17 *> _build/velox-hs/logs/buildenv_(date).txt
```
Building `windows_support_oap_2024_02_29`
```
cmake -B "_build\velox-hs" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL=OFF -DVELOX_BUILD_TESTING=OFF -DVELOX_ENABLE_PARQUET=1 -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17 *> "logs/buildenv_20240409.txt"
```

Move to build directory and build it. 
```
cd  _build\velox-hs
cmake --build . --config "Release" > logs\build_2024_03_07_winsupport_full.txt
```

cmake -B "_build\enable_parquet" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL=OFF -DVELOX_BUILD_TESTING=OFF -DVELOX_ENABLE_PARQUET=1 -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=D:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17 | Tee-object -FilePath "build_details_gluten_2024_03_04.txt"

1. Copy .lib lines -> match with David's build
2. Create new repo -> branch to 1.1.1 -> Branch with Windows Changes -> patch all changes by Hand -> build -> eventually send pull request


C:/Users/hsukhwan/Downloads/repos/damart25_velox/_build/velox-hs/vcpkg_installed/x64-windows/include\folly/net/NetOps.h(64,8): message : previous definition is here

Please comment the following block. 
```
/*
struct sockaddr_un {
  sa_family_t sun_family;
  char sun_path[108];
};
*/
```

Rebaseline with a working version