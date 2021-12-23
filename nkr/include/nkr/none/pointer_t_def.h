/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_def.h"

#include "nkr/trait/none_tr_def.h"
#include "nkr/trait/none/any_tr_def.h"

#include "nkr/none/pointer_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<none::pointer_tg>::Is_Any()
        noexcept
    {
        return none::pointer_tr<other_p>;
    }

}}

namespace nkr { namespace none {

    static_assert(trait::none_tr<pointer_t>);
    static_assert(trait::none_tr<const pointer_t>);
    static_assert(trait::none_tr<volatile pointer_t>);
    static_assert(trait::none_tr<const volatile pointer_t>);

    static_assert(trait::none::any_tr<pointer_t>);
    static_assert(trait::none::any_tr<const pointer_t>);
    static_assert(trait::none::any_tr<volatile pointer_t>);
    static_assert(trait::none::any_tr<const volatile pointer_t>);

}}
