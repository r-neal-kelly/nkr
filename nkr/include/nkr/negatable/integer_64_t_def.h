/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/trait/negatable_tr_def.h"
#include "nkr/trait/negatable/any_tr_def.h"
#include "nkr/trait/negatable/integer_tr_def.h"

#include "nkr/negatable/integer_64_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<negatable::integer_64_tg>::Is_Any()
        noexcept
    {
        return negatable::integer_64_tr<other_p>;
    }

}}

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<integer_64_t>);
    static_assert(trait::negatable_tr<const integer_64_t>);
    static_assert(trait::negatable_tr<volatile integer_64_t>);
    static_assert(trait::negatable_tr<const volatile integer_64_t>);

    static_assert(trait::negatable::any_tr<integer_64_t>);
    static_assert(trait::negatable::any_tr<const integer_64_t>);
    static_assert(trait::negatable::any_tr<volatile integer_64_t>);
    static_assert(trait::negatable::any_tr<const volatile integer_64_t>);

    static_assert(trait::negatable::integer_tr<integer_64_t>);
    static_assert(trait::negatable::integer_tr<const integer_64_t>);
    static_assert(trait::negatable::integer_tr<volatile integer_64_t>);
    static_assert(trait::negatable::integer_tr<const volatile integer_64_t>);

}}
