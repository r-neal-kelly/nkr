# tree

function(get_include_files RESULT)
    set(${RESULT}
        "CMakeLists.txt"
        "CMakeLists_Funcs.cmake"
        PARENT_SCOPE)
endfunction()

function(get_source_files RESULT)
    set(${RESULT}
        "src/binary_search_t.cpp"
        PARENT_SCOPE)
endfunction()

function(get_all_files RESULT)
    get_include_files(THIS_INCLUDE_FILES)
    get_source_files(THIS_SOURCE_FILES)
    set(${RESULT} ${THIS_INCLUDE_FILES} ${THIS_SOURCE_FILES} PARENT_SCOPE)
endfunction()
