/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/negatable/integer_t_dec.h"

#include "nkr/generic/negatable_tr_dec.h"
#include "nkr/generic/negatable/any_tr_dec.h"
#include "nkr/generic/negatable/integer_tr_dec.h"

namespace nkr { namespace negatable {

    using   size_t =
        nkr::cpp::negatable::size_t;

    struct  size_tg {};

    template <typename type_p>
    concept size_tr =
        nkr::cpp::is_any_tr<type_p, size_t> ||
        (nkr::cpp::negatable_integer_tr<type_p> && sizeof(type_p) == sizeof(size_t));

    template <size_t value_p>
    using   size_c =
        nkr::cpp::constant_t<size_t, value_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::negatable::size_tg> :
        public type_i<nkr::negatable::size_t>
    {
    public:
        using type_t    = nkr::negatable::size_tg;
    };

}}

#include "nkr/negatable/size_t_dec_def.h"

namespace nkr { namespace negatable {

    static_assert(generic::negatable_tr<size_t>);
    static_assert(generic::negatable_tr<const size_t>);
    static_assert(generic::negatable_tr<volatile size_t>);
    static_assert(generic::negatable_tr<const volatile size_t>);

    static_assert(generic::negatable::any_tr<size_t>);
    static_assert(generic::negatable::any_tr<const size_t>);
    static_assert(generic::negatable::any_tr<volatile size_t>);
    static_assert(generic::negatable::any_tr<const volatile size_t>);

    static_assert(generic::negatable::integer_tr<size_t>);
    static_assert(generic::negatable::integer_tr<const size_t>);
    static_assert(generic::negatable::integer_tr<volatile size_t>);
    static_assert(generic::negatable::integer_tr<const volatile size_t>);

}}
