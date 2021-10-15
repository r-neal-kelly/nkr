/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/math.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"
#include "nkr/allocator_i.h"
#include "nkr/allocator/heap_t.h"

#include "nkr/array_i.h"
#include "nkr/array/instant_t.h"
#include "nkr/array/stack_t.h"

namespace nkr { namespace array {

    template <any_type_tr unit_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    class dynamic_t;

    template <typename array_p>
    concept any_dynamic_tr =
        is_any_tr<array_p, dynamic_t<typename array_p::unit_t, typename array_p::allocator_t, typename array_p::grow_rate_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(dynamic, unit_t);

}}

namespace nkr { namespace array {

    /// @nosubgrouping
    /// @copydoc _70413fdc_3017_4341_a1d3_090d577803c8
    template <
        any_type_tr         unit_p,
        allocator_i         allocator_p = allocator::heap_t<unit_p>,
        math::fraction_i    grow_rate_p = math::fraction_t<17, 10>
    > class dynamic_t
    {
    public:
        static_assert(is_tr<unit_p, allocator_p::unit_t>, "allocator has a different unit_t");

    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t                = unit_p;
        using writable_unit_t       = std::remove_const_t<unit_t>;
        using pointer_t             = nkr::pointer_t<unit_t>;
        using writable_pointer_t    = nkr::pointer_t<writable_unit_t>;
        using allocator_t           = allocator_p;
        using grow_rate_t           = grow_rate_p;
        /// @}

    public:
        /// @name static functions
        /// @copydoc 
        /// @{
        static constexpr real_t Grow_Rate();
        /// @}

    private:
        static auto&                    Units(is_any_tr<dynamic_t> auto& self);

        static void_t                   Copy_Construct(is_any_non_const_tr<dynamic_t> auto& self,
                                                       const is_any_tr<dynamic_t> auto& other);
        static auto&                    Copy_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                    const is_any_tr<dynamic_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                    is_any_non_const_tr<dynamic_t> auto& other);

        static pointer_t                Pointer(const is_any_tr<dynamic_t> auto& self);
        static count_t                  Count(const is_any_tr<dynamic_t> auto& self);

        static count_t                  Capacity(const is_any_tr<dynamic_t> auto& self);
        static maybe_t<allocator_err>   Capacity(is_any_tr<dynamic_t> auto& self, count_t new_capacity);

        static bool_t                   Has_Memory(const is_any_tr<dynamic_t> auto& self);

        static bool_t                   Should_Grow(const is_any_tr<dynamic_t> auto& self);
        static maybe_t<allocator_err>   Grow(is_any_tr<dynamic_t> auto& self);

        static unit_t&                  At(const is_any_tr<dynamic_t> auto& self, index_t index);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const unit_t& unit);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, is_any_non_const_tr<unit_t> auto&& unit);
        static unit_t                   Pop(is_any_tr<dynamic_t> auto& self);

        static maybe_t<allocator_err>   Copy_To(const is_any_tr<dynamic_t> auto& self,
                                                any_non_const_array_of_any_tr<unit_t> auto& other);
        static maybe_t<allocator_err>   Copy_From(is_any_non_const_tr<dynamic_t> auto& self,
                                                  const any_array_of_any_tr<unit_t> auto& other);
        static maybe_t<allocator_err>   Move_To(any_non_const_dynamic_of_any_non_const_tr<unit_t> auto& self,
                                                any_non_const_array_of_any_tr<unit_t> auto& other);
        static maybe_t<allocator_err>   Move_From(is_any_non_const_tr<dynamic_t> auto& self,
                                                  any_non_const_array_of_any_non_const_tr<unit_t> auto& other);

        static bool_t                   Is_Fit(const is_any_tr<dynamic_t> auto& self);
        static maybe_t<allocator_err>   Fit(is_any_tr<dynamic_t> auto& self);

        static bool_t                   Is_Clear(const is_any_tr<dynamic_t> auto& self);
        static void_t                   Clear(is_any_tr<dynamic_t> auto& self);

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        writable_pointer_t  writable_units;
        count_t             unit_count;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        dynamic_t();

        dynamic_t(count_t capacity);

        dynamic_t(const unit_t& filler, count_t count);
        dynamic_t(writable_unit_t&& filler, count_t count);
        dynamic_t(const volatile unit_t&& filler, count_t count)                            = delete;

        dynamic_t(const std_array_of_tr<writable_unit_t> auto& array);
        dynamic_t(std_array_of_tr<writable_unit_t> auto&& array);
        dynamic_t(const volatile std_array_of_tr<writable_unit_t> auto&& array)             = delete;

        dynamic_t(const any_stack_of_any_tr<unit_t> auto& stack_array);
        dynamic_t(any_non_const_stack_of_any_non_const_tr<unit_t> auto&& stack_array);
        dynamic_t(any_stack_of_any_const_tr<unit_t> auto&& stack_array)                     = delete;   ///< @copydoc _075b7e64_4cb5_4651_b911_2fd1dabeef80

        dynamic_t(const any_instant_of_any_tr<unit_t> auto& instant_array);
        dynamic_t(any_non_const_instant_of_any_non_const_tr<unit_t> auto&& instant_array);
        dynamic_t(any_instant_of_any_const_tr<unit_t> auto&& instant_array)                 = delete;   ///< @copydoc _965c239c_d5ec_4d39_9832_666e6503019d

        dynamic_t(const dynamic_t& other);
        dynamic_t(const volatile dynamic_t& other);
        dynamic_t(dynamic_t&& other) noexcept;
        dynamic_t(volatile dynamic_t&& other) noexcept;

        dynamic_t&          operator =(const dynamic_t& other);
        volatile dynamic_t& operator =(const dynamic_t& other) volatile;
        dynamic_t&          operator =(const volatile dynamic_t& other);
        volatile dynamic_t& operator =(const volatile dynamic_t& other) volatile;
        dynamic_t&          operator =(dynamic_t&& other) noexcept;
        volatile dynamic_t& operator =(dynamic_t&& other) volatile noexcept;
        dynamic_t&          operator =(is_just_volatile_tr<dynamic_t> auto&& other) noexcept;
        volatile dynamic_t& operator =(is_just_volatile_tr<dynamic_t> auto&& other) volatile noexcept;

        ~dynamic_t();
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        pointer_t                   Pointer() const;
        pointer_t                   Pointer() const volatile;
        count_t                     Count() const;
        count_t                     Count() const volatile;

        count_t                     Capacity() const;
        count_t                     Capacity() const volatile;
        maybe_t<allocator_err>      Capacity(count_t new_capacity);
        maybe_t<allocator_err>      Capacity(count_t new_capacity) volatile;

        bool_t                      Has_Memory() const;
        bool_t                      Has_Memory() const volatile;

        unit_t&                     At(index_t index) const;
        unit_t&                     At(index_t index) const volatile;
        maybe_t<allocator_err>      Push(const unit_t& unit);
        maybe_t<allocator_err>      Push(const unit_t& unit) volatile;
        maybe_t<allocator_err>      Push(is_any_non_const_tr<unit_t> auto&& unit);
        maybe_t<allocator_err>      Push(is_any_non_const_tr<unit_t> auto&& unit) volatile;
        maybe_t<allocator_err>      Push(is_any_const_tr<unit_t> auto&& unit)                                                   = delete;
        maybe_t<allocator_err>      Push(is_any_const_tr<unit_t> auto&& unit) volatile                                          = delete;
        unit_t                      Pop();
        unit_t                      Pop() volatile;

        maybe_t<allocator_err>      Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        maybe_t<allocator_err>      Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;
        maybe_t<allocator_err>      Copy_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        maybe_t<allocator_err>      Copy_From(const any_array_of_any_tr<unit_t> auto& other);
        maybe_t<allocator_err>      Copy_From(const any_array_of_any_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>      Copy_From(const not_any_array_of_any_tr<unit_t> auto& other) const volatile                 = delete;
        maybe_t<allocator_err>      Move_To(any_non_const_array_of_any_tr<unit_t> auto& other);
        maybe_t<allocator_err>      Move_To(any_non_const_array_of_any_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>      Move_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        maybe_t<allocator_err>      Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other);
        maybe_t<allocator_err>      Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>      Move_From(not_any_non_const_array_of_any_non_const_tr<unit_t> auto& other) const volatile   = delete;

        bool_t                      Is_Fit() const;
        bool_t                      Is_Fit() const volatile;
        maybe_t<allocator_err>      Fit();
        maybe_t<allocator_err>      Fit() volatile;

        bool_t                      Is_Clear() const;
        bool_t                      Is_Clear() const volatile;
        void_t                      Clear();
        void_t                      Clear() volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        unit_t& operator [](index_t index) const;
        unit_t& operator [](index_t index) const volatile;
        /// @}
    };
    static_assert(array_i<dynamic_t<word_t>>);
    static_assert(array_i<dynamic_t<const word_t>>);
    static_assert(array_i<dynamic_t<volatile word_t>>);
    static_assert(array_i<dynamic_t<const volatile word_t>>);
    static_assert(array_i<const dynamic_t<word_t>>);
    static_assert(array_i<const dynamic_t<const word_t>>);
    static_assert(array_i<const dynamic_t<volatile word_t>>);
    static_assert(array_i<const dynamic_t<const volatile word_t>>);
    static_assert(array_i<volatile dynamic_t<word_t>>);
    static_assert(array_i<volatile dynamic_t<const word_t>>);
    static_assert(array_i<volatile dynamic_t<volatile word_t>>);
    static_assert(array_i<volatile dynamic_t<const volatile word_t>>);
    static_assert(array_i<const volatile dynamic_t<word_t>>);
    static_assert(array_i<const volatile dynamic_t<const word_t>>);
    static_assert(array_i<const volatile dynamic_t<volatile word_t>>);
    static_assert(array_i<const volatile dynamic_t<const volatile word_t>>);

}}
