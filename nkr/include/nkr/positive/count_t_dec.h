/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_t_dec.h"

namespace nkr { namespace positive {

    struct  count_tg    { class tag; };

    template <typename type_p>
    concept count_tr =
        nkr::cpp::is_any_tr<type_p, count_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(count_t));

}}

namespace nkr { namespace positive { namespace $count_t {

    template <nkr::cpp::is_any_tr<nkr::positive::count_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::positive::count_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::positive::$count_t::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/positive/count_t_dec_def.h"
