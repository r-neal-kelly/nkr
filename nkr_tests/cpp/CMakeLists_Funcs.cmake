# cpp

function(get_include_files RESULT)
    set(${RESULT}
        "CMakeLists.txt"
        "CMakeLists_Funcs.cmake"
        PARENT_SCOPE)
endfunction()

function(get_source_files RESULT)
    set(${RESULT}
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
        "src/generic/concurrency/locker_tr.cpp"
        "src/generic/concurrency/lock_tr.cpp"
        "src/generic/randomness/distributor/uniform_tr.cpp"
        "src/generic/randomness/distributor_tr.cpp"
        "src/generic/randomness/generator_tr.cpp"
        "src/list/remote/forward_t.cpp"
        "src/randomness/generator/software/mersenne_twister_t.cpp"
        PARENT_SCOPE)
endfunction()

function(get_all_files RESULT)
    get_include_files(THIS_INCLUDE_FILES)
    get_source_files(THIS_SOURCE_FILES)
    set(${RESULT} ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES} PARENT_SCOPE)
endfunction()
