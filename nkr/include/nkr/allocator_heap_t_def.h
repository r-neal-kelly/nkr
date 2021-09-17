/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_t_dec.h"
#include "nkr/os.h"

namespace nkr { namespace allocator {

    template <type_tr unit_p>
    inline constexpr count_t heap_t<unit_p>::Min_Unit_Count()
    {
        return 1;
    }

    template <type_tr unit_p>
    inline constexpr count_t heap_t<unit_p>::Max_Unit_Count()
    {
        return std::numeric_limits<count_t>::max() / sizeof(unit_t);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(same_as_any_tr<heap_t> auto& self,
                                           same_as_any_tr<units_t> auto& units,
                                           count_t unit_count)
    {
        return os::heap::Allocate(units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(same_as_any_tr<heap_t> auto& self,
                                           same_as_any_tr<pointer_t> auto& units,
                                           count_t unit_count)
    {
        if (os::heap::Allocate(units(), unit_count)) {
            units.Unit_Count() = unit_count;
            return true;
        } else {
            units = { nullptr, 0 };
            return false;
        }
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(same_as_any_tr<heap_t> auto& self,
                                             same_as_any_tr<units_t> auto& units,
                                             count_t new_unit_count)
    {
        return os::heap::Reallocate(units, new_unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(same_as_any_tr<heap_t> auto& self,
                                             same_as_any_tr<pointer_t> auto& units,
                                             count_t new_unit_count)
    {
        if (os::heap::Reallocate(units(), new_unit_count)) {
            units.Unit_Count() = new_unit_count;
            return true;
        } else {
            return false;
        }
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(same_as_any_tr<heap_t> auto& self,
                                             same_as_any_tr<units_t> auto& units)
    {
        return os::heap::Deallocate(units);
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(same_as_any_tr<heap_t> auto& self,
                                             same_as_any_tr<pointer_t> auto& units)
    {
        os::heap::Deallocate(units());
        units = { nullptr, 0 };
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Is_Equal_To(same_as_any_tr<heap_t> auto a,
                                              same_as_any_tr<heap_t> auto b)
    {
        return true;
    }

    template <type_tr unit_p>
    inline heap_t<unit_p>::heap_t(const heap_t& other)
    {
    }

    template <type_tr unit_p>
    inline heap_t<unit_p>::heap_t(volatile const heap_t& other)
    {
    }

    template <type_tr unit_p>
    inline heap_t<unit_p>::heap_t(heap_t&& other) noexcept
    {
    }

    template <type_tr unit_p>
    inline heap_t<unit_p>::heap_t(volatile heap_t&& other) noexcept
    {
    }

    template <type_tr unit_p>
    inline heap_t<unit_p>& heap_t<unit_p>::operator =(const heap_t& other)
    {
        return *this;
    }

    template <type_tr unit_p>
    inline volatile heap_t<unit_p>& heap_t<unit_p>::operator =(volatile const heap_t& other) volatile
    {
        return *this;
    }

    template <type_tr unit_p>
    inline heap_t<unit_p>& heap_t<unit_p>::operator =(heap_t&& other) noexcept
    {
        return *this;
    }

    template <type_tr unit_p>
    inline volatile heap_t<unit_p>& heap_t<unit_p>::operator =(volatile heap_t&& other) volatile noexcept
    {
        return *this;
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(units_t& units, count_t unit_count)
    {
        return Allocate(*this, units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(volatile units_t& units, count_t unit_count) volatile
    {
        return Allocate(*this, units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(pointer_t& units, count_t unit_count)
    {
        return Allocate(*this, units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(volatile pointer_t& units, count_t unit_count) volatile
    {
        return Allocate(*this, units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(units_t& units, count_t new_unit_count)
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(volatile units_t& units, count_t new_unit_count) volatile
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(pointer_t& units, count_t new_unit_count)
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(volatile pointer_t& units, count_t new_unit_count) volatile
    {
        return Reallocate(*this, units, new_unit_count);
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(units_t& units)
    {
        return Deallocate(*this, units);
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(volatile units_t& units) volatile
    {
        return Deallocate(*this, units);
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(pointer_t& units)
    {
        return Deallocate(*this, units);
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(volatile pointer_t& units) volatile
    {
        return Deallocate(*this, units);
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr { namespace allocator {



}}

#endif
