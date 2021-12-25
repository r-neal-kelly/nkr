/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace trait { namespace negatable {

    struct  any_tg  {};

    template <typename>
    struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        cpp::negatable_integer_tr<type_p> ||
        cpp::negatable_real_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::negatable::any_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<trait::negatable::any_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = trait::negatable::any_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/trait/negatable/any_tr_dec_def.h"
