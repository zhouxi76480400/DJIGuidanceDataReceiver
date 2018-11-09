cmake_minimum_required(VERSION 3.12)
project(DJIGuidanceDataReceiver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -g -O0")

include_directories(include)

if((CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64") AND (CMAKE_SIZEOF_VOID_P EQUAL 8))
    set(TARGET_ARCH "x86_64")
elseif((CMAKE_SYSTEM_PROCESSOR MATCHES "i386|i686|x86|AMD64") AND (CMAKE_SIZEOF_VOID_P EQUAL 4))
    set(TARGET_ARCH "x86")
elseif((CMAKE_SYSTEM_PROCESSOR MATCHES "^arm*") OR (CMAKE_SYSTEM_PROCESSOR MATCHES "^aarch*"))
    set(TARGET_ARCH "arm")
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(PROC_VERSION "v7")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(PROC_VERSION "v8")
    endif()
endif()


if (TARGET_ARCH MATCHES "x86_64")
    set(LIB_PATH "x86-64linux")
elseif(TARGET_ARCH MATCHES "arm")
    if (PROC_VERSION MATCHES "v7")
        set(LIB_PATH "arm-v7linux")
    elseif(PROC_VERSION MATCHES "v8")
        set(LIB_PATH "arm-v8linux")
    endif ()
endif ()

add_executable(DJIGuidanceDataReceiver
        main.cpp
        serial/serial.h
        serial/serial.cpp
        GuidanceReceiver.cpp
        GuidanceReceiver.h
        )

target_link_libraries(DJIGuidanceDataReceiver
        ${CMAKE_SOURCE_DIR}/libs/${LIB_PATH}/libDJI_guidance.so
        )