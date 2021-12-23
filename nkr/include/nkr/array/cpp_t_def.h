/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_def.h"

#include "nkr/trait/array_tr_def.h"
#include "nkr/trait/array/any_tr_def.h"

#include "nkr/array/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<array::cpp_tg>::Is_Any()
        noexcept
    {
        return array::cpp_tr<other_p>;
    }

    inline constexpr boolean::cpp_t
        template_i<array::cpp_ttg>::Is_Implemented()
        noexcept
    {
        return true;
    }

}}

namespace nkr { namespace array {

    static_assert(trait::array_tr<cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array_tr<const cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array_tr<volatile cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array_tr<const volatile cpp_t<positive::integer_t, 1>>);

    static_assert(trait::array::any_tr<cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array::any_tr<const cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array::any_tr<volatile cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array::any_tr<const volatile cpp_t<positive::integer_t, 1>>);

}}
