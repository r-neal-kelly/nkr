/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/boolean/pure_t.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/pure_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr {

    // potential problem.
    static_assert(nkr::generic::boolean_tr<nkr::positive::integer_t>);

    TEST_SUITE("nkr::boolean::pure_t")
    {
    #define nkr_TYPES(TYPE_QUALIFIER_p)         \
        TYPE_QUALIFIER_p nkr::boolean::pure_t   \

    #define nkr_JUST_NON_QUALIFIED  \
        nkr_TYPES(nkr_BLANK)        \

    #define nkr_JUST_CONST  \
        nkr_TYPES(const)    \

    #define nkr_JUST_VOLATILE   \
        nkr_TYPES(volatile)     \

    #define nkr_JUST_CONST_VOLATILE \
        nkr_TYPES(const volatile)   \

    #define nkr_ANY_QUALIFIED   \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_QUALIFIED   \
        nkr_JUST_NON_QUALIFIED      \

    #define nkr_ANY_CONST       \
        nkr_JUST_CONST,         \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_CONST   \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_VOLATILE       \

    #define nkr_ANY_VOLATILE    \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

    #define nkr_ANY_NON_VOLATILE    \
        nkr_JUST_NON_QUALIFIED,     \
        nkr_JUST_CONST              \

    #define nkr_ANY             \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE \

        TEST_SUITE("identity")
        {
            TEST_CASE_TEMPLATE("should satisfy the identity trait", pure_p, nkr_ANY)
            {
                static_assert(nkr::boolean::pure_tr<pure_p>);
            }
        }

        TEST_SUITE("generic")
        {
            // not sure why intellisense thinks some of these are false. they do properly compile.
            // it's something to do with having an == check in the concept requires section?
            static_assert(nkr::generic::boolean_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::boolean::any_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::any_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::boolean::pure_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::boolean::pure_tr<const volatile nkr::boolean::pure_t>);

            static_assert(nkr::generic::implementing::interface::none::value_tr<nkr::boolean::pure_t>);

            static_assert(nkr::generic::implementing::interface::type_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::implementing::interface::type_tr<nkr::boolean::pure_tg>);

            static_assert(nkr::generic::type_tr<nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<const nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<volatile nkr::boolean::pure_t>);
            static_assert(nkr::generic::type_tr<const volatile nkr::boolean::pure_t>);
        }

        TEST_SUITE("interface")
        {
            TEST_SUITE("nkr::interface::none::value_i")
            {
                static_assert(nkr::interface::none::value_i<nkr::boolean::pure_t>::Value() == false);

                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == false);
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::boolean::pure_t(false));
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());

                static_assert(false == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::boolean::pure_t(false) == nkr::none::value_t<nkr::boolean::pure_t>());
                static_assert(nkr::none::value_t<nkr::boolean::pure_t>() == nkr::none::value_t<nkr::boolean::pure_t>());
            }
        }

        TEST_SUITE("tr")
        {
            TEST_SUITE("tr1")
            {
                template <nkr::boolean::cpp_t _, typename subject_p, typename tag_p, typename ...objects_p>
                class tr1_tag_objects_tmpl;

                template <typename subject_p, typename tag_p, typename ...objects_p>
                class tr1_tag_objects_tmpl<false, subject_p, tag_p, objects_p...>
                {
                public:
                    static constexpr nkr::boolean::cpp_t
                        Is_True()
                        noexcept
                    {
                        return false;
                    }
                };

                template <typename subject_p, typename tag_p, typename last_object_p>
                class tr1_tag_objects_tmpl<true, subject_p, tag_p, last_object_p>
                {
                public:
                    static constexpr nkr::boolean::cpp_t
                        Is_True()
                        noexcept
                    {
                        return tr1<subject_p, tag_p, last_object_p>;
                    }
                };

                template <typename subject_p, typename tag_p, typename first_object_p, typename ...more_objects_p>
                class tr1_tag_objects_tmpl<true, subject_p, tag_p, first_object_p, more_objects_p...>
                {
                public:
                    static constexpr nkr::boolean::cpp_t
                        Is_True()
                        noexcept
                    {
                        return tr1_tag_objects_tmpl<
                            tr1<subject_p, tag_p, first_object_p>,
                            subject_p,
                            tag_p,
                            more_objects_p...
                        >::Is_True();
                    }
                };

                template <nkr::boolean::cpp_t _, typename ...subjects_p>
                class tr1_subjects_tmpl;

                template <typename ...subjects_p>
                class tr1_subjects_tmpl<false, subjects_p...>
                {
                public:
                    template <typename tag_p, typename ...objects_p>
                    static constexpr nkr::boolean::cpp_t
                        Satisfy()
                        noexcept
                    {
                        return false;
                    }
                };

                template <typename last_subject_p>
                class tr1_subjects_tmpl<true, last_subject_p>
                {
                public:
                    template <typename tag_p, typename ...objects_p>
                    static constexpr nkr::boolean::cpp_t
                        Satisfy()
                        noexcept
                    {
                        return tr1_tag_objects_tmpl<true, last_subject_p, tag_p, objects_p...>::Is_True();
                    }
                };

                template <typename first_subject_p, typename ...more_subjects_p>
                class tr1_subjects_tmpl<true, first_subject_p, more_subjects_p...>
                {
                public:
                    template <typename tag_p, typename ...objects_p>
                    static constexpr nkr::boolean::cpp_t
                        Satisfy()
                        noexcept
                    {
                        return tr1_subjects_tmpl<
                            tr1_tag_objects_tmpl<true, first_subject_p, tag_p, objects_p...>::Is_True(),
                            more_subjects_p...
                        >::template Satisfy<tag_p, objects_p...>();
                    }
                };

                template <typename ...subjects_p>
                class tr1_subjects_t
                {
                public:
                    template <typename tag_p, typename ...objects_p>
                    static constexpr nkr::boolean::cpp_t
                        Satisfy()
                        noexcept
                    {
                        return tr1_subjects_tmpl<true, subjects_p...>::template Satisfy<tag_p, objects_p...>();
                    }
                };

                static_assert(tr1_subjects_t<nkr_ANY>::Satisfy<any_tg, nkr::boolean::pure_t, nkr::boolean::pure_tg>());
                static_assert(!tr1_subjects_t<nkr_ANY>::Satisfy<any_tg, nkr::boolean::cpp_t, nkr::boolean::cpp_tg>());
            }

            TEST_SUITE("tr1 any_tg")
            {
                TEST_CASE_TEMPLATE("should be true for any compared to nkr::boolean::pure_t", pure_p, nkr_ANY)
                {
                    static_assert(tr1<pure_p, any_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be true for any compared to nkr::boolean::pure_tg", pure_p, nkr_ANY)
                {
                    static_assert(tr1<pure_p, any_tg, nkr::boolean::pure_tg>);
                }
            }

            TEST_SUITE("tr1 any_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should be true for any qualified compared to nkr::boolean::pure_t", pure_p, nkr_ANY_QUALIFIED)
                {
                    static_assert(tr1<pure_p, any_qualified_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be true for any qualified compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_QUALIFIED)
                {
                    static_assert(tr1<pure_p, any_qualified_tg, nkr::boolean::pure_tg>);
                }

                TEST_CASE_TEMPLATE("should be false for any non-qualified compared to nkr::boolean::pure_t", pure_p, nkr_ANY_NON_QUALIFIED)
                {
                    static_assert(!tr1<pure_p, any_qualified_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be false for any non-qualified compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_NON_QUALIFIED)
                {
                    static_assert(!tr1<pure_p, any_qualified_tg, nkr::boolean::pure_tg>);
                }
            }

            TEST_SUITE("tr1 any_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should be true for any non-qualified compared to nkr::boolean::pure_t", pure_p, nkr_ANY_NON_QUALIFIED)
                {
                    static_assert(tr1<pure_p, any_non_qualified_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be true for any non-qualified compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_NON_QUALIFIED)
                {
                    static_assert(tr1<pure_p, any_non_qualified_tg, nkr::boolean::pure_tg>);
                }

                TEST_CASE_TEMPLATE("should be false for any qualified compared to nkr::boolean::pure_t", pure_p, nkr_ANY_QUALIFIED)
                {
                    static_assert(!tr1<pure_p, any_non_qualified_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be false for any qualified compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_QUALIFIED)
                {
                    static_assert(!tr1<pure_p, any_non_qualified_tg, nkr::boolean::pure_tg>);
                }
            }

            TEST_SUITE("tr1 any_const_tg")
            {
                TEST_CASE_TEMPLATE("should be true for any const compared to nkr::boolean::pure_t", pure_p, nkr_ANY_CONST)
                {
                    static_assert(tr1<pure_p, any_const_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be true for any const compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_CONST)
                {
                    static_assert(tr1<pure_p, any_const_tg, nkr::boolean::pure_tg>);
                }

                TEST_CASE_TEMPLATE("should be false for any non-const compared to nkr::boolean::pure_t", pure_p, nkr_ANY_NON_CONST)
                {
                    static_assert(!tr1<pure_p, any_const_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be false for any non-const compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_NON_CONST)
                {
                    static_assert(!tr1<pure_p, any_const_tg, nkr::boolean::pure_tg>);
                }
            }

            TEST_SUITE("tr1 any_non_const_tg")
            {
                TEST_CASE_TEMPLATE("should be true for any non-const compared to nkr::boolean::pure_t", pure_p, nkr_ANY_NON_CONST)
                {
                    static_assert(tr1<pure_p, any_non_const_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be true for any non-const compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_NON_CONST)
                {
                    static_assert(tr1<pure_p, any_non_const_tg, nkr::boolean::pure_tg>);
                }

                TEST_CASE_TEMPLATE("should be false for any const compared to nkr::boolean::pure_t", pure_p, nkr_ANY_CONST)
                {
                    static_assert(!tr1<pure_p, any_non_const_tg, nkr::boolean::pure_t>);
                }

                TEST_CASE_TEMPLATE("should be false for any const compared to nkr::boolean::pure_tg", pure_p, nkr_ANY_CONST)
                {
                    static_assert(!tr1<pure_p, any_non_const_tg, nkr::boolean::pure_tg>);
                }
            }
        }

        TEST_SUITE("operators")
        {
            TEST_CASE("temp")
            {
                nkr::boolean::pure_t boolean;
                volatile nkr::boolean::cpp_t test = false;
                boolean = nkr::boolean::cpp_t();
                boolean = nkr::cpp::Move(test);

                CHECK((boolean == nkr::cpp::Move(test)));
            }
        }
    }

}
