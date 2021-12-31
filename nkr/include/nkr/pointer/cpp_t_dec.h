/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/pointer_tr_dec.h"
#include "nkr/generic/pointer/any_tr_dec.h"

namespace nkr { namespace pointer {

    struct  cpp_tg  {};

    template <typename>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        cpp::pointer_tr<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::pointer::cpp_tg>
    {
    public:
        using type_t    = nkr::pointer::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::pointer::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::pointer::cpp_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::pointer_unit_t<type_t>;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::pointer::cpp_ttg>
    {
    public:
        template <typename inner_p>
        using of_t  = nkr::pointer::cpp_t<inner_p>;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <>
    class template_i<nkr::pointer::cpp_t> :
        public template_i<nkr::pointer::cpp_ttg>
    {
    public:
    };

}}

#include "nkr/pointer/cpp_t_dec_def.h"

namespace nkr { namespace pointer {

    static_assert(generic::pointer_tr<cpp_t<positive::integer_t>>);
    static_assert(generic::pointer_tr<const cpp_t<positive::integer_t>>);
    static_assert(generic::pointer_tr<volatile cpp_t<positive::integer_t>>);
    static_assert(generic::pointer_tr<const volatile cpp_t<positive::integer_t>>);

    static_assert(generic::pointer::any_tr<cpp_t<positive::integer_t>>);
    static_assert(generic::pointer::any_tr<const cpp_t<positive::integer_t>>);
    static_assert(generic::pointer::any_tr<volatile cpp_t<positive::integer_t>>);
    static_assert(generic::pointer::any_tr<const volatile cpp_t<positive::integer_t>>);

}}
