cmake_minimum_required(VERSION 3.5)
project( peak_flow )

set(CMAKE_CXX_STANDARD 20)
set(CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message("build type:" ${CMAKE_BUILD_TYPE})
endif()

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(CMAKE_CXX_FLAGS "-std=c++20 -g3 -Wall")
  message("flag:" ${CMAKE_CXX_FLAGS})
endif()

#link
set( LINK_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set( SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/peak.cpp
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${LINK_INCLUDE_DIRS}
)

add_executable(peak ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(peak
  PUBLIC
  ${PROJECT_NAME}
)