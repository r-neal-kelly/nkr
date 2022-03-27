cmake_minimum_required(VERSION 3.23)

project(nkr
        LANGUAGES CXX)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_subdirectory("./nkr")
add_subdirectory("./doctest")

#if (BUILD_TESTING)
    add_subdirectory("./nkr_tests/boolean")
#endif()
