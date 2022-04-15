/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/enumeration/errors_t.h"
#include "nkr/interface/forward.h"
#include "nkr/macro/qualified_templates.h"
#include "nkr/macro/qualified_types.h"
#include "nkr/negatable/integer_t.h"
#include "nkr/pointer/cpp_t.h"
#include "nkr/positive/integer_t.h"

#include "doctest.h"

namespace nkr {

    class user_defined_t
    {
    public:
        using integer_t = nkr::positive::integer_t;

    public:
        integer_t   error_integer;

    private:
        nkr::boolean::cpp_t is_live;

    public:
        constexpr user_defined_t(integer_t error_integer) noexcept :
            error_integer(error_integer),
            is_live(true)
        {
        }

        constexpr user_defined_t(const user_defined_t& other) noexcept :
            error_integer(other.error_integer),
            is_live(true)
        {
        }

        user_defined_t(const volatile user_defined_t& other) noexcept :
            error_integer(other.error_integer),
            is_live(true)
        {
        }

        constexpr user_defined_t(user_defined_t&& other) noexcept :
            error_integer(nkr::cpp::Move(other.error_integer)),
            is_live(true)
        {
            other.is_live = false;
        }

        user_defined_t(volatile user_defined_t&& other) noexcept :
            error_integer(nkr::cpp::Move(other.error_integer)),
            is_live(true)
        {
            other.is_live = false;
        }

        constexpr user_defined_t&
            operator =(const user_defined_t& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = other.error_integer;
                this->is_live = true;
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(const user_defined_t& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = other.error_integer;
                this->is_live = true;
            }

            return *this;
        }

        user_defined_t&
            operator =(const volatile user_defined_t& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = other.error_integer;
                this->is_live = true;
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(const volatile user_defined_t& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = other.error_integer;
                this->is_live = true;
            }

            return *this;
        }

        constexpr user_defined_t&
            operator =(user_defined_t&& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = nkr::cpp::Move(other.error_integer);
                this->is_live = true;
                other.is_live = false;
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(user_defined_t&& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = nkr::cpp::Move(other.error_integer);
                this->is_live = true;
                other.is_live = false;
            }

            return *this;
        }

        user_defined_t&
            operator =(tr<just_volatile_tg, t<user_defined_t>> auto&& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = nkr::cpp::Move(other.error_integer);
                this->is_live = true;
                other.is_live = false;
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(tr<just_volatile_tg, t<user_defined_t>> auto&& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->error_integer = nkr::cpp::Move(other.error_integer);
                this->is_live = true;
                other.is_live = false;
            }

            return *this;
        }

        constexpr ~user_defined_t() noexcept
        {
            this->is_live = false;
        }

    public:
        constexpr nkr::boolean::cpp_t
            Is_Live()
            const volatile noexcept
        {
            return this->is_live;
        }

    public:
        constexpr operator integer_t() const noexcept
        {
            return this->error_integer;
        }

        operator integer_t() const volatile noexcept
        {
            return this->error_integer;
        }
    };

    template <nkr::cpp::is_any_tr<user_defined_t> type_p>
    class user_defined_t_interface_enumeration_types_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using integer_t = typename type_t::integer_t;

    public:
        static constexpr integer_t
            Default_Integer()
            noexcept
        {
            return integer_t(0);
        }

        static constexpr integer_t
            Integer(const tr<any_tg, t<value_t>> auto& value)
            noexcept
        {
            return value.error_integer;
        }

        static constexpr nkr::none::type_t
            Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer)
            noexcept
        {
            value.error_integer = integer;
        }

    public:
        template <typename ...>
        constexpr user_defined_t_interface_enumeration_types_sp(...) noexcept   = delete;
    };

    namespace interface { namespace enumeration {

        template <nkr::cpp::is_any_tr<user_defined_t> type_p>
        class types_i_sp<type_p>
        {
        public:
            using type_t    = user_defined_t_interface_enumeration_types_sp<type_p>;
        };

    }}

    class convertible_to_user_defined_t
    {
    public:
        user_defined_t  non_built_in;

    public:
        constexpr convertible_to_user_defined_t(user_defined_t non_built_in) noexcept :
            non_built_in(non_built_in)
        {
        }

    public:
        constexpr operator user_defined_t() const noexcept
        {
            return non_built_in;
        }

        operator user_defined_t() const volatile noexcept
        {
            return non_built_in;
        }
    };

    TEST_SUITE("nkr::enumeration::errors_t")
    {
    #define nkr_TEMPLATES(TEMPLATE_QUALIFIER_p, TYPE_p)         \
        TEMPLATE_QUALIFIER_p nkr::enumeration::errors_t<TYPE_p> \

    #define nkr_TEMPLATE_TYPES(TEMPLATE_QUALIFIER_p, TEMPLATE_p, TYPE_QUALIFIER_p)      \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::positive::integer_32_t>,  \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::positive::integer_64_t>,  \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::negatable::integer_32_t>, \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p nkr::negatable::integer_64_t>, \
        TEMPLATE_QUALIFIER_p TEMPLATE_p<TYPE_QUALIFIER_p user_defined_t>                \

    #define nkr_TYPES(TYPE_QUALIFIER_p)                                                     \
        nkr_TEMPLATE_TYPES(TYPE_QUALIFIER_p, nkr::enumeration::errors_t, nkr_BLANK),        \
        nkr_TEMPLATE_TYPES(TYPE_QUALIFIER_p, nkr::enumeration::errors_t, const),            \
        nkr_TEMPLATE_TYPES(TYPE_QUALIFIER_p, nkr::enumeration::errors_t, volatile),         \
        nkr_TEMPLATE_TYPES(TYPE_QUALIFIER_p, nkr::enumeration::errors_t, const volatile)    \

        nkr_DEFINE_QUALIFIED_TEMPLATE_TS;
        nkr_DEFINE_QUALIFIED_TYPE_TS;

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_constructor()")
            {
                TEST_CASE_TEMPLATE("should equal the default integer", errors_p, nkr_ANY)
                {
                    using none_t = typename errors_p::none_t;

                    errors_p error;

                    CHECK((error == none_t::Value()));
                }

                TEST_CASE_TEMPLATE("should cast to false", errors_p, nkr_ANY)
                {
                    using none_t = typename errors_p::none_t;

                    errors_p error;

                    CHECK((error == false));
                }
            }

            TEST_SUITE("to_constructor()"
                       * doctest::description("should convert other without changing it"))
            {
                TEST_SUITE("lvalue")
                {

                }

                TEST_SUITE("rvalue")
                {

                }
            }

            TEST_SUITE("copy_constructor()"
                       * doctest::description("should copy other without changing it"))
            {

            }

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move other and disarm it"))
            {

            }

            TEST_SUITE("destructor()")
            {
                TEST_CASE_TEMPLATE("should call the destructors of its data members", errors_p, nkr_ANY_OF_ANY(user_defined_t))
                {
                    errors_p error;

                    CHECK(error.Value().Is_Live() == true);

                    error.~errors_p();
                    CHECK(error.Value().Is_Live() == false);
                }
            }
        }
    }

}
