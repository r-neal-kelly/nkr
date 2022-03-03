/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/interface/randomness/distributor/uniform_i_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_uniform_i_sp<type_p>::value_t
        example_uniform_i_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<value_t>();
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_uniform_i_sp<type_p>::value_t
        example_uniform_i_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<value_t>();
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_uniform_i_sp<type_p>::number_t
        example_uniform_i_sp<type_p>::To_Number(value_t value)
        noexcept
    {
        return static_cast<number_t>(value);
    }

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_uniform_i_sp<type_p>::value_t
        example_uniform_i_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return static_cast<value_t>(number);
    }

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_tr {

    template <nkr::interface::randomness::distributor::uniform_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::randomness::distributor::uniform_tr<other_p>;
    }

    template <nkr::interface::randomness::distributor::uniform_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::distributor::uniform_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::randomness::distributor::uniform_tr<other_p>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::distributor::uniform_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::randomness::distributor::uniform_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::randomness::distributor::uniform_ttr<other_p>;
    }

}}
