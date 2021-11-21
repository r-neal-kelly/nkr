/*
    Copyright 2021 r-neal-kelly
*/

#include "tr2.h"

namespace nkr { namespace traits {

    template <>
    class assert_t<not_any_qualified_tg>
    {
    public:
        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is()
        {
            if constexpr (std_array_tr<subject_p>) {
                if constexpr (tr0<of_p, not_any_qualified_tg>) {
                    static_assert(tr2<subject_p,
                                  not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
                }
            } else {
                static_assert(any_non_qualified_tr<subject_p>);

                static_assert(tr2<subject_p,
                              not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            }
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Is_Opposite()
        {
            static_assert(any_non_qualified_tr<subject_p>);
            static_assert(!std_array_tr<subject_p>);

            static_assert(tr2<const subject_p,
                          not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(tr2<volatile subject_p,
                          not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(tr2<const volatile subject_p,
                          not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is()
        {
            if constexpr (std_array_tr<subject_p>) {
                static_assert(!tr2<subject_p,
                              not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            } else {
                static_assert(any_non_qualified_tr<subject_p>);

                static_assert(!tr2<subject_p,
                              not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            }
        }

        template <typename subject_p, template <typename ...> typename template_p, typename of_tag_p, typename of_p>
        static void_t constexpr Not_Is_Opposite()
        {
            static_assert(any_non_qualified_tr<subject_p>);
            static_assert(!std_array_tr<subject_p>);

            static_assert(!tr2<const subject_p,
                          not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(!tr2<volatile subject_p,
                          not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
            static_assert(!tr2<const volatile subject_p,
                          not_any_qualified_tg, template_p, of_tag_p, std::remove_cv_t<of_p>>);
        }
    };

    TEST_SUITE("not_any_qualified_tg")
    {
        TEST_SUITE("of_any_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_non_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_non_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any non-matching type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_any_non_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_non_qualified_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching non-qualified type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching qualified type", type_p, nkr_ANY_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_non_qualified_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_non_const_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching non-const type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching const type", type_p, nkr_ANY_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_NON_CONST_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_non_const_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_volatile_tg, type_p>();
            }
        }

        TEST_SUITE("of_not_any_non_volatile_tg")
        {
            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-qualified container of any non-matching type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Tagged_Container_Of_Non_Matching_Type<true, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any qualified container of any matching non-volatile type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<true, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any matching volatile type", type_p, nkr_ANY_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Matching_Type<false, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should not allow any qualified container of any non-matching type", type_p, nkr_ANY_NON_VOLATILE_TYPES)
            {
                Assert_Non_Tagged_Container_Of_Non_Matching_Type<false, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }

            TEST_CASE_TEMPLATE("should allow any non-container", type_p, nkr_JUST_NON_QUALIFIED_TYPES)
            {
                Assert_Non_Container<true, not_any_qualified_tg, of_not_any_non_volatile_tg, type_p>();
            }
        }
    }

}}