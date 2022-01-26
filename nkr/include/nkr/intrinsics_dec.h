/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_dec.h"

#include "nkr/cpp_dec.h"

namespace nkr { namespace none {

    using   type_t =
        nkr::cpp::none::type_t;

}}

namespace nkr { namespace boolean {

    using   cpp_t =
        nkr::cpp::boolean_t;

    template <cpp_t value_p>
    using   cpp_c =
        nkr::cpp::constant_t<cpp_t, value_p>;

    template <typename type_p>
    concept cpp_ctr =
        nkr::cpp::constant_of_tr<type_p, nkr::boolean::cpp_t>;

}}

namespace nkr { namespace positive {

    using   count_t =
        nkr::cpp::positive::count_t;

    using   index_t =
        nkr::cpp::positive::index_t;

    template <typename type_p>
    concept index_ctr =
        nkr::cpp::constant_of_tr<type_p, index_t>;

    using   integer_t =
        nkr::cpp::positive::integer_t;

}}

namespace nkr { namespace positive {

    using   integer_min_t =
        nkr::cpp::positive::integer_min_t;

    template <integer_min_t value_p>
    using   integer_min_c =
        nkr::cpp::constant_t<integer_min_t, value_p>;

    using   integer_max_t =
        nkr::cpp::positive::integer_max_t;

    template <integer_max_t value_p>
    using   integer_max_c =
        nkr::cpp::constant_t<integer_max_t, value_p>;

}}

namespace nkr { namespace negatable {

    using   integer_t =
        nkr::cpp::negatable::integer_t;

}}

namespace nkr { namespace negatable {

    using   integer_min_t =
        nkr::cpp::negatable::integer_min_t;

    template <integer_min_t value_p>
    using   integer_min_c =
        nkr::cpp::constant_t<integer_min_t, value_p>;

    using   integer_max_t =
        nkr::cpp::negatable::integer_max_t;

    template <integer_max_t value_p>
    using   integer_max_c =
        nkr::cpp::constant_t<integer_max_t, value_p>;

    using   real_min_t =
        nkr::cpp::negatable::real_min_t;

    template <real_min_t value_p>
    using   real_min_c =
        nkr::cpp::constant_t<real_min_t, value_p>;

    using   real_max_t =
        nkr::cpp::negatable::real_max_t;

    template <real_max_t value_p>
    using   real_max_c =
        nkr::cpp::constant_t<real_max_t, value_p>;

}}

#include "nkr/intrinsics_dec_def.h"

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
    class   template_i;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/tuple/templates_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

#include "nkr/none/type_t_dec.h"
#include "nkr/none/pointer_t_dec.h"

#include "nkr/boolean/cpp_t_dec.h"

#include "nkr/positive/byte_t_dec.h"
#include "nkr/positive/count_t_dec.h"
#include "nkr/positive/index_t_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/positive/integer_8_t_dec.h"
#include "nkr/positive/integer_16_t_dec.h"
#include "nkr/positive/integer_32_t_dec.h"
#include "nkr/positive/integer_64_t_dec.h"
#include "nkr/positive/size_t_dec.h"
#include "nkr/positive/word_t_dec.h"

#include "nkr/negatable/byte_t_dec.h"
#include "nkr/negatable/count_t_dec.h"
#include "nkr/negatable/index_t_dec.h"
#include "nkr/negatable/integer_t_dec.h"
#include "nkr/negatable/integer_8_t_dec.h"
#include "nkr/negatable/integer_16_t_dec.h"
#include "nkr/negatable/integer_32_t_dec.h"
#include "nkr/negatable/integer_64_t_dec.h"
#include "nkr/negatable/real_t_dec.h"
#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"
#include "nkr/negatable/size_t_dec.h"
#include "nkr/negatable/word_t_dec.h"

#include "nkr/pointer/cpp_t_dec.h"

#include "nkr/array/cpp_t_dec.h"
