/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/built_in/boolean_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/built_in/pointer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <typename type_p>
    concept aliases_i =
        nkr::generic::type_tr<typename type_p::type_t> &&

        nkr::cpp::is_tr<typename type_p::value_t, nkr::cpp::just_non_qualified_t<typename type_p::type_t>> &&
        nkr::generic::implementing::self_tr<typename type_p::value_t> &&

        nkr::cpp::just_non_qualified_tr<typename type_p::number_t> &&
        (nkr::generic::built_in::number::integer_tr<typename type_p::number_t> ||
         nkr::generic::built_in::number::real_tr<typename type_p::number_t>);

    template <typename type_p>
    concept static_functions_i =
        (requires(typename type_p::value_t object,
                  const typename type_p::value_t const_object,
                  volatile typename type_p::value_t volatile_object,
                  const volatile typename type_p::value_t const_volatile_object,

                  typename type_p::number_t number)
    {
        { type_p::Default_Min() }                       -> nkr::cpp::is_tr<typename type_p::value_t>;
        { type_p::Default_Max() }                       -> nkr::cpp::is_tr<typename type_p::value_t>;

        { type_p::To_Number(const_object) }             -> nkr::cpp::is_tr<typename type_p::number_t>;
        { type_p::To_Number(const_volatile_object) }    -> nkr::cpp::is_tr<typename type_p::number_t>;

        { type_p::From_Number(number) }                 -> nkr::cpp::is_tr<typename type_p::value_t>;
    });

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

    class   dummy_t;

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <typename type_p>
    using   uniform_i =
        uniform_i_sp<type_p>::type_t;

    struct  uniform_tg  {};

    template <typename>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        (nkr::cpp::is_any_tr<type_p, uniform_i<typename type_p::type_t>> &&
         $uniform_i::aliases_i<type_p> &&
         $uniform_i::static_functions_i<type_p> &&
         $uniform_i::objects_i<type_p>) ||
        nkr::cpp::is_any_tr<type_p, $uniform_i::dummy_t>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        nkr::cpp::is_any_ttr<template_p, uniform_i, $uniform_i::dummy_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = nkr::interface::randomness::distributor::uniform_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::randomness::distributor::uniform_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::randomness::distributor::uniform_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::type_t;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::interface::randomness::distributor::uniform_ttg>
    {
    public:
        template <typename type_p>
        using template_t    = nkr::interface::randomness::distributor::uniform_i<type_p>;

        template <typename inner_p>
        using of_t          = template_t<inner_p>;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t    = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using of_pack_t     = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using example_t     = nkr::interface::randomness::distributor::$uniform_i::dummy_t;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::distributor::uniform_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::interface::randomness::distributor::uniform_ttg>
    {
    public:
    };

}}

#include "nkr/interface/randomness/distributor/uniform_i_dec_def.h"
