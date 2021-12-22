/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/negatable_tr_dec.h"
#include "nkr/trait/negatable/any_tr_dec.h"
#include "nkr/trait/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  integer_64_tg   {};

    template <typename type_p>
    concept integer_64_tr =
        cpp::is_any_tr<type_p, integer_64_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 64);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::integer_64_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <negatable::integer_64_tr type_p>
    class type_i<type_p> :
        public type_i<negatable::integer_64_tg>
    {
    public:
    };

}}
