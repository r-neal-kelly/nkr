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

#include "nkr/array_i.h"
#include "nkr/array/stack_t.h"

namespace nkr {

    template <
        type_tr             unit_p,
        allocator_i         allocator_p = allocator::heap_t<unit_p>,
        math::fraction_i    grow_rate_p = math::fraction_t<17, 10>
    > class dynamic_array_t
    {
    public:
        static_assert(std::same_as<unit_p, allocator_p::unit_t>, "allocator has a different unit_t");

    public:
        using unit_t                = unit_p;
        using writable_unit_t       = std::remove_const_t<unit_t>;
        using pointer_t             = nkr::pointer_t<unit_t>;
        using writable_pointer_t    = nkr::pointer_t<writable_unit_t>;
        using allocator_t           = allocator_p;
        using grow_rate_t           = grow_rate_p;

    public:
        static constexpr real_t Grow_Rate();

    private:
        static auto&        Units(same_as_any_tr<dynamic_array_t> auto& self);

        static void_t       Copy(const same_as_any_tr<dynamic_array_t> auto& from,
                                         same_as_any_tr<dynamic_array_t> auto& to);
        static void_t       Destroy(same_as_any_tr<dynamic_array_t> auto& self);

        static pointer_t    Pointer(const same_as_any_tr<dynamic_array_t> auto& self);
        static count_t      Count(const same_as_any_tr<dynamic_array_t> auto& self);
        static auto&        Allocator(const same_as_any_tr<dynamic_array_t> auto& self);

        static count_t      Capacity(const same_as_any_tr<dynamic_array_t> auto& self);
        static bool_t       Capacity(same_as_any_tr<dynamic_array_t> auto& self, count_t new_capacity);

        static bool_t       Should_Grow(const same_as_any_tr<dynamic_array_t> auto& self);
        static bool_t       Grow(same_as_any_tr<dynamic_array_t> auto& self);

        static unit_t&      At(const same_as_any_tr<dynamic_array_t> auto& self, index_t index);
        static bool_t       Push(same_as_any_tr<dynamic_array_t> auto& self, const unit_t& unit);
        static bool_t       Push(same_as_any_tr<dynamic_array_t> auto& self, writable_unit_t&& unit);
        static unit_t       Pop(same_as_any_tr<dynamic_array_t> auto& self);

        static bool_t       Is_Fit(const same_as_any_tr<dynamic_array_t> auto& self);
        static bool_t       Fit(same_as_any_tr<dynamic_array_t> auto& self);

        static bool_t       Is_Clear(const same_as_any_tr<dynamic_array_t> auto& self);
        static void_t       Clear(same_as_any_tr<dynamic_array_t> auto& self);

    protected:
        writable_pointer_t  writable_units;
        count_t             unit_count;
        allocator_t         allocator;

    public:
        dynamic_array_t(const allocator_t& allocator = allocator_t());
        dynamic_array_t(allocator_t&& allocator);

        dynamic_array_t(count_t capacity, const allocator_t& allocator = allocator_t());
        dynamic_array_t(count_t capacity, allocator_t&& allocator);

        dynamic_array_t(const unit_t& filler, count_t count, const allocator_t& allocator = allocator_t());
        dynamic_array_t(const unit_t& filler, count_t count, allocator_t&& allocator);
        dynamic_array_t(writable_unit_t&& filler, count_t count, const allocator_t& allocator = allocator_t());
        dynamic_array_t(writable_unit_t&& filler, count_t count, allocator_t&& allocator);
        dynamic_array_t(volatile const unit_t&& filler, count_t count, const allocator_t& allocator = allocator_t())                    = delete;
        dynamic_array_t(volatile const unit_t&& filler, count_t count, allocator_t&& allocator)                                         = delete;

        dynamic_array_t(const array_of_tr<writable_unit_t> auto& array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(const array_of_tr<writable_unit_t> auto& array, allocator_t&& allocator);
        dynamic_array_t(array_of_tr<writable_unit_t> auto&& array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(array_of_tr<writable_unit_t> auto&& array, allocator_t&& allocator);
        dynamic_array_t(volatile const array_of_tr<writable_unit_t> auto&& array, const allocator_t& allocator = allocator_t())         = delete;
        dynamic_array_t(volatile const array_of_tr<writable_unit_t> auto&& array, allocator_t&& allocator)                              = delete;

        dynamic_array_t(const stack_array_of_any_tr<unit_t> auto& stack_array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(const stack_array_of_any_tr<unit_t> auto& stack_array, allocator_t&& allocator);
        dynamic_array_t(stack_array_of_any_writable_tr<unit_t> auto&& stack_array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(stack_array_of_any_writable_tr<unit_t> auto&& stack_array, allocator_t&& allocator);
        dynamic_array_t(stack_array_of_any_unwritable_tr<unit_t> auto&& stack_array, const allocator_t& allocator = allocator_t())      = delete;   ///< @copydoc _075b7e64_4cb5_4651_b911_2fd1dabeef80
        dynamic_array_t(stack_array_of_any_unwritable_tr<unit_t> auto&& stack_array, allocator_t&& allocator)                           = delete;   ///< @copydoc _d8def8ae_7b56_41a9_8494_b96bbb13c5b9

        dynamic_array_t(const instant_array_of_any_tr<unit_t> auto& instant_array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(const instant_array_of_any_tr<unit_t> auto& instant_array, allocator_t&& allocator);
        dynamic_array_t(instant_array_of_any_writable_tr<unit_t> auto&& instant_array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(instant_array_of_any_writable_tr<unit_t> auto&& instant_array, allocator_t&& allocator);
        dynamic_array_t(instant_array_of_any_unwritable_tr<unit_t> auto&& instant_array, const allocator_t& allocator = allocator_t())  = delete;   ///< @copydoc _965c239c_d5ec_4d39_9832_666e6503019d
        dynamic_array_t(instant_array_of_any_unwritable_tr<unit_t> auto&& instant_array, allocator_t&& allocator)                       = delete;   ///< @copydoc _c1790cd3_ad82_4ddf_9eb2_cc9036a6bc75

        dynamic_array_t(const dynamic_array_t& other);
        dynamic_array_t(volatile const dynamic_array_t& other);
        dynamic_array_t(dynamic_array_t&& other) noexcept;
        dynamic_array_t(volatile dynamic_array_t&& other) noexcept;

        dynamic_array_t&            operator =(const dynamic_array_t& other);
        volatile dynamic_array_t&   operator =(volatile const dynamic_array_t& other) volatile;
        dynamic_array_t&            operator =(dynamic_array_t&& other) noexcept;
        volatile dynamic_array_t&   operator =(volatile dynamic_array_t&& other) volatile noexcept;

        ~dynamic_array_t();

    public:
        pointer_t                   Pointer() const;
        pointer_t                   Pointer() volatile const;
        count_t                     Count() const;
        count_t                     Count() volatile const;
        const allocator_t&          Allocator() const;
        volatile const allocator_t& Allocator() volatile const;

        count_t                     Capacity() const;
        count_t                     Capacity() volatile const;
        bool_t                      Capacity(count_t new_capacity);
        bool_t                      Capacity(count_t new_capacity) volatile;

        unit_t&                     At(index_t index) const;
        unit_t&                     At(index_t index) volatile const;
        bool_t                      Push(const unit_t& unit);
        bool_t                      Push(const unit_t& unit) volatile;
        bool_t                      Push(writable_unit_t&& unit);
        bool_t                      Push(writable_unit_t&& unit) volatile;
        bool_t                      Push(volatile const unit_t&& unit)          = delete;
        bool_t                      Push(volatile const unit_t&& unit) volatile = delete;
        unit_t                      Pop();
        unit_t                      Pop() volatile;

        bool_t                      Is_Fit() const;
        bool_t                      Is_Fit() volatile const;
        bool_t                      Fit();
        bool_t                      Fit() volatile;

        bool_t                      Is_Clear() const;
        bool_t                      Is_Clear() volatile const;
        void_t                      Clear();
        void_t                      Clear() volatile;

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
