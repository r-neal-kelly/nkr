/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace generic { namespace pointer {

    struct  any_tg  {};

    template <typename>
    struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        cpp::pointer_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::pointer::any_tg>
    {
    public:
        using type_t    = nkr::generic::pointer::any_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::generic::pointer::any_ttg>
    {
    public:
        template <typename inner_p>
        using of_t  = nkr::generic::pointer::any_tg;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/pointer/any_tr_dec_def.h"
