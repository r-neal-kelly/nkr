/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/generic/negatable/any_tr_dec.h"

namespace nkr { namespace generic { namespace negatable {

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
    class type_i<generic::negatable::integer_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<generic::negatable::integer_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = generic::negatable::integer_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/generic/negatable/integer_tr_dec_def.h"
