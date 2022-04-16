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
#include "nkr/randomness.h"

#include "doctest.h"

namespace nkr { namespace enumeration { namespace errors_t$ { namespace test {

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

    class convertible_to_user_defined_t
    {
    public:
        user_defined_t  user_defined;

    public:
        constexpr convertible_to_user_defined_t(user_defined_t user_defined) noexcept :
            user_defined(user_defined)
        {
        }

    public:
        constexpr operator user_defined_t() const noexcept
        {
            return user_defined;
        }

        operator user_defined_t() const volatile noexcept
        {
            return user_defined;
        }
    };

}}}}

namespace nkr { namespace interface { namespace enumeration {

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_t$::test::user_defined_t> type_p>
    class types_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::test::user_defined_t_interface_enumeration_types_sp<type_p>;
    };

}}}

namespace nkr {

    TEST_SUITE("nkr::enumeration::errors_t")
    {
        using user_defined_t = nkr::enumeration::errors_t$::test::user_defined_t;

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

        namespace types_accumulator_t$ {

            template <nkr::tuple::types_tr types_p, template <typename ...> typename algorithm_p>
            class accumulate_tmpl;

            template <nkr::tuple::types_tr types_p, template <typename ...> typename algorithm_p>
                requires (types_p::Count() == 0)
            class accumulate_tmpl<types_p, algorithm_p>
            {
            public:
                using type_t = nkr::tuple::types_t<>;
            };

            template <nkr::tuple::types_tr types_p, template <typename ...> typename algorithm_p>
                requires (types_p::Count() > 0)
            class accumulate_tmpl<types_p, algorithm_p>
            {
            public:
                using type_t = typename accumulate_tmpl<
                    typename types_p::tail_t, algorithm_p
                >::type_t::template apply_front_t<
                    algorithm_p<typename types_p::head_t>
                >;
            };

            template <nkr::tuple::types_tr types_p, template <typename ...> typename algorithm_p>
            using accumulate_t =
                typename accumulate_tmpl<types_p, algorithm_p>::type_t;

            template <typename type_p>
            using just_const_for_t = nkr::tuple::types_t<
                nkr::cpp::just_const_t<type_p>
            >;

            template <typename type_p>
            using any_const_for_t = nkr::tuple::types_t<
                nkr::cpp::just_const_t<type_p>,
                nkr::cpp::just_const_volatile_t<type_p>
            >;

        }

        namespace template_types_accumulator_t$ {

            template <
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        primary_inner_types_p,
                nkr::tuple::types_tr                                                        per_primary_default_types_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_p
            > class accumulate_tmpl;

            template <
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        primary_inner_types_p,
                nkr::tuple::types_tr                                                        per_primary_default_types_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_p
            >
                requires (primary_inner_types_p::Count() == 0)
            class accumulate_tmpl<template_p, primary_inner_types_p, per_primary_default_types_p, algorithm_p>
            {
            public:
                using type_t = nkr::tuple::types_t<>;
            };

            template <
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        primary_inner_types_p,
                nkr::tuple::types_tr                                                        per_primary_default_types_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_p
            >
                requires (primary_inner_types_p::Count() > 0)
            class accumulate_tmpl<template_p, primary_inner_types_p, per_primary_default_types_p, algorithm_p>
            {
            public:
                using type_t = typename accumulate_tmpl<
                    template_p, typename primary_inner_types_p::tail_t, per_primary_default_types_p, algorithm_p
                >::type_t::template apply_front_t<
                    algorithm_p<template_p, typename primary_inner_types_p::head_t, per_primary_default_types_p>
                >;
            };

            template <
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        primary_inner_types_p,
                nkr::tuple::types_tr                                                        per_primary_default_types_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_p
            > using accumulate_t =
                typename accumulate_tmpl<template_p, primary_inner_types_p, per_primary_default_types_p, algorithm_p>::type_t;

            template <
                template <typename ...> typename    template_p,
                typename                            primary_inner_type_p,
                nkr::tuple::types_tr                more_types_p
            > using of_just_const_for_t = nkr::tuple::types_t<
                typename more_types_p::template push_front_t<nkr::cpp::just_const_t<primary_inner_type_p>>::template into_t<template_p>
            >;

        }

        template <
            nkr::tuple::types_tr    types_p
        > class types_accumulator_t
        {
        public:
            using types_t = types_p;

        public:
            using just_const_ts = types_accumulator_t$::accumulate_t<types_t, types_accumulator_t$::just_const_for_t>;
        };

        template <
            template <typename ...> typename    template_p,
            nkr::tuple::types_tr                primary_inner_types_p,
            nkr::tuple::types_tr                per_primary_default_types_p = nkr::tuple::types_t<>
        > class template_types_accumulator_t
        {
        public:
            using just_const_of_just_const_ts = types_accumulator_t$::accumulate_t<
                template_types_accumulator_t$::accumulate_t<
                    template_p,
                    primary_inner_types_p,
                    per_primary_default_types_p,
                    template_types_accumulator_t$::of_just_const_for_t
                >,
                types_accumulator_t$::just_const_for_t
            >;
        };

        using primary_inner_types_t = nkr::tuple::types_t<
            nkr::positive::integer_32_t,
            nkr::positive::integer_64_t,
            nkr::negatable::integer_32_t,
            nkr::negatable::integer_64_t/*,
            user_defined_t*/
        >;
        using template_types_t = template_types_accumulator_t<nkr::enumeration::errors_t, primary_inner_types_t>;

        using test_ts = template_types_t::just_const_of_just_const_ts;
        static_assert(nkr::cpp::is_tr<
                      typename test_ts::template at_t<nkr::constant::positive::index_t<0>>::head_t,
                      const nkr::enumeration::errors_t<const nkr::positive::integer_32_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      typename test_ts::template at_t<nkr::constant::positive::index_t<1>>::head_t,
                      const nkr::enumeration::errors_t<const nkr::positive::integer_64_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      typename test_ts::template at_t<nkr::constant::positive::index_t<2>>::head_t,
                      const nkr::enumeration::errors_t<const nkr::negatable::integer_32_t>
        >);
        static_assert(nkr::cpp::is_tr<
                      typename test_ts::template at_t<nkr::constant::positive::index_t<3>>::head_t,
                      const nkr::enumeration::errors_t<const nkr::negatable::integer_64_t>
        >);

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_constructor()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should equal the default integer", errors_p, _2c02690b_6d3c_4079_88f5_cff123b952c6)
                {
                    using none_t = typename errors_p::none_t;

                    errors_p errors;

                    CHECK((errors == none_t::Value()));
                }
                TEST_CASE_TEMPLATE_APPLY(_2c02690b_6d3c_4079_88f5_cff123b952c6, std::tuple<nkr::enumeration::errors_t<int>>);

                TEST_CASE_TEMPLATE("should cast to false", errors_p, nkr_ANY)
                {
                    using none_t = typename errors_p::none_t;

                    errors_p errors;

                    CHECK((errors == false));
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
                TEST_SUITE("lvalue")
                {
                    TEST_CASE_TEMPLATE("non_qualified", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        nkr::cpp::just_non_qualified_t<errors_p> other = nkr::randomness::Value<integer_t>();
                        errors_p errors = other;

                        CHECK((errors == other));
                    }

                    TEST_CASE_TEMPLATE("const", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        nkr::cpp::just_const_t<errors_p> other = nkr::randomness::Value<integer_t>();
                        errors_p errors = other;

                        CHECK((errors == other));
                    }

                    TEST_CASE_TEMPLATE("volatile", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        nkr::cpp::just_volatile_t<errors_p> other = nkr::randomness::Value<integer_t>();
                        errors_p errors = other;

                        CHECK((errors == other));
                    }

                    TEST_CASE_TEMPLATE("const_volatile", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        nkr::cpp::just_const_volatile_t<errors_p> other = nkr::randomness::Value<integer_t>();
                        errors_p errors = other;

                        CHECK((errors == other));
                    }
                }
            }

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move other and disarm it"))
            {
                TEST_SUITE("value")
                {
                    TEST_CASE_TEMPLATE("non_qualified", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        integer_t integer = nkr::randomness::Value<integer_t>();
                        errors_p errors = nkr::cpp::just_non_qualified_t<errors_p>(integer);

                        CHECK((errors == integer));
                    }
                }

                TEST_SUITE("rvalue")
                {
                    TEST_CASE_TEMPLATE("non_qualified", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        nkr::cpp::just_non_qualified_t<errors_p> other = nkr::randomness::Value<integer_t>();
                        nkr::cpp::just_non_qualified_t<errors_p> backup = other;
                        errors_p errors = nkr::cpp::Move(other);

                        CHECK((errors == backup));
                    }

                    TEST_CASE_TEMPLATE("volatile", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        nkr::cpp::just_volatile_t<errors_p> other = nkr::randomness::Value<integer_t>();
                        nkr::cpp::just_volatile_t<errors_p> backup = other;
                        errors_p errors = nkr::cpp::Move(other);

                        CHECK((errors == backup));
                    }
                }
            }

            TEST_SUITE("destructor()")
            {
                TEST_CASE_TEMPLATE("should call the destructors of its data members", errors_p, nkr_ANY_OF_ANY(user_defined_t))
                {
                    errors_p errors;

                    CHECK(errors.Value().Is_Live() == true);

                    errors.~errors_p();
                    CHECK(errors.Value().Is_Live() == false);
                }
            }
        }
    }

}
