/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_015e4206_27b6_4543_b086_94ddc8e6325a
#define nkr_INCLUDE_GUARD_015e4206_27b6_4543_b086_94ddc8e6325a

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/built_in/boolean_tr_dec.h"
#include "nkr/generic/built_in/number/integer_tr_dec.h"
#include "nkr/generic/built_in/number/real_tr_dec.h"
#include "nkr/generic/built_in/pointer_tr_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
#include "nkr/generic/implementing/self_tr_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace uniform_i$ {

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
        (requires(typename type_p::value_t value,
                  const typename type_p::value_t const_value,
                  volatile typename type_p::value_t volatile_value,
                  const volatile typename type_p::value_t const_volatile_value,

                  typename type_p::number_t number)
    {
        { type_p::Default_Min() }                   -> nkr::cpp::is_tr<typename type_p::value_t>;
        { type_p::Default_Max() }                   -> nkr::cpp::is_tr<typename type_p::value_t>;

        { type_p::To_Number(const_value) }          -> nkr::cpp::is_tr<typename type_p::number_t>;
        { type_p::To_Number(const_volatile_value) } -> nkr::cpp::is_tr<typename type_p::number_t>;

        { type_p::From_Number(number) }             -> nkr::cpp::is_tr<typename type_p::value_t>;
    });

    template <typename type_p>
    concept objects_i =
        !nkr::generic::implementing::constructor::default_tr<type_p>;

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace uniform_i$ {

    using example_t =
        nkr::positive::integer_t;

    template <nkr::cpp::is_any_tr<example_t> type_p>
    class example_uniform_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using number_t  = value_t;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;

        static constexpr number_t   To_Number(value_t value) noexcept;
        static constexpr value_t    From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr example_uniform_i_sp(...) noexcept    = delete;
    };

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <nkr::cpp::is_any_tr<uniform_i$::example_t> type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = uniform_i$::example_uniform_i_sp<type_p>;
    };

}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    struct  uniform_tg  { class tag_lb; };

    template <typename ...>
    struct  uniform_ttg {};

    template <typename type_p>
    concept uniform_tr =
        nkr::cpp::is_any_tr<type_p, uniform_i<typename type_p::type_t>> &&
        uniform_i$::aliases_i<type_p> &&
        uniform_i$::static_functions_i<type_p> &&
        uniform_i$::objects_i<type_p>;

    template <template <typename ...> typename template_p>
    concept uniform_ttr =
        nkr::cpp::is_any_ttr<template_p, uniform_i, uniform_i$::example_t>;

}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace uniform_i$ {

    template <nkr::interface::randomness::distributor::uniform_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::distributor::uniform_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}}}

namespace nkr { namespace interface {

    template <nkr::interface::randomness::distributor::uniform_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::randomness::distributor::uniform_i$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::interface::randomness::distributor::uniform_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::interface::randomness::distributor::uniform_i$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace uniform_i$ {

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::distributor::uniform_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::interface::randomness::distributor::uniform_i,
            nkr::tuple::types_t<nkr::interface::randomness::distributor::uniform_i$::example_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::interface::randomness::distributor::uniform_tg,
            nkr::interface::randomness::distributor::uniform_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::randomness::distributor::uniform_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::interface::randomness::distributor::uniform_i>
        >
    {
    public:
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::interface::randomness::distributor::uniform_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::randomness::distributor::uniform_i$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::interface::randomness::distributor::uniform_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::interface::randomness::distributor::uniform_i$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/interface/randomness/distributor/uniform_i_dec_def.h"

#endif
