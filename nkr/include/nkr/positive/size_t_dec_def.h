/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_6108a6a2_4c38_4825_af64_d8093aa80034
#define nkr_INCLUDE_GUARD_6108a6a2_4c38_4825_af64_d8093aa80034

#include "nkr/positive/size_t_dec.h"

namespace nkr { namespace positive { namespace size_t$ {

    template <nkr::cpp::is_any_tr<nkr::positive::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::positive::size_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::positive::size_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::positive::size_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
