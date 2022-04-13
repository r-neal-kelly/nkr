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
            class test_t
            {
            private:
                nkr::positive::integer_t integer = 10;

            public:
                operator long int() const volatile noexcept
                {
                    return static_cast<long int>(this->integer);
                }
            };

            volatile test_t value;
            nkr::enumeration::errors_t<int> errors = nkr::cpp::Move(value);

            CHECK((errors.types.Integer() == 10));

            errors.has_been_checked = true;
        }

        TEST_CASE("non-built-in")
        {
            /*nkr::enumeration::errors_t<non_built_in_t> errors_1;

            CHECK(errors_1.types.Integer() == 0);
            errors_1.has_been_checked = true;

            convert_to_non_built_in_t convert_to_non_built_in(10);

            //non_built_in_t non_built_in = 10;
            nkr::enumeration::errors_t<non_built_in_t> errors_2;
            errors_2 = errors_1;

            CHECK(errors_2.types.Integer() == 10);
            errors_2.has_been_checked = true;*/
        }
    }

}
