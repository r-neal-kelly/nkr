/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace none {

    struct  type_tg { class tag; };

    template <typename type_p>
    concept type_tr =
        nkr::cpp::is_any_tr<type_p, type_t>;

}}

namespace nkr { namespace none { namespace $type_t {

    template <nkr::none::type_tr type_p>
    class type_i_type_sp
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
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::none::type_tg> type_p>
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

    template <nkr::none::type_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::none::$type_t::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::none::type_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::none::$type_t::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/none/type_t_dec_def.h"
