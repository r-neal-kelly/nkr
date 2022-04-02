/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_e1547d15_55f9_4d65_8876_76585f3d00c1
#define nkr_INCLUDE_GUARD_e1547d15_55f9_4d65_8876_76585f3d00c1

#include "nkr/negatable/word_t_dec.h"

namespace nkr { namespace negatable { namespace word_t$ {

    template <nkr::cpp::is_any_tr<nkr::negatable::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return
            nkr::negatable::word_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::negatable::word_tg>;
    }

    template <nkr::cpp::is_any_tr<nkr::negatable::word_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

#endif
