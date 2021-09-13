/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array_dynamic_t_dec.h"
#include "nkr/os.h"


namespace nkr {

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr real_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow_Rate()
    {
        static_assert(grow_rate_t::Numerator() >= 0, "numerator must be > 0");
        static_assert(grow_rate_t::Denominator() >= 0, "denominator must be > 0");

        constexpr real_t grow_rate = grow_rate_t::To_Decimal();
        static_assert(grow_rate >= 1.0, "grow_rate must be >= 1.0");

        return grow_rate;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy(const same_as_non_cv_tr<self_t> auto& from,
                                                                          same_as_non_cv_tr<self_t> auto& to)
    {
        assert(to.units == nullptr);
        assert(to.unit_count == 0);

        if (from.unit_count > 0) {
            if (to.allocator.Allocate(to.units, from.unit_count)) {
                for (index_t idx = 0, end = from.unit_count; idx < end; idx += 1) {
                    to.units[idx] = from.units[idx];
                }
                to.unit_count = from.unit_count;
            } else {
                assert(false);
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Destroy(same_as_non_cv_tr<self_t> auto& it)
    {
        it.Clear();
        it.allocator.Deallocate(it.units);
        it.units = nullptr;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t() :
        units(),
        unit_count(0),
        allocator()
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t(const array_dynamic_t& other) :
        units(),
        unit_count(0),
        allocator(other.allocator)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t(volatile const array_dynamic_t& other) :
        units(),
        unit_count(0),
        allocator(other.allocator)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t(array_dynamic_t&& other) noexcept :
        units(std::move(other.units)),
        unit_count(std::exchange(other.unit_count)),
        allocator(std::move(other.allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t(volatile array_dynamic_t&& other) noexcept :
        units(std::move(other.units)),
        unit_count(std::exchange(other.unit_count)),
        allocator(std::move(other.allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>& array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const array_dynamic_t& other)
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->allocator = other.allocator;
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile array_dynamic_t<unit_p, allocator_p, grow_rate_p>& array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(volatile const array_dynamic_t& other) volatile
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->allocator = other.allocator;
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>& array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(array_dynamic_t&& other) noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->units = std::move(other.units);
            this->unit_count = std::exchange(other.unit_count, 0);
            this->allocator = std::move(other.allocator);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile array_dynamic_t<unit_p, allocator_p, grow_rate_p>& array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(volatile array_dynamic_t&& other) volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->units = std::move(other.units);
            this->unit_count = std::exchange(other.unit_count, 0);
            this->allocator = std::move(other.allocator);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::~array_dynamic_t()
    {
        Destroy(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity() const
    {
        return this->units.unit_count;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
    {
        assert(new_capacity > this->allocator.Min_Unit_Count());
        assert(new_capacity <= this->allocator.Max_Unit_Count());

        if (this->units == nullptr) {
            return this->allocator.Allocate(this->units, new_capacity);
        } else {
            if (this->units.unit_count < new_capacity) {
                return this->allocator.Reallocate(this->units, new_capacity);
            } else {
                return true;
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Count() const
    {
        return this->unit_count;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t& array_dynamic_t<unit_p, allocator_p, grow_rate_p>::At(index_t index) const
    {
        assert(index < this->unit_count);

        return this->units[index];
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
    {
        if (Should_Grow()) {
            if (!Grow()) {
                return false;
            }
        }

        this->units[this->unit_count] = unit;
        this->unit_count += 1;

        return true;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(unit_t&& unit)
    {
        if (Should_Grow()) {
            if (!Grow()) {
                return false;
            }
        }

        this->units[this->unit_count] = std::move(unit);
        this->unit_count += 1;

        return true;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop()
    {
        assert(this->unit_count > 0);

        this->unit_count -= 1;
        return std::move(this->units[this->unit_count]);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit() const
    {
        return Count() == Capacity();
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
    {
        if (this->unit_count < this->units.unit_count) {
            return this->allocator.Reallocate(this->units, this->unit_count);
        } else {
            return true;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear() const
    {
        return this->unit_count == 0;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear()
    {
        for (index_t idx = 0, end = this->unit_count; idx < end; idx += 1) {
            this->units[idx].~unit_t();
        }
        this->unit_count = 0;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer() const
    {
        return this->units;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow() const
    {
        if (this->unit_count < this->allocator.Max_Unit_Count()) {
            return this->unit_count + 1 > Capacity();
        } else {
            return true;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow()
    {
        count_t capacity = Capacity();
        assert(capacity < this->allocator.Max_Unit_Count());

        if (os::math::Will_Overflow_Multiply(static_cast<real_t>(capacity), Grow_Rate())) {
            return Capacity(this->allocator.Max_Unit_Count());
        } else {
            count_t new_capacity = static_cast<count_t>(static_cast<real_t>(capacity) * Grow_Rate());
            if (new_capacity < this->allocator.Max_Unit_Count()) {
                new_capacity += 1;
            }
            return Capacity(new_capacity);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t& array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index) const
    {
        assert(index < this->unit_count);

        return this->units[index];
    }

}
