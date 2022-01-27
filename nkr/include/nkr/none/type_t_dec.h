/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"

namespace nkr { namespace none {

    using   type_t =
        nkr::cpp::none::type_t;

    struct  type_tg {};

    template <typename type_p>
    concept type_tr =
        nkr::cpp::is_any_tr<type_p, type_t>;

}}

namespace nkr { namespace interface {

    template <typename type_p>
    class type_i;

    template <>
    class type_i<nkr::none::type_tg>
    {
    public:
        using type_t    = nkr::none::type_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::cpp::boolean_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::none::type_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::none::type_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/none/type_t_dec_def.h"
