/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"

namespace nkr { namespace none {

    using   type_t      = cpp::void_t;
    using   pointer_t   = cpp::nullptr_t;

}}

namespace nkr { namespace boolean {

    using   cpp_t   = cpp::bool_t;

}}

namespace nkr { namespace integer { namespace positive {

    using   cpp_8_t     = cpp::u8_t;
    using   cpp_16_t    = cpp::u16_t;
    using   cpp_32_t    = cpp::u32_t;
    using   cpp_64_t    = cpp::u64_t;

    using   byte_t      = cpp::u8_t;
    using   word_t      = cpp::unsigned_word_t;

    using   size_t      = cpp::unsigned_word_t;
    using   count_t     = cpp::unsigned_word_t;
    using   index_t     = cpp::unsigned_word_t;
    using   address_t   = cpp::unsigned_word_t;

}}}

namespace nkr { namespace integer { namespace negatable {

    using   cpp_8_t     = cpp::s8_t;
    using   cpp_16_t    = cpp::s16_t;
    using   cpp_32_t    = cpp::s32_t;
    using   cpp_64_t    = cpp::s64_t;

    using   byte_t      = cpp::s8_t;
    using   word_t      = cpp::signed_word_t;

    using   size_t      = cpp::signed_word_t;
    using   count_t     = cpp::signed_word_t;
    using   index_t     = cpp::signed_word_t;
    using   address_t   = cpp::signed_word_t;

}}}

namespace nkr { namespace real { namespace negatable {

    using   cpp_32_t    = cpp::r32_t;
    using   cpp_64_t    = cpp::r64_t;

    using   word_t      = cpp::real_word_t;

}}}

namespace nkr { namespace pointer {

    template <typename any_p>
    using   cpp_t   = any_p*;

}}

namespace nkr { namespace array {

    template <cpp::type_tr type_p, cpp::count_t capacity_p>
    using   cpp_t   = type_p[capacity_p];

}}
