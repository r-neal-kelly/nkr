/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/cpp.h"
#include "nkr/interface/type_i.h"
#include "nkr/namespaces.h"
#include "nkr/pointer/cpp_t.h"

#include "doctest.h"

// primary inner type
TEST_SUITE("")
{
    // [_71d0edc7_85b8_40e5_a79b_4d46a8ff2f08]
    using namespace nkr;

    template <typename type_p, typename ...maybe_more_types_p>
    class template_t
    {
    public:
        using type_t    = type_p;   // the primary inner type
    };
    // [_71d0edc7_85b8_40e5_a79b_4d46a8ff2f08]
}

TEST_SUITE("")
{
    // [_61c79cda_e67d_4202_b6de_3f7078ba5f7b]
    using namespace nkr;

    template <typename type_p, typename ...maybe_more_types_p>
    class template_t
    {
    public:
        using value_t   = type_p;   // does not use the parameter's name
    };
    // [_61c79cda_e67d_4202_b6de_3f7078ba5f7b]
}

TEST_SUITE("")
{
    // [_6dffcb91_cf58_4490_9cd2_e39762bab3f0]
    using namespace nkr;

    // we can use any nkr template as long as it has a primary inner type
    template <typename type_p>
    using template_t = nkr::pointer::cpp_t<type_p>;

    static_assert(tr<
                  template_t<long>,         // we provide a primary inner type of "long"
                  any_tg, tt<template_t>,
                  of_any_tg, t<long long>   // but we're looking for "long long", so it's false
    > == false);

    static_assert(tr<
                  template_t<long long>,    // we change it to "long long" to get true
                  any_tg, tt<template_t>,
                  of_any_tg, t<long long>
    > == true);
    // [_6dffcb91_cf58_4490_9cd2_e39762bab3f0]
}

TEST_SUITE("")
{
    // [_7c1eacd8_f30a_4dd8_80e7_c4e02c2b88a2]
    using namespace nkr;

    template <typename type_p>
    using template_t = nkr::pointer::cpp_t<type_p>;

    // here we give our example template a primary inner type of "int"
    using type_t = template_t<int>;

    using interface_of_type_t = nkr::interface::type_i<type_t>;

    // we can access the primary inner type with an alias contained in the interface
    using primary_inner_type_of_type_t = interface_of_type_t::of_t;

    // it should be equal to what we gave our template_t
    static_assert(nkr::cpp::is_tr<primary_inner_type_of_type_t, int>);

    using interface_of_interface_of_type_t = nkr::interface::type_i<interface_of_type_t>;

    // coincidentally, the interface itself has a primary inner type equal to type_t
    static_assert(nkr::cpp::is_tr<interface_of_interface_of_type_t::of_t, type_t>);
    // [_7c1eacd8_f30a_4dd8_80e7_c4e02c2b88a2]
}
