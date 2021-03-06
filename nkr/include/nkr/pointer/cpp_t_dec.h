/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_f5f7ce4b_557c_46fa_8835_12d2a2f8f7fa
#define nkr_INCLUDE_GUARD_f5f7ce4b_557c_46fa_8835_12d2a2f8f7fa

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"
#include "nkr/tr_dec.h"

namespace nkr { namespace pointer {

    template <typename type_p>
    using   cpp_t =
        type_p*;

    struct  cpp_tg  { class tag_lb; };

    template <typename ...>
    struct  cpp_ttg {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::pointer_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept cpp_ttr =
        nkr::cpp::is_any_ttr<template_p, cpp_t, nkr::none::type_t>;

}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::pointer_unit_t<type_t>;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::pointer::cpp_tg> type_p>
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

}}}

namespace nkr { namespace interface {

    template <nkr::pointer::cpp_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::pointer::cpp_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::pointer::cpp_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::pointer::cpp_t,
            nkr::tuple::types_t<nkr::none::type_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
            nkr::pointer::cpp_tg,
            nkr::pointer::cpp_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::pointer::cpp_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::pointer::cpp_t>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::pointer::cpp_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::pointer::cpp_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
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

    template <nkr::pointer::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
    class randomness_distributor_uniform_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;
        using number_t  = nkr::positive::integer_t;

    public:
        static constexpr value_t    Default_Min() noexcept;
        static constexpr value_t    Default_Max() noexcept;

        static constexpr number_t   To_Number(value_t value) noexcept;
        static constexpr value_t    From_Number(number_t number) noexcept;

    public:
        template <typename ...>
        constexpr randomness_distributor_uniform_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor {

    template <nkr::pointer::cpp_tr type_p>
    class uniform_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::randomness_distributor_uniform_i_sp<type_p>;
    };

}}}}

namespace nkr { namespace pointer { namespace cpp_t$ {

    template <nkr::pointer::cpp_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min = nkr::cpp::Default_Min<value_t>(), value_t max = nkr::cpp::Default_Max<value_t>()) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::pointer::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::pointer::cpp_t$::randomness_value_i_sp<type_p>;
    };

}}}

#include "nkr/pointer/cpp_t_dec_def.h"

#endif
