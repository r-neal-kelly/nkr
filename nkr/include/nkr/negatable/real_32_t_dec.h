/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/trait/negatable_tr_dec.h"
#include "nkr/trait/negatable/any_tr_dec.h"
#include "nkr/trait/negatable/real_tr_dec.h"

namespace nkr { namespace negatable {

    struct  real_32_tg  {};

    template <typename type_p>
    concept real_32_tr =
        cpp::is_any_tr<type_p, real_32_t> ||
        (cpp::negatable_real_tr<type_p> && sizeof(type_p) * 8 == 32);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::real_32_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <negatable::real_32_tr type_p>
    class type_i<type_p> :
        public type_i<negatable::real_32_tg>
    {
    public:
    };

}}

#include "nkr/negatable/real_32_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(trait::negatable_tr<real_32_t>);
    static_assert(trait::negatable_tr<const real_32_t>);
    static_assert(trait::negatable_tr<volatile real_32_t>);
    static_assert(trait::negatable_tr<const volatile real_32_t>);

    static_assert(trait::negatable::any_tr<real_32_t>);
    static_assert(trait::negatable::any_tr<const real_32_t>);
    static_assert(trait::negatable::any_tr<volatile real_32_t>);
    static_assert(trait::negatable::any_tr<const volatile real_32_t>);

    static_assert(trait::negatable::real_tr<real_32_t>);
    static_assert(trait::negatable::real_tr<const real_32_t>);
    static_assert(trait::negatable::real_tr<volatile real_32_t>);
    static_assert(trait::negatable::real_tr<const volatile real_32_t>);

}}
