cmake_minimum_required(VERSION 3.27)
project(AaDT_Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(AaDT_Lab1 main.cpp
        LinkedList.h
        Stack.h
        application.h
        application.cpp
        Array.h
        SortStation.h
        SortStation.cpp
)
