# C:\git\nkr\doctest

function(add_target_includes target_name)
    target_sources(${target_name} PUBLIC
                   "include/doctest.h")
endfunction()

function(add_target_sources target_name)
    target_sources(${target_name} PRIVATE
                   "src/doctest.cpp")
endfunction()
