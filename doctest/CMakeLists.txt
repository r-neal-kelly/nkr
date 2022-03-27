cmake_minimum_required(VERSION 3.23)

project(doctest
        LANGUAGES CXX)

add_library(doctest STATIC
            "src/doctest.cpp")

target_include_directories(doctest
                           PUBLIC "include")

target_compile_features(doctest
                        PUBLIC cxx_std_20)
