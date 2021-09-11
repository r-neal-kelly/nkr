/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_zeros_t_dec.h"
#include "nkr/os.h"

namespace nkr { namespace allocator {

    template <type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(units_t& units, count_t unit_count)
    {
        return os::heap::Allocate_Zeros(units, unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Allocate(pointer_t<unit_t>& units, count_t unit_count)
    {
        if (os::heap::Allocate_Zeros(units(), unit_count)) {
            static_cast<count_t&>(units) = unit_count;
            return true;
        } else {
            units = { nullptr, 0 };
            return false;
        }
    }

    template <type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(units_t& units, count_t new_unit_count)
    {
        return os::heap::Reallocate_Zeros(units, new_unit_count);
    }

    template <type_tr unit_p>
    inline bool_t heap_zeros_t<unit_p>::Reallocate(pointer_t<unit_t>& units, count_t new_unit_count)
    {
        if (os::heap::Reallocate_Zeros(units(), new_unit_count)) {
            static_cast<count_t&>(units) = new_unit_count;
            return true;
        } else {
            return false;
        }
    }

    template <type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(units_t& units)
    {
        return os::heap::Deallocate_Zeros(units);
    }

    template <type_tr unit_p>
    inline void_t heap_zeros_t<unit_p>::Deallocate(pointer_t<unit_t>& units)
    {
        os::heap::Deallocate_Zeros(units());
        units = { nullptr, 0 };
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr { namespace allocator {



}}

#endif
