/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2891ce0f_cca2_4ffe_9679_717b6e1a651d
#define nkr_INCLUDE_GUARD_2891ce0f_cca2_4ffe_9679_717b6e1a651d

#include "nkr/pointer/cpp_t_dec.h"

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::pointer::cpp_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::pointer::cpp_tg>;
    }

    template <nkr::pointer::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::pointer::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::pointer::cpp_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::pointer::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::pointer::cpp_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::pointer::cpp_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
    inline constexpr typename none_value_i_sp<type_p>::value_t
        none_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
    inline constexpr typename randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<value_t>();
    }

    template <nkr::pointer::cpp_tr type_p>
    inline constexpr typename randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<value_t>();
    }

    template <nkr::pointer::cpp_tr type_p>
    inline constexpr typename randomness_distributor_uniform_i_sp<type_p>::number_t
        randomness_distributor_uniform_i_sp<type_p>::To_Number(value_t value)
        noexcept
    {
        static_assert(sizeof(value_t) == sizeof(number_t));

        return *reinterpret_cast<number_t*>(&value);
    }

    template <nkr::pointer::cpp_tr type_p>
    inline constexpr typename randomness_distributor_uniform_i_sp<type_p>::value_t
        randomness_distributor_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return *reinterpret_cast<value_t*>(&number);
    }

}}}

#endif
