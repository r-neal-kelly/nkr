/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/general/negatable_tr_dec.h"
#include "nkr/general/negatable/any_tr_dec.h"
#include "nkr/general/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    struct  index_tg    {};

    template <typename type_p>
    concept index_tr =
        cpp::is_any_tr<type_p, index_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(index_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::index_tg> :
        public type_i<negatable::index_t>
    {
    public:
    };

}}

#include "nkr/negatable/index_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(general::negatable_tr<index_t>);
    static_assert(general::negatable_tr<const index_t>);
    static_assert(general::negatable_tr<volatile index_t>);
    static_assert(general::negatable_tr<const volatile index_t>);

    static_assert(general::negatable::any_tr<index_t>);
    static_assert(general::negatable::any_tr<const index_t>);
    static_assert(general::negatable::any_tr<volatile index_t>);
    static_assert(general::negatable::any_tr<const volatile index_t>);

    static_assert(general::negatable::integer_tr<index_t>);
    static_assert(general::negatable::integer_tr<const index_t>);
    static_assert(general::negatable::integer_tr<volatile index_t>);
    static_assert(general::negatable::integer_tr<const volatile index_t>);

}}