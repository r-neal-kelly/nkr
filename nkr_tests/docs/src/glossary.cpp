/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/constant/boolean/cpp_t.h"
#include "nkr/cpp.h"
#include "nkr/tuple/templates_t.h"
#include "nkr/tuple/types_t.h"

#include "doctest.h"

/* identity trait */

TEST_SUITE("")
{
    // [_54c5c7e1_91a3_4d5b_b41d_c158d3b4c573]
    class a_t
    {
    public:
    };

    // the "type indentity trait" for a_t
    template <typename type_p>
    concept a_tr =
        nkr::cpp::is_any_tr<type_p, a_t>;

    // should constrain to any qualification of a_t
    static_assert(a_tr<a_t> == true);
    static_assert(a_tr<const a_t> == true);
    static_assert(a_tr<volatile a_t> == true);
    static_assert(a_tr<const volatile a_t> == true);

    using alias_of_a_t = a_t;

    // and naturally any qualification of an alias of a_t
    static_assert(a_tr<alias_of_a_t> == true);
    static_assert(a_tr<const alias_of_a_t> == true);
    static_assert(a_tr<volatile alias_of_a_t> == true);
    static_assert(a_tr<const volatile alias_of_a_t> == true);

    class b_t
    {
    public:
    };

    // but never any qualification of any other type
    static_assert(a_tr<b_t> == false);
    static_assert(a_tr<const b_t> == false);
    static_assert(a_tr<volatile b_t> == false);
    static_assert(a_tr<const volatile b_t> == false);
    // [_54c5c7e1_91a3_4d5b_b41d_c158d3b4c573]
}

TEST_SUITE("")
{
    // [_fbae0c33_830c_4106_8c8d_bcbae9a82433]
    template <typename ...parameters_p>
    class a_t
    {
    public:
        using parameters_t = nkr::tuple::types_t<parameters_p...>;
    };

    // the "instantiated type indentity trait" for a_t
    template <typename type_p>
    concept a_tr =
        nkr::cpp::is_any_tr<type_p, typename type_p::parameters_t::template into_t<a_t>>;

    // should constrain to any qualification of an instantiated a_t
    static_assert(a_tr<a_t<>> == true);
    static_assert(a_tr<const a_t<>> == true);
    static_assert(a_tr<volatile a_t<>> == true);
    static_assert(a_tr<const volatile a_t<>> == true);

    template <typename ...parameters_p>
    using alias_of_a_t = a_t<parameters_p...>;

    // and naturally any qualification of an instantiated alias of a_t
    static_assert(a_tr<alias_of_a_t<>> == true);
    static_assert(a_tr<const alias_of_a_t<>> == true);
    static_assert(a_tr<volatile alias_of_a_t<>> == true);
    static_assert(a_tr<const volatile alias_of_a_t<>> == true);

    template <typename ...parameters_p>
    class b_t
    {
    public:
        using parameters_t = nkr::tuple::types_t<parameters_p...>;
    };

    // but never any qualification of any other type
    static_assert(a_tr<b_t<>> == false);
    static_assert(a_tr<const b_t<>> == false);
    static_assert(a_tr<volatile b_t<>> == false);
    static_assert(a_tr<const volatile b_t<>> == false);

    // the "template indentity trait" for a_t
    template <template <typename ...> typename template_p>
    concept a_ttr =
        nkr::cpp::is_any_ttr<template_p, a_t>;

    // should constrain to a_t
    static_assert(a_ttr<a_t> == true);

    // and any alias of a_t
    static_assert(a_ttr<alias_of_a_t> == true);

    // but never any other template
    static_assert(a_ttr<b_t> == false);
    // [_fbae0c33_830c_4106_8c8d_bcbae9a82433]
}

TEST_SUITE("")
{
    // [_7e0fe0cd_2eac_4f85_9539_4a1399492ab0]
    template <template <typename ...> typename ...parameters_p>
    class a_t
    {
    public:
        using parameters_t = nkr::tuple::templates_t<parameters_p...>;
    };

    // the "instantiated type indentity trait" for a_t
    template <typename type_p>
    concept a_tr =
        nkr::cpp::is_any_tr<type_p, typename type_p::parameters_t::template into_t<a_t>>;

    // should constrain to any qualification of an instantiated a_t
    static_assert(a_tr<a_t<>> == true);
    static_assert(a_tr<const a_t<>> == true);
    static_assert(a_tr<volatile a_t<>> == true);
    static_assert(a_tr<const volatile a_t<>> == true);

    template <template <typename ...> typename ...parameters_p>
    using alias_of_a_t = a_t<parameters_p...>;

    // and naturally any qualification of an instantiated alias of a_t
    static_assert(a_tr<alias_of_a_t<>> == true);
    static_assert(a_tr<const alias_of_a_t<>> == true);
    static_assert(a_tr<volatile alias_of_a_t<>> == true);
    static_assert(a_tr<const volatile alias_of_a_t<>> == true);

    template <template <typename ...> typename ...parameters_p>
    class b_t
    {
    public:
        using parameters_t = nkr::tuple::templates_t<parameters_p...>;
    };

    // but never any qualification of any other type
    static_assert(a_tr<b_t<>> == false);
    static_assert(a_tr<const b_t<>> == false);
    static_assert(a_tr<volatile b_t<>> == false);
    static_assert(a_tr<const volatile b_t<>> == false);

    // the "template template indentity trait" for a_t
    template <template <template <typename ...> typename ...> typename template_template_p>
    concept a_tttr =
        nkr::cpp::is_any_tttr<template_template_p, a_t>;

    // should constrain to a_t
    static_assert(a_tttr<a_t> == true);

    // and any alias of a_t
    static_assert(a_tttr<alias_of_a_t> == true);

    // but never any other template
    static_assert(a_tttr<b_t> == false);
    // [_7e0fe0cd_2eac_4f85_9539_4a1399492ab0]
}
