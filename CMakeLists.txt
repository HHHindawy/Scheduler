cmake_minimum_required(VERSION 3.8)
project(FScheduler)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c minHeap.c minHeap.h queue.c queue.h)
add_executable(FScheduler ${SOURCE_FILES})