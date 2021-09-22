/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_i.h"
#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

namespace nkr { namespace allocator {

    template <any_type_tr unit_p>
    class heap_zeros_t
    {
    public:
        using unit_t    = unit_p;
        using units_t   = unit_p*;
        using pointer_t = pointer_t<unit_p>;

    public:
        static constexpr count_t    Min_Unit_Count();
        static constexpr count_t    Max_Unit_Count();

    private:
        static bool_t   Allocate(is_any_tr<heap_zeros_t> auto& self,
                                 is_any_non_const_tr<units_t> auto& units,
                                 count_t unit_count);
        static bool_t   Allocate(is_any_tr<heap_zeros_t> auto& self,
                                 is_any_non_const_tr<pointer_t> auto& units,
                                 count_t unit_count);

        static bool_t   Reallocate(is_any_tr<heap_zeros_t> auto& self,
                                   is_any_non_const_tr<units_t> auto& units,
                                   count_t new_unit_count);
        static bool_t   Reallocate(is_any_tr<heap_zeros_t> auto& self,
                                   is_any_non_const_tr<pointer_t> auto& units,
                                   count_t new_unit_count);

        static void_t   Deallocate(is_any_tr<heap_zeros_t> auto& self,
                                   is_any_non_const_tr<units_t> auto& units);
        static void_t   Deallocate(is_any_tr<heap_zeros_t> auto& self,
                                   is_any_non_const_tr<pointer_t> auto& units);

        static bool_t   Is_Equal_To(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b);

    public:
        friend bool_t operator ==(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b)
        {
            return Is_Equal_To(a, b);
        }

        friend bool_t operator !=(is_any_tr<heap_zeros_t> auto a, is_any_tr<heap_zeros_t> auto b)
        {
            return !Is_Equal_To(a, b);
        }

    public:
        heap_zeros_t()                                                                          = default;

        heap_zeros_t(const heap_zeros_t& other);
        heap_zeros_t(volatile const heap_zeros_t& other);
        heap_zeros_t(heap_zeros_t&& other) noexcept;
        heap_zeros_t(volatile heap_zeros_t&& other) noexcept;

        heap_zeros_t&           operator =(const heap_zeros_t& other);
        volatile heap_zeros_t&  operator =(volatile const heap_zeros_t& other) volatile;
        heap_zeros_t&           operator =(heap_zeros_t&& other) noexcept;
        volatile heap_zeros_t&  operator =(volatile heap_zeros_t&& other) volatile noexcept;

        ~heap_zeros_t()                                                                         = default;

    public:
        bool_t  Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count) const;
        bool_t  Allocate(is_any_non_const_tr<units_t> auto& units, count_t unit_count) const volatile;
        bool_t  Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count) const;
        bool_t  Allocate(is_any_non_const_tr<pointer_t> auto& units, count_t unit_count) const volatile;

        bool_t  Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count) const;
        bool_t  Reallocate(is_any_non_const_tr<units_t> auto& units, count_t new_unit_count) const volatile;
        bool_t  Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count) const;
        bool_t  Reallocate(is_any_non_const_tr<pointer_t> auto& units, count_t new_unit_count) const volatile;

        void_t  Deallocate(is_any_non_const_tr<units_t> auto& units) const;
        void_t  Deallocate(is_any_non_const_tr<units_t> auto& units) const volatile;
        void_t  Deallocate(is_any_non_const_tr<pointer_t> auto& units) const;
        void_t  Deallocate(is_any_non_const_tr<pointer_t> auto& units) const volatile;
    };
    static_assert(allocator_i<heap_zeros_t<word_t>>);

}}
