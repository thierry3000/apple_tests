cmake_minimum_required(VERSION 3.1)
project(apple_tests)
# c++ 11 for newer cmake
set(CMAKE_CXX_STANDARD 11)
# adding cmake support for GMP
message("CMAKE_ROOT: ${CMAKE_ROOT}")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules/;")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
#already prepare for vbl
find_package(GMP)#provides variables ${GMP_LIBRARIES} and ${GMPXX_LIBRARIES}

#see which compiler is there
message(WARNING "you are using the compiler: ${CMAKE_CXX_COMPILER}")
#check for openmp
find_package(OpenMP)
if (OPENMP_FOUND)
  message(STATUS "OpenMP_CXX_FLAGS        = ${OpenMP_CXX_FLAGS}")
  message(STATUS "OpenMP_C_FLAGS          = ${OpenMP_C_FLAGS}")
  message(STATUS "OpenMP_EXE_LINKER_FLAGS = ${OpenMP_EXE_LINKER_FLAGS}")
  set (CMAKE_C_FLAGS          "${OpenMP_C_FLAGS} ${CMAKE_C_FLAGS}")
  set (CMAKE_CXX_FLAGS        "${OpenMP_CXX_FLAGS} ${CMAKE_CXX_FLAGS}")
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else()
  message(WARNING "OpenMP not supported by compiler: ${CMAKE_CXX_COMPILER}")
endif()

add_executable(apple_tests main.cpp)

install(TARGETS apple_tests RUNTIME DESTINATION bin)
