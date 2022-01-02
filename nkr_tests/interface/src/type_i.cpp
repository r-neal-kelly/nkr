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
#include "nkr/generic/built_in_tr.h"
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
#include "nkr/generic/number_tr.h"
#include "nkr/generic/number/any_tr.h"
#include "nkr/generic/number/integer_tr.h"
#include "nkr/generic/number/real_tr.h"
#include "nkr/generic/pointer_tr.h"
#include "nkr/generic/pointer/any_tr.h"
#include "nkr/generic/positive_tr.h"
#include "nkr/generic/positive/any_tr.h"
#include "nkr/generic/positive/integer_tr.h"
#include "nkr/generic/positive/real_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/generic/user_defined_tr.h"

#include "nkr/generic_template/implementing/parameter_list/default_tr.h"
#include "nkr/generic_template_template/implementing/parameter_list/default_tr.h"

#include "nkr/interface/none/value_i.h"
#include "nkr/interface/template_i.h"
#include "nkr/interface/type_i.h"

#include "nkr/negatable/byte_t.h"
#include "nkr/negatable/count_t.h"
#include "nkr/negatable/index_t.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/negatable/integer_8_t.h"
#include "nkr/negatable/integer_16_t.h"
#include "nkr/negatable/integer_32_t.h"
#include "nkr/negatable/integer_64_t.h"
#include "nkr/negatable/real_t.h"
#include "nkr/negatable/real_32_t.h"
#include "nkr/negatable/real_64_t.h"
#include "nkr/negatable/size_t.h"
#include "nkr/negatable/word_t.h"

#include "nkr/none/pointer_t.h"
#include "nkr/none/type_t.h"
#include "nkr/none/value_t.h"

#include "nkr/pointer/cpp_t.h"

#include "nkr/positive/byte_t.h"
#include "nkr/positive/count_t.h"
#include "nkr/positive/index_t.h"
#include "nkr/positive/integer_t.h"
#include "nkr/positive/integer_8_t.h"
#include "nkr/positive/integer_16_t.h"
#include "nkr/positive/integer_32_t.h"
#include "nkr/positive/integer_64_t.h"
#include "nkr/positive/size_t.h"
#include "nkr/positive/word_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("should implement the following interfaces")
    {
        static_assert(generic::implementing::interface::type_tr<interface::type_tg>);
        static_assert(generic::implementing::interface::type_tr<interface::type_i<positive::integer_t>>);

        static_assert(generic::implementing::interface::template_ttr<interface::type_ttg>);
        static_assert(generic::implementing::interface::template_ttr<interface::type_i>);
    }

}

namespace nkr {

    TEST_SUITE("the following tags should implement this interface")
    {
        static_assert(generic::implementing::interface::type_tr<array::cpp_tg>);

        static_assert(generic::implementing::interface::type_tr<boolean::cpp_tg>);
        static_assert(generic::implementing::interface::type_tr<boolean::safe_tg>);

        static_assert(generic::implementing::interface::type_tr<generic::array_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::array::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::boolean_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::boolean::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::boolean::impure_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::boolean::pure_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::built_in_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::implementing::constructor::default_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::implementing::interface::none::value_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::implementing::interface::type_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::negatable_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::negatable::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::negatable::integer_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::negatable::real_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::non_type_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::none_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::none::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::number_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::number::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::number::integer_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::number::real_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::pointer_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::pointer::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::positive_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::positive::any_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::positive::integer_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::positive::real_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::type_tg>);
        static_assert(generic::implementing::interface::type_tr<generic::user_defined_tg>);

        static_assert(generic::implementing::interface::type_tr<interface::none::value_tg>);
        static_assert(generic::implementing::interface::type_tr<interface::template_tg>);
        static_assert(generic::implementing::interface::type_tr<interface::type_tg>);

        static_assert(generic::implementing::interface::type_tr<negatable::byte_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::count_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::index_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_8_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_16_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_32_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_64_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::real_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::real_32_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::real_64_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::size_tg>);
        static_assert(generic::implementing::interface::type_tr<negatable::word_tg>);

        static_assert(generic::implementing::interface::type_tr<none::pointer_tg>);
        static_assert(generic::implementing::interface::type_tr<none::type_tg>);
        static_assert(generic::implementing::interface::type_tr<none::value_tg>);

        static_assert(generic::implementing::interface::type_tr<pointer::cpp_tg>);

        static_assert(generic::implementing::interface::type_tr<positive::byte_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::count_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::index_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_8_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_16_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_32_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_64_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::size_tg>);
        static_assert(generic::implementing::interface::type_tr<positive::word_tg>);
    }

}

namespace nkr {

    TEST_SUITE("the following types should implement this interface")
    {
        static_assert(generic::implementing::interface::type_tr<array::cpp_t<positive::integer_t, positive::count_c<1>>>);

        static_assert(generic::implementing::interface::type_tr<boolean::cpp_t>);
        static_assert(generic::implementing::interface::type_tr<boolean::safe_t>);

        static_assert(generic::implementing::interface::type_tr<interface::none::value_i<positive::integer_t>>);
        static_assert(generic::implementing::interface::type_tr<interface::template_i<array::cpp_t>>);
        static_assert(generic::implementing::interface::type_tr<interface::type_i<positive::integer_t>>);

        static_assert(generic::implementing::interface::type_tr<negatable::byte_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::count_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::index_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_8_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_16_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_32_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::integer_64_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::real_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::real_32_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::real_64_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::size_t>);
        static_assert(generic::implementing::interface::type_tr<negatable::word_t>);

        static_assert(generic::implementing::interface::type_tr<none::pointer_t>);
        static_assert(generic::implementing::interface::type_tr<none::type_t>);
        static_assert(generic::implementing::interface::type_tr<none::value_t<positive::integer_t>>);

        static_assert(generic::implementing::interface::type_tr<pointer::cpp_t<positive::integer_t>>);

        static_assert(generic::implementing::interface::type_tr<positive::byte_t>);
        static_assert(generic::implementing::interface::type_tr<positive::count_t>);
        static_assert(generic::implementing::interface::type_tr<positive::index_t>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_t>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_8_t>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_16_t>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_32_t>);
        static_assert(generic::implementing::interface::type_tr<positive::integer_64_t>);
        static_assert(generic::implementing::interface::type_tr<positive::size_t>);
        static_assert(generic::implementing::interface::type_tr<positive::word_t>);
    }

}
