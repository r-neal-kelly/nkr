/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"

namespace nkr { namespace interface { namespace none { namespace $value_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::type_t;
        tr1<typename type_p::type_t, just_non_qualified_tg, generic::type_tg>;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::Value() } -> cpp::is_just_non_qualified_tr<typename type_p::type_t>;
    };

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace none {

    template <typename type_p>
    class   value_i;

    struct  value_tg    {};

    template <typename type_p>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        cpp::is_any_tr<type_p, value_i<typename type_p::type_t>> &&
        $value_i::aliases_i<type_p> &&
        $value_i::static_constexpr_functions_i<type_p> &&
        $value_i::objects_i<type_p>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::none::value_tg>
    {
    public:
        using type_t    = nkr::interface::none::value_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::none::value_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::none::value_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::none::value_ttg>
    {
    public:
        template <typename inner_p>
        using of_t  = nkr::interface::none::value_i<inner_p>;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <>
    class template_i<nkr::interface::none::value_i> :
        public template_i<nkr::interface::none::value_ttg>
    {
    public:
    };

}}

namespace nkr { namespace interface { namespace none {

    template <tr1<just_non_qualified_tg, nkr::generic::implementing::constructor::default_tg> type_p>
    class value_i<type_p>
    {
    public:
        using type_t    = type_p;

    public:
        static constexpr type_t Value() noexcept;

    public:
        template <typename ...>
        constexpr value_i(...) noexcept = delete;
    };

}}}

#include "nkr/interface/none/value_i_dec_def.h"

namespace nkr { namespace interface { namespace none {

    static_assert(value_tr<value_i<positive::integer_t>>);
    static_assert(!value_tr<value_i<const positive::integer_t>>);
    static_assert(!value_tr<value_i<volatile positive::integer_t>>);
    static_assert(!value_tr<value_i<const volatile positive::integer_t>>);

}}}
