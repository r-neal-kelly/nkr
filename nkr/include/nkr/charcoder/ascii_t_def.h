/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/utils.h"

#include "nkr/charcoder/ascii_t_dec.h"

namespace nkr { namespace charcoder {

    inline ascii_t::ascii_t()
    {
        this->unit = 0;
    }

    inline ascii_t::ascii_t(const ascii_t& other)
    {
        this->unit = other.unit;
    }

    inline ascii_t::ascii_t(const volatile ascii_t& other)
    {
        this->unit = other.unit;
    }

    inline ascii_t::ascii_t(ascii_t&& other) noexcept
    {
        this->unit = nkr::Move(other.unit);
    }

    inline ascii_t::ascii_t(volatile ascii_t&& other) noexcept
    {
        this->unit = nkr::Move(other.unit);
    }

    inline ascii_t&
        ascii_t::operator =(const ascii_t& other)
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline volatile ascii_t&
        ascii_t::operator =(const ascii_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline ascii_t&
        ascii_t::operator =(const volatile ascii_t& other)
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline volatile ascii_t&
        ascii_t::operator =(const volatile ascii_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->unit = other.unit;
        }
        return *this;
    }

    inline ascii_t&
        ascii_t::operator =(ascii_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = nkr::Move(other.unit);
        }
        return *this;
    }

    inline volatile ascii_t&
        ascii_t::operator =(ascii_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = nkr::Move(other.unit);
        }
        return *this;
    }

    inline ascii_t&
        ascii_t::operator =(is_just_volatile_tr<ascii_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = nkr::Move(other.unit);
        }
        return *this;
    }

    inline volatile ascii_t&
        ascii_t::operator =(is_just_volatile_tr<ascii_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->unit = nkr::Move(other.unit);
        }
        return *this;
    }

    inline ascii_t::~ascii_t()
    {
        this->unit = 0;
    }

    inline bool_t
        ascii_t::Is_Well_Formed()
        const
    {
        return this->unit > -1;
    }

    inline void_t
        ascii_t::Encode(point_t point)
    {
        this->unit = point > 127 ? '?' : static_cast<unit_t>(point);

        nkr_ASSERT_THAT(Is_Well_Formed());
    }

    inline point_t
        ascii_t::Decode()
        const
    {
        nkr_ASSERT_THAT(Is_Well_Formed());

        return static_cast<point_t>(this->unit);
    }

    inline count_t
        ascii_t::Read_Forward(const unit_t* from)
    {
        nkr_ASSERT_THAT(from);

        Encode(*from);

        return 1;
    }

    inline count_t
        ascii_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        Encode(*(from - 1));

        return 1;
    }

    inline count_t
        ascii_t::Unit_Count()
        const
    {
        return 1;
    }

    inline typename ascii_t::unit_t
        ascii_t::operator [](index_t index)
        const
    {
        nkr_ASSERT_THAT(index < 1);

        return this->unit;
    }

    inline ascii_t::ascii_t(none_t) :
        ascii_t()
    {
    }

    inline ascii_t&
        ascii_t::operator =(none_t)
    {
        this->unit = 0;
        return *this;
    }

    inline volatile ascii_t&
        ascii_t::operator =(none_t)
        volatile
    {
        this->unit = 0;
        return *this;
    }

    inline bool_t
        ascii_t::operator ==(none_t)
        const
    {
        return this->unit == 0;
    }

    inline bool_t
        ascii_t::operator ==(none_t)
        const volatile
    {
        return this->unit == 0;
    }

    inline bool_t
        ascii_t::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    inline bool_t
        ascii_t::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}
