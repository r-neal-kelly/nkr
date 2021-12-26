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

    struct  size_tg {};

    template <typename type_p>
    concept size_tr =
        cpp::is_any_tr<type_p, size_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::positive::size_tg> :
        public type_i<nkr::positive::size_t>
    {
    public:
        using type_t    = nkr::positive::size_tg;
    };

}}

#include "nkr/positive/size_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(generic::positive_tr<size_t>);
    static_assert(generic::positive_tr<const size_t>);
    static_assert(generic::positive_tr<volatile size_t>);
    static_assert(generic::positive_tr<const volatile size_t>);

    static_assert(generic::positive::any_tr<size_t>);
    static_assert(generic::positive::any_tr<const size_t>);
    static_assert(generic::positive::any_tr<volatile size_t>);
    static_assert(generic::positive::any_tr<const volatile size_t>);

    static_assert(generic::positive::integer_tr<size_t>);
    static_assert(generic::positive::integer_tr<const size_t>);
    static_assert(generic::positive::integer_tr<volatile size_t>);
    static_assert(generic::positive::integer_tr<const volatile size_t>);

}}
