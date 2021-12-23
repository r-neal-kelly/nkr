/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/trait/pointer_tr_dec.h"
#include "nkr/trait/pointer/any_tr_dec.h"

namespace nkr { namespace pointer {

    struct                      cpp_tg  {};
    template <typename> struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        cpp::pointer_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<pointer::cpp_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <pointer::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<pointer::cpp_tg>
    {
    public:
        using of_t  = cpp::pointer_unit_t<type_p>;
    };

    template <>
    class template_i<pointer::cpp_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = pointer::cpp_t<of_p>;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

    template <>
    class template_i<pointer::cpp_t> :
        public template_i<pointer::cpp_ttg>
    {
    public:
    };

}}
