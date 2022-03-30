# nkr_test_atomic_t

cmake_minimum_required(VERSION 3.23)

project(nkr_test_atomic_t
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/boolean_p.cpp"
    "src/integer_p.cpp"
    "src/pointer_p.cpp"
    "src/real_p.cpp"
    "src/void_pointer_p.cpp")

add_executable(nkr_test_atomic_t)
target_sources(nkr_test_atomic_t PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_atomic_t PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_atomic_t
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_atomic_t
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
