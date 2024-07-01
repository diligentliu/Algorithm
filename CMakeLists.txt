cmake_minimum_required(VERSION 3.22)
project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-DLOCAL_LEETCODE)

file(GLOB_RECURSE HEADER_FILES "src/solution/*.h")

set(ALL_INCLUDES "")
foreach (HEADER ${HEADER_FILES})
    get_filename_component(FILE_NAME ${HEADER} NAME)
    set(ALL_INCLUDES "${ALL_INCLUDES}#include \"${FILE_NAME}\"\n")
endforeach ()

message(STATUS "ALL_INCLUDES: \n${ALL_INCLUDES}")
configure_file(solution.h.in ${CMAKE_CURRENT_SOURCE_DIR}/solution.h @ONLY)

include_directories(
        ./
        include
        src/solution
)

file(GLOB_RECURSE SOURCES "./src/*.*" "src/solution/*.*" "include/*.*")

add_executable(
        Algorithm
        ${SOURCES}
        solution.h
)
