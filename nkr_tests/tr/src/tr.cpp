/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/negatable/integer_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("tr")
    {
        static_assert(tr<nkr::positive::integer_t, any_tg, t<nkr::positive::integer_t>>);
        static_assert(tr<nkr::positive::integer_t, any_tg, t<nkr::positive::integer_t>>);
        static_assert(tr<nkr::positive::integer_t, any_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>>);
        static_assert(tr<nkr::negatable::integer_t, any_non_const_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>>);

        // pretty darn powerful. we still need to get tr3 hooked up though!
        static_assert(tr<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, tts<AND_tg, nkr::pointer::cpp_t, nkr::pointer::cpp_ttg>,
                      of_just_volatile_tg, ts<OR_tg, nkr::positive::integer_t, nkr::negatable::integer_t>>);

        // and of course, one can just the simple tuple wrappers to get the most readable and most common use-case
        static_assert(tr<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_just_volatile_tg, t<nkr::positive::integer_t>>);
        // as compared to:
        static_assert(tr2<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, nkr::pointer::cpp_t,
                      of_just_volatile_tg, nkr::positive::integer_t>);

        // just_tg continues to work!
        static_assert(tr<const volatile nkr::pointer::cpp_t<volatile nkr::positive::integer_t>,
                      any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_just_tg, ts<OR_tg, volatile nkr::positive::integer_t, nkr::negatable::integer_t>>);
        static_assert(tr<const volatile nkr::pointer::cpp_t<nkr::negatable::integer_t>,
                      any_const_tg, tt<nkr::pointer::cpp_t>,
                      of_just_tg, ts<OR_tg, volatile nkr::positive::integer_t, nkr::negatable::integer_t>>);

        // now tr3 is working!
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

        // now with tr0
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

            using operators_t = nkr::$tr::operators_t<expression_parts_t>;
            using subjects_t = nkr::$tr::subjects_t<subject_t, operators_t>;
            using objects_t = nkr::$tr::objects_t<expression_parts_t>;

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

            using operators_t = nkr::$tr::operators_t<expression_parts_t>;
            using subjects_t = nkr::$tr::subjects_t<subject_t, operators_t>;
            using objects_t = nkr::$tr::objects_t<expression_parts_t>;

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

            static_assert(nkr::$tr::Execute<subjects_t, operators_t, objects_t>());
        }

        TEST_SUITE("temp")
        {
            static_assert(nkr::$tr::Single_TR<volatile int* volatile* const, nkr::tuple::types_t<
                          any_tg, tt<nkr::pointer::cpp_t>,
                          of_any_access_const_tg, tt<nkr::pointer::cpp_t>,
                          of_any_access_const_tg, t<int>
                          >>());

            static_assert(nkr::$tr::Single_TR <const volatile int* volatile* const* volatile* const* volatile* const*, nkr::tuple::types_t <
                          just_non_qualified_tg,        tt<nkr::pointer::cpp_t>,
                          of_just_const_tg,             tt<nkr::pointer::cpp_t>,
                          of_just_volatile_tg,          tt<nkr::pointer::cpp_t>,
                          of_just_const_tg,             tt<nkr::pointer::cpp_t>,
                          of_just_volatile_tg,          tt<nkr::pointer::cpp_t>,
                          of_just_const_tg,             tt<nkr::pointer::cpp_t>,
                          of_just_volatile_tg,          tt<nkr::pointer::cpp_t>,
                          of_just_tg,                   t<const volatile int>
                          >>());

            // we now support the just_tg with tt operands as well as inner t and now outer t operands too!
            static_assert(nkr::$tr::Single_TR<const volatile int* const, nkr::tuple::types_t<
                          just_tg,      const tt<nkr::pointer::cpp_t>,
                          of_just_tg,   const t<volatile int>
                          >>());
            // remember, these extra qualifiers are ignored without the just_tg
            static_assert(nkr::$tr::Single_TR<int*, nkr::tuple::types_t<
                          any_tg,       const tt<nkr::pointer::cpp_t>,
                          of_any_tg,    const t<volatile int>
                          >>());

            static_assert(nkr::$tr::Single_TR<const int, nkr::tuple::types_t<
                          any_tg
                          >>());
        }

        TEST_SUITE("temp")
        {
            static_assert(nkr::$tr::Multiple_TR<const int, nkr::tuple::types_t<
                          any_tg
                          >>());

            static_assert(nkr::$tr::Multiple_TR<const int, nkr::tuple::types_t<
                          any_const_tg, t<int>
                          >>());

            static_assert(nkr::$tr::Multiple_TR<const int* const* volatile*, nkr::tuple::types_t<
                          any_non_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_any_volatile_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, tt<nkr::pointer::cpp_t>,
                          of_any_const_tg, t<int>
                          >>());
        }
    }

    TEST_SUITE("nkr::tr1_t")
    {
        using true_t = nkr::positive::integer_t;
        using false_t = nkr::negatable::integer_t;

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::OR<false_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::OR<false_t, true_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::OR<true_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::OR<true_t, true_t>() == true);

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::AND<false_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::AND<false_t, true_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::AND<true_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::AND<true_t, true_t>() == true);

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XOR<false_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XOR<false_t, true_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XOR<true_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XOR<true_t, true_t>() == false);

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NOR<false_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NOR<false_t, true_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NOR<true_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NOR<true_t, true_t>() == false);

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NAND<false_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NAND<false_t, true_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NAND<true_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::NAND<true_t, true_t>() == false);

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<false_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<false_t, true_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<true_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<true_t, true_t>() == true);

        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<false_t, false_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<true_t, false_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<false_t, true_t, false_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<false_t, false_t, true_t>() == false);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<true_t, true_t, false_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<false_t, true_t, true_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<true_t, false_t, true_t>() == true);
        static_assert(tr1_t<any_tg, nkr::positive::integer_t>::XNOR<true_t, true_t, true_t>() == true);
    }

}
