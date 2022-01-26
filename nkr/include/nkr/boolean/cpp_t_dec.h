/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace boolean {

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::is_any_tr<type_p, cpp_t>;

    /*template <cpp_t value_p>
    using   cpp_c =
        nkr::cpp::constant_t<cpp_t, value_p>;

    template <typename type_p>
    concept cpp_ctr =
        nkr::cpp::constant_of_tr<type_p, nkr::boolean::cpp_t>;*/

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::boolean::cpp_tg>
    {
    public:
        using type_t    = nkr::boolean::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::boolean::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::boolean::cpp_tg>
    {
    public:
        using type_t    = type_p;
    };

}}

#include "nkr/boolean/cpp_t_dec_def.h"
