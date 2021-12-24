/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/trait/negatable_tr_dec.h"
#include "nkr/trait/negatable/any_tr_dec.h"
#include "nkr/trait/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  integer_8_tg    {};

    template <typename type_p>
    concept integer_8_tr =
        cpp::is_any_tr<type_p, integer_8_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 8);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::integer_8_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <negatable::integer_8_tr type_p>
    class type_i<type_p> :
        public type_i<negatable::integer_8_tg>
    {
    public:
    };

}}

#include "nkr/negatable/integer_8_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<integer_8_t>);
    static_assert(trait::negatable_tr<const integer_8_t>);
    static_assert(trait::negatable_tr<volatile integer_8_t>);
    static_assert(trait::negatable_tr<const volatile integer_8_t>);

    static_assert(trait::negatable::any_tr<integer_8_t>);
    static_assert(trait::negatable::any_tr<const integer_8_t>);
    static_assert(trait::negatable::any_tr<volatile integer_8_t>);
    static_assert(trait::negatable::any_tr<const volatile integer_8_t>);

    static_assert(trait::negatable::integer_tr<integer_8_t>);
    static_assert(trait::negatable::integer_tr<const integer_8_t>);
    static_assert(trait::negatable::integer_tr<volatile integer_8_t>);
    static_assert(trait::negatable::integer_tr<const volatile integer_8_t>);

}}
