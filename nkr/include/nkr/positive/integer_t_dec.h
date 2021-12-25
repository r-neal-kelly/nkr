/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/positive/integer_8_t_dec.h"
#include "nkr/positive/integer_16_t_dec.h"
#include "nkr/positive/integer_32_t_dec.h"
#include "nkr/positive/integer_64_t_dec.h"

#include "nkr/general/positive_tr_dec.h"
#include "nkr/general/positive/any_tr_dec.h"
#include "nkr/general/positive/integer_tr_dec.h"

namespace nkr { namespace positive {

    struct  integer_tg  {};

    template <typename type_p>
    concept integer_tr =
        cpp::is_any_tr<type_p, integer_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<positive::integer_tg> :
        public type_i<positive::integer_t>
    {
    public:
    };

}}

#include "nkr/positive/integer_t_dec_def.h"

namespace nkr { namespace positive {

    static_assert(general::positive_tr<integer_t>);
    static_assert(general::positive_tr<const integer_t>);
    static_assert(general::positive_tr<volatile integer_t>);
    static_assert(general::positive_tr<const volatile integer_t>);

    static_assert(general::positive::any_tr<integer_t>);
    static_assert(general::positive::any_tr<const integer_t>);
    static_assert(general::positive::any_tr<volatile integer_t>);
    static_assert(general::positive::any_tr<const volatile integer_t>);

    static_assert(general::positive::integer_tr<integer_t>);
    static_assert(general::positive::integer_tr<const integer_t>);
    static_assert(general::positive::integer_tr<volatile integer_t>);
    static_assert(general::positive::integer_tr<const volatile integer_t>);

}}