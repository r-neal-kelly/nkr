/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/general/type_tr_dec.h"

namespace nkr { namespace general {

    struct  non_type_tg     {};

    template <typename>
    struct  non_type_ttg    {};

    template <typename type_p>
    concept non_type_tr =
        !type_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<general::non_type_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<general::non_type_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = general::non_type_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/general/non_type_tr_dec_def.h"
