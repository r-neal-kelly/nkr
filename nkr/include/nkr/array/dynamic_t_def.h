/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/os.h"

#include "nkr/array/dynamic_t_dec.h"

namespace nkr {

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr real_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Grow_Rate()
    {
        static_assert(grow_rate_t::Numerator() >= 0, "numerator must be > 0");
        static_assert(grow_rate_t::Denominator() >= 0, "denominator must be > 0");

        constexpr real_t grow_rate = grow_rate_t::To_Decimal();
        static_assert(grow_rate >= 1.0, "grow_rate must be >= 1.0");

        return grow_rate;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Units(same_as_any_tr<dynamic_array_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;

        if constexpr (std::is_volatile_v<self_t> && std::is_const_v<self_t>) {
            return reinterpret_cast<volatile const pointer_t&>(self.writable_units);
        } else if constexpr (std::is_volatile_v<self_t>) {
            return reinterpret_cast<volatile pointer_t&>(self.writable_units);
        } else if constexpr (std::is_const_v<self_t>) {
            return reinterpret_cast<const pointer_t&>(self.writable_units);
        } else {
            return reinterpret_cast<pointer_t&>(self.writable_units);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Copy(const same_as_any_tr<dynamic_array_t> auto& from,
                                                                same_as_any_tr<dynamic_array_t> auto& to)
    {
        assert(to.writable_units == nullptr);
        assert(to.unit_count == 0);

        if (from.unit_count > 0) {
            if (to.allocator.Allocate(Units(to), from.unit_count)) {
                for (index_t idx = 0, end = from.unit_count; idx < end; idx += 1) {
                    to.writable_units[idx] = from.writable_units[idx];
                }
                to.unit_count = from.unit_count;
            } else {
                assert(false);
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Destroy(same_as_any_tr<dynamic_array_t> auto& self)
    {
        self.Clear();
        self.allocator.Deallocate(Units(self));
        self.writable_units = nullptr;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Pointer(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        return Units(self);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Count(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        return self.unit_count;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const dynamic_array_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Allocator(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        return self.allocator;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Capacity(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        return self.writable_units.unit_count;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Capacity(same_as_any_tr<dynamic_array_t> auto& self,
                                                                    count_t new_capacity)
    {
        assert(new_capacity >= self.allocator.Min_Unit_Count());
        assert(new_capacity <= self.allocator.Max_Unit_Count());

        // I think we can get away with just using Reallocate.

        if (self.writable_units == nullptr) {
            return self.allocator.Allocate(Units(self), new_capacity);
        } else {
            if (self.writable_units.unit_count < new_capacity) {
                return self.allocator.Reallocate(Units(self), new_capacity);
            } else {
                return true;
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Should_Grow(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        if (self.unit_count < self.allocator.Max_Unit_Count()) {
            return self.unit_count + 1 > self.Capacity();
        } else {
            return true;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Grow(same_as_any_tr<dynamic_array_t> auto& self)
    {
        count_t capacity = self.Capacity();
        if (capacity < self.allocator.Max_Unit_Count()) {
            if (os::math::Will_Overflow_Multiply(static_cast<real_t>(capacity), Grow_Rate())) {
                return self.Capacity(self.allocator.Max_Unit_Count());
            } else {
                count_t new_capacity = static_cast<count_t>(static_cast<real_t>(capacity) * Grow_Rate());
                if (new_capacity < self.allocator.Max_Unit_Count()) {
                    new_capacity += 1;
                } else {
                    new_capacity = self.allocator.Max_Unit_Count();
                }
                return self.Capacity(new_capacity);
            }
        } else {
            return false;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::At(const same_as_any_tr<dynamic_array_t> auto& self,
                                                              index_t index)
    {
        assert(index < self.unit_count);

        return Units(self)[index];
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Push(same_as_any_tr<dynamic_array_t> auto& self,
                                                                const unit_t& unit)
    {
        if (self.Should_Grow()) {
            if (!self.Grow()) {
                return false;
            }
        }

        self.writable_units[self.unit_count] = unit;
        self.unit_count += 1;

        return true;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Push(same_as_any_tr<dynamic_array_t> auto& self,
                                                                writable_unit_t&& unit)
    {
        if (self.Should_Grow()) {
            if (!self.Grow()) {
                return false;
            }
        }

        self.writable_units[self.unit_count] = std::move(unit);
        self.unit_count += 1;

        return true;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Pop(same_as_any_tr<dynamic_array_t> auto& self)
    {
        assert(self.unit_count > 0);

        self.unit_count -= 1;
        if constexpr (built_in_tr<unit_t>) {
            return std::exchange(self.writable_units[self.unit_count], std::remove_cv_t<unit_t>(0));
        } else {
            return std::move(self.writable_units[self.unit_count]);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Is_Fit(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        return self.Count() == self.Capacity();
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Fit(same_as_any_tr<dynamic_array_t> auto& self)
    {
        if (self.unit_count < self.writable_units.unit_count) {
            return self.allocator.Reallocate(Units(self), self.unit_count);
        } else {
            return true;
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Is_Clear(const same_as_any_tr<dynamic_array_t> auto& self)
    {
        return self.unit_count == 0;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Clear(same_as_any_tr<dynamic_array_t> auto& self)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            self.writable_units[idx].~unit_t();
        }
        self.unit_count = 0;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const allocator_t& allocator) :
        writable_units(),
        unit_count(0),
        allocator(allocator)
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(allocator_t&& allocator) :
        writable_units(),
        unit_count(0),
        allocator(std::move(allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(count_t capacity, const allocator_t& allocator) :
        dynamic_array_t(allocator)
    {
        if (capacity > 0) {
            Capacity(*this, capacity);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(count_t capacity, allocator_t&& allocator) :
        dynamic_array_t(std::move(allocator))
    {
        if (capacity > 0) {
            Capacity(*this, capacity);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const unit_t& filler,
                                                                              count_t count,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(count, allocator)
    {
        for (index_t idx = 0, end = count; idx < end; idx += 1) {
            Push(*this, filler);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const unit_t& filler,
                                                                              count_t count,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(count, std::move(allocator))
    {
        for (index_t idx = 0, end = count; idx < end; idx += 1) {
            Push(*this, filler);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(writable_unit_t&& filler,
                                                                              count_t count,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(count, allocator)
    {
        if (count > 0) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, std::exchange(filler, std::remove_cv_t<unit_t>(0)));
            } else {
                Push(*this, std::move(filler));
            }
            for (index_t idx = 0, end = count - 1; idx < end; idx += 1) {
                Push(*this, At(*this, 0));
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(writable_unit_t&& filler,
                                                                              count_t count,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(count, std::move(allocator))
    {
        if (count > 0) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, std::exchange(filler, std::remove_cv_t<unit_t>(0)));
            } else {
                Push(*this, std::move(filler));
            }
            for (index_t idx = 0, end = count - 1; idx < end; idx += 1) {
                Push(*this, At(*this, 0));
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const array_of_tr<writable_unit_t> auto& array,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(sizeof(array) / sizeof(unit_t), allocator)
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            Push(*this, array[idx]);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const array_of_tr<writable_unit_t> auto& array,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(sizeof(array) / sizeof(unit_t), std::move(allocator))
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            Push(*this, array[idx]);
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(array_of_tr<writable_unit_t> auto&& array,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(sizeof(array) / sizeof(unit_t), allocator)
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, std::exchange(array[idx], std::remove_cv_t<unit_t>(0)));
            } else {
                Push(*this, std::move(array[idx]));
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(array_of_tr<writable_unit_t> auto&& array,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(sizeof(array) / sizeof(unit_t), std::move(allocator))
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, std::exchange(array[idx], std::remove_cv_t<unit_t>(0)));
            } else {
                Push(*this, std::move(array[idx]));
            }
        }
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const stack_array_of_any_tr<unit_t> auto& stack_array,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(stack_array.Count(), allocator)
    {
        stack_array.Copy_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const stack_array_of_any_tr<unit_t> auto& stack_array,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(stack_array.Count(), std::move(allocator))
    {
        stack_array.Copy_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(stack_array_of_any_writable_tr<unit_t> auto&& stack_array,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(stack_array.Count(), allocator)
    {
        stack_array.Move_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(stack_array_of_any_writable_tr<unit_t> auto&& stack_array,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(stack_array.Count(), std::move(allocator))
    {
        stack_array.Move_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const instant_array_of_any_tr<unit_t> auto& instant_array,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(instant_array.Count(), allocator)
    {
        instant_array.Copy_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const instant_array_of_any_tr<unit_t> auto& instant_array,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(instant_array.Count(), std::move(allocator))
    {
        instant_array.Copy_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(instant_array_of_any_writable_tr<unit_t> auto&& instant_array,
                                                                              const allocator_t& allocator) :
        dynamic_array_t(instant_array.Count(), allocator)
    {
        instant_array.Move_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(instant_array_of_any_writable_tr<unit_t> auto&& instant_array,
                                                                              allocator_t&& allocator) :
        dynamic_array_t(instant_array.Count(), std::move(allocator))
    {
        instant_array.Move_Into(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(const dynamic_array_t& other) :
        writable_units(),
        unit_count(0),
        allocator(other.allocator)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(volatile const dynamic_array_t& other) :
        writable_units(),
        unit_count(0),
        allocator(other.allocator)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(dynamic_array_t&& other) noexcept :
        writable_units(std::move(other.writable_units)),
        unit_count(std::exchange(other.unit_count, 0)),
        allocator(std::move(other.allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::dynamic_array_t(volatile dynamic_array_t&& other) noexcept :
        writable_units(std::move(other.writable_units)),
        unit_count(std::exchange(other.unit_count, 0)),
        allocator(std::move(other.allocator))
    {
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::operator =(const dynamic_array_t& other)
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->allocator = other.allocator;
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_array_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::operator =(volatile const dynamic_array_t& other)
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
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::operator =(dynamic_array_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->writable_units = std::move(other.writable_units);
            this->unit_count = std::exchange(other.unit_count, 0);
            this->allocator = std::move(other.allocator);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_array_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::operator =(volatile dynamic_array_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            this->writable_units = std::move(other.writable_units);
            this->unit_count = std::exchange(other.unit_count, 0);
            this->allocator = std::move(other.allocator);
        }
        return *this;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_array_t<unit_p, allocator_p, grow_rate_p>::~dynamic_array_t()
    {
        Destroy(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Pointer()
        const
    {
        return Pointer(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Pointer()
        volatile const
    {
        return Pointer(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Count()
        const
    {
        return Count(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Count()
        volatile const
    {
        return Count(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const dynamic_array_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Allocator()
        const
    {
        return Allocator(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const dynamic_array_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Allocator()
        volatile const
    {
        return Allocator(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Capacity()
        const
    {
        return Capacity(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Capacity()
        volatile const
    {
        return Capacity(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
    {
        return Capacity(*this, new_capacity);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
        volatile
    {
        return Capacity(*this, new_capacity);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::At(index_t index)
        volatile const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
    {
        return Push(*this, unit);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
        volatile
    {
        return Push(*this, unit);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Push(writable_unit_t&& unit)
    {
        return Push(*this, std::move(unit));
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Push(writable_unit_t&& unit)
        volatile
    {
        return Push(*this, std::move(unit));
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Pop()
    {
        return Pop(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Pop()
        volatile
    {
        return Pop(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Is_Fit()
        const
    {
        return Is_Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Is_Fit()
        volatile const
    {
        return Is_Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Fit()
    {
        return Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Fit()
        volatile
    {
        return Fit(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Is_Clear()
        const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Is_Clear()
        volatile const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Clear()
    {
        return Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Should_Grow()
        const
    {
        return Should_Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Should_Grow()
        volatile const
    {
        return Should_Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Grow()
    {
        return Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::Grow()
        volatile
    {
        return Grow(*this);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_array_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index)
        volatile const
    {
        return At(*this, index);
    }

}
