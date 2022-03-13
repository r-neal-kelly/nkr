/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/generic/type_tr_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr {

    /// @copydoc _09f6d63e_f4b7_46e1_b499_fcfa5132d76f
    /// @ingroup _144407f2_f15c_4e13_9507_168de44b2b1f
    template <nkr::generic::type_tr type_p, type_p value_p>
    class constant_t;

    /// @copydoc _7011a9e2_12cb_4fb5_b2b0_83080a091ab4
    /// @ingroup _144407f2_f15c_4e13_9507_168de44b2b1f
    template <typename type_p>
    concept constant_tr =
        nkr::cpp::is_any_tr<type_p, constant_t<typename type_p::value_t, type_p::Value()>>;

    /// @copydoc _651a47d3_40f7_4a6f_be9c_5fbc92a159ec
    /// @ingroup _144407f2_f15c_4e13_9507_168de44b2b1f
    template <template <typename inner_p, inner_p value_p> typename template_p>
    concept constant_ttr =
        nkr::cpp::is_any_tr<template_p<nkr::boolean::cpp_t, false>, constant_t<nkr::boolean::cpp_t, false>>;

    /// @copydoc _fba50840_494c_4a81_8772_9c5315bc8cd2
    /// @ingroup _144407f2_f15c_4e13_9507_168de44b2b1f
    template <typename type_p, typename value_p>
    concept constant_of_tr =
        nkr::constant_tr<type_p> &&
        nkr::cpp::is_tr<typename type_p::value_t, value_p>;

    /// @copydoc _c8ccd7aa_610c_4f1b_ba49_de22374f3b78
    /// @ingroup _144407f2_f15c_4e13_9507_168de44b2b1f
    class constant_tg
    {
    public:
        /// @name label labels
        /// @{
        class   tag_lb      {}; ///< @copydoc _ce94d1e4_a278_45b7_810b_cefc31748bb7
        class   type_lb     {}; ///< @copydoc _ecc4588e_6d37_42e1_a034_46d91bc1105b
        class   identity_lb {}; ///< @copydoc _c09f867d_57cb_452a_83a2_ee9b677b193c
        /// @}
    };

    /// @copydoc _96f44ebd_b97a_46fc_b2cc_8ed5ac09da45
    /// @ingroup _144407f2_f15c_4e13_9507_168de44b2b1f
    template <typename ...>
    class constant_ttg
    {
    public:
        /// @name label labels
        /// @{
        class   tag_lb      {}; ///< @copydoc _f2b5c812_c49d_48ce_b4f0_a3747def4f5f
        class   template_lb {}; ///< @copydoc _4fe39de6_ce5d_4ecd_985f_d214044ce654
        class   identity_lb {}; ///< @copydoc _22613a5f_f098_47c3_bb33_fde978e6e70a
        /// @}
    };

}

namespace nkr { namespace constant_t$ {

    template <nkr::constant_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::value_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::constant_tg> type_p>
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

}}

namespace nkr { namespace interface {

    template <nkr::constant_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::constant_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::constant_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::constant_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace constant_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    class template_i_tag_sp
    {
    private:
        template <typename ...parameters_p>
        class parameters_to_value_t;

        template <typename value_p>
        class parameters_to_value_t<value_p>
        {
        public:
            using type_t    = value_p;
        };

    public:
        template <nkr::generic::type_tr type_p, type_p value_p>
        using template_t        = nkr::constant_t<type_p, value_p>;

        template <typename inner_p>
            requires requires { { nkr::interface::none::value_i<inner_p>::Value() } -> nkr::cpp::is_any_tr<inner_p>; }
        using of_t              = template_t<inner_p, nkr::interface::none::value_i<inner_p>::Value()>;

        template <typename parameters_p>
            requires (parameters_p::Count() == 1)
        using of_tuple_t        = parameters_p::template into_t<of_t>;

        template <typename ...parameters_p>
            requires (sizeof...(parameters_p) == 1)
        using of_pack_t         = of_t<typename parameters_to_value_t<parameters_p...>::type_t>;

        using example_t         = template_t<nkr::boolean::cpp_t, false>;

        template <typename ...parameters_p>
        using actual_template_t = nkr::constant_ttg<parameters_p...>;

        template <typename inner_p>
        using actual_of_t       = actual_template_t<inner_p>;

        template <typename parameters_p>
        using actual_of_tuple_t = parameters_p::template into_t<actual_template_t>;

        template <typename ...parameters_p>
        using actual_of_pack_t  = actual_template_t<parameters_p...>;

        using actual_example_t  = actual_template_t<>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
        template <template <typename inner_p, inner_p> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;
        template <template <typename inner_p, inner_p> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Actual() noexcept;

    public:
        template <typename ...>
        constexpr template_i_tag_sp(...) noexcept   = delete;
    };

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::constant_ttg>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::constant_t$::template_i_tag_sp<template_p>;
    };

}}

namespace nkr {

    template <nkr::generic::type_tr type_p, type_p value_p>
    class constant_t
    {
    public:
        /// @name aliases
        /// @{
        using value_t   = type_p;   ///< @copydoc _3930c6fb_a15c_42cd_a6db_b41d3318b998
        /// @}

    public:
        /// @name static functions
        /// @{
        static constexpr value_t    Value() noexcept;   ///< @copydoc _0e8b0f54_647f_4838_a696_bc19fd0ef14f
        /// @}

    public:
        /// @name constructors
        /// @{
        constexpr constant_t() noexcept;

        constexpr constant_t(const constant_t& other) noexcept;
        constexpr constant_t(const volatile constant_t& other) noexcept;
        constexpr constant_t(constant_t&& other) noexcept;
        constexpr constant_t(volatile constant_t&& other) noexcept;
        /// @}

        /// @name assigners
        /// @{
        constexpr constant_t&           operator =(const constant_t& other) noexcept                    = delete;
        constexpr volatile constant_t&  operator =(const constant_t& other) volatile noexcept           = delete;
        constexpr constant_t&           operator =(const volatile constant_t& other) noexcept           = delete;
        constexpr volatile constant_t&  operator =(const volatile constant_t& other) volatile noexcept  = delete;
        constexpr constant_t&           operator =(constant_t&& other) noexcept                         = delete;
        constexpr volatile constant_t&  operator =(constant_t&& other) volatile noexcept                = delete;
        constexpr constant_t&           operator =(volatile constant_t&& other) noexcept                = delete;
        constexpr volatile constant_t&  operator =(volatile constant_t&& other) volatile noexcept       = delete;
        /// @}

    public:
        /// @name casters
        /// @{
        constexpr operator  nkr::constant_t<type_p, value_p>::value_t() const noexcept;             ///< @copydoc _92c0cf7e_3299_4b26_8925_51a2bb742f40
        constexpr operator  nkr::constant_t<type_p, value_p>::value_t() const volatile noexcept;    ///< @copydoc _fb9e9b09_08ef_4200_8b62_650ee3288bf6
        /// @}

    public:
        /// @name operators
        /// @{
        constexpr value_t   operator ()() const noexcept;           ///< @copydoc _88bb3161_7ba1_4e16_9e75_db8a07e0adaa
        constexpr value_t   operator ()() const volatile noexcept;  ///< @copydoc _c3f090d1_cfa0_4212_b596_01d86b9c4a07
        /// @}
    };

}

#include "nkr/constant_t_dec_def.h"
