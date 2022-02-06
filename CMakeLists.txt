cmake_minimum_required(VERSION 3.10)
project(LisaScript)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE MY_APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(my_app_src ${MY_APP_SRC})
target_include_directories(my_app_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(my_app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(my_app my_app_src)

file(GLOB_RECURSE MY_APP_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${MY_APP_TEST_SRC})
target_link_libraries(tests my_app_src)
target_link_libraries(tests ${CONAN_LIBS})