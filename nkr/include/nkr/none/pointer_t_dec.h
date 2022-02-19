/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace none {

    struct  pointer_tg  {};

    template <typename type_p>
    concept pointer_tr =
        nkr::cpp::is_any_tr<type_p, pointer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::none::pointer_tg>
    {
    public:
        using type_t    = nkr::none::pointer_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::none::pointer_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::none::pointer_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

#include "nkr/none/pointer_t_dec_def.h"
