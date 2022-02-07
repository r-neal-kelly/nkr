/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/any_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/unlimited_tr_dec.h"
#include "nkr/generic/implementing/tag/data/none_tr_dec.h"
#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/positive_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tr_dec.h"

// may want to pull in nkr/positive/integer_t and nkr/negatable/integer_t for the sake of their interfaces.

namespace nkr { namespace enumeration {

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::enumeration_tr<type_p>;

}}

namespace nkr { namespace enumeration {

    template <nkr::generic::built_in::number::enumeration::any_tr enumeration_p>
    class cpp_value_tmpl;

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 1 && enumeration_p(~0) > 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_8_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 1 && enumeration_p(~0) < 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_8_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 2 && enumeration_p(~0) > 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_16_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 2 && enumeration_p(~0) < 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_16_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 4 && enumeration_p(~0) > 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_32_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 4 && enumeration_p(~0) < 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_32_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 8 && enumeration_p(~0) > 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_64_t;
    };

    template <nkr::cpp::c_enumeration_tr enumeration_p>
        requires (sizeof(enumeration_p(0)) == 8 && enumeration_p(~0) < 0)
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_64_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::unlimited_tr<enumeration_p> && sizeof(enumeration_p(0)) == sizeof(nkr::negatable::integer_8_t))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_8_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::unlimited_tr<enumeration_p> && sizeof(enumeration_p(0)) == sizeof(nkr::negatable::integer_16_t))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_16_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::unlimited_tr<enumeration_p> && sizeof(enumeration_p(0)) == sizeof(nkr::negatable::integer_32_t))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_32_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::unlimited_tr<enumeration_p> && sizeof(enumeration_p(0)) == sizeof(nkr::negatable::integer_64_t))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_64_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::positive::integer_8_t) && nkr::positive::integer_8_t(enumeration_p::MIN_tg) < nkr::positive::integer_8_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_8_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::positive::integer_16_t) && nkr::positive::integer_16_t(enumeration_p::MIN_tg) < nkr::positive::integer_16_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_16_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::positive::integer_32_t) && nkr::positive::integer_32_t(enumeration_p::MIN_tg) < nkr::positive::integer_32_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_32_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::positive::integer_64_t) && nkr::positive::integer_64_t(enumeration_p::MIN_tg) < nkr::positive::integer_64_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::positive::integer_64_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::negatable::integer_8_t) && nkr::positive::integer_8_t(enumeration_p::MIN_tg) >= nkr::positive::integer_8_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_8_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::negatable::integer_16_t) && nkr::positive::integer_16_t(enumeration_p::MIN_tg) >= nkr::positive::integer_16_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_16_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::negatable::integer_32_t) && nkr::positive::integer_32_t(enumeration_p::MIN_tg) >= nkr::positive::integer_32_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_32_t;
    };

    template <nkr::cpp::cpp_enumeration_tr enumeration_p>
        requires (nkr::generic::built_in::number::enumeration::limited_tr<enumeration_p> && sizeof(enumeration_p) == sizeof(nkr::negatable::integer_64_t) && nkr::positive::integer_64_t(enumeration_p::MIN_tg) >= nkr::positive::integer_64_t(enumeration_p::MAX_tg))
    class cpp_value_tmpl<enumeration_p>
    {
    public:
        using type_t    = nkr::negatable::integer_64_t;
    };

    template <nkr::generic::built_in::number::enumeration::any_tr enumeration_p>
    using cpp_value_t   = cpp_value_tmpl<enumeration_p>::type_t;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::enumeration::cpp_tg>
    {
    public:
        using type_t    = nkr::enumeration::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::enumeration::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::enumeration::cpp_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::enumeration::cpp_value_t<type_t>;
    };

}}

namespace nkr { namespace enumeration { namespace $cpp_t {

    template <nkr::enumeration::cpp_tr type_p>
    class none_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        static constexpr value_t    Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::enumeration::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::$cpp_t::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace enumeration { namespace $cpp_t {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class randomness_distributor_uniform_i_sp
    {
    public:
        using type_t    = type_p;
        using number_t  = nkr::enumeration::cpp_value_t<type_t>;

    public:
        static constexpr type_t     Default_Min() noexcept;
        static constexpr type_t     Default_Max() noexcept;

        static constexpr number_t   To_Number(type_t object) noexcept;
        static constexpr type_t     From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr randomness_distributor_uniform_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::$cpp_t::randomness_distributor_uniform_i_sp<type_p>;
    };

}}}}

namespace nkr { namespace enumeration { namespace $cpp_t {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = value_t::MIN_tg, value_t max = value_t::MAX_tg) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = value_t::MIN_tg, value_t max = value_t::MAX_tg) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::$cpp_t::randomness_value_i_sp<type_p>;
    };

}}}

#include "nkr/enumeration/cpp_t_dec_def.h"
