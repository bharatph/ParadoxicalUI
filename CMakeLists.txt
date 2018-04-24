cmake_minimum_required(VERSION 2.8.11)
project(CallbackTests)
find_package(Threads REQUIRED)

add_executable(CallbackTests main.cpp)
target_include_directories(CallbackTests PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(CallbackTests ${CMAKE_THREAD_LIBS_INIT})
