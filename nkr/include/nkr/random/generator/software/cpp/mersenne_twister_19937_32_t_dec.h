/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/random/generator/software/cpp/mersenne_twister_t_dec.h"

namespace nkr { namespace random { namespace generator { namespace software { namespace cpp {

    using   mersenne_twister_19937_32_t =
        nkr::cpp::random::generator::mersenne_twister_19937_32_t;

    struct  mersenne_twister_19937_32_tg    {};

    template <typename type_p>
    concept mersenne_twister_19937_32_tr =
        nkr::cpp::is_any_tr<type_p, mersenne_twister_19937_32_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::random::generator::software::cpp::mersenne_twister_19937_32_tg>
    {
    public:
        using type_t    = nkr::random::generator::software::cpp::mersenne_twister_19937_32_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

#include "nkr/random/generator/software/cpp/mersenne_twister_19937_32_t_dec_def.h"
