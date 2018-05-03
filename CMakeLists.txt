cmake_minimum_required(VERSION 3.10)
project(dsincpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsincpp main.cpp linearList/linkList/linkList.h linearList/linkList/linkList.cpp
        linearList/linkList/DLinkList.cpp linearList/linkList/DLinkList.h)