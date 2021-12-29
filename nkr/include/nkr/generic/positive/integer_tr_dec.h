/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/positive/any_tr_dec.h"

namespace nkr { namespace generic { namespace positive {

    struct  integer_tg  {};

    template <typename>
    struct  integer_ttg {};

    template <typename type_p>
    concept integer_tr =
        any_tr<type_p> &&
        cpp::integer_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::generic::positive::integer_tg>
    {
    public:
        using type_t    = nkr::generic::positive::integer_tg;
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
    class template_i<nkr::generic::positive::integer_ttg>
    {
    public:
        template <typename of_p>
        using of_t  = nkr::generic::positive::integer_tg;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

}}

#include "nkr/generic/positive/integer_tr_dec_def.h"
