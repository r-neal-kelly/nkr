/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/generic/boolean_tr_dec.h"
#include "nkr/generic/boolean/any_tr_dec.h"
#include "nkr/generic/boolean/impure_tr_dec.h"

namespace nkr { namespace boolean {

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        cpp::is_any_tr<type_p, cpp_t>;

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

namespace nkr { namespace boolean {

    static_assert(generic::boolean_tr<cpp_t>);
    static_assert(generic::boolean_tr<const cpp_t>);
    static_assert(generic::boolean_tr<volatile cpp_t>);
    static_assert(generic::boolean_tr<const volatile cpp_t>);

    static_assert(generic::boolean::any_tr<cpp_t>);
    static_assert(generic::boolean::any_tr<const cpp_t>);
    static_assert(generic::boolean::any_tr<volatile cpp_t>);
    static_assert(generic::boolean::any_tr<const volatile cpp_t>);

    static_assert(generic::boolean::impure_tr<cpp_t>);
    static_assert(generic::boolean::impure_tr<const cpp_t>);
    static_assert(generic::boolean::impure_tr<volatile cpp_t>);
    static_assert(generic::boolean::impure_tr<const volatile cpp_t>);

}}
