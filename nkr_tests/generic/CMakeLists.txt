# nkr_test_generic

cmake_minimum_required(VERSION 3.18)

project(nkr_test_generic
        LANGUAGES CXX)

set(THIS_INCLUDE_FILES
    "")

set(THIS_SOURCE_FILES
    "src/array/any_tr.cpp"
    "src/array_tr.cpp"
    "src/boolean/any_tr.cpp"
    "src/boolean/impure_tr.cpp"
    "src/boolean/pure_tr.cpp"
    "src/boolean_tr.cpp"
    "src/built_in_tr.cpp"
    "src/implementing/constructor/default_tr.cpp"
    "src/implementing/interface/enumeration/types_tr.cpp"
    "src/implementing/interface/none/value_tr.cpp"
    "src/implementing/interface/template_tr.cpp"
    "src/implementing/interface/type_tr.cpp"
    "src/implementing/self_tr.cpp"
    "src/negatable/any_tr.cpp"
    "src/negatable/integer_tr.cpp"
    "src/negatable/real_tr.cpp"
    "src/negatable_tr.cpp"
    "src/none/any_tr.cpp"
    "src/none_tr.cpp"
    "src/non_type_tr.cpp"
    "src/number/any_tr.cpp"
    "src/number/integer_tr.cpp"
    "src/number/real_tr.cpp"
    "src/number_tr.cpp"
    "src/pointer/any_tr.cpp"
    "src/pointer_tr.cpp"
    "src/positive/any_tr.cpp"
    "src/positive/integer_tr.cpp"
    "src/positive/real_tr.cpp"
    "src/positive_tr.cpp"
    "src/type_tr.cpp"
    "src/user_defined_tr.cpp")

add_executable(nkr_test_generic)
target_sources(nkr_test_generic PUBLIC ${THIS_INCLUDE_FILES})
target_sources(nkr_test_generic PRIVATE ${THIS_SOURCE_FILES})

target_include_directories(nkr_test_generic
                           PRIVATE "${NKR_NKR_INCLUDE_DIR}"
                           PRIVATE "${NKR_DOCTEST_INCLUDE_DIR}"
                           PRIVATE "include")

target_link_libraries(nkr_test_generic
                      PRIVATE nkr
                      PRIVATE doctest)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
             PREFIX "File Tree"
             FILES ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES})
