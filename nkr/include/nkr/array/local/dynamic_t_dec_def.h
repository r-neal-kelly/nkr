/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_8fdaa008_a319_43f5_b411_0559c765926e
#define nkr_INCLUDE_GUARD_8fdaa008_a319_43f5_b411_0559c765926e

#include "nkr/array/local/dynamic_t_dec.h"

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::array::local::dynamic_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::array::local::dynamic_tg>;
    }

    template <nkr::array::local::dynamic_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::local::dynamic_t$::Is_Any_General<other_p>();
    }

    template <nkr::array::local::dynamic_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::array::local::dynamic_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::local::dynamic_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::array::local::dynamic_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

#endif
