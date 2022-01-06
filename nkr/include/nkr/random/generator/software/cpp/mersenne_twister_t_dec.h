/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace random { namespace generator { namespace software { namespace cpp {

    template <
        typename result_p                               = positive::integer_t,

        nkr::cpp::constant_of_tr<positive::size_t> w_p  = positive::size_c<3>,
        nkr::cpp::constant_of_tr<positive::size_t> n_p  = positive::size_c<1>,
        nkr::cpp::constant_of_tr<positive::size_t> m_p  = positive::size_c<1>,
        nkr::cpp::constant_of_tr<positive::size_t> r_p  = positive::size_c<3>,

        nkr::cpp::constant_of_tr<result_p> a_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> u_p  = positive::size_c<3>,
        nkr::cpp::constant_of_tr<result_p> d_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> s_p  = positive::size_c<3>,
        nkr::cpp::constant_of_tr<result_p> b_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> t_p  = positive::size_c<3>,
        nkr::cpp::constant_of_tr<result_p> c_p          = nkr::cpp::constant_t<result_p, 0>,
        nkr::cpp::constant_of_tr<positive::size_t> l_p  = positive::size_c<3>,

        nkr::cpp::constant_of_tr<result_p> f_p          = nkr::cpp::constant_t<result_p, 0>
    > using mersenne_twister_t = nkr::cpp::random::generator::mersenne_twister_t<
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
        nkr::cpp::random::generator::mersenne_twister_tr<type_p>;

    template <template <typename ...> typename template_p>
    concept mersenne_twister_ttr =
        nkr::cpp::is_any_ttr<template_p, mersenne_twister_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::random::generator::software::cpp::mersenne_twister_tg>
    {
    public:
        using type_t    = nkr::random::generator::software::cpp::mersenne_twister_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::random::generator::software::cpp::mersenne_twister_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::random::generator::software::cpp::mersenne_twister_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::result_type;
    };

}}

namespace nkr { namespace interface {

    template <>
    class template_i<nkr::random::generator::software::cpp::mersenne_twister_ttg>
    {
    public:
        template <typename inner_p>
        using of_t      = nkr::random::generator::software::cpp::mersenne_twister_t<inner_p>;
        using example_t = of_t<nkr::positive::integer_t>;

    public:
        template <template <typename ...> typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr template_i(...) noexcept  = delete;
    };

    template <template <typename ...> typename template_p>
        requires nkr::random::generator::software::cpp::mersenne_twister_ttr<template_p>
    class template_i<template_p> :
        public template_i<nkr::random::generator::software::cpp::mersenne_twister_ttg>
    {
    public:
    };

}}

#include "nkr/random/generator/software/cpp/mersenne_twister_t_dec_def.h"
