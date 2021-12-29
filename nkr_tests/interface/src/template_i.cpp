/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/safe_t.h"

#include "nkr/generic/array_tr.h"
#include "nkr/generic/array/any_tr.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/impure_tr.h"
#include "nkr/generic/boolean/pure_tr.h"
#include "nkr/generic/implementing/constructor/default_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/negatable_tr.h"
#include "nkr/generic/negatable/any_tr.h"
#include "nkr/generic/negatable/integer_tr.h"
#include "nkr/generic/negatable/real_tr.h"
#include "nkr/generic/non_type_tr.h"
#include "nkr/generic/none_tr.h"
#include "nkr/generic/none/any_tr.h"
#include "nkr/generic/pointer_tr.h"
#include "nkr/generic/pointer/any_tr.h"
#include "nkr/generic/positive_tr.h"
#include "nkr/generic/positive/any_tr.h"
#include "nkr/generic/positive/integer_tr.h"
#include "nkr/generic/type_tr.h"

#include "nkr/generic_template/implementing/template_parameter_list/default_tr.h"
#include "nkr/generic_template/implementing/type_parameter_list/default_tr.h"

#include "nkr/interface/none/value_i.h"
#include "nkr/interface/template_i.h"
#include "nkr/interface/type_i.h"

#include "nkr/negatable/byte_t.h"
#include "nkr/negatable/count_t.h"
#include "nkr/negatable/index_t.h"
#include "nkr/negatable/integer_8_t.h"
#include "nkr/negatable/integer_16_t.h"
#include "nkr/negatable/integer_32_t.h"
#include "nkr/negatable/integer_64_t.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/real_32_t.h"
#include "nkr/negatable/real_64_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/negatable/size_t.h"
#include "nkr/negatable/word_t.h"

#include "nkr/none/pointer_t.h"
#include "nkr/none/type_t.h"
#include "nkr/none/value_t.h"

#include "nkr/pointer/cpp_t.h"

#include "nkr/positive/byte_t.h"
#include "nkr/positive/count_t.h"
#include "nkr/positive/index_t.h"
#include "nkr/positive/integer_8_t.h"
#include "nkr/positive/integer_16_t.h"
#include "nkr/positive/integer_32_t.h"
#include "nkr/positive/integer_64_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/positive/size_t.h"
#include "nkr/positive/word_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("should implement the following interfaces")
    {
        static_assert(generic::implementing::interface::type_tr<interface::template_tg>);
        static_assert(generic::implementing::interface::type_tr<interface::template_i<pointer::cpp_t>>);
    }

}

namespace nkr {

    TEST_SUITE("the following tags should implement this interface")
    {
        //static_assert(generic::implementing::interface::template_tr<array::cpp_ttg>); // failing because we're passing none::type_t during comparison, and it can't accept none::type_t.

        static_assert(generic::implementing::interface::template_tr<generic::array_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::array::any_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::boolean_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::boolean::any_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::boolean::impure_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::boolean::pure_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::implementing::constructor::default_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::implementing::interface::none::value_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::implementing::interface::template_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::implementing::interface::type_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::negatable_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::negatable::any_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::negatable::integer_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::negatable::real_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::non_type_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::none_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::none::any_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::pointer_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::pointer::any_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::positive_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::positive::any_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::positive::integer_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic::type_ttg>);

        static_assert(generic::implementing::interface::template_tr<generic_template::implementing::template_parameter_list::default_ttg>);
        static_assert(generic::implementing::interface::template_tr<generic_template::implementing::type_parameter_list::default_ttg>);

        static_assert(generic::implementing::interface::template_tr<interface::none::value_ttg>);
        static_assert(generic::implementing::interface::template_tr<interface::type_ttg>);

        static_assert(generic::implementing::interface::template_tr<none::value_ttg>);

        static_assert(generic::implementing::interface::template_tr<pointer::cpp_ttg>);
    }

}

namespace nkr {

    TEST_SUITE("the following templates should implement this interface")
    {
        //static_assert(generic::implementing::interface::template_tr<array::cpp_t>); // failing because we're passing none::type_t during comparison, and it can't accept none::type_t.

        static_assert(generic::implementing::interface::template_tr<interface::none::value_i>);
        static_assert(generic::implementing::interface::template_tr<interface::type_i>);

        static_assert(generic::implementing::interface::template_tr<none::value_t>);

        static_assert(generic::implementing::interface::template_tr<pointer::cpp_t>);
    }

}
