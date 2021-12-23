/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/trait/none_tr_def.h"
#include "nkr/trait/none/any_tr_def.h"

#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<none::type_tg>::Is_Any()
        noexcept
    {
        return none::type_tr<other_p>;
    }

}}

namespace nkr { namespace none {

    static_assert(trait::none_tr<type_t>);
    static_assert(trait::none_tr<const type_t>);
    static_assert(trait::none_tr<volatile type_t>);
    static_assert(trait::none_tr<const volatile type_t>);

    static_assert(trait::none::any_tr<type_t>);
    static_assert(trait::none::any_tr<const type_t>);
    static_assert(trait::none::any_tr<volatile type_t>);
    static_assert(trait::none::any_tr<const volatile type_t>);

}}
