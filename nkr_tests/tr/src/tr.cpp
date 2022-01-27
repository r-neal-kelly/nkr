/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/negatable/integer_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/tr.h"

#include "doctest.h"

namespace nkr {

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
