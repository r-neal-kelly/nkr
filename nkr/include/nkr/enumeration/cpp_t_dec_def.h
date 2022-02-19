/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/enumeration/cpp_t_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::enumeration::cpp_tg>::Is_Any()
        noexcept
    {
        return nkr::enumeration::cpp_tr<other_p>;
    }

}}

namespace nkr { namespace enumeration { namespace $cpp_t {

    template <nkr::enumeration::cpp_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        if constexpr (nkr::generic::implementing::tag::data::none_tr<value_t>) {
            return value_t::NONE_tg;
        } else {
            return value_t(~0);
        }
    }

}}}

namespace nkr { namespace enumeration { namespace $cpp_t {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return value_t::MIN_tg;
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return value_t::MAX_tg;
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::number_t
        randomness_distributor_uniform_i_sp<type_p>::To_Number(value_t value)
        noexcept
    {
        return static_cast<number_t>(value);
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return static_cast<value_t>(number);
    }

}}}
