/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_8_t_dec.h"
#include "nkr/positive/integer_16_t_dec.h"
#include "nkr/positive/integer_32_t_dec.h"
#include "nkr/positive/integer_64_t_dec.h"

#include "nkr/generic/positive_tr_dec.h"
#include "nkr/generic/positive/any_tr_dec.h"
#include "nkr/generic/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    /*using   integer_t =
        nkr::cpp::positive::integer_t;*/

    struct  integer_tg  {};

    template <typename type_p>
    concept integer_tr =
        nkr::cpp::is_any_tr<type_p, integer_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_t));

    template <integer_t value_p>
    using   integer_c =
        nkr::cpp::constant_t<integer_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::integer_tg> :
        public type_i<nkr::positive::integer_t>
    {
    public:
        using type_t    = nkr::positive::integer_tg;
    };

}}

#include "nkr/positive/integer_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<integer_t>);
    static_assert(generic::positive_tr<const integer_t>);
    static_assert(generic::positive_tr<volatile integer_t>);
    static_assert(generic::positive_tr<const volatile integer_t>);

    static_assert(generic::positive::any_tr<integer_t>);
    static_assert(generic::positive::any_tr<const integer_t>);
    static_assert(generic::positive::any_tr<volatile integer_t>);
    static_assert(generic::positive::any_tr<const volatile integer_t>);

    static_assert(generic::positive::integer_tr<integer_t>);
    static_assert(generic::positive::integer_tr<const integer_t>);
    static_assert(generic::positive::integer_tr<volatile integer_t>);
    static_assert(generic::positive::integer_tr<const volatile integer_t>);

}}
