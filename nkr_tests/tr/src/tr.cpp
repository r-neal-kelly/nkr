/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"
#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/pure_t.h"
#include "nkr/generic/boolean_tr.h"
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

            // I think this is kind of unexpected behavior. shouldn't OR become NOR because of the not?
            static_assert(tr<volatile int* const*,
                          not_any_non_qualified_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_any_volatile_tg, ts<OR_tg, nkr::positive::integer_t, int>>);
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
                  t<float>,
                  any_const_tg, t<float>
    >() == false);

    static_assert(TR<
                  t<const float>,
                  any_const_tg, t<float>
    >() == true);
    // [_655eeb36_08b4_4a4c_bd0c_e36f89db9736]
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
