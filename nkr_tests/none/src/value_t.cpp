/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/pointer/cpp_t.h"

#include "nkr/positive/integer_t.h"

#include "nkr/none/pointer_t.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

namespace nkr {

    TEST_CASE("temp")
    {
        none::value_t<positive::integer_t> none = none::value_t<positive::integer_t>();

        CHECK(static_cast<positive::integer_t>(none) == 0);

        positive::integer_t integer = none::value_t<positive::integer_t>();

        CHECK(integer == 0);
    }

    TEST_CASE("temp")
    {
        none::value_t<pointer::cpp_t<positive::integer_t>> none = none::value_t<pointer::cpp_t<positive::integer_t>>();

        CHECK(static_cast<pointer::cpp_t<positive::integer_t>>(none) == pointer::cpp_t<positive::integer_t>());
        CHECK(static_cast<pointer::cpp_t<positive::integer_t>>(none) == none::pointer_t());

        pointer::cpp_t<positive::integer_t> pointer = none::value_t<pointer::cpp_t<positive::integer_t>>();

        CHECK(pointer == pointer::cpp_t<positive::integer_t>());
        CHECK(pointer == none::pointer_t());
    }

    TEST_CASE("temp")
    {
        using integer_t = positive::integer_t;
        using none_t    = none::value_t<integer_t>;

        integer_t integer = none_t();

        CHECK(integer == 0);
        CHECK(integer == integer_t());
        CHECK(integer == none_t());
    }

    class non_none_default_t
    {
    public:
        static constexpr const positive::integer_t  NONE = 1;

    private:
        positive::integer_t value;

    public:
        /*constexpr non_none_default_t() :
            value(0)
        {
        }*/

        constexpr non_none_default_t(positive::integer_t value) :
            value(value)
        {
        }

        non_none_default_t(const non_none_default_t& other)                 = delete;
        non_none_default_t(non_none_default_t&& other) noexcept             = delete;

        non_none_default_t& operator =(const non_none_default_t& other)     = delete;
        non_none_default_t& operator =(non_none_default_t&& other) noexcept = delete;

    public:
        positive::integer_t Value() const
        {
            return this->value;
        }
    };

    static_assert(tr1<non_none_default_t, any_tg, non_none_default_t>);

    namespace interface
    {
        namespace none {

            template <>
            class value_i<non_none_default_t>
            {
            public:
                using type_t    = non_none_default_t;

            public:
                static constexpr non_none_default_t
                    Value()
                    noexcept
                {
                    return 1;
                }

            public:
                template <typename ...>
                constexpr value_i(...) noexcept = delete;
            };

        }
    }

    TEST_CASE("should work as a tag for types that don't use none as a default value")
    {
        non_none_default_t non_none_default = none::value_t<non_none_default_t>();

        CHECK(non_none_default.Value() == non_none_default_t::NONE);
    }

}
