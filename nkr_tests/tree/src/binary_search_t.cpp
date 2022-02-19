/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/z_intrinsics.h"

#include "nkr/z_tree/binary_search_t.h"

#include "doctest.h"

namespace nkr { namespace tree {

    TEST_SUITE("temp")
    {
        stack::binary_search_t<maybe_t<word_t>, 16> tree;
    }

    TEST_SUITE("temp")
    {
        stack::binary_search_t<optional_t<word_t>, 16> tree;
    }

    TEST_SUITE("temp")
    {
        stack::binary_search_t<maybe_t<word_t>, 16> tree = maybe_t<word_t>();
    }

    TEST_SUITE("temp")
    {
        stack::binary_search_t<optional_t<word_t>, 16> tree = optional_t<word_t>();
    }

}}
