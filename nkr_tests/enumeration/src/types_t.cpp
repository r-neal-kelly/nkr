/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/tr.h"

#include "nkr/array/cpp_t.h"
#include "nkr/constant/negatable/integer_t.h"
#include "nkr/constant/positive/count_t.h"
#include "nkr/constant/positive/integer_t.h"
#include "nkr/enumeration/types_t.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/none/value_t.h"
#include "nkr/positive/count_t.h"
#include "nkr/positive/integer_t.h"

#include "doctest.h"

namespace nkr {

    class user_defined_t
    {
    public:
        using value_t   = nkr::positive::integer_t;

    public:
        value_t                                                         value;
        nkr::array::cpp_t<value_t, nkr::constant::positive::count_t<8>> unused_but_exemplary_values = { 0 };

    public:
        constexpr user_defined_t(value_t value) noexcept :
            value(value)
        {
        }

        constexpr user_defined_t(const user_defined_t& other) noexcept :
            value(other.value)
        {
        }

        constexpr user_defined_t(const volatile user_defined_t& other) noexcept :
            value(other.value)
        {
        }

        constexpr user_defined_t(user_defined_t&& other) noexcept :
            value(nkr::cpp::Exchange(other.value, nkr::none::value_t<value_t>()))
        {
        }

        constexpr user_defined_t(volatile user_defined_t&& other) noexcept :
            value(nkr::cpp::Exchange(other.value, nkr::none::value_t<value_t>()))
        {
        }

        constexpr user_defined_t&
            operator =(const user_defined_t& other)
            noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = other.value;
            }

            return *this;
        }

        constexpr volatile user_defined_t&
            operator =(const user_defined_t& other)
            volatile noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = other.value;
            }

            return *this;
        }

        constexpr user_defined_t&
            operator =(const volatile user_defined_t& other)
            noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = other.value;
            }

            return *this;
        }

        constexpr volatile user_defined_t&
            operator =(const volatile user_defined_t& other)
            volatile noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = other.value;
            }

            return *this;
        }

        constexpr user_defined_t&
            operator =(user_defined_t&& other)
            noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = nkr::cpp::Exchange(other.value, nkr::none::value_t<value_t>());
            }

            return *this;
        }

        constexpr volatile user_defined_t&
            operator =(user_defined_t&& other)
            volatile noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = nkr::cpp::Exchange(other.value, nkr::none::value_t<value_t>());
            }

            return *this;
        }

        constexpr user_defined_t&
            operator =(tr<just_volatile_tg, t<user_defined_t>> auto&& other)
            noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = nkr::cpp::Exchange(other.value, nkr::none::value_t<value_t>());
            }

            return *this;
        }

        constexpr volatile user_defined_t&
            operator =(tr<just_volatile_tg, t<user_defined_t>> auto&& other)
            volatile noexcept
        {
            if (this != nkr::cpp::Address(other)) {
                this->value = nkr::cpp::Exchange(other.value, nkr::none::value_t<value_t>());
            }

            return *this;
        }

    public:
        constexpr operator value_t()
            const noexcept
        {
            return this->value;
        }

        constexpr operator value_t()
            const volatile noexcept
        {
            return this->value;
        }
    };

    template <nkr::cpp::is_any_tr<user_defined_t> type_p>
    class user_defined_enumeration_types_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using integer_t = value_t::value_t;

    public:
        static constexpr integer_t
            Default_Integer()
            noexcept
        {
            return 0;
        }

        static constexpr integer_t
            Integer(const tr<any_tg, t<value_t>> auto& value)
            noexcept
        {
            return value.value;
        }

        static constexpr nkr::none::type_t
            Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer)
            noexcept
        {
            value.value = integer;
        }

    public:
        template <typename ...>
        constexpr user_defined_enumeration_types_i_sp(...) noexcept = delete;
    };

    namespace interface { namespace enumeration {

        template <nkr::cpp::is_any_tr<user_defined_t> type_p>
        class types_i_sp<type_p>
        {
        public:
            using type_t    = user_defined_enumeration_types_i_sp<type_p>;
        };

    }}

    template <typename ...base_parameters_p>
    class example_e :
        public nkr::enumeration::types_t<base_parameters_p...>
    {
    public:
        using base_t    = nkr::enumeration::types_t<base_parameters_p...>;

    public:
        enum : typename base_t::integer_t
        {
            NONE_tg = base_t::none_t::Value(),

            A       = NONE_tg + 1, // avoid potential unsigned int overflow warning
            B,
            C,

            END_tg,
        };

    public:
        nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(example_e, base_t);
    };

    #define nkr_TYPES                                                                       \
        enumeration::types_t<positive::integer_t>,                                          \
        enumeration::types_t<positive::integer_t, nkr::constant::positive::integer_t<0>>,   \
        enumeration::types_t<negatable::integer_t>,                                         \
        enumeration::types_t<negatable::integer_t, nkr::constant::negatable::integer_t<0>>, \
        enumeration::types_t<user_defined_t>,                                               \
        enumeration::types_t<user_defined_t, nkr::constant::positive::integer_t<1>>         \

    #define nkr_EXAMPLES                                                            \
        example_e<positive::integer_t>,                                             \
        example_e<positive::integer_t, nkr::constant::positive::integer_t<0>>,      \
        example_e<negatable::integer_t>,                                            \
        example_e<negatable::integer_t, nkr::constant::negatable::integer_t<0>>,    \
        example_e<user_defined_t>,                                                  \
        example_e<user_defined_t, nkr::constant::positive::integer_t<1>>            \

    #define nkr_BOTH    \
        nkr_TYPES,      \
        nkr_EXAMPLES

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
                static_assert(generic::implementing::interface::type_tr<enumeration::types_t<positive::integer_t, nkr::constant::positive::integer_t<0>>>);

                static_assert(generic::implementing::interface::template_ttr<enumeration::types_ttg>);
                static_assert(generic::implementing::interface::template_ttr<enumeration::types_t>);

                static_assert(generic::implementing::interface::none::value_tr<enumeration::types_t<positive::integer_t>>);
                static_assert(generic::implementing::interface::none::value_tr<enumeration::types_t<positive::integer_t, nkr::constant::positive::integer_t<0>>>);
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
                using user_defined_types_e = nkr::enumeration::types_t<user_defined_t>;
                static_assert(nkr::cpp::is_tr<user_defined_types_e, user_defined_types_e>);
                static_assert(nkr::cpp::is_tr<user_defined_types_e::value_t, user_defined_t>);
                static_assert(user_defined_types_e::none_t::Value() == 0);
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("construct")
            {
                TEST_CASE_TEMPLATE("shouldn't have trouble resolving between the three main overloads", types_p, nkr_BOTH)
                {
                    using value_t = types_p::value_t;

                    types_p a(1);
                    types_p b(value_t(1));
                    types_p c(a);

                    CHECK(a == 1);
                    CHECK(b == 1);
                    CHECK(c == 1);
                }

                TEST_CASE_TEMPLATE("should accept an enum", types_p, nkr_EXAMPLES)
                {
                    // we really need to get the random_i working so that we can test any of the available enum values

                    types_p types(types_p::A);

                    CHECK(types == types_p::A);
                }
            }

            TEST_SUITE("assign")
            {
                TEST_CASE_TEMPLATE("shouldn't have trouble resolving between the three main overloads", types_p, nkr_BOTH)
                {
                    using value_t = types_p::value_t;

                    types_p a;
                    types_p b;
                    types_p c;

                    a = 1;
                    b = value_t(1);
                    c = a;

                    CHECK(a == 1);
                    CHECK(b == 1);
                    CHECK(c == 1);
                }
            }
        }

        TEST_SUITE("methods")
        {

        }

        TEST_SUITE("casts")
        {
            TEST_SUITE("integer_t()")
            {
                TEST_CASE_TEMPLATE("should return the selected integer", types_p, nkr_BOTH)
                {
                    types_p types;

                    CHECK(types + 1 == types_p::none_t::Value() + 1);
                }
            }

            TEST_SUITE("boolean::cpp_t()")
            {
                TEST_CASE_TEMPLATE("should return false by default", types_p, nkr_BOTH)
                {
                    types_p types;

                    CHECK(!types);
                }
            }
        }
    }
}
