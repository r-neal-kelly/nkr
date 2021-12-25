/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/general/negatable_tr_dec.h"
#include "nkr/general/negatable/any_tr_dec.h"
#include "nkr/general/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  integer_32_tg   {};

    template <typename type_p>
    concept integer_32_tr =
        cpp::is_any_tr<type_p, integer_32_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) * 8 == 32);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::integer_32_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <negatable::integer_32_tr type_p>
    class type_i<type_p> :
        public type_i<negatable::integer_32_tg>
    {
    public:
    };

}}

#include "nkr/negatable/integer_32_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(general::negatable_tr<integer_32_t>);
    static_assert(general::negatable_tr<const integer_32_t>);
    static_assert(general::negatable_tr<volatile integer_32_t>);
    static_assert(general::negatable_tr<const volatile integer_32_t>);

    static_assert(general::negatable::any_tr<integer_32_t>);
    static_assert(general::negatable::any_tr<const integer_32_t>);
    static_assert(general::negatable::any_tr<volatile integer_32_t>);
    static_assert(general::negatable::any_tr<const volatile integer_32_t>);

    static_assert(general::negatable::integer_tr<integer_32_t>);
    static_assert(general::negatable::integer_tr<const integer_32_t>);
    static_assert(general::negatable::integer_tr<volatile integer_32_t>);
    static_assert(general::negatable::integer_tr<const volatile integer_32_t>);

}}
