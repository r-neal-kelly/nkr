/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/accumulator/instantiations_t.h"
#include "nkr/enumeration/errors_t.h"
#include "nkr/interface/forward.h"
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

    template <nkr::cpp::is_any_tr<user_defined_t> type_p>
    class user_defined_t_interface_randomness_value_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using integer_t = typename type_t::integer_t;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t
            Value(integer_t min = nkr::cpp::Default_Min<integer_t>(), integer_t max = nkr::cpp::Default_Max<integer_t>())
            noexcept
        {
            return nkr::interface::randomness::value_i<integer_t>::template Value<>(min, max);
        }

        template <typename unused_p = nkr::none::type_t>
        static value_t
            Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                  integer_t min = nkr::cpp::Default_Min<integer_t>(), integer_t max = nkr::cpp::Default_Max<integer_t>())
            noexcept
        {
            return nkr::interface::randomness::value_i<integer_t>::template Value<>(generator, min, max);
        }

    public:
        template <typename ...>
        constexpr user_defined_t_interface_randomness_value_sp(...) noexcept    = delete;
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

namespace nkr { namespace interface { namespace randomness {

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_t$::test::user_defined_t> type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::test::user_defined_t_interface_randomness_value_sp<type_p>;
    };

}}}

namespace nkr {

    TEST_SUITE("nkr::enumeration::errors_t")
    {
        using user_defined_t = nkr::enumeration::errors_t$::test::user_defined_t;

        using test_ts = nkr::accumulator::instantiations_t<
            nkr::enumeration::errors_t,
            nkr::tuple::types_t<
                nkr::tuple::types_t<nkr::positive::integer_32_t>,
                nkr::tuple::types_t<nkr::positive::integer_64_t>,
                nkr::tuple::types_t<nkr::negatable::integer_32_t>,
                nkr::tuple::types_t<nkr::negatable::integer_64_t>,
                nkr::tuple::types_t<user_defined_t>
            >
        >;

        using test_user_defined_ts = nkr::accumulator::instantiations_t<
            nkr::enumeration::errors_t,
            nkr::tuple::types_t<
                nkr::tuple::types_t<user_defined_t>
            >
        >;

        // should copying disarm the error? It seems to get disarmed, so double check that this is occuring only where we want it to.
        TEST_SUITE("objects")
        {
            TEST_SUITE("default_constructor()")
            {
                TEST_CASE_TEMPLATE_DEFINE("should equal the default integer",
                                          errors_p, _2c02690b_6d3c_4079_88f5_cff123b952c6)
                {
                    using errors_t = errors_p;
                    using none_t = typename errors_t::none_t;

                    errors_t errors;

                    CHECK((errors == none_t::Value()));
                }
                TEST_CASE_TEMPLATE_APPLY(_2c02690b_6d3c_4079_88f5_cff123b952c6,
                                         test_ts::get_cpp_t<any_tg, of_any_tg>);

                TEST_CASE_TEMPLATE_DEFINE("should cast to false",
                                          errors_p, _c4babb07_37d8_487c_b655_a3406c8445c6)
                {
                    using errors_t = errors_p;

                    errors_t errors;

                    CHECK((errors == false));
                }
                TEST_CASE_TEMPLATE_APPLY(_c4babb07_37d8_487c_b655_a3406c8445c6,
                                         test_ts::get_cpp_t<any_tg, of_any_tg>);
            }

            TEST_SUITE("to_constructor()"
                       * doctest::description("should convert 'from' without changing it"))
            {
                template <
                    template <nkr::tuple::types_tr> typename    accumulator_p,
                    typename                                    instantiation_p,
                    template <typename ...> typename            instantiator_p,
                    nkr::tuple::types_tr                        arguments_p
                > using from_ts = accumulator_p<nkr::tuple::types_t<
                    typename instantiation_p::integer_t,
                    typename instantiation_p::value_t>>;

                TEST_CASE_TEMPLATE_DEFINE("value",
                                          pair_p, _a827c31a_144d_4e39_88b4_8df42077f667)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using from_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;

                    from_t backup = nkr::randomness::Value<from_t>();
                    errors_t errors = from_t(backup);

                    CHECK((errors == backup));
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

                    CHECK((errors == from));
                    CHECK((from == backup));
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

                    CHECK((errors == backup));
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
                    using integer_t = typename errors_t::integer_t;

                    integer_t backup = nkr::randomness::Value<integer_t>();
                    other_t other = backup;
                    errors_t errors = other;

                    CHECK((errors == other));
                    CHECK((other == backup));
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
                    using integer_t = typename errors_t::integer_t;

                    integer_t backup = nkr::randomness::Value<integer_t>();
                    errors_t errors = other_t(backup);

                    CHECK((errors == backup));
                }
                TEST_CASE_TEMPLATE_APPLY(_8ca47671_ce56_4438_8174_7212e97b76d1,
                                         test_ts::get_cpp_pairs_t<any_tg, of_any_tg, just_non_qualified_tg, of_any_non_const_tg>);

                TEST_CASE_TEMPLATE_DEFINE("rvalue",
                                          pair_p, _6f2104e7_030c_44fe_9224_7003d0a40c20)
                {
                    using errors_t = typename pair_p::template at_t<nkr::constant::positive::index_t<0>>::head_t;
                    using other_t = typename pair_p::template at_t<nkr::constant::positive::index_t<1>>::head_t;
                    using integer_t = typename errors_t::integer_t;

                    integer_t backup = nkr::randomness::Value<integer_t>();
                    other_t other = backup;
                    errors_t errors = nkr::cpp::Move(other);

                    CHECK((errors == backup));
                }
                TEST_CASE_TEMPLATE_APPLY(_6f2104e7_030c_44fe_9224_7003d0a40c20,
                                         test_ts::get_cpp_pairs_t<any_tg, of_any_tg, any_non_const_tg, of_any_non_const_tg>);
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
    }

}
