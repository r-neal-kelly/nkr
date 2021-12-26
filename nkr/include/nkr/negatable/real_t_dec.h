/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/real_32_t_dec.h"
#include "nkr/negatable/real_64_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/real_tr_dec.h"

namespace nkr { namespace negatable {

    struct  real_tg {};

    template <typename type_p>
    concept real_tr =
        cpp::is_any_tr<type_p, real_t> ||
        (cpp::negatable_real_tr<type_p> && sizeof(type_p) == sizeof(real_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::real_tg> :
        public type_i<negatable::real_t>
    {
    public:
    };

}}

#include "nkr/negatable/real_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<real_t>);
    static_assert(generic::negatable_tr<const real_t>);
    static_assert(generic::negatable_tr<volatile real_t>);
    static_assert(generic::negatable_tr<const volatile real_t>);

    static_assert(generic::negatable::any_tr<real_t>);
    static_assert(generic::negatable::any_tr<const real_t>);
    static_assert(generic::negatable::any_tr<volatile real_t>);
    static_assert(generic::negatable::any_tr<const volatile real_t>);

    static_assert(generic::negatable::real_tr<real_t>);
    static_assert(generic::negatable::real_tr<const real_t>);
    static_assert(generic::negatable::real_tr<volatile real_t>);
    static_assert(generic::negatable::real_tr<const volatile real_t>);

}}
