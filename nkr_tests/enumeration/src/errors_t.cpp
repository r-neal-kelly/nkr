/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/cpp/tuple/values_t.h"
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

        namespace types_accumulator_t$ {

            template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
            class accumulate_tmpl;

            template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
                requires (types_p::Count() == 0)
            class accumulate_tmpl<algorithm_p, types_p>
            {
            public:
                using type_t = nkr::tuple::types_t<>;
            };

            template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
                requires (types_p::Count() > 0)
            class accumulate_tmpl<algorithm_p, types_p>
            {
            public:
                using type_t = typename accumulate_tmpl<
                    algorithm_p, typename types_p::tail_t
                >::type_t::template apply_front_t<
                    algorithm_p<typename types_p::head_t>
                >;
            };

            template <template <typename ...> typename algorithm_p, nkr::tuple::types_tr types_p>
            using accumulate_t =
                typename accumulate_tmpl<algorithm_p, types_p>::type_t;

            template <typename type_p>
            using just_const_t = nkr::tuple::types_t<
                nkr::cpp::just_const_t<type_p>
            >;

            template <typename type_p>
            using any_t = nkr::tuple::types_t<
                nkr::cpp::just_non_qualified_t<type_p>,
                nkr::cpp::just_const_t<type_p>,
                nkr::cpp::just_volatile_t<type_p>,
                nkr::cpp::just_const_volatile_t<type_p>
            >;

            template <typename type_p>
            using any_const_t = nkr::tuple::types_t<
                nkr::cpp::just_const_t<type_p>,
                nkr::cpp::just_const_volatile_t<type_p>
            >;

            template <
                template <typename ...> typename algorithm_a_p,
                template <typename ...> typename algorithm_b_p,
                nkr::tuple::types_tr types_p
            > class accumulate_per_tmpl;

            template <
                template <typename ...> typename algorithm_a_p,
                template <typename ...> typename algorithm_b_p,
                nkr::tuple::types_tr types_p
            >
                requires (types_p::Count() > 0)
            class accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, types_p>
            {
            public:
                using type_t = typename accumulate_per_tmpl<
                    algorithm_a_p, algorithm_b_p, typename types_p::tail_t
                >::type_t::template apply_front_t<
                    algorithm_a_p<typename types_p::head_t>::template each_with_each_t<algorithm_b_p<typename types_p::head_t>>
                >;
            };

            template <
                template <typename ...> typename algorithm_a_p,
                template <typename ...> typename algorithm_b_p,
                nkr::tuple::types_tr types_p
            >
                requires (types_p::Count() == 0)
            class accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, types_p>
            {
            public:
                using type_t = nkr::tuple::types_t<>;
            };

            template <
                template <typename ...> typename algorithm_a_p,
                template <typename ...> typename algorithm_b_p,
                nkr::tuple::types_tr types_p
            > using accumulate_per_t =
                typename accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, types_p>::type_t;

        }

        template <
            nkr::tuple::types_tr    types_p
        > class types_accumulator_t
        {
        public:
            using types_t   = types_p;

        public:
            using just_const_ts = types_accumulator_t$::accumulate_t<types_accumulator_t$::just_const_t, types_t>;

            using any_ts        = types_accumulator_t$::accumulate_t<types_accumulator_t$::any_t, types_t>;
            using any_const_ts  = types_accumulator_t$::accumulate_t<types_accumulator_t$::any_const_t, types_t>;

        public:
            using any_per_any_ts = types_accumulator_t$::accumulate_per_t<
                types_accumulator_t$::any_t,
                types_accumulator_t$::any_t,
                types_t
            >;
        };

        namespace template_types_accumulator_t$ {

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <typename ...> typename                                            template_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            > class accumulate_tmpl;

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <typename ...> typename                                            template_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            >
                requires (argument_tuples_p::Count() == 0)
            class accumulate_tmpl<algorithm_a_p, template_p, algorithm_b_p, argument_tuples_p>
            {
            public:
                using type_t = nkr::tuple::types_t<>;
            };

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <typename ...> typename                                            template_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            >
                requires (argument_tuples_p::Count() > 0)
            class accumulate_tmpl<algorithm_a_p, template_p, algorithm_b_p, argument_tuples_p>
            {
            private:
                using accumulation_b_t = algorithm_b_p<
                    template_p,
                    typename argument_tuples_p::head_t::head_t,
                    typename argument_tuples_p::head_t::tail_t
                >;

            public:
                using type_t = typename accumulate_tmpl<
                    algorithm_a_p, template_p, algorithm_b_p, typename argument_tuples_p::tail_t
                >::type_t::template apply_front_t<
                    types_accumulator_t$::accumulate_t<algorithm_a_p, accumulation_b_t>
                >;
            };

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <typename ...> typename                                            template_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            > using accumulate_t =
                typename accumulate_tmpl<algorithm_a_p, template_p, algorithm_b_p, argument_tuples_p>::type_t;

            template <
                template <typename ...> typename    template_p,
                typename                            head_type_p,
                nkr::tuple::types_tr                tail_types_p
            > using of_just_const_t = nkr::tuple::types_t<
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>
            >;

            template <
                template <typename ...> typename    template_p,
                typename                            head_type_p,
                nkr::tuple::types_tr                tail_types_p
            > using of_any_t = nkr::tuple::types_t<
                typename tail_types_p::template push_front_t<nkr::cpp::just_non_qualified_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_volatile_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_volatile_t<head_type_p>>::template into_t<template_p>
            >;

            template <
                template <typename ...> typename    template_p,
                typename                            head_type_p,
                nkr::tuple::types_tr                tail_types_p
            > using of_any_const_t = nkr::tuple::types_t<
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_t<head_type_p>>::template into_t<template_p>,
                typename tail_types_p::template push_front_t<nkr::cpp::just_const_volatile_t<head_type_p>>::template into_t<template_p>
            >;

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                template <typename ...> typename                                            algorithm_c_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            > class accumulate_per_tmpl;

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                template <typename ...> typename                                            algorithm_c_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            >
                requires (argument_tuples_p::Count() > 0)
            class accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, argument_tuples_p>
            {
            private:
                using accumulation_b_t = algorithm_b_p<
                    template_p,
                    typename argument_tuples_p::head_t::head_t,
                    typename argument_tuples_p::head_t::tail_t
                >;

                using accumulation_a_t = types_accumulator_t$::accumulate_t<algorithm_a_p, accumulation_b_t>;

                using accumulation_d_t = algorithm_d_p<
                    template_p,
                    typename argument_tuples_p::head_t::head_t,
                    typename argument_tuples_p::head_t::tail_t
                >;

                using accumulation_c_t = types_accumulator_t$::accumulate_t<algorithm_c_p, accumulation_d_t>;

            public:
                using type_t = typename accumulate_per_tmpl<
                    algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, typename argument_tuples_p::tail_t
                >::type_t::template apply_front_t<
                    accumulation_a_t::template each_with_each_t<accumulation_c_t>
                >;
            };

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                template <typename ...> typename                                            algorithm_c_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            >
                requires (argument_tuples_p::Count() == 0)
            class accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, argument_tuples_p>
            {
            public:
                using type_t = nkr::tuple::types_t<>;
            };

            template <
                template <typename ...> typename                                            algorithm_a_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_b_p,
                template <typename ...> typename                                            algorithm_c_p,
                template <template <typename ...> typename, typename, typename> typename    algorithm_d_p,
                template <typename ...> typename                                            template_p,
                nkr::tuple::types_tr                                                        argument_tuples_p
            > using accumulate_per_t =
                typename accumulate_per_tmpl<algorithm_a_p, algorithm_b_p, algorithm_c_p, algorithm_d_p, template_p, argument_tuples_p>::type_t;

        }

        template <
            template <typename ...> typename    template_p,
            nkr::tuple::types_tr                argument_tuples_p
        > class template_types_accumulator_t
        {
        public:
            using just_const_of_just_const_ts = template_types_accumulator_t$::accumulate_t<
                types_accumulator_t$::just_const_t,
                template_p,
                template_types_accumulator_t$::of_just_const_t,
                argument_tuples_p
            >;

            using any_of_any_ts = template_types_accumulator_t$::accumulate_t<
                types_accumulator_t$::any_t,
                template_p,
                template_types_accumulator_t$::of_any_t,
                argument_tuples_p
            >;

            using any_const_of_any_const_ts = template_types_accumulator_t$::accumulate_t<
                types_accumulator_t$::any_const_t,
                template_p,
                template_types_accumulator_t$::of_any_const_t,
                argument_tuples_p
            >;

        public:
            using any_of_any_per_any_of_any_ts = template_types_accumulator_t$::accumulate_per_t<
                types_accumulator_t$::any_t,
                template_types_accumulator_t$::of_any_t,
                types_accumulator_t$::any_t,
                template_types_accumulator_t$::of_any_t,
                template_p,
                argument_tuples_p
            >;

        public:
            using cpp_any_of_any_ts = any_of_any_ts::template into_t<nkr::cpp::tuple::values_t>;
        };

        using test_ts = template_types_accumulator_t<
            nkr::enumeration::errors_t,
            nkr::tuple::types_t<
                nkr::tuple::types_t<nkr::positive::integer_32_t>,
                nkr::tuple::types_t<nkr::positive::integer_64_t>,
                nkr::tuple::types_t<nkr::negatable::integer_32_t>,
                nkr::tuple::types_t<nkr::negatable::integer_64_t>/*,
                nkr::tuple::types_t<user_defined_t>*/
            >
        >;

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
                TEST_CASE_TEMPLATE_APPLY(_2c02690b_6d3c_4079_88f5_cff123b952c6, test_ts::cpp_any_of_any_ts);

                TEST_CASE_TEMPLATE_DEFINE("should cast to false", errors_p, _c4babb07_37d8_487c_b655_a3406c8445c6)
                {
                    using none_t = typename errors_p::none_t;

                    errors_p errors;

                    CHECK((errors == false));
                }
                TEST_CASE_TEMPLATE_APPLY(_c4babb07_37d8_487c_b655_a3406c8445c6, test_ts::cpp_any_of_any_ts);
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
                    /*TEST_CASE_TEMPLATE("non_qualified", errors_p, nkr_ANY)
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
                    }*/
                }
            }

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move other and disarm it"))
            {
                TEST_SUITE("value")
                {
                    /*TEST_CASE_TEMPLATE("non_qualified", errors_p, nkr_ANY)
                    {
                        using integer_t = typename errors_p::integer_t;

                        integer_t integer = nkr::randomness::Value<integer_t>();
                        errors_p errors = nkr::cpp::just_non_qualified_t<errors_p>(integer);

                        CHECK((errors == integer));
                    }*/
                }

                TEST_SUITE("rvalue")
                {
                    /*TEST_CASE_TEMPLATE("non_qualified", errors_p, nkr_ANY)
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
                    }*/
                }
            }

            TEST_SUITE("destructor()")
            {
                /*TEST_CASE_TEMPLATE("should call the destructors of its data members", errors_p, nkr_ANY_OF_ANY(user_defined_t))
                {
                    errors_p errors;

                    CHECK(errors.Value().Is_Live() == true);

                    errors.~errors_p();
                    CHECK(errors.Value().Is_Live() == false);
                }*/
            }
        }
    }

}
