cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(test_boost_python)

set(Python_ADDITIONAL_VERSIONS 3.4m)
find_package(PythonLibs 3.4 REQUIRED)
find_package(Boost REQUIRED python-py34)

link_directories(~/usr/lib64)  # directory containing libboost_numpy.so
include_directories(~/usr/include)  # directory containing boost/numpy.hpp

add_executable(test src/test.cpp)
target_link_libraries(test ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} boost_numpy)
target_include_directories(test PUBLIC ${PYTHON_INCLUDE_DIRS})
