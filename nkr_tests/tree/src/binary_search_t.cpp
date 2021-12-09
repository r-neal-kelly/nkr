/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"

#include "nkr/tree/binary_search_t.h"

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
        stack::binary_search_t<maybe_t<word_t>, 16> tree(maybe_t<word_t>(word_t(0)));
    }

    TEST_SUITE("temp")
    {
        stack::binary_search_t<optional_t<word_t>, 16> tree(optional_t<word_t>(word_t(0), false));
    }

}}
