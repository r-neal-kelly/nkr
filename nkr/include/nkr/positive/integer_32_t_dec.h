/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/general/positive_tr_dec.h"
#include "nkr/general/positive/any_tr_dec.h"
#include "nkr/general/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  integer_32_tg   {};

    template <typename type_p>
    concept integer_32_tr =
        cpp::is_any_tr<type_p, integer_32_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) * 8 == 32);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<positive::integer_32_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <positive::integer_32_tr type_p>
    class type_i<type_p> :
        public type_i<positive::integer_32_tg>
    {
    public:
    };

}}

#include "nkr/positive/integer_32_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(general::positive_tr<integer_32_t>);
    static_assert(general::positive_tr<const integer_32_t>);
    static_assert(general::positive_tr<volatile integer_32_t>);
    static_assert(general::positive_tr<const volatile integer_32_t>);

    static_assert(general::positive::any_tr<integer_32_t>);
    static_assert(general::positive::any_tr<const integer_32_t>);
    static_assert(general::positive::any_tr<volatile integer_32_t>);
    static_assert(general::positive::any_tr<const volatile integer_32_t>);

    static_assert(general::positive::integer_tr<integer_32_t>);
    static_assert(general::positive::integer_tr<const integer_32_t>);
    static_assert(general::positive::integer_tr<volatile integer_32_t>);
    static_assert(general::positive::integer_tr<const volatile integer_32_t>);

}}
