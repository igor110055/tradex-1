include_directories(../include ../)

file(GLOB ${PROJECT_NAME}_TEST_SOURCES *.cpp)

find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

add_executable(${PROJECT_NAME}_test_defs "${${PROJECT_NAME}_TEST_SOURCES}")

target_link_libraries(
  ${PROJECT_NAME}_test_defs PRIVATE ${PROJECT_NAME} Catch2::Catch2
                                    Catch2::Catch2WithMain fmt::fmt-header-only)
