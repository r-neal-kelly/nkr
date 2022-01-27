/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"
#include "nkr/positive/integer_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software { namespace $mersenne_twister_t {

    template <typename type_p>
    class is_tmpl :
        public std::false_type
    {
    public:
    };

    template <
        typename result_p,
        size_t w_p, size_t n_p, size_t m_p, size_t r_p,
        result_p a_p, size_t u_p, result_p d_p, size_t s_p, result_p b_p, size_t t_p, result_p c_p, size_t l_p,
        result_p f_p
    > class is_tmpl<std::mersenne_twister_engine<result_p, w_p, n_p, m_p, r_p, a_p, u_p, d_p, s_p, b_p, t_p, c_p, l_p, f_p>> :
        public std::true_type
    {
    public:
    };

}}}}}}

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software {

    template <
        typename result_p                               = nkr::positive::integer_t,

        nkr::cpp::constant_of_tr<positive::size_t> w_p  = nkr::cpp::constant_t<positive::size_t, 3>,
        nkr::cpp::constant_of_tr<positive::size_t> n_p  = nkr::cpp::constant_t<positive::size_t, 1>,
        nkr::cpp::constant_of_tr<positive::size_t> m_p  = nkr::cpp::constant_t<positive::size_t, 1>,
        nkr::cpp::constant_of_tr<positive::size_t> r_p  = nkr::cpp::constant_t<positive::size_t, 3>,

        nkr::cpp::constant_of_tr<result_p> a_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> u_p  = nkr::cpp::constant_t<positive::size_t, 3>,
        nkr::cpp::constant_of_tr<result_p> d_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> s_p  = nkr::cpp::constant_t<positive::size_t, 3>,
        nkr::cpp::constant_of_tr<result_p> b_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> t_p  = nkr::cpp::constant_t<positive::size_t, 3>,
        nkr::cpp::constant_of_tr<result_p> c_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> l_p  = nkr::cpp::constant_t<positive::size_t, 3>,

        nkr::cpp::constant_of_tr<result_p> f_p          = nkr::cpp::constant_t<result_p, 0>
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

    struct  mersenne_twister_tg     {};

    template <typename>
    struct  mersenne_twister_ttg    {};

    template <typename type_p>
    concept mersenne_twister_tr =
        $mersenne_twister_t::is_tmpl<just_non_qualified_t<type_p>>::value;

    template <template <typename ...> typename template_p>
    concept mersenne_twister_ttr =
        nkr::cpp::is_any_ttr<template_p, mersenne_twister_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::randomness::generator::software::mersenne_twister_tg>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::cpp::randomness::generator::software::mersenne_twister_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::cpp::randomness::generator::software::mersenne_twister_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::result_type;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::cpp::randomness::generator::software::mersenne_twister_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::cpp::randomness::generator::software::mersenne_twister_t<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::cpp::randomness::generator::software::mersenne_twister_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::cpp::randomness::generator::software::mersenne_twister_ttg>
    {
    public:
    };

}}

#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec_def.h"
