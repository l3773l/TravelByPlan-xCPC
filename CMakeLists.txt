cmake_minimum_required(VERSION 3.18)
project(OI CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB_RECURSE ANSWER_SOURCE ./*.cpp)

foreach (file ${ANSWER_SOURCE})
    string(REGEX REPLACE ".:.*\\./(.*)\\..*" "\\1" file_name ${file})
    string(REGEX REPLACE "/" "_" file_name ${file_name})
    message("Creat Target " ${file_name} " ON " ${file})
    add_executable(${file_name} ${file})
endforeach ()