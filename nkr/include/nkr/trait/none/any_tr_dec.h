/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace trait { namespace none {

    struct                      any_tg  {};
    template <typename> struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        cpp::none_type_tr<type_p> ||
        cpp::none_pointer_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<trait::none::any_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<trait::none::any_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = trait::none::any_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}
