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

    /*using   index_t =
        nkr::cpp::positive::index_t;*/

    struct  index_tg    {};

    template <typename type_p>
    concept index_tr =
        nkr::cpp::is_any_tr<type_p, index_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(index_t));

    template <index_t value_p>
    using   index_c =
        nkr::cpp::constant_t<index_t, value_p>;

    /*template <typename type_p>
    concept index_ctr =
        nkr::cpp::constant_of_tr<type_p, index_t>;*/

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::index_tg> :
        public type_i<nkr::positive::index_t>
    {
    public:
        using type_t    = nkr::positive::index_tg;
    };

}}

#include "nkr/positive/index_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<index_t>);
    static_assert(generic::positive_tr<const index_t>);
    static_assert(generic::positive_tr<volatile index_t>);
    static_assert(generic::positive_tr<const volatile index_t>);

    static_assert(generic::positive::any_tr<index_t>);
    static_assert(generic::positive::any_tr<const index_t>);
    static_assert(generic::positive::any_tr<volatile index_t>);
    static_assert(generic::positive::any_tr<const volatile index_t>);

    static_assert(generic::positive::integer_tr<index_t>);
    static_assert(generic::positive::integer_tr<const index_t>);
    static_assert(generic::positive::integer_tr<volatile index_t>);
    static_assert(generic::positive::integer_tr<const volatile index_t>);

}}
