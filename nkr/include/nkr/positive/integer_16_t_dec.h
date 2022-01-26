/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/positive_tr_dec.h"
#include "nkr/generic/positive/any_tr_dec.h"
#include "nkr/generic/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    using   integer_16_t =
        nkr::cpp::positive::integer_16_t;

    struct  integer_16_tg   {};

    template <typename type_p>
    concept integer_16_tr =
        nkr::cpp::is_any_tr<type_p, integer_16_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) * 8 == 16);

    template <integer_16_t value_p>
    using   integer_16_c =
        nkr::cpp::constant_t<integer_16_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::integer_16_tg>
    {
    public:
        using type_t    = nkr::positive::integer_16_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::positive::integer_16_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::positive::integer_16_tg>
    {
    public:
        using type_t    = type_p;
    };

}}

#include "nkr/positive/integer_16_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<integer_16_t>);
    static_assert(generic::positive_tr<const integer_16_t>);
    static_assert(generic::positive_tr<volatile integer_16_t>);
    static_assert(generic::positive_tr<const volatile integer_16_t>);

    static_assert(generic::positive::any_tr<integer_16_t>);
    static_assert(generic::positive::any_tr<const integer_16_t>);
    static_assert(generic::positive::any_tr<volatile integer_16_t>);
    static_assert(generic::positive::any_tr<const volatile integer_16_t>);

    static_assert(generic::positive::integer_tr<integer_16_t>);
    static_assert(generic::positive::integer_tr<const integer_16_t>);
    static_assert(generic::positive::integer_tr<volatile integer_16_t>);
    static_assert(generic::positive::integer_tr<const volatile integer_16_t>);

}}
