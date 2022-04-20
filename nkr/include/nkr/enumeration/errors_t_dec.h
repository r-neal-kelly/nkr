/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_69f678da_34c5_4a38_9e05_2c62fd94b8de
#define nkr_INCLUDE_GUARD_69f678da_34c5_4a38_9e05_2c62fd94b8de

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/enumeration/cpp_t_dec.h"
#include "nkr/enumeration/types_t_dec.h"
#include "nkr/generic/implementing/interface/enumeration/types_tr_dec.h"
#include "nkr/interface/enumeration/types_i_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/reference/lvalue_t_dec.h"
#include "nkr/reference/rvalue_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace enumeration {

    namespace errors_t$ {};

}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    class common_t;

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    class generic_sp;

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    class specialization_tmpl
    {
    public:
        using type_t    = generic_sp<type_p, none_p>;
    };

}}}

namespace nkr { namespace enumeration {

    template <
        nkr::generic::implementing::interface::enumeration::types_tr type_p,
        nkr::constant_of_tr<typename nkr::interface::enumeration::types_i<type_p>::integer_t> none_p = nkr::constant_t<
            typename nkr::interface::enumeration::types_i<type_p>::integer_t,
            nkr::interface::enumeration::types_i<type_p>::Default_Integer()
        >
    > using errors_t =
        typename nkr::enumeration::errors_t$::specialization_tmpl<type_p, none_p>::type_t;

    template <typename type_p>
    concept errors_tr =
        nkr::cpp::is_any_tr<type_p, errors_t<typename type_p::type_t, typename type_p::none_t>>;

    template <template <typename ...> typename template_p>
    concept errors_ttr =
        nkr::cpp::is_any_ttr<template_p, errors_t, nkr::positive::integer_t>;

    class errors_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

    template <typename ...>
    class errors_ttg
    {
    public:
        class   tag_lb      {};
        class   template_lb {};
        class   identity_lb {};
    };

}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::enumeration::errors_tr type_p>
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

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_tg> type_p>
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

    template <nkr::enumeration::errors_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::enumeration::errors_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_t<
            nkr::enumeration::errors_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<2>,
            nkr::enumeration::errors_tg,
            nkr::enumeration::errors_ttg
        >
    {
    public:
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::enumeration::errors_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::enumeration::errors_t>
        >
    {
    public:
    };

}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::enumeration::errors_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::enumeration::errors_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::enumeration::errors_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    class generic_sp
    {
    public:
        using type_t        = type_p;
        using none_t        = none_p;

        using interface_t   = nkr::interface::enumeration::types_i<type_t>;
        using integer_t     = typename interface_t::integer_t;
        using value_t       = typename interface_t::value_t;

        using types_t       = nkr::enumeration::types_t<type_t, none_t>;

    public:
        friend  nkr::enumeration::errors_t$::common_t;

    public:
        types_t                     types;
    #if defined(nkr_IS_DEBUG)
        mutable nkr::boolean::cpp_t has_been_read;
    #endif

    public:
        constexpr generic_sp() noexcept;

        constexpr generic_sp(tr<any_tg, t<nkr::enumeration::cpp_tg>> auto enumeration) noexcept;

        constexpr generic_sp(const generic_sp& other) noexcept;
                  generic_sp(const volatile generic_sp& other) noexcept;
        constexpr generic_sp(generic_sp&& other) noexcept;
                  generic_sp(volatile generic_sp&& other) noexcept;

        constexpr generic_sp&           operator =(tr<any_tg, t<nkr::enumeration::cpp_tg>> auto enumeration) noexcept;
                  volatile generic_sp&  operator =(tr<any_tg, t<nkr::enumeration::cpp_tg>> auto enumeration) volatile noexcept;

        constexpr generic_sp&           operator =(const generic_sp& other) noexcept;
                  volatile generic_sp&  operator =(const generic_sp& other) volatile noexcept;
                  generic_sp&           operator =(const volatile generic_sp& other) noexcept;
                  volatile generic_sp&  operator =(const volatile generic_sp& other) volatile noexcept;
        constexpr generic_sp&           operator =(generic_sp&& other) noexcept;
                  volatile generic_sp&  operator =(generic_sp&& other) volatile noexcept;
                  generic_sp&           operator =(volatile generic_sp&& other) noexcept;
                  volatile generic_sp&  operator =(volatile generic_sp&& other) volatile noexcept;

    #if defined(nkr_IS_DEBUG)
        constexpr ~generic_sp() noexcept;
    #endif

    public:
        constexpr nkr::boolean::cpp_t       Boolean() const noexcept;
                  nkr::boolean::cpp_t       Boolean() const volatile noexcept;

        constexpr integer_t                 Integer() const noexcept;
                  integer_t                 Integer() const volatile noexcept;
        constexpr generic_sp&               Integer(tr<any_to_tg, t<integer_t>> auto& from) noexcept;
                  volatile generic_sp&      Integer(tr<any_to_tg, t<integer_t>> auto& from) volatile noexcept;
        constexpr generic_sp&               Integer(tr<any_non_const_to_tg, t<integer_t>> auto&& from) noexcept;
                  volatile generic_sp&      Integer(tr<any_non_const_to_tg, t<integer_t>> auto&& from) volatile noexcept;

        constexpr value_t&                  Value() noexcept;
        constexpr const value_t&            Value() const noexcept;
                  volatile value_t&         Value() volatile noexcept;
                  const volatile value_t&   Value() const volatile noexcept;
        constexpr generic_sp&               Value(tr<any_to_tg, t<value_t>> auto& from) noexcept;
                  volatile generic_sp&      Value(tr<any_to_tg, t<value_t>> auto& from) volatile noexcept;
        constexpr generic_sp&               Value(tr<any_non_const_to_tg, t<value_t>> auto&& from) noexcept;
                  volatile generic_sp&      Value(tr<any_non_const_to_tg, t<value_t>> auto&& from) volatile noexcept;

        constexpr nkr::boolean::cpp_t       Is_Armed() const noexcept;
                  nkr::boolean::cpp_t       Is_Armed() const volatile noexcept;
        constexpr nkr::none::type_t         Arm() const noexcept;
                  nkr::none::type_t         Arm() const volatile noexcept;
        constexpr nkr::none::type_t         Disarm() const noexcept;
                  nkr::none::type_t         Disarm() const volatile noexcept;

    public:
        explicit constexpr operator nkr::boolean::cpp_t() const noexcept;
        explicit           operator nkr::boolean::cpp_t() const volatile noexcept;

        constexpr operator          generic_sp<type_p, none_p>::integer_t() const noexcept;
                  operator          generic_sp<type_p, none_p>::integer_t() const volatile noexcept;

    public:
        constexpr integer_t operator ()() const noexcept;
                  integer_t operator ()() const volatile noexcept;
    };

}}}

constexpr nkr::boolean::cpp_t   operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto&& b) noexcept;

constexpr nkr::boolean::cpp_t   operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto&& b) noexcept;

#include "nkr/enumeration/errors_t_dec_def.h"

#endif
