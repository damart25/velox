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
Copy it at `C:\Users\Administrator\source\repos\lzo-2.10`

In file `<repo>/CMake/Findlzo2.cmake`, update 
```
LZO2_LIBRARY -> C:\Users\Administrator\source\repos\lzo-2.10\lzo2.lib
LZO2_INCLUDE_DIR -> C:\Users\Administrator\source\repos\lzo-2.10\include
```

# Build Velox
Setup build environment for Minimal (not needed anymore)
```
cmake -B "_build\velox-hs" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL="ON" -DVELOX_BUILD_TESTING="ON" -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17 | Tee-object -FilePath "logs/buildenv_<date_comment>.txt"
```
Setup build environment for building `windows_support_oap_2024_02_29`
```
cmake -B "_build\velox-hs" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL=OFF -DVELOX_BUILD_TESTING=OFF -DVELOX_ENABLE_PARQUET=1 -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17  | Tee-object -FilePath "logs/buildenv_<date_comment>.txt"
```

Test build environment for building `windows_support_oap_2024_02_29`
```
cmake -B "_build\velox-hs" -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL=OFF -DVELOX_BUILD_TESTING=OFF -DVELOX_ENABLE_PARQUET=ON -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17  | Tee-object -FilePath "_build\velox-hs\logs\buildenv_ParquetON.txt"
```

Manual
```
cmake
-B "_build\velox-hs"
-DTREAT_WARNINGS_AS_ERRORS=0
-DENABLE_ALL_WARNINGS=1
-DVELOX_BUILD_MINIMAL=OFF
-DVELOX_BUILD_TESTING=OFF
-DVELOX_ENABLE_PARQUET=1
-DCMAKE_BUILD_TYPE=Release
-DMAX_LINK_JOBS=
-DMAX_HIGH_MEM_JOBS=
-T ClangCL
-DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake
-DCXX_STANDARD=17  | Tee-object -FilePath "logs/buildenv_<date_comment>.txt"
```
cmake . -DTREAT_WARNINGS_AS_ERRORS=0 -DENABLE_ALL_WARNINGS=1 -DVELOX_BUILD_MINIMAL=OFF -DVELOX_BUILD_TESTING=OFF -DVELOX_ENABLE_PARQUET=ON -DCMAKE_BUILD_TYPE=Release -DMAX_LINK_JOBS= -DMAX_HIGH_MEM_JOBS= -T ClangCL -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake -DCXX_STANDARD=17  | Tee-object -FilePath "..\logs\buildenv_veloxCopy_2024_06_07.txt"

From automation code
```
cmake -B "_build\velox-hs"
-DTREAT_WARNINGS_AS_ERRORS=0
-DENABLE_ALL_WARNINGS=1
-DVELOX_BUILD_MINIMAL=OFF
-DVELOX_BUILD_TESTING=OFF	#From $COMPILE_OPTION
-DVELOX_ENABLE_PARQUET=ON	#From $COMPILE_OPTION
-DCMAKE_BUILD_TYPE=Release	#From $COMPILE_OPTION
-T ClangCL
-DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake
-DCXX_STANDARD=17  | Tee-object -FilePath "logs/buildenv_<date_comment>.txt"
```

Move to build directory and then build it.
```
cd  _build\velox-hs
cmake --build . --config "Release" | Tee-object -FilePath logs\build_2024_04_29_Int128CheckedPlus.txt
```

(optional) If you need to clean the build in the future, do
```
cmake --build . --config "Release" --target clean | Tee-object -FilePath logs\build_<date_comment>.txt
```

# Known errors
Problem
```
C:/Users/hsukhwan/Downloads/repos/damart25_velox/_build/velox-hs/vcpkg_installed/x64-windows/include\folly/net/NetOps.h(64,8): message : previous definition is here
```
Solution - Please comment the following block.
```
/*
struct sockaddr_un {
  sa_family_t sun_family;
  char sun_path[108];
};
*/
```

# Misc Comments (ignore)
Parse build file for libs
```
Get-Content .\logs\build_2024_03_18_2.txt | Select-String '->' | Select-String '\.lib' | ForEach-Object Line | Out-File .\logs\build_2024_03_18_2_libs.txt
```
Master diff of all commits by damart25
```
https://github.com/damart25/velox/commit/8a0785d17bf05c4ccb817b79c22c34643ed52318#diff-24ab21c3a960665939e2043f811c576ba51a1bf306c843d4daccebb93ea62ea0
```