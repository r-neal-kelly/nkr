/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_os.h"

#include "nkr/z_allocator/heap_zeros_t_dec.h"

namespace nkr { namespace allocator {

    template <any_type_tr unit_p>
    inline constexpr count_t
        heap_zeros_t<unit_p>::Min_Unit_Count()
    {
        return 0;
    }

    template <any_type_tr unit_p>
    inline constexpr count_t
        heap_zeros_t<unit_p>::Max_Unit_Count()
    {
        return std::numeric_limits<count_t>::max() / sizeof(unit_t);
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_zeros_t<unit_p>::Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count)
    {
        nkr_ASSERT_THAT(units == none_t());

        return nkr::Move(os::heap::Allocate_Zeros(units, unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_zeros_t<unit_p>::Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count)
    {
        nkr_ASSERT_THAT(units == none_t());

        maybe_t<allocator_err> err = os::heap::Allocate_Zeros(units(), unit_count);
        if (!err) {
            units.Unit_Count() = unit_count;
        }
        return err;
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_zeros_t<unit_p>::Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count)
    {
        return nkr::Move(os::heap::Reallocate_Zeros(units, new_unit_count));
    }

    template <any_type_tr unit_p>
    inline maybe_t<allocator_err>
        heap_zeros_t<unit_p>::Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count)
    {
        maybe_t<allocator_err> err = os::heap::Reallocate_Zeros(units(), new_unit_count);
        if (!err) {
            units.Unit_Count() = new_unit_count;
        }
        return err;
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_zeros_t<unit_p>::Deallocate(is_any_non_const_tr<units_t> auto& units)
    {
        return os::heap::Deallocate_Zeros(units);
    }

    template <any_type_tr unit_p>
    inline void_t
        heap_zeros_t<unit_p>::Deallocate(is_any_non_const_tr<pointer_t> auto& units)
    {
        os::heap::Deallocate_Zeros(units());
        units = none_t();
    }

}}

#if defined(nkr_DO_EXTERN_TEMPLATES)

namespace nkr { namespace allocator {



}}

#endif
