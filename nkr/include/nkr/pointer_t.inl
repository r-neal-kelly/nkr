/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t.h"

namespace nkr {

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::pointer_t() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(unit_t* unit_pointer) :
        units(unit_pointer),
        unit_count(unit_pointer ? 1 : 0)
    {
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(units_t units, count_t unit_count) :
        units(units),
        unit_count(unit_count)
    {
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(const pointer_t& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(pointer_t&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator =(const pointer_t& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator =(pointer_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::~pointer_t()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <sized_tr unit_p>
    inline typename pointer_t<unit_p>::units_t& pointer_t<unit_p>::Units()
    {
        return this->units;
    }

    template <sized_tr unit_p>
    inline typename const pointer_t<unit_p>::units_t& pointer_t<unit_p>::Units() const
    {
        return this->units;
    }

    template <sized_tr unit_p>
    inline count_t& pointer_t<unit_p>::Unit_Count()
    {
        return this->unit_count;
    }

    template <sized_tr unit_p>
    inline const count_t& pointer_t<unit_p>::Unit_Count() const
    {
        return this->unit_count;
    }

    template <sized_tr unit_p>
    inline address_t pointer_t<unit_p>::Address() const
    {
        return reinterpret_cast<address_t>(this->units);
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::operator bool_t()
    {
        return this->units != nullptr;
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::operator const bool_t() const
    {
        return const_cast<pointer_t*>(this)->operator bool_t();
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::operator units_t& ()
    {
        return this->units;
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>::operator const units_t& () const
    {
        return this->units;
    }

    template <sized_tr unit_p>
    inline const bool_t pointer_t<unit_p>::operator !() const
    {
        return !operator const bool_t();
    }

    template <sized_tr unit_p>
    inline typename pointer_t<unit_p>::units_t& pointer_t<unit_p>::operator ()()
    {
        return this->units;
    }

    template <sized_tr unit_p>
    inline typename const pointer_t<unit_p>::units_t& pointer_t<unit_p>::operator ()() const
    {
        return this->units;
    }

    template <sized_tr unit_p>
    inline typename const pointer_t<unit_p>::units_t& pointer_t<unit_p>::operator ->() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <sized_tr unit_p>
    inline typename pointer_t<unit_p>::unit_t& pointer_t<unit_p>::operator *() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <sized_tr unit_p>
    inline typename pointer_t<unit_p>::unit_t& pointer_t<unit_p>::operator [](index_t index) const
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator ++()
    {
        assert(this->units != nullptr);

        this->units += 1;
        this->unit_count -= 1;

        return *this;
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator ++(int)
    {
        assert(this->units != nullptr);

        pointer_t initial = *this;

        this->units += 1;
        this->unit_count -= 1;

        return initial; // rvo
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator --()
    {
        assert(this->units != nullptr);

        this->units -= 1;
        this->unit_count += 1;

        return *this;
    }

    template <sized_tr unit_p>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator --(int)
    {
        assert(this->units != nullptr);

        pointer_t initial = *this;

        this->units -= 1;
        this->unit_count += 1;

        return initial; // rvo
    }

    template <sized_tr unit_p>
    template <integral_tr integer>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator +=(integer count)
    {
        assert(this->units != nullptr);

        this->units += count;
        this->unit_count -= count;

        return *this;
    }

    template <sized_tr unit_p>
    template <integral_tr integer>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator -=(integer count)
    {
        assert(this->units != nullptr);

        this->units -= count;
        this->unit_count += count;

        return *this;
    }

    template <sized_tr unit_p>
    template <integral_tr integer>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator +(integer count) const
    {
        assert(this->units != nullptr);

        return pointer_t(this->units + count, this->unit_count - count);
    }

    template <sized_tr unit_p>
    template <integral_tr integer>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator -(integer count) const
    {
        assert(this->units != nullptr);

        return pointer_t(this->units - count, this->unit_count + count);
    }

}
