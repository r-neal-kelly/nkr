cmake_minimum_required(VERSION 3.23)

project(doctest
        LANGUAGES CXX)

add_library(doctest STATIC
            "${NKR_DOCTEST_INCLUDE_DIR}/doctest.h"
            "${NKR_DOCTEST_SOURCE_DIR}/doctest.cpp")

target_include_directories(doctest
                           PUBLIC "${NKR_DOCTEST_INCLUDE_DIR}")

target_compile_features(doctest
                        PUBLIC cxx_std_20)
