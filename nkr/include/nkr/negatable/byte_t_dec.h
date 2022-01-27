/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/integer_t_dec.h"

namespace nkr { namespace negatable {

    using   byte_t =
        nkr::cpp::negatable::byte_t;

    struct  byte_tg {};

    template <typename type_p>
    concept byte_tr =
        nkr::cpp::is_any_tr<type_p, byte_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(byte_t));

    template <byte_t value_p>
    using   byte_c =
        nkr::cpp::constant_t<byte_t, value_p>;

    template <typename type_p>
    concept byte_ctr =
        nkr::cpp::constant_of_tr<type_p, byte_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::byte_tg> :
        public type_i<nkr::negatable::byte_t>
    {
    public:
        using type_t    = nkr::negatable::byte_tg;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/negatable/byte_t_dec_def.h"
