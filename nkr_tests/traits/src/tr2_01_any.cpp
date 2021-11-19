/*
    Copyright 2021 r-neal-kelly
*/

#include "tr2.h"

namespace nkr { namespace traits {

    template <>
    class assert_t<any_tg>
    {
    public:
        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is()
        {
            if constexpr (std_array_tr<subject_p>) {
                if constexpr (tr0<of_p, any_tg>) {
                    static_assert(tr2<subject_p,
                                  any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                }
            } else {
                static_assert(any_non_qualified_tr<subject_p>);

                static_assert(tr2<subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                static_assert(tr2<const subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                static_assert(tr2<volatile subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                static_assert(tr2<const volatile subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            }
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is_Opposite()
        {
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is()
        {
            if constexpr (std_array_tr<subject_p>) {
                static_assert(!tr2<subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            } else {
                static_assert(any_non_qualified_tr<subject_p>);

                static_assert(!tr2<subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                static_assert(!tr2<const subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                static_assert(!tr2<volatile subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                static_assert(!tr2<const volatile subject_p,
                              any_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            }
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is_Opposite()
        {
        }
    };

    TEST_SUITE("any_tg")
    {
        TEST_SUITE("of_any_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_non_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_non_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_any_non_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_non_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_const_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_non_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should not allow any container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_not_any_non_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_tg")
        {
            TEST_CASE_TEMPLATE("should just allow any container of a matching type with the matching qualification", type_p, nkr_JUST_TYPES)
            {
                static_assert(tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should not allow any container of a matching type with a non-matching qualification", type_p, nkr_JUST_TYPES)
            {
                static_assert(!tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);

                static_assert(!tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);

                static_assert(!tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_TYPES)
            {
                static_assert(!tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(!tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(!tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(!tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, type_p>);

                static_assert(!tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);

                static_assert(!tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);

                static_assert(!tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_TYPES)
            {
                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, type_p>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, type_p>);

                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);

                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);

                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
            }
        }

        TEST_SUITE("of_just_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should just allow any container of a matching non-qualified type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any other matching type", type_p, nkr_NOT_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_just_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_non_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_const_tg")
        {
            TEST_CASE_TEMPLATE("should just allow any container of a matching const type", type_p, nkr_JUST_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any other matching type", type_p, nkr_NOT_JUST_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_just_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just allow any container of a matching volatile type", type_p, nkr_JUST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any other matching type", type_p, nkr_NOT_JUST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_just_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_const_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just allow any container of a matching const volatile type", type_p, nkr_JUST_CONST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_const_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any other matching type", type_p, nkr_NOT_JUST_CONST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_const_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<false, any_tg, of_just_const_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_const_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_not_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow any container of a matching type with the matching qualification", type_p, nkr_JUST_TYPES)
            {
                static_assert(!tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(!tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(!tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(!tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
            }

            TEST_CASE_TEMPLATE("should allow any container of a matching type with a non-matching qualification", type_p, nkr_JUST_TYPES)
            {
                static_assert(tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);

                static_assert(tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);

                static_assert(tr2<value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(tr2<const value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(tr2<volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(tr2<const volatile value_template_t<type_p>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_TYPES)
            {
                static_assert(tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, type_p>);

                static_assert(tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);

                static_assert(tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);

                static_assert(tr2<value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(tr2<const value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(tr2<volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(tr2<const volatile value_template_t<non_match_t>,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_TYPES)
            {
                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, type_p>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, type_p>);

                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_a_t>);

                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_b_t>);

                static_assert(!tr2<non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
                static_assert(!tr2<const volatile non_match_t,
                              any_tg, value_template_t, of_just_not_tg, typename other_qualifications_of_tmpl<type_p>::type_c_t>);
            }
        }

        TEST_SUITE("of_just_not_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow any container of a matching non-qualified type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_not_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any other matching type", type_p, nkr_NOT_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_not_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_just_not_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_not_non_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_not_const_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow any container of a matching const type", type_p, nkr_JUST_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_not_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any other matching type", type_p, nkr_NOT_JUST_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_not_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_just_not_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_not_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_not_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow any container of a matching volatile type", type_p, nkr_JUST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_not_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any other matching type", type_p, nkr_NOT_JUST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_not_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_just_not_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_not_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_just_not_const_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should just not allow any container of a matching const volatile type", type_p, nkr_JUST_CONST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<false, any_tg, of_just_not_const_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any other matching type", type_p, nkr_NOT_JUST_CONST_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, any_tg, of_just_not_const_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any container of any non-matching type", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, any_tg, of_just_not_const_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<false, any_tg, of_just_not_const_volatile_tg, type_p>();
            }
        }
    }

}}
