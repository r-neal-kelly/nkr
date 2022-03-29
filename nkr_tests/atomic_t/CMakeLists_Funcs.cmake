# atomic_t

function(get_include_files RESULT)
    set(${RESULT}
        "CMakeLists.txt"
        "CMakeLists_Funcs.cmake"
        PARENT_SCOPE)
endfunction()

function(get_source_files RESULT)
    set(${RESULT}
        "src/boolean_p.cpp"
        "src/integer_p.cpp"
        "src/pointer_p.cpp"
        "src/real_p.cpp"
        "src/void_pointer_p.cpp"
        PARENT_SCOPE)
endfunction()

function(get_all_files RESULT)
    get_include_files(THIS_INCLUDE_FILES)
    get_source_files(THIS_SOURCE_FILES)
    set(${RESULT} ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES} PARENT_SCOPE)
endfunction()
