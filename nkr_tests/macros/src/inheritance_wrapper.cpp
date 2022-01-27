/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/cpp.h"
#include "nkr/macros.h"
#include "nkr/negatable/real_t.h"
#include "nkr/positive/integer_t.h"

#include "doctest.h"

namespace nkr {

    TEST_SUITE("CONSTEXPR_INHERITANCE_WRAPPER")
    {
        TEST_SUITE("DEFINE_CTORS")
        {
            class original_t
            {
            public:
                using alias_t   = none::type_t;

            public:
                positive::integer_t integer;
                negatable::real_t   real;

            public:
                constexpr original_t() noexcept :
                    integer(1),
                    real(1.0)
                {
                }

                constexpr original_t(positive::integer_t integer) noexcept :
                    integer(integer),
                    real()
                {
                }

                constexpr original_t(negatable::real_t real) noexcept :
                    integer(),
                    real(real)
                {
                }

                constexpr original_t(const original_t& other) noexcept :
                    integer(other.integer),
                    real(other.real)
                {
                }

                constexpr original_t(const volatile original_t& other) noexcept :
                    integer(other.integer),
                    real(other.real)
                {
                }

                constexpr original_t(original_t&& other) noexcept :
                    integer(cpp::Exchange(other.integer, 0)),
                    real(cpp::Exchange(other.real, negatable::real_t(0.0)))
                {
                }

                constexpr original_t(volatile original_t&& other) noexcept :
                    integer(cpp::Exchange(other.integer, 0)),
                    real(cpp::Exchange(other.real, negatable::real_t(0.0)))
                {
                }

                constexpr original_t& operator =(const original_t& other) noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = other.integer;
                        this->real = other.real;
                    }

                    return *this;
                }

                constexpr volatile original_t& operator =(const original_t& other) volatile noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = other.integer;
                        this->real = other.real;
                    }

                    return *this;
                }

                constexpr original_t& operator =(const volatile original_t& other) noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = other.integer;
                        this->real = other.real;
                    }

                    return *this;
                }

                constexpr volatile original_t& operator =(const volatile original_t& other) volatile noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = other.integer;
                        this->real = other.real;
                    }

                    return *this;
                }

                constexpr original_t& operator =(original_t&& other) noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = cpp::Exchange(other.integer, 0);
                        this->real = cpp::Exchange(other.real, negatable::real_t(0.0));
                    }

                    return *this;
                }

                constexpr volatile original_t& operator =(original_t&& other) volatile noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = cpp::Exchange(other.integer, 0);
                        this->real = cpp::Exchange(other.real, negatable::real_t(0.0));
                    }

                    return *this;
                }

                constexpr original_t& operator =(volatile original_t&& other) noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = cpp::Exchange(other.integer, 0);
                        this->real = cpp::Exchange(other.real, negatable::real_t(0.0));
                    }

                    return *this;
                }

                constexpr volatile original_t& operator =(volatile original_t&& other) volatile noexcept
                {
                    if (this != cpp::Address(other)) {
                        this->integer = cpp::Exchange(other.integer, 0);
                        this->real = cpp::Exchange(other.real, negatable::real_t(0.0));
                    }

                    return *this;
                }

            public:
                constexpr positive::integer_t Integer() const noexcept
                {
                    return this->integer;
                }

                constexpr positive::integer_t Integer() const volatile noexcept
                {
                    return this->integer;
                }

                constexpr negatable::real_t Real() const noexcept
                {
                    return this->real;
                }

                constexpr negatable::real_t Real() const volatile noexcept
                {
                    return this->real;
                }

            public:
                constexpr operator positive::integer_t() const noexcept
                {
                    return this->integer;
                }

                constexpr operator positive::integer_t() const volatile noexcept
                {
                    return this->integer;
                }

                constexpr operator negatable::real_t() const noexcept
                {
                    return this->real;
                }

                constexpr operator negatable::real_t() const volatile noexcept
                {
                    return this->real;
                }

            public:
                constexpr positive::integer_t operator +(positive::integer_t integer) const noexcept
                {
                    return this->integer + integer;
                }

                constexpr positive::integer_t operator +(positive::integer_t integer) const volatile noexcept
                {
                    return this->integer + integer;
                }

                constexpr original_t& operator =(boolean::cpp_t boolean) noexcept
                {
                    if (boolean) {
                        this->integer = 1;
                        this->real = 1.0;
                    } else {
                        this->integer = 0;
                        this->real = negatable::real_t(0.0);
                    }

                    return *this;
                }

                constexpr volatile original_t& operator =(boolean::cpp_t boolean) volatile noexcept
                {
                    if (boolean) {
                        this->integer = 1;
                        this->real = 1.0;
                    } else {
                        this->integer = 0;
                        this->real = negatable::real_t(0.0);
                    }

                    return *this;
                }
            };

            class derived_1_t :
                public original_t
            {
            public:
                using base_t    = original_t;

            public:
                nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(derived_1_t, original_t);
            };

            class derived_2_t :
                public derived_1_t
            {
            public:
                using base_t    = derived_1_t;

            public:
                nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(derived_2_t, derived_1_t);
            };

            class derived_3_t :
                public derived_2_t
            {
            public:
                using base_t    = derived_2_t;

            public:
                nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(derived_3_t, derived_2_t);
            };

            template <typename base_p>
            class implicit_t :
                public base_p
            {
            public:
                using base_p::base_p;
            };

            TEST_SUITE("aliases")
            {
                TEST_CASE_TEMPLATE("should have base's aliases", derived_p, derived_1_t, derived_2_t, derived_3_t)
                {
                    using base_t = derived_p::base_t;

                    static_assert(cpp::is_tr<derived_p::alias_t, base_t::alias_t>);
                }
            }

            TEST_SUITE("objects")
            {
                TEST_SUITE("base")
                {
                    TEST_CASE_TEMPLATE("should use base's default ctor", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        constexpr derived_p derived;

                        static_assert(derived.integer == 1);
                        static_assert(derived.real == 1.0);
                    }

                    TEST_CASE_TEMPLATE("should use base's custom ctors", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        constexpr derived_p a = positive::integer_t(1);

                        static_assert(a.integer == 1);
                        static_assert(a.real == 0.0);

                        constexpr derived_p b = negatable::real_t(1.0);

                        static_assert(b.integer == 0);
                        static_assert(b.real == 1.0);
                    }

                    TEST_CASE_TEMPLATE("should copy base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        constexpr base_t base = positive::integer_t(1);
                        constexpr derived_p derived = base;

                        static_assert(base.integer == 1);
                        static_assert(base.real == 0.0);
                        static_assert(derived.integer == base.integer);
                        static_assert(derived.real == base.real);
                    }

                    TEST_CASE_TEMPLATE("should copy volatile base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile base_t base = positive::integer_t(1);
                        derived_p derived = base;

                        CHECK(base.integer == 1);
                        CHECK(base.real == 0.0);
                        CHECK(derived.integer == base.integer);
                        CHECK(derived.real == base.real);
                    }

                    TEST_CASE_TEMPLATE("should move base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        base_t base = positive::integer_t(1);
                        derived_p derived = cpp::Move(base);

                        CHECK(base.integer == 0);
                        CHECK(base.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should move volatile base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile base_t base = positive::integer_t(1);
                        derived_p derived = cpp::Move(base);

                        CHECK(base.integer == 0);
                        CHECK(base.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        base_t base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = base), derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = base;
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(base);
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        base_t base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = base), volatile derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = base;
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(base);
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy volatile base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile base_t base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = base), derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = base;
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(base);
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy volatile base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile base_t base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = base), volatile derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = base;
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(base);
                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-move base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        base_t base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(base)), derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(base);
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(base));
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        base_t base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(base)), volatile derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(base);
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(base));
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("should assign-move volatile base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile base_t base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(base)), derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(base);
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(base));
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move volatile base", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile base_t base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(base)), volatile derived_p&>);

                        CHECK(base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(base);
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(base));
                        CHECK(base.integer == 0);
                        CHECK(derived.integer == 0);
                    }
                }

                TEST_SUITE("derived")
                {
                    TEST_CASE_TEMPLATE("should copy derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        constexpr derived_p other = positive::integer_t(1);
                        constexpr derived_p derived = other;

                        static_assert(other.integer == 1);
                        static_assert(other.real == 0.0);
                        static_assert(derived.integer == other.integer);
                        static_assert(derived.real == other.real);
                    }

                    TEST_CASE_TEMPLATE("should copy volatile derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile derived_p other = positive::integer_t(1);
                        derived_p derived = other;

                        CHECK(other.integer == 1);
                        CHECK(other.real == 0.0);
                        CHECK(derived.integer == other.integer);
                        CHECK(derived.real == other.real);
                    }

                    TEST_CASE_TEMPLATE("should move derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        derived_p other = positive::integer_t(1);
                        derived_p derived = cpp::Move(other);

                        CHECK(other.integer == 0);
                        CHECK(other.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should move volatile derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile derived_p other = positive::integer_t(1);
                        derived_p derived = cpp::Move(other);

                        CHECK(other.integer == 0);
                        CHECK(other.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        derived_p other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = other), derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = other;
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(other);
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        derived_p other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = other), volatile derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = other;
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(other);
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy volatile derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile derived_p other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = other), derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = other;
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(other);
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy volatile derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile derived_p other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = other), volatile derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = other;
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(other);
                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-move derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        derived_p other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(other)), derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(other);
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(other));
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        derived_p other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(other)), volatile derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(other);
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(other));
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("should assign-move volatile derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile derived_p other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(other)), derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(other);
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(other));
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move volatile derived", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile derived_p other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(other)), volatile derived_p&>);

                        CHECK(other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(other);
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(other));
                        CHECK(other.integer == 0);
                        CHECK(derived.integer == 0);
                    }
                }

                TEST_SUITE("implicit base")
                {
                    TEST_CASE_TEMPLATE("should copy type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        constexpr implicit_t<base_t> implicit_base = positive::integer_t(1);
                        constexpr derived_p derived = implicit_base;

                        static_assert(implicit_base.integer == 1);
                        static_assert(implicit_base.real == 0.0);
                        static_assert(derived.integer == implicit_base.integer);
                        static_assert(derived.real == implicit_base.real);
                    }

                    TEST_CASE_TEMPLATE("should copy volatile type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = implicit_base;

                        CHECK(implicit_base.integer == 1);
                        CHECK(implicit_base.real == 0.0);
                        CHECK(derived.integer == implicit_base.integer);
                        CHECK(derived.real == implicit_base.real);
                    }

                    TEST_CASE_TEMPLATE("should move type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = cpp::Move(implicit_base);

                        CHECK(implicit_base.integer == 0);
                        CHECK(implicit_base.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should move volatile type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = cpp::Move(implicit_base);

                        CHECK(implicit_base.integer == 0);
                        CHECK(implicit_base.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_base), derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_base;
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_base);
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        implicit_t<base_t> implicit_base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_base), volatile derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_base;
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_base);
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy volatile type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_base), derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_base;
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_base);
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy volatile type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile implicit_t<base_t> implicit_base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_base), volatile derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_base;
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_base);
                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-move type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_base)), derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_base);
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_base));
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        implicit_t<base_t> implicit_base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_base)), volatile derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_base);
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_base));
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("should assign-move volatile type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile implicit_t<base_t> implicit_base = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_base)), derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_base);
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_base));
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move volatile type that implicitly casts to base_t", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        using base_t = derived_p::base_t;

                        volatile implicit_t<base_t> implicit_base = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_base)), volatile derived_p&>);

                        CHECK(implicit_base.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_base);
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_base));
                        CHECK(implicit_base.integer == 0);
                        CHECK(derived.integer == 0);
                    }
                }

                TEST_SUITE("implicit derived")
                {
                    TEST_CASE_TEMPLATE("should copy type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        constexpr implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        constexpr derived_p derived = implicit_other;

                        static_assert(implicit_other.integer == 1);
                        static_assert(implicit_other.real == 0.0);
                        static_assert(derived.integer == implicit_other.integer);
                        static_assert(derived.real == implicit_other.real);
                    }

                    TEST_CASE_TEMPLATE("should copy volatile type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = implicit_other;

                        CHECK(implicit_other.integer == 1);
                        CHECK(implicit_other.real == 0.0);
                        CHECK(derived.integer == implicit_other.integer);
                        CHECK(derived.real == implicit_other.real);
                    }

                    TEST_CASE_TEMPLATE("should move type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = cpp::Move(implicit_other);

                        CHECK(implicit_other.integer == 0);
                        CHECK(implicit_other.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should move volatile type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = cpp::Move(implicit_other);

                        CHECK(implicit_other.integer == 0);
                        CHECK(implicit_other.real == 0.0);
                        CHECK(derived.integer == 1);
                        CHECK(derived.real == 0.0);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_other), derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_other;
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_other);
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_other), volatile derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_other;
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_other);
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-copy volatile type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_other), derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_other;
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_other);
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-copy volatile type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = implicit_other), volatile derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = implicit_other;
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                        derived.operator =(implicit_other);
                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 1);
                    }

                    TEST_CASE_TEMPLATE("should assign-move type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_other)), derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_other);
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_other));
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_other)), volatile derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_other);
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_other));
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("should assign-move volatile type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_other)), derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_other);
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_other));
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 0);
                    }

                    TEST_CASE_TEMPLATE("volatile should assign-move volatile type that implicitly casts to derived_p", derived_p, derived_1_t, derived_2_t, derived_3_t)
                    {
                        volatile implicit_t<derived_p> implicit_other = positive::integer_t(1);
                        volatile derived_p derived = positive::integer_t(0);

                        static_assert(cpp::is_tr<decltype(derived = cpp::Move(implicit_other)), volatile derived_p&>);

                        CHECK(implicit_other.integer == 1);
                        CHECK(derived.integer == 0);
                        derived = cpp::Move(implicit_other);
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 1);
                        derived.operator =(cpp::Move(implicit_other));
                        CHECK(implicit_other.integer == 0);
                        CHECK(derived.integer == 0);
                    }
                }
            }

            TEST_SUITE("methods")
            {
                TEST_CASE_TEMPLATE("should use base's methods", derived_p, derived_1_t, derived_2_t, derived_3_t)
                {
                    constexpr derived_p derived;

                    static_assert(derived.Integer() == 1);
                    static_assert(derived.Real() == 1.0);
                }
            }

            TEST_SUITE("casts")
            {
                TEST_CASE_TEMPLATE("should use base's custom casts", derived_p, derived_1_t, derived_2_t, derived_3_t)
                {
                    constexpr derived_p derived;

                    static_assert(static_cast<positive::integer_t>(derived) == 1);
                    static_assert(static_cast<negatable::real_t>(derived) == 1.0);
                }
            }

            TEST_SUITE("operators")
            {
                TEST_CASE_TEMPLATE("should use base's custom operators", derived_p, derived_1_t, derived_2_t, derived_3_t)
                {
                    constexpr derived_p derived;

                    static_assert(derived.integer == 1);
                    static_assert(derived + positive::integer_t(1) == 2);
                }

                TEST_CASE_TEMPLATE("should use base's custom operator =()'s", derived_p, derived_1_t, derived_2_t, derived_3_t)
                {
                    derived_p derived;

                    CHECK(derived.integer == 1);
                    derived = false;
                    CHECK(derived.integer == 0);
                    derived = true;
                    CHECK(derived.integer == 1);
                }
            }
        }
    }

}
