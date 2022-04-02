/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_55088867_a449_4bb4_a20b_f51de1364a8b
#define nkr_INCLUDE_GUARD_55088867_a449_4bb4_a20b_f51de1364a8b

#include "nkr/cpp/randomness/distributor/uniform/integer_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace uniform { namespace integer_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::cpp::randomness::distributor::uniform::integer_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::cpp::randomness::distributor::uniform::integer_tg>;
    }

    template <nkr::cpp::randomness::distributor::uniform::integer_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::distributor::uniform::integer_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::randomness::distributor::uniform::integer_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::cpp::randomness::distributor::uniform::integer_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::uniform::integer_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}}}

#endif
