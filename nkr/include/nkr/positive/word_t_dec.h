/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/positive/integer_t_dec.h"

namespace nkr { namespace positive {

    struct  word_tg { class tag; };

    template <typename type_p>
    concept word_tr =
        nkr::cpp::is_any_tr<type_p, word_t> ||
        (nkr::cpp::positive_integer_tr<type_p> && sizeof(type_p) == sizeof(word_t));

}}

namespace nkr { namespace positive { namespace $word_t {

    template <nkr::cpp::is_any_tr<nkr::positive::word_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::positive::word_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::positive::$word_t::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/positive/word_t_dec_def.h"
