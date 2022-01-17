/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/generic/built_in/boolean_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/built_in/pointer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/randomness/generator/software/default_t_dec.h"

namespace nkr { namespace interface { namespace $randomness_i {

    template <typename type_p>
    concept aliases_i =
        cpp::just_non_qualified_tr<typename type_p::value_t> &&
        nkr::generic::type_tr<typename type_p::value_t>;

    template <typename type_p>
    concept static_functions_i =
        (requires(nkr::randomness::generator::software::default_t generator)
    {
        { type_p::template Value<>() }          -> cpp::is_tr<typename type_p::value_t>;
        { type_p::template Value<>(generator) } -> cpp::is_tr<typename type_p::value_t>;
    });

    template <typename type_p>
    concept objects_i =
        !generic::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface { namespace $randomness_i {

    template <nkr::generic::built_in::boolean_tr value_p>
    class   boolean_sp;

    template <nkr::generic::built_in::number::enumeration::limited_tr value_p>
    class   enumeration_limited_sp;

    template <nkr::generic::built_in::number::integer_tr value_p>
    class   integer_sp;

    template <nkr::generic::built_in::number::real_tr value_p>
    class   real_sp;

    template <nkr::generic::built_in::pointer_tr value_p>
    class   pointer_sp;

}}}

namespace nkr { namespace interface {

    template <typename value_p>
    class randomness_i_sp;

    template <nkr::generic::built_in::boolean_tr value_p>
    class randomness_i_sp<value_p>
    {
    public:
        using type_t    = $randomness_i::boolean_sp<value_p>;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr value_p>
    class randomness_i_sp<value_p>
    {
    public:
        using type_t    = $randomness_i::enumeration_limited_sp<value_p>;
    };

    template <nkr::generic::built_in::number::integer_tr value_p>
    class randomness_i_sp<value_p>
    {
    public:
        using type_t    = $randomness_i::integer_sp<value_p>;
    };

    template <nkr::generic::built_in::number::real_tr value_p>
    class randomness_i_sp<value_p>
    {
    public:
        using type_t    = $randomness_i::real_sp<value_p>;
    };

    template <nkr::generic::built_in::pointer_tr value_p>
    class randomness_i_sp<value_p>
    {
    public:
        using type_t    = $randomness_i::pointer_sp<value_p>;
    };

}}

namespace nkr { namespace interface {

    template <typename value_p>
    using   randomness_i =
        randomness_i_sp<value_p>::type_t;

    struct  randomness_tg   {};

    template <typename>
    struct  randomness_ttg  {};

    template <typename type_p>
    concept randomness_tr =
        cpp::is_any_tr<type_p, randomness_i<typename type_p::value_t>> &&
        $randomness_i::aliases_i<type_p> &&
        $randomness_i::static_functions_i<type_p> &&
        $randomness_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept randomness_ttr =
        cpp::is_any_ttr<template_p, randomness_i, nkr::positive::integer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::randomness_tg>
    {
    public:
        using type_t    = nkr::interface::randomness_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::randomness_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::randomness_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::randomness_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::interface::randomness_i<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::randomness_ttg>
    {
    public:
    };

}}

namespace nkr { namespace interface { namespace $randomness_i {

    template <nkr::generic::built_in::boolean_tr value_p>
    class boolean_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(nkr::negatable::real_t probability_for_true = 0.5) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                              nkr::negatable::real_t probability_for_true = 0.5) noexcept;

    public:
        template <typename ...>
        constexpr boolean_sp(...) noexcept  = delete;
    };

}}}

namespace nkr { namespace interface { namespace $randomness_i {

    template <nkr::generic::built_in::number::enumeration::limited_tr value_p>
    class enumeration_limited_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = value_t::MIN_tg, value_t max = value_t::MAX_tg) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                              value_t min = value_t::MIN_tg, value_t max = value_t::MAX_tg) noexcept;

    public:
        template <typename ...>
        constexpr enumeration_limited_sp(...) noexcept  = delete;
    };

}}}

namespace nkr { namespace interface { namespace $randomness_i {

    template <nkr::generic::built_in::number::integer_tr value_p>
    class integer_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr integer_sp(...) noexcept  = delete;
    };

}}}

namespace nkr { namespace interface { namespace $randomness_i {

    template <nkr::generic::built_in::number::real_tr value_p>
    class real_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr real_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace $randomness_i {

    template <nkr::generic::built_in::pointer_tr value_p>
    class pointer_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr1<any_non_const_tg, nkr::cpp::generic::randomness::generator_tg> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr pointer_sp(...) noexcept  = delete;
    };

}}}

#include "nkr/interface/randomness_i_dec_def.h"
