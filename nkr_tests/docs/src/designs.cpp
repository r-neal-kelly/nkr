/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/cpp.h"
#include "nkr/interface/type_i.h"
#include "nkr/namespaces.h"
#include "nkr/pointer/cpp_t.h"

#include "doctest.h"

// Label Postfixes
TEST_SUITE("")
{
    // [_b516dddc_3630_470a_acf5_f070b2d4ffd1]
    // "_t" is for "type"
    class example_t
    {
    public:
    };

    // "_tr" is for "trait"
    template <typename type_p>
    concept example_tr =
        true;

    // "_i" is for "interface"
    template <typename type_p>
    class example_i
    {
    public:
    };
    // [_b516dddc_3630_470a_acf5_f070b2d4ffd1]
}

TEST_SUITE("")
{
    // [_d77d72c6_49d4_48d5_8799_655eef4bdebb]
    // "_p" is for "parameter"
    template <typename parameter_p>
    class example_t
    {
    public:
        using parameter_t   = parameter_p;
    };
    // [_d77d72c6_49d4_48d5_8799_655eef4bdebb]
}

TEST_SUITE("")
{
    // [_d4386f68_d330_40bb_8659_4d3d81ca6a2c]
    using namespace nkr;

    // a template type is frequently the primary entity in a relationship
    template <typename type_p>
    class entity_t
    {
    public:
    };

    // this "tag" can represent an instantiation of the primary entity
    struct entity_tg    {};

    // whereas this "template tag" can represent the template itself
    template <typename>
    struct entity_ttg   {};

    // a "trait" can be used to constrain to an instantiated type
    template <typename type_p>
    concept entity_tr =
        true;

    // and a "template trait" to constrain to the template proper
    template <template <typename ...> typename template_p>
    concept entity_ttr =
        true;
    // [_d4386f68_d330_40bb_8659_4d3d81ca6a2c]
}

TEST_SUITE("")
{
    // [_78f65ebc_ee89_4eb9_b7bf_eca7bf552002]
    using namespace nkr;

    // "_t" is not for "template"!
    template <typename type_p>
    class template_t
    {
    public:
    };

    // "_t" is for "type", as in "instantiated type".
    using instantiated_type_t = template_t<int>;
    // [_78f65ebc_ee89_4eb9_b7bf_eca7bf552002]
}

TEST_SUITE("")
{
    // [_4af78359_e062_45a4_b14c_f59533520b0b]
    using namespace nkr;

    // "_tttg" for "template of template of type tag"
    template <template <template <typename ...> typename ...> typename template_template_p>
    struct  entity_tttg {};

    // "_tttr" for "template of template of type trait"
    template <template <template <typename ...> typename ...> typename template_template_p>
    concept entity_tttr =
        true;
    // [_4af78359_e062_45a4_b14c_f59533520b0b]
}

// [_dda6b4f4_9596_4713_8d31_f48990e0c898]
    // The non-postfix header pulls in everything but the "_dox" below. This is what you would normally use in your code.
    #include "nkr/pointer/cpp_t.h"

    // "_dec" provides the declarations of entities contained in this header-group. The go-to file to know what is available.
    #include "nkr/pointer/cpp_t_dec.h"

    // "_dec_def" defines the constexpr and other meta entities of "_dec". A helpful technical distinction from "_def".
    #include "nkr/pointer/cpp_t_dec_def.h"

    // "_def" defines the non-constexpr and non-meta entities of "_dec".
    #include "nkr/pointer/cpp_t_def.h"

    // "_dox" provides the doxygen comments used to create the documention for the entities of "_dec".
    #include "nkr/pointer/cpp_t_dox.h"
// [_dda6b4f4_9596_4713_8d31_f48990e0c898]

// Primary Inner Type
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
