/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t.h"

namespace nkr {

    template <type_tr unit_p>
    inline pointer_t<unit_p>::pointer_t() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(unit_t* unit) :
        units(unit),
        unit_count(unit ? 1 : 0)
    {
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(units_t units, count_t unit_count) :
        units(units),
        unit_count(unit_count)
    {
        assert(units || unit_count > 0 ? units && unit_count > 0 : true);
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(const pointer_t& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>::pointer_t(pointer_t&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator =(unit_t* unit)
    {
        this->units = unit;
        this->unit_count = unit ? 1 : 0;

        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator =(const pointer_t& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator =(pointer_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>::~pointer_t()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <type_tr unit_p>
    inline typename pointer_t<unit_p>::units_t pointer_t<unit_p>::Units() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline count_t pointer_t<unit_p>::Unit_Count() volatile const
    {
        return this->unit_count;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>::operator units_t () volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename pointer_t<unit_p>::units_t pointer_t<unit_p>::operator ()() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator ()(unit_t* unit)
    {
        this->units = unit;
        this->unit_count = unit ? 1 : 0;

        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator()(units_t units, count_t unit_count){
        assert(units || unit_count > 0 ? units && unit_count > 0 : true);

        this->units = units;
        this->unit_count = unit_count;

        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator +(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        return pointer_t<unit_p>(this->unit + amount, this->unit_count - amount);
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator -(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        return pointer_t<unit_p>(this->unit - amount, this->unit_count + amount);
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator +=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator -=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator ++()
    {
        assert(this->units != nullptr);

        return operator +(1);
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator ++(int)
    {
        assert(this->units != nullptr);

        pointer_t initial = *this;
        operator +(1);

        return initial;
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p>& pointer_t<unit_p>::operator --()
    {
        assert(this->units != nullptr);

        return operator -(1);
    }

    template <type_tr unit_p>
    inline pointer_t<unit_p> pointer_t<unit_p>::operator --(int)
    {
        assert(this->units != nullptr);

        pointer_t initial = *this;
        operator -(1);

        return initial;
    }

    template <type_tr unit_p>
    inline typename pointer_t<unit_p>::units_t pointer_t<unit_p>::operator ->() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <type_tr unit_p>
    inline typename pointer_t<unit_p>::unit_t& pointer_t<unit_p>::operator *() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <type_tr unit_p>
    inline typename pointer_t<unit_p>::unit_t& pointer_t<unit_p>::operator [](index_t index) const
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

}
