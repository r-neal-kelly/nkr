/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/os.h"

#include "nkr/allocator/heap_t_dec.h"

namespace nkr { namespace allocator {

    template <any_type_tr unit_p>
    inline constexpr count_t
        heap_t<unit_p>::Min_Unit_Count()
    {
        return 1;
    }

    template <any_type_tr unit_p>
    inline constexpr count_t
        heap_t<unit_p>::Max_Unit_Count()
    {
        return std::numeric_limits<count_t>::max() / sizeof(unit_t);
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Allocate(is_any_tr<heap_t> auto& self,
                                 is_any_non_const_tr<units_t> auto& units,
                                 count_t unit_count)
    {
        return nkr::Move(os::heap::Allocate(units, unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Allocate(is_any_tr<heap_t> auto& self,
                                 is_any_non_const_tr<pointer_t> auto& units,
                                 count_t unit_count)
    {
        maybe_t<allocator_err> err = os::heap::Allocate(units(), unit_count);
        if (err) {
            units = { nullptr, 0 };
        } else {
            units.Unit_Count() = unit_count;
        }
        return err;
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Reallocate(is_any_tr<heap_t> auto& self,
                                   is_any_non_const_tr<units_t> auto& units,
                                   count_t new_unit_count)
    {
        return nkr::Move(os::heap::Reallocate(units, new_unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Reallocate(is_any_tr<heap_t> auto& self,
                                   is_any_non_const_tr<pointer_t> auto& units,
                                   count_t new_unit_count)
    {
        maybe_t<allocator_err> err = os::heap::Reallocate(units(), new_unit_count);
        if (!err) {
            units.Unit_Count() = new_unit_count;
        }
        return err;
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_t<unit_p>::Deallocate(is_any_tr<heap_t> auto& self,
                                   is_any_non_const_tr<units_t> auto& units)
    {
        return os::heap::Deallocate(units);
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_t<unit_p>::Deallocate(is_any_tr<heap_t> auto& self,
                                   is_any_non_const_tr<pointer_t> auto& units)
    {
        os::heap::Deallocate(units());
        units = { nullptr, 0 };
    }

    template <any_type_tr unit_p>
    inline bool_t
        heap_t<unit_p>::Is_Equal_To(is_any_tr<heap_t> auto a, is_any_tr<heap_t> auto b)
    {
        return true;
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>::heap_t(const heap_t& other)
    {
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>::heap_t(const volatile heap_t& other)
    {
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>::heap_t(heap_t&& other)
        noexcept
    {
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>::heap_t(volatile heap_t&& other)
        noexcept
    {
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>&
        heap_t<unit_p>::operator =(const heap_t& other)
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile heap_t<unit_p>&
        heap_t<unit_p>::operator =(const heap_t& other)
        volatile
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>&
        heap_t<unit_p>::operator =(const volatile heap_t& other)
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile heap_t<unit_p>&
        heap_t<unit_p>::operator =(const volatile heap_t& other)
        volatile
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>&
        heap_t<unit_p>::operator =(heap_t&& other)
        noexcept
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile heap_t<unit_p>&
        heap_t<unit_p>::operator =(heap_t&& other)
        volatile noexcept
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline heap_t<unit_p>&
        heap_t<unit_p>::operator =(is_just_volatile_tr<heap_t> auto&& other)
        noexcept
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline volatile heap_t<unit_p>&
        heap_t<unit_p>::operator =(is_just_volatile_tr<heap_t> auto&& other)
        volatile noexcept
    {
        return *this;
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count)
        const
    {
        return nkr::Move(Allocate(*this, units, unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count)
        const volatile
    {
        return nkr::Move(Allocate(*this, units, unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count)
        const
    {
        return nkr::Move(Allocate(*this, units, unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count)
        const volatile
    {
        return nkr::Move(Allocate(*this, units, unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count)
        const
    {
        return nkr::Move(Reallocate(*this, units, new_unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count)
        const volatile
    {
        return nkr::Move(Reallocate(*this, units, new_unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count)
        const
    {
        return nkr::Move(Reallocate(*this, units, new_unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_t<unit_p>::Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count)
        const volatile
    {
        return nkr::Move(Reallocate(*this, units, new_unit_count));
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_t<unit_p>::Deallocate(is_any_non_const_tr<units_t> auto& units)
        const
    {
        return Deallocate(*this, units);
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_t<unit_p>::Deallocate(is_any_non_const_tr<units_t> auto& units)
        const volatile
    {
        return Deallocate(*this, units);
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_t<unit_p>::Deallocate(is_any_non_const_tr<pointer_t> auto& units)
        const
    {
        return Deallocate(*this, units);
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_t<unit_p>::Deallocate(is_any_non_const_tr<pointer_t> auto& units)
        const volatile
    {
        return Deallocate(*this, units);
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr { namespace allocator {



}}

#endif
