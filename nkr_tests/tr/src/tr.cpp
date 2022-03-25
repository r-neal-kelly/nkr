/*
    Copyright 2022 r-neal-kelly
*/

#include <unordered_map>

#include "nkr/array/cpp_t.h"
#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/cpp/array/remote/dynamic_t.h"
#include "nkr/cpp/list/remote/forward_t.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/built_in/number/integer_tr.h"
#include "nkr/generic/negatable_tr.h"
#include "nkr/generic/number_tr.h"
#include "nkr/generic/user_defined_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/reference/lvalue_t.h"
#include "nkr/reference/rvalue_t.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("tr")
    {
        static_assert(tr<nkr::positive::integer_t, any_tg, t<nkr::positive::integer_t>>);
        static_assert(tr<nkr::positive::integer_t, any_tg, t<nkr::positive::integer_t>>);
        static_assert(tr<nkr::positive::integer_t, any_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>>);
        static_assert(tr<nkr::negatable::integer_t, any_non_const_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>>);

        static_assert(tr<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, tts<AND_tg, nkr::pointer::cpp_t, nkr::pointer::cpp_ttg>,
                      of_just_volatile_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>>);

        // and of course, one can just the simple tuple wrappers to get the most readable and most common use-case
        static_assert(tr<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_just_volatile_tg, t<nkr::positive::integer_t>>);

        // just_tg continues to work!
        static_assert(tr<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_just_tg, ts<OR_tg, volatile nkr::positive::integer_t, nkr::negatable::integer_t>>);
        static_assert(tr<const volatile nkr::pointer::cpp_t<nkr::negatable::integer_t>,
                      any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_just_tg, ts<OR_tg, volatile nkr::positive::integer_t, nkr::negatable::integer_t>>);

        static_assert(tr<nkr::pointer::cpp_t<const nkr::pointer::cpp_t<volatile nkr::positive::integer_t>>,
                      any_non_qualified_tg, tt<nkr::pointer::cpp_t>,
                      of_any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_any_volatile_tg, t<nkr::positive::integer_t>>);

        static_assert(tr<volatile nkr::positive::integer_t* const*,
                      any_non_qualified_tg, tt<nkr::pointer::cpp_t>,
                      of_any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_any_volatile_tg, t<nkr::positive::integer_t>>);

        static_assert(tr<volatile int* const*,
                      any_non_qualified_tg, tt<nkr::pointer::cpp_t>,
                      of_any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_any_volatile_tg, ts<OR_tg, nkr::positive::integer_t, int>>);

        static_assert(tr<volatile nkr::positive::integer_t,
                      any_non_const_tg>);

        TEST_CASE("3 levels")
        {
            static_assert(tr<volatile int* const*,
                          any_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_volatile_tg, t<int>>);
            static_assert(!tr<volatile short* const*,
                          any_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_volatile_tg, t<int>>);
            static_assert(tr<volatile short* volatile*,
                          any_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_volatile_tg, t<int>>);

            static_assert(tr<volatile int* const*,
                          not_any_non_qualified_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_any_volatile_tg, ts<OR_tg, nkr::positive::integer_t, int>> == false);
        }

        TEST_SUITE("should invert an entire expression when negated")
        {
            using namespace nkr;

            static_assert(tr<
                          const long long*,
                          any_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_const_tg, ts<OR_tg, int, short>
            >);

            class a_t
            {
            public:
            };

            class b_t
            {
            public:
            };

            static_assert(tr<
                          a_t,
                          any_tg, ts<OR_tg, a_t, b_t>
            > == true);

            static_assert(tr<
                          b_t,
                          any_tg, ts<OR_tg, a_t, b_t>
            > == true);

            static_assert(tr<
                          a_t,
                          not_any_tg, ts<OR_tg, a_t, b_t>
            > == false);

            static_assert(tr<
                          b_t,
                          not_any_tg, ts<OR_tg, a_t, b_t>
            > == false);
        }

        TEST_SUITE("must work with multiple not operators")
        {
            static_assert(tr<
                          volatile int* volatile,
                          not_any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_any_volatile_tg, t<short>
            >);

            static_assert(tr<
                          volatile int* volatile,
                          not_any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_volatile_tg, t<int>
            >);

            static_assert(tr<
                          volatile int* const,
                          not_any_volatile_tg, tt<nkr::pointer::cpp_t>
            >);

            static_assert(tr<
                          volatile int* const,
                          not_any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_volatile_tg, t<int>
            >);

            static_assert(tr<
                          volatile int* const,
                          any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_not_any_volatile_tg, t<int>
            > == false);

            static_assert(nkr::tr$::not_operator_tr<any_volatile_tg> == false);
        }

        TEST_SUITE("temp")
        {
            using subject_t = volatile short* volatile*;
            using expression_parts_t = nkr::tuple::types_t<
                any_tg, tt<nkr::pointer::cpp_t>,
                of_not_any_access_const_tg, tt<nkr::pointer::cpp_t>,
                of_not_any_volatile_tg, t<int>>;

            using operators_t = nkr::tr$::operators_t<expression_parts_t>;
            using subjects_t = nkr::tr$::subjects_t<subject_t, operators_t>;
            using objects_t = nkr::tr$::objects_t<expression_parts_t>;

            static_assert(nkr::cpp::is_tr<operators_t, nkr::tuple::types_t<
                          any_tg,
                          of_not_any_access_const_tg,
                          of_not_any_volatile_tg>>);

            static_assert(nkr::cpp::is_tr<subjects_t, nkr::tuple::types_t<
                          nkr::pointer::cpp_t<volatile nkr::pointer::cpp_t<volatile short>>,
                          volatile nkr::pointer::cpp_t<volatile short>,
                          volatile short>>);

            static_assert(nkr::cpp::is_tr<objects_t, nkr::tuple::types_t<
                          nkr::pointer::cpp_t<nkr::pointer::cpp_t<int>>,
                          nkr::pointer::cpp_t<int>,
                          int>>);
        }

        TEST_SUITE("temp")
        {
            using subject_t = volatile int* volatile* const;
            using expression_parts_t = nkr::tuple::types_t<
                any_tg, tt<nkr::pointer::cpp_t>,
                of_any_access_const_tg, tt<nkr::pointer::cpp_t>,
                of_any_access_const_tg, t<int>>;

            using operators_t = nkr::tr$::operators_t<expression_parts_t>;
            using subjects_t = nkr::tr$::subjects_t<subject_t, operators_t>;
            using objects_t = nkr::tr$::objects_t<expression_parts_t>;

            static_assert(nkr::cpp::is_tr<operators_t, nkr::tuple::types_t<
                          any_tg,
                          of_any_access_const_tg,
                          of_any_access_const_tg>>);
            static_assert(nkr::cpp::is_tr<subjects_t, nkr::tuple::types_t<
                          const nkr::pointer::cpp_t<volatile nkr::pointer::cpp_t<volatile int>>,
                          const volatile nkr::pointer::cpp_t<volatile int>,
                          const volatile int>>);
            static_assert(nkr::cpp::is_tr<objects_t, nkr::tuple::types_t<
                          nkr::pointer::cpp_t<nkr::pointer::cpp_t<int>>,
                          nkr::pointer::cpp_t<int>,
                          int>>);

            static_assert(nkr::tr$::Evaluate<subjects_t, operators_t, objects_t>());
        }

        TEST_SUITE("temp")
        {
            static_assert(tr<volatile int* volatile* const,
                          any_tg, tt<nkr::pointer::cpp_t>,
                          of_any_access_const_tg, tt<nkr::pointer::cpp_t>,
                          of_any_access_const_tg, t<int>
            >);

            static_assert(tr<const volatile int* volatile* const* volatile* const* volatile* const*,
                          just_non_qualified_tg, tt<nkr::pointer::cpp_t>,
                          of_just_const_tg, tt<nkr::pointer::cpp_t>,
                          of_just_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_just_const_tg, tt<nkr::pointer::cpp_t>,
                          of_just_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_just_const_tg, tt<nkr::pointer::cpp_t>,
                          of_just_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_just_tg, t<const volatile int>
            >);

            // we now support the just_tg with tt operands as well as inner t and now outer t operands too!
            static_assert(tr<const volatile int* const,
                          just_tg, const tt<nkr::pointer::cpp_t>,
                          of_just_tg, const t<volatile int>
            >);
            // remember, these extra qualifiers are ignored without the just_tg
            static_assert(tr<int*,
                          any_tg, const tt<nkr::pointer::cpp_t>,
                          of_any_tg, const t<volatile int>
            >);

            static_assert(tr<const int,
                          any_tg
            >);
        }

        TEST_SUITE("temp")
        {
            static_assert(tr<const int,
                          any_tg
            >);

            static_assert(tr<const int,
                          any_const_tg, t<int>
            >);

            static_assert(tr<const int* const* volatile*,
                          any_non_volatile_tg, tts<AND_tg, nkr::pointer::cpp_t, nkr::pointer::cpp_ttg>,
                          of_any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, ts<OR_tg, int, short>
            >);

            static_assert(tr<int,
                          any_tg, ts<NOR_tg, short, long long int>
            >);

            // even ts and tts can be used with just_tg
            static_assert(tr<const int* const* volatile* const,
                          just_tg, const tts<AND_tg, nkr::pointer::cpp_t, nkr::pointer::cpp_ttg>,
                          of_any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_just_tg, const ts<OR_tg, int, short>
            >);
        }

        TEST_SUITE("temp")
        {
            static_assert(TR<t<int>,
                          any_tg, ts<OR_tg, int, short>>());

            static_assert(TR<t<short>,
                          any_tg, ts<OR_tg, int, short>>());

            static_assert(TR<ts<OR_tg, int, short>,
                          any_tg, ts<OR_tg, int, short>>());

            static_assert(TR<ts<OR_tg, short, int>,
                          any_tg, ts<OR_tg, int, short>>());

            static_assert(TR<ts<AND_tg, int, short>,
                          any_tg, ts<OR_tg, int, short>>());
        }

        TEST_SUITE("temp")
        {
            static_assert(TR<t<long>,
                          any_tg, ts<XOR_tg, short, long>>());
            static_assert(TR<t<long>,
                          any_tg, ts<XOR_tg, short, long, long long>>());
            static_assert(TR<t<long>,
                          any_tg, ts<XNOR_tg, short, long long, long long>>());
            static_assert(TR<t<long>,
                          any_tg, ts<XNOR_tg, short, long, long>>());
        }

        TEST_CASE("to")
        {
            static_assert(TR<t<int>,
                          to_tg, t<int>>());
            static_assert(TR<t<int*>,
                          to_tg, tt<nkr::pointer::cpp_t>,
                          of_just_tg, t<int>>());
            static_assert(TR<t<int**>,
                          to_tg, tt<nkr::pointer::cpp_t>,
                          of_just_tg, tt<nkr::pointer::cpp_t>,
                          of_just_tg, t<int>>());
            static_assert(TR<t<int&>,
                          to_tg, tt<nkr::reference::lvalue_t>,
                          of_just_tg, t<int>>());
            static_assert(TR<t<int&&>,
                          to_tg, tt<nkr::reference::rvalue_t>,
                          of_just_tg, t<int>>());

            static_assert(TR<t<int>,
                          to_tg, tt<nkr::reference::lvalue_t>,
                          of_just_tg, t<int>>());
            static_assert(TR<t<int>,
                          to_tg, tt<nkr::reference::rvalue_t>,
                          of_just_tg, t<int>>());
        }

        TEST_CASE("to with qualification")
        {
            class test_t
            {
            public:
                constexpr test_t() noexcept
                {
                }

                constexpr test_t(const test_t& other) noexcept
                {
                }

                constexpr test_t(const volatile test_t& other) noexcept
                {
                }

                constexpr test_t(test_t&& other) noexcept
                {

                }

                constexpr test_t(volatile test_t&& other) noexcept
                {
                }
            };

            static_assert(TR<t<test_t>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<test_t>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<test_t>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<test_t>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<test_t&>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<test_t&>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<test_t&>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<test_t&>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<test_t&&>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<test_t&&>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<test_t&&>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<test_t&&>,
                          to_tg, t<const volatile test_t>>());

            static_assert(TR<t<const test_t>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<const test_t>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<const test_t>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<const test_t>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<const test_t&>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<const test_t&>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<const test_t&>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<const test_t&>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<const test_t&&>,
                          not_to_tg, t<test_t>>());
            static_assert(TR<t<const test_t&&>,
                          not_to_tg, t<const test_t>>());
            static_assert(TR<t<const test_t&&>,
                          not_to_tg, t<volatile test_t>>());
            static_assert(TR<t<const test_t&&>,
                          not_to_tg, t<const volatile test_t>>());

            static_assert(TR<t<volatile test_t>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<volatile test_t>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<volatile test_t>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<volatile test_t>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<volatile test_t&>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<volatile test_t&>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<volatile test_t&>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<volatile test_t&>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<volatile test_t&&>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<volatile test_t&&>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<volatile test_t&&>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<volatile test_t&&>,
                          to_tg, t<const volatile test_t>>());

            static_assert(TR<t<const volatile test_t>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<const volatile test_t>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<const volatile test_t>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<const volatile test_t>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<const volatile test_t&>,
                          to_tg, t<test_t>>());
            static_assert(TR<t<const volatile test_t&>,
                          to_tg, t<const test_t>>());
            static_assert(TR<t<const volatile test_t&>,
                          to_tg, t<volatile test_t>>());
            static_assert(TR<t<const volatile test_t&>,
                          to_tg, t<const volatile test_t>>());
            static_assert(TR<t<const volatile test_t&&>,
                          not_to_tg, t<test_t>>());
            static_assert(TR<t<const volatile test_t&&>,
                          not_to_tg, t<const test_t>>());
            static_assert(TR<t<const volatile test_t&&>,
                          not_to_tg, t<volatile test_t>>());
            static_assert(TR<t<const volatile test_t&&>,
                          not_to_tg, t<const volatile test_t>>());

            static_assert(TR<t<const test_t*>,
                          to_tg, tt<nkr::pointer::cpp_t>,
                          of_just_tg, const t<test_t>>());
        }

        TEST_CASE("making sure Evaluate_Expression maintains qualification on expression parts")
        {
            static_assert(TR<const ts<AND_tg, int, int, int, int, int>,
                          just_tg, const ts<AND_tg, int, int, int, int, int, int>>());

            static_assert(TR<t<const int* const volatile* volatile>,
                          just_tg, volatile tts<AND_tg, nkr::pointer::cpp_t, nkr::pointer::cpp_t, nkr::pointer::cpp_t, nkr::pointer::cpp_t>,
                          of_just_tg, const volatile tts<XOR_tg, nkr::array::cpp_t, nkr::pointer::cpp_t, nkr::array::cpp_t, nkr::array::cpp_t>,
                          of_just_tg, const ts<AND_tg, int, int, int, int, int, int, int, int, int, int>>());
        }
    }

}

// Examples: nkr::TR
TEST_CASE("")
{
    // [_19a3f5b7_c3aa_4e86_bb68_1cfd8c306cda]
    using namespace nkr;

    static_assert(TR<
               /* subject */
                  t<int>,

               /* operator, operand */
                  any_tg, t<int>
    >() == true);
    // [_19a3f5b7_c3aa_4e86_bb68_1cfd8c306cda]
}

TEST_CASE("")
{
    // [_008550d1_21e3_4bae_8844_b85ca680e16a]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  any_tg, t<int>
    >() == true);
    // [_008550d1_21e3_4bae_8844_b85ca680e16a]
}

TEST_CASE("")
{
    // [_236e3aa6_fd72_446d_ad8e_10d3afce07a3]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  any_tg
    >() == true);

    static_assert(TR<
                  t<float>,
                  any_tg
    >() == true);
    // [_236e3aa6_fd72_446d_ad8e_10d3afce07a3]
}

TEST_CASE("")
{
    // [_6d5532ca_8399_4a97_9e58_60e7bf7f7eb2]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  any_const_tg
    >() == false);

    static_assert(TR<
                  t<const int>,
                  any_const_tg
    >() == true);

    static_assert(TR<
                  t<float>,
                  any_const_tg
    >() == false);

    static_assert(TR<
                  t<const float>,
                  any_const_tg
    >() == true);

    static_assert(TR<
                  t<int>,
                  any_volatile_tg
    >() == false);

    static_assert(TR<
                  t<volatile int>,
                  any_volatile_tg
    >() == true);

    static_assert(TR<
                  t<float>,
                  any_volatile_tg
    >() == false);

    static_assert(TR<
                  t<volatile float>,
                  any_volatile_tg
    >() == true);
    // [_6d5532ca_8399_4a97_9e58_60e7bf7f7eb2]
}

TEST_CASE("")
{
    // [_655eeb36_08b4_4a4c_bd0c_e36f89db9736]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  any_const_tg, t<int>
    >() == false);

    static_assert(TR<
                  t<const int>,
                  any_const_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<const int>,
                  any_const_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<float>,
                  any_volatile_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<volatile float>,
                  any_volatile_tg, t<float>
    >() == true);

    static_assert(TR<
                  t<volatile float>,
                  any_volatile_tg, t<int>
    >() == false);
    // [_655eeb36_08b4_4a4c_bd0c_e36f89db9736]
}

TEST_CASE("")
{
    // [_24f822e7_6c8f_4ce5_8ecc_f8b142a8f635]
    using namespace nkr;

    static_assert(TR<
                  t<const int>,
                  any_const_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<const volatile int>,
                  any_const_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<volatile float>,
                  any_volatile_tg, t<float>
    >() == true);

    static_assert(TR<
                  t<const volatile float>,
                  any_volatile_tg, t<float>
    >() == true);
    // [_24f822e7_6c8f_4ce5_8ecc_f8b142a8f635]
}

TEST_CASE("")
{
    // [_b760cc4f_cd3c_49e7_b19d_ebecb0c444fc]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  any_qualified_tg, t<int>
    >() == false);

    static_assert(TR<
                  t<const int>,
                  any_qualified_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<volatile int>,
                  any_qualified_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<const volatile int>,
                  any_qualified_tg, t<int>
    >() == true);
    // [_b760cc4f_cd3c_49e7_b19d_ebecb0c444fc]
}

TEST_CASE("")
{
    // [_2db89416_6998_4dcb_91d1_4ff326956702]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  any_non_qualified_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<const int>,
                  any_non_qualified_tg, t<int>
    >() == false);

    static_assert(TR<
                  t<volatile int>,
                  any_non_qualified_tg, t<int>
    >() == false);

    static_assert(TR<
                  t<const volatile int>,
                  any_non_qualified_tg, t<int>
    >() == false);
    // [_2db89416_6998_4dcb_91d1_4ff326956702]
}

TEST_CASE("")
{
    // [_c5229a18_0f89_4919_b18f_2a87a5c6ded5]
    using namespace nkr;

    static_assert(TR<
                  t<int>,
                  just_tg, t<const int>
    >() == false);

    static_assert(TR<
                  t<const int>,
                  just_tg, t<const int>
    >() == true);

    static_assert(TR<
                  t<float>,
                  just_tg, t<volatile float>
    >() == false);

    static_assert(TR<
                  t<volatile float>,
                  just_tg, t<volatile float>
    >() == true);
    // [_c5229a18_0f89_4919_b18f_2a87a5c6ded5]
}

TEST_CASE("")
{
    // [_d43e49fd_9953_4e45_b787_da4dd4be0018]
    using namespace nkr;

    static_assert(TR<
                  t<const int>,
                  just_non_qualified_tg, t<int>
    >() == false);

    static_assert(TR<
                  t<int>,
                  just_non_qualified_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<float>,
                  just_const_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<const float>,
                  just_const_tg, t<float>
    >() == true);

    static_assert(TR<
                  t<int>,
                  just_volatile_tg, t<int>
    >() == false);

    static_assert(TR<
                  t<volatile int>,
                  just_volatile_tg, t<int>
    >() == true);

    static_assert(TR<
                  t<float>,
                  just_const_volatile_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<const float>,
                  just_const_volatile_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<volatile float>,
                  just_const_volatile_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<const volatile float>,
                  just_const_volatile_tg, t<float>
    >() == true);
    // [_d43e49fd_9953_4e45_b787_da4dd4be0018]
}

TEST_CASE("")
{
    // [_3a337d2c_afd1_4cf0_abb9_f7565d351f84]
    using namespace nkr;

    static_assert(TR<
                  t<const int>,
                  just_tg, t<const int>
    >() == true);

    static_assert(TR<
                  t<const int>,
                  just_const_tg, t<volatile int>
    >() == true);

    static_assert(TR<
                  t<const volatile int>,
                  just_const_tg, t<volatile int>
    >() == false);
    // [_3a337d2c_afd1_4cf0_abb9_f7565d351f84]
}

TEST_CASE("")
{
    // [_4f3d5c98_22ec_4d5a_bf75_08462f1be395]
    using namespace nkr;

    using alias_of_int_t = volatile int;

    static_assert(TR<
                  t<const volatile int>,
                  just_const_tg, t<alias_of_int_t>
    >() == false);

    static_assert(TR<
                  t<const int>,
                  just_const_tg, t<alias_of_int_t>
    >() == true);
    // [_4f3d5c98_22ec_4d5a_bf75_08462f1be395]
}

TEST_CASE("")
{
    // [_17ac0ffa_ab9b_4e98_a3ff_91f45a911c09]
    using namespace nkr;

    using alias_of_int_t = volatile int;

    static_assert(TR<
                  t<const volatile int>,
                  just_tg, t<const alias_of_int_t>
    >() == true);

    static_assert(TR<
                  t<const int>,
                  just_tg, t<const alias_of_int_t>
    >() == false);
    // [_17ac0ffa_ab9b_4e98_a3ff_91f45a911c09]
}

TEST_CASE("")
{
    // [_de9f97b4_db90_42bf_b9b9_f2166a5d4fcb]
    using namespace nkr;

    static_assert(TR<
                  t<int*>,
                  any_tg, t<int*>
    >() == true);

    static_assert(TR<
                  t<int[256]>,
                  any_tg, t<int[256]>
    >() == true);

    static_assert(TR<
                  t<int&>,
                  any_tg, t<int&>
    >() == true);

    static_assert(TR<
                  t<int&&>,
                  any_tg, t<int&&>
    >() == true);
    // [_de9f97b4_db90_42bf_b9b9_f2166a5d4fcb]
}

TEST_CASE("")
{
    // [_19915f22_ec07_4242_99e1_43cc4599420c]
    using namespace nkr;

    static_assert(TR<
                  t<int*>,
                  just_tg, t<const int*>
    >() == false);

    static_assert(TR<
                  t<const int*>,
                  just_tg, t<const int*>
    >() == true);

    static_assert(TR<
                  t<int*>,
                  just_tg, t<int* const>
    >() == false);

    static_assert(TR<
                  t<int* const>,
                  just_tg, t<int* const>
    >() == true);

    static_assert(TR<
                  t<int* const>,
                  just_tg, t<const int* const>
    >() == false);

    static_assert(TR<
                  t<const int* const>,
                  just_tg, t<const int* const>
    >() == true);

    static_assert(TR<
                  t<int[256]>,
                  just_tg, t<volatile int[256]>
    >() == false);

    static_assert(TR<
                  t<volatile int[256]>,
                  just_tg, t<volatile int[256]>
    >() == true);

    static_assert(TR<
                  t<int&>,
                  just_tg, t<const int&>
    >() == false);

    static_assert(TR<
                  t<const int&>,
                  just_tg, t<const int&>
    >() == true);

    static_assert(TR<
                  t<int&&>,
                  just_tg, t<volatile int&&>
    >() == false);

    static_assert(TR<
                  t<volatile int&&>,
                  just_tg, t<volatile int&&>
    >() == true);
    // [_19915f22_ec07_4242_99e1_43cc4599420c]
}

TEST_CASE("")
{
    // [_78dd14b0_5e07_4515_bf85_67522602406b]
    using namespace nkr;

    static_assert(TR<
                  t<int[1]>,
                  any_tg, t<int[2]>
    >() == false);
    // [_78dd14b0_5e07_4515_bf85_67522602406b]
}

TEST_CASE("")
{
    // [_371738b1_f8c5_4ebf_b8e4_a7bd23e4ab44]
    using namespace nkr;

    static_assert(TR<
                  t<int*>,
                  any_tg, t<nkr::pointer::cpp_t<int>>
    >() == true);

    static_assert(TR<
                  t<int*>,
                  any_tg, t<nkr::pointer::cpp_t<float>>
    >() == false);
    // [_371738b1_f8c5_4ebf_b8e4_a7bd23e4ab44]
}

TEST_CASE("")
{
    // [_f06311f0_df34_4df8_af3b_4753b1c4d6b1]
    using namespace nkr;

    static_assert(TR<
                  t<int*>,
                  any_tg, tt<nkr::pointer::cpp_t>,
                  of_any_tg, t<int>
    >() == true);
    // [_f06311f0_df34_4df8_af3b_4753b1c4d6b1]
}

TEST_CASE("")
{
    // [_59ddfa80_4281_4c2c_9838_d215d7528058]
    using namespace nkr;

    static_assert(TR<
                  t<int*>,
                  any_tg, tt<nkr::pointer::cpp_ttg>,
                  of_any_tg, t<int>
    >() == true);
    // [_59ddfa80_4281_4c2c_9838_d215d7528058]
}

TEST_CASE("")
{
    // [_b0d595d6_4012_4b2b_89ac_3a861aca7af7]
    using namespace nkr;

    static_assert(TR<
                  t<int*>,
                  any_tg, t<nkr::pointer::cpp_tg>
    >() == true);

    static_assert(TR<
                  t<float*>,
                  any_tg, t<nkr::pointer::cpp_tg>
    >() == true);
    // [_b0d595d6_4012_4b2b_89ac_3a861aca7af7]
}

TEST_CASE("")
{
    // [_15b00d3d_2838_4308_a2ce_77071393e5d5]
    using namespace nkr;

    static_assert(TR<
                  t<int****>,
                  any_tg, tt<nkr::pointer::cpp_t>,
                  of_any_tg, tt<nkr::pointer::cpp_t>,
                  of_any_tg, tt<nkr::pointer::cpp_t>,
                  of_any_tg, tt<nkr::pointer::cpp_t>,
                  of_any_tg, t<int>
    >() == true);
    // [_15b00d3d_2838_4308_a2ce_77071393e5d5]
}

TEST_CASE("")
{
    // [_1374a6bc_a3e9_4663_90d7_45bf338a9077]
    using namespace nkr;

    static_assert(TR<
                  t<const int* volatile&>,
                  any_tg, tt<nkr::reference::lvalue_t>,
                  of_any_non_const_tg, tt<nkr::pointer::cpp_t>,
                  of_any_tg, t<int>
    >() == true);
    // [_1374a6bc_a3e9_4663_90d7_45bf338a9077]
}

TEST_CASE("")
{
    // [_2e80ad9f_7fa0_4d4f_ba2c_7f56d92659d3]
    using namespace nkr;

    static_assert(TR<t<nkr::negatable::integer_t>,
                  any_tg, ts<OR_tg, nkr::negatable::integer_t, nkr::negatable::real_t>>() == true);

    static_assert(TR<t<nkr::negatable::real_t>,
                  any_tg, ts<OR_tg, nkr::negatable::integer_t, nkr::negatable::real_t>>() == true);
    // [_2e80ad9f_7fa0_4d4f_ba2c_7f56d92659d3]
}

TEST_CASE("")
{
    // [_898208a2_8cc9_48cb_a4b5_c7bdada49152]
    using namespace nkr;

    static_assert(TR<t<nkr::negatable::integer_t>,
                  any_tg, ts<AND_tg, nkr::generic::negatable_tg, nkr::generic::number_tg>>() == true);

    static_assert(TR<t<nkr::negatable::real_t>,
                  any_tg, ts<AND_tg, nkr::generic::negatable_tg, nkr::generic::number_tg>>() == true);
    // [_898208a2_8cc9_48cb_a4b5_c7bdada49152]
}

TEST_CASE("")
{
    // [_ea052059_b418_4201_9690_5166d46ff670]
    using namespace nkr;

    static_assert(TR<t<nkr::boolean::cpp_t>,
                  any_tg, ts<XOR_tg, nkr::generic::boolean_tg, nkr::generic::user_defined_tg>>() == true);

    static_assert(TR<t<nkr::boolean::pure_t>,
                  any_tg, ts<XOR_tg, nkr::generic::boolean_tg, nkr::generic::user_defined_tg>>() == false);
    // [_ea052059_b418_4201_9690_5166d46ff670]
}

TEST_CASE("")
{
    // [_01233b5b_1059_4d1d_a06b_50643a3f30eb]
    using namespace nkr;

    using true_t = nkr::positive::integer_t;
    using false_t = nkr::negatable::integer_t;

    static_assert(TR<ts<OR_tg, false_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<OR_tg, false_t, true_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<OR_tg, true_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<OR_tg, true_t, true_t>, any_tg, t<true_t>>() == true);

    static_assert(TR<ts<AND_tg, false_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<AND_tg, false_t, true_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<AND_tg, true_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<AND_tg, true_t, true_t>, any_tg, t<true_t>>() == true);

    static_assert(TR<ts<XOR_tg, false_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XOR_tg, false_t, true_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XOR_tg, true_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XOR_tg, true_t, true_t>, any_tg, t<true_t>>() == false);

    static_assert(TR<ts<XOR_tg, false_t, false_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XOR_tg, true_t, false_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XOR_tg, false_t, true_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XOR_tg, false_t, false_t, true_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XOR_tg, true_t, true_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XOR_tg, false_t, true_t, true_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XOR_tg, true_t, false_t, true_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XOR_tg, true_t, true_t, true_t>, any_tg, t<true_t>>() == false);

    static_assert(TR<ts<NOR_tg, false_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<NOR_tg, false_t, true_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<NOR_tg, true_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<NOR_tg, true_t, true_t>, any_tg, t<true_t>>() == false);

    static_assert(TR<ts<NAND_tg, false_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<NAND_tg, false_t, true_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<NAND_tg, true_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<NAND_tg, true_t, true_t>, any_tg, t<true_t>>() == false);

    static_assert(TR<ts<XNOR_tg, false_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XNOR_tg, false_t, true_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XNOR_tg, true_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XNOR_tg, true_t, true_t>, any_tg, t<true_t>>() == true);

    static_assert(TR<ts<XNOR_tg, false_t, false_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XNOR_tg, true_t, false_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XNOR_tg, false_t, true_t, false_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XNOR_tg, false_t, false_t, true_t>, any_tg, t<true_t>>() == false);
    static_assert(TR<ts<XNOR_tg, true_t, true_t, false_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XNOR_tg, false_t, true_t, true_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XNOR_tg, true_t, false_t, true_t>, any_tg, t<true_t>>() == true);
    static_assert(TR<ts<XNOR_tg, true_t, true_t, true_t>, any_tg, t<true_t>>() == true);
    // [_01233b5b_1059_4d1d_a06b_50643a3f30eb]
}

TEST_CASE("")
{
    // [_76decf6a_1e47_43c3_9413_4b9a895b73e3]
    using namespace nkr;

    static_assert(TR<t<nkr::positive::integer_t*>,
                  any_tg, tts<OR_tg, nkr::pointer::cpp_ttg, nkr::array::cpp_ttg>,
                  of_any_tg, t<nkr::positive::integer_t>>());

    static_assert(TR<t<nkr::positive::integer_t[1]>,
                  any_tg, tts<OR_tg, nkr::pointer::cpp_ttg, nkr::array::cpp_ttg>,
                  of_any_tg, t<nkr::positive::integer_t>>());
    // [_76decf6a_1e47_43c3_9413_4b9a895b73e3]
}

#pragma warning (disable : 4101)

TEST_SUITE("Use-Cases")
{
    TEST_SUITE("Dynamically Define Concepts In-Place")
    {
        // [_1eb89575_6738_4a9f_970d_ec9694d4b9d7]
        void Combine(auto& vector_a, auto& vector_b)
        {
            using vector_a_t = std::remove_reference_t<decltype(vector_a)>;

            vector_a.reserve(vector_a.size() + vector_b.size());
            for (auto itr = vector_b.begin(); itr != vector_b.end(); ++itr) {
                vector_a.push_back(static_cast<typename vector_a_t::value_type>(*itr));
            }

            vector_b.clear();
        }

        TEST_CASE("should move elements from vector_b to vector_a")
        {
            std::vector<float> vector_a{ 10.0f, 20.0f };
            std::vector<int> vector_b{ 30, 40 };

            CHECK(vector_a.size() == 2);
            CHECK(vector_b.size() == 2);

            Combine(vector_a, vector_b);

            CHECK(vector_a.size() == 4);
            CHECK(vector_b.size() == 0);

            CHECK(vector_a[0] == 10.0f);
            CHECK(vector_a[1] == 20.0f);
            CHECK(vector_a[2] == 30.0f);
            CHECK(vector_a[3] == 40.0f);
        }
        // [_1eb89575_6738_4a9f_970d_ec9694d4b9d7]

        // [_67458ff6_c7f5_46e6_b24e_24f4c565ab62]
        TEST_CASE("will give a compile error not very friendly towards the user of our function")
        {
            std::vector<float> vector{ 10.0f, 20.0f };
            std::forward_list<int> forward_list{ 30, 40 };

            // Combine(vector, forward_list);
            // ERROR: 'size': is not a member of 'std::forward_list<int,std::allocator<int>>'
        }
        // [_67458ff6_c7f5_46e6_b24e_24f4c565ab62]

        // [_69e2f254_d945_4a7b_a8f1_09264cd66821]
        template <typename type_p>
        concept has_size =
            requires(type_p instance)
        {
            { instance.size() } -> std::same_as<std::size_t>;
        };

        void Combine_If_Has_Size(has_size auto& vector_a, has_size auto& vector_b)
        {
            // ...
        }

        TEST_CASE("should give a more user-friendly compile error")
        {
            std::vector<float> vector{ 10.0f, 20.0f };
            std::forward_list<int> forward_list{ 30, 40 };

            // Combine_If_Has_Size(vector, forward_list);
            // ERROR: 'Combine_If_Has_Size': no matching overloaded function found
            // ERROR: 'Combine_If_Has_Size': the associated constraints are not satisfied
        }
        // [_69e2f254_d945_4a7b_a8f1_09264cd66821]

        // [_80ac1030_b280_42c4_9c4f_e70b43e05f11]
        TEST_CASE("will not give a user-friendly compile error")
        {
            std::vector<float> vector{ 10.0f, 20.0f };
            std::unordered_map<std::string, int> unordered_map;

            // Combine_If_Has_Size(vector, unordered_map);
            // ERROR: 'static_cast': cannot convert from 'std::pair<const std::string,int>' to 'float'
        }
        // [_80ac1030_b280_42c4_9c4f_e70b43e05f11]

        // [_33593243_fddd_4839_b95d_32f1ef8aba3b]
        class user_defined_t
        {
        public:
            std::size_t size()
            {
                return 42;
            }
        };

        TEST_CASE("will also not give a user-friendly compile error")
        {
            std::vector<float> vector{ 10.0f, 20.0f };
            user_defined_t user_defined;

            CHECK(user_defined.size() == 42);

            // Combine_If_Has_Size(vector, user_defined);
            // ERROR: 'begin': is not a member of 'user_defined_t'
        }
        // [_33593243_fddd_4839_b95d_32f1ef8aba3b]

        // [_d244a6f8_6154_41f6_8a41_f8eba234289b]
        template <typename type_p>
        struct is_vector :
            public std::false_type
        {
        };

        template <typename value_type, typename allocator_type>
        struct is_vector<std::vector<value_type, allocator_type>> :
            public std::true_type
        {
        };

        template <typename type_p>
        concept is_vector_1 =
            is_vector<type_p>::value;

        static_assert(is_vector_1<std::vector<int>> == true);
        static_assert(is_vector_1<std::forward_list<int>> == false);
        static_assert(is_vector_1<std::unordered_map<std::string, int>> == false);
        static_assert(is_vector_1<user_defined_t> == false);

        void Combine_If_Is_Vector_1(is_vector_1 auto& vector_a, is_vector_1 auto& vector_b);
        // [_d244a6f8_6154_41f6_8a41_f8eba234289b]

        // [_d87f347d_24a8_43f9_a87a_e0ec26b25bd6]
        template <typename type_p>
        concept is_vector_2 = std::same_as<
            type_p,
            std::vector<typename type_p::value_type, typename type_p::allocator_type>
        >;

        static_assert(is_vector_2<std::vector<int>> == true);
        static_assert(is_vector_2<std::forward_list<int>> == false);
        static_assert(is_vector_2<std::unordered_map<std::string, int>> == false);
        static_assert(is_vector_2<user_defined_t> == false);

        void Combine_If_Is_Vector_2(is_vector_2 auto& vector_a, is_vector_2 auto& vector_b);
        // [_d87f347d_24a8_43f9_a87a_e0ec26b25bd6]

        // [_f3feb95c_c2e0_47f9_9bbb_0ddae4e4de2e]
        static_assert(is_vector_1<const std::vector<int>> == false);
        static_assert(is_vector_2<const std::vector<int>> == false);
        // [_f3feb95c_c2e0_47f9_9bbb_0ddae4e4de2e]

        // [_bdba9807_d875_4e5f_8b01_66662833310d]
        void Combine_Non_Const_Vectors(nkr::tr<nkr::any_non_const_tg, nkr::tt<std::vector>> auto& vector_a,
                                       nkr::tr<nkr::any_non_const_tg, nkr::tt<std::vector>> auto& vector_b)
        {
            using vector_a_t = std::remove_reference_t<decltype(vector_a)>;

            vector_a.reserve(vector_a.size() + vector_b.size());
            for (auto itr = vector_b.begin(); itr != vector_b.end(); ++itr) {
                vector_a.push_back(static_cast<typename vector_a_t::value_type>(*itr));
            }

            vector_b.clear();
        }

        TEST_CASE("should fulfill most of our design specifications")
        {
            std::vector<float> vector_a;
            std::vector<int> vector_b;
            std::forward_list<int> forward_list;
            std::unordered_map<std::string, int> unordered_map;
            const std::vector<float> const_vector_a;
            const std::vector<int> const_vector_b;

            // works beautifully
            Combine_Non_Const_Vectors(vector_a, vector_b);

            // and all of these fail to compile: "the associated constraints are not satisfied"
            // Combine_Non_Const_Vectors(vector_a, forward_list);
            // Combine_Non_Const_Vectors(vector_a, unordered_map);
            // Combine_Non_Const_Vectors(const_vector_a, vector_b);
            // Combine_Non_Const_Vectors(vector_a, const_vector_b);
        }
        // [_bdba9807_d875_4e5f_8b01_66662833310d]
        
        // [_9728b2d9_8986_46b7_b27b_a0d777cf2c90]
        void Combine_Non_Const_Compatible_Vectors(nkr::tr<nkr::any_non_const_tg, nkr::tt<std::vector>> auto& vector_a,
                                                  nkr::tr<nkr::any_non_const_tg, nkr::tt<std::vector>> auto& vector_b)
        {
            using vector_a_t = std::remove_reference_t<decltype(vector_a)>;
            using vector_b_t = std::remove_reference_t<decltype(vector_b)>;

            static_assert(nkr::tr<
                          typename vector_b_t::value_type,
                          nkr::to_tg, nkr::t<typename vector_a_t::value_type>
            >, "the values of vector_b cannot be converted to the value_type of vector_a");

            vector_a.reserve(vector_a.size() + vector_b.size());
            for (auto itr = vector_b.begin(); itr != vector_b.end(); ++itr) {
                vector_a.push_back(static_cast<typename vector_a_t::value_type>(*itr));
            }

            vector_b.clear();
        }

        TEST_CASE("should fulfill the rest of our design specifications")
        {
            std::vector<float> vector_a;
            std::vector<int> vector_b;
            std::vector<void*> vector_c;

            // works perfectly
            Combine_Non_Const_Compatible_Vectors(vector_a, vector_b);

            // fails with our error message: "the values of vector_b cannot be converted to the value_type of vector_a"
            // Combine_Non_Const_Compatible_Vectors(vector_a, vector_c);
        }
        // [_9728b2d9_8986_46b7_b27b_a0d777cf2c90]

        // [_0642efde_b645_4ca3_bb58_f094905d5c2e]
        void Combine_With_Overloads(nkr::tr<nkr::any_non_const_tg, nkr::tt<std::vector>> auto& vector_a,
                                    nkr::tr<nkr::any_non_const_tg, nkr::tt<std::vector>> auto& vector_b)
        {
            // ...
        }

        void Combine_With_Overloads(nkr::tr<nkr::any_non_const_tg, nkr::tt<std::forward_list>> auto& forward_list_a,
                                    nkr::tr<nkr::any_non_const_tg, nkr::tt<std::forward_list>> auto& forward_list_b)
        {
            // ...
        }

        TEST_CASE("should work with non-const std::vectors or non-const std::forward_lists")
        {
            std::vector<float> vector_a;
            std::vector<int> vector_b;

            Combine_With_Overloads(vector_a, vector_b);

            std::forward_list<float> forward_list_a;
            std::forward_list<int> forward_list_b;

            Combine_With_Overloads(forward_list_a, forward_list_b);
        }
        // [_0642efde_b645_4ca3_bb58_f094905d5c2e]
    }

    TEST_SUITE("constrain to inner types, even when there is more than one template")
    {

    }

    // volatile methods

    TEST_SUITE("Cleanly Negate Concepts")
    {
        TEST_SUITE("")
        {
            // [_4d0e3bec_7bd6_4a17_ae41_691eb0d71080]
            enum class result_e
            {
                WILL_COPY,
                WILL_CONVERT,
                WILL_MOVE,
            };

            template <typename element_p>
            class container_t
            {
            public:
                using element_t = element_p;

            public:
                result_e Add(std::convertible_to<element_t> auto& element_to_copy_or_non_element_to_convert)
                {
                    using argument_t = std::remove_cvref_t<decltype(element_to_copy_or_non_element_to_convert)>;

                    if constexpr (std::same_as<argument_t, element_t>) {
                        return result_e::WILL_COPY;
                    } else {
                        return result_e::WILL_CONVERT;
                    }
                }

                result_e Add(std::same_as<element_t> auto&& element_to_move)
                {
                    return result_e::WILL_MOVE;
                }
            };

            TEST_CASE("should select the appropriate overload depending on the type and qualification")
            {
                container_t<long long> container;
                long long element_to_copy = 0;
                long other_to_convert = 0;
                long long element_to_move = 0;

                CHECK(container.Add(element_to_copy) == result_e::WILL_COPY);
                CHECK(container.Add(other_to_convert) == result_e::WILL_CONVERT);
                CHECK(container.Add(std::move(element_to_move)) == result_e::WILL_MOVE);
            }
            // [_4d0e3bec_7bd6_4a17_ae41_691eb0d71080]

            // [_891ccf29_a571_4cf2_b6d6_f4cb1596d13e]
            TEST_CASE("will have a confusing compile-time error when moving something other than element_t")
            {
                container_t<long long> container;
                long other_to_move = 0;

                // ERROR: result_e container_t<__int64>::Add<long>(_T0 &)': cannot convert argument 1 from 'long' to '_T0 &'
                // container.Add(std::move(other_to_move));
            }
            // [_891ccf29_a571_4cf2_b6d6_f4cb1596d13e]
        }

        TEST_SUITE("")
        {
            // [_c7c83cab_5715_4153_b61b_7e2aa3ab2fe4]
            template <typename element_p>
            class container_t
            {
            public:
                using element_t = element_p;

            public:
                void Add(std::convertible_to<element_t> auto& element_to_copy_or_non_element_to_convert)
                {
                    // ...
                }

                void Add(std::same_as<element_t> auto&& element_to_move)
                {
                    // ...
                }

                // ERROR: syntax error: '!'
                // void Add(!std::same_as<element_t> auto&&) = delete;
            };
            // [_c7c83cab_5715_4153_b61b_7e2aa3ab2fe4]
        }

        TEST_SUITE("")
        {
            // [_71f8326b_8eff_41d5_aaff_159d7b731959]
            template <typename element_p>
            class container_t
            {
            public:
                using element_t = element_p;

            public:
                void Add(std::convertible_to<element_t> auto& element_to_copy_or_non_element_to_convert)
                {
                    // ...
                }

                void Add(std::same_as<element_t> auto&& element_to_move)
                {
                    // ...
                }

                // Inconsist signature with the above method.
                // It may not even be clear to the user that these two methods are intricately related
                template <typename type_p>
                void Add(type_p&&) requires (!std::same_as<type_p, element_t>) = delete;
            };

            TEST_CASE("will have a better compile-time error")
            {
                container_t<long long> container;
                long other_to_move = 0;

                // ERROR: attempting to reference a deleted function
                // container.Add(std::move(other_to_move));
            }
            // [_71f8326b_8eff_41d5_aaff_159d7b731959]
        }

        TEST_SUITE("")
        {
            // [_eb3e5c90_332f_44a4_9a2d_5c42bdc11403]
            template <typename a, typename b>
            concept not_same_as =
                !std::same_as<a, b>;

            template <typename element_p>
            class container_t
            {
            public:
                using element_t = element_p;

            public:
                void Add(std::convertible_to<element_t> auto& element_to_copy_or_non_element_to_convert)
                {
                    // ...
                }

                void Add(std::same_as<element_t> auto&& element_to_move)
                {
                    // ...
                }

                void Add(not_same_as<element_t> auto&&) = delete;
            };

            TEST_CASE("will have a better compile-time error")
            {
                container_t<long long> container;
                long other_to_move = 0;

                // ERROR: attempting to reference a deleted function
                // container.Add(std::move(other_to_move));
            }
            // [_eb3e5c90_332f_44a4_9a2d_5c42bdc11403]
        }

        TEST_SUITE("")
        {
            // [_2e0e2f4b_2dca_45a9_9915_be7041b222f9]
            template <typename a, typename b>
            concept same_as_non_const =
                std::same_as<a, b> && !std::is_const_v<a>;

            template <typename a, typename b>
            concept not_same_as_non_const =
                !same_as_non_const<a, b>;

            template <typename element_p>
            class container_t
            {
            public:
                using element_t = element_p;

            public:
                void Add(std::convertible_to<element_t> auto& element_to_copy_or_non_element_to_convert)
                {
                    // ...
                }

                void Add(same_as_non_const<element_t> auto&& element_to_move)
                {
                    // ...
                }

                void Add(not_same_as_non_const<element_t> auto&&) = delete;
            };
            // [_2e0e2f4b_2dca_45a9_9915_be7041b222f9]
        }
        
        TEST_SUITE("")
        {
            // [_8e9ee60f_0c2c_4d3f_a843_84072362921b]
            template <typename element_p>
            class container_t
            {
            public:
                using element_t = element_p;

            public:
                void Add(nkr::tr<nkr::to_tg, nkr::t<element_t>> auto& element_to_copy_or_non_element_to_convert)
                {
                    // ...
                }

                void Add(nkr::tr<nkr::any_non_const_tg, nkr::t<element_t>> auto&& element_to_move)
                {
                    // ...
                }

                void Add(nkr::tr<nkr::not_any_non_const_tg, nkr::t<element_t>> auto&&) = delete;
            };

            TEST_CASE("should have better compile-time errors, an easier to read API, and be more robust to change")
            {
                container_t<long long> container;
                long long element_to_copy = 0;
                long other_to_convert = 0;
                long long element_to_move = 0;
                long other_to_move = 0;
                const long long const_element_to_move = 0;

                container.Add(element_to_copy);
                container.Add(other_to_convert);
                container.Add(std::move(element_to_move));

                // ERROR: attempting to reference a deleted function
                // container.Add(std::move(other_to_move));

                // ERROR: attempting to reference a deleted function
                // container.Add(std::move(const_element_to_move));
            }
            // [_8e9ee60f_0c2c_4d3f_a843_84072362921b]
        }
    }

    // class specializations

    // static assertions

    // having better assignment operators

    TEST_SUITE("Succinctly Disambiguate Assignment Operators")
    {
        TEST_SUITE("")
        {
            // [_bccbe189_fffc_4af0_a71a_8077d835593a]
            class safe_bool_t
            {
            public:
                bool value = false;

            public:
                safe_bool_t()
                {
                }

                safe_bool_t(bool value)
                {
                    // ...
                }

                safe_bool_t& operator =(safe_bool_t&& other) noexcept
                {
                    // ...

                    return *this;
                }

                volatile safe_bool_t& operator =(safe_bool_t&& other) volatile noexcept
                {
                    // ...

                    return *this;
                }

                safe_bool_t& operator =(volatile safe_bool_t&& other) noexcept
                {
                    // ...

                    return *this;
                }

                volatile safe_bool_t& operator =(volatile safe_bool_t&& other) volatile noexcept
                {
                    // ...

                    return *this;
                }
            };

            TEST_CASE("should be able to assign value and rvalue references of itself whether volatile or not")
            {
                safe_bool_t safe_bool;
                volatile safe_bool_t volatile_safe_bool;

                safe_bool = safe_bool_t();
                safe_bool = std::move(safe_bool);
                safe_bool = std::move(volatile_safe_bool);
                volatile_safe_bool = safe_bool_t();
                volatile_safe_bool = std::move(safe_bool);
                volatile_safe_bool = std::move(volatile_safe_bool);
            }
            // [_bccbe189_fffc_4af0_a71a_8077d835593a]

            // [_797c89f6_f562_4052_9c68_01a7a7be8f37]
            TEST_CASE("may fail to disambiguate when implicitly assigning through a constructor")
            {
                safe_bool_t safe_bool;
                volatile safe_bool_t volatile_safe_bool;
                bool unsafe_bool = false;

                // ERROR: 'operator =' is ambiguous
                // safe_bool = bool(false);
                // safe_bool = unsafe_bool;
                // volatile_safe_bool = bool(false);
                // volatile_safe_bool = unsafe_bool;
            }
            // [_797c89f6_f562_4052_9c68_01a7a7be8f37]
        }

        TEST_SUITE("")
        {
            // [_3639ae18_40aa_4473_92d7_efc6b93d54ba]
            class safe_bool_t
            {
            public:
                bool value = false;

            public:
                safe_bool_t()
                {
                }

                safe_bool_t(bool value)
                {
                    // ...
                }

                // will handle assignment of bool for non-volatile this
                safe_bool_t& operator =(bool value) noexcept
                {
                    // ...

                    return *this;
                }

                // will handle assignment of bool for volatile this
                volatile safe_bool_t& operator =(bool value) volatile noexcept
                {
                    // ...

                    return *this;
                }

                safe_bool_t& operator =(safe_bool_t&& other) noexcept
                {
                    // ...

                    return *this;
                }

                volatile safe_bool_t& operator =(safe_bool_t&& other) volatile noexcept
                {
                    // ...

                    return *this;
                }

                safe_bool_t& operator =(volatile safe_bool_t&& other) noexcept
                {
                    // ...

                    return *this;
                }

                volatile safe_bool_t& operator =(volatile safe_bool_t&& other) volatile noexcept
                {
                    // ...

                    return *this;
                }
            };

            TEST_CASE("should be able to disambiguate when implicitly assigning through a constructor")
            {
                safe_bool_t safe_bool;
                volatile safe_bool_t volatile_safe_bool;
                bool unsafe_bool = false;

                // works
                safe_bool = bool(false);
                safe_bool = unsafe_bool;
                volatile_safe_bool = bool(false);
                volatile_safe_bool = unsafe_bool;
            }
            // [_3639ae18_40aa_4473_92d7_efc6b93d54ba]
        }

        TEST_SUITE("")
        {
            // [_16b843a2_25b4_48fa_8dc1_70069b6b22ed]
            class safe_bool_t
            {
            public:
                bool value = false;

            public:
                safe_bool_t()
                {
                }

                safe_bool_t(bool value)
                {
                    // ...
                }

                safe_bool_t& operator =(safe_bool_t&& other) noexcept
                {
                    // ...

                    return *this;
                }

                volatile safe_bool_t& operator =(safe_bool_t&& other) volatile noexcept
                {
                    // ...

                    return *this;
                }

                // just volatile safe_bool_t will be accepted by this operator
                safe_bool_t& operator =(nkr::tr<nkr::just_tg, nkr::t<volatile safe_bool_t>> auto&& other) noexcept
                {
                    // ...

                    return *this;
                }

                // just volatile safe_bool_t will be accepted by this operator
                volatile safe_bool_t& operator =(nkr::tr<nkr::just_tg, nkr::t<volatile safe_bool_t>> auto&& other) volatile noexcept
                {
                    // ...

                    return *this;
                }
            };

            TEST_CASE("should work with all assignment possibilities")
            {
                safe_bool_t safe_bool;
                volatile safe_bool_t volatile_safe_bool;
                bool unsafe_bool = false;

                safe_bool = safe_bool_t();
                safe_bool = std::move(safe_bool);
                safe_bool = std::move(volatile_safe_bool);
                safe_bool = bool(false);
                safe_bool = unsafe_bool;
                volatile_safe_bool = safe_bool_t();
                volatile_safe_bool = std::move(safe_bool);
                volatile_safe_bool = std::move(volatile_safe_bool);
                volatile_safe_bool = bool(false);
                volatile_safe_bool = unsafe_bool;
            }
            // [_16b843a2_25b4_48fa_8dc1_70069b6b22ed]
        }
    }

    // easily ensure that interfaces are satisfied
}
