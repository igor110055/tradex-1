cmake_minimum_required(VERSION 3.18)

project(crypto_bot VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# include(${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
# conan_basic_setup()

string(TOUPPER ${CMAKE_CXX_COMPILER_ID} CMAKE_CXX_COMPILER_ID)
if(CMAKE_CXX_COMPILER_ID STREQUAL "CLANG")
  add_compile_options(-fsanitize=thread)
  add_link_options(-fsanitize=thread)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/binance-sdk)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/binance)
