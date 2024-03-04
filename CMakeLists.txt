cmake_minimum_required(VERSION 3.22)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADER_FILES "src/solution/*.h")

set(ALL_INCLUDES "")
foreach(HEADER ${HEADER_FILES})
    file(RELATIVE_PATH REL_HEADER ${CMAKE_SOURCE_DIR} ${HEADER})
    set(ALL_INCLUDES "${ALL_INCLUDES}#include \"${REL_HEADER}\"\n")
endforeach()

message(STATUS "ALL_INCLUDES: \n${ALL_INCLUDES}")
configure_file(solution.h.in  ${CMAKE_CURRENT_SOURCE_DIR}/solution.h @ONLY)

include_directories(
        ./
        src/include
        src/solution
)

file(GLOB_RECURSE SOURCES "./src/*.*" "src/solution/*.*" "./src/include/*.*")

add_executable(
        Algorithm
        ${SOURCES}
        solution.h
)
