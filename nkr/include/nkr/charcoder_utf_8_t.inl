/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/charcoder_utf_8_t.h"

namespace nkr { namespace charcoder {

    inline count_t utf_8_t::Unit_Count() const
    {
        return this->unit_count;
    }

    inline typename utf_8_t::unit_t utf_8_t::operator [](index_t index) const
    {
        assert(index < this->unit_count);

        return this->units[index];
    }

}}
