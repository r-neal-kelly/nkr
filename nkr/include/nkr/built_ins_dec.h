/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"

namespace nkr { namespace none {

    using   type_t      = cpp::none::type_t;
    using   pointer_t   = cpp::none::pointer_t;

}}

namespace nkr { namespace boolean {

    using   cpp_t   = cpp::boolean_t;

}}

namespace nkr { namespace positive {

    using   integer_8_t     = cpp::positive::integer_8_t;
    using   integer_16_t    = cpp::positive::integer_16_t;
    using   integer_32_t    = cpp::positive::integer_32_t;
    using   integer_64_t    = cpp::positive::integer_64_t;
    using   integer_t       = cpp::positive::integer_t;

    using   byte_t          = cpp::positive::byte_t;
    using   word_t          = cpp::positive::word_t;

    using   size_t          = cpp::positive::size_t;
    using   count_t         = cpp::positive::count_t;
    using   index_t         = cpp::positive::index_t;

}}

namespace nkr { namespace negatable {

    using   integer_8_t     = cpp::negatable::integer_8_t;
    using   integer_16_t    = cpp::negatable::integer_16_t;
    using   integer_32_t    = cpp::negatable::integer_32_t;
    using   integer_64_t    = cpp::negatable::integer_64_t;
    using   integer_t       = cpp::negatable::integer_t;

    using   real_32_t       = cpp::negatable::real_32_t;
    using   real_64_t       = cpp::negatable::real_64_t;
    using   real_t          = cpp::negatable::real_t;

    using   byte_t          = cpp::negatable::byte_t;
    using   word_t          = cpp::negatable::word_t;

    using   size_t          = cpp::negatable::size_t;
    using   count_t         = cpp::negatable::count_t;
    using   index_t         = cpp::negatable::index_t;

}}

namespace nkr { namespace pointer {

    template <typename any_p>
    using   cpp_t   = any_p*;

}}

namespace nkr { namespace array {

    template <cpp::type_tr type_p, cpp::positive::count_t capacity_p>
    using   cpp_t   = type_p[capacity_p];

}}
