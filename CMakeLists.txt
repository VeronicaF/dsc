cmake_minimum_required(VERSION 3.10)
project(dsincpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsincpp main.cpp linearList/linkList/linkList.h linearList/linkList/linkList.cpp
        linearList/linkList/DLinkList.cpp linearList/linkList/DLinkList.h stack&queue/stack/SqStack.cpp stack&queue/stack/SqStack.h stack&queue/queue/sqQueue.cpp stack&queue/queue/sqQueue.h stack&queue/queue/linkQueue.cpp stack&queue/queue/linkQueue.h)