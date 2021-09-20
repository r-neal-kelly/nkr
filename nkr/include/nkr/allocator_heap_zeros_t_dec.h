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

    template <type_tr unit_p>
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
        static bool_t   Allocate(any_tr<heap_zeros_t> auto& self, any_tr<units_t> auto& units, count_t unit_count);
        static bool_t   Allocate(any_tr<heap_zeros_t> auto& self, any_tr<pointer_t> auto& units, count_t unit_count);

        static bool_t   Reallocate(any_tr<heap_zeros_t> auto& self, any_tr<units_t> auto& units, count_t new_unit_count);
        static bool_t   Reallocate(any_tr<heap_zeros_t> auto& self, any_tr<pointer_t> auto& units, count_t new_unit_count);

        static void_t   Deallocate(any_tr<heap_zeros_t> auto& self, any_tr<units_t> auto& units);
        static void_t   Deallocate(any_tr<heap_zeros_t> auto& self, any_tr<pointer_t> auto& units);

        static bool_t   Is_Equal_To(any_tr<heap_zeros_t> auto a, any_tr<heap_zeros_t> auto b);

    public:
        friend bool_t operator ==(any_tr<heap_zeros_t> auto a, any_tr<heap_zeros_t> auto b)
        {
            return Is_Equal_To(a, b);
        }

        friend bool_t operator !=(any_tr<heap_zeros_t> auto a, any_tr<heap_zeros_t> auto b)
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
        bool_t  Allocate(units_t& units, count_t unit_count);
        bool_t  Allocate(volatile units_t& units, count_t unit_count) volatile;
        bool_t  Allocate(pointer_t& units, count_t unit_count);
        bool_t  Allocate(volatile pointer_t& units, count_t unit_count) volatile;

        bool_t  Reallocate(units_t& units, count_t new_unit_count);
        bool_t  Reallocate(volatile units_t& units, count_t new_unit_count) volatile;
        bool_t  Reallocate(pointer_t& units, count_t new_unit_count);
        bool_t  Reallocate(volatile pointer_t& units, count_t new_unit_count) volatile;

        void_t  Deallocate(units_t& units);
        void_t  Deallocate(volatile units_t& units) volatile;
        void_t  Deallocate(pointer_t& units);
        void_t  Deallocate(volatile pointer_t& units) volatile;
    };
    static_assert(allocator_i<heap_zeros_t<word_t>>);

}}
