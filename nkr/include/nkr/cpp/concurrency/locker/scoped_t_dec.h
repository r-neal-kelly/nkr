/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_65451a8d_b8b8_41d6_89fb_4a665d73dbed
#define nkr_INCLUDE_GUARD_65451a8d_b8b8_41d6_89fb_4a665d73dbed

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec.h"
#include "nkr/cpp/generic/concurrency/lock_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace scoped_t$ {

    template <typename type_p>
    class is_tmpl :
        public std::false_type
    {
    public:
    };

    template <nkr::cpp::generic::concurrency::lock_tr ...locks_p>
    class is_tmpl<std::scoped_lock<locks_p...>> :
        public std::true_type
    {
    public:
    };

    template <typename type_p>
    class inner_tmpl
    {
    public:
        using type_t    = nkr::none::type_t;
    };

    template <nkr::cpp::generic::concurrency::lock_tr lock_p>
    class inner_tmpl<std::scoped_lock<lock_p>>
    {
    public:
        using type_t    = lock_p;
    };

    template <typename type_p>
    using inner_t   = typename inner_tmpl<type_p>::type_t;

}}}}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker {

    template <nkr::cpp::generic::concurrency::lock_tr ...locks_p>
    using   scoped_t =
        std::scoped_lock<locks_p...>;

    struct  scoped_tg   { class tag_lb; };

    template <typename ...>
    struct  scoped_ttg  {};

    template <typename type_p>
    concept scoped_tr =
        scoped_t$::is_tmpl<nkr::cpp::just_non_qualified_t<type_p>>::value;

    template <template <typename ...> typename template_p>
    concept scoped_ttr =
        nkr::cpp::is_any_ttr<template_p, scoped_t, nkr::cpp::concurrency::lock::perpetual::unary_t>;

}}}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace scoped_t$ {

    template <nkr::cpp::concurrency::locker::scoped_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::cpp::concurrency::locker::scoped_t$::inner_t<type_t>;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::scoped_tg> type_p>
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

    template <nkr::cpp::concurrency::locker::scoped_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::scoped_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::locker::scoped_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::scoped_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace concurrency { namespace locker { namespace scoped_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::concurrency::locker::scoped_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::cpp::concurrency::locker::scoped_t,
            nkr::tuple::types_t<nkr::cpp::concurrency::lock::perpetual::unary_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<~nkr::positive::count_t(0)>,
            nkr::cpp::concurrency::locker::scoped_tg,
            nkr::cpp::concurrency::locker::scoped_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::concurrency::locker::scoped_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::cpp::concurrency::locker::scoped_t>
        >
    {
    public:
    };

}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::concurrency::locker::scoped_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::scoped_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::concurrency::locker::scoped_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::locker::scoped_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/concurrency/locker/scoped_t_dec_def.h"

#endif
