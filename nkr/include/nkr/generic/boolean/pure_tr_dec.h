/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/boolean/impure_tr_dec.h"

namespace nkr { namespace generic { namespace boolean {

    struct  pure_tg     {};

    template <typename>
    struct  pure_ttg    {};

    template <typename type_p>
    concept pure_tr =
        any_tr<type_p> &&
        !impure_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::boolean::pure_tg>
    {
    public:
        using type_t    = nkr::generic::boolean::pure_tg;
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
    class template_i<nkr::generic::boolean::pure_ttg>
    {
    public:
        template <typename of_p>
        using of_t  = nkr::generic::boolean::pure_tg;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/boolean/pure_tr_dec_def.h"
