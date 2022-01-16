/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/array/cpp_t.h"

#include "nkr/pointer/cpp_t.h"

#include "nkr/positive/integer_t.h"

#include "nkr/none/pointer_t.h"
#include "nkr/none/value_t.h"

#include "doctest.h"

// this is really a scrap book at the moment, but I'm prototyping and building some serious
// additions to the entire library. will clean up after it stabilizes enough, and a lot of these
// tests will go into their respective suites.

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

    namespace interface { namespace none {

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

    }}

    static_assert(generic::implementing::interface::template_ttr<none::value_ttg>);
    static_assert(tr1<non_none_default_t, any_tg, non_none_default_t>);
    static_assert(tr2<none::value_t<non_none_default_t>, any_tg, none::value_ttg, of_any_tg, non_none_default_t>);

    TEST_CASE("should work as a tag for types that don't use none as a default value")
    {
        non_none_default_t non_none_default = none::value_t<non_none_default_t>();

        CHECK(non_none_default.Value() == non_none_default_t::NONE);
    }

    static_assert(nkr::interface::template_i<nkr::generic::implementing::interface::template_ttg>::Is_Any<nkr::none::value_t>());

}
