/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b957e8c5_bde6_471d_9d3b_30c6c42ac66b
#define nkr_INCLUDE_GUARD_b957e8c5_bde6_471d_9d3b_30c6c42ac66b

#include "nkr/boolean/cpp_t_dec.h"

namespace nkr { namespace boolean { namespace cpp_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::boolean::cpp_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::boolean::cpp_tg>;
    }

    template <nkr::boolean::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::boolean::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::boolean::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::boolean::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::boolean::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::boolean::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace boolean { namespace cpp_t$ {

    template <nkr::boolean::cpp_tr type_p>
    inline constexpr none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}

namespace nkr { namespace boolean { namespace cpp_t$ {

    template <nkr::boolean::cpp_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<value_t>();
    }

    template <nkr::boolean::cpp_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<value_t>();
    }

    template <nkr::boolean::cpp_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::number_t
        randomness_distributor_uniform_i_sp<type_p>::To_Number(value_t value)
        noexcept
    {
        return static_cast<number_t>(value);
    }

    template <nkr::boolean::cpp_tr type_p>
    inline constexpr randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return static_cast<value_t>(number);
    }

}}}

#endif
