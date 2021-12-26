/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace generic {

    struct  type_tg     {};

    template <typename>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        cpp::type_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<generic::type_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<generic::type_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = generic::type_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/generic/type_tr_dec_def.h"
