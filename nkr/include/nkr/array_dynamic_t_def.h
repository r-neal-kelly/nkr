/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "array_dynamic_t_dec.h"

namespace nkr {

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr size_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Unit_Size()
    {
        return sizeof(unit_t);
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline constexpr real_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Grow_Rate()
    {
        static_assert(grow_rate_t::NUMERATOR >= 0, "numerator must be > 0");
        static_assert(grow_rate_t::DENOMINATOR >= 0, "denominator must be > 0");

        constexpr real_t grow_rate =
            static_cast<real_t>(grow_rate_t::NUMERATOR) /
            static_cast<real_t>(grow_rate_t::DENOMINATOR);

        static_assert(grow_rate >= 1.0, "grow_rate must be >= 1.0");

        return grow_rate;
    }

    template <type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    inline void_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Copy(const same_as_non_cv_tr<this_t> auto& from,
                                                                          same_as_non_cv_tr<this_t> auto& to)
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
    inline void_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Destroy(same_as_non_cv_tr<this_t> auto& it)
    {
        for (index_t idx = 0, end = it.unit_count; idx < end; idx += 1) {
            it.units[idx].~unit_t();
        }
        it.allocator.Deallocate(it.units);
        it.units = nullptr;
        it.unit_count = 0;
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
    inline bool_t array_dynamic_t<unit_p, allocator_p, grow_rate_p>::Reserve(count_t reserve_unit_count)
    {
        assert(reserve_unit_count > 0);

        if (this->units == nullptr) {
            return this->allocator.Allocate(this->units, reserve_unit_count);
        } else {
            if (this->units.unit_count < reserve_unit_count) {
                return this->allocator.Reallocate(this->units, reserve_unit_count);
            } else {
                return true;
            }
        }
    }

}
