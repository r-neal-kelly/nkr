/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/accumulator/instantiations_t.h"
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
            NONE_tg     = base_t::none_t::Value(),

            ERROR_A,
            ERROR_B,
            ERROR_C,
            ERROR_D,
            ERROR_E,
            ERROR_F,

            MIN_tg      = NONE_tg,
            MAX_tg      = ERROR_F,

            // The above should be _lb, but we need to update some interfaces that requires _tg.
            NONE_lb     = NONE_tg,
            MIN_lb      = NONE_tg,
            MAX_lb      = ERROR_F,
        };

    public:
        nkr_CONSTEXPR_INHERITANCE_WRAPPER_DEFINE_CTORS(example_e, base_t);
    };

    template <typename type_p>
    concept example_tr =
        nkr::cpp::is_any_tr<type_p, example_e<typename type_p::base_t::type_t>>;

}}}}

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
        using test_ts = nkr::accumulator::instantiations_t<
            nkr::enumeration::errors_t$::test::example_e,
            nkr::tuple::types_t<
                nkr::tuple::types_t<nkr::positive::integer_32_t>,
                nkr::tuple::types_t<nkr::positive::integer_64_t>,
                nkr::tuple::types_t<nkr::negatable::integer_32_t>,
                nkr::tuple::types_t<nkr::negatable::integer_64_t>,
                nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
            >
        >;

        using test_user_defined_ts = nkr::accumulator::instantiations_t<
            nkr::enumeration::errors_t$::test::example_e,
            nkr::tuple::types_t<
                nkr::tuple::types_t<nkr::enumeration::errors_t$::test::user_defined_t>
            >
        >;

        TEST_SUITE("objects")
        {
            TEST_SUITE("default_constructor()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should equal the none value",
                                          errors_p, _2c02690b_6d3c_4079_88f5_cff123b952c6)
                {
                    using errors_t = errors_p;
                    using none_t = typename errors_t::none_t;

                    errors_t errors;

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == none_t::Value()));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_2c02690b_6d3c_4079_88f5_cff123b952c6,
                                         test_ts::get_cpp_t<any_tg, of_any_tg>);

                TEST_CASE_TEMPLATE_DEFINE("should equal false",
                                          errors_p, _c4babb07_37d8_487c_b655_a3406c8445c6)
                {
                    using errors_t = errors_p;

                    errors_t errors;

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == false));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_c4babb07_37d8_487c_b655_a3406c8445c6,
                                         test_ts::get_cpp_t<any_tg, of_any_tg>);
            }

            TEST_SUITE("enumeration_constructor()"
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
                    errors_t errors = from_t(backup);

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
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
                    errors_t errors = from;

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == from));
                    CHECK((from == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
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
                    errors_t errors = nkr::cpp::Move(from);

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == backup));
                    CHECK((from == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif
                }
                TEST_CASE_TEMPLATE_APPLY(_12fc82b3_6b08_4743_988e_8c44bd1817bd,
                                         test_ts::get_cpp_paired_types_t<any_tg, of_any_tg, any_non_const_tg, from_ts>);
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
                        errors_t errors = other;

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((errors == other));
                        CHECK((other == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
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
                        errors_t errors = other_t(backup);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == true);
                    #else
                        CHECK(errors.Is_Armed() == false);
                    #endif

                        CHECK((errors == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
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
                        errors_t errors = nkr::cpp::Move(other);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((errors == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
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
                    errors_t errors;
                    errors = from_t(backup);

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
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
                    errors_t errors;
                    errors = from;

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == from));
                    CHECK((from == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
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
                    errors_t errors;
                    errors = nkr::cpp::Move(from);

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == true);
                #else
                    CHECK(errors.Is_Armed() == false);
                #endif

                    CHECK((errors == backup));
                    CHECK((from == backup));

                #if defined(nkr_IS_DEBUG)
                    CHECK(errors.Is_Armed() == false);
                #else
                    CHECK(errors.Is_Armed() == false);
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
                        errors_t errors;
                        errors = other;

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((errors == other));
                        CHECK((other == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
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
                        errors_t errors;
                        errors = other_t(backup);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == true);
                    #else
                        CHECK(errors.Is_Armed() == false);
                    #endif

                        CHECK((errors == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
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
                        errors_t errors;
                        errors = nkr::cpp::Move(other);

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == true);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #endif

                        CHECK((errors == backup));

                    #if defined(nkr_IS_DEBUG)
                        CHECK(errors.Is_Armed() == false);
                        CHECK(other.Is_Armed() == false);
                    #else
                        CHECK(errors.Is_Armed() == false);
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

                    errors_t errors;

                    CHECK(errors.Value().Is_Live() == true);
                    errors.~errors_t();
                    CHECK(errors.Value().Is_Live() == false);
                }
                TEST_CASE_TEMPLATE_APPLY(_7b7bcbde_9473_49a9_969d_97b2be2de0b7,
                                         test_user_defined_ts::get_cpp_t<any_tg, of_any_tg>);
            }
        }

        TEST_SUITE("methods")
        {
            TEST_SUITE("Boolean()")
            {

            }

            TEST_SUITE("Integer()")
            {

            }

            TEST_SUITE("Value()")
            {

            }

            TEST_SUITE("Is_Armed()")
            {

            }

            TEST_SUITE("Arm()")
            {

            }

            TEST_SUITE("Disarm()")
            {

            }
        }
    }

}
