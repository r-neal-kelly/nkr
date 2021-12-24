/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/trait/array_tr_dec.h"
#include "nkr/trait/array/any_tr_dec.h"

namespace nkr { namespace array {

    struct                      cpp_tg  {};
    template <typename> struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        cpp::array_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<array::cpp_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <array::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<array::cpp_tg>
    {
    public:
        using of_t  = cpp::array_unit_t<type_p>;
    };

    template <>
    class template_i<array::cpp_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = array::cpp_t<of_p, 1>;

    public:
        static constexpr boolean::cpp_t Is_Implemented() noexcept;
    };

    template <>
    class template_i<array::cpp_t> :
        public template_i<array::cpp_ttg>
    {
    public:
    };

}}

#include "nkr/array/cpp_t_dec_def.h"

namespace nkr { namespace array {

    static_assert(trait::array_tr<cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array_tr<const cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array_tr<volatile cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array_tr<const volatile cpp_t<positive::integer_t, 1>>);

    static_assert(trait::array::any_tr<cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array::any_tr<const cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array::any_tr<volatile cpp_t<positive::integer_t, 1>>);
    static_assert(trait::array::any_tr<const volatile cpp_t<positive::integer_t, 1>>);

}}
