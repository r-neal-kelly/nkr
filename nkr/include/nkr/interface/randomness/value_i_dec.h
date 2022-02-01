/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/generic/built_in/boolean_tr_dec.h"
#include "nkr/generic/built_in/number/enumeration/limited_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/built_in/pointer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/negatable/real_t_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/randomness/generator/software/default_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <typename type_p>
    concept aliases_i =
        nkr::cpp::just_non_qualified_tr<typename type_p::value_t> &&
        nkr::generic::type_tr<typename type_p::value_t>;

    template <typename type_p>
    concept static_functions_i =
        (requires(nkr::randomness::generator::software::default_t generator)
    {
        { type_p::template Value<>() }          -> nkr::cpp::is_tr<typename type_p::value_t>;
        { type_p::template Value<>(generator) } -> nkr::cpp::is_tr<typename type_p::value_t>;
    });

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

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

}}}}

namespace nkr { namespace interface { namespace randomness {

    template <typename value_p>
    class value_i_sp;

    template <nkr::generic::built_in::boolean_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = $value_i::boolean_sp<value_p>;
    };

    template <nkr::generic::built_in::number::enumeration::limited_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = $value_i::enumeration_limited_sp<value_p>;
    };

    template <nkr::generic::built_in::number::integer_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = $value_i::integer_sp<value_p>;
    };

    template <nkr::generic::built_in::number::real_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = $value_i::real_sp<value_p>;
    };

    template <nkr::generic::built_in::pointer_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = $value_i::pointer_sp<value_p>;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <typename value_p>
    using   value_i =
        value_i_sp<value_p>::type_t;

    struct  value_tg    {};

    template <typename>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        nkr::cpp::is_any_tr<type_p, value_i<typename type_p::value_t>> &&
        $value_i::aliases_i<type_p> &&
        $value_i::static_functions_i<type_p> &&
        $value_i::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept value_ttr =
        nkr::cpp::is_any_ttr<template_p, value_i, nkr::positive::integer_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::randomness::value_tg>
    {
    public:
        using type_t    = nkr::interface::randomness::value_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::randomness::value_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::randomness::value_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::randomness::value_ttg>
    {
    public:
        template <typename value_p>
        using template_t    = nkr::interface::randomness::value_i<value_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::value_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::randomness::value_ttg>
    {
    public:
    };

}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::boolean_tr value_p>
    class boolean_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(nkr::negatable::real_t probability_for_true = 0.5) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              nkr::negatable::real_t probability_for_true = 0.5) noexcept;

        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min, value_t max) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min, value_t max) noexcept;

    public:
        template <typename ...>
        constexpr boolean_sp(...) noexcept  = delete;
    };

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::number::enumeration::limited_tr value_p>
    class enumeration_limited_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = value_t::MIN_tg, value_t max = value_t::MAX_tg) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = value_t::MIN_tg, value_t max = value_t::MAX_tg) noexcept;

    public:
        template <typename ...>
        constexpr enumeration_limited_sp(...) noexcept  = delete;
    };

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::number::integer_tr value_p>
    class integer_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr integer_sp(...) noexcept  = delete;
    };

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::number::real_tr value_p>
    class real_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr real_sp(...) noexcept = delete;
    };

}}}}

namespace nkr { namespace interface { namespace randomness { namespace $value_i {

    template <nkr::generic::built_in::pointer_tr value_p>
    class pointer_sp
    {
    public:
        using value_t   = value_p;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr pointer_sp(...) noexcept  = delete;
    };

}}}}

#include "nkr/interface/randomness/value_i_dec_def.h"
