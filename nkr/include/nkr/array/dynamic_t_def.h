/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/macros_def.h"
#include "nkr/math.h"
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
        nkr_ASSERT_THAT(self.writable_units == nullptr);
        nkr_ASSERT_THAT(self.unit_count == 0);

        if (other.unit_count > 0) {
            maybe_t<allocator_err> err = allocator_t::Allocate(Units(self), other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    self.writable_units[idx] = other.writable_units[idx];
                }
                self.unit_count = other.unit_count;
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Destruct(is_any_tr<dynamic_t> auto& self)
    {
        Clear(self);
        allocator_t::Deallocate(Units(self));
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
    inline count_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(const is_any_tr<dynamic_t> auto& self)
    {
        return self.writable_units.Unit_Count();
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(is_any_tr<dynamic_t> auto& self, count_t new_capacity)
    {
        nkr_ASSERT_THAT(new_capacity >= allocator_t::Min_Unit_Count());
        nkr_ASSERT_THAT(new_capacity <= allocator_t::Max_Unit_Count());

        if (self.writable_units == nullptr) {
            return nkr::Move(allocator_t::Allocate(Units(self), new_capacity));
        } else {
            if (self.writable_units.Unit_Count() < new_capacity) {
                return nkr::Move(allocator_t::Reallocate(Units(self), new_capacity));
            } else {
                return allocator_err::NONE;
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Has_Memory(const is_any_tr<dynamic_t> auto& self)
    {
        return self.writable_units != nullptr;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Should_Grow(const is_any_tr<dynamic_t> auto& self)
    {
        if (self.unit_count < allocator_t::Max_Unit_Count()) {
            return self.unit_count + 1 > self.Capacity();
        } else {
            return true;
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow(is_any_tr<dynamic_t> auto& self)
    {
        count_t capacity = self.Capacity();
        if (capacity < allocator_t::Max_Unit_Count()) {
            if (math::Will_Overflow_Multiply(static_cast<real_t>(capacity), Grow_Rate())) {
                return nkr::Move(self.Capacity(allocator_t::Max_Unit_Count()));
            } else {
                count_t new_capacity = static_cast<count_t>(static_cast<real_t>(capacity) * Grow_Rate());
                if (new_capacity < allocator_t::Max_Unit_Count()) {
                    new_capacity += 1;
                } else {
                    new_capacity = allocator_t::Max_Unit_Count();
                }
                return nkr::Move(self.Capacity(new_capacity));
            }
        } else {
            return allocator_err::OUT_OF_MEMORY;
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline typename dynamic_t<unit_p, allocator_p, grow_rate_p>::unit_t&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::At(const is_any_tr<dynamic_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(index < self.unit_count);

        return self.writable_units[index];
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, const unit_t& unit)
    {
        if (Should_Grow(self)) {
            maybe_t<allocator_err> err = Grow(self);
            if (err) {
                return nkr::Move(err);
            }
        }

        self.writable_units[self.unit_count] = unit;
        self.unit_count += 1;

        return true;
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(is_any_tr<dynamic_t> auto& self, writable_unit_t&& unit)
    {
        if (Should_Grow(self)) {
            maybe_t<allocator_err> err = Grow(self);
            if (err) {
                return nkr::Move(err);
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
        nkr_ASSERT_THAT(self.unit_count > 0);

        self.unit_count -= 1;

        return nkr::Move(self.writable_units[self.unit_count]);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_To(const is_any_tr<dynamic_t> auto& self,
                                                             any_non_const_array_of_any_tr<unit_t> auto& other)
    {
        const count_t other_count = other.Count();
        const count_t count = Count(self);
        if (math::Will_Overflow_Add(other_count, count)) {
            return allocator_err::OUT_OF_MEMORY;
        } else {
            maybe_t<allocator_err> err = other.Capacity(other_count + count);
            if (err) {
                return nkr::Move(err);
            } else {
                for (index_t idx = 0, end = count; idx < end; idx += 1) {
                    other.Push(Array(self)[idx]).Ignore_Error();
                }

                return allocator_err::NONE;
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_From(is_any_non_const_tr<dynamic_t> auto& self,
                                                               const any_array_of_any_tr<unit_t> auto& other)
    {
        return nkr::Move(other.Copy_To(self));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Move_To(any_non_const_dynamic_of_any_non_const_tr<unit_t> auto& self,
                                                             any_non_const_array_of_any_tr<unit_t> auto& other)
    {
        if (reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
            reinterpret_cast<const volatile void_t*>(std::addressof(other))) {
            const count_t other_count = other.Count();
            const count_t count = Count(self);
            if (math::Will_Overflow_Add(other_count, count)) {
                return allocator_err::OUT_OF_MEMORY;
            } else {
                maybe_t<allocator_err> err = other.Capacity(other_count + count);
                if (err) {
                    return nkr::Move(err);
                } else {
                    for (index_t idx = 0, end = count; idx < end; idx += 1) {
                        other.Push(nkr::Move(Writable_Array(self)[idx])).Ignore_Error();
                    }
                    self.unit_count = 0;

                    return allocator_err::NONE;
                }
            }
        } else {
            return allocator_err::NONE;
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Move_From(is_any_non_const_tr<dynamic_t> auto& self,
                                                               any_non_const_array_of_any_non_const_tr<unit_t> auto& other)
    {
        if (reinterpret_cast<const volatile void_t*>(std::addressof(self)) !=
            reinterpret_cast<const volatile void_t*>(std::addressof(other))) {
            return nkr::Move(other.Move_To(self));
        } else {
            return allocator_err::NONE;
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Is_Fit(const is_any_tr<dynamic_t> auto& self)
    {
        return Count(self) == Capacity(self);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit(is_any_tr<dynamic_t> auto& self)
    {
        if (self.unit_count < self.writable_units.Unit_Count()) {
            return nkr::Move(allocator_t::Reallocate(Units(self), self.unit_count));
        } else {
            return allocator_err::NONE;
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
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t() :
        writable_units(),
        unit_count(0)
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(count_t capacity) :
        dynamic_t()
    {
        if (capacity > 0) {
            Capacity(*this, capacity).Ignore_Error();
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const unit_t& filler, count_t count) :
        dynamic_t(count)
    {
        if (Has_Memory(*this)) {
            for (index_t idx = 0, end = count; idx < end; idx += 1) {
                Push(*this, filler).Ignore_Error();
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(writable_unit_t&& filler, count_t count) :
        dynamic_t(count)
    {
        if (count > 0 && Has_Memory(*this)) {
            Push(*this, nkr::Move(filler)).Ignore_Error();
            for (index_t idx = 0, end = count - 1; idx < end; idx += 1) {
                Push(*this, At(*this, 0)).Ignore_Error();
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const std_array_of_tr<writable_unit_t> auto& array) :
        dynamic_t(sizeof(array) / sizeof(unit_t))
    {
        if (Has_Memory(*this)) {
            for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
                Push(*this, array[idx]).Ignore_Error();
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(std_array_of_tr<writable_unit_t> auto&& array) :
        dynamic_t(sizeof(array) / sizeof(unit_t))
    {
        if (Has_Memory(*this)) {
            for (index_t idx = 0, end = sizeof(array) / sizeof(unit_t); idx < end; idx += 1) {
                Push(*this, nkr::Move(array[idx])).Ignore_Error();
            }
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const any_stack_of_any_tr<unit_t> auto& stack_array) :
        dynamic_t(stack_array.Count())
    {
        if (Has_Memory(*this)) {
            stack_array.Copy_To(*this).Ignore_Error();
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(any_non_const_stack_of_any_non_const_tr<unit_t> auto&& stack_array) :
        dynamic_t(stack_array.Count())
    {
        if (Has_Memory(*this)) {
            stack_array.Move_To(*this).Ignore_Error();
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const any_instant_of_any_tr<unit_t> auto& instant_array) :
        dynamic_t(instant_array.Count())
    {
        if (Has_Memory(*this)) {
            instant_array.Copy_To(*this).Ignore_Error();
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(any_non_const_instant_of_any_non_const_tr<unit_t> auto&& instant_array) :
        dynamic_t(instant_array.Count())
    {
        if (Has_Memory(*this)) {
            instant_array.Move_To(*this).Ignore_Error();
        }
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const dynamic_t& other) :
        writable_units(),
        unit_count(0)
    {
        Copy_Construct(*this, other);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(const volatile dynamic_t& other) :
        writable_units(),
        unit_count(0)
    {
        Copy_Construct(*this, other);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(dynamic_t&& other) noexcept :
        writable_units(nkr::Move(other.writable_units)),
        unit_count(nkr::Move(other.unit_count))
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>::dynamic_t(volatile dynamic_t&& other) noexcept :
        writable_units(nkr::Move(other.writable_units)),
        unit_count(nkr::Move(other.unit_count))
    {
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline dynamic_t<unit_p, allocator_p, grow_rate_p>&
        dynamic_t<unit_p, allocator_p, grow_rate_p>::operator =(const dynamic_t& other)
    {
        if (this != std::addressof(other)) {
            Destruct(*this);
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
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
    {
        return nkr::Move(Capacity(*this, new_capacity));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Capacity(count_t new_capacity)
        volatile
    {
        return nkr::Move(Capacity(*this, new_capacity));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline bool_t
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
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
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
    {
        return nkr::Move(Push(*this, unit));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(const unit_t& unit)
        volatile
    {
        return nkr::Move(Push(*this, unit));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(writable_unit_t&& unit)
    {
        return nkr::Move(Push(*this, nkr::Move(unit)));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Push(writable_unit_t&& unit)
        volatile
    {
        return nkr::Move(Push(*this, nkr::Move(unit)));
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
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other)
        const
    {
        return nkr::Move(Copy_To(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other)
        const volatile
    {
        return nkr::Move(Copy_To(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_From(const any_array_of_any_tr<unit_t> auto& other)
    {
        return nkr::Move(Copy_From(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy_From(const any_array_of_any_tr<unit_t> auto& other)
        volatile
    {
        return nkr::Move(Copy_From(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Move_To(any_non_const_array_of_any_tr<unit_t> auto& other)
    {
        return nkr::Move(Move_To(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Move_To(any_non_const_array_of_any_tr<unit_t> auto& other)
        volatile
    {
        return nkr::Move(Move_To(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other)
    {
        return nkr::Move(Move_From(*this, other));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other)
        volatile
    {
        return nkr::Move(Move_From(*this, other));
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
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
    {
        return nkr::Move(Fit(*this));
    }

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline maybe_t<allocator_err>
        dynamic_t<unit_p, allocator_p, grow_rate_p>::Fit()
        volatile
    {
        return nkr::Move(Fit(*this));
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
