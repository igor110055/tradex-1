cmake_minimum_required(VERSION 3.18)

project(binance_bot VERSION 0.1.0)

find_package(Threads)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads binance_sdk)
