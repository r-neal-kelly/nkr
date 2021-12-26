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
    class type_i<boolean::cpp_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <boolean::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::cpp_tg>
    {
    public:
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
