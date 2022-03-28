cmake_minimum_required(VERSION 3.23)

project(nkr_test_generic
        LANGUAGES CXX)

add_executable(nkr_test_generic
               "src/array/any_tr.cpp"
               "src/boolean/any_tr.cpp")

target_include_directories(nkr_test_generic
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}")

target_link_libraries(nkr_test_generic
                      PRIVATE nkr
                      PRIVATE doctest)

target_compile_features(nkr_test_generic
                        PRIVATE cxx_std_20)
