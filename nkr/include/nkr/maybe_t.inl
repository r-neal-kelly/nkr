/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/maybe_t.h"

namespace nkr {

    inline none_t::none_t() :
        none(0)
    {
    }

    template <maybe_i any_p>
    inline maybe_t<any_p>::operator bool_t() const
    {
        return value_t::operator !=(none_t());
    }

    template <maybe_i any_p>
    inline maybe_t<any_p>& maybe_t<any_p>::operator =(none_t)
    {
        return value_t::operator =(none_t());
    }

    template <maybe_i any_p>
    inline bool_t maybe_t<any_p>::operator ==(none_t) const
    {
        return value_t::operator ==(none_t());
    }

    template <maybe_i any_p>
    inline bool_t maybe_t<any_p>::operator !=(none_t) const
    {
        return value_t::operator !=(none_t());
    }

}
