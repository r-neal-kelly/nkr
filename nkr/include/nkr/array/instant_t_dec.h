/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "nkr/array_i.h"
#include "nkr/array/stack_t.h"

namespace nkr { namespace array {

    template <any_non_const_tr head_p, is_tr<head_p> ...tail_p>
    class instant_t;

    template <typename type_p>
    concept any_instant_tr =
        type_p::Is_Instant_Array();

    nkr_DEFINE_CONTAINER_TRAITS(instant, unit_t);

}}

namespace nkr { namespace array {

    template <any_non_const_tr head_p, is_tr<head_p> ...tail_p>
    class instant_t :
        public stack_t<head_p, 1 + sizeof...(tail_p)>
    {
    public:
        using base_t    = stack_t<head_p, 1 + sizeof...(tail_p)>;

    public:
        static constexpr std_bool_t Is_Instant_Array();

    public:
        instant_t(head_p&& head, tail_p&& ...tail);
    };
    static_assert(array_i<instant_t<word_t>>);
    static_assert(array_i<instant_t<volatile word_t>>);
    static_assert(array_i<const instant_t<word_t>>);
    static_assert(array_i<const instant_t<volatile word_t>>);
    static_assert(array_i<volatile instant_t<word_t>>);
    static_assert(array_i<volatile instant_t<volatile word_t>>);
    static_assert(array_i<const volatile instant_t<word_t>>);
    static_assert(array_i<const volatile instant_t<volatile word_t>>);

}}
