/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_19937_32_t$ {

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}
