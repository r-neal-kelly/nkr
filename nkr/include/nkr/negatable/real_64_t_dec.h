/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/general/negatable_tr_dec.h"
#include "nkr/general/negatable/any_tr_dec.h"
#include "nkr/general/negatable/real_tr_dec.h"

namespace nkr { namespace negatable {

    struct  real_64_tg  {};

    template <typename type_p>
    concept real_64_tr =
        cpp::is_any_tr<type_p, real_64_t> ||
        (cpp::negatable_real_tr<type_p> && sizeof(type_p) * 8 == 64);

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::real_64_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <negatable::real_64_tr type_p>
    class type_i<type_p> :
        public type_i<negatable::real_64_tg>
    {
    public:
    };

}}

#include "nkr/negatable/real_64_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(general::negatable_tr<real_64_t>);
    static_assert(general::negatable_tr<const real_64_t>);
    static_assert(general::negatable_tr<volatile real_64_t>);
    static_assert(general::negatable_tr<const volatile real_64_t>);

    static_assert(general::negatable::any_tr<real_64_t>);
    static_assert(general::negatable::any_tr<const real_64_t>);
    static_assert(general::negatable::any_tr<volatile real_64_t>);
    static_assert(general::negatable::any_tr<const volatile real_64_t>);

    static_assert(general::negatable::real_tr<real_64_t>);
    static_assert(general::negatable::real_tr<const real_64_t>);
    static_assert(general::negatable::real_tr<volatile real_64_t>);
    static_assert(general::negatable::real_tr<const volatile real_64_t>);

}}
