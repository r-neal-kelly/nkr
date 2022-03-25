/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/cpp/concurrency/locker/inclusive_t.h"
#include "nkr/generic/implementing/interface/template_tr.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("nkr::interface::template_i")
    {
        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::cpp::concurrency::locker::inclusive_t>);
        using template_template_i = nkr::interface::template_i<nkr::cpp::concurrency::locker::inclusive_t>;

        static_assert(nkr::cpp::is_tr<
                      template_template_i::template_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::of_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::of_tuple_t<nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::of_pack_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::example_arguments_t,
                      nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::example_t,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);

        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_template_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_of_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_of_tuple_t<nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_of_pack_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_example_arguments_t,
                      nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_template_i::actual_example_t,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);

        static_assert(nkr::generic::implementing::interface::template_ttr<nkr::cpp::concurrency::locker::inclusive_ttg>);
        using template_tag_i = nkr::interface::template_i<nkr::cpp::concurrency::locker::inclusive_ttg>;

        static_assert(nkr::cpp::is_tr<
                      template_tag_i::template_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::of_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::of_tuple_t<nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::of_pack_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::example_arguments_t,
                      nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::example_t,
                      nkr::cpp::concurrency::locker::inclusive_t<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);

        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_template_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_ttg<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_of_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_ttg<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_of_tuple_t<nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::wide_t>>,
                      nkr::cpp::concurrency::locker::inclusive_ttg<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_of_pack_t<nkr::cpp::concurrency::lock::perpetual::wide_t>,
                      nkr::cpp::concurrency::locker::inclusive_ttg<nkr::cpp::concurrency::lock::perpetual::wide_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_example_arguments_t,
                      nkr::tuple::types_t<>
        >);
        static_assert(nkr::cpp::is_tr<
                      template_tag_i::actual_example_t,
                      nkr::cpp::concurrency::locker::inclusive_ttg<>
        >);
    }

}
