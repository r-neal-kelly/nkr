/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

namespace nkr { namespace generic { namespace pointer {

    struct  any_tg  {};

    template <typename>
    struct  any_ttg {};

    template <typename type_p>
    concept any_tr =
        cpp::pointer_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<generic::pointer::any_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <>
    class template_i<generic::pointer::any_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = generic::pointer::any_tg;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

}}

#include "nkr/generic/pointer/any_tr_dec_def.h"
