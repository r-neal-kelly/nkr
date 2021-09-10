/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/pointer_t.h"

namespace nkr { namespace $pointer_t {

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(convertible_tr<unit_t*> auto unit) :
        units(static_cast<unit_t*>(unit)),
        unit_count(unit ? 1 : 0)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(convertible_tr<unit_t*> auto units, count_t unit_count) :
        units(static_cast<unit_t*>(units)),
        unit_count(unit_count)
    {
        assert(units || unit_count > 0 ? units && unit_count > 0 : true);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(const type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::type_sp(type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator =(convertible_tr<unit_t*> auto unit)
    {
        this->units = static_cast<unit_t*>(unit);
        this->unit_count = unit ? 1 : 0;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator =(const type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator =(type_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::~type_sp()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* type_sp<unit_p>::Units() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline count_t type_sp<unit_p>::Unit_Count() volatile const
    {
        return this->unit_count;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>::operator type_sp<unit_p>::unit_t*() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* type_sp<unit_p>::operator ()() volatile const
    {
        return this->units;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        this->units = static_cast<unit_t*>(unit);
        this->unit_count = unit ? 1 : 0;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto units, count_t unit_count)
    {
        assert(units || unit_count > 0 ? units && unit_count > 0 : true);

        this->units = static_cast<unit_t*>(units);
        this->unit_count = unit_count;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator +(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        return type_sp<unit_p>(this->unit + amount, this->unit_count - amount);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator -(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        return type_sp<unit_p>(this->unit - amount, this->unit_count + amount);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator +=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units += amount;
        this->unit_count -= amount;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator -=(integer_tr auto amount)
    {
        assert(this->units != nullptr);

        this->units -= amount;
        this->unit_count += amount;

        return *this;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator ++()
    {
        assert(this->units != nullptr);

        return operator +(1);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator ++(int)
    {
        assert(this->units != nullptr);

        type_sp initial = *this;
        operator +(1);

        return initial;
    }

    template <type_tr unit_p>
    inline type_sp<unit_p>& type_sp<unit_p>::operator --()
    {
        assert(this->units != nullptr);

        return operator -(1);
    }

    template <type_tr unit_p>
    inline type_sp<unit_p> type_sp<unit_p>::operator --(int)
    {
        assert(this->units != nullptr);

        type_sp initial = *this;
        operator -(1);

        return initial;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t* type_sp<unit_p>::operator ->() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t& type_sp<unit_p>::operator *() const
    {
        assert(this->units != nullptr);
        assert(this->unit_count > 0);

        return *this->units;
    }

    template <type_tr unit_p>
    inline typename type_sp<unit_p>::unit_t& type_sp<unit_p>::operator [](index_t index) const
    {
        assert(this->units != nullptr);
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp() :
        units(nullptr),
        unit_count(0)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(convertible_tr<unit_t*> auto unit) :
        units(static_cast<unit_t*>(unit)),
        unit_count(unit ? 1 : 0)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(convertible_tr<unit_t*> auto units, count_t unit_count) :
        units(static_cast<unit_t*>(units)),
        unit_count(unit_count)
    {
        assert(units || unit_count > 0 ? units && unit_count > 0 : true);
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(const non_type_sp& other) :
        units(other.units),
        unit_count(other.unit_count)
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::non_type_sp(non_type_sp&& other) noexcept :
        units(std::exchange(other.units, nullptr)),
        unit_count(std::exchange(other.unit_count, 0))
    {
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(convertible_tr<unit_t*> auto unit)
    {
        this->units = static_cast<unit_t*>(unit);
        this->unit_count = unit ? 1 : 0;

        return *this;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(const non_type_sp& other)
    {
        if (this != std::addressof(other)) {
            this->units = other.units;
            this->unit_count = other.unit_count;
        }
        return *this;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator =(non_type_sp&& other) noexcept
    {
        if (this != std::addressof(other)) {
            this->units = std::exchange(other.units, nullptr);
            this->unit_count = std::exchange(other.unit_count, 0);
        }
        return *this;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::~non_type_sp()
    {
        this->units = nullptr;
        this->unit_count = 0;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::unit_t* non_type_sp<unit_p>::Units() volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline count_t non_type_sp<unit_p>::Unit_Count() volatile const
    {
        return this->unit_count;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>::operator non_type_sp<unit_p>::unit_t*() volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline typename non_type_sp<unit_p>::unit_t* non_type_sp<unit_p>::operator ()() volatile const
    {
        return this->units;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto unit)
    {
        this->units = static_cast<unit_t*>(unit);
        this->unit_count = unit ? 1 : 0;

        return *this;
    }

    template <non_type_tr unit_p>
    inline non_type_sp<unit_p>& non_type_sp<unit_p>::operator ()(convertible_tr<unit_t*> auto units, count_t unit_count)
    {
        assert(units || unit_count > 0 ? units && unit_count > 0 : true);

        this->units = static_cast<unit_t*>(units);
        this->unit_count = unit_count;

        return *this;
    }

}}
