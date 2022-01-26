/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_t_dec.h"

#include "nkr/generic/positive_tr_dec.h"
#include "nkr/generic/positive/any_tr_dec.h"
#include "nkr/generic/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    /*using   count_t =
        nkr::cpp::positive::count_t;*/

    struct  count_tg    {};

    template <typename type_p>
    concept count_tr =
        nkr::cpp::is_any_tr<type_p, count_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

    template <count_t value_p>
    using   count_c =
        nkr::cpp::constant_t<count_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::count_tg> :
        public type_i<nkr::positive::count_t>
    {
    public:
        using type_t    = nkr::positive::count_tg;
    };

}}

#include "nkr/positive/count_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<count_t>);
    static_assert(generic::positive_tr<const count_t>);
    static_assert(generic::positive_tr<volatile count_t>);
    static_assert(generic::positive_tr<const volatile count_t>);

    static_assert(generic::positive::any_tr<count_t>);
    static_assert(generic::positive::any_tr<const count_t>);
    static_assert(generic::positive::any_tr<volatile count_t>);
    static_assert(generic::positive::any_tr<const volatile count_t>);

    static_assert(generic::positive::integer_tr<count_t>);
    static_assert(generic::positive::integer_tr<const count_t>);
    static_assert(generic::positive::integer_tr<volatile count_t>);
    static_assert(generic::positive::integer_tr<const volatile count_t>);

}}
