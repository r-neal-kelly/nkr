/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/positive/integer_32_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::positive::integer_32_tg>::Is_Any()
        noexcept
    {
        return nkr::positive::integer_32_tr<other_p>;
    }

}}

namespace nkr { namespace positive { namespace $integer_32_t {

    template <nkr::positive::integer_32_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}

namespace nkr { namespace positive { namespace $integer_32_t {

    template <nkr::positive::integer_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<value_t>();
    }

    template <nkr::positive::integer_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<value_t>();
    }

    template <nkr::positive::integer_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::number_t
        randomness_distributor_uniform_i_sp<type_p>::To_Number(value_t object)
        noexcept
    {
        return object;
    }

    template <nkr::positive::integer_32_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return number;
    }

}}}
