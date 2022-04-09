/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_25e0eb68_8673_45db_b0e9_d090604e2b29
#define nkr_INCLUDE_GUARD_25e0eb68_8673_45db_b0e9_d090604e2b29

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/template_i_identity_tag_t_dec.h"
#include "nkr/interface/template_i_identity_template_t_dec.h"
#include "nkr/tr_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace array { namespace local {

    namespace static_t$ {};

}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    class common_t;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (capacity_p::Value() < 1)
    class empty_sp;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg> && capacity_p::Value() > 0)
    class non_const_sp;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_const_tg> && capacity_p::Value() > 0)
    class const_sp;

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class specialization_tmpl;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (capacity_p::Value() < 1)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = empty_sp<unit_p, capacity_p>;
    };

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = non_const_sp<unit_p, capacity_p>;
    };

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_const_tg>&& capacity_p::Value() > 0)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = const_sp<unit_p, capacity_p>;
    };

}}}}

namespace nkr { namespace array { namespace local {

    template <nkr::generic::type_tr unit_p, nkr::constant::positive::count_tr capacity_p>
    using static_t =
        typename nkr::array::local::static_t$::specialization_tmpl<unit_p, capacity_p>::type_t;

    template <typename type_p>
    concept static_tr =
        nkr::cpp::is_any_tr<type_p, static_t<typename type_p::unit_t, typename type_p::capacity_t>>;

    template <template <typename ...> typename template_p>
    concept static_ttr =
        nkr::cpp::is_any_ttr<template_p, static_t, nkr::positive::integer_t, nkr::constant::positive::count_t<1>>;

    class static_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

    template <typename ...>
    class static_ttg
    {
    public:
        class   tag_lb      {};
        class   template_lb {};
        class   identity_lb {};
    };

}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::array::local::static_tr type_p>
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

    template <nkr::cpp::is_any_tr<nkr::array::local::static_tg> type_p>
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

}}}}

namespace nkr { namespace interface {

    template <nkr::array::local::static_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::local::static_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::array::local::static_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::local::static_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::array::local::static_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_basic_t<
            nkr::array::local::static_t,
            nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
            nkr::constant::positive::count_t<2>,
            nkr::constant::positive::count_t<2>,
            nkr::array::local::static_tg,
            nkr::array::local::static_ttg
        >
    {
    public:
        template <typename inner_p>
        using of_t          = template_t<inner_p, nkr::constant::positive::count_t<1>>;

        template <typename inner_p>
        using actual_of_t   = of_t<inner_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::local::static_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::array::local::static_t>
        >
    {
    public:
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::array::local::static_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::local::static_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::local::static_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::local::static_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (capacity_p::Value() < 1)
    class empty_sp
    {
    public:
        using unit_t        = unit_p;
        using capacity_t    = capacity_p;
    };

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg> && capacity_p::Value() > 0)
    class non_const_sp
    {
    public:
        using unit_t        = unit_p;
        using capacity_t    = capacity_p;
        using units_t       = unit_t[capacity_t::Value()];

    public:
        friend  nkr::array::local::static_t$::common_t;

    protected:
        units_t units;

    public:
        constexpr non_const_sp() noexcept                                                                       = delete;
        constexpr non_const_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr non_const_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr non_const_sp(const non_const_sp& other) noexcept;
                  non_const_sp(const volatile non_const_sp& other) noexcept;
        constexpr non_const_sp(non_const_sp&& other) noexcept;
                  non_const_sp(volatile non_const_sp&& other) noexcept;

        constexpr non_const_sp&             operator =(const non_const_sp& other) noexcept;
                  volatile non_const_sp&    operator =(const non_const_sp& other) volatile noexcept;
                  non_const_sp&             operator =(const volatile non_const_sp& other) noexcept;
                  volatile non_const_sp&    operator =(const volatile non_const_sp& other) volatile noexcept;
        constexpr non_const_sp&             operator =(non_const_sp&& other) noexcept;
                  volatile non_const_sp&    operator =(non_const_sp&& other) volatile noexcept;
                  non_const_sp&             operator =(volatile non_const_sp&& other) noexcept;
                  volatile non_const_sp&    operator =(volatile non_const_sp&& other) volatile noexcept;

    public:
        constexpr units_t&                  Units() noexcept;
        constexpr const units_t&            Units() const noexcept;
                  volatile units_t&         Units() volatile noexcept;
                  const volatile units_t&   Units() const volatile noexcept;

        constexpr nkr::positive::count_t    Count() const noexcept;
                  nkr::positive::count_t    Count() const volatile noexcept;
        constexpr nkr::positive::count_t    Capacity() const noexcept;
                  nkr::positive::count_t    Capacity() const volatile noexcept;
    };

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_const_tg>&& capacity_p::Value() > 0)
    class const_sp
    {
    public:
        using unit_t        = unit_p;
        using capacity_t    = capacity_p;
        using units_t       = unit_t[capacity_t::Value()];

    protected:
        units_t units;

    public:
        constexpr const_sp() noexcept                                                                   = delete;
        constexpr const_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr const_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr const_sp(const const_sp& other) noexcept;
                  const_sp(const volatile const_sp& other) noexcept;
        constexpr const_sp(const_sp&& other) noexcept;
                  const_sp(volatile const_sp&& other) noexcept;

        constexpr const_sp&             operator =(const const_sp& other) noexcept                      = delete;
                  volatile const_sp&    operator =(const const_sp& other) volatile noexcept             = delete;
                  const_sp&             operator =(const volatile const_sp& other) noexcept             = delete;
                  volatile const_sp&    operator =(const volatile const_sp& other) volatile noexcept    = delete;
        constexpr const_sp&             operator =(const_sp&& other) noexcept                           = delete;
                  volatile const_sp&    operator =(const_sp&& other) volatile noexcept                  = delete;
                  const_sp&             operator =(volatile const_sp&& other) noexcept                  = delete;
                  volatile const_sp&    operator =(volatile const_sp&& other) volatile noexcept         = delete;

    public:
        constexpr nkr::positive::count_t    Count() const noexcept;
                  nkr::positive::count_t    Count() const volatile noexcept;
        constexpr nkr::positive::count_t    Capacity() const noexcept;
                  nkr::positive::count_t    Capacity() const volatile noexcept;
    };

}}}}

#include "nkr/array/local/static_t_dec_def.h"

#endif
