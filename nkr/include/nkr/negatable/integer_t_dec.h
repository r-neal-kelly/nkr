/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_8_t_dec.h"
#include "nkr/negatable/integer_16_t_dec.h"
#include "nkr/negatable/integer_32_t_dec.h"
#include "nkr/negatable/integer_64_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  integer_tg  {};

    template <typename type_p>
    concept integer_tr =
        cpp::is_any_tr<type_p, integer_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(integer_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::integer_tg> :
        public type_i<nkr::negatable::integer_t>
    {
    public:
        using type_t    = nkr::negatable::integer_tg;
    };

}}

#include "nkr/negatable/integer_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<integer_t>);
    static_assert(generic::negatable_tr<const integer_t>);
    static_assert(generic::negatable_tr<volatile integer_t>);
    static_assert(generic::negatable_tr<const volatile integer_t>);

    static_assert(generic::negatable::any_tr<integer_t>);
    static_assert(generic::negatable::any_tr<const integer_t>);
    static_assert(generic::negatable::any_tr<volatile integer_t>);
    static_assert(generic::negatable::any_tr<const volatile integer_t>);

    static_assert(generic::negatable::integer_tr<integer_t>);
    static_assert(generic::negatable::integer_tr<const integer_t>);
    static_assert(generic::negatable::integer_tr<volatile integer_t>);
    static_assert(generic::negatable::integer_tr<const volatile integer_t>);

}}
