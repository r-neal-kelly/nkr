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
        static constexpr real_t Grow_Rate();

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
        count_t     Capacity() const;
        bool_t      Capacity(count_t new_capacity);
        count_t     Count() const;

        unit_t&     At(index_t index) const;
        bool_t      Push(const unit_t& unit);
        bool_t      Push(unit_t&& unit);
        unit_t      Pop();

        bool_t      Is_Fit() const;
        bool_t      Fit();

        bool_t      Is_Clear() const;
        void_t      Clear();

        pointer_t   Pointer() const;

    private:
        bool_t  Should_Grow() const;
        bool_t  Grow();

    public:
        unit_t& operator [](index_t index) const;
    };

}
