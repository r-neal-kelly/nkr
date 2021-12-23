/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/trait/positive_tr_def.h"
#include "nkr/trait/positive/any_tr_def.h"
#include "nkr/trait/positive/integer_tr_def.h"

#include "nkr/positive/integer_8_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<positive::integer_8_tg>::Is_Any()
        noexcept
    {
        return positive::integer_8_tr<other_p>;
    }

}}

namespace nkr { namespace positive {

    static_assert(trait::positive_tr<integer_8_t>);
    static_assert(trait::positive_tr<const integer_8_t>);
    static_assert(trait::positive_tr<volatile integer_8_t>);
    static_assert(trait::positive_tr<const volatile integer_8_t>);

    static_assert(trait::positive::any_tr<integer_8_t>);
    static_assert(trait::positive::any_tr<const integer_8_t>);
    static_assert(trait::positive::any_tr<volatile integer_8_t>);
    static_assert(trait::positive::any_tr<const volatile integer_8_t>);

    static_assert(trait::positive::integer_tr<integer_8_t>);
    static_assert(trait::positive::integer_tr<const integer_8_t>);
    static_assert(trait::positive::integer_tr<volatile integer_8_t>);
    static_assert(trait::positive::integer_tr<const volatile integer_8_t>);

}}
