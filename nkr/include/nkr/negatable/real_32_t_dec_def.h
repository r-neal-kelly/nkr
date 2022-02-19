/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/negatable/real_32_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::negatable::real_32_tg>::Is_Any()
        noexcept
    {
        return nkr::negatable::real_32_tr<other_p>;
    }

}}

namespace nkr { namespace negatable { namespace $real_32_t {

    template <nkr::negatable::real_32_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}

namespace nkr { namespace negatable { namespace $real_32_t {

    template <nkr::negatable::real_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<value_t>();
    }

    template <nkr::negatable::real_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<value_t>();
    }

    template <nkr::negatable::real_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::number_t
        randomness_distributor_uniform_i_sp<type_p>::To_Number(value_t value)
        noexcept
    {
        return value;
    }

    template <nkr::negatable::real_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return number;
    }

}}}
