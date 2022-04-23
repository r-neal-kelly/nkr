/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_fd30857e_817c_4e8b_940a_fe49e0fa00fc
#define nkr_INCLUDE_GUARD_fd30857e_817c_4e8b_940a_fe49e0fa00fc

#include "nkr/enumeration/cpp_t_dec.h"

namespace nkr { namespace enumeration { namespace cpp_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::enumeration::cpp_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::enumeration::cpp_tg>;
    }

    template <nkr::enumeration::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::enumeration::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::enumeration::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::enumeration::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::enumeration::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::enumeration::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace enumeration { namespace cpp_t$ {

    template <nkr::enumeration::cpp_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        if constexpr (nkr::generic::implementing::label::none_tr<value_t>) {
            return value_t::NONE_lb;
        } else {
            return value_t(~0);
        }
    }

}}}

namespace nkr { namespace enumeration { namespace cpp_t$ {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return value_t::MIN_lb;
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return value_t::MAX_lb;
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

#endif
