cmake_minimum_required(VERSION 3.23)

project(nkr
        LANGUAGES CXX)

add_library(nkr STATIC
            "${NKR_NKR_SOURCE_DIR}/z_allocator_heap_t.cpp"
            "${NKR_NKR_SOURCE_DIR}/z_allocator_heap_zeros_t.cpp"
            "${NKR_NKR_SOURCE_DIR}/z_pointer_t.cpp"
            "${NKR_NKR_SOURCE_DIR}/z_utils.cpp")

target_include_directories(nkr
                           PUBLIC "${NKR_NKR_INCLUDE_DIR}")

target_compile_features(nkr
                        PUBLIC cxx_std_20)
