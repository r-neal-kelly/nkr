/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"

#include "nkr/boolean/cpp_t.h"
#include "nkr/boolean/safe_t.h"

#include "nkr/enumeration/types_t.h"

#include "nkr/generic/array_tr.h"
#include "nkr/generic/array/any_tr.h"
#include "nkr/generic/boolean_tr.h"
#include "nkr/generic/boolean/any_tr.h"
#include "nkr/generic/boolean/impure_tr.h"
#include "nkr/generic/boolean/pure_tr.h"
#include "nkr/generic/built_in_tr.h"
#include "nkr/generic/implementing/constructor/default_tr.h"
#include "nkr/generic/implementing/interface/enumeration/types_tr.h"
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
#include "nkr/generic/random/distributor_tr.h"
#include "nkr/generic/random/distributor/cpp_tr.h"
#include "nkr/generic/random/generator_tr.h"
#include "nkr/generic/random/generator/cpp_tr.h"
#include "nkr/generic/type_tr.h"
#include "nkr/generic/user_defined_tr.h"

#include "nkr/generic_template/implementing/parameter_list/default_tr.h"
#include "nkr/generic_template_template/implementing/parameter_list/default_tr.h"

#include "nkr/interface/enumeration/types_i.h"
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

#include "nkr/random/distributor/cpp/bernoulli_t.h"
#include "nkr/random/distributor/cpp/uniform/integer_t.h"
#include "nkr/random/distributor/cpp/uniform/real_t.h"
#include "nkr/random/generator/hardware/cpp_t.h"
#include "nkr/random/generator/software/cpp/mersenne_twister_t.h"
#include "nkr/random/generator/software/cpp/mersenne_twister_19937_32_t.h"
#include "nkr/random/generator/software/cpp/mersenne_twister_19937_64_t.h"

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
        static_assert(generic::implementing::interface::template_ttr<array::cpp_ttg>);

        static_assert(generic::implementing::interface::template_ttr<enumeration::types_ttg>);

        static_assert(generic::implementing::interface::template_ttr<generic::array_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::array::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::boolean_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::boolean::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::boolean::impure_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::boolean::pure_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::built_in_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::implementing::constructor::default_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::implementing::interface::enumeration::types_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::implementing::interface::none::value_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::implementing::interface::template_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::implementing::interface::type_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::negatable_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::negatable::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::negatable::integer_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::negatable::real_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::non_type_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::none_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::none::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::number_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::number::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::number::integer_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::number::real_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::pointer_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::pointer::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::positive_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::positive::any_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::positive::integer_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::positive::real_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::random::distributor_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::random::distributor::cpp_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::random::generator_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::random::generator::cpp_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::type_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic::user_defined_ttg>);

        static_assert(generic::implementing::interface::template_ttr<generic_template::implementing::parameter_list::default_ttg>);
        static_assert(generic::implementing::interface::template_ttr<generic_template_template::implementing::parameter_list::default_ttg>);

        static_assert(generic::implementing::interface::template_ttr<interface::enumeration::types_ttg>);
        static_assert(generic::implementing::interface::template_ttr<interface::none::value_ttg>);
        static_assert(generic::implementing::interface::template_ttr<interface::type_ttg>);

        static_assert(generic::implementing::interface::template_ttr<none::value_ttg>);

        static_assert(generic::implementing::interface::template_ttr<pointer::cpp_ttg>);

        static_assert(generic::implementing::interface::template_ttr<random::distributor::cpp::uniform::integer_ttg>);
        static_assert(generic::implementing::interface::template_ttr<random::distributor::cpp::uniform::real_ttg>);
        static_assert(generic::implementing::interface::template_ttr<random::generator::software::cpp::mersenne_twister_ttg>);
    }

}

namespace nkr {

    TEST_SUITE("the following templates should implement this interface")
    {
        static_assert(generic::implementing::interface::template_ttr<array::cpp_t>);

        static_assert(generic::implementing::interface::template_ttr<enumeration::types_t>);

        static_assert(generic::implementing::interface::template_ttr<interface::enumeration::types_i>);
        static_assert(generic::implementing::interface::template_ttr<interface::none::value_i>);
        static_assert(generic::implementing::interface::template_ttr<interface::type_i>);

        static_assert(generic::implementing::interface::template_ttr<none::value_t>);

        static_assert(generic::implementing::interface::template_ttr<pointer::cpp_t>);

        static_assert(generic::implementing::interface::template_ttr<random::distributor::cpp::uniform::integer_t>);
        static_assert(generic::implementing::interface::template_ttr<random::distributor::cpp::uniform::real_t>);
        static_assert(generic::implementing::interface::template_ttr<random::generator::software::cpp::mersenne_twister_t>);
    }

}
