/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array_dynamic_t_dec.h"
#include "nkr/os.h"

namespace nkr {

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr real_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow_Rate()
    {
        static_assert(grow_rate_t::Numerator() >= 0, "numerator must be > 0");
        static_assert(grow_rate_t::Denominator() >= 0, "denominator must be > 0");

        constexpr real_t grow_rate = grow_rate_t::To_Decimal();
        static_assert(grow_rate >= 1.0, "grow_rate must be >= 1.0");

        return grow_rate;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <
        same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_1_p,
        same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_2_p
    > inline void_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy(const self_1_p& from, self_2_p& to)
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
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline void_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Destroy(self_p& it)
    {
        it.Clear();
        it.allocator.Deallocate(it.units);
        it.units = nullptr;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer(const self_p& self)
    {
        return self.units;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline count_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Count(const self_p& self)
    {
        return self.unit_count;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline typename const array_dynamic_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Allocator(const self_p& self)
    {
        return self.allocator;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline count_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(const self_p& self)
    {
        return self.units.unit_count;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(self_p& self, count_t new_capacity)
    {
        assert(new_capacity >= self.allocator.Min_Unit_Count());
        assert(new_capacity <= self.allocator.Max_Unit_Count());

        if (self.units == nullptr) {
            return self.allocator.Allocate(self.units, new_capacity);
        } else {
            if (self.units.unit_count < new_capacity) {
                return self.allocator.Reallocate(self.units, new_capacity);
            } else {
                return true;
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow(const self_p& self)
    {
        if (self.unit_count < self.allocator.Max_Unit_Count()) {
            return self.unit_count + 1 > self.Capacity();
        } else {
            return true;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow(self_p& self)
    {
        count_t capacity = self.Capacity();
        assert(capacity < self.allocator.Max_Unit_Count());

        if (os::math::Will_Overflow_Multiply(static_cast<real_t>(capacity), Grow_Rate())) {
            return self.Capacity(self.allocator.Max_Unit_Count());
        } else {
            count_t new_capacity = static_cast<count_t>(static_cast<real_t>(capacity) * Grow_Rate());
            if (new_capacity < self.allocator.Max_Unit_Count()) {
                new_capacity += 1;
            }
            return self.Capacity(new_capacity);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::At(const self_p& self, index_t index)
    {
        assert(index < self.unit_count);

        return self.units[index];
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(self_p& self, const unit_t& unit)
    {
        if (self.Should_Grow()) {
            if (!self.Grow()) {
                return false;
            }
        }

        self.units[self.unit_count] = unit;
        self.unit_count += 1;

        return true;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(self_p& self, unit_t&& unit)
    {
        if (self.Should_Grow()) {
            if (!self.Grow()) {
                return false;
            }
        }

        self.units[self.unit_count] = std::move(unit);
        self.unit_count += 1;

        return true;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop(self_p& self)
    {
        assert(self.unit_count > 0);

        self.unit_count -= 1;
        return std::move(self.units[self.unit_count]);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit(const self_p& self)
    {
        return self.Count() == self.Capacity();
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit(self_p& self)
    {
        if (self.unit_count < self.units.unit_count) {
            return self.allocator.Reallocate(self.units, self.unit_count);
        } else {
            return true;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear(const self_p& self)
    {
        return self.unit_count == 0;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    template <same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p>
    inline void_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear(self_p& self)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            self.units[idx].~unit_t();
        }
        self.unit_count = 0;
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
        unit_count(std::exchange(other.unit_count, 0)),
        allocator(std::move(other.allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>::array_dynamic_t(volatile array_dynamic_t&& other) noexcept :
        units(std::move(other.units)),
        unit_count(std::exchange(other.unit_count, 0)),
        allocator(std::move(other.allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const array_dynamic_t& other)
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->allocator = other.allocator;
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile array_dynamic_t<unit_p, allocator_p, grow_rate_p>&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(volatile const array_dynamic_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->allocator = other.allocator;
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline array_dynamic_t<unit_p, allocator_p, grow_rate_p>&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(array_dynamic_t&& other)
        noexcept
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
    inline volatile array_dynamic_t<unit_p, allocator_p, grow_rate_p>&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(volatile array_dynamic_t&& other)
        volatile noexcept
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
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer()
        const
    {
        return Pointer(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer()
        volatile const
    {
        return Pointer(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Count()
        const
    {
        return Count(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Count()
        volatile const
    {
        return Count(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const array_dynamic_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Allocator()
        const
    {
        return Allocator(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const array_dynamic_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Allocator()
        volatile const
    {
        return Allocator(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity()
        const
    {
        return Capacity(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity()
        volatile const
    {
        return Capacity(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
    {
        return Capacity(*this, new_capacity);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
        volatile
    {
        return Capacity(*this, new_capacity);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::At(index_t index)
        volatile const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
    {
        return Push(*this, unit);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
        volatile
    {
        return Push(*this, unit);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(unit_t&& unit)
    {
        return Push(*this, std::move(unit));
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(unit_t&& unit)
        volatile
    {
        return Push(*this, std::move(unit));
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop()
    {
        return Pop(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop()
        volatile
    {
        return Pop(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit()
        const
    {
        return Is_Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit()
        volatile const
    {
        return Is_Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
    {
        return Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
        volatile
    {
        return Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear()
        const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear()
        volatile const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear()
    {
        return Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow()
        const
    {
        return Should_Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow()
        volatile const
    {
        return Should_Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow()
    {
        return Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow()
        volatile
    {
        return Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename array_dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        array_dynamic_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index)
        volatile const
    {
        return At(*this, index);
    }

}
