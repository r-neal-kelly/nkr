/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/interface/type_i_def.h"

#include "nkr/trait/boolean_tr_def.h"
#include "nkr/trait/boolean/any_tr_def.h"
#include "nkr/trait/boolean/impure_tr_def.h"

#include "nkr/boolean/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<boolean::cpp_tg>::Is_Any()
        noexcept
    {
        return boolean::cpp_tr<other_p>;
    }

}}

namespace nkr { namespace boolean {

    static_assert(trait::boolean_tr<cpp_t>);
    static_assert(trait::boolean_tr<const cpp_t>);
    static_assert(trait::boolean_tr<volatile cpp_t>);
    static_assert(trait::boolean_tr<const volatile cpp_t>);

    static_assert(trait::boolean::any_tr<cpp_t>);
    static_assert(trait::boolean::any_tr<const cpp_t>);
    static_assert(trait::boolean::any_tr<volatile cpp_t>);
    static_assert(trait::boolean::any_tr<const volatile cpp_t>);

    static_assert(trait::boolean::impure_tr<cpp_t>);
    static_assert(trait::boolean::impure_tr<const cpp_t>);
    static_assert(trait::boolean::impure_tr<volatile cpp_t>);
    static_assert(trait::boolean::impure_tr<const volatile cpp_t>);

}}
