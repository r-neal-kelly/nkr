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
                // the if constexpr blocks are used to assist the compiler in avoiding instantiating a type when unnecessary.
                template <typename ...subjects_p>
                class tr1_tmpl;

                template <typename last_subject_p>
                class tr1_tmpl<last_subject_p>
                {
                public:
                    template <typename operator_p, typename operand_p>
                    static constexpr nkr::boolean::cpp_t
                        OR()
                        noexcept
                    {
                        return tr1<last_subject_p, operator_p, operand_p>;
                    }

                    template <typename operator_p, typename operand_p>
                    static constexpr nkr::boolean::cpp_t
                        AND()
                        noexcept
                    {
                        return tr1<last_subject_p, operator_p, operand_p>;
                    }

                    template <typename operator_p, typename operand_p, nkr::boolean::cpp_t state_p>
                    static constexpr nkr::boolean::cpp_t
                        XOR()
                        noexcept
                    {
                        if constexpr (state_p) {
                            return !tr1<last_subject_p, operator_p, operand_p>;
                        } else {
                            return tr1<last_subject_p, operator_p, operand_p>;
                        }
                    }
                };

                template <typename first_subject_p, typename ...more_subjects_p>
                class tr1_tmpl<first_subject_p, more_subjects_p...>
                {
                public:
                    template <typename operator_p, typename operand_p>
                    static constexpr nkr::boolean::cpp_t
                        OR()
                        noexcept
                    {
                        if constexpr (tr1<first_subject_p, operator_p, operand_p>) {
                            return true;
                        } else {
                            return tr1_tmpl<more_subjects_p...>::template OR<operator_p, operand_p>();
                        }
                    }

                    template <typename operator_p, typename operand_p>
                    static constexpr nkr::boolean::cpp_t
                        AND()
                        noexcept
                    {
                        if constexpr (tr1<first_subject_p, operator_p, operand_p>) {
                            return tr1_tmpl<more_subjects_p...>::template AND<operator_p, operand_p>();
                        } else {
                            return false;
                        }
                    }

                    template <typename operator_p, typename operand_p, nkr::boolean::cpp_t state_p>
                    static constexpr nkr::boolean::cpp_t
                        XOR()
                        noexcept
                    {
                        if constexpr (state_p) {
                            if constexpr (tr1<first_subject_p, operator_p, operand_p>) {
                                return false;
                            } else {
                                return tr1_tmpl<more_subjects_p...>::template XOR<operator_p, operand_p, true>();
                            }
                        } else {
                            if constexpr (tr1<first_subject_p, operator_p, operand_p>) {
                                return tr1_tmpl<more_subjects_p...>::template XOR<operator_p, operand_p, true>();
                            } else {
                                return tr1_tmpl<more_subjects_p...>::template XOR<operator_p, operand_p, false>();
                            }
                        }
                    }
                };

                template <typename operator_p, typename operand_p>
                class tr1_t
                {
                public:
                    // passes if any subjects satisfy
                    template <typename ...subjects_p>
                    static constexpr nkr::boolean::cpp_t
                        OR()
                        noexcept
                    {
                        return tr1_tmpl<subjects_p...>::template OR<operator_p, operand_p>();
                    }

                    // passes if all subjects satisfy
                    template <typename ...subjects_p>
                    static constexpr nkr::boolean::cpp_t
                        AND()
                        noexcept
                    {
                        return tr1_tmpl<subjects_p...>::template AND<operator_p, operand_p>();
                    }

                    // passes if just one subject satisfies
                    template <typename ...subjects_p>
                    static constexpr nkr::boolean::cpp_t
                        XOR()
                        noexcept
                    {
                        return tr1_tmpl<subjects_p...>::template XOR<operator_p, operand_p, false>();
                    }

                    // passes if not any subjects satisfy
                    template <typename ...subjects_p>
                    static constexpr nkr::boolean::cpp_t
                        NOR()
                        noexcept
                    {
                        return !OR<subjects_p...>();
                    }

                    // passes if not all subjects satisfy
                    template <typename ...subjects_p>
                    static constexpr nkr::boolean::cpp_t
                        NAND()
                        noexcept
                    {
                        return !AND<subjects_p...>();
                    }

                    // passes if not just one subject satisfies
                    template <typename ...subjects_p>
                    static constexpr nkr::boolean::cpp_t
                        XNOR()
                        noexcept
                    {
                        return !XOR<subjects_p...>();
                    }
                };

                using true_t = nkr::boolean::pure_t;
                using false_t = nkr::positive::integer_t;

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::OR<false_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::OR<false_t, true_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::OR<true_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::OR<true_t, true_t>() == true);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::AND<false_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::AND<false_t, true_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::AND<true_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::AND<true_t, true_t>() == true);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XOR<false_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XOR<false_t, true_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XOR<true_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XOR<true_t, true_t>() == false);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NOR<false_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NOR<false_t, true_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NOR<true_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NOR<true_t, true_t>() == false);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NAND<false_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NAND<false_t, true_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NAND<true_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NAND<true_t, true_t>() == false);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<false_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<false_t, true_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<true_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<true_t, true_t>() == true);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<false_t, false_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<true_t, false_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<false_t, true_t, false_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<false_t, false_t, true_t>() == false);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<true_t, true_t, false_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<false_t, true_t, true_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<true_t, false_t, true_t>() == true);
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::XNOR<true_t, true_t, true_t>() == true);

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::AND<nkr_ANY>());
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NAND<nkr::boolean::pure_t, nkr::boolean::cpp_t>());

                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::OR<nkr::boolean::pure_t, nkr::boolean::cpp_t>());
                static_assert(tr1_t<any_tg, nkr::boolean::pure_t>::NOR<nkr::positive::integer_t, nkr::negatable::integer_t, nkr::boolean::cpp_t>());
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
