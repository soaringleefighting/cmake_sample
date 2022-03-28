#vim: syntax=cmake
if(NOT CMAKE_BUILD_TYPE)
    # default to Release build for GCC builds
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
endif()

cmake_minimum_required (VERSION 2.8.8) #CMake要求的最低版本
project (CMake_sample) # 工程名
message (STATUS "cmake version ${CMAKE_VERSION}") #输出log信息
message (STATUS "project name ${PROJECT_NAME}")
#message (STATUS "compile helloworld!!!")
SET(CMAKE_SOURCE_DIR .)

option(NATIVE_BUILD "Target the build CPU" OFF) #选项设置
option(STATIC_LINK_CRT "Statically link C runtime for release builds" OFF)

set (COMPILE_ARGS -fPIC) #设置普通变量
list (APPEND COMPILE_ARGS "-D_TEST") #列表追加
add_definitions (${COMPILE_ARGS}) #添加宏定义

# System architecture detection
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" SYSPROC)
set(X86_ALIASES x86 i386 i686 x86_64 amd64)
set(ARM_ALIASES armv6l armv7l aarch64)
list(FIND X86_ALIASES "${SYSPROC}" X86MATCH)
list(FIND ARM_ALIASES "${SYSPROC}" ARMMATCH)
message (STATUS "X86MATCH ${X86MATCH}")
message (STATUS "ARMMATCH ${ARMMATCH}")

add_executable ( demo ./helloworld.cpp) #设置可执行文件