/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/negatable/any_tr_dec.h"

namespace nkr { namespace generic { namespace negatable {

    struct  real_tg     {};

    template <typename>
    struct  real_ttg    {};

    template <typename type_p>
    concept real_tr =
        any_tr<type_p> &&
        cpp::real_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::negatable::real_tg>
    {
    public:
        using type_t    = nkr::generic::negatable::real_tg;
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
    class template_i<nkr::generic::negatable::real_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = nkr::generic::negatable::real_tg;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/negatable/real_tr_dec_def.h"
