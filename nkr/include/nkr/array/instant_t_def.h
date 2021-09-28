/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/array/instant_t_dec.h"

namespace nkr { namespace array {

    template <any_non_const_tr head_p, is_tr<head_p> ...tail_p>
    constexpr std_bool_t instant_t<head_p, tail_p...>::Is_Instant_Array()
    {
        return true;
    }

    template <any_non_const_tr head_p, is_tr<head_p> ...tail_p>
    instant_t<head_p, tail_p...>::instant_t(head_p&& head, tail_p&&... tail) :
        base_t(nkr::Move(head), nkr::Move(tail)...)
    {
    }

}}
