/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace trait {

    struct                      type_tg     {};
    template <typename> struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        sizeof(type_p) > 0;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::type_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any() noexcept;
    };

    template <>
    class template_i<trait::type_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = trait::type_tg;

    public:
        static constexpr cpp::bool_t    Is_Implemented() noexcept;
    };

}}
