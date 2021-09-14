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
    inline bool_t heap_t<unit_p>::Is_Equal_To(same_as_remove_cvref_tr<heap_t> auto a,
                                              same_as_remove_cvref_tr<heap_t> auto b)
    {
        return true;
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(units_t& units, count_t unit_count)
    {
        return os::heap::Allocate(units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Allocate(pointer_t<unit_t>& units, count_t unit_count)
    {
        if (os::heap::Allocate(units(), unit_count)) {
            static_cast<count_t&>(units) = unit_count;
            return true;
        } else {
            units = { nullptr, 0 };
            return false;
        }
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(units_t& units, count_t new_unit_count)
    {
        return os::heap::Reallocate(units, new_unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_t<unit_p>::Reallocate(pointer_t<unit_t>& units, count_t new_unit_count)
    {
        if (os::heap::Reallocate(units(), new_unit_count)) {
            static_cast<count_t&>(units) = new_unit_count;
            return true;
        } else {
            return false;
        }
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(units_t& units)
    {
        return os::heap::Deallocate(units);
    }

    template <type_tr unit_p>
    inline void_t heap_t<unit_p>::Deallocate(pointer_t<unit_t>& units)
    {
        os::heap::Deallocate(units());
        units = { nullptr, 0 };
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr { namespace allocator {



}}

#endif
