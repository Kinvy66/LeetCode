cmake_minimum_required(VERSION 3.16)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)
include_directories(./inc)


#add_executable(LeetCode main.cpp 001TwoSum.cpp)
# 遍历项目目录下所有的 .cpp 文件，注意文件不能重名以及包即中文字符
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()