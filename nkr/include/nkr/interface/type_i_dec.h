/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/trait/constructor/defaultable_tr_dec.h"

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::type_t;
        typename type_p::of_t;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::template Is_Any<nkr::none::type_t>() }    -> cpp::is_tr<boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !trait::constructor::defaultable_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

    struct  type_tg     {};

    template <typename type_p>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        cpp::is_any_tr<type_p, type_i<typename type_p::type_t>> &&
        $type_i::aliases_i<type_p> &&
        $type_i::static_constexpr_functions_i<type_p> &&
        $type_i::objects_i<type_p>;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class type_i
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

#include "nkr/interface/type_i_dec_def.h"

namespace nkr { namespace interface {

    static_assert(type_tr<type_i<positive::integer_t>>);
    static_assert(type_tr<type_i<const positive::integer_t>>);
    static_assert(type_tr<type_i<volatile positive::integer_t>>);
    static_assert(type_tr<type_i<const volatile positive::integer_t>>);

}}
