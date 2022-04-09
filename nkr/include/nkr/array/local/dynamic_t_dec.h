/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_77d78d93_6414_4569_b47c_0ba6ef0c8f7a
#define nkr_INCLUDE_GUARD_77d78d93_6414_4569_b47c_0ba6ef0c8f7a

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

namespace nkr { namespace array { namespace local {

    // capacity_p should be constrained by nkr::constant::positive::count_tr, but intellisense keeps crashing.
    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class dynamic_t;

    template <typename type_p>
    concept dynamic_tr =
        nkr::cpp::is_any_tr<type_p, dynamic_t<typename type_p::unit_t, typename type_p::capacity_t>>;

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

namespace nkr { namespace array { namespace local {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    class dynamic_t
    {
    public:
        using unit_t        = unit_p;
        using capacity_t    = capacity_p;
        using bytes_t       = nkr::positive::byte_t[capacity_t::Value() * sizeof(unit_t)];
        using units_t       = unit_t[capacity_t::Value()];

    protected:
        nkr::positive::count_t  count;
        bytes_t                 bytes;

    public:
        constexpr dynamic_t() noexcept;

        constexpr dynamic_t(const dynamic_t& other) noexcept;
                  dynamic_t(const volatile dynamic_t& other) noexcept;
        constexpr dynamic_t(dynamic_t&& other) noexcept;
                  dynamic_t(volatile dynamic_t&& other) noexcept;

        constexpr dynamic_t&            operator =(const dynamic_t& other) noexcept;
                  volatile dynamic_t&   operator =(const dynamic_t& other) volatile noexcept;
                  dynamic_t&            operator =(const volatile dynamic_t& other) noexcept;
                  volatile dynamic_t&   operator =(const volatile dynamic_t& other) volatile noexcept;
        constexpr dynamic_t&            operator =(dynamic_t&& other) noexcept;
                  volatile dynamic_t&   operator =(dynamic_t&& other) volatile noexcept;
                  dynamic_t&            operator =(volatile dynamic_t&& other) noexcept;
                  volatile dynamic_t&   operator =(volatile dynamic_t&& other) volatile noexcept;

    public:
        constexpr nkr::positive::count_t    Count() const noexcept;
                  nkr::positive::count_t    Count() const volatile noexcept;
        constexpr nkr::positive::count_t    Capacity() const noexcept;
                  nkr::positive::count_t    Capacity() const volatile noexcept;
    };

}}}

#include "nkr/array/local/dynamic_t_dec_def.h"

#endif
