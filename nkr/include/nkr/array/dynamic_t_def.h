/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/os.h"
#include "nkr/utils.h"

#include "nkr/array/dynamic_t_dec.h"

namespace nkr { namespace array {

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr real_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow_Rate()
    {
        static_assert(grow_rate_t::Numerator() >= 0, "numerator must be > 0");
        static_assert(grow_rate_t::Denominator() >= 0, "denominator must be > 0");

        constexpr real_t grow_rate = grow_rate_t::To_Decimal();
        static_assert(grow_rate >= 1.0, "grow_rate must be >= 1.0");

        return grow_rate;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Units(is_any_tr<dynamic_t> auto& self)
    {
        using self_t = std::remove_reference_t<decltype(self)>;

        if constexpr (just_const_tr<self_t>) {
            return reinterpret_cast<const pointer_t&>(self.writable_units);
        } else if constexpr (just_volatile_tr<self_t>) {
            return reinterpret_cast<volatile pointer_t&>(self.writable_units);
        } else if constexpr (just_const_volatile_tr<self_t>) {
            return reinterpret_cast<const volatile pointer_t&>(self.writable_units);
        } else {
            return reinterpret_cast<pointer_t&>(self.writable_units);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_Construct(is_any_non_const_tr<dynamic_t> auto& self,
                                                                    const is_any_tr<dynamic_t> auto& other)
    {
        assert(self.writable_units == nullptr);
        assert(self.unit_count == 0);

        if (other.unit_count > 0) {
            if (self.allocator.Allocate(Units(self), other.unit_count)) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    self.writable_units[idx] = other.writable_units[idx];
                }
                self.unit_count = other.unit_count;
            } else {
                assert(false);
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Destruct(is_any_tr<dynamic_t> auto& self)
    {
        self.Clear();
        self.allocator.Deallocate(Units(self));
        self.writable_units = nullptr;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer(const is_any_tr<dynamic_t> auto& self)
    {
        return self.writable_units;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Count(const is_any_tr<dynamic_t> auto& self)
    {
        return self.unit_count;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline auto&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Allocator(const is_any_tr<dynamic_t> auto& self)
    {
        return self.allocator;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(const is_any_tr<dynamic_t> auto& self)
    {
        return self.writable_units.unit_count;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(is_any_tr<dynamic_t> auto& self, count_t new_capacity)
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

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow(const is_any_tr<dynamic_t> auto& self)
    {
        if (self.unit_count < self.allocator.Max_Unit_Count()) {
            return self.unit_count + 1 > self.Capacity();
        } else {
            return true;
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow(is_any_tr<dynamic_t> auto& self)
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

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::At(const is_any_tr<dynamic_t> auto& self, index_t index)
    {
        assert(index < self.unit_count);

        return self.writable_units[index];
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const unit_t& unit)
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

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, writable_unit_t&& unit)
    {
        if (self.Should_Grow()) {
            if (!self.Grow()) {
                return false;
            }
        }

        self.writable_units[self.unit_count] = nkr::Move(unit);
        self.unit_count += 1;

        return true;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop(is_any_tr<dynamic_t> auto& self)
    {
        assert(self.unit_count > 0);

        self.unit_count -= 1;
        if constexpr (built_in_tr<unit_t>) {
            return nkr::Move(self.writable_units[self.unit_count]);
        } else {
            return nkr::Move(self.writable_units[self.unit_count]);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit(const is_any_tr<dynamic_t> auto& self)
    {
        return self.Count() == self.Capacity();
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit(is_any_tr<dynamic_t> auto& self)
    {
        if (self.unit_count < self.writable_units.unit_count) {
            return self.allocator.Reallocate(Units(self), self.unit_count);
        } else {
            return true;
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear(const is_any_tr<dynamic_t> auto& self)
    {
        return self.unit_count == 0;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear(is_any_tr<dynamic_t> auto& self)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                self.writable_units[idx] = std::remove_cv_t<unit_t>(0);
            } else {
                self.writable_units[idx].~unit_t();
            }
        }
        self.unit_count = 0;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const allocator_t& allocator) :
        writable_units(),
        unit_count(0),
        allocator(allocator)
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(allocator_t&& allocator) :
        writable_units(),
        unit_count(0),
        allocator(nkr::Move(allocator))
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(count_t capacity, const allocator_t& allocator) :
        dynamic_t(allocator)
    {
        if (capacity > 0) {
            Capacity(*this, capacity);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(count_t capacity, allocator_t&& allocator) :
        dynamic_t(nkr::Move(allocator))
    {
        if (capacity > 0) {
            Capacity(*this, capacity);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const unit_t& filler,
                                                                  count_t count,
                                                                  const allocator_t& allocator) :
        dynamic_t(count, allocator)
    {
        for (index_t idx = 0, end = count; idx < end; idx += 1) {
            Push(*this, filler);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const unit_t& filler,
                                                                  count_t count,
                                                                  allocator_t&& allocator) :
        dynamic_t(count, nkr::Move(allocator))
    {
        for (index_t idx = 0, end = count; idx < end; idx += 1) {
            Push(*this, filler);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(writable_unit_t&& filler,
                                                                  count_t count,
                                                                  const allocator_t& allocator) :
        dynamic_t(count, allocator)
    {
        if (count > 0) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, nkr::Move(filler));
            } else {
                Push(*this, nkr::Move(filler));
            }
            for (index_t idx = 0, end = count - 1; idx < end; idx += 1) {
                Push(*this, At(*this, 0));
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(writable_unit_t&& filler,
                                                                  count_t count,
                                                                  allocator_t&& allocator) :
        dynamic_t(count, nkr::Move(allocator))
    {
        if (count > 0) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, nkr::Move(filler));
            } else {
                Push(*this, nkr::Move(filler));
            }
            for (index_t idx = 0, end = count - 1; idx < end; idx += 1) {
                Push(*this, At(*this, 0));
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const std_array_of_tr<writable_unit_t> auto& array,
                                                                  const allocator_t& allocator) :
        dynamic_t(sizeof(array) / sizeof(unit_t), allocator)
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            Push(*this, array[idx]);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const std_array_of_tr<writable_unit_t> auto& array,
                                                                  allocator_t&& allocator) :
        dynamic_t(sizeof(array) / sizeof(unit_t), nkr::Move(allocator))
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            Push(*this, array[idx]);
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(std_array_of_tr<writable_unit_t> auto&& array,
                                                                  const allocator_t& allocator) :
        dynamic_t(sizeof(array) / sizeof(unit_t), allocator)
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, nkr::Move(array[idx]));
            } else {
                Push(*this, nkr::Move(array[idx]));
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(std_array_of_tr<writable_unit_t> auto&& array,
                                                                  allocator_t&& allocator) :
        dynamic_t(sizeof(array) / sizeof(unit_t), nkr::Move(allocator))
    {
        for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                Push(*this, nkr::Move(array[idx]));
            } else {
                Push(*this, nkr::Move(array[idx]));
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const any_stack_of_any_tr<unit_t> auto& stack_array,
                                                                  const allocator_t& allocator) :
        dynamic_t(stack_array.Count(), allocator)
    {
        stack_array.Copy_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const any_stack_of_any_tr<unit_t> auto& stack_array,
                                                                  allocator_t&& allocator) :
        dynamic_t(stack_array.Count(), nkr::Move(allocator))
    {
        stack_array.Copy_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(any_non_const_stack_of_any_non_const_tr<unit_t> auto&& stack_array,
                                                                  const allocator_t& allocator) :
        dynamic_t(stack_array.Count(), allocator)
    {
        stack_array.Move_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(any_non_const_stack_of_any_non_const_tr<unit_t> auto&& stack_array,
                                                                  allocator_t&& allocator) :
        dynamic_t(stack_array.Count(), nkr::Move(allocator))
    {
        stack_array.Move_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const any_instant_of_any_tr<unit_t> auto& instant_array,
                                                                  const allocator_t& allocator) :
        dynamic_t(instant_array.Count(), allocator)
    {
        instant_array.Copy_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const any_instant_of_any_tr<unit_t> auto& instant_array,
                                                                  allocator_t&& allocator) :
        dynamic_t(instant_array.Count(), nkr::Move(allocator))
    {
        instant_array.Copy_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(any_non_const_instant_of_any_non_const_tr<unit_t> auto&& instant_array,
                                                                  const allocator_t& allocator) :
        dynamic_t(instant_array.Count(), allocator)
    {
        instant_array.Move_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(any_non_const_instant_of_any_non_const_tr<unit_t> auto&& instant_array,
                                                                  allocator_t&& allocator) :
        dynamic_t(instant_array.Count(), nkr::Move(allocator))
    {
        instant_array.Move_To(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const dynamic_t& other) :
        writable_units(),
        unit_count(0),
        allocator(other.allocator)
    {
        Copy_Construct(*this, other);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const volatile dynamic_t& other) :
        writable_units(),
        unit_count(0),
        allocator(other.allocator)
    {
        Copy_Construct(*this, other);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(dynamic_t&& other) noexcept :
        writable_units(nkr::Move(other.writable_units)),
        unit_count(nkr::Move(other.unit_count)),
        allocator(nkr::Move(other.allocator))
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(volatile dynamic_t&& other) noexcept :
        writable_units(nkr::Move(other.writable_units)),
        unit_count(nkr::Move(other.unit_count)),
        allocator(nkr::Move(other.allocator))
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const dynamic_t& other)
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->allocator = other.allocator;
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const dynamic_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->allocator = other.allocator;
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const volatile dynamic_t& other)
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->allocator = other.allocator;
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const volatile dynamic_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->allocator = other.allocator;
            Copy_Construct(*this, other);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(dynamic_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->writable_units = nkr::Move(other.writable_units);
            this->unit_count = nkr::Move(other.unit_count);
            this->allocator = nkr::Move(other.allocator);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(dynamic_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->writable_units = nkr::Move(other.writable_units);
            this->unit_count = nkr::Move(other.unit_count);
            this->allocator = nkr::Move(other.allocator);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(is_just_volatile_tr<dynamic_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->writable_units = nkr::Move(other.writable_units);
            this->unit_count = nkr::Move(other.unit_count);
            this->allocator = nkr::Move(other.allocator);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline volatile dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(is_just_volatile_tr<dynamic_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
            this->writable_units = nkr::Move(other.writable_units);
            this->unit_count = nkr::Move(other.unit_count);
            this->allocator = nkr::Move(other.allocator);
        }
        return *this;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::~dynamic_t()
    {
        Destruct(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer()
        const
    {
        return Pointer(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::pointer_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Pointer()
        const volatile
    {
        return Pointer(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Count()
        const
    {
        return Count(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Count()
        const volatile
    {
        return Count(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const dynamic_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Allocator()
        const
    {
        return Allocator(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename const volatile dynamic_t<unit_p, allocator_p, grow_rate_p>::allocator_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Allocator()
        const volatile
    {
        return Allocator(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity()
        const
    {
        return Capacity(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity()
        const volatile
    {
        return Capacity(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
    {
        return Capacity(*this, new_capacity);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
        volatile
    {
        return Capacity(*this, new_capacity);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::At(index_t index)
        const volatile
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
    {
        return Push(*this, unit);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
        volatile
    {
        return Push(*this, unit);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(writable_unit_t&& unit)
    {
        return Push(*this, nkr::Move(unit));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(writable_unit_t&& unit)
        volatile
    {
        return Push(*this, nkr::Move(unit));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop()
    {
        return Pop(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Pop()
        volatile
    {
        return Pop(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit()
        const
    {
        return Is_Fit(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit()
        const volatile
    {
        return Is_Fit(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
    {
        return Fit(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
        volatile
    {
        return Fit(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear()
        const
    {
        return Is_Clear(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Clear()
        const volatile
    {
        return Is_Clear(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear()
    {
        return Clear(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow()
        const
    {
        return Should_Grow(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow()
        const volatile
    {
        return Should_Grow(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow()
    {
        return Grow(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow()
        volatile
    {
        return Grow(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator [](index_t index)
        const volatile
    {
        return At(*this, index);
    }

}}
