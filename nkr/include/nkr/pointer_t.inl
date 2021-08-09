/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t.h"

namespace nkr {

    template <trait::sized unit>
    inline pointer_t<unit>::pointer_t() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <trait::sized unit>
    inline pointer_t<unit>::pointer_t(unit_t* unit_pointer) :
        units(unit_pointer),
        unit_count(unit_pointer ? 1 : 0)
    {
    }

    template <trait::sized unit>
    inline pointer_t<unit>::pointer_t(units_t units, count_t unit_count) :
        units(units),
        unit_count(unit_count)
    {
    }

    template <trait::sized unit>
    inline pointer_t<unit>::pointer_t(const pointer_t& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <trait::sized unit>
    inline pointer_t<unit>::pointer_t(pointer_t&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <trait::sized unit>
    inline pointer_t<unit>& pointer_t<unit>::operator =(const pointer_t& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <trait::sized unit>
    inline pointer_t<unit>& pointer_t<unit>::operator =(pointer_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <trait::sized unit>
    inline pointer_t<unit>::~pointer_t()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <trait::sized unit>
    inline typename pointer_t<unit>::units_t& pointer_t<unit>::raw()
    {
        return this->units;
    }

    template <trait::sized unit>
    inline typename const pointer_t<unit>::units_t& pointer_t<unit>::raw() const
    {
        return this->units;
    }

    template <trait::sized unit>
    inline count_t& pointer_t<unit>::count()
    {
        return this->unit_count;
    }

    template <trait::sized unit>
    inline const count_t& pointer_t<unit>::count() const
    {
        return this->unit_count;
    }

    template <trait::sized unit>
    inline address_t pointer_t<unit>::address() const
    {
        return reinterpret_cast<address_t>(this->units);
    }

    template <trait::sized unit>
    inline pointer_t<unit>::operator bool_t()
    {
        return this->units != nullptr;
    }

    template <trait::sized unit>
    inline pointer_t<unit>::operator const bool_t() const
    {
        return const_cast<pointer_t*>(this)->operator bool_t();
    }

    template <trait::sized unit>
    inline pointer_t<unit>::operator units_t& ()
    {
        return this->units;
    }

    template <trait::sized unit>
    inline pointer_t<unit>::operator const units_t& () const
    {
        return this->units;
    }

    template <trait::sized unit>
    inline const bool_t pointer_t<unit>::operator !() const
    {
        return !operator const bool_t();
    }

    template <trait::sized unit>
    inline typename pointer_t<unit>::units_t& pointer_t<unit>::operator ()()
    {
        return this->units;
    }

    template <trait::sized unit>
    inline typename const pointer_t<unit>::units_t& pointer_t<unit>::operator ()() const
    {
        return this->units;
    }

    template <trait::sized unit>
    inline typename const pointer_t<unit>::units_t& pointer_t<unit>::operator ->() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <trait::sized unit>
    inline typename pointer_t<unit>::unit_t& pointer_t<unit>::operator *() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <trait::sized unit>
    inline typename pointer_t<unit>::unit_t& pointer_t<unit>::operator [](index_t index) const
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <trait::sized unit>
    inline pointer_t<unit>& pointer_t<unit>::operator ++()
    {
        assert(this->units != nullptr);

        this->units += 1;
        this->unit_count -= 1;

        return *this;
    }

    template <trait::sized unit>
    inline pointer_t<unit> pointer_t<unit>::operator ++(int)
    {
        assert(this->units != nullptr);

        pointer_t initial = *this;

        this->units += 1;
        this->unit_count -= 1;

        return initial; // rvo
    }

    template <trait::sized unit>
    inline pointer_t<unit>& pointer_t<unit>::operator --()
    {
        assert(this->units != nullptr);

        this->units -= 1;
        this->unit_count += 1;

        return *this;
    }

    template <trait::sized unit>
    inline pointer_t<unit> pointer_t<unit>::operator --(int)
    {
        assert(this->units != nullptr);

        pointer_t initial = *this;

        this->units -= 1;
        this->unit_count += 1;

        return initial; // rvo
    }

    template <trait::sized unit>
    template <trait::integral integer>
    inline pointer_t<unit>& pointer_t<unit>::operator +=(integer count)
    {
        assert(this->units != nullptr);

        this->units += count;
        this->unit_count -= count;

        return *this;
    }

    template <trait::sized unit>
    template <trait::integral integer>
    inline pointer_t<unit>& pointer_t<unit>::operator -=(integer count)
    {
        assert(this->units != nullptr);

        this->units -= count;
        this->unit_count += count;

        return *this;
    }

    template <trait::sized unit>
    template <trait::integral integer>
    inline pointer_t<unit> pointer_t<unit>::operator +(integer count) const
    {
        assert(this->units != nullptr);

        return pointer_t(this->units + count, this->unit_count - count);
    }

    template <trait::sized unit>
    template <trait::integral integer>
    inline pointer_t<unit> pointer_t<unit>::operator -(integer count) const
    {
        assert(this->units != nullptr);

        return pointer_t(this->units - count, this->unit_count + count);
    }

}
