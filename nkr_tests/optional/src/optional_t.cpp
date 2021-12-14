/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/optional_t.h"

#include "doctest.h"

namespace nkr {

    class user_defined_t;

    template <is_any_tr<user_defined_t> type_p>
    class type_traits_i<type_p>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t
            Is_Any()
        {
            return is_any_tr<other_p, user_defined_t>;
        }
    };

    class user_defined_t
    {
    public:
        word_t  value;

    public:
        user_defined_t() :
            value(0)
        {
        }

        user_defined_t(word_t value) :
            value(value)
        {
        }

        user_defined_t(const user_defined_t& other) :
            value(other.value)
        {
        }

        user_defined_t(const volatile user_defined_t& other) :
            value(other.value)
        {
        }

        user_defined_t(user_defined_t&& other) noexcept :
            value(nkr::Move(other.value))
        {
        }

        user_defined_t(volatile user_defined_t&& other) noexcept :
            value(nkr::Move(other.value))
        {
        }

        user_defined_t&
            operator =(const user_defined_t& other)
        {
            if (this != std::addressof(other)) {
                this->value = other.value;
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(const user_defined_t& other)
            volatile
        {
            if (this != std::addressof(other)) {
                this->value = other.value;
            }

            return *this;
        }

        user_defined_t&
            operator =(const volatile user_defined_t& other)
        {
            if (this != std::addressof(other)) {
                this->value = other.value;
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(const volatile user_defined_t& other)
            volatile
        {
            if (this != std::addressof(other)) {
                this->value = other.value;
            }

            return *this;
        }

        user_defined_t&
            operator =(user_defined_t&& other)
            noexcept
        {
            if (this != std::addressof(other)) {
                this->value = nkr::Move(other.value);
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(user_defined_t&& other)
            volatile noexcept
        {
            if (this != std::addressof(other)) {
                this->value = nkr::Move(other.value);
            }

            return *this;
        }

        user_defined_t&
            operator =(is_just_volatile_tr<user_defined_t> auto&& other)
            noexcept
        {
            if (this != std::addressof(other)) {
                this->value = nkr::Move(other.value);
            }

            return *this;
        }

        volatile user_defined_t&
            operator =(is_just_volatile_tr<user_defined_t> auto&& other)
            volatile noexcept
        {
            if (this != std::addressof(other)) {
                this->value = nkr::Move(other.value);
            }

            return *this;
        }

        ~user_defined_t()
        {
            this->value = 0;
        }

    public:
        bool_t
            operator ==(tr1<any_tg, user_defined_t> auto& other)
            const
        {
            return this->value == other.value;
        }

        bool_t
            operator ==(tr1<any_tg, user_defined_t> auto& other)
            const volatile
        {
            return this->value == other.value;
        }

        bool_t
            operator ==(tr1<any_tg, user_defined_t> auto&& other)
            const
        {
            return operator ==(other);
        }

        bool_t
            operator ==(tr1<any_tg, user_defined_t> auto&& other)
            const volatile
        {
            return operator ==(other);
        }

        bool_t
            operator !=(tr1<any_tg, user_defined_t> auto& other)
            const
        {
            return !operator ==(other);
        }

        bool_t
            operator !=(tr1<any_tg, user_defined_t> auto& other)
            const volatile
        {
            return !operator ==(other);
        }

        bool_t
            operator !=(tr1<any_tg, user_defined_t> auto&& other)
            const
        {
            return !operator ==(other);
        }

        bool_t
            operator !=(tr1<any_tg, user_defined_t> auto&& other)
            const volatile
        {
            return !operator ==(other);
        }

    public:
        user_defined_t(none_t) :
            user_defined_t()
        {
        }

        user_defined_t&
            operator =(none_t)
        {
            this->value = 0;
        }

        volatile user_defined_t&
            operator =(none_t)
            volatile
        {
            this->value = 0;
        }

        bool_t
            operator ==(none_t)
            const
        {
            return this->value == 0;
        }

        bool_t
            operator ==(none_t)
            const volatile
        {
            return this->value == 0;
        }

        bool_t
            operator !=(none_t)
            const
        {
            return !operator ==(none_t());
        }

        bool_t
            operator !=(none_t)
            const volatile
        {
            return !operator ==(none_t());
        }
    };

    template <is_any_tr<user_defined_t> user_defined_p>
    auto Random()
    {
        return std::remove_cvref_t<user_defined_p>(Random<word_t>());
    }

    static_assert(maybe_i<user_defined_t>);
    static_assert(maybe_i<const user_defined_t>);
    static_assert(maybe_i<volatile user_defined_t>);
    static_assert(maybe_i<const volatile user_defined_t>);

}

namespace nkr {

    TEST_SUITE("optional_t<value_p>")
    {
    #define nkr_VALUES(QUALIFIER_p) \
        QUALIFIER_p word_t,         \
        void_t* QUALIFIER_p,        \
        word_t* QUALIFIER_p,        \
        QUALIFIER_p user_defined_t

    #define nkr_JUST_NON_QUALIFIED_VALUES   \
        nkr_VALUES(nkr_BLANK)

    #define nkr_JUST_CONST_VALUES   \
        nkr_VALUES(const)

    #define nkr_JUST_VOLATILE_VALUES    \
        nkr_VALUES(volatile)

    #define nkr_JUST_CONST_VOLATILE_VALUES  \
        nkr_VALUES(const volatile)

    #define nkr_ANY_QUALIFIED_VALUES    \
        nkr_JUST_CONST_VALUES,          \
        nkr_JUST_VOLATILE_VALUES,       \
        nkr_JUST_CONST_VOLATILE_VALUES

    #define nkr_ANY_NON_QUALIFIED_VALUES    \
        nkr_JUST_NON_QUALIFIED_VALUES

    #define nkr_ANY_CONST_VALUES        \
        nkr_JUST_CONST_VALUES,          \
        nkr_JUST_CONST_VOLATILE_VALUES

    #define nkr_ANY_NON_CONST_VALUES    \
        nkr_JUST_NON_QUALIFIED_VALUES,  \
        nkr_JUST_VOLATILE_VALUES

    #define nkr_ANY_VOLATILE_VALUES     \
        nkr_JUST_VOLATILE_VALUES,       \
        nkr_JUST_CONST_VOLATILE_VALUES

    #define nkr_ANY_NON_VOLATILE_VALUES \
        nkr_JUST_NON_QUALIFIED_VALUES,  \
        nkr_JUST_CONST_VALUES

    #define nkr_ALL_VALUES              \
        nkr_JUST_NON_QUALIFIED_VALUES,  \
        nkr_JUST_CONST_VALUES,          \
        nkr_JUST_VOLATILE_VALUES,       \
        nkr_JUST_CONST_VOLATILE_VALUES

    #define nkr_OPTIONALS(OPTIONAL_QUALIFIER_p, VALUE_QUALIFIER_p)          \
        OPTIONAL_QUALIFIER_p optional_t<VALUE_QUALIFIER_p word_t>,          \
        OPTIONAL_QUALIFIER_p optional_t<void_t* VALUE_QUALIFIER_p>,         \
        OPTIONAL_QUALIFIER_p optional_t<word_t* VALUE_QUALIFIER_p>,         \
        OPTIONAL_QUALIFIER_p optional_t<VALUE_QUALIFIER_p user_defined_t>

    #define nkr_JUST_NON_QUALIFIED                  \
        nkr_OPTIONALS(nkr_BLANK, nkr_BLANK),        \
        nkr_OPTIONALS(nkr_BLANK, const),            \
        nkr_OPTIONALS(nkr_BLANK, volatile),         \
        nkr_OPTIONALS(nkr_BLANK, const volatile)

    #define nkr_JUST_CONST                      \
        nkr_OPTIONALS(const, nkr_BLANK),        \
        nkr_OPTIONALS(const, const),            \
        nkr_OPTIONALS(const, volatile),         \
        nkr_OPTIONALS(const, const volatile)

    #define nkr_JUST_VOLATILE                   \
        nkr_OPTIONALS(volatile, nkr_BLANK),     \
        nkr_OPTIONALS(volatile, const),         \
        nkr_OPTIONALS(volatile, volatile),      \
        nkr_OPTIONALS(volatile, const volatile)

    #define nkr_JUST_CONST_VOLATILE                     \
        nkr_OPTIONALS(const volatile, nkr_BLANK),       \
        nkr_OPTIONALS(const volatile, const),           \
        nkr_OPTIONALS(const volatile, volatile),        \
        nkr_OPTIONALS(const volatile, const volatile)

    #define nkr_ANY_QUALIFIED   \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE

    #define nkr_ANY_NON_QUALIFIED   \
        nkr_JUST_NON_QUALIFIED

    #define nkr_ANY_CONST       \
        nkr_JUST_CONST,         \
        nkr_JUST_CONST_VOLATILE

    #define nkr_ANY_NON_CONST   \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_VOLATILE

    #define nkr_ANY_VOLATILE    \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE

    #define nkr_ANY_NON_VOLATILE    \
        nkr_JUST_NON_QUALIFIED,     \
        nkr_JUST_CONST

    #define nkr_ALL             \
        nkr_JUST_NON_QUALIFIED, \
        nkr_JUST_CONST,         \
        nkr_JUST_VOLATILE,      \
        nkr_JUST_CONST_VOLATILE

        template <typename value_p>
        auto
            Random_Non_None()
        {
            using non_const_value_t = std::remove_const_t<value_p>;

            non_const_value_t random;
            do {
                random = Random<non_const_value_t>();
            } while (random == none_t());

            return random;
        }

        TEST_SUITE("traits interface")
        {
            TEST_SUITE("tr0")
            {
                TEST_CASE("should work with tr0")
                {
                    static_assert(tr0<optional_t<word_t*>, any_tg>);
                }
            }

            TEST_SUITE("tr1")
            {
                TEST_CASE("should work with tr1")
                {
                    static_assert(tr1<optional_t<word_t*>, any_tg, optional_tg>);
                }
            }

            TEST_SUITE("tr2")
            {
                TEST_CASE("should work with tr2")
                {
                    static_assert(tr2<optional_t<word_t*>, any_tg, optional_ttg, of_any_tg, word_t*>);
                }
            }

            TEST_SUITE("tr3")
            {
                TEST_CASE("should work with tr3")
                {
                    static_assert(tr3<optional_t<word_t*>, any_tg, optional_ttg, of_any_tg, c_pointer_ttg, of_any_tg, word_t>);
                }
            }
        }

        TEST_SUITE("aliases")
        {
            TEST_SUITE("value_t")
            {
                TEST_CASE_TEMPLATE("should have a value_t", optional_p, nkr_ALL)
                {
                    static_assert(is_tr<typename optional_p::value_t, typename optional_p::value_t>);
                }
            }
        }

        TEST_SUITE("protected object data")
        {
            TEST_SUITE("has_value")
            {
                TEST_CASE_TEMPLATE("should have a has_value that's a bool_t", optional_p, nkr_ALL)
                {
                    class derived_t :
                        public optional_p
                    {
                    public:
                        static_assert(is_tr<decltype(has_value), bool_t>);
                    };
                }
            }

            TEST_SUITE("value")
            {
                TEST_CASE_TEMPLATE("should have a value that's its value_t", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    class derived_t :
                        public optional_p
                    {
                    public:
                        static_assert(is_tr<decltype(value), value_t>);
                    };
                }
            }
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_ctor()")
            {
                TEST_CASE_TEMPLATE("should have no value", optional_p, nkr_ALL)
                {
                    optional_p optional;

                    CHECK(!optional.Has_Value());
                }
            }

            TEST_SUITE("copy_value_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy a given non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value);
                }

                TEST_CASE_TEMPLATE("should copy a given none value and have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t value = None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value);
                }
            }

            TEST_SUITE("move_value_ctor()")
            {
                TEST_CASE_TEMPLATE("should move a given non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    non_const_value_t value = Random_Non_None<non_const_value_t>();
                    non_const_value_t backup = value;
                    optional_p optional = nkr::Move(value);

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == backup);
                }

                TEST_CASE_TEMPLATE("should move a given none value and have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    non_const_value_t value = None<non_const_value_t>();
                    non_const_value_t backup = value;
                    optional_p optional = nkr::Move(value);

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == backup);
                }
            }

            TEST_SUITE("copy_maybe_value_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy a given non-none maybe value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    maybe_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should accept a given none maybe value, but not have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    maybe_t<value_t> value = None<value_t>();
                    optional_p optional = value;

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should copy a given const non-none maybe value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const maybe_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should accept a given const none maybe value, but not have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const maybe_t<value_t> value = None<value_t>();
                    optional_p optional = value;

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should copy a given volatile non-none maybe value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    volatile maybe_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should accept a given volatile none maybe value, but not have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    volatile maybe_t<value_t> value = None<value_t>();
                    optional_p optional = value;

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should copy a given const volatile non-none maybe value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const volatile maybe_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should accept a given const volatile none maybe value, but not have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const volatile maybe_t<value_t> value = None<value_t>();
                    optional_p optional = value;

                    CHECK(!optional.Has_Value());
                }
            }

            TEST_SUITE("move_maybe_value_ctor()")
            {
                TEST_CASE_TEMPLATE("should move a given non-none maybe value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    maybe_t<non_const_value_t> value = Random_Non_None<non_const_value_t>();
                    maybe_t<non_const_value_t> backup = value;
                    optional_p optional = nkr::Move(value);

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == backup());
                }

                TEST_CASE_TEMPLATE("should accept a given none maybe value, but not have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    maybe_t<non_const_value_t> value = None<non_const_value_t>();
                    optional_p optional = nkr::Move(value);

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should move a given volatile non-none maybe value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    volatile maybe_t<non_const_value_t> value = Random_Non_None<non_const_value_t>();
                    maybe_t<non_const_value_t> backup = value;
                    optional_p optional = nkr::Move(value);

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == backup());
                }

                TEST_CASE_TEMPLATE("should accept a given volatile none maybe value, but not have it", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    volatile maybe_t<non_const_value_t> value = None<non_const_value_t>();
                    optional_p optional = nkr::Move(value);

                    CHECK(!optional.Has_Value());
                }
            }

            TEST_SUITE("copy_some_value_ctor()")
            {
                TEST_CASE_TEMPLATE("should copy a given non-none some value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    some_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should copy a given const non-none some value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const some_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should copy a given volatile non-none some value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    volatile some_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }

                TEST_CASE_TEMPLATE("should copy a given const volatile non-none some value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const volatile some_t<value_t> value = Random_Non_None<value_t>();
                    optional_p optional = value;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == value());
                }
            }

            TEST_SUITE("move_some_value_ctor()")
            {
                TEST_CASE_TEMPLATE("should move a given non-none some value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    some_t<non_const_value_t> value = Random_Non_None<non_const_value_t>();
                    some_t<non_const_value_t> backup = value;
                    optional_p optional = nkr::Move(value);

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == backup());
                }

                TEST_CASE_TEMPLATE("should move a given volatile non-none some value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;
                    using non_const_value_t = std::remove_const_t<value_t>;

                    volatile some_t<non_const_value_t> value = Random_Non_None<non_const_value_t>();
                    some_t<non_const_value_t> backup = value;
                    optional_p optional = nkr::Move(value);

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == backup());
                }
            }

            TEST_SUITE("copy_ctor()")
            {
                TEST_CASE_TEMPLATE("should not change an other", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const value_t value = Random<value_t>();
                    optional_t<value_t> other = value;
                    optional_p optional = other;

                    CHECK(other.Has_Value());
                    CHECK(other.Value() == value);
                }

                TEST_CASE_TEMPLATE("should not change a const other", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const value_t value = Random<value_t>();
                    const optional_t<value_t> other = value;
                    optional_p optional = other;

                    CHECK(other.Has_Value());
                    CHECK(other.Value() == value);
                }

                TEST_CASE_TEMPLATE("should not change a volatile other", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const value_t value = Random<value_t>();
                    volatile optional_t<value_t> other = value;
                    optional_p optional = other;

                    CHECK(other.Has_Value());
                    CHECK(other.Value() == value);
                }

                TEST_CASE_TEMPLATE("should not change a const volatile other", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const value_t value = Random<value_t>();
                    const volatile optional_t<value_t> other = value;
                    optional_p optional = other;

                    CHECK(other.Has_Value());
                    CHECK(other.Value() == value);
                }

                TEST_CASE_TEMPLATE("should copy an other with a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    optional_t<value_t> other = Random_Non_None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy a const other with a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const optional_t<value_t> other = Random_Non_None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy a volatile other with a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    volatile optional_t<value_t> other = Random_Non_None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy a const volatile other with a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const volatile optional_t<value_t> other = Random_Non_None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy an other with a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    optional_t<value_t> other = None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy a const other with a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const optional_t<value_t> other = None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy a volatile other with a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    volatile optional_t<value_t> other = None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy a const volatile other with a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const volatile optional_t<value_t> other = None<value_t>();
                    optional_p optional = other;

                    CHECK(optional.Has_Value());
                    CHECK(optional.Value() == other.Value());
                }

                TEST_CASE_TEMPLATE("should copy an other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    optional_t<value_t> other;
                    optional_p optional = other;

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should copy a const other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const optional_t<value_t> other;
                    optional_p optional = other;

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should copy a volatile other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    volatile optional_t<value_t> other;
                    optional_p optional = other;

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should copy a const volatile other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    const volatile optional_t<value_t> other;
                    optional_p optional = other;

                    CHECK(!optional.Has_Value());
                }
            }

            TEST_SUITE("move_ctor()")
            {
                TEST_CASE_TEMPLATE("should leave an other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional = nkr::Move(other);

                        CHECK(!other.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should leave a volatile other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional = nkr::Move(other);

                        CHECK(!other.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should move an other with a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random_Non_None<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move a volatile other with a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random_Non_None<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move an other with a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = None<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move a volatile other with a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = None<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move an other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        optional_t<value_t> other;
                        optional_p optional = nkr::Move(other);

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should move a volatile other without a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        volatile optional_t<value_t> other;
                        optional_p optional = nkr::Move(other);

                        CHECK(!optional.Has_Value());
                    }
                }
            }

            TEST_SUITE("copy_assignment()")
            {
                TEST_CASE_TEMPLATE("should not change an other", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional;
                        optional = other;

                        CHECK(other.Has_Value());
                        CHECK(other.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should not change a const other", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        const optional_t<value_t> other = value;
                        optional_p optional;
                        optional = other;

                        CHECK(other.Has_Value());
                        CHECK(other.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should not change a volatile other", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional;
                        optional = other;

                        CHECK(other.Has_Value());
                        CHECK(other.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should not change a const volatile other", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        const volatile optional_t<value_t> other = value;
                        optional_p optional;
                        optional = other;

                        CHECK(other.Has_Value());
                        CHECK(other.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should copy an other with a non-none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        optional_t<value_t> other = Random_Non_None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a const other with a non-none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const optional_t<value_t> other = Random_Non_None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a volatile other with a non-none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        volatile optional_t<value_t> other = Random_Non_None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a const volatile other with a non-none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const volatile optional_t<value_t> other = Random_Non_None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy an other with a none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        optional_t<value_t> other = None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a const other with a none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const optional_t<value_t> other = None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a volatile other with a none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        volatile optional_t<value_t> other = None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a const volatile other with a none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const volatile optional_t<value_t> other = None<value_t>();
                        optional_p optional;
                        optional = other;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == other.Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy an other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        optional_t<value_t> other;
                        optional_p optional;
                        optional = other;

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a const other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const optional_t<value_t> other;
                        optional_p optional;
                        optional = other;

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a volatile other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        volatile optional_t<value_t> other;
                        optional_p optional;
                        optional = other;

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should copy a const volatile other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const volatile optional_t<value_t> other;
                        optional_p optional;
                        optional = other;

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should safely work with itself without changing", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        optional_p optional = value;
                        optional = optional;

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }
            }

            TEST_SUITE("move_assignment()")
            {
                TEST_CASE_TEMPLATE("should leave an other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(!other.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should leave a volatile other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(!other.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should move an other with a non-none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random_Non_None<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move a volatile other with a non-none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random_Non_None<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move an other with a none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = None<value_t>();
                        optional_t<value_t> other = value;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move a volatile other with a none value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = None<value_t>();
                        volatile optional_t<value_t> other = value;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }

                TEST_CASE_TEMPLATE("should move an other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        optional_t<value_t> other;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should move a volatile other without a value", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        volatile optional_t<value_t> other;
                        optional_p optional;
                        optional = nkr::Move(other);

                        CHECK(!optional.Has_Value());
                    }
                }

                TEST_CASE_TEMPLATE("should safely work with itself without changing", optional_p, nkr_ANY_NON_CONST)
                {
                    using value_t = optional_p::value_t;

                    if constexpr (any_non_const_tr<value_t>) {
                        const value_t value = Random<value_t>();
                        optional_p optional = value;
                        optional = nkr::Move(optional);

                        CHECK(optional.Has_Value());
                        CHECK(optional.Value() == value);
                    }
                }
            }

            TEST_SUITE("dtor()")
            {
                TEST_CASE_TEMPLATE("should no longer have a non-none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    optional_p optional = Random_Non_None<value_t>();
                    optional.~optional_t();

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should no longer have a none value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    optional_p optional = None<value_t>();
                    optional.~optional_t();

                    CHECK(!optional.Has_Value());
                }

                TEST_CASE_TEMPLATE("should still not have a value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    optional_p optional;
                    optional.~optional_t();

                    CHECK(!optional.Has_Value());
                }
            }
        }

        TEST_SUITE("none interface")
        {
            TEST_SUITE("ctor()")
            {
                TEST_CASE_TEMPLATE("should have no value", optional_p, nkr_ALL)
                {
                    optional_p optional = none_t();

                    CHECK(!optional.Has_Value());
                }
            }
        }

        // these tests need to be moved because they are no longer static operators
        TEST_SUITE("static operators")
        {
            TEST_SUITE("==(optional_t, optional_t)")
            {
                TEST_CASE_TEMPLATE("should return true with two of the same type that have an equal value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t value = Random<value_t>();
                    optional_p optional_a = value;
                    optional_p optional_b = value;

                    CHECK_TRUE(optional_a == optional_b);
                }

                TEST_CASE_TEMPLATE("should return false with two of the same type that do not have an equal value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t value_a = Random<value_t>();
                    std::remove_const_t<value_t> value_b;
                    do {
                        value_b = Random<value_t>();
                    } while (value_b == value_a);
                    optional_p optional_a = value_a;
                    optional_p optional_b = value_b;

                    CHECK_FALSE(optional_a == optional_b);
                }

                /*TEST_CASE_TEMPLATE("should return true with two different references of the same type that have an equal value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t random = Random<value_t>();
                    optional_p optional_a = random;
                    optional_p optional_b = random;

                    CHECK_TRUE(optional_a == optional_b);
                    CHECK_TRUE(optional_a == optional_t<value_t>(random));
                    CHECK_TRUE(optional_t<value_t>(random) == optional_b);
                    CHECK_TRUE(optional_t<value_t>(random) == optional_t<value_t>(random));
                }

                TEST_CASE_TEMPLATE("should return false with two different references of the same type that do not have an equal value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t random_a = Random<value_t>();
                    std::remove_const_t<value_t> random_b;
                    do {
                        random_b = Random<value_t>();
                    } while (random_b == random_a);
                    optional_p optional_a = random_a;
                    optional_p optional_b = random_b;

                    CHECK_FALSE(optional_a == optional_b);
                    CHECK_FALSE(optional_a == optional_t<value_t>(random_b));
                    CHECK_FALSE(optional_t<value_t>(random_a) == optional_b);
                    CHECK_FALSE(optional_t<value_t>(random_a) == optional_t<value_t>(random_b));
                }*/

                /*TEST_CASE_TEMPLATE("should return true for two maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();

                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<const value_p>(random));
                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<volatile value_p>(random));
                    CHECK_TRUE(maybe_t<value_p>(random) == maybe_t<const volatile value_p>(random));

                    CHECK_TRUE(maybe_t<const value_p>(random) == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<const value_p>(random) == maybe_t<volatile value_p>(random));
                    CHECK_TRUE(maybe_t<const value_p>(random) == maybe_t<const volatile value_p>(random));

                    CHECK_TRUE(maybe_t<volatile value_p>(random) == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<volatile value_p>(random) == maybe_t<const value_p>(random));
                    CHECK_TRUE(maybe_t<volatile value_p>(random) == maybe_t<const volatile value_p>(random));

                    CHECK_TRUE(maybe_t<const volatile value_p>(random) == maybe_t<value_p>(random));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random) == maybe_t<const value_p>(random));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random) == maybe_t<volatile value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    value_p random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);

                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<const value_p>(random_b));
                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<volatile value_p>(random_b));
                    CHECK_FALSE(maybe_t<value_p>(random_a) == maybe_t<const volatile value_p>(random_b));

                    CHECK_FALSE(maybe_t<const value_p>(random_a) == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<const value_p>(random_a) == maybe_t<volatile value_p>(random_b));
                    CHECK_FALSE(maybe_t<const value_p>(random_a) == maybe_t<const volatile value_p>(random_b));

                    CHECK_FALSE(maybe_t<volatile value_p>(random_a) == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<volatile value_p>(random_a) == maybe_t<const value_p>(random_b));
                    CHECK_FALSE(maybe_t<volatile value_p>(random_a) == maybe_t<const volatile value_p>(random_b));

                    CHECK_FALSE(maybe_t<const volatile value_p>(random_a) == maybe_t<value_p>(random_b));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random_a) == maybe_t<const value_p>(random_b));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random_a) == maybe_t<volatile value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    const maybe_t<value_p> const_maybe = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;

                    CHECK_TRUE(maybe == const_maybe);
                    CHECK_TRUE(maybe == volatile_maybe);
                    CHECK_TRUE(maybe == const_volatile_maybe);

                    CHECK_TRUE(const_maybe == maybe);
                    CHECK_TRUE(const_maybe == volatile_maybe);
                    CHECK_TRUE(const_maybe == const_volatile_maybe);

                    CHECK_TRUE(volatile_maybe == maybe);
                    CHECK_TRUE(volatile_maybe == const_maybe);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe);

                    CHECK_TRUE(const_volatile_maybe == maybe);
                    CHECK_TRUE(const_volatile_maybe == const_maybe);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> optional_a = random_a;
                    maybe_t<value_p> optional_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;

                    CHECK_FALSE(optional_a == const_maybe_b);
                    CHECK_FALSE(optional_a == volatile_maybe_b);
                    CHECK_FALSE(optional_a == const_volatile_maybe_b);

                    CHECK_FALSE(const_maybe_a == optional_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_b);

                    CHECK_FALSE(volatile_maybe_a == optional_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_b);

                    CHECK_FALSE(const_volatile_maybe_a == optional_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_b);
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    maybe_t<const value_p> maybe_c = random;
                    maybe_t<volatile value_p> maybe_v = random;
                    maybe_t<const volatile value_p> maybe_cv = random;
                    const maybe_t<value_p> const_maybe = random;
                    const maybe_t<const value_p> const_maybe_c = random;
                    const maybe_t<volatile value_p> const_maybe_v = random;
                    const maybe_t<const volatile value_p> const_maybe_cv = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    volatile maybe_t<const value_p> volatile_maybe_c = random;
                    volatile maybe_t<volatile value_p> volatile_maybe_v = random;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c = random;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v = random;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv = random;

                    CHECK_TRUE(maybe == maybe);
                    CHECK_TRUE(maybe == maybe_c);
                    CHECK_TRUE(maybe == maybe_v);
                    CHECK_TRUE(maybe == maybe_cv);
                    CHECK_TRUE(maybe == const_maybe);
                    CHECK_TRUE(maybe == const_maybe_c);
                    CHECK_TRUE(maybe == const_maybe_v);
                    CHECK_TRUE(maybe == const_maybe_cv);
                    CHECK_TRUE(maybe == volatile_maybe);
                    CHECK_TRUE(maybe == volatile_maybe_c);
                    CHECK_TRUE(maybe == volatile_maybe_v);
                    CHECK_TRUE(maybe == volatile_maybe_cv);
                    CHECK_TRUE(maybe == const_volatile_maybe);
                    CHECK_TRUE(maybe == const_volatile_maybe_c);
                    CHECK_TRUE(maybe == const_volatile_maybe_v);
                    CHECK_TRUE(maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(maybe_c == maybe);
                    CHECK_TRUE(maybe_c == maybe_c);
                    CHECK_TRUE(maybe_c == maybe_v);
                    CHECK_TRUE(maybe_c == maybe_cv);
                    CHECK_TRUE(maybe_c == const_maybe);
                    CHECK_TRUE(maybe_c == const_maybe_c);
                    CHECK_TRUE(maybe_c == const_maybe_v);
                    CHECK_TRUE(maybe_c == const_maybe_cv);
                    CHECK_TRUE(maybe_c == volatile_maybe);
                    CHECK_TRUE(maybe_c == volatile_maybe_c);
                    CHECK_TRUE(maybe_c == volatile_maybe_v);
                    CHECK_TRUE(maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(maybe_c == const_volatile_maybe);
                    CHECK_TRUE(maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(maybe_v == maybe);
                    CHECK_TRUE(maybe_v == maybe_c);
                    CHECK_TRUE(maybe_v == maybe_v);
                    CHECK_TRUE(maybe_v == maybe_cv);
                    CHECK_TRUE(maybe_v == const_maybe);
                    CHECK_TRUE(maybe_v == const_maybe_c);
                    CHECK_TRUE(maybe_v == const_maybe_v);
                    CHECK_TRUE(maybe_v == const_maybe_cv);
                    CHECK_TRUE(maybe_v == volatile_maybe);
                    CHECK_TRUE(maybe_v == volatile_maybe_c);
                    CHECK_TRUE(maybe_v == volatile_maybe_v);
                    CHECK_TRUE(maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(maybe_v == const_volatile_maybe);
                    CHECK_TRUE(maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(maybe_cv == maybe);
                    CHECK_TRUE(maybe_cv == maybe_c);
                    CHECK_TRUE(maybe_cv == maybe_v);
                    CHECK_TRUE(maybe_cv == maybe_cv);
                    CHECK_TRUE(maybe_cv == const_maybe);
                    CHECK_TRUE(maybe_cv == const_maybe_c);
                    CHECK_TRUE(maybe_cv == const_maybe_v);
                    CHECK_TRUE(maybe_cv == const_maybe_cv);
                    CHECK_TRUE(maybe_cv == volatile_maybe);
                    CHECK_TRUE(maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(maybe_cv == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe == maybe);
                    CHECK_TRUE(const_maybe == maybe_c);
                    CHECK_TRUE(const_maybe == maybe_v);
                    CHECK_TRUE(const_maybe == maybe_cv);
                    CHECK_TRUE(const_maybe == const_maybe);
                    CHECK_TRUE(const_maybe == const_maybe_c);
                    CHECK_TRUE(const_maybe == const_maybe_v);
                    CHECK_TRUE(const_maybe == const_maybe_cv);
                    CHECK_TRUE(const_maybe == volatile_maybe);
                    CHECK_TRUE(const_maybe == volatile_maybe_c);
                    CHECK_TRUE(const_maybe == volatile_maybe_v);
                    CHECK_TRUE(const_maybe == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe == const_volatile_maybe);
                    CHECK_TRUE(const_maybe == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe_c == maybe);
                    CHECK_TRUE(const_maybe_c == maybe_c);
                    CHECK_TRUE(const_maybe_c == maybe_v);
                    CHECK_TRUE(const_maybe_c == maybe_cv);
                    CHECK_TRUE(const_maybe_c == const_maybe);
                    CHECK_TRUE(const_maybe_c == const_maybe_c);
                    CHECK_TRUE(const_maybe_c == const_maybe_v);
                    CHECK_TRUE(const_maybe_c == const_maybe_cv);
                    CHECK_TRUE(const_maybe_c == volatile_maybe);
                    CHECK_TRUE(const_maybe_c == volatile_maybe_c);
                    CHECK_TRUE(const_maybe_c == volatile_maybe_v);
                    CHECK_TRUE(const_maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe_v == maybe);
                    CHECK_TRUE(const_maybe_v == maybe_c);
                    CHECK_TRUE(const_maybe_v == maybe_v);
                    CHECK_TRUE(const_maybe_v == maybe_cv);
                    CHECK_TRUE(const_maybe_v == const_maybe);
                    CHECK_TRUE(const_maybe_v == const_maybe_c);
                    CHECK_TRUE(const_maybe_v == const_maybe_v);
                    CHECK_TRUE(const_maybe_v == const_maybe_cv);
                    CHECK_TRUE(const_maybe_v == volatile_maybe);
                    CHECK_TRUE(const_maybe_v == volatile_maybe_c);
                    CHECK_TRUE(const_maybe_v == volatile_maybe_v);
                    CHECK_TRUE(const_maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(const_maybe_cv == maybe);
                    CHECK_TRUE(const_maybe_cv == maybe_c);
                    CHECK_TRUE(const_maybe_cv == maybe_v);
                    CHECK_TRUE(const_maybe_cv == maybe_cv);
                    CHECK_TRUE(const_maybe_cv == const_maybe);
                    CHECK_TRUE(const_maybe_cv == const_maybe_c);
                    CHECK_TRUE(const_maybe_cv == const_maybe_v);
                    CHECK_TRUE(const_maybe_cv == const_maybe_cv);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(const_maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(const_maybe_cv == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe == maybe);
                    CHECK_TRUE(volatile_maybe == maybe_c);
                    CHECK_TRUE(volatile_maybe == maybe_v);
                    CHECK_TRUE(volatile_maybe == maybe_cv);
                    CHECK_TRUE(volatile_maybe == const_maybe);
                    CHECK_TRUE(volatile_maybe == const_maybe_c);
                    CHECK_TRUE(volatile_maybe == const_maybe_v);
                    CHECK_TRUE(volatile_maybe == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe == volatile_maybe);
                    CHECK_TRUE(volatile_maybe == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe_c == maybe);
                    CHECK_TRUE(volatile_maybe_c == maybe_c);
                    CHECK_TRUE(volatile_maybe_c == maybe_v);
                    CHECK_TRUE(volatile_maybe_c == maybe_cv);
                    CHECK_TRUE(volatile_maybe_c == const_maybe);
                    CHECK_TRUE(volatile_maybe_c == const_maybe_c);
                    CHECK_TRUE(volatile_maybe_c == const_maybe_v);
                    CHECK_TRUE(volatile_maybe_c == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe_v == maybe);
                    CHECK_TRUE(volatile_maybe_v == maybe_c);
                    CHECK_TRUE(volatile_maybe_v == maybe_v);
                    CHECK_TRUE(volatile_maybe_v == maybe_cv);
                    CHECK_TRUE(volatile_maybe_v == const_maybe);
                    CHECK_TRUE(volatile_maybe_v == const_maybe_c);
                    CHECK_TRUE(volatile_maybe_v == const_maybe_v);
                    CHECK_TRUE(volatile_maybe_v == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(volatile_maybe_cv == maybe);
                    CHECK_TRUE(volatile_maybe_cv == maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == maybe_cv);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == const_maybe_cv);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(volatile_maybe_cv == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe == maybe);
                    CHECK_TRUE(const_volatile_maybe == maybe_c);
                    CHECK_TRUE(const_volatile_maybe == maybe_v);
                    CHECK_TRUE(const_volatile_maybe == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe == const_maybe);
                    CHECK_TRUE(const_volatile_maybe == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe_c == maybe);
                    CHECK_TRUE(const_volatile_maybe_c == maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_c == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe_v == maybe);
                    CHECK_TRUE(const_volatile_maybe_v == maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_v == const_volatile_maybe_cv);

                    CHECK_TRUE(const_volatile_maybe_cv == maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == const_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == volatile_maybe_cv);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe_c);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe_v);
                    CHECK_TRUE(const_volatile_maybe_cv == const_volatile_maybe_cv);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> optional_a = random_a;
                    maybe_t<value_p> optional_b = random_b;
                    maybe_t<const value_p> maybe_c_a = random_a;
                    maybe_t<const value_p> maybe_c_b = random_b;
                    maybe_t<volatile value_p> maybe_v_a = random_a;
                    maybe_t<volatile value_p> maybe_v_b = random_b;
                    maybe_t<const volatile value_p> maybe_cv_a = random_a;
                    maybe_t<const volatile value_p> maybe_cv_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    const maybe_t<const value_p> const_maybe_c_a = random_a;
                    const maybe_t<const value_p> const_maybe_c_b = random_b;
                    const maybe_t<volatile value_p> const_maybe_v_a = random_a;
                    const maybe_t<volatile value_p> const_maybe_v_b = random_b;
                    const maybe_t<const volatile value_p> const_maybe_cv_a = random_a;
                    const maybe_t<const volatile value_p> const_maybe_cv_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    volatile maybe_t<const value_p> volatile_maybe_c_a = random_a;
                    volatile maybe_t<const value_p> volatile_maybe_c_b = random_b;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_a = random_a;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_b = random_b;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_a = random_a;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_a = random_a;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_b = random_b;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_a = random_a;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_b = random_b;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_a = random_a;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_b = random_b;

                    CHECK_FALSE(optional_a == optional_b);
                    CHECK_FALSE(optional_a == maybe_c_b);
                    CHECK_FALSE(optional_a == maybe_v_b);
                    CHECK_FALSE(optional_a == maybe_cv_b);
                    CHECK_FALSE(optional_a == const_maybe_b);
                    CHECK_FALSE(optional_a == const_maybe_c_b);
                    CHECK_FALSE(optional_a == const_maybe_v_b);
                    CHECK_FALSE(optional_a == const_maybe_cv_b);
                    CHECK_FALSE(optional_a == volatile_maybe_b);
                    CHECK_FALSE(optional_a == volatile_maybe_c_b);
                    CHECK_FALSE(optional_a == volatile_maybe_v_b);
                    CHECK_FALSE(optional_a == volatile_maybe_cv_b);
                    CHECK_FALSE(optional_a == const_volatile_maybe_b);
                    CHECK_FALSE(optional_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(optional_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(optional_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(maybe_c_a == optional_b);
                    CHECK_FALSE(maybe_c_a == maybe_c_b);
                    CHECK_FALSE(maybe_c_a == maybe_v_b);
                    CHECK_FALSE(maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(maybe_v_a == optional_b);
                    CHECK_FALSE(maybe_v_a == maybe_c_b);
                    CHECK_FALSE(maybe_v_a == maybe_v_b);
                    CHECK_FALSE(maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(maybe_cv_a == optional_b);
                    CHECK_FALSE(maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(maybe_cv_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_a == optional_b);
                    CHECK_FALSE(const_maybe_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_c_a == optional_b);
                    CHECK_FALSE(const_maybe_c_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_v_a == optional_b);
                    CHECK_FALSE(const_maybe_v_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_maybe_cv_a == optional_b);
                    CHECK_FALSE(const_maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_maybe_cv_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_a == optional_b);
                    CHECK_FALSE(volatile_maybe_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_c_a == optional_b);
                    CHECK_FALSE(volatile_maybe_c_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_v_a == optional_b);
                    CHECK_FALSE(volatile_maybe_v_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(volatile_maybe_cv_a == optional_b);
                    CHECK_FALSE(volatile_maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(volatile_maybe_cv_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_a == optional_b);
                    CHECK_FALSE(const_volatile_maybe_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_c_a == optional_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_c_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_v_a == optional_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_v_a == const_volatile_maybe_cv_b);

                    CHECK_FALSE(const_volatile_maybe_cv_a == optional_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == volatile_maybe_cv_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_c_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_v_b);
                    CHECK_FALSE(const_volatile_maybe_cv_a == const_volatile_maybe_cv_b);
                }

                TEST_CASE("should return true for two maybes with different number types that have an equal value")
                {
                    u8_t random = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    maybe_t<u8_t> maybe = random;

                    CHECK_TRUE(maybe == maybe_t<u16_t>(u16_t(random)));
                    CHECK_TRUE(maybe == maybe_t<u32_t>(u32_t(random)));
                    CHECK_TRUE(maybe == maybe_t<u64_t>(u64_t(random)));

                    CHECK_TRUE(maybe == maybe_t<s8_t>(s8_t(random)));
                    CHECK_TRUE(maybe == maybe_t<s16_t>(s16_t(random)));
                    CHECK_TRUE(maybe == maybe_t<s32_t>(s32_t(random)));
                    CHECK_TRUE(maybe == maybe_t<s64_t>(s64_t(random)));

                    CHECK_TRUE(maybe == maybe_t<r32_t>(r32_t(random)));
                    CHECK_TRUE(maybe == maybe_t<r64_t>(r64_t(random)));
                }

                TEST_CASE("should return false for two maybes with different number types that do not have an equal value")
                {
                    u8_t random_a = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    u8_t random_b;
                    do {
                        random_b = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    } while (random_b == random_a);
                    maybe_t<u8_t> optional_a = random_a;

                    CHECK_FALSE(optional_a == maybe_t<u16_t>(u16_t(random_b)));
                    CHECK_FALSE(optional_a == maybe_t<u32_t>(u32_t(random_b)));
                    CHECK_FALSE(optional_a == maybe_t<u64_t>(u64_t(random_b)));

                    CHECK_FALSE(optional_a == maybe_t<s8_t>(s8_t(random_b)));
                    CHECK_FALSE(optional_a == maybe_t<s16_t>(s16_t(random_b)));
                    CHECK_FALSE(optional_a == maybe_t<s32_t>(s32_t(random_b)));
                    CHECK_FALSE(optional_a == maybe_t<s64_t>(s64_t(random_b)));

                    CHECK_FALSE(optional_a == maybe_t<r32_t>(r32_t(random_b)));
                    CHECK_FALSE(optional_a == maybe_t<r64_t>(r64_t(random_b)));
                }*/
            }

            /*TEST_SUITE("!=(optional_t, optional_t)")
            {
                TEST_CASE_TEMPLATE("should return true for two maybes with the same type that do not have an equal value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t random_a = Random<value_t>();
                    std::remove_const_t<value_t> random_b;
                    do {
                        random_b = Random<value_t>();
                    } while (random_b == random_a);
                    optional_p optional_a = random_a;
                    optional_p optional_b = random_b;

                    CHECK_TRUE(optional_a != optional_b);
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same type that have an equal value", optional_p, nkr_ALL)
                {
                    using value_t = optional_p::value_t;

                    value_t random = Random<value_t>();
                    optional_p optional_a = random;
                    optional_p optional_b = random;

                    CHECK_FALSE(optional_a != optional_b);
                }

                TEST_CASE_TEMPLATE("should return true for two maybes of different reference types with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> optional_a = random_a;
                    maybe_t<value_p> optional_b = random_b;

                    CHECK_TRUE(optional_a != optional_b);
                    CHECK_TRUE(optional_a != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<value_p>(random_a) != optional_b);
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes of different reference types with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> optional_a = random;
                    maybe_t<value_p> optional_b = random;

                    CHECK_FALSE(optional_a != optional_b);
                    CHECK_FALSE(optional_a != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<value_p>(random) != optional_b);
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return true for two maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    value_p random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);

                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<const value_p>(random_b));
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<volatile value_p>(random_b));
                    CHECK_TRUE(maybe_t<value_p>(random_a) != maybe_t<const volatile value_p>(random_b));

                    CHECK_TRUE(maybe_t<const value_p>(random_a) != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<const value_p>(random_a) != maybe_t<volatile value_p>(random_b));
                    CHECK_TRUE(maybe_t<const value_p>(random_a) != maybe_t<const volatile value_p>(random_b));

                    CHECK_TRUE(maybe_t<volatile value_p>(random_a) != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<volatile value_p>(random_a) != maybe_t<const value_p>(random_b));
                    CHECK_TRUE(maybe_t<volatile value_p>(random_a) != maybe_t<const volatile value_p>(random_b));

                    CHECK_TRUE(maybe_t<const volatile value_p>(random_a) != maybe_t<value_p>(random_b));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random_a) != maybe_t<const value_p>(random_b));
                    CHECK_TRUE(maybe_t<const volatile value_p>(random_a) != maybe_t<volatile value_p>(random_b));
                }

                TEST_CASE_TEMPLATE("should return false for two maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();

                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<const value_p>(random));
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<volatile value_p>(random));
                    CHECK_FALSE(maybe_t<value_p>(random) != maybe_t<const volatile value_p>(random));

                    CHECK_FALSE(maybe_t<const value_p>(random) != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<const value_p>(random) != maybe_t<volatile value_p>(random));
                    CHECK_FALSE(maybe_t<const value_p>(random) != maybe_t<const volatile value_p>(random));

                    CHECK_FALSE(maybe_t<volatile value_p>(random) != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<volatile value_p>(random) != maybe_t<const value_p>(random));
                    CHECK_FALSE(maybe_t<volatile value_p>(random) != maybe_t<const volatile value_p>(random));

                    CHECK_FALSE(maybe_t<const volatile value_p>(random) != maybe_t<value_p>(random));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random) != maybe_t<const value_p>(random));
                    CHECK_FALSE(maybe_t<const volatile value_p>(random) != maybe_t<volatile value_p>(random));
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same type that do not have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> optional_a = random_a;
                    maybe_t<value_p> optional_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;

                    CHECK_TRUE(optional_a != const_maybe_b);
                    CHECK_TRUE(optional_a != volatile_maybe_b);
                    CHECK_TRUE(optional_a != const_volatile_maybe_b);

                    CHECK_TRUE(const_maybe_a != optional_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_b);

                    CHECK_TRUE(volatile_maybe_a != optional_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_b);

                    CHECK_TRUE(const_volatile_maybe_a != optional_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_b);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same type that have an equal value", value_p, nkr_ALL_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    const maybe_t<value_p> const_maybe = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;

                    CHECK_FALSE(maybe != const_maybe);
                    CHECK_FALSE(maybe != volatile_maybe);
                    CHECK_FALSE(maybe != const_volatile_maybe);

                    CHECK_FALSE(const_maybe != maybe);
                    CHECK_FALSE(const_maybe != volatile_maybe);
                    CHECK_FALSE(const_maybe != const_volatile_maybe);

                    CHECK_FALSE(volatile_maybe != maybe);
                    CHECK_FALSE(volatile_maybe != const_maybe);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe);

                    CHECK_FALSE(const_volatile_maybe != maybe);
                    CHECK_FALSE(const_volatile_maybe != const_maybe);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe);
                }

                TEST_CASE_TEMPLATE("should return true for two differently qualified maybes with the same but differently qualified types that do not have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random_a = Random<value_p>();
                    std::remove_const_t<value_p> random_b;
                    do {
                        random_b = Random<value_p>();
                    } while (random_b == random_a);
                    maybe_t<value_p> optional_a = random_a;
                    maybe_t<value_p> optional_b = random_b;
                    maybe_t<const value_p> maybe_c_a = random_a;
                    maybe_t<const value_p> maybe_c_b = random_b;
                    maybe_t<volatile value_p> maybe_v_a = random_a;
                    maybe_t<volatile value_p> maybe_v_b = random_b;
                    maybe_t<const volatile value_p> maybe_cv_a = random_a;
                    maybe_t<const volatile value_p> maybe_cv_b = random_b;
                    const maybe_t<value_p> const_maybe_a = random_a;
                    const maybe_t<value_p> const_maybe_b = random_b;
                    const maybe_t<const value_p> const_maybe_c_a = random_a;
                    const maybe_t<const value_p> const_maybe_c_b = random_b;
                    const maybe_t<volatile value_p> const_maybe_v_a = random_a;
                    const maybe_t<volatile value_p> const_maybe_v_b = random_b;
                    const maybe_t<const volatile value_p> const_maybe_cv_a = random_a;
                    const maybe_t<const volatile value_p> const_maybe_cv_b = random_b;
                    volatile maybe_t<value_p> volatile_maybe_a = random_a;
                    volatile maybe_t<value_p> volatile_maybe_b = random_b;
                    volatile maybe_t<const value_p> volatile_maybe_c_a = random_a;
                    volatile maybe_t<const value_p> volatile_maybe_c_b = random_b;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_a = random_a;
                    volatile maybe_t<volatile value_p> volatile_maybe_v_b = random_b;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_a = random_a;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv_b = random_b;
                    const volatile maybe_t<value_p> const_volatile_maybe_a = random_a;
                    const volatile maybe_t<value_p> const_volatile_maybe_b = random_b;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_a = random_a;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c_b = random_b;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_a = random_a;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v_b = random_b;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_a = random_a;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv_b = random_b;

                    CHECK_TRUE(optional_a != optional_b);
                    CHECK_TRUE(optional_a != maybe_c_b);
                    CHECK_TRUE(optional_a != maybe_v_b);
                    CHECK_TRUE(optional_a != maybe_cv_b);
                    CHECK_TRUE(optional_a != const_maybe_b);
                    CHECK_TRUE(optional_a != const_maybe_c_b);
                    CHECK_TRUE(optional_a != const_maybe_v_b);
                    CHECK_TRUE(optional_a != const_maybe_cv_b);
                    CHECK_TRUE(optional_a != volatile_maybe_b);
                    CHECK_TRUE(optional_a != volatile_maybe_c_b);
                    CHECK_TRUE(optional_a != volatile_maybe_v_b);
                    CHECK_TRUE(optional_a != volatile_maybe_cv_b);
                    CHECK_TRUE(optional_a != const_volatile_maybe_b);
                    CHECK_TRUE(optional_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(optional_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(optional_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(maybe_c_a != optional_b);
                    CHECK_TRUE(maybe_c_a != maybe_c_b);
                    CHECK_TRUE(maybe_c_a != maybe_v_b);
                    CHECK_TRUE(maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(maybe_v_a != optional_b);
                    CHECK_TRUE(maybe_v_a != maybe_c_b);
                    CHECK_TRUE(maybe_v_a != maybe_v_b);
                    CHECK_TRUE(maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(maybe_cv_a != optional_b);
                    CHECK_TRUE(maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(maybe_cv_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_a != optional_b);
                    CHECK_TRUE(const_maybe_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_c_a != optional_b);
                    CHECK_TRUE(const_maybe_c_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_v_a != optional_b);
                    CHECK_TRUE(const_maybe_v_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_maybe_cv_a != optional_b);
                    CHECK_TRUE(const_maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_maybe_cv_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_a != optional_b);
                    CHECK_TRUE(volatile_maybe_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_c_a != optional_b);
                    CHECK_TRUE(volatile_maybe_c_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_v_a != optional_b);
                    CHECK_TRUE(volatile_maybe_v_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(volatile_maybe_cv_a != optional_b);
                    CHECK_TRUE(volatile_maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(volatile_maybe_cv_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_a != optional_b);
                    CHECK_TRUE(const_volatile_maybe_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_c_a != optional_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_c_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_v_a != optional_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_v_a != const_volatile_maybe_cv_b);

                    CHECK_TRUE(const_volatile_maybe_cv_a != optional_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != volatile_maybe_cv_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_c_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_v_b);
                    CHECK_TRUE(const_volatile_maybe_cv_a != const_volatile_maybe_cv_b);
                }

                TEST_CASE_TEMPLATE("should return false for two differently qualified maybes with the same but differently qualified types that have an equal value", value_p, nkr_JUST_NON_QUALIFIED_VALUES)
                {
                    value_p random = Random<value_p>();
                    maybe_t<value_p> maybe = random;
                    maybe_t<const value_p> maybe_c = random;
                    maybe_t<volatile value_p> maybe_v = random;
                    maybe_t<const volatile value_p> maybe_cv = random;
                    const maybe_t<value_p> const_maybe = random;
                    const maybe_t<const value_p> const_maybe_c = random;
                    const maybe_t<volatile value_p> const_maybe_v = random;
                    const maybe_t<const volatile value_p> const_maybe_cv = random;
                    volatile maybe_t<value_p> volatile_maybe = random;
                    volatile maybe_t<const value_p> volatile_maybe_c = random;
                    volatile maybe_t<volatile value_p> volatile_maybe_v = random;
                    volatile maybe_t<const volatile value_p> volatile_maybe_cv = random;
                    const volatile maybe_t<value_p> const_volatile_maybe = random;
                    const volatile maybe_t<const value_p> const_volatile_maybe_c = random;
                    const volatile maybe_t<volatile value_p> const_volatile_maybe_v = random;
                    const volatile maybe_t<const volatile value_p> const_volatile_maybe_cv = random;

                    CHECK_FALSE(maybe != maybe);
                    CHECK_FALSE(maybe != maybe_c);
                    CHECK_FALSE(maybe != maybe_v);
                    CHECK_FALSE(maybe != maybe_cv);
                    CHECK_FALSE(maybe != const_maybe);
                    CHECK_FALSE(maybe != const_maybe_c);
                    CHECK_FALSE(maybe != const_maybe_v);
                    CHECK_FALSE(maybe != const_maybe_cv);
                    CHECK_FALSE(maybe != volatile_maybe);
                    CHECK_FALSE(maybe != volatile_maybe_c);
                    CHECK_FALSE(maybe != volatile_maybe_v);
                    CHECK_FALSE(maybe != volatile_maybe_cv);
                    CHECK_FALSE(maybe != const_volatile_maybe);
                    CHECK_FALSE(maybe != const_volatile_maybe_c);
                    CHECK_FALSE(maybe != const_volatile_maybe_v);
                    CHECK_FALSE(maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(maybe_c != maybe);
                    CHECK_FALSE(maybe_c != maybe_c);
                    CHECK_FALSE(maybe_c != maybe_v);
                    CHECK_FALSE(maybe_c != maybe_cv);
                    CHECK_FALSE(maybe_c != const_maybe);
                    CHECK_FALSE(maybe_c != const_maybe_c);
                    CHECK_FALSE(maybe_c != const_maybe_v);
                    CHECK_FALSE(maybe_c != const_maybe_cv);
                    CHECK_FALSE(maybe_c != volatile_maybe);
                    CHECK_FALSE(maybe_c != volatile_maybe_c);
                    CHECK_FALSE(maybe_c != volatile_maybe_v);
                    CHECK_FALSE(maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(maybe_c != const_volatile_maybe);
                    CHECK_FALSE(maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(maybe_v != maybe);
                    CHECK_FALSE(maybe_v != maybe_c);
                    CHECK_FALSE(maybe_v != maybe_v);
                    CHECK_FALSE(maybe_v != maybe_cv);
                    CHECK_FALSE(maybe_v != const_maybe);
                    CHECK_FALSE(maybe_v != const_maybe_c);
                    CHECK_FALSE(maybe_v != const_maybe_v);
                    CHECK_FALSE(maybe_v != const_maybe_cv);
                    CHECK_FALSE(maybe_v != volatile_maybe);
                    CHECK_FALSE(maybe_v != volatile_maybe_c);
                    CHECK_FALSE(maybe_v != volatile_maybe_v);
                    CHECK_FALSE(maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(maybe_v != const_volatile_maybe);
                    CHECK_FALSE(maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(maybe_cv != maybe);
                    CHECK_FALSE(maybe_cv != maybe_c);
                    CHECK_FALSE(maybe_cv != maybe_v);
                    CHECK_FALSE(maybe_cv != maybe_cv);
                    CHECK_FALSE(maybe_cv != const_maybe);
                    CHECK_FALSE(maybe_cv != const_maybe_c);
                    CHECK_FALSE(maybe_cv != const_maybe_v);
                    CHECK_FALSE(maybe_cv != const_maybe_cv);
                    CHECK_FALSE(maybe_cv != volatile_maybe);
                    CHECK_FALSE(maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(maybe_cv != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe != maybe);
                    CHECK_FALSE(const_maybe != maybe_c);
                    CHECK_FALSE(const_maybe != maybe_v);
                    CHECK_FALSE(const_maybe != maybe_cv);
                    CHECK_FALSE(const_maybe != const_maybe);
                    CHECK_FALSE(const_maybe != const_maybe_c);
                    CHECK_FALSE(const_maybe != const_maybe_v);
                    CHECK_FALSE(const_maybe != const_maybe_cv);
                    CHECK_FALSE(const_maybe != volatile_maybe);
                    CHECK_FALSE(const_maybe != volatile_maybe_c);
                    CHECK_FALSE(const_maybe != volatile_maybe_v);
                    CHECK_FALSE(const_maybe != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe != const_volatile_maybe);
                    CHECK_FALSE(const_maybe != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe_c != maybe);
                    CHECK_FALSE(const_maybe_c != maybe_c);
                    CHECK_FALSE(const_maybe_c != maybe_v);
                    CHECK_FALSE(const_maybe_c != maybe_cv);
                    CHECK_FALSE(const_maybe_c != const_maybe);
                    CHECK_FALSE(const_maybe_c != const_maybe_c);
                    CHECK_FALSE(const_maybe_c != const_maybe_v);
                    CHECK_FALSE(const_maybe_c != const_maybe_cv);
                    CHECK_FALSE(const_maybe_c != volatile_maybe);
                    CHECK_FALSE(const_maybe_c != volatile_maybe_c);
                    CHECK_FALSE(const_maybe_c != volatile_maybe_v);
                    CHECK_FALSE(const_maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe_v != maybe);
                    CHECK_FALSE(const_maybe_v != maybe_c);
                    CHECK_FALSE(const_maybe_v != maybe_v);
                    CHECK_FALSE(const_maybe_v != maybe_cv);
                    CHECK_FALSE(const_maybe_v != const_maybe);
                    CHECK_FALSE(const_maybe_v != const_maybe_c);
                    CHECK_FALSE(const_maybe_v != const_maybe_v);
                    CHECK_FALSE(const_maybe_v != const_maybe_cv);
                    CHECK_FALSE(const_maybe_v != volatile_maybe);
                    CHECK_FALSE(const_maybe_v != volatile_maybe_c);
                    CHECK_FALSE(const_maybe_v != volatile_maybe_v);
                    CHECK_FALSE(const_maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(const_maybe_cv != maybe);
                    CHECK_FALSE(const_maybe_cv != maybe_c);
                    CHECK_FALSE(const_maybe_cv != maybe_v);
                    CHECK_FALSE(const_maybe_cv != maybe_cv);
                    CHECK_FALSE(const_maybe_cv != const_maybe);
                    CHECK_FALSE(const_maybe_cv != const_maybe_c);
                    CHECK_FALSE(const_maybe_cv != const_maybe_v);
                    CHECK_FALSE(const_maybe_cv != const_maybe_cv);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(const_maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(const_maybe_cv != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe != maybe);
                    CHECK_FALSE(volatile_maybe != maybe_c);
                    CHECK_FALSE(volatile_maybe != maybe_v);
                    CHECK_FALSE(volatile_maybe != maybe_cv);
                    CHECK_FALSE(volatile_maybe != const_maybe);
                    CHECK_FALSE(volatile_maybe != const_maybe_c);
                    CHECK_FALSE(volatile_maybe != const_maybe_v);
                    CHECK_FALSE(volatile_maybe != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe != volatile_maybe);
                    CHECK_FALSE(volatile_maybe != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe_c != maybe);
                    CHECK_FALSE(volatile_maybe_c != maybe_c);
                    CHECK_FALSE(volatile_maybe_c != maybe_v);
                    CHECK_FALSE(volatile_maybe_c != maybe_cv);
                    CHECK_FALSE(volatile_maybe_c != const_maybe);
                    CHECK_FALSE(volatile_maybe_c != const_maybe_c);
                    CHECK_FALSE(volatile_maybe_c != const_maybe_v);
                    CHECK_FALSE(volatile_maybe_c != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe_v != maybe);
                    CHECK_FALSE(volatile_maybe_v != maybe_c);
                    CHECK_FALSE(volatile_maybe_v != maybe_v);
                    CHECK_FALSE(volatile_maybe_v != maybe_cv);
                    CHECK_FALSE(volatile_maybe_v != const_maybe);
                    CHECK_FALSE(volatile_maybe_v != const_maybe_c);
                    CHECK_FALSE(volatile_maybe_v != const_maybe_v);
                    CHECK_FALSE(volatile_maybe_v != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(volatile_maybe_cv != maybe);
                    CHECK_FALSE(volatile_maybe_cv != maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != maybe_cv);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != const_maybe_cv);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(volatile_maybe_cv != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe != maybe);
                    CHECK_FALSE(const_volatile_maybe != maybe_c);
                    CHECK_FALSE(const_volatile_maybe != maybe_v);
                    CHECK_FALSE(const_volatile_maybe != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe != const_maybe);
                    CHECK_FALSE(const_volatile_maybe != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe_c != maybe);
                    CHECK_FALSE(const_volatile_maybe_c != maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_c != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe_v != maybe);
                    CHECK_FALSE(const_volatile_maybe_v != maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_v != const_volatile_maybe_cv);

                    CHECK_FALSE(const_volatile_maybe_cv != maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != const_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != volatile_maybe_cv);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe_c);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe_v);
                    CHECK_FALSE(const_volatile_maybe_cv != const_volatile_maybe_cv);
                }

                TEST_CASE("should return true for two maybes with different number types that do not have an equal value")
                {
                    u8_t random_a = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    u8_t random_b;
                    do {
                        random_b = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    } while (random_b == random_a);
                    maybe_t<u8_t> optional_a = random_a;

                    CHECK_TRUE(optional_a != maybe_t<u16_t>(u16_t(random_b)));
                    CHECK_TRUE(optional_a != maybe_t<u32_t>(u32_t(random_b)));
                    CHECK_TRUE(optional_a != maybe_t<u64_t>(u64_t(random_b)));

                    CHECK_TRUE(optional_a != maybe_t<s8_t>(s8_t(random_b)));
                    CHECK_TRUE(optional_a != maybe_t<s16_t>(s16_t(random_b)));
                    CHECK_TRUE(optional_a != maybe_t<s32_t>(s32_t(random_b)));
                    CHECK_TRUE(optional_a != maybe_t<s64_t>(s64_t(random_b)));

                    CHECK_TRUE(optional_a != maybe_t<r32_t>(r32_t(random_b)));
                    CHECK_TRUE(optional_a != maybe_t<r64_t>(r64_t(random_b)));
                }

                TEST_CASE("should return false for two maybes with different number types that have an equal value")
                {
                    u8_t random = Random<u8_t>(0, std::numeric_limits<s8_t>::max());
                    maybe_t<u8_t> maybe = random;

                    CHECK_FALSE(maybe != maybe_t<u16_t>(u16_t(random)));
                    CHECK_FALSE(maybe != maybe_t<u32_t>(u32_t(random)));
                    CHECK_FALSE(maybe != maybe_t<u64_t>(u64_t(random)));

                    CHECK_FALSE(maybe != maybe_t<s8_t>(s8_t(random)));
                    CHECK_FALSE(maybe != maybe_t<s16_t>(s16_t(random)));
                    CHECK_FALSE(maybe != maybe_t<s32_t>(s32_t(random)));
                    CHECK_FALSE(maybe != maybe_t<s64_t>(s64_t(random)));

                    CHECK_FALSE(maybe != maybe_t<r32_t>(r32_t(random)));
                    CHECK_FALSE(maybe != maybe_t<r64_t>(r64_t(random)));
                }
            }*/
        }
    }

}
