/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/allocator_heap_t.h"
#include "nkr/allocator_i.h"
#include "nkr/bool_t.h"
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
        using unit_t        = unit_p;
        using pointer_t     = pointer_t<unit_t>;
        using allocator_t   = allocator_p;
        using grow_rate_t   = grow_rate_p;

    public:
        static constexpr real_t Grow_Rate();

    private:
    #define self_tr                                                                     \
        template <                                                                      \
            same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_p  \
        >

    #define self_2_tr                                                                       \
        template <                                                                          \
            same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_1_p,   \
            same_as_plain_tr<array_dynamic_t<unit_p, allocator_p, grow_rate_p>> self_2_p    \
        >

        self_2_tr static void_t             Copy(const self_1_p& from, self_2_p& to);
        self_tr static void_t               Destroy(self_p& it);

        self_tr static pointer_t            Pointer(const self_p& self);
        self_tr static count_t              Count(const self_p& self);
        self_tr static const allocator_t&   Allocator(const self_p& self);

        self_tr static count_t              Capacity(const self_p& self);
        self_tr static bool_t               Capacity(self_p& self, count_t new_capacity);

        self_tr static bool_t               Should_Grow(const self_p& self);
        self_tr static bool_t               Grow(self_p& self);

        self_tr static unit_t&              At(const self_p& self, index_t index);
        self_tr static bool_t               Push(self_p& self, const unit_t& unit);
        self_tr static bool_t               Push(self_p& self, unit_t&& unit);
        self_tr static unit_t               Pop(self_p& self);

        self_tr static bool_t               Is_Fit(const self_p& self);
        self_tr static bool_t               Fit(self_p& self);

        self_tr static bool_t               Is_Clear(const self_p& self);
        self_tr static void_t               Clear(self_p& self);

    #undef self_tr
    #undef self_2_tr

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
        pointer_t           Pointer() const;
        pointer_t           Pointer() volatile const;
        count_t             Count() const;
        count_t             Count() volatile const;
        const allocator_t&  Allocator() const;
        const allocator_t&  Allocator() volatile const;

        count_t             Capacity() const;
        count_t             Capacity() volatile const;
        bool_t              Capacity(count_t new_capacity);
        bool_t              Capacity(count_t new_capacity) volatile;

        unit_t&             At(index_t index) const;
        unit_t&             At(index_t index) volatile const;
        bool_t              Push(const unit_t& unit);
        bool_t              Push(const unit_t& unit) volatile;
        bool_t              Push(unit_t&& unit);
        bool_t              Push(unit_t&& unit) volatile;
        unit_t              Pop();
        unit_t              Pop() volatile;

        bool_t              Is_Fit() const;
        bool_t              Is_Fit() volatile const;
        bool_t              Fit();
        bool_t              Fit() volatile;

        bool_t              Is_Clear() const;
        bool_t              Is_Clear() volatile const;
        void_t              Clear();
        void_t              Clear() volatile;

    private:
        bool_t  Should_Grow() const;
        bool_t  Should_Grow() volatile const;
        bool_t  Grow();
        bool_t  Grow() volatile;

    public:
        unit_t& operator [](index_t index) const;
        unit_t& operator [](index_t index) volatile const;
    };

}
