/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/accumulator/templates_t.h"
#include "nkr/enumeration/cpp_t.h"
#include "nkr/enumeration/errors_t.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/macros.h"
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

        explicit operator nkr::boolean::cpp_t() const noexcept
        {
            return this->error_integer != 0;
        }

        explicit operator nkr::boolean::cpp_t() const volatile noexcept
        {
            return this->error_integer != 0;
        }
    };

    template <typename type_p>
    concept user_defined_tr =
        nkr::cpp::is_any_tr<type_p, user_defined_t>;

}}}}

namespace nkr { namespace enumeration { namespace errors_t$ { namespace test {

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

}}}}

namespace nkr { namespace interface { namespace enumeration {

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_t$::test::user_defined_t> type_p>
    class types_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::test::user_defined_t_interface_enumeration_types_sp<type_p>;
    };

}}}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::user_defined_tr auto& a, auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;

    if constexpr (nkr::cpp::is_any_tr<a_t, b_t>) {
        return a.error_integer == b.error_integer;
    } else if constexpr (nkr::cpp::is_any_tr<b_t, nkr::boolean::cpp_t>) {
        return static_cast<nkr::boolean::cpp_t>(a) == b;
    } else if constexpr (nkr::cpp::is_any_tr<b_t, typename a_t::integer_t>) {
        return a.error_integer == b;
    } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
        return nkr::cpp::just_non_qualified_t<b_t>(a) == b;
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
        return a == nkr::cpp::just_non_qualified_t<a_t>(b);
    } else {
        [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "these two values can not be compared."); }();
    }
}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::user_defined_tr auto& a, auto&& b)
    noexcept
{
    return operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::user_defined_tr auto&& a, auto& b)
    noexcept
{
    return operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::user_defined_tr auto&& a, auto&& b)
    noexcept
{
    return operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::user_defined_tr auto& a, auto& b)
    noexcept
{
    return !operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::user_defined_tr auto& a, auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::user_defined_tr auto&& a, auto& b)
    noexcept
{
    return !operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::user_defined_tr auto&& a, auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

namespace nkr { namespace enumeration { namespace errors_t$ { namespace test {

    template <typename type_p>
    class example_e :
        public nkr::enumeration::errors_t<type_p, nkr::constant_t<typename nkr::enumeration::errors_t<type_p>::integer_t, 0>>
    {
    public:
        using base_t    = nkr::enumeration::errors_t<type_p, nkr::constant_t<typename nkr::enumeration::errors_t<type_p>::integer_t, 0>>;

    public:
        enum enumeration_t :
            typename base_t::integer_t
        {
            NONE_lb     = base_t::none_t::Value(),

            ERROR_A     = NONE_lb + 1,
            ERROR_B,
            ERROR_C,
            ERROR_D,
            ERROR_E,
            ERROR_F,

            MIN_lb      = NONE_lb,
            MAX_lb      = ERROR_F,
        };

    public:
        nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(example_e, base_t);
    };

    template <typename type_p>
    concept example_tr =
        nkr::cpp::is_any_tr<type_p, example_e<typename type_p::base_t::type_t>>;

}}}}

namespace nkr { namespace enumeration { namespace errors_t$ { namespace test { namespace example_e$ {

    template <nkr::enumeration::errors_t$::test::example_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t
            Value(value_t min = value_t::MIN_lb, value_t max = value_t::MAX_lb)
            noexcept
        {
            return nkr::interface::randomness::value_i<typename value_t::enumeration_t>::template Value<>(
                typename value_t::enumeration_t(min.Integer()),
                typename value_t::enumeration_t(max.Integer()));
        }

        template <typename unused_p = nkr::none::type_t>
        static value_t
            Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                  value_t min = value_t::MIN_lb, value_t max = value_t::MAX_lb)
            noexcept
        {
            return nkr::interface::randomness::value_i<typename value_t::enumeration_t>::template Value<>(
                generator,
                typename value_t::enumeration_t(min.Integer()),
                typename value_t::enumeration_t(max.Integer()));
        }

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::enumeration::errors_t$::test::example_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::test::example_e$::randomness_value_i_sp<type_p>;
    };

}}}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::example_tr auto& a, auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;

    return operator ==(static_cast<nkr::cpp::same_qualification_as_t<typename a_t::base_t, a_t>&>(a), b);
}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::example_tr auto& a, auto&& b)
    noexcept
{
    return operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::example_tr auto&& a, auto& b)
    noexcept
{
    return operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator ==(nkr::enumeration::errors_t$::test::example_tr auto&& a, auto&& b)
    noexcept
{
    return operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::example_tr auto& a, auto& b)
    noexcept
{
    return !operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::example_tr auto& a, auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::example_tr auto&& a, auto& b)
    noexcept
{
    return !operator ==(a, b);
}

constexpr nkr::boolean::cpp_t
    operator !=(nkr::enumeration::errors_t$::test::example_tr auto&& a, auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

namespace nkr {

    TEST_SUITE("nkr::enumeration::errors_t")
    {
        using test_ts = nkr::accumulator::templates_t<
            nkr::tuple::types_t<
                nkr::accumulator::instantiations_t<
                    nkr::enumeration::errors_t,
                    nkr::tuple::types_t<
                        nkr::tuple::types_t<nkr::positive::integer_t>,
                        nkr::tuple::types_t<nkr::negatable::integer_t>,
                        nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
                    >
                >,
                nkr::accumulator::instantiations_t<
                    nkr::enumeration::errors_t$::test::example_e,
                    nkr::tuple::types_t<
                        nkr::tuple::types_t<nkr::positive::integer_t>,
                        nkr::tuple::types_t<nkr::negatable::integer_t>,
                        nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
                    >
                >
            >
        >;

        using test_example_ts = nkr::accumulator::templates_t<
            nkr::tuple::types_t<
                nkr::accumulator::instantiations_t<
                    nkr::enumeration::errors_t$::test::example_e,
                    nkr::tuple::types_t<
                        nkr::tuple::types_t<nkr::positive::integer_t>,
                        nkr::tuple::types_t<nkr::negatable::integer_t>,
                        nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
                    >
                >
            >
        >;

        using test_user_defined_ts = nkr::accumulator::templates_t<
            nkr::tuple::types_t<
                nkr::accumulator::instantiations_t<
                    nkr::enumeration::errors_t,
                    nkr::tuple::types_t<
                        nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
                    >
                >,
                nkr::accumulator::instantiations_t<
                    nkr::enumeration::errors_t$::test::example_e,
                    nkr::tuple::types_t<
                        nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
                    >
                >
            >
        >;

        inline constexpr nkr::positive::count_t
            Default_Iteration_Count()
            noexcept
        {
            return 128;
        }

        template <typename errors_p>
        inline constexpr auto
            Random_Non_None()
            noexcept
        {
            using errors_t = nkr::cpp::just_non_qualified_t<errors_p>;

            errors_t result;

            do {
                result = nkr::randomness::Value<errors_t>();
            } while (!result);

            return result;
        }

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_constructor()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should equal the none value",
                                          errors_p, _2c02690b_6d3c_4079_88f5_cff123b952c6)
                {
                    using errors_t = errors_p;
                    using none_t = typename errors_t::none_t;

                    errors_t error;

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == true);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif

                    CHECK((error == none_t::Value()));

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == false);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_2c02690b_6d3c_4079_88f5_cff123b952c6,
                                         test_ts::get_cpp_t<any_tg, of_any_tg>);

                TEST_CASE_TEMPLATE_DEFINE("should equal false",
                                          errors_p, _c4babb07_37d8_487c_b655_a3406c8445c6)
                {
                    using errors_t = errors_p;

                    errors_t error;

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == true);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif

                    CHECK((error == false));

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == false);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_c4babb07_37d8_487c_b655_a3406c8445c6,
                                         test_ts::get_cpp_t<any_tg, of_any_tg>);
            }

            TEST_SUITE("enumeration_constructor()"
                       * doctest::description("should set itself to the passed in enumeration"))
            {
                TEST_CASE_TEMPLATE_DEFINE("should work with a passed in named-enumeration",
                                          errors_p, _df715c96_5907_4fbb_a2da_94c14ce52f17)
                {
                    using errors_t = errors_p;

                    errors_t error = errors_t::ERROR_A;

                    CHECK(error == errors_t::ERROR_A);
                }
                TEST_CASE_TEMPLATE_APPLY(_df715c96_5907_4fbb_a2da_94c14ce52f17,
                                         test_example_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                TEST_SUITE("random")
                {
                    template <
                        template <nkr::tuple::types_tr> typename    accumulator_p,
                        typename                                    instantiation_p,
                        template <typename ...> typename            instantiator_p,
                        nkr::tuple::types_tr                        arguments_p
                    > using from_ts = accumulator_p<nkr::tuple::types_t<
                        typename instantiation_p::enumeration_t>>;

                    TEST_CASE_TEMPLATE_DEFINE("value",
                                              pair_p, _a827c31a_144d_4e39_88b4_8df42077f667)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                        from_t backup = nkr::randomness::Value<from_t>();
                        errors_t error = from_t(backup);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        CHECK((error == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                    TEST_CASE_TEMPLATE_APPLY(_a827c31a_144d_4e39_88b4_8df42077f667,
                                             test_ts::get_cpp_paired_types_t<any_tg, of_any_tg, just_non_qualified_tg, from_ts>);

                    TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                              pair_p, _7522e053_c58b_48f0_a055_fdfb6019f4d8)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                        from_t from = nkr::randomness::Value<from_t>();
                        from_t backup = from;
                        errors_t error = from;

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        CHECK((error == from));
                        CHECK((from == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                    TEST_CASE_TEMPLATE_APPLY(_7522e053_c58b_48f0_a055_fdfb6019f4d8,
                                             test_ts::get_cpp_paired_types_t<any_tg, of_any_tg, any_tg, from_ts>);

                    TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                              pair_p, _12fc82b3_6b08_4743_988e_8c44bd1817bd)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                        from_t from = nkr::randomness::Value<from_t>();
                        from_t backup = from;
                        errors_t error = nkr::cpp::Move(from);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        CHECK((error == backup));
                        CHECK((from == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                    TEST_CASE_TEMPLATE_APPLY(_12fc82b3_6b08_4743_988e_8c44bd1817bd,
                                             test_ts::get_cpp_paired_types_t<any_tg, of_any_tg, any_non_const_tg, from_ts>);
                }
            }

            TEST_SUITE("copy_constructor()"
                       * doctest::description("should copy 'other' without changing it"))
            {
                TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                          pair_p, _7a836d8f_350f_4ed5_907e_2f6eee77cd61)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    if constexpr (nkr::cpp::is_tr<typename errors_t::type_t, typename other_t::type_t>) {
                        using enumeration_t = typename errors_t::enumeration_t;

                        enumeration_t backup = nkr::randomness::Value<enumeration_t>();
                        other_t other = backup;
                        errors_t error = other;

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((error == other));
                        CHECK((other == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_7a836d8f_350f_4ed5_907e_2f6eee77cd61,
                                         test_ts::get_cpp_pairs_t<any_tg, of_any_tg, any_tg, of_any_tg>);
            }

            TEST_SUITE("move_constructor()"
                       * doctest::description("should move 'other' and disarm it"))
            {
                TEST_CASE_TEMPLATE_DEFINE("value",
                                          pair_p, _8ca47671_ce56_4438_8174_7212e97b76d1)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    if constexpr (nkr::cpp::is_tr<typename errors_t::type_t, typename other_t::type_t>) {
                        using enumeration_t = typename errors_t::enumeration_t;

                        enumeration_t backup = nkr::randomness::Value<enumeration_t>();
                        errors_t error = other_t(backup);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        CHECK((error == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_8ca47671_ce56_4438_8174_7212e97b76d1,
                                         test_ts::get_cpp_pairs_t<any_tg, of_any_tg, just_non_qualified_tg, of_any_tg>);

                TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                          pair_p, _6f2104e7_030c_44fe_9224_7003d0a40c20)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    if constexpr (nkr::cpp::is_tr<typename errors_t::type_t, typename other_t::type_t>) {
                        using enumeration_t = typename errors_t::enumeration_t;

                        enumeration_t backup = nkr::randomness::Value<enumeration_t>();
                        other_t other = backup;
                        errors_t error = nkr::cpp::Move(other);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((error == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_6f2104e7_030c_44fe_9224_7003d0a40c20,
                                         test_ts::get_cpp_pairs_t<any_tg, of_any_tg, any_non_const_tg, of_any_tg>);
            }

            TEST_SUITE("enumeration_assigner()"
                       * doctest::description("should convert 'from' without changing it"))
            {
                template <
                    template <nkr::tuple::types_tr> typename    accumulator_p,
                    typename                                    instantiation_p,
                    template <typename ...> typename            instantiator_p,
                    nkr::tuple::types_tr                        arguments_p
                > using from_ts = accumulator_p<nkr::tuple::types_t<
                    typename instantiation_p::enumeration_t>>;

                TEST_CASE_TEMPLATE_DEFINE("value",
                                          pair_p, _a827c31a_144d_4e39_88b4_8df42077f667)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    from_t backup = nkr::randomness::Value<from_t>();
                    errors_t error;
                    error = from_t(backup);

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == true);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif

                    CHECK((error == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == false);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_a827c31a_144d_4e39_88b4_8df42077f667,
                                         test_ts::get_cpp_paired_types_t<any_non_const_tg, of_any_non_const_tg, just_non_qualified_tg, from_ts>);

                TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                          pair_p, _7522e053_c58b_48f0_a055_fdfb6019f4d8)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    from_t from = nkr::randomness::Value<from_t>();
                    from_t backup = from;
                    errors_t error;
                    error = from;

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == true);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif

                    CHECK((error == from));
                    CHECK((from == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == false);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_7522e053_c58b_48f0_a055_fdfb6019f4d8,
                                         test_ts::get_cpp_paired_types_t<any_non_const_tg, of_any_non_const_tg, any_tg, from_ts>);

                TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                          pair_p, _12fc82b3_6b08_4743_988e_8c44bd1817bd)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    from_t from = nkr::randomness::Value<from_t>();
                    from_t backup = from;
                    errors_t error;
                    error = nkr::cpp::Move(from);

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == true);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif

                    CHECK((error == backup));
                    CHECK((from == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(error.Is_Armed() == false);
                #else
                    CHECK(error.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_12fc82b3_6b08_4743_988e_8c44bd1817bd,
                                         test_ts::get_cpp_paired_types_t<any_non_const_tg, of_any_non_const_tg, any_non_const_tg, from_ts>);
            }

            TEST_SUITE("copy_assigner()"
                       * doctest::description("should copy 'other' without changing it"))
            {
                TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                          pair_p, _7a836d8f_350f_4ed5_907e_2f6eee77cd61)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    if constexpr (nkr::cpp::is_tr<typename errors_t::type_t, typename other_t::type_t>) {
                        using enumeration_t = typename errors_t::enumeration_t;

                        enumeration_t backup = nkr::randomness::Value<enumeration_t>();
                        other_t other = backup;
                        errors_t error;
                        error = other;

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((error == other));
                        CHECK((other == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_7a836d8f_350f_4ed5_907e_2f6eee77cd61,
                                         test_ts::get_cpp_pairs_t<any_non_const_tg, of_any_non_const_tg, any_tg, of_any_tg>);
            }

            TEST_SUITE("move_assigner()"
                       * doctest::description("should move 'other' and disarm it"))
            {
                TEST_CASE_TEMPLATE_DEFINE("value",
                                          pair_p, _8ca47671_ce56_4438_8174_7212e97b76d1)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    if constexpr (nkr::cpp::is_tr<typename errors_t::type_t, typename other_t::type_t>) {
                        using enumeration_t = typename errors_t::enumeration_t;

                        enumeration_t backup = nkr::randomness::Value<enumeration_t>();
                        errors_t error;
                        error = other_t(backup);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        CHECK((error == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_8ca47671_ce56_4438_8174_7212e97b76d1,
                                         test_ts::get_cpp_pairs_t<any_non_const_tg, of_any_non_const_tg, just_non_qualified_tg, of_any_non_const_tg>);

                TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                          pair_p, _6f2104e7_030c_44fe_9224_7003d0a40c20)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    if constexpr (nkr::cpp::is_tr<typename errors_t::type_t, typename other_t::type_t>) {
                        using enumeration_t = typename errors_t::enumeration_t;

                        enumeration_t backup = nkr::randomness::Value<enumeration_t>();
                        other_t other = backup;
                        errors_t error;
                        error = nkr::cpp::Move(other);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((error == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_6f2104e7_030c_44fe_9224_7003d0a40c20,
                                         test_ts::get_cpp_pairs_t<any_non_const_tg, of_any_non_const_tg, any_non_const_tg, of_any_non_const_tg>);
            }

            TEST_SUITE("destructor()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should call the destructors of its data members",
                                          errors_p, _7b7bcbde_9473_49a9_969d_97b2be2de0b7)
                {
                    using errors_t = errors_p;

                    errors_t error;

                    CHECK(error.Value().Is_Live() == true);
                    error.~errors_t();
                    CHECK(error.Value().Is_Live() == false);
                }
                TEST_CASE_TEMPLATE_APPLY(_7b7bcbde_9473_49a9_969d_97b2be2de0b7,
                                         test_user_defined_ts::get_cpp_t<any_tg, of_any_tg>);
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Boolean()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should return false when there is no error, else true",
                                          errors_p, _467cbb35_f233_461b_b744_f9bf8601ff85)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        errors_t error = nkr::randomness::Value<enumeration_t>();

                        if (error == enumeration_t::NONE_lb) {
                            CHECK(error.Boolean() == false);
                        } else {
                            CHECK(error.Boolean() == true);
                        }
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_467cbb35_f233_461b_b744_f9bf8601ff85,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);
            }

            TEST_SUITE("Integer()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should return an integer equatable to the enumeration_t passed in",
                                          errors_p, _467cbb35_f233_461b_b744_f9bf8601ff85)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        enumeration_t enumeration = nkr::randomness::Value<enumeration_t>();
                        errors_t error = enumeration;

                        CHECK(enumeration_t(error.Integer()) == enumeration);
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_467cbb35_f233_461b_b744_f9bf8601ff85,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                TEST_SUITE("should set itself to anything passed in that can be constructed as an integer_t")
                {
                    template <
                        template <nkr::tuple::types_tr> typename    accumulator_p,
                        typename                                    instantiation_p,
                        template <typename ...> typename            instantiator_p,
                        nkr::tuple::types_tr                        arguments_p
                    > using from_ts = accumulator_p<nkr::tuple::types_t<
                        typename instantiation_p::enumeration_t,
                        typename instantiation_p::integer_t,
                        typename nkr::positive::byte_t>>;

                    TEST_CASE_TEMPLATE_DEFINE("value",
                                              pair_p, _a5662bce_4b36_4bc7_8b60_b361eeb1fa3e)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            other_t backup = nkr::randomness::Value<other_t>();
                            errors_t error;
                            error.Integer(other_t(backup));

                            CHECK((error == backup));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_a5662bce_4b36_4bc7_8b60_b361eeb1fa3e,
                                             test_ts::get_cpp_paired_types_t<any_non_const_tg, of_just_non_qualified_tg, just_non_qualified_tg, from_ts>);

                    TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                              pair_p, _b0ef003f_c21b_437d_963e_be962b947da4)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            other_t backup = nkr::randomness::Value<other_t>();
                            other_t other = backup;
                            errors_t error;
                            error.Integer(other);

                            CHECK((error == other));
                            CHECK((other == backup));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_b0ef003f_c21b_437d_963e_be962b947da4,
                                             test_ts::get_cpp_paired_types_t<any_non_const_tg, of_just_non_qualified_tg, any_tg, from_ts>);

                    TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                              pair_p, _23d3895a_32a1_4b60_850c_40318b60aa27)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            other_t backup = nkr::randomness::Value<other_t>();
                            other_t other = backup;
                            errors_t error;
                            error.Integer(nkr::cpp::Move(other));

                            CHECK((error == backup));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_23d3895a_32a1_4b60_850c_40318b60aa27,
                                             test_ts::get_cpp_paired_types_t<any_non_const_tg, of_just_non_qualified_tg, any_non_const_tg, from_ts>);
                }
            }

            TEST_SUITE("Value()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should return a reference to the actual value of the enum",
                                          errors_p, _e43d45a0_f512_4fb7_8917_e4cb73d039fe)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;
                    using integer_t = typename errors_t::integer_t;
                    using value_t = typename errors_t::value_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        value_t value = nkr::randomness::Value<enumeration_t>();
                        errors_t error = enumeration_t(integer_t(value));

                        CHECK(error.Value() == value);
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_e43d45a0_f512_4fb7_8917_e4cb73d039fe,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                TEST_SUITE("should set itself to the value_t passed in")
                {
                    template <
                        template <nkr::tuple::types_tr> typename    accumulator_p,
                        typename                                    instantiation_p,
                        template <typename ...> typename            instantiator_p,
                        nkr::tuple::types_tr                        arguments_p
                    > using from_ts = accumulator_p<nkr::tuple::types_t<
                        typename instantiation_p::value_t>>;

                    TEST_CASE_TEMPLATE_DEFINE("value",
                                              pair_p, _a7ad03b2_2d04_47d9_ad75_e53d61b4925b)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                        using enumeration_t = typename errors_t::enumeration_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            other_t backup = nkr::randomness::Value<enumeration_t>();
                            errors_t error;
                            error.Value(other_t(backup));

                            CHECK((error == backup));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_a7ad03b2_2d04_47d9_ad75_e53d61b4925b,
                                             test_ts::get_cpp_paired_types_t<any_non_const_tg, of_just_non_qualified_tg, just_non_qualified_tg, from_ts>);

                    TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                              pair_p, _578358b5_fba3_4231_9d3a_db141f813716)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                        using enumeration_t = typename errors_t::enumeration_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            other_t backup = nkr::randomness::Value<enumeration_t>();
                            other_t other = backup;
                            errors_t error;
                            error.Value(other);

                            CHECK((error == other));
                            CHECK((other == backup));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_578358b5_fba3_4231_9d3a_db141f813716,
                                             test_ts::get_cpp_paired_types_t<any_non_const_tg, of_just_non_qualified_tg, any_tg, from_ts>);

                    TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                              pair_p, _967e7fd2_f011_44f9_99c7_4a7a31147add)
                    {
                        using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                        using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                        using enumeration_t = typename errors_t::enumeration_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            other_t backup = nkr::randomness::Value<enumeration_t>();
                            other_t other = backup;
                            errors_t error;
                            error.Value(nkr::cpp::Move(other));

                            CHECK((error == backup));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_967e7fd2_f011_44f9_99c7_4a7a31147add,
                                             test_ts::get_cpp_paired_types_t<any_non_const_tg, of_just_non_qualified_tg, any_non_const_tg, from_ts>);
                }
            }

            TEST_SUITE("Is_Armed()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should return true only when in debug mode and if the error has not be read",
                                          errors_p, _dc17e19f_b7d5_42d7_835a_9396f63638fb)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        errors_t error = nkr::randomness::Value<enumeration_t>();

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        if (error) {
                        }

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_dc17e19f_b7d5_42d7_835a_9396f63638fb,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);
            }

            TEST_SUITE("Arm()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should arm the error even if it's already been read",
                                          errors_p, _333efb73_2fd7_46d5_9d8f_ca3577a0d974)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        errors_t error = nkr::randomness::Value<enumeration_t>();

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        if (error) {
                        }

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        error.Arm();

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        if (error) {
                        }

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_333efb73_2fd7_46d5_9d8f_ca3577a0d974,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);
            }

            TEST_SUITE("Disarm()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should disarm the error even if it's not been read",
                                          errors_p, _8800f3e7_9989_4c97_ad1f_2bdd4d92b944)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        errors_t error = nkr::randomness::Value<enumeration_t>();

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == true);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif

                        error.Disarm();

                    #if defined(nkr_IS_DEBUG)
                        CHECK(error.Is_Armed() == false);
                    #else
                        CHECK(error.Is_Armed() == false);
                    #endif
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_8800f3e7_9989_4c97_ad1f_2bdd4d92b944,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);
            }
        }

        TEST_SUITE("casters")
        {
            TEST_SUITE("nkr::boolean::cpp_t")
            {

            }

            TEST_SUITE("enumeration_t")
            {
                TEST_CASE("temp")
                {
                    using errors_t = nkr::enumeration::errors_t$::test::example_e<nkr::positive::integer_t>;

                    errors_t error = errors_t::ERROR_C;

                    CHECK(static_cast<typename errors_t::enumeration_t>(error) == errors_t::ERROR_C);
                }
            }

            TEST_SUITE("integer_t")
            {

            }
        }

        TEST_SUITE("operators")
        {
            TEST_SUITE("()()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should return the none value integer by default",
                                          errors_p, _7e11ab31_5883_4df1_bac5_934362aedbb1)
                {
                    using errors_t = errors_p;
                    using none_t = typename errors_t::none_t;

                    errors_t error;

                    CHECK((error() == none_t::Value()));
                }
                TEST_CASE_TEMPLATE_APPLY(_7e11ab31_5883_4df1_bac5_934362aedbb1,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                TEST_CASE_TEMPLATE_DEFINE("should return an integer equatable to the enumeration_t passed in",
                                          errors_p, _3a4a435e_6e75_49b3_a792_fbf3de42fa80)
                {
                    using errors_t = errors_p;
                    using enumeration_t = typename errors_t::enumeration_t;

                    for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                        enumeration_t enumeration = nkr::randomness::Value<enumeration_t>();
                        errors_t error = enumeration;

                        CHECK(enumeration_t(error()) == enumeration);
                    }
                }
                TEST_CASE_TEMPLATE_APPLY(_3a4a435e_6e75_49b3_a792_fbf3de42fa80,
                                         test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);
            }

            TEST_SUITE("unary_logical")
            {
                TEST_SUITE("!()")
                {
                    TEST_CASE_TEMPLATE_DEFINE("should return true when defaulted",
                                              errors_p, _843a12d3_85ed_4118_97e3_56f0e09ae930)
                    {
                        using errors_t = errors_p;

                        errors_t error;

                        CHECK(!error);
                    }
                    TEST_CASE_TEMPLATE_APPLY(_843a12d3_85ed_4118_97e3_56f0e09ae930,
                                             test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                    TEST_CASE_TEMPLATE_DEFINE("should return the opposite of Boolean()",
                                              errors_p, _4a7010ce_70da_4cd1_8e62_911268d271c5)
                    {
                        using errors_t = errors_p;
                        using enumeration_t = typename errors_t::enumeration_t;

                        for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                            errors_t error = nkr::randomness::Value<enumeration_t>();

                            CHECK((!error == !error.Boolean()));
                        }
                    }
                    TEST_CASE_TEMPLATE_APPLY(_4a7010ce_70da_4cd1_8e62_911268d271c5,
                                             test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);
                }
            }

            TEST_SUITE("binary_logical")
            {
                TEST_SUITE("||()")
                {
                    TEST_CASE_TEMPLATE_DEFINE("should use the underlying boolean cast",
                                              errors_p, _7b7b005c_eb16_4f0b_8565_0d08a541e367)
                    {
                        using errors_t = errors_p;
                        using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;

                        errors_t a = errors_t::NONE_lb;
                        errors_t b = Random_Non_None<errors_t>();

                        CHECK((a || a) == false);
                        CHECK((a || b) == true);
                        CHECK((b || a) == true);
                        CHECK((b || b) == true);
                    }
                    TEST_CASE_TEMPLATE_APPLY(_7b7b005c_eb16_4f0b_8565_0d08a541e367,
                                             test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                    TEST_SUITE("random")
                    {
                        template <
                            template <nkr::tuple::types_tr> typename    accumulator_p,
                            typename                                    instantiation_p,
                            template <typename ...> typename            instantiator_p,
                            nkr::tuple::types_tr                        arguments_p
                        > using from_ts = accumulator_p<nkr::tuple::types_t<
                            instantiation_p,
                            typename instantiation_p::enumeration_t,
                            typename instantiation_p::integer_t>>;

                        TEST_CASE_TEMPLATE_DEFINE("value",
                                                  pair_p, _8cbdca82_4b95_4491_89e7_c7a3b347671a)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (a || non_qualified_other_t(b)));
                                CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (non_qualified_other_t(b) || a));
                                CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (non_qualified_errors_t(a) || b));
                                CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (b || non_qualified_errors_t(a)));
                                CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (non_qualified_errors_t(a) || non_qualified_other_t(b)));
                                CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (non_qualified_other_t(b) || non_qualified_errors_t(a)));
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_8cbdca82_4b95_4491_89e7_c7a3b347671a,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, just_non_qualified_tg, from_ts>);

                        TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                                  pair_p, _8f6172f9_34e8_47aa_9fc6_404b86450a51)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (a || b));
                                CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (b || a));
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_8f6172f9_34e8_47aa_9fc6_404b86450a51,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, any_tg, from_ts>);

                        TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                                  pair_p, _c4732c55_033e_49e8_b081_78da8fc31171)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (a || nkr::cpp::Move(b)));
                                CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (nkr::cpp::Move(b) || a));
                                if constexpr (nkr::cpp::any_non_const_tr<errors_t>) {
                                    CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (nkr::cpp::Move(a) || b));
                                    CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (b || nkr::cpp::Move(a)));
                                    CHECK((non_qualified_errors_t(a) || non_qualified_other_t(b)) == (nkr::cpp::Move(a) || nkr::cpp::Move(b)));
                                    CHECK((non_qualified_other_t(b) || non_qualified_errors_t(a)) == (nkr::cpp::Move(b) || nkr::cpp::Move(a)));
                                }
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_c4732c55_033e_49e8_b081_78da8fc31171,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, any_non_const_tg, from_ts>);
                    }
                }

                TEST_SUITE("&&()")
                {
                    TEST_CASE_TEMPLATE_DEFINE("should use the underlying boolean cast",
                                              errors_p, _7b7b005c_eb16_4f0b_8565_0d08a541e367)
                    {
                        using errors_t = errors_p;
                        using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;

                        errors_t a = errors_t::NONE_lb;
                        errors_t b = Random_Non_None<errors_t>();

                        CHECK((a && a) == false);
                        CHECK((a && b) == false);
                        CHECK((b && a) == false);
                        CHECK((b && b) == true);
                    }
                    TEST_CASE_TEMPLATE_APPLY(_7b7b005c_eb16_4f0b_8565_0d08a541e367,
                                             test_ts::get_cpp_t<any_tg, of_just_non_qualified_tg>);

                    TEST_SUITE("random")
                    {
                        template <
                            template <nkr::tuple::types_tr> typename    accumulator_p,
                            typename                                    instantiation_p,
                            template <typename ...> typename            instantiator_p,
                            nkr::tuple::types_tr                        arguments_p
                        > using from_ts = accumulator_p<nkr::tuple::types_t<
                            instantiation_p,
                            typename instantiation_p::enumeration_t,
                            typename instantiation_p::integer_t>>;

                        TEST_CASE_TEMPLATE_DEFINE("value",
                                                  pair_p, _75d805a0_4afb_45b0_974c_13258325b634)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (a && non_qualified_other_t(b)));
                                CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (non_qualified_other_t(b) && a));
                                CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (non_qualified_errors_t(a) && b));
                                CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (b && non_qualified_errors_t(a)));
                                CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (non_qualified_errors_t(a) && non_qualified_other_t(b)));
                                CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (non_qualified_other_t(b) && non_qualified_errors_t(a)));
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_75d805a0_4afb_45b0_974c_13258325b634,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, just_non_qualified_tg, from_ts>);

                        TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                                  pair_p, _c9f54109_19d3_4f14_a2c2_bb4c840da743)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (a && b));
                                CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (b && a));
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_c9f54109_19d3_4f14_a2c2_bb4c840da743,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, any_tg, from_ts>);

                        TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                                  pair_p, _79a5f56d_d8fc_4794_a1cd_7ec38d3070ed)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (a && nkr::cpp::Move(b)));
                                CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (nkr::cpp::Move(b) && a));
                                if constexpr (nkr::cpp::any_non_const_tr<errors_t>) {
                                    CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (nkr::cpp::Move(a) && b));
                                    CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (b && nkr::cpp::Move(a)));
                                    CHECK((non_qualified_errors_t(a) && non_qualified_other_t(b)) == (nkr::cpp::Move(a) && nkr::cpp::Move(b)));
                                    CHECK((non_qualified_other_t(b) && non_qualified_errors_t(a)) == (nkr::cpp::Move(b) && nkr::cpp::Move(a)));
                                }
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_79a5f56d_d8fc_4794_a1cd_7ec38d3070ed,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, any_non_const_tg, from_ts>);
                    }
                }
            }

            TEST_SUITE("trinary_logical")
            {
                TEST_SUITE("?:()")
                {
                    TEST_SUITE("random")
                    {
                        template <
                            template <nkr::tuple::types_tr> typename    accumulator_p,
                            typename                                    instantiation_p,
                            template <typename ...> typename            instantiator_p,
                            nkr::tuple::types_tr                        arguments_p
                        > using from_ts = accumulator_p<nkr::tuple::types_t<
                            instantiation_p,
                            typename instantiation_p::enumeration_t,
                            typename instantiation_p::integer_t>>;

                        TEST_CASE_TEMPLATE_DEFINE("value",
                                                  pair_p, _5098f5b5_fc20_4b01_81b2_3911638d24b9)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();
                                other_t c = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (a ? non_qualified_other_t(b) : non_qualified_other_t(c)));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (a ? non_qualified_other_t(c) : non_qualified_other_t(b)));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (non_qualified_errors_t(a) ? b : c));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (non_qualified_errors_t(a) ? c : b));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)));
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_5098f5b5_fc20_4b01_81b2_3911638d24b9,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, just_non_qualified_tg, from_ts>);

                        TEST_CASE_TEMPLATE_DEFINE("lvalue",
                                                  pair_p, _8ca9eb94_b30e_49da_a05a_f9e87c5f5e62)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();
                                other_t c = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (a ? b : c));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (a ? c : b));
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_8ca9eb94_b30e_49da_a05a_f9e87c5f5e62,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, any_tg, from_ts>);

                        TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                                  pair_p, _1cd42e74_e378_43d1_8f99_56614ed038d2)
                        {
                            using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                            using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                            using non_qualified_errors_t = nkr::cpp::just_non_qualified_t<errors_t>;
                            using non_qualified_other_t = nkr::cpp::just_non_qualified_t<other_t>;

                            for (nkr::positive::index_t idx = 0, end = Default_Iteration_Count(); idx < end; idx += 1) {
                                errors_t a = nkr::randomness::Value<errors_t>();
                                other_t b = nkr::randomness::Value<other_t>();
                                other_t c = nkr::randomness::Value<other_t>();

                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (a ? nkr::cpp::Move(b) : nkr::cpp::Move(c)));
                                CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (a ? nkr::cpp::Move(c) : nkr::cpp::Move(b)));
                                if constexpr (nkr::cpp::any_non_const_tr<errors_t>) {
                                    CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (nkr::cpp::Move(a) ? b : c));
                                    CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (nkr::cpp::Move(a) ? c : b));
                                    CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(b) : non_qualified_other_t(c)) == (nkr::cpp::Move(a) ? nkr::cpp::Move(b) : nkr::cpp::Move(c)));
                                    CHECK((non_qualified_errors_t(a) ? non_qualified_other_t(c) : non_qualified_other_t(b)) == (nkr::cpp::Move(a) ? nkr::cpp::Move(c) : nkr::cpp::Move(b)));
                                }
                            }
                        }
                        TEST_CASE_TEMPLATE_APPLY(_1cd42e74_e378_43d1_8f99_56614ed038d2,
                                                 test_ts::get_cpp_paired_types_t<any_tg, of_just_non_qualified_tg, any_non_const_tg, from_ts>);
                    }
                }
            }

            TEST_SUITE("binary_comparison")
            {
                TEST_SUITE("==()")
                {

                }

                TEST_SUITE("!=()")
                {

                }

                TEST_SUITE("<()")
                {

                }

                TEST_SUITE(">()")
                {

                }

                TEST_SUITE("<=()")
                {

                }

                TEST_SUITE(">=()")
                {

                }

                TEST_SUITE("<=>()")
                {

                }
            }
        }
    }

}
