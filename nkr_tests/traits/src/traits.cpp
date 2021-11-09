/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "doctest.h"

namespace nkr {

    class user_defined_t;

    template <>
    class type_traits_i<user_defined_t>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any()
        {
            return is_any_tr<other_p, user_defined_t>;
        }
    };

    class user_defined_t
    {
    public:
    };

    class other_t;

    template <>
    class type_traits_i<other_t>
    {
    public:
        using of_t = void_t;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any()
        {
            return is_any_tr<other_p, other_t>;
        }
    };

    class other_t
    {
    public:
    };

    template <typename value_p>
    class value_template_t;

    namespace $value_template_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, value_template_t<typename type_p::value_t>>;

    }

    template <$value_template_t::any_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = type_p::value_t;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any()
        {
            return $value_template_t::any_tr<other_p>;
        }
    };

    template <>
    class template_traits_i<value_template_t>
    {
    public:
        template <typename of_p>
        using type_t    = value_template_t<of_p>;

    public:
        static constexpr std_bool_t Is_Implemented()
        {
            return true;
        }
    };

    template <typename value_p>
    class value_template_t
    {
    public:
        using value_t   = value_p;
    };

    template <typename unit_p>
    class unit_template_t;

    namespace $unit_template_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, unit_template_t<typename type_p::unit_t>>;

    }

    template <$unit_template_t::any_tr type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = type_p::unit_t;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any()
        {
            return $unit_template_t::any_tr<other_p>;
        }
    };

    template <>
    class template_traits_i<unit_template_t>
    {
    public:
        template <typename of_p>
        using type_t    = unit_template_t<of_p>;

    public:
        static constexpr std_bool_t Is_Implemented()
        {
            return true;
        }
    };

    template <typename unit_p>
    class unit_template_t
    {
    public:
        using unit_t    = unit_p;
    };

}

namespace nkr { namespace traits {

    TEST_SUITE("traits")
    {
    #define nkr_NON_QUALIFIED   \
        void_t,                 \
        std_bool_t,             \
        bool_t,                 \
        unsigned_word_t,        \
        signed_word_t,          \
        real_t,                 \
        void_t*,                \
        word_t*,                \
        word_t[1],              \
        user_defined_t

        TEST_SUITE("tr0")
        {
            TEST_SUITE("any_tg")
            {
                TEST_CASE_TEMPLATE("should allow any subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  any_tg>);
                    static_assert(tr0<const subject_p,
                                  any_tg>);
                    static_assert(tr0<volatile subject_p,
                                  any_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  any_tg>);
                }
            }

            TEST_SUITE("any_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should allow any qualified subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const subject_p,
                                  any_qualified_tg>);
                    static_assert(tr0<volatile subject_p,
                                  any_qualified_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  any_qualified_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  any_qualified_tg>);
                }
            }

            TEST_SUITE("any_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should allow any non-qualified subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  any_non_qualified_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const subject_p,
                                  any_non_qualified_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  any_non_qualified_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  any_non_qualified_tg>);
                }
            }

            TEST_SUITE("any_const_tg")
            {
                TEST_CASE_TEMPLATE("should allow any const subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const subject_p,
                                  any_const_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  any_const_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  any_const_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  any_const_tg>);
                }
            }

            TEST_SUITE("any_non_const_tg")
            {
                TEST_CASE_TEMPLATE("should allow any non-const subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  any_non_const_tg>);
                    static_assert(tr0<volatile subject_p,
                                  any_non_const_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const subject_p,
                                  any_non_const_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  any_non_const_tg>);
                }
            }

            TEST_SUITE("any_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should allow any volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<volatile subject_p,
                                  any_volatile_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  any_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  any_volatile_tg>);
                    static_assert(!tr0<const subject_p,
                                  any_volatile_tg>);
                }
            }

            TEST_SUITE("any_non_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should allow any non-volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  any_non_volatile_tg>);
                    static_assert(tr0<const subject_p,
                                  any_non_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<volatile subject_p,
                                  any_non_volatile_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  any_non_volatile_tg>);
                }
            }

            TEST_SUITE("not_any_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  not_any_tg>);
                    static_assert(!tr0<const subject_p,
                                  not_any_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  not_any_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  not_any_tg>);
                }
            }

            TEST_SUITE("not_any_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any qualified subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const subject_p,
                                  not_any_qualified_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  not_any_qualified_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  not_any_qualified_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  not_any_qualified_tg>);
                }
            }

            TEST_SUITE("not_any_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any non-qualified subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  not_any_non_qualified_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const subject_p,
                                  not_any_non_qualified_tg>);
                    static_assert(tr0<volatile subject_p,
                                  not_any_non_qualified_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  not_any_non_qualified_tg>);
                }
            }

            TEST_SUITE("not_any_const_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any const subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const subject_p,
                                  not_any_const_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  not_any_const_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  not_any_const_tg>);
                    static_assert(tr0<volatile subject_p,
                                  not_any_const_tg>);
                }
            }

            TEST_SUITE("not_any_non_const_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any non-const subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  not_any_non_const_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  not_any_non_const_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const subject_p,
                                  not_any_non_const_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  not_any_non_const_tg>);
                }
            }

            TEST_SUITE("not_any_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<volatile subject_p,
                                  not_any_volatile_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  not_any_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  not_any_volatile_tg>);
                    static_assert(tr0<const subject_p,
                                  not_any_volatile_tg>);
                }
            }

            TEST_SUITE("not_any_non_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any non-volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  not_any_non_volatile_tg>);
                    static_assert(!tr0<const subject_p,
                                  not_any_non_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<volatile subject_p,
                                  not_any_non_volatile_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  not_any_non_volatile_tg>);
                }
            }

            TEST_SUITE("just_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  just_tg>);
                    static_assert(tr0<const subject_p,
                                  just_tg>);
                    static_assert(tr0<volatile subject_p,
                                  just_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  just_tg>);
                }
            }

            TEST_SUITE("just_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a non-qualified subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  just_non_qualified_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const subject_p,
                                  just_non_qualified_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  just_non_qualified_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  just_non_qualified_tg>);
                }
            }

            TEST_SUITE("just_const_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a const subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const subject_p,
                                  just_const_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  just_const_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  just_const_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  just_const_tg>);
                }
            }

            TEST_SUITE("just_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<volatile subject_p,
                                  just_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  just_volatile_tg>);
                    static_assert(!tr0<const subject_p,
                                  just_volatile_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  just_volatile_tg>);
                }
            }

            TEST_SUITE("just_const_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a const volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const volatile subject_p,
                                  just_const_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should not allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  just_const_volatile_tg>);
                    static_assert(!tr0<const subject_p,
                                  just_const_volatile_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  just_const_volatile_tg>);
                }
            }

            TEST_SUITE("just_not_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  just_not_tg>);
                    static_assert(!tr0<const subject_p,
                                  just_not_tg>);
                    static_assert(!tr0<volatile subject_p,
                                  just_not_tg>);
                    static_assert(!tr0<const volatile subject_p,
                                  just_not_tg>);
                }
            }

            TEST_SUITE("just_not_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a non-qualified subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<subject_p,
                                  just_not_non_qualified_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<const subject_p,
                                  just_not_non_qualified_tg>);
                    static_assert(tr0<volatile subject_p,
                                  just_not_non_qualified_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  just_not_non_qualified_tg>);
                }
            }

            TEST_SUITE("just_not_const_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a const subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const subject_p,
                                  just_not_const_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  just_not_const_tg>);
                    static_assert(tr0<volatile subject_p,
                                  just_not_const_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  just_not_const_tg>);
                }
            }

            TEST_SUITE("just_not_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<volatile subject_p,
                                  just_not_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  just_not_volatile_tg>);
                    static_assert(tr0<const subject_p,
                                  just_not_volatile_tg>);
                    static_assert(tr0<const volatile subject_p,
                                  just_not_volatile_tg>);
                }
            }

            TEST_SUITE("just_not_const_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a const volatile subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr0<const volatile subject_p,
                                  just_not_const_volatile_tg>);
                }

                TEST_CASE_TEMPLATE("should allow any other subject", subject_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr0<subject_p,
                                  just_not_const_volatile_tg>);
                    static_assert(tr0<const subject_p,
                                  just_not_const_volatile_tg>);
                    static_assert(tr0<volatile subject_p,
                                  just_not_const_volatile_tg>);
                }
            }
        }

        TEST_SUITE("tr1")
        {
            TEST_SUITE("any_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  any_tg, type_p>);
                    static_assert(tr1<const type_p,
                                  any_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  any_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  any_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_tg, type_p>);
                }
            }

            TEST_SUITE("any_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const type_p,
                                  any_qualified_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  any_qualified_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  any_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any matching non-qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  any_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_qualified_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_qualified_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_qualified_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_qualified_tg, type_p>);
                }
            }

            TEST_SUITE("any_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching non-qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  any_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any matching qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const type_p,
                                  any_non_qualified_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  any_non_qualified_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  any_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_non_qualified_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_non_qualified_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_non_qualified_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_non_qualified_tg, type_p>);
                }
            }

            TEST_SUITE("any_const_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const type_p,
                                  any_const_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  any_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any matching non-const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  any_const_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  any_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_const_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_const_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_const_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_const_tg, type_p>);
                }
            }

            TEST_SUITE("any_non_const_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching non-const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  any_non_const_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  any_non_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any matching const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const type_p,
                                  any_non_const_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  any_non_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_non_const_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_non_const_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_non_const_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_non_const_tg, type_p>);
                }
            }

            TEST_SUITE("any_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<volatile type_p,
                                  any_volatile_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  any_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any matching non-volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  any_volatile_tg, type_p>);
                    static_assert(!tr1<const type_p,
                                  any_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_volatile_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_volatile_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("any_non_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should allow any matching non-volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  any_non_volatile_tg, type_p>);
                    static_assert(tr1<const type_p,
                                  any_non_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any matching volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<volatile type_p,
                                  any_non_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  any_non_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  any_non_volatile_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  any_non_volatile_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  any_non_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  any_non_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  not_any_tg, type_p>);
                    static_assert(!tr1<const type_p,
                                  not_any_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  not_any_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  not_any_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const type_p,
                                  not_any_qualified_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  not_any_qualified_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  not_any_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any matching non-qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  not_any_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_qualified_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_qualified_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_qualified_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_qualified_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching non-qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  not_any_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any matching qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const type_p,
                                  not_any_non_qualified_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  not_any_non_qualified_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  not_any_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_non_qualified_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_non_qualified_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_non_qualified_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_non_qualified_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_const_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const type_p,
                                  not_any_const_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  not_any_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any matching non-const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  not_any_const_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  not_any_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_const_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_const_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_const_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_const_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_non_const_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching non-const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  not_any_non_const_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  not_any_non_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any matching const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const type_p,
                                  not_any_non_const_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  not_any_non_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_non_const_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_non_const_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_non_const_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_non_const_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<volatile type_p,
                                  not_any_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  not_any_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any matching non-volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  not_any_volatile_tg, type_p>);
                    static_assert(tr1<const type_p,
                                  not_any_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_volatile_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_volatile_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_volatile_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("not_any_non_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should not allow any matching non-volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  not_any_non_volatile_tg, type_p>);
                    static_assert(!tr1<const type_p,
                                  not_any_non_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any matching volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<volatile type_p,
                                  not_any_non_volatile_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  not_any_non_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  not_any_non_volatile_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  not_any_non_volatile_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  not_any_non_volatile_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  not_any_non_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("just_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  just_tg, type_p>);
                    static_assert(tr1<const type_p,
                                  just_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  just_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  just_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  just_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  just_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  just_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  just_tg, type_p>);
                }
            }

            TEST_SUITE("just_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a matching non-qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  just_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const type_p,
                                  just_non_qualified_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  just_non_qualified_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  just_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  just_non_qualified_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  just_non_qualified_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  just_non_qualified_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  just_non_qualified_tg, type_p>);
                }
            }

            TEST_SUITE("just_const_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a matching const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const type_p,
                                  just_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  just_const_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  just_const_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  just_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  just_const_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  just_const_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  just_const_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  just_const_tg, type_p>);
                }
            }

            TEST_SUITE("just_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a matching volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<volatile type_p,
                                  just_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  just_volatile_tg, type_p>);
                    static_assert(!tr1<const type_p,
                                  just_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  just_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  just_volatile_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  just_volatile_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  just_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  just_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("just_const_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just allow a matching const volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const volatile type_p,
                                  just_const_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  just_const_volatile_tg, type_p>);
                    static_assert(!tr1<const type_p,
                                  just_const_volatile_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  just_const_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should not allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<other_t,
                                  just_const_volatile_tg, type_p>);
                    static_assert(!tr1<const other_t,
                                  just_const_volatile_tg, type_p>);
                    static_assert(!tr1<volatile other_t,
                                  just_const_volatile_tg, type_p>);
                    static_assert(!tr1<const volatile other_t,
                                  just_const_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("just_not_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  just_not_tg, type_p>);
                    static_assert(!tr1<const type_p,
                                  just_not_tg, type_p>);
                    static_assert(!tr1<volatile type_p,
                                  just_not_tg, type_p>);
                    static_assert(!tr1<const volatile type_p,
                                  just_not_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  just_not_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  just_not_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  just_not_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  just_not_tg, type_p>);
                }
            }

            TEST_SUITE("just_not_non_qualified_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a matching non-qualified type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<type_p,
                                  just_not_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<const type_p,
                                  just_not_non_qualified_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  just_not_non_qualified_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  just_not_non_qualified_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  just_not_non_qualified_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  just_not_non_qualified_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  just_not_non_qualified_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  just_not_non_qualified_tg, type_p>);
                }
            }

            TEST_SUITE("just_not_const_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a matching const type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const type_p,
                                  just_not_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  just_not_const_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  just_not_const_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  just_not_const_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  just_not_const_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  just_not_const_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  just_not_const_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  just_not_const_tg, type_p>);
                }
            }

            TEST_SUITE("just_not_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a matching volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<volatile type_p,
                                  just_not_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  just_not_volatile_tg, type_p>);
                    static_assert(tr1<const type_p,
                                  just_not_volatile_tg, type_p>);
                    static_assert(tr1<const volatile type_p,
                                  just_not_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  just_not_volatile_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  just_not_volatile_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  just_not_volatile_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  just_not_volatile_tg, type_p>);
                }
            }

            TEST_SUITE("just_not_const_volatile_tg")
            {
                TEST_CASE_TEMPLATE("should just not allow a matching const volatile type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(!tr1<const volatile type_p,
                                  just_not_const_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any other matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<type_p,
                                  just_not_const_volatile_tg, type_p>);
                    static_assert(tr1<const type_p,
                                  just_not_const_volatile_tg, type_p>);
                    static_assert(tr1<volatile type_p,
                                  just_not_const_volatile_tg, type_p>);
                }

                TEST_CASE_TEMPLATE("should allow any non-matching type", type_p, nkr_NON_QUALIFIED)
                {
                    static_assert(tr1<other_t,
                                  just_not_const_volatile_tg, type_p>);
                    static_assert(tr1<const other_t,
                                  just_not_const_volatile_tg, type_p>);
                    static_assert(tr1<volatile other_t,
                                  just_not_const_volatile_tg, type_p>);
                    static_assert(tr1<const volatile other_t,
                                  just_not_const_volatile_tg, type_p>);
                }
            }
        }

        TEST_SUITE("tr2")
        {
            TEST_SUITE("any_tg")
            {

            }
        }

        TEST_SUITE("tr3")
        {
            TEST_SUITE("any_tg")
            {

            }
        }







        TEST_SUITE("of_any_tg")
        {

        }

        TEST_SUITE("c_pointer_tg")
        {

        }

        TEST_SUITE("c_pointer_ttg")
        {

        }

        TEST_SUITE("c_array_tg")
        {

        }

        TEST_SUITE("c_array_ttg")
        {

        }
    }




    static_assert(tr1<
                  const char*,
                  any_non_const_tg, c_pointer_tg>);
    static_assert(tr1<
                  const char* const,
                  any_const_tg, c_pointer_tg>);

    static_assert(tr2<
                  char**,
                  any_tg, c_pointer_ttg, of_any_tg, c_pointer_tg>);
    static_assert(tr2<
                  std::add_pointer_t<char[3]>,
                  any_tg, c_pointer_ttg, of_any_tg, c_array_tg>);

    class testing_t
    {
    public:
        static bool_t Test(tr1<any_non_const_tg, c_pointer_tg> auto& test)
        {
            return true;
        }

        static bool_t Test(tr1<any_const_tg, c_pointer_tg> auto& test)
        {
            return false;
        }
    };

    class testing_2_t
    {
    public:
        static bool_t Test(tr1<any_tg, c_array_tg> auto& array)
        {
            static_assert(std_array_tr<std::remove_reference_t<decltype(array)>>);

            printf("sizeof array: %zu\n", sizeof(array));

            return true;
        }
    };

    TEST_CASE("temp")
    {
        const char* a = nullptr;
        CHECK(testing_t::Test(a));
        const char* volatile b = nullptr;
        CHECK(testing_t::Test(b));
        const volatile char* c = nullptr;
        CHECK(testing_t::Test(c));
        const volatile char* volatile d = nullptr;
        CHECK(testing_t::Test(d));

        const char* const e = nullptr;
        CHECK(!testing_t::Test(e));
        const char* const volatile f = nullptr;
        CHECK(!testing_t::Test(f));
        const volatile char* const g = nullptr;
        CHECK(!testing_t::Test(g));
        const volatile char* const volatile h = nullptr;
        CHECK(!testing_t::Test(h));

        const char array[5] = { 0 };
        CHECK(testing_2_t::Test(array));
    }

    static_assert(!tr2<
                  volatile value_template_t<const volatile word_t*>,
                  any_tg, unit_template_t, of_any_tg, word_t*>);

    static_assert(tr3<
                  volatile value_template_t<const volatile word_t*>,
                  just_volatile_tg, value_template_t, of_just_non_qualified_tg, c_pointer_ttg, of_any_const_tg, word_t>);

    static_assert(tr3<
                  value_template_t<void_t*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, void_t>);

    static_assert(tr1<
                  value_template_t<char>,
                  any_tg, value_template_t<char>>);
    static_assert(tr1<
                  volatile value_template_t<const volatile char>,
                  any_tg, value_template_t<char>>);

    static_assert(tr1<
                  const volatile value_template_t<char>,
                  any_const_tg, value_template_t<char>>);

    static_assert(tr2<
                  volatile value_template_t<const volatile char>,
                  any_tg, value_template_t, of_any_tg, char>);
    static_assert(tr2<
                  const value_template_t<volatile value_template_t<char>>,
                  any_tg, value_template_t, of_any_tg, value_template_t<char>>);

    static_assert(tr3<
                  value_template_t<value_template_t<char>>,
                  any_tg, value_template_t, of_any_tg, value_template_t, of_any_tg, char>);

    static_assert(tr3<
                  value_template_t<char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  value_template_t<const volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const value_template_t<const volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile value_template_t<const volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const volatile char*>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const volatile char* const>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const volatile char* volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile value_template_t<const volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);

    static_assert(!tr3<
                  const volatile value_template_t<const volatile char* const volatile>,
                  any_tg, value_template_t, of_any_tg, c_pointer_ttg, of_any_tg, int>);

    static_assert(tr3<
                  value_template_t<const char* const volatile>,
                  any_tg, value_template_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);
    static_assert(!tr3<
                  value_template_t<char* const volatile>,
                  any_tg, value_template_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);
    static_assert(!tr3<
                  value_template_t<const char* volatile>,
                  any_tg, value_template_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);

}}
