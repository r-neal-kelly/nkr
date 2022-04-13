/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_69f678da_34c5_4a38_9e05_2c62fd94b8de
#define nkr_INCLUDE_GUARD_69f678da_34c5_4a38_9e05_2c62fd94b8de

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/enumeration/types_t_dec.h"
#include "nkr/generic/implementing/interface/enumeration/types_tr_dec.h"
#include "nkr/interface/enumeration/types_i_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/positive/integer_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace enumeration {

    namespace errors_t$ {};

}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    class common_t;

    template <tr<any_non_const_tg, t<nkr::generic::implementing::interface::enumeration::types_tg>> value_p>
    class types_sp;

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <typename value_p>
    class specialization_tmpl;

    template <typename value_p>
        requires (tr<value_p, any_non_const_tg, t<nkr::generic::implementing::interface::enumeration::types_tg>>)
    class specialization_tmpl<value_p>
    {
    public:
        using type_t    = types_sp<value_p>;
    };

}}}

namespace nkr { namespace enumeration {

    template <typename value_p>
    using errors_t =
        typename nkr::enumeration::errors_t$::specialization_tmpl<value_p>::type_t;

    template <typename type_p>
    concept errors_tr =
        nkr::cpp::is_any_tr<type_p, errors_t<typename type_p::value_t>>;

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
        using of_t      = typename type_t::unit_t;

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
        public nkr::interface::template_i_identity_template_t <
            nkr::enumeration::errors_t,
            nkr::tuple::types_t<nkr::positive::integer_t>,
            nkr::constant::positive::count_t<1>,
            nkr::constant::positive::count_t<1>,
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

    template <tr<any_non_const_tg, t<nkr::generic::implementing::interface::enumeration::types_tg>> value_p>
    class types_sp
    {
    public:
        using type_t        = value_p;

        using interface_t   = nkr::interface::enumeration::types_i<value_p>;
        using integer_t     = typename interface_t::integer_t;
        using value_t       = typename interface_t::value_t;

        using types_t       = nkr::enumeration::types_t<type_t, nkr::constant_t<integer_t, integer_t(0)>>;

    public:
        types_t                     types;
    #if defined(nkr_IS_DEBUG)
        mutable nkr::boolean::cpp_t has_been_checked;
    #endif

    public:
        constexpr types_sp() noexcept;

        constexpr types_sp(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;
        constexpr types_sp(tr<to_tg, t<integer_t>> auto&& to_integer) noexcept;

        constexpr types_sp(const value_t& value) noexcept;
                  types_sp(const volatile value_t& value) noexcept;
        constexpr types_sp(value_t&& value) noexcept;
                  types_sp(volatile value_t&& value) noexcept;

        constexpr types_sp(const types_sp& other) noexcept;
                  types_sp(const volatile types_sp& other) noexcept;
        constexpr types_sp(types_sp&& other) noexcept;
                  types_sp(volatile types_sp&& other) noexcept;

        constexpr types_sp&             operator =(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;
                  volatile types_sp&    operator =(const tr<to_tg, t<integer_t>> auto& to_integer) volatile noexcept;
        constexpr types_sp&             operator =(tr<to_tg, t<integer_t>> auto&& to_integer) noexcept;
                  volatile types_sp&    operator =(tr<to_tg, t<integer_t>> auto&& to_integer) volatile noexcept;

        constexpr types_sp&             operator =(const value_t& value) noexcept;
                  volatile types_sp&    operator =(const value_t& value) volatile noexcept;
                  types_sp&             operator =(const volatile value_t& value) noexcept;
                  volatile types_sp&    operator =(const volatile value_t& value) volatile noexcept;
        constexpr types_sp&             operator =(value_t&& value) noexcept;
                  volatile types_sp&    operator =(value_t&& value) volatile noexcept;
                  types_sp&             operator =(tr<just_volatile_tg, t<value_t>> auto&& value) noexcept;
                  volatile types_sp&    operator =(tr<just_volatile_tg, t<value_t>> auto&& value) volatile noexcept;

        constexpr types_sp&             operator =(const types_sp& other) noexcept;
                  volatile types_sp&    operator =(const types_sp& other) volatile noexcept;
                  types_sp&             operator =(const volatile types_sp& other) noexcept;
                  volatile types_sp&    operator =(const volatile types_sp& other) volatile noexcept;
        constexpr types_sp&             operator =(types_sp&& other) noexcept;
                  volatile types_sp&    operator =(types_sp&& other) volatile noexcept;
                  types_sp&             operator =(tr<just_volatile_tg, t<types_sp>> auto&& other) noexcept;
                  volatile types_sp&    operator =(tr<just_volatile_tg, t<types_sp>> auto&& other) volatile noexcept;

    #if defined(nkr_IS_DEBUG)
        constexpr ~types_sp() noexcept;
    #endif

    public:
        constexpr integer_t                 Integer() const noexcept;
                  integer_t                 Integer() const volatile noexcept;
        constexpr types_sp&                 Integer(const tr<to_tg, t<integer_t>> auto& to_integer) noexcept;
                  volatile types_sp&        Integer(const tr<to_tg, t<integer_t>> auto& to_integer) volatile noexcept;
        constexpr types_sp&                 Integer(tr<to_tg, t<integer_t>> auto&& to_integer) noexcept;
                  volatile types_sp&        Integer(tr<to_tg, t<integer_t>> auto&& to_integer) volatile noexcept;

        constexpr value_t&                  Value() noexcept;
        constexpr const value_t&            Value() const noexcept;
                  volatile value_t&         Value() volatile noexcept;
                  const volatile value_t&   Value() const volatile noexcept;
        constexpr types_sp&                 Value(const tr<any_tg, t<value_t>> auto& value) noexcept;
                  volatile types_sp&        Value(const tr<any_tg, t<value_t>> auto& value) volatile noexcept;
        constexpr types_sp&                 Value(tr<any_non_const_tg, t<value_t>> auto&& value) noexcept;
                  volatile types_sp&        Value(tr<any_non_const_tg, t<value_t>> auto&& value) volatile noexcept;

        constexpr nkr::none::type_t         Ignore_Error() const noexcept;
                  nkr::none::type_t         Ignore_Error() const volatile noexcept;

    public:
        constexpr operator          types_sp<value_p>::integer_t() const noexcept;
                  operator          types_sp<value_p>::integer_t() const volatile noexcept;

        explicit constexpr operator nkr::boolean::cpp_t() const noexcept;
        explicit           operator nkr::boolean::cpp_t() const volatile noexcept;
    };

}}}

#include "nkr/enumeration/errors_t_dec_def.h"

#endif
