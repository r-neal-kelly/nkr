/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_zeros_t_dec.h"
#include "nkr/os.h"

namespace nkr { namespace allocator {

    template <any_type_tr unit_p>
    inline constexpr count_t heap_zeros_t<unit_p>::Min_Unit_Count()
    {
        return 1;
    }

    template <any_type_tr unit_p>
    inline constexpr count_t heap_zeros_t<unit_p>::Max_Unit_Count()
    {
        return std::numeric_limits<count_t>::max() / sizeof(unit_t);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(is_any_tr<heap_zeros_t> auto& self, is_any_tr<units_t> auto& units, count_t unit_count)
    {
        return os::heap::Allocate_Zeros(units, unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(is_any_tr<heap_zeros_t> auto& self, is_any_tr<pointer_t> auto& units, count_t unit_count)
    {
        if (os::heap::Allocate_Zeros(units(), unit_count)) {
            units.Unit_Count() = unit_count;
            return true;
        } else {
            units = { nullptr, 0 };
            return false;
        }
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(is_any_tr<heap_zeros_t> auto& self, is_any_tr<units_t> auto& units, count_t new_unit_count)
    {
        return os::heap::Reallocate_Zeros(units, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(is_any_tr<heap_zeros_t> auto& self, is_any_tr<pointer_t> auto& units, count_t new_unit_count)
    {
        if (os::heap::Reallocate_Zeros(units(), new_unit_count)) {
            units.Unit_Count() = new_unit_count;
            return true;
        } else {
            return false;
        }
    }

    template <any_type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(is_any_tr<heap_zeros_t> auto& self, is_any_tr<units_t> auto& units)
    {
        return os::heap::Deallocate_Zeros(units);
    }

    template <any_type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(is_any_tr<heap_zeros_t> auto& self, is_any_tr<pointer_t> auto& units)
    {
        os::heap::Deallocate_Zeros(units());
        units = { nullptr, 0 };
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Is_Equal_To(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b)
    {
        return true;
    }

    template <any_type_tr unit_p>
    inline heap_zeros_t<unit_p>::heap_zeros_t(const heap_zeros_t& other)
    {
    }

    template <any_type_tr unit_p>
    inline heap_zeros_t<unit_p>::heap_zeros_t(volatile const heap_zeros_t& other)
    {
    }

    template <any_type_tr unit_p>
    inline heap_zeros_t<unit_p>::heap_zeros_t(heap_zeros_t&& other) noexcept
    {
    }

    template <any_type_tr unit_p>
    inline heap_zeros_t<unit_p>::heap_zeros_t(volatile heap_zeros_t&& other) noexcept
    {
    }

    template <any_type_tr unit_p>
    inline heap_zeros_t<unit_p>& heap_zeros_t<unit_p>::operator =(const heap_zeros_t& other)
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile heap_zeros_t<unit_p>& heap_zeros_t<unit_p>::operator =(volatile const heap_zeros_t& other) volatile
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline heap_zeros_t<unit_p>& heap_zeros_t<unit_p>::operator =(heap_zeros_t&& other) noexcept
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile heap_zeros_t<unit_p>& heap_zeros_t<unit_p>::operator =(volatile heap_zeros_t&& other) volatile noexcept
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(units_t& units, count_t unit_count)
    {
        return Allocate(*this, units, unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(volatile units_t& units, count_t unit_count) volatile
    {
        return Allocate(*this, units, unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(pointer_t& units, count_t unit_count)
    {
        return Allocate(*this, units, unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(volatile pointer_t& units, count_t unit_count) volatile
    {
        return Allocate(*this, units, unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(units_t& units, count_t new_unit_count)
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(volatile units_t& units, count_t new_unit_count) volatile
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(pointer_t& units, count_t new_unit_count)
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(volatile pointer_t& units, count_t new_unit_count) volatile
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <any_type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(units_t& units)
    {
        return Deallocate(*this, units);
    }

    template <any_type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(volatile units_t& units) volatile
    {
        return Deallocate(*this, units);
    }

    template <any_type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(pointer_t& units)
    {
        return Deallocate(*this, units);
    }

    template <any_type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(volatile pointer_t& units) volatile
    {
        return Deallocate(*this, units);
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr { namespace allocator {



}}

#endif
