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

    struct  size_tg {};

    template <typename type_p>
    concept size_tr =
        cpp::is_any_tr<type_p, size_t> ||
        (cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

}}

namespace nkr { namespace interface {

    template <>
    class type_i<negatable::size_tg> :
        public type_i<negatable::size_t>
    {
    public:
    };

}}

#include "nkr/negatable/size_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(general::negatable_tr<size_t>);
    static_assert(general::negatable_tr<const size_t>);
    static_assert(general::negatable_tr<volatile size_t>);
    static_assert(general::negatable_tr<const volatile size_t>);

    static_assert(general::negatable::any_tr<size_t>);
    static_assert(general::negatable::any_tr<const size_t>);
    static_assert(general::negatable::any_tr<volatile size_t>);
    static_assert(general::negatable::any_tr<const volatile size_t>);

    static_assert(general::negatable::integer_tr<size_t>);
    static_assert(general::negatable::integer_tr<const size_t>);
    static_assert(general::negatable::integer_tr<volatile size_t>);
    static_assert(general::negatable::integer_tr<const volatile size_t>);

}}
