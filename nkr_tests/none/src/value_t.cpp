/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/pointer/cpp_t.h"

#include "nkr/positive/integer_t.h"

#include "nkr/none/pointer_t.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr {

    TEST_CASE("temp")
    {
        none::value_t<positive::integer_t> none = none::value_t<positive::integer_t>();

        CHECK(static_cast<positive::integer_t>(none) == 0);

        positive::integer_t integer = none::value_t<positive::integer_t>();

        CHECK(integer == 0);
    }

    TEST_CASE("temp")
    {
        none::value_t<pointer::cpp_t<positive::integer_t>> none = none::value_t<pointer::cpp_t<positive::integer_t>>();

        CHECK(static_cast<pointer::cpp_t<positive::integer_t>>(none) == pointer::cpp_t<positive::integer_t>());
        CHECK(static_cast<pointer::cpp_t<positive::integer_t>>(none) == none::pointer_t());

        pointer::cpp_t<positive::integer_t> pointer = none::value_t<pointer::cpp_t<positive::integer_t>>();

        CHECK(pointer == pointer::cpp_t<positive::integer_t>());
        CHECK(pointer == none::pointer_t());
    }

    TEST_CASE("temp")
    {
        using integer_t = positive::integer_t;
        using none_t    = none::value_t<integer_t>;

        integer_t integer = none_t();

        CHECK(integer == 0);
        CHECK(integer == integer_t());
        CHECK(integer == none_t());
    }

    class non_none_default_t
    {
    public:
        static constexpr const positive::integer_t  NONE = 1;

    private:
        positive::integer_t value;

    public:
        /*constexpr non_none_default_t() :
            value(0)
        {
        }*/

        constexpr non_none_default_t(positive::integer_t value) :
            value(value)
        {
        }

        non_none_default_t(const non_none_default_t& other)                 = delete;
        non_none_default_t(non_none_default_t&& other) noexcept             = delete;

        non_none_default_t& operator =(const non_none_default_t& other)     = delete;
        non_none_default_t& operator =(non_none_default_t&& other) noexcept = delete;

    public:
        positive::integer_t Value() const
        {
            return this->value;
        }
    };

    namespace interface
    {
        namespace none {

            template <>
            class value_i<non_none_default_t>
            {
            public:
                using type_t    = non_none_default_t;

            public:
                static constexpr non_none_default_t
                    Value()
                    noexcept
                {
                    return 1;
                }

            public:
                template <typename ...>
                constexpr value_i(...) noexcept = delete;
            };

        }
    }

    static_assert(tr1<non_none_default_t, any_tg, non_none_default_t>);
    static_assert(tr2<none::value_t<non_none_default_t>, any_tg, none::value_ttg, of_any_tg, non_none_default_t>);

    TEST_CASE("should work as a tag for types that don't use none as a default value")
    {
        non_none_default_t non_none_default = none::value_t<non_none_default_t>();

        CHECK(non_none_default.Value() == non_none_default_t::NONE);
    }

    static_assert(nkr::interface::template_i<nkr::generic::implementing::interface::template_ttg>::Is_Any<nkr::none::value_t>());

}

// temp
#include "nkr/generic_template/implementing/type_parameter_list/default_tr.h"

namespace nkr {

    template <typename type_p = positive::integer_t>
    class template_a_t
    {
    public:
    };

    template <typename type_p>
    class template_b_t
    {
    public:
    };

    static_assert(nkr::generic_template::implementing::type_parameter_list::default_tr<template_a_t>);
    static_assert(!nkr::generic_template::implementing::type_parameter_list::default_tr<template_b_t>);

    template <typename type_p>
    concept is_any_integral_constant_tr =
        cpp::is_any_tr<type_p, std::integral_constant<typename type_p::value_type, type_p::value>>;

    //template <is_any_integral_constant_tr type_p> /// the trait that tests equality uses nkr::none::type_t, which doesn't satisfy the constraint. we need a default_t for the template_i I think.
    template <typename type_p>
    class hard_to_instantiate_t
    {
    public:
        using of_t  = type_p;
    };
    static_assert(cpp::is_tr<nkr::interface::type_i<hard_to_instantiate_t<int>>::of_t, int>);
    static_assert(nkr::generic::implementing::interface::template_tr<hard_to_instantiate_t>);
    static_assert(cpp::is_tr<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>, nkr::interface::template_i<hard_to_instantiate_t>::type_t<std::integral_constant<positive::integer_8_t, 1>>>);
    static_assert(cpp::is_any_tr<nkr::interface::type_i<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>>::of_t, std::integral_constant<positive::integer_8_t, 1>>);

    hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>> hard_to_instantiate;
    static_assert(nkr::interface::type_i<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>>::Is_Any<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>>());
    static_assert(!nkr::interface::type_i<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>>::Is_Any<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 2>>>());
    static_assert(!nkr::interface::type_i<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>>::Is_Any<hard_to_instantiate_t<std::integral_constant<positive::integer_16_t, 1>>>());
    static_assert(nkr::tr1<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>,
                  any_tg, hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>>);
    /*static_assert(nkr::tr2<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>,
                  any_tg, hard_to_instantiate_t, of_any_tg, std::integral_constant<positive::integer_8_t, 1>>);*/ // just results in false because we haven't properly defined a template_i for this template

    template <positive::integer_8_t value_p = 0>
    class easy_to_instantiate_t
    {
    public:
    };

    easy_to_instantiate_t<1> easy_to_instantiate;
    static_assert(nkr::interface::type_i<easy_to_instantiate_t<1>>::Is_Any<easy_to_instantiate_t<1>>());
    static_assert(!nkr::interface::type_i<easy_to_instantiate_t<1>>::Is_Any<easy_to_instantiate_t<2>>());
    static_assert(nkr::tr1<easy_to_instantiate_t<1>,
                  any_tg, easy_to_instantiate_t<1>>);
    /*static_assert(nkr::tr2<easy_to_instantiate_t<1>,
                  any_tg, easy_to_instantiate_t, of_any_tg, nkr::none::type_t>);*/ // can't compile because the template has a value_parameter

    template <typename type_p>
    class test_t
    {
    public:
        template <typename type_p>
        using template_t    = test_t<type_p>;
        using self_t        = test_t;
        using of_t          = type_p;
    };

    static_assert(cpp::is_tr<test_t<positive::integer_t>, test_t<positive::integer_t>::template_t<positive::integer_t>>);

}
//
