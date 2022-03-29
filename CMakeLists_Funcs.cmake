# repository

function(get_test_directories RESULT)
    set(${RESULT}
        "doctest"
        "nkr_tests/allocator"
        "nkr_tests/array"
        "nkr_tests/atomic_t"
        "nkr_tests/boolean"
        "nkr_tests/charcoder"
        "nkr_tests/concurrency"
        "nkr_tests/constant"
        "nkr_tests/cpp"
        "nkr_tests/docs"
        "nkr_tests/enumeration"
        "nkr_tests/generic"
        "nkr_tests/hasher"
        "nkr_tests/interface"
        "nkr_tests/macros"
        "nkr_tests/math"
        "nkr_tests/maybe_t"
        "nkr_tests/negatable"
        "nkr_tests/none"
        "nkr_tests/number"
        "nkr_tests/optional"
        "nkr_tests/os"
        "nkr_tests/pointer"
        "nkr_tests/pointer_t"
        "nkr_tests/positive"
        "nkr_tests/randomness"
        "nkr_tests/regex_t"
        "nkr_tests/string"
        "nkr_tests/tr"
        "nkr_tests/tree"
        "nkr_tests/tuple"
        "nkr_tests/utils"
        PARENT_SCOPE)
endfunction()

