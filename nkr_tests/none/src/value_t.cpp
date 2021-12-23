/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/tr_dec.h"

namespace nkr { namespace positive {

    struct  integer_32_tg   {};

    template <typename type_p>
    concept integer_32_tr =
        cpp::is_any_tr<type_p, integer_32_t> ||
        (cpp::positive_integer_tr<type_p> && sizeof(type_p) * 8 == 32);

}}

// the base case Is_Any() definition must exist before the declaration of a specialization's Is_Any()???
// I know constexpr definitions must exist before they are executed, but it would appear to be even more restrictive!
#include "nkr/interface/type_i_def.h"

namespace nkr { namespace interface {

    template <>
    class type_i<positive::integer_32_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <positive::integer_32_tr type_p>
    class type_i<type_p> :
        public type_i<positive::integer_32_tg>
    {
    public:
    };

}}

#include "nkr/tr_def.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr boolean::cpp_t
        type_i<positive::integer_32_tg>::Is_Any()
        noexcept
    {
        return positive::integer_32_tr<other_p>;
    }

}}

//#include "nkr/positive/integer_t.h"

//#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr { namespace none {

    TEST_CASE("temp")
    {
        static_assert(tr1<unsigned int, any_tg, positive::integer_32_t>);

        //value_t<positive::integer_t> none = value_t<positive::integer_t>();

        //CHECK(static_cast<positive::integer_t>(none) == 0);
    }

}}
