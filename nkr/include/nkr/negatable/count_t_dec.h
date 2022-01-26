/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    using   count_t =
        nkr::cpp::negatable::count_t;

    struct  count_tg    {};

    template <typename type_p>
    concept count_tr =
        nkr::cpp::is_any_tr<type_p, count_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

    template <count_t value_p>
    using   count_c =
        nkr::cpp::constant_t<count_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::count_tg> :
        public type_i<nkr::negatable::count_t>
    {
    public:
        using type_t    = nkr::negatable::count_tg;
    };

}}

#include "nkr/negatable/count_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<count_t>);
    static_assert(generic::negatable_tr<const count_t>);
    static_assert(generic::negatable_tr<volatile count_t>);
    static_assert(generic::negatable_tr<const volatile count_t>);

    static_assert(generic::negatable::any_tr<count_t>);
    static_assert(generic::negatable::any_tr<const count_t>);
    static_assert(generic::negatable::any_tr<volatile count_t>);
    static_assert(generic::negatable::any_tr<const volatile count_t>);

    static_assert(generic::negatable::integer_tr<count_t>);
    static_assert(generic::negatable::integer_tr<const count_t>);
    static_assert(generic::negatable::integer_tr<volatile count_t>);
    static_assert(generic::negatable::integer_tr<const volatile count_t>);

}}
