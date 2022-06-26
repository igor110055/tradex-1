cmake_minimum_required(VERSION 3.18)

project(
  binance_sdk
  VERSION 0.1.0
  DESCRIPTION "Binance API C++ SDK"
  LANGUAGES C CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
include(CTest)
include(CPack)

find_package(Poco 1.11.2 CONFIG REQUIRED COMPONENTS JSON NetSSL)
find_package(Threads)

file(GLOB SRCS "*.cpp" "*.hpp")
add_library(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads Poco::NetSSL
                                             Poco::JSON)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(BUILD_SHARED_LIBS AND WIN32)
  target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE "${PROJECT_NAME}_EXPORT=__declspec(dllexport)"
    INTERFACE "${PROJECT_NAME}_EXPORT=__declspec(dllimport)")
endif()

if(BUILD_TESTING AND ${PROJECT_NAME}_BUILD_TESTS)
  enable_testing()
  include(Dart)
  find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
  add_subdirectory(tests)
  add_test(NAME ${PROJECT_NAME}_test_defs
           COMMAND ${EXECUTABLE_OUTPUT_PATH}/tests/${PROJECT_NAME}_test_defs)
endif()

configure_package_config_file(
  cmake/config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}
  NO_SET_AND_CHECK_MACRO)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  VERSION ${beicode_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
install(
  EXPORT ${PROJECT_NAME}-targets
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})
