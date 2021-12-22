/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace trait { namespace positive {

    struct                      any_tg  {};
    template <typename> struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        cpp::positive_integer_tr<type_p> ||
        cpp::positive_real_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::positive::any_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<trait::positive::any_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = trait::positive::any_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}
