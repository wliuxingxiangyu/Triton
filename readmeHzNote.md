```
https://triton.quarkslab.com/documentation/doxygen/#install_sec
Installation
To be able to compile Triton, you must install these libraries before:

lib name	version
libboost	>= 1.68
libpython	== 2.7.x or 3.6.x
libz3	>= 4.6.0
libcapstone	>= 4.0.x
Pin (optional)	== 71313


Linux Installation
Once the libraries are installed, you can use cmake and make to build libTriton.
$ git clone https://github.com/JonathanSalwan/Triton.git
$ cd Triton
$ mkdir build
$ cd build
$ cmake ..
$ sudo make -j2 install

```

```
wanghuozhu@dlserver:~/ws/other/Triton$ mkdir build
wanghuozhu@dlserver:~/ws/other/Triton$ cd build/
wanghuozhu@dlserver:~/ws/other/Triton/build$ cmake ..
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Error at /usr/share/cmake-3.5/Modules/FindPackageHandleStandardArgs.cmake:148 (message):
  Could NOT find PythonInterp: Found unsuitable version "3.5.2", but required
  is at least "3.6" (found /usr/bin/python3)
Call Stack (most recent call first):
  /usr/share/cmake-3.5/Modules/FindPackageHandleStandardArgs.cmake:386 (_FPHSA_FAILURE_MESSAGE)
  /usr/share/cmake-3.5/Modules/FindPythonInterp.cmake:163 (FIND_PACKAGE_HANDLE_STANDARD_ARGS)
  CMakeLists.txt:45 (find_package)

ans:

sudo add-apt-repository ppa:deadsnakes/ppa   
sudo apt-get update   
sudo apt install python3.7  
https://askubuntu.com/questions/1176270/couldnt-find-any-package-by-glob-python-3-7-0

pythonLib missing:
sudo apt-get install python3.7-dev
https://github.com/spillai/numpy-opencv-converter/issues/6

wanghuozhu@dlserver:~/ws/other/Triton/build$ ..cmake clean
sudo apt-get install python3.7-gdbm

sudo apt install python-z3

wanghuozhu@dlserver:~/ws/other/Triton/build$ cmake ..
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found PythonInterp: /usr/bin/python3 (found suitable version "3.7.7", minimum required is "3.6") 
-- Found PythonLibs: /usr/lib/x86_64-linux-gnu/libpython3.7m.so (found suitable version "3.7.7", minimum required is "3.6") 
-- Found Z3 include directory: /usr/include
-- Found Z3 library: /usr/lib/x86_64-linux-gnu/libz3.so
-- Found CAPSTONE include directory: /usr/include
-- Found CAPSTONE library: /usr/lib/libcapstone.so
-- Boost version: 1.58.0
-- Configuring done
-- Generating done
-- Build files have been written to: /yiyuan/data/home/wanghuozhu/ws/other/Triton/build
```



```
------------- z3-solver can not solve------
https://github.com/pypa/pip/issues/5373
sudo easy_install3 pip
pip3 install z3-solver

wanghuozhu@dlserver:~/ws/other$ pip install z3-solver
Traceback (most recent call last):
  File "/yiyuan/data/home/wanghuozhu/.local/bin/pip", line 5, in <module>
    from pip._internal.cli.main import main
ModuleNotFoundError: No module named 'pip._internal'
wanghuozhu@dlserver:~/ws/other$

change:
from pip._internal import main
to
from pip import main



wanghuozhu@dlserver:~/ws/other$ pip3 install z3-solver
Collecting z3-solver
  Using cached https://files.pythonhosted.org/packages/a3/75/3a1d4c044082baf017e08df32c39974ec34fcfa068b6a7b0cd4bfbf1ccfb/z3_solver-4.8.7.0-py2.py3-none-manylinux1_x86_64.whl
Installing collected packages: z3-solver
Successfully installed z3-solver-4.8.7.0
You are using pip version 8.1.1, however version 20.0.2 is available.
You should consider upgrading via the 'pip install --upgrade pip' command.
wanghuozhu@dlserver:~/ws/other$ 

```

```
wanghuozhu@dlserver:~/ws/other/Triton/build$ make -j8
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/arch/x86/x86Specifications.cpp:5246:16: error: ‘X86_INS_ENDBR32’ is not a member of ‘triton::extlibs::capstone’
           case triton::extlibs::capstone::X86_INS_ENDBR32:
                ^
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/arch/x86/x86Specifications.cpp:5250:16: error: ‘X86_INS_ENDBR64’ is not a member of ‘triton::extlibs::capstone’
           case triton::extlibs::capstone::X86_INS_ENDBR64:
                ^
src/libtriton/CMakeFiles/triton.dir/build.make:456: recipe for target 'src/libtriton/CMakeFiles/triton.dir/arch/x86/x86Specifications.cpp.o' failed

ans:
capstone-4.0 failed  https://github.com/JonathanSalwan/Triton/issues/459 
```

```
[ 24%] Building CXX object src/libtriton/CMakeFiles/triton.dir/bindings/python/namespaces/initArchNamespace.cpp.o
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/tritonToZ3Ast.cpp: In member function ‘triton::__uint triton::ast::TritonToZ3Ast::getUintValue(const z3::expr&)’:
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/tritonToZ3Ast.cpp:39:19: error: ‘const class z3::expr’ has no member named ‘get_numeral_uint64’
       return expr.get_numeral_uint64();
                   ^
ans:
https://github.com/Z3Prover/z3/blob/z3-4.7.1/src/api/c%2B%2B/z3%2B%2B.h#L778-L787
```

```
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/z3ToTritonAst.cpp: In member function ‘triton::ast::SharedAbstractNode triton::ast::Z3ToTritonAst::convert(const z3::expr&)’:
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/z3ToTritonAst.cpp:151:14: error: ‘Z3_OP_BSDIV_I’ was not declared in this scope
         case Z3_OP_BSDIV_I:
              ^
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/z3ToTritonAst.cpp:161:14: error: ‘Z3_OP_BUDIV_I’ was not declared in this scope
         case Z3_OP_BUDIV_I:
              ^
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/z3ToTritonAst.cpp:171:14: error: ‘Z3_OP_BSREM_I’ was not declared in this scope
         case Z3_OP_BSREM_I:
              ^
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/z3ToTritonAst.cpp:181:14: error: ‘Z3_OP_BUREM_I’ was not declared in this scope
         case Z3_OP_BUREM_I:
              ^
/yiyuan/data/home/wanghuozhu/ws/other/Triton/src/libtriton/ast/z3/z3ToTritonAst.cpp:191:14: error: ‘Z3_OP_BSMOD_I’ was not declared in this scope
         case Z3_OP_BSMOD_I:
              ^
src/libtriton/CMakeFiles/triton.dir/build.make:984: recipe for target 'src/libtriton/CMakeFiles/triton.dir/ast/z3/z3ToTritonAst.cpp.o' failed
make[2]: *** [src/libtriton/CMakeFiles/triton.dir/ast/z3/z3ToTritonAst.cpp.o] Error 1
make[2]: *** Waiting for unfinished jobs....
src/libtriton/CMakeFiles/triton.dir/build.make:960: recipe for target 'src/libtriton/CMakeFiles/triton.dir/ast/z3/tritonToZ3Ast.cpp.o' failed
make[2]: *** [src/libtriton/CMakeFiles/triton.dir/ast/z3/tritonToZ3Ast.cpp.o] Error 1
CMakeFiles/Makefile2:1185: recipe for target 'src/libtriton/CMakeFiles/triton.dir/all' failed
make[1]: *** [src/libtriton/CMakeFiles/triton.dir/all] Error 2
Makefile:138: recipe for target 'all' failed
make: *** [all] Error 2
wanghuozhu@dlserver:~/ws/other/Triton/build$ 

ans:
 I tried with z3 4.8.8 and it's works well. 
https://github.com/JonathanSalwan/Triton/issues/704

wanghuozhu@dlserver:~/ws/other/Triton/build$ sudo apt install libz3-dev
Reading package lists... Done
Building dependency tree       
Reading state information... Done
libz3-dev is already the newest version (4.4.0-5).
0 upgraded, 0 newly installed, 0 to remove and 245 not upgraded.
wanghuozhu@dlserver:~/ws/other/Triton/build$ 

```