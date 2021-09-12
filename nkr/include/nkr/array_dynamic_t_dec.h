/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_t.h"
#include "nkr/allocator_i.h"
#include "nkr/intrinsics.h"
#include "nkr/math.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

namespace nkr {

    template <
        type_tr             unit_p,
        allocator_i         allocator_p = allocator::heap_t<unit_p>,
        math::fraction_i    grow_rate_p = math::fraction_t<17, 10>
    > class array_dynamic_t
    {
    public:
        using this_t        = array_dynamic_t<unit_p, allocator_p, grow_rate_p>;
        using unit_t        = unit_p;
        using pointer_t     = pointer_t<unit_t>;
        using allocator_t   = allocator_p;
        using grow_rate_t   = grow_rate_p;

    public:
        static constexpr size_t     Unit_Size();
        static constexpr real_t     Grow_Rate();

    private:
        static void_t   Copy(const same_as_non_cv_tr<this_t> auto& from, same_as_non_cv_tr<this_t> auto& to);
        static void_t   Destroy(same_as_non_cv_tr<this_t> auto& it);

    protected:
        pointer_t   units;
        count_t     unit_count;
        allocator_t allocator;

    public:
        array_dynamic_t();

        array_dynamic_t(const array_dynamic_t& other);
        array_dynamic_t(volatile const array_dynamic_t& other);
        array_dynamic_t(array_dynamic_t&& other) noexcept;
        array_dynamic_t(volatile array_dynamic_t&& other) noexcept;

        array_dynamic_t&            operator =(const array_dynamic_t& other);
        volatile array_dynamic_t&   operator =(volatile const array_dynamic_t& other) volatile;
        array_dynamic_t&            operator =(array_dynamic_t&& other) noexcept;
        volatile array_dynamic_t&   operator =(volatile array_dynamic_t&& other) volatile noexcept;

        ~array_dynamic_t();

    public:
        bool_t  Reserve(count_t reserve_unit_count);
    };

}
