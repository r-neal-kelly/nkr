/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/enumeration/errors_t.h"
#include "nkr/interface/forward.h"
#include "nkr/positive/integer_t.h"
#include "nkr/negatable/integer_t.h"

#include "doctest.h"

namespace nkr {

    class non_built_in_t
    {
    public:
        using integer_t = nkr::positive::integer_t;

    public:
        integer_t   integer;

    public:
        constexpr non_built_in_t(integer_t integer) noexcept :
            integer(integer)
        {
        }

        constexpr non_built_in_t(const non_built_in_t& other) noexcept :
            integer(other.integer)
        {
        }

        non_built_in_t(const volatile non_built_in_t& other) noexcept :
            integer(other.integer)
        {
        }

        constexpr non_built_in_t(non_built_in_t&& other) noexcept :
            integer(nkr::cpp::Move(other.integer))
        {
        }

        non_built_in_t(volatile non_built_in_t&& other) noexcept :
            integer(nkr::cpp::Move(other.integer))
        {
        }

        constexpr non_built_in_t&
            operator =(const non_built_in_t& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = other.integer;
            }

            return *this;
        }

        volatile non_built_in_t&
            operator =(const non_built_in_t& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = other.integer;
            }

            return *this;
        }

        non_built_in_t&
            operator =(const volatile non_built_in_t& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = other.integer;
            }

            return *this;
        }

        volatile non_built_in_t&
            operator =(const volatile non_built_in_t& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = other.integer;
            }

            return *this;
        }

        constexpr non_built_in_t&
            operator =(non_built_in_t&& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = nkr::cpp::Move(other.integer);
            }

            return *this;
        }

        volatile non_built_in_t&
            operator =(non_built_in_t&& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = nkr::cpp::Move(other.integer);
            }

            return *this;
        }

        non_built_in_t&
            operator =(tr<just_volatile_tg, t<non_built_in_t>> auto&& other)
            noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = nkr::cpp::Move(other.integer);
            }

            return *this;
        }

        volatile non_built_in_t&
            operator =(tr<just_volatile_tg, t<non_built_in_t>> auto&& other)
            volatile noexcept
        {
            if (nkr::cpp::Address(*this) != nkr::cpp::Address(other)) {
                this->integer = nkr::cpp::Move(other.integer);
            }

            return *this;
        }

    public:
        constexpr operator integer_t() const noexcept
        {
            return this->integer;
        }

        operator integer_t() const volatile noexcept
        {
            return this->integer;
        }
    };

    template <nkr::cpp::is_any_tr<non_built_in_t> type_p>
    class non_built_in_t_interface_enumeration_types_sp
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
            return integer_t();
        }

        static constexpr integer_t
            Integer(const tr<any_tg, t<value_t>> auto& value)
            noexcept
        {
            return value.integer;
        }

        static constexpr nkr::none::type_t
            Integer(tr<any_non_const_tg, t<value_t>> auto& value, integer_t integer)
            noexcept
        {
            value.integer = integer;
        }

    public:
        template <typename ...>
        constexpr non_built_in_t_interface_enumeration_types_sp(...) noexcept   = delete;
    };

    namespace interface { namespace enumeration {

        template <nkr::cpp::is_any_tr<non_built_in_t> type_p>
        class types_i_sp<type_p>
        {
        public:
            using type_t    = non_built_in_t_interface_enumeration_types_sp<type_p>;
        };

    }}

    class convert_to_non_built_in_t
    {
    public:
        non_built_in_t  non_built_in;

    public:
        constexpr convert_to_non_built_in_t(non_built_in_t non_built_in) noexcept :
            non_built_in(non_built_in)
        {
        }

    public:
        constexpr operator non_built_in_t() const noexcept
        {
            return non_built_in;
        }

        operator non_built_in_t() const volatile noexcept
        {
            return non_built_in;
        }
    };

    TEST_SUITE("nkr::enumeration::errors_t")
    {
        TEST_CASE("temp")
        {
            nkr::enumeration::errors_t<int> error_1;
            nkr::enumeration::errors_t<int> error_2(error_1);

            CHECK(error_1 == 0);
            CHECK(error_2 == error_1);
        }

        TEST_CASE("temp")
        {
            int integer = 1;
            nkr::enumeration::errors_t<int> error_1(integer);
            nkr::enumeration::errors_t<int> error_2(error_1);

            CHECK(error_1 == integer);
            CHECK(error_2 == error_1);
        }

        TEST_CASE("temp")
        {
            int integer = 1;
            nkr::enumeration::errors_t<int> error_1(nkr::cpp::Move(integer));
            nkr::enumeration::errors_t<int> error_2(error_1);

            CHECK(error_1 == integer);
            CHECK(error_2 == error_1);
        }

        TEST_CASE("temp")
        {
            nkr::enumeration::errors_t<int> error_1(1);
            nkr::enumeration::errors_t<int> error_2(error_1);

            CHECK(error_1 == 1);
            CHECK(error_2 == error_1);
        }

        /*TEST_CASE("temp")
        {
            nkr::enumeration::errors_t<non_built_in_t> error;

            CHECK(error == 0);
        }

        TEST_CASE("temp")
        {
            nkr::enumeration::errors_t<non_built_in_t> error_1;
            nkr::enumeration::errors_t<non_built_in_t> error_2(error_1);

            CHECK(error_2 == error_1);
        }*/
    }

}
