/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_25e0eb68_8673_45db_b0e9_d090604e2b29
#define nkr_INCLUDE_GUARD_25e0eb68_8673_45db_b0e9_d090604e2b29

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant/positive/count_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/implementing/constructor/default_tr_dec.h"
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
    union units_or_bytes_u;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class empty_sp;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class non_const_default_sp;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class non_const_non_default_sp;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class const_default_sp;

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class const_non_default_sp;

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
        requires (capacity_p::Value() > 0 && tr<unit_p, any_non_const_tg> && nkr::generic::implementing::constructor::default_tr<unit_p>)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = non_const_default_sp<unit_p, capacity_p>;
    };

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (capacity_p::Value() > 0 && tr<unit_p, any_non_const_tg> && !nkr::generic::implementing::constructor::default_tr<unit_p>)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = non_const_non_default_sp<unit_p, capacity_p>;
    };

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (capacity_p::Value() > 0 && tr<unit_p, any_const_tg> && nkr::generic::implementing::constructor::default_tr<unit_p>)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = const_default_sp<unit_p, capacity_p>;
    };

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (capacity_p::Value() > 0 && tr<unit_p, any_const_tg> && !nkr::generic::implementing::constructor::default_tr<unit_p>)
    class specialization_tmpl<unit_p, capacity_p>
    {
    public:
        using type_t    = const_non_default_sp<unit_p, capacity_p>;
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

    // TODO: Move this comment to the docs.
    /*
        We want to be able to copy and move C arrays through constructors.
        But C arrays have no construction/assignment semantics for their own type.
        This means we have to iterate over the right-hand array and set each element individually.
        But we want to support unit types that do not have a default constructor or
        which have an expensive default constructor. So we necessarily avoid calling any unit_t
        default constructor by uniting this with a byte array which does not need to be constructed.
        Then we can iterate over the given unit_t array and copy/move elements freely.

        This type REQUIRES that all unit_t elements in the array are valid by the time of destruction,
        because it calls the destructor on each element as if it were a unit_t.

        This type REQUIRES that all unit_t elements are valid before any copy or move assignment
        takes place, because each element's unit_t destructor is called.
    */
    template <nkr::generic::type_tr unit_p, typename capacity_p>
    union units_or_bytes_u
    {
    public:
        using unit_t        = unit_p;
        using capacity_t    = capacity_p;
        using units_t       = unit_t[capacity_t::Value()];
        using bytes_t       = nkr::positive::byte_t[capacity_t::Value() * sizeof(unit_t)];

    public:
        class default_units_t
        {
        public:
        };

        class common_t
        {
        public:
            static constexpr nkr::none::type_t  Construct(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                          const tr<any_tg, t<units_or_bytes_u>> auto& other) noexcept;
            static constexpr nkr::none::type_t  Construct(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                          tr<any_non_const_tg, t<units_or_bytes_u>> auto&& other) noexcept;

            static constexpr auto&              Assign(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                       const tr<any_tg, t<units_or_bytes_u>> auto& other) noexcept;
            static constexpr auto&              Assign(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                       tr<any_non_const_tg, t<units_or_bytes_u>> auto&& other) noexcept;

            static constexpr nkr::none::type_t  Destruct(tr<any_tg, t<units_or_bytes_u>> auto& self) noexcept;

            static constexpr auto&              Units(tr<any_tg, t<units_or_bytes_u>> auto& self) noexcept;
        };

    public:
        units_t units;
        bytes_t bytes;

    public:
        constexpr units_or_bytes_u() noexcept;

        constexpr units_or_bytes_u(tr<any_tg, t<default_units_t>> auto default_units) noexcept;
        constexpr units_or_bytes_u(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr units_or_bytes_u(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr units_or_bytes_u(const units_or_bytes_u& other) noexcept;
                  units_or_bytes_u(const volatile units_or_bytes_u& other) noexcept;
        constexpr units_or_bytes_u(units_or_bytes_u&& other) noexcept;
                  units_or_bytes_u(volatile units_or_bytes_u&& other) noexcept;

        constexpr units_or_bytes_u&             operator =(const units_or_bytes_u& other) noexcept;
                  volatile units_or_bytes_u&    operator =(const units_or_bytes_u& other) volatile noexcept;
                  units_or_bytes_u&             operator =(const volatile units_or_bytes_u& other) noexcept;
                  volatile units_or_bytes_u&    operator =(const volatile units_or_bytes_u& other) volatile noexcept;
        constexpr units_or_bytes_u&             operator =(units_or_bytes_u&& other) noexcept;
                  volatile units_or_bytes_u&    operator =(units_or_bytes_u&& other) volatile noexcept;
                  units_or_bytes_u&             operator =(tr<just_volatile_tg, t<units_or_bytes_u>> auto&& other) noexcept;
                  volatile units_or_bytes_u&    operator =(tr<just_volatile_tg, t<units_or_bytes_u>> auto&& other) volatile noexcept;

        constexpr ~units_or_bytes_u() noexcept;

    public:
        constexpr units_t&                  Units() noexcept;
        constexpr const units_t&            Units() const noexcept;
                  volatile units_t&         Units() volatile noexcept;
                  const volatile units_t&   Units() const volatile noexcept;
    };

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class empty_sp
    {
    public:
        using unit_t        = unit_p;
        using capacity_t    = capacity_p;
        using units_t       = unit_t[];

    public:
        friend  nkr::array::local::static_t$::common_t;

    public:
        constexpr empty_sp() noexcept;

        constexpr empty_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept                                         = delete;
        constexpr empty_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept                                    = delete;

        constexpr empty_sp(const empty_sp& other) noexcept;
                  empty_sp(const volatile empty_sp& other) noexcept;
        constexpr empty_sp(empty_sp&& other) noexcept;
                  empty_sp(volatile empty_sp&& other) noexcept;

        constexpr empty_sp&             operator =(const empty_sp& other) noexcept;
                  volatile empty_sp&    operator =(const empty_sp& other) volatile noexcept;
                  empty_sp&             operator =(const volatile empty_sp& other) noexcept;
                  volatile empty_sp&    operator =(const volatile empty_sp& other) volatile noexcept;
        constexpr empty_sp&             operator =(empty_sp&& other) noexcept;
                  volatile empty_sp&    operator =(empty_sp&& other) volatile noexcept;
                  empty_sp&             operator =(tr<just_volatile_tg, t<empty_sp>> auto&& other) noexcept;
                  volatile empty_sp&    operator =(tr<just_volatile_tg, t<empty_sp>> auto&& other) volatile noexcept;

    public:
        constexpr units_t&                  Units() noexcept                            = delete;
        constexpr const units_t&            Units() const noexcept                      = delete;
                  volatile units_t&         Units() volatile noexcept                   = delete;
                  const volatile units_t&   Units() const volatile noexcept             = delete;

        constexpr nkr::positive::count_t    Count() const noexcept;
                  nkr::positive::count_t    Count() const volatile noexcept;
        constexpr nkr::positive::count_t    Capacity() const noexcept;
                  nkr::positive::count_t    Capacity() const volatile noexcept;
    };

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class non_const_default_sp
    {
    public:
        using unit_t            = unit_p;
        using capacity_t        = capacity_p;
        using units_or_bytes_u  = units_or_bytes_u<unit_t, capacity_t>;
        using units_t           = typename units_or_bytes_u::units_t;

    public:
        friend  nkr::array::local::static_t$::common_t;

    public:
        units_or_bytes_u    units_or_bytes;

    public:
        constexpr non_const_default_sp() noexcept;

        constexpr non_const_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr non_const_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr non_const_default_sp(const non_const_default_sp& other) noexcept;
                  non_const_default_sp(const volatile non_const_default_sp& other) noexcept;
        constexpr non_const_default_sp(non_const_default_sp&& other) noexcept;
                  non_const_default_sp(volatile non_const_default_sp&& other) noexcept;

        constexpr non_const_default_sp&             operator =(const non_const_default_sp& other) noexcept;
                  volatile non_const_default_sp&    operator =(const non_const_default_sp& other) volatile noexcept;
                  non_const_default_sp&             operator =(const volatile non_const_default_sp& other) noexcept;
                  volatile non_const_default_sp&    operator =(const volatile non_const_default_sp& other) volatile noexcept;
        constexpr non_const_default_sp&             operator =(non_const_default_sp&& other) noexcept;
                  volatile non_const_default_sp&    operator =(non_const_default_sp&& other) volatile noexcept;
                  non_const_default_sp&             operator =(tr<just_volatile_tg, t<non_const_default_sp>> auto&& other) noexcept;
                  volatile non_const_default_sp&    operator =(tr<just_volatile_tg, t<non_const_default_sp>> auto&& other) volatile noexcept;

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
    class non_const_non_default_sp
    {
    public:
        using unit_t            = unit_p;
        using capacity_t        = capacity_p;
        using units_or_bytes_u  = units_or_bytes_u<unit_t, capacity_t>;
        using units_t           = typename units_or_bytes_u::units_t;

    public:
        friend  nkr::array::local::static_t$::common_t;

    public:
        units_or_bytes_u    units_or_bytes;

    public:
        constexpr non_const_non_default_sp() noexcept                                                                                                   = delete;
        
        constexpr non_const_non_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr non_const_non_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr non_const_non_default_sp(const non_const_non_default_sp& other) noexcept;
                  non_const_non_default_sp(const volatile non_const_non_default_sp& other) noexcept;
        constexpr non_const_non_default_sp(non_const_non_default_sp&& other) noexcept;
                  non_const_non_default_sp(volatile non_const_non_default_sp&& other) noexcept;

        constexpr non_const_non_default_sp&             operator =(const non_const_non_default_sp& other) noexcept;
                  volatile non_const_non_default_sp&    operator =(const non_const_non_default_sp& other) volatile noexcept;
                  non_const_non_default_sp&             operator =(const volatile non_const_non_default_sp& other) noexcept;
                  volatile non_const_non_default_sp&    operator =(const volatile non_const_non_default_sp& other) volatile noexcept;
        constexpr non_const_non_default_sp&             operator =(non_const_non_default_sp&& other) noexcept;
                  volatile non_const_non_default_sp&    operator =(non_const_non_default_sp&& other) volatile noexcept;
                  non_const_non_default_sp&             operator =(tr<just_volatile_tg, t<non_const_non_default_sp>> auto&& other) noexcept;
                  volatile non_const_non_default_sp&    operator =(tr<just_volatile_tg, t<non_const_non_default_sp>> auto&& other) volatile noexcept;

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
    class const_default_sp
    {
    public:
        using unit_t            = unit_p;
        using capacity_t        = capacity_p;
        using units_or_bytes_u  = units_or_bytes_u<unit_t, capacity_t>;
        using units_t           = typename units_or_bytes_u::units_t;

    public:
        friend  nkr::array::local::static_t$::common_t;

    public:
        units_or_bytes_u    units_or_bytes;

    public:
        constexpr const_default_sp() noexcept;

        constexpr const_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr const_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr const_default_sp(const const_default_sp& other) noexcept;
                  const_default_sp(const volatile const_default_sp& other) noexcept;
        constexpr const_default_sp(const_default_sp&& other) noexcept;
                  const_default_sp(volatile const_default_sp&& other) noexcept;

        constexpr const_default_sp&             operator =(const const_default_sp& other) noexcept                                      = delete;
                  volatile const_default_sp&    operator =(const const_default_sp& other) volatile noexcept                             = delete;
                  const_default_sp&             operator =(const volatile const_default_sp& other) noexcept                             = delete;
                  volatile const_default_sp&    operator =(const volatile const_default_sp& other) volatile noexcept                    = delete;
        constexpr const_default_sp&             operator =(const_default_sp&& other) noexcept                                           = delete;
                  volatile const_default_sp&    operator =(const_default_sp&& other) volatile noexcept                                  = delete;
                  const_default_sp&             operator =(tr<just_volatile_tg, t<const_default_sp>> auto&& other) noexcept             = delete;
                  volatile const_default_sp&    operator =(tr<just_volatile_tg, t<const_default_sp>> auto&& other) volatile noexcept    = delete;

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
    class const_non_default_sp
    {
    public:
        using unit_t            = unit_p;
        using capacity_t        = capacity_p;
        using units_or_bytes_u  = units_or_bytes_u<unit_t, capacity_t>;
        using units_t           = typename units_or_bytes_u::units_t;

    public:
        friend  nkr::array::local::static_t$::common_t;

    public:
        units_or_bytes_u    units_or_bytes;

    public:
        constexpr const_non_default_sp() noexcept                                                                                               = delete;
        
        constexpr const_non_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept;
        constexpr const_non_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept;

        constexpr const_non_default_sp(const const_non_default_sp& other) noexcept;
                  const_non_default_sp(const volatile const_non_default_sp& other) noexcept;
        constexpr const_non_default_sp(const_non_default_sp&& other) noexcept;
                  const_non_default_sp(volatile const_non_default_sp&& other) noexcept;

        constexpr const_non_default_sp&             operator =(const const_non_default_sp& other) noexcept                                      = delete;
                  volatile const_non_default_sp&    operator =(const const_non_default_sp& other) volatile noexcept                             = delete;
                  const_non_default_sp&             operator =(const volatile const_non_default_sp& other) noexcept                             = delete;
                  volatile const_non_default_sp&    operator =(const volatile const_non_default_sp& other) volatile noexcept                    = delete;
        constexpr const_non_default_sp&             operator =(const_non_default_sp&& other) noexcept                                           = delete;
                  volatile const_non_default_sp&    operator =(const_non_default_sp&& other) volatile noexcept                                  = delete;
                  const_non_default_sp&             operator =(tr<just_volatile_tg, t<const_non_default_sp>> auto&& other) noexcept             = delete;
                  volatile const_non_default_sp&    operator =(tr<just_volatile_tg, t<const_non_default_sp>> auto&& other) volatile noexcept    = delete;

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

#include "nkr/array/local/static_t_dec_def.h"

#endif
