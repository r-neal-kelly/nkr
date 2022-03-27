cmake_minimum_required(VERSION 3.23)

project(nkr
        LANGUAGES CXX)

add_library(nkr STATIC
            "src/z_allocator_heap_t.cpp"
            "src/z_allocator_heap_zeros_t.cpp"
            "src/z_pointer_t.cpp"
            "src/z_utils.cpp")

target_include_directories(nkr
                           PUBLIC "include")

target_compile_features(nkr
                        PUBLIC cxx_std_20)
