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
