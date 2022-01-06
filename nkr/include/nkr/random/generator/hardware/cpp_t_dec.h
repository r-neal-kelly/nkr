/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace random { namespace generator { namespace hardware {

    using   cpp_t =
        nkr::cpp::random::generator::hardware_t;

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::is_any_tr<type_p, cpp_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::random::generator::hardware::cpp_tg>
    {
    public:
        using type_t    = nkr::random::generator::hardware::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::random::generator::hardware::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::random::generator::hardware::cpp_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/random/generator/hardware/cpp_t_dec_def.h"
