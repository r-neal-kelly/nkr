/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/template_traits_i_dec.h"
#include "nkr/interface/type_i_dec.h"
#include "nkr/interface/type_traits_i_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    concept non_type_i =
        !type_i<type_p>;

}}

namespace nkr { namespace interface {

    struct                      non_type_tg     {};
    template <typename> struct  non_type_ttg    {};

    template <>
    class type_traits_i<non_type_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any();
    };

    template <>
    class template_traits_i<non_type_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = non_type_tg;

    public:
        static constexpr cpp::bool_t    Is_Implemented();
    };

}}
