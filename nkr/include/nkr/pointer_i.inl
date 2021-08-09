/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_i.h"

namespace nkr {

    template <sized_t unit>
    inline pointer_i<unit>::pointer_i() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <sized_t unit>
    inline pointer_i<unit>::pointer_i(unit_t* unit_pointer) :
        units(unit_pointer),
        unit_count(unit_pointer ? 1 : 0)
    {
    }

    template <sized_t unit>
    inline pointer_i<unit>::pointer_i(units_t units, count_t unit_count) :
        units(units),
        unit_count(unit_count)
    {
    }

    template <sized_t unit>
    inline pointer_i<unit>::pointer_i(const pointer_i& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <sized_t unit>
    inline pointer_i<unit>::pointer_i(pointer_i&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <sized_t unit>
    inline pointer_i<unit>& pointer_i<unit>::operator =(const pointer_i& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <sized_t unit>
    inline pointer_i<unit>& pointer_i<unit>::operator =(pointer_i&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <sized_t unit>
    inline pointer_i<unit>::~pointer_i()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <sized_t unit>
    inline pointer_i<unit>::operator bool_t()
    {
        return this->units != nullptr;
    }

    template <sized_t unit>
    inline pointer_i<unit>::operator const bool_t() const
    {
        return const_cast<pointer_i*>(this)->operator bool_t();
    }

    template <sized_t unit>
    inline pointer_i<unit>::operator units_t& ()
    {
        return this->units;
    }

    template <sized_t unit>
    inline pointer_i<unit>::operator const units_t& () const
    {
        return this->units;
    }

    template <sized_t unit>
    inline pointer_i<unit>::operator count_t& ()
    {
        return this->unit_count;
    }

    template <sized_t unit>
    inline pointer_i<unit>::operator const count_t& () const
    {
        return this->unit_count;
    }

    template <sized_t unit>
    inline const bool_t pointer_i<unit>::operator !() const
    {
        return !operator const bool_t();
    }

    template <sized_t unit>
    inline typename pointer_i<unit>::units_t& pointer_i<unit>::operator ()()
    {
        return this->units;
    }

    template <sized_t unit>
    inline typename const pointer_i<unit>::units_t& pointer_i<unit>::operator ()() const
    {
        return this->units;
    }

    template <sized_t unit>
    inline typename const pointer_i<unit>::units_t& pointer_i<unit>::operator ->() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <sized_t unit>
    inline typename pointer_i<unit>::unit_t& pointer_i<unit>::operator *() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <sized_t unit>
    inline typename pointer_i<unit>::unit_t& pointer_i<unit>::operator [](index_t index) const
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <sized_t unit>
    inline pointer_i<unit>& pointer_i<unit>::operator ++()
    {
        assert(this->units != nullptr);

        this->units += 1;
        this->unit_count -= 1;

        return *this;
    }

    template <sized_t unit>
    inline pointer_i<unit> pointer_i<unit>::operator ++(int)
    {
        assert(this->units != nullptr);

        pointer_i initial = *this;

        this->units += 1;
        this->unit_count -= 1;

        return std::move(initial);
    }

    template <sized_t unit>
    inline pointer_i<unit>& pointer_i<unit>::operator --()
    {
        assert(this->units != nullptr);

        this->units -= 1;
        this->unit_count += 1;

        return *this;
    }

    template <sized_t unit>
    inline pointer_i<unit> pointer_i<unit>::operator --(int)
    {
        assert(this->units != nullptr);

        pointer_i initial = *this;

        this->units -= 1;
        this->unit_count += 1;

        return std::move(initial);
    }

    template <sized_t unit>
    template <integral_t integer>
    inline pointer_i<unit>& pointer_i<unit>::operator +=(integer count)
    {
        assert(this->units != nullptr);

        this->units += count;
        this->unit_count -= count;

        return *this;
    }

    template <sized_t unit>
    template <integral_t integer>
    inline pointer_i<unit>& pointer_i<unit>::operator -=(integer count)
    {
        assert(this->units != nullptr);

        this->units -= count;
        this->unit_count += count;

        return *this;
    }

    template <sized_t unit>
    template <integral_t integer>
    inline pointer_i<unit> pointer_i<unit>::operator +(integer count) const
    {
        assert(this->units != nullptr);

        return pointer_i(this->units + count, this->unit_count - count);
    }

    template <sized_t unit>
    template <integral_t integer>
    inline pointer_i<unit> pointer_i<unit>::operator -(integer count) const
    {
        assert(this->units != nullptr);

        return pointer_i(this->units - count, this->unit_count + count);
    }

    template <sized_t unit>
    inline typename pointer_i<unit>::units_t& pointer_i<unit>::pointer()
    {
        return this->units;
    }

    template <sized_t unit>
    inline typename const pointer_i<unit>::units_t& pointer_i<unit>::pointer() const
    {
        return this->units;
    }

    template <sized_t unit>
    inline count_t& pointer_i<unit>::count()
    {
        return this->unit_count;
    }

    template <sized_t unit>
    inline const count_t& pointer_i<unit>::count() const
    {
        return this->unit_count;
    }

    template <sized_t unit>
    inline address_t pointer_i<unit>::address() const
    {
        return reinterpret_cast<address_t>(this->units);
    }

}
