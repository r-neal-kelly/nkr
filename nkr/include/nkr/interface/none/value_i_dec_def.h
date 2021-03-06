/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_79dff24d_ec80_4c17_8109_4f58f74271fc
#define nkr_INCLUDE_GUARD_79dff24d_ec80_4c17_8109_4f58f74271fc

#include "nkr/interface/none/value_i_dec.h"

namespace nkr { namespace interface { namespace none { namespace value_i$ {

    template <nkr::cpp::is_any_tr<example_t> type_p>
    inline constexpr example_value_i_sp<type_p>::value_t
        example_value_i_sp<type_p>::Value()
        noexcept
    {
        return value_t();
    }

}}}}

namespace nkr { namespace interface { namespace none { namespace value_i$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::interface::none::value_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::interface::none::value_tg>;
    }

    template <nkr::interface::none::value_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::none::value_i$::Is_Any_General<other_p>();
    }

    template <nkr::interface::none::value_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::interface::none::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::interface::none::value_i$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::interface::none::value_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
