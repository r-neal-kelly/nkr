/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_t_dec.h"

#include "nkr/trait/positive_tr_dec.h"
#include "nkr/trait/positive/any_tr_dec.h"
#include "nkr/trait/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  count_tg    {};

    template <typename type_p>
    concept count_tr =
        cpp::is_any_tr<type_p, count_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<positive::count_tg> :
        public type_i<positive::count_t>
    {
    public:
    };

}}

#include "nkr/positive/count_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<count_t>);
    static_assert(trait::positive_tr<const count_t>);
    static_assert(trait::positive_tr<volatile count_t>);
    static_assert(trait::positive_tr<const volatile count_t>);

    static_assert(trait::positive::any_tr<count_t>);
    static_assert(trait::positive::any_tr<const count_t>);
    static_assert(trait::positive::any_tr<volatile count_t>);
    static_assert(trait::positive::any_tr<const volatile count_t>);

    static_assert(trait::positive::integer_tr<count_t>);
    static_assert(trait::positive::integer_tr<const count_t>);
    static_assert(trait::positive::integer_tr<volatile count_t>);
    static_assert(trait::positive::integer_tr<const volatile count_t>);

}}
