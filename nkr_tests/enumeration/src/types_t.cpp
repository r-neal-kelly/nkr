/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/enumeration/types_t.h"

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "doctest.h"

namespace nkr {

    class user_defined_t
    {
    public:
        using value_t   = positive::integer_t;

    public:
        value_t value;

    public:
        user_defined_t(value_t value) :
            value(value)
        {
        }
    };

    namespace interface { namespace enumeration {

        template <>
        class types_i<user_defined_t>
        {
        public:
            using type_t    = user_defined_t;
            using integer_t = type_t::value_t;

        public:
            static constexpr integer_t
                Default_None_Value()
                noexcept
            {
                return 0;
            }

            static constexpr integer_t
                Value(const tr1<any_tg, type_t> auto& type)
                noexcept
            {
                return type.value;
            }

            static constexpr nkr::none::type_t
                Value(tr1<any_non_const_tg, type_t> auto& type, integer_t integer)
                noexcept
            {
                type.value = integer;
            }

        public:
            template <typename ...>
            constexpr types_i(...) noexcept = delete;
        };

    }}

    TEST_SUITE("enumeration::types_t")
    {
        TEST_SUITE("traits")
        {
            TEST_CASE("should satisfy the following traits")
            {

            }
        }

        TEST_SUITE("interfaces")
        {
            TEST_SUITE("should implement the following interfaces")
            {
                static_assert(generic::implementing::interface::type_tr<enumeration::types_tg>);
                static_assert(generic::implementing::interface::type_tr<enumeration::types_t<positive::integer_t>>);
                static_assert(generic::implementing::interface::type_tr<enumeration::types_t<positive::integer_t, positive::integer_c<0>>>);

                static_assert(generic::implementing::interface::template_ttr<enumeration::types_ttg>);
                static_assert(generic::implementing::interface::template_ttr<enumeration::types_t>);
            }

            TEST_CASE("should instantiate with built-in types that correctly interface")
            {
                using positive_types_e = enumeration::types_t<positive::integer_t>;
                static_assert(cpp::is_tr<positive_types_e, positive_types_e>);
                static_assert(cpp::is_tr<positive_types_e::value_t, positive::integer_t>);
                static_assert(positive_types_e::none_t::Value() == ~0);

                using negatable_types_e = enumeration::types_t<negatable::integer_t>;
                static_assert(cpp::is_tr<negatable_types_e, negatable_types_e>);
                static_assert(cpp::is_tr<negatable_types_e::value_t, negatable::integer_t>);
                static_assert(negatable_types_e::none_t::Value() == -1);
            }

            TEST_CASE("should instantiate with user-defined types that correctly interface")
            {
                using user_defined_types_e = enumeration::types_t<user_defined_t>;
                static_assert(cpp::is_tr<user_defined_types_e, user_defined_types_e>);
                static_assert(cpp::is_tr<user_defined_types_e::value_t, user_defined_t>);
                static_assert(user_defined_types_e::none_t::Value() == 0);
            }
        }
    }
}
