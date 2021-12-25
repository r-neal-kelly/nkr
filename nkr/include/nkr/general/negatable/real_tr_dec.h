/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/negatable/any_tr_dec.h"

namespace nkr { namespace general { namespace negatable {

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
    class type_i<general::negatable::real_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<general::negatable::real_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = general::negatable::real_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/general/negatable/real_tr_dec_def.h"
