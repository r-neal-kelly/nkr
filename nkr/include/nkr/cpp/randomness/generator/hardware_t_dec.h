/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace generator {

    using   hardware_t =
        std::random_device;

    struct  hardware_tg {};

    template <typename type_p>
    concept hardware_tr =
        nkr::cpp::is_any_tr<type_p, hardware_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::randomness::generator::hardware_tg>
    {
    public:
        using type_t    = nkr::cpp::randomness::generator::hardware_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::cpp::randomness::generator::hardware_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::cpp::randomness::generator::hardware_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/cpp/randomness/generator/hardware_t_dec_def.h"
