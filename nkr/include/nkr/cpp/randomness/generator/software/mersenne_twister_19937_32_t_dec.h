/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/randomness/generator/software/mersenne_twister_t_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator { namespace software {

    using   mersenne_twister_19937_32_t =
        std::mt19937;

    struct  mersenne_twister_19937_32_tg    {};

    template <typename type_p>
    concept mersenne_twister_19937_32_tr =
        nkr::cpp::is_any_tr<type_p, mersenne_twister_19937_32_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tg>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::software::mersenne_twister_19937_32_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/randomness/generator/software/mersenne_twister_19937_32_t_dec_def.h"
