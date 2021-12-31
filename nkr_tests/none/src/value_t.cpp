/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"

#include "nkr/pointer/cpp_t.h"

#include "nkr/positive/integer_t.h"

#include "nkr/none/pointer_t.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

// this is really a scrap book at the moment, but I'm prototyping and building some serious
// additions to the entire library. will clean up after it stabilizes enough, and a lot of these
// tests will go into their respective suites.

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
#include "nkr/generic_template/implementing/template_parameter_list/default_tr.h"
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
        using value_t   = type_p;
    };
    static_assert(cpp::is_tr<nkr::interface::type_i<hard_to_instantiate_t<int>>::of_t, int>);
    static_assert(nkr::generic::implementing::interface::template_tr<hard_to_instantiate_t>);
    static_assert(cpp::is_tr<hard_to_instantiate_t<std::integral_constant<positive::integer_8_t, 1>>, nkr::interface::template_i<hard_to_instantiate_t>::of_t<std::integral_constant<positive::integer_8_t, 1>>>);
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
        template <typename ...types_p>
        using template_t    = test_t<types_p...>;
        using self_t        = test_t;
        using of_t          = type_p;
    };
    static_assert(cpp::is_ttr<test_t, test_t>);
    static_assert(!cpp::is_ttr<test_t, test_t<none::type_t>::template template_t>);
    static_assert(cpp::is_any_ttr<test_t, test_t<none::type_t>::template template_t, none::type_t>);
    static_assert(cpp::is_tr<test_t<positive::integer_t>, test_t<positive::integer_t>::template_t<positive::integer_t>>);

    template <template <typename ...> typename template_p>
    concept test_ttr =
        cpp::is_any_ttr<template_p, test_t, interface::default_child_of_i<test_t>::child_t>;

    static_assert(test_ttr<test_t>);
    static_assert(test_ttr<test_t<none::type_t>::template template_t>);

    /////

    template <typename type_p>
    class type_t
    {
    public:
    };

    template <template <typename ...> typename template_p = type_t>
    class template_t
    {
    public:
    };

    static_assert(nkr::generic_template::implementing::template_parameter_list::default_tr<template_t>);


    ///

    using none_value_template_a_t = interface::template_i<none::value_t>;
    using none_value_template_b_t = interface::template_i<interface::template_i<none::value_t>::template_t>;
    static_assert(cpp::is_tr<none_value_template_a_t::template_t<none::type_t>, none_value_template_b_t::template_t<none::type_t>>);

    static_assert(cpp::is_tr<none::value_t<positive::integer_t>, interface::template_i<none::value_t>::template_t<positive::integer_t>>);
    static_assert(!cpp::is_tr<interface::template_i<none::value_t>, interface::template_i<interface::template_i<none::value_t>::template_t>>);
    static_assert(generic::implementing::interface::template_tr<interface::template_i<none::value_t>::template_t>);

}
//

//// temp
namespace nkr {

    namespace $testing_thing_t {

        using default_child_t   = positive::integer_t;

    }

    template <typename value_p>
    class testing_thing_t;

    template <template <typename ...> typename template_p>
    concept testing_thing_ttr =
        cpp::is_any_ttr<template_p, testing_thing_t, $testing_thing_t::default_child_t>;

    template <cpp::type_tr value_p>
    class testing_thing_t<value_p>
    {
    public:
        template <typename ...types_p>
        using template_t    = testing_thing_t<types_p...>;
        using self_t        = testing_thing_t;
        using value_t       = value_p;
    };

    namespace interface {

        template <template <typename ...> typename template_p>
            requires testing_thing_ttr<template_p>
        class default_child_of_i<template_p>
        {
        public:
            using child_t   = $testing_thing_t::default_child_t;

        public:
            template <typename ...>
            constexpr default_child_of_i(...) noexcept  = delete;
        };

    };

    static_assert(testing_thing_ttr<testing_thing_t>);
    static_assert(testing_thing_ttr<testing_thing_t<positive::integer_t>::template template_t>);


    //////

    using true_t = boolean::cpp_c<true>;
    using false_t = boolean::cpp_c<false>;
    static_assert(true_t::Value());
    static_assert(!false_t::Value());

    using real_tt = negatable::real_c<-64.5>;
    static_assert(real_tt::Value() == -64.5);

    static_assert(array::cpp_ttr<array::cpp_t>);
    static_assert(array::cpp_ttr<interface::template_i<array::cpp_ttg>::template template_t>);
    static_assert(generic::implementing::interface::template_tr<array::cpp_ttg>);

    using test_1_t = interface::template_i<array::cpp_ttg>::template template_t<positive::integer_t, positive::count_c<1>>;
    using test_2_t = array::cpp_t<positive::integer_t, positive::count_c<1>>;
    static_assert(cpp::is_tr<test_1_t, test_2_t>);
    constexpr test_1_t test_1 = { 1 };
    constexpr test_2_t test_2 = { 2 };
    static_assert(test_1[0] != test_2[0]);

}
////

#include "nkr/tuple/types_t.h"

namespace nkr {

    using tuple_t = tuple::types_t<positive::integer_t, negatable::integer_t, negatable::real_t>;

    static_assert(tuple::types_tr<tuple_t>);
    static_assert(!tuple::types_tr<positive::integer_t>);

    static_assert(cpp::is_tr<tuple_t::at_t<0>, positive::integer_t>);
    static_assert(cpp::is_tr<tuple_t::at_t<1>, negatable::integer_t>);
    static_assert(cpp::is_tr<tuple_t::at_t<2>, negatable::real_t>);

}
