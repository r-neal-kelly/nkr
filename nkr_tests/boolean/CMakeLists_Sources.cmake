# C:\git\nkr\nkr_tests\boolean

function(add_target_includes target_name)
endfunction()

function(add_target_sources target_name)
    target_sources(${target_name} PRIVATE
                   "src/bool_t.cpp"
                   "src/cpp_t.cpp"
                   "src/pure_t.cpp")
endfunction()
