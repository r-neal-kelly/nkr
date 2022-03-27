cmake_minimum_required(VERSION 3.23)

project(nkr_test_boolean
        LANGUAGES CXX)

add_executable(nkr_test_boolean
               "src/bool_t.cpp"
               "src/cpp_t.cpp"
               "src/pure_t.cpp")

target_include_directories(nkr_test_boolean
                           PRIVATE "../../nkr/include"
                           PRIVATE "../../doctest/include")

target_link_libraries(nkr_test_boolean
                      PRIVATE "../../nkr/Debug/nkr"
                      PRIVATE "../../doctest/Debug/doctest")

target_compile_features(nkr_test_boolean
                        PUBLIC cxx_std_20)
