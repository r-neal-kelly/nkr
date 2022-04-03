# nkr_test_cpp

cmake_minimum_required(VERSION 3.18)

project(nkr_test_cpp
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/array/remote/dynamic_t.cpp"
    "src/concurrency/locker/exclusive_t.cpp"
    "src/concurrency/locker/inclusive_t.cpp"
    "src/concurrency/locker/scoped_t.cpp"
    "src/cpp.cpp"
    "src/generic/concurrency/lock/deep_tr.cpp"
    "src/generic/concurrency/lock/exclusive_tr.cpp"
    "src/generic/concurrency/lock/inclusive_tr.cpp"
    "src/generic/concurrency/lock/perpetual_tr.cpp"
    "src/generic/concurrency/lock/temporal_tr.cpp"
    "src/generic/concurrency/lock/unary_tr.cpp"
    "src/generic/concurrency/lock/wide_tr.cpp"
    "src/generic/concurrency/lock_tr.cpp"
    "src/generic/concurrency/locker_tr.cpp"
    "src/generic/randomness/distributor/uniform_tr.cpp"
    "src/generic/randomness/distributor_tr.cpp"
    "src/generic/randomness/generator_tr.cpp"
    "src/list/remote/forward_t.cpp"
    "src/randomness/generator/software/mersenne_twister_t.cpp")

add_executable(nkr_test_cpp)
target_sources(nkr_test_cpp PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_cpp PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_cpp
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_cpp
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
