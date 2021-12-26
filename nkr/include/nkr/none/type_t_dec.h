/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/none_tr_dec.h"
#include "nkr/generic/none/any_tr_dec.h"

namespace nkr { namespace none {

    struct  type_tg {};

    template <typename type_p>
    concept type_tr =
        cpp::is_any_tr<type_p, type_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::none::type_tg>
    {
    public:
        using type_t    = nkr::none::type_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

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
    };

}}

#include "nkr/none/type_t_dec_def.h"

namespace nkr { namespace none {

    static_assert(generic::none_tr<type_t>);
    static_assert(generic::none_tr<const type_t>);
    static_assert(generic::none_tr<volatile type_t>);
    static_assert(generic::none_tr<const volatile type_t>);

    static_assert(generic::none::any_tr<type_t>);
    static_assert(generic::none::any_tr<const type_t>);
    static_assert(generic::none::any_tr<volatile type_t>);
    static_assert(generic::none::any_tr<const volatile type_t>);

}}
