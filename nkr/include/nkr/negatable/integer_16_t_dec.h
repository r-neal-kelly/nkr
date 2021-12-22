/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace negatable {

    struct  integer_16_tg   {};

    template <typename type_p>
    concept integer_16_tr =
        cpp::is_any_tr<type_p, integer_16_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 16);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::integer_16_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <negatable::integer_16_tr type_p>
    class type_i<type_p> :
        public type_i<negatable::integer_16_tg>
    {
    public:
    };

}}
