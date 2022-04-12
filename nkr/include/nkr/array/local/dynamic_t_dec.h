/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_77d78d93_6414_4569_b47c_0ba6ef0c8f7a
#define nkr_INCLUDE_GUARD_77d78d93_6414_4569_b47c_0ba6ef0c8f7a

#include "nkr/array/cpp_t_dec.h"
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

    namespace dynamic_t$    {};

}}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    class common_t;

    template <nkr::generic::type_tr unit_p, typename unit_capacity_p>
    class empty_sp;

    template <nkr::generic::type_tr unit_p, typename unit_capacity_p>
    class non_empty_sp;

}}}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <nkr::generic::type_tr unit_p, typename unit_capacity_p>
    class specialization_tmpl;

    template <nkr::generic::type_tr unit_p, typename unit_capacity_p>
        requires (unit_capacity_p::Value() < 1)
    class specialization_tmpl<unit_p, unit_capacity_p>
    {
    public:
        using type_t    = empty_sp<unit_p, unit_capacity_p>;
    };

    template <nkr::generic::type_tr unit_p, typename unit_capacity_p>
        requires (unit_capacity_p::Value() > 0)
    class specialization_tmpl<unit_p, unit_capacity_p>
    {
    public:
        using type_t    = non_empty_sp<unit_p, unit_capacity_p>;
    };

}}}}

namespace nkr { namespace array { namespace local {

    template <nkr::generic::type_tr unit_p, nkr::constant::positive::count_tr unit_capacity_p>
    using dynamic_t =
        typename nkr::array::local::dynamic_t$::specialization_tmpl<unit_p, unit_capacity_p>::type_t;

    template <typename type_p>
    concept dynamic_tr =
        nkr::cpp::is_any_tr<type_p, dynamic_t<typename type_p::unit_t, typename type_p::unit_capacity_t>>;

    template <template <typename ...> typename template_p>
    concept dynamic_ttr =
        nkr::cpp::is_any_ttr<template_p, dynamic_t, nkr::positive::integer_t, nkr::constant::positive::count_t<1>>;

    class dynamic_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

    template <typename ...>
    class dynamic_ttg
    {
    public:
        class   tag_lb      {};
        class   template_lb {};
        class   identity_lb {};
    };

}}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <nkr::array::local::dynamic_tr type_p>
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

    template <nkr::cpp::is_any_tr<nkr::array::local::dynamic_tg> type_p>
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

    template <nkr::array::local::dynamic_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::local::dynamic_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::array::local::dynamic_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::array::local::dynamic_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::array::local::dynamic_ttr<template_p>
    class template_i_template_sp :
        public nkr::interface::template_i_identity_template_basic_t<
            nkr::array::local::dynamic_t,
            nkr::tuple::types_t<nkr::positive::integer_t, nkr::constant::positive::count_t<1>>,
            nkr::constant::positive::count_t<2>,
            nkr::constant::positive::count_t<2>,
            nkr::array::local::dynamic_tg,
            nkr::array::local::dynamic_ttg
        >
    {
    public:
        template <typename inner_p>
        using of_t          = template_t<inner_p, nkr::constant::positive::count_t<1>>;

        template <typename inner_p>
        using actual_of_t   = of_t<inner_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::local::dynamic_ttg>
    class template_i_tag_sp :
        public nkr::interface::template_i_identity_tag_t<
            template_i_template_sp<nkr::array::local::dynamic_t>
        >
    {
    public:
    };

}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::array::local::dynamic_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::local::dynamic_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::array::local::dynamic_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::array::local::dynamic_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <nkr::generic::type_tr unit_p, typename unit_capacity_p>
    class non_empty_sp
    {
    public:
        using unit_t                    = unit_p;
        using unit_capacity_t           = nkr::constant::positive::count_t<unit_capacity_p::Value()>;
        using units_t                   = nkr::array::cpp_t<unit_t, unit_capacity_t>;

        using non_const_unit_t          = nkr::cpp::any_non_const_t<unit_t>;
        using non_const_unit_capacity_t = nkr::constant::positive::count_t<unit_capacity_t::Value()>;
        using non_const_units_t         = nkr::array::cpp_t<non_const_unit_t, non_const_unit_capacity_t>;
        
        using byte_t                    = nkr::positive::byte_t;
        using byte_capacity_t           = nkr::constant::positive::count_t<unit_capacity_t::Value() * sizeof(unit_t)>;
        using bytes_t                   = nkr::array::cpp_t<byte_t, byte_capacity_t>;

    public:
        friend  nkr::array::local::dynamic_t$::common_t;

    public:
        static constexpr nkr::positive::count_t Unit_Capacity() noexcept;

    public:
        nkr::positive::count_t  unit_count;
        bytes_t                 bytes;

    public:
        constexpr non_empty_sp() noexcept;

        constexpr non_empty_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr non_empty_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr non_empty_sp(const non_empty_sp& other) noexcept;
                  non_empty_sp(const volatile non_empty_sp& other) noexcept;
        constexpr non_empty_sp(non_empty_sp&& other) noexcept;
                  non_empty_sp(volatile non_empty_sp&& other) noexcept;

        constexpr non_empty_sp&             operator =(const non_empty_sp& other) noexcept;
                  volatile non_empty_sp&    operator =(const non_empty_sp& other) volatile noexcept;
                  non_empty_sp&             operator =(const volatile non_empty_sp& other) noexcept;
                  volatile non_empty_sp&    operator =(const volatile non_empty_sp& other) volatile noexcept;
        constexpr non_empty_sp&             operator =(non_empty_sp&& other) noexcept;
                  volatile non_empty_sp&    operator =(non_empty_sp&& other) volatile noexcept;
                  non_empty_sp&             operator =(volatile non_empty_sp&& other) noexcept;
                  volatile non_empty_sp&    operator =(volatile non_empty_sp&& other) volatile noexcept;

        constexpr ~non_empty_sp() noexcept;

    public:
        constexpr nkr::positive::count_t            Unit_Count() const noexcept;
                  nkr::positive::count_t            Unit_Count() const volatile noexcept;
        constexpr nkr::none::type_t                 Unit_Count(nkr::positive::count_t unit_count) noexcept;
                  nkr::none::type_t                 Unit_Count(nkr::positive::count_t unit_count) volatile noexcept;

        constexpr units_t&                          Units() noexcept;
        constexpr const units_t&                    Units() const noexcept;
                  volatile units_t&                 Units() volatile noexcept;
                  const volatile units_t&           Units() const volatile noexcept;

        constexpr non_const_units_t&                Non_Const_Units() noexcept;
        constexpr const non_const_units_t&          Non_Const_Units() const noexcept;
                  volatile non_const_units_t&       Non_Const_Units() volatile noexcept;
                  const volatile non_const_units_t& Non_Const_Units() const volatile noexcept;

        constexpr unit_t&                           Unit(nkr::positive::index_t unit_index) noexcept;
        constexpr const unit_t&                     Unit(nkr::positive::index_t unit_index) const noexcept;
                  volatile unit_t&                  Unit(nkr::positive::index_t unit_index) volatile noexcept;
                  const volatile unit_t&            Unit(nkr::positive::index_t unit_index) const volatile noexcept;

        constexpr non_const_unit_t&                 Non_Const_Unit(nkr::positive::index_t non_const_unit_index) noexcept;
        constexpr const non_const_unit_t&           Non_Const_Unit(nkr::positive::index_t non_const_unit_index) const noexcept;
                  volatile non_const_unit_t&        Non_Const_Unit(nkr::positive::index_t non_const_unit_index) volatile noexcept;
                  const volatile non_const_unit_t&  Non_Const_Unit(nkr::positive::index_t non_const_unit_index) const volatile noexcept;

    public:
        constexpr unit_t&                   operator [](nkr::positive::index_t unit_index) noexcept;
        constexpr const unit_t&             operator [](nkr::positive::index_t unit_index) const noexcept;
                  volatile unit_t&          operator [](nkr::positive::index_t unit_index) volatile noexcept;
                  const volatile unit_t&    operator [](nkr::positive::index_t unit_index) const volatile noexcept;
    };

}}}}

#include "nkr/array/local/dynamic_t_dec_def.h"

#endif
