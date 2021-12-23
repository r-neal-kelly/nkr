/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/trait/pointer_tr_def.h"
#include "nkr/trait/pointer/any_tr_def.h"

#include "nkr/pointer/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<pointer::cpp_tg>::Is_Any()
        noexcept
    {
        return pointer::cpp_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<pointer::cpp_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}

namespace nkr { namespace pointer {

    static_assert(trait::pointer_tr<cpp_t<positive::integer_t>>);
    static_assert(trait::pointer_tr<const cpp_t<positive::integer_t>>);
    static_assert(trait::pointer_tr<volatile cpp_t<positive::integer_t>>);
    static_assert(trait::pointer_tr<const volatile cpp_t<positive::integer_t>>);

    static_assert(trait::pointer::any_tr<cpp_t<positive::integer_t>>);
    static_assert(trait::pointer::any_tr<const cpp_t<positive::integer_t>>);
    static_assert(trait::pointer::any_tr<volatile cpp_t<positive::integer_t>>);
    static_assert(trait::pointer::any_tr<const volatile cpp_t<positive::integer_t>>);

}}
