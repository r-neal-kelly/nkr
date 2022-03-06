/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/constant_t_dec.h"
#include "nkr/constant/boolean/cpp_t_dec.h"
#include "nkr/constant/positive/integer_t_dec.h"
#include "nkr/constant/positive/size_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tuple/types_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_t$ {

    template <typename type_p>
    class   is_tmpl;

}}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software {

    template <
        typename                            result_p,

        nkr::constant::positive::size_tr    w_p,
        nkr::constant::positive::size_tr    n_p,
        nkr::constant::positive::size_tr    m_p,
        nkr::constant::positive::size_tr    r_p,

        nkr::constant_of_tr<result_p>       a_p,
        nkr::constant::positive::size_tr    u_p,
        nkr::constant_of_tr<result_p>       d_p,
        nkr::constant::positive::size_tr    s_p,
        nkr::constant_of_tr<result_p>       b_p,
        nkr::constant::positive::size_tr    t_p,
        nkr::constant_of_tr<result_p>       c_p,
        nkr::constant::positive::size_tr    l_p,

        nkr::constant_of_tr<result_p>       f_p
    > using mersenne_twister_t = std::mersenne_twister_engine<
        result_p,

        w_p::Value(),
        n_p::Value(),
        m_p::Value(),
        r_p::Value(),

        a_p::Value(),
        u_p::Value(),
        d_p::Value(),
        s_p::Value(),
        b_p::Value(),
        t_p::Value(),
        c_p::Value(),
        l_p::Value(),

        f_p::Value()
    >;

    struct  mersenne_twister_tg     { class tag_lb; };

    template <typename>
    struct  mersenne_twister_ttg    {};

    template <typename type_p>
    concept mersenne_twister_tr =
        mersenne_twister_t$::is_tmpl<just_non_qualified_t<type_p>>::Value();

    template <template <typename ...> typename template_p>
    concept mersenne_twister_ttr = nkr::cpp::is_any_ttr<template_p, mersenne_twister_t,
        nkr::positive::integer_t,

        nkr::constant::positive::size_t<3>,
        nkr::constant::positive::size_t<1>,
        nkr::constant::positive::size_t<1>,
        nkr::constant::positive::size_t<3>,

        nkr::constant::positive::integer_t<0>,
        nkr::constant::positive::size_t<3>,
        nkr::constant::positive::integer_t<0>,
        nkr::constant::positive::size_t<3>,
        nkr::constant::positive::integer_t<0>,
        nkr::constant::positive::size_t<3>,
        nkr::constant::positive::integer_t<0>,
        nkr::constant::positive::size_t<3>,

        nkr::constant::positive::integer_t<0>
    >;

}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_t$ {

    template <typename type_p>
    class is_tmpl :
        public nkr::constant::boolean::cpp_t<false>
    {
    public:
    };

    template <
        typename result_p,

        nkr::positive::size_t w_p,
        nkr::positive::size_t n_p,
        nkr::positive::size_t m_p,
        nkr::positive::size_t r_p,

        result_p a_p,
        nkr::positive::size_t u_p,
        result_p d_p,
        nkr::positive::size_t s_p,
        result_p b_p,
        nkr::positive::size_t t_p,
        result_p c_p,
        nkr::positive::size_t l_p,

        result_p f_p
    > class is_tmpl<std::mersenne_twister_engine<
        result_p,

        w_p,
        n_p,
        m_p,
        r_p,

        a_p,
        u_p,
        d_p,
        s_p,
        b_p,
        t_p,
        c_p,
        l_p,

        f_p>
    > : public nkr::constant::boolean::cpp_t<true>
    {
    public:
    };

}}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_t$ {

    template <nkr::cpp::randomness::generator::software::mersenne_twister_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::result_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_tg> type_p>
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

}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::randomness::generator::software::mersenne_twister_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::generator::software::mersenne_twister_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace mersenne_twister_t$ {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_p>
    class template_i_template_sp
    {
    public:
        template <
            typename                            result_p,

            nkr::constant::positive::size_tr    w_p,
            nkr::constant::positive::size_tr    n_p,
            nkr::constant::positive::size_tr    m_p,
            nkr::constant::positive::size_tr    r_p,

            nkr::constant_of_tr<result_p>       a_p,
            nkr::constant::positive::size_tr    u_p,
            nkr::constant_of_tr<result_p>       d_p,
            nkr::constant::positive::size_tr    s_p,
            nkr::constant_of_tr<result_p>       b_p,
            nkr::constant::positive::size_tr    t_p,
            nkr::constant_of_tr<result_p>       c_p,
            nkr::constant::positive::size_tr    l_p,

            nkr::constant_of_tr<result_p>       f_p
        > using template_t  = nkr::cpp::randomness::generator::software::mersenne_twister_t<
            result_p,

            w_p,
            n_p,
            m_p,
            r_p,

            a_p,
            u_p,
            d_p,
            s_p,
            b_p,
            t_p,
            c_p,
            l_p,

            f_p
        >;

        template <typename inner_p>
        using   of_t        = template_t<
            inner_p,

            nkr::constant::positive::size_t<3>,
            nkr::constant::positive::size_t<1>,
            nkr::constant::positive::size_t<1>,
            nkr::constant::positive::size_t<3>,

            nkr::constant_t<inner_p, 0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant_t<inner_p, 0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant_t<inner_p, 0>,
            nkr::constant::positive::size_t<3>,
            nkr::constant_t<inner_p, 0>,
            nkr::constant::positive::size_t<3>,

            nkr::constant_t<inner_p, 0>
        >;

        template <nkr::tuple::types_tr parameters_p>
            requires (parameters_p::Count() == 14)
        using   of_tuple_t  = parameters_p::template into_t<template_t>;

        template <typename ...parameters_p>
        using   of_pack_t   = of_tuple_t<nkr::tuple::types_t<parameters_p...>>;

        using   example_t   = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i_template_sp(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::generator::software::mersenne_twister_ttg, nkr::none::type_t>
    class template_i_tag_sp :
        public template_i_template_sp<nkr::cpp::randomness::generator::software::mersenne_twister_t>
    {
    public:
    };

}}}}}}

namespace nkr { namespace interface {

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_p>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_t$::template_i_template_sp<template_p>;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::is_any_ttr<template_p, nkr::cpp::randomness::generator::software::mersenne_twister_ttg, nkr::none::type_t>
    class template_i_sp<template_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_t$::template_i_tag_sp<template_p>;
    };

}}

#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec_def.h"
