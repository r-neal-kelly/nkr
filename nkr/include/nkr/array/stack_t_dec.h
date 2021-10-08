/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array_i.h"

namespace nkr { namespace array {

    template <any_type_tr unit_p, count_t capacity_p>
    class stack_t;

    template <typename array_p>
    concept any_stack_tr =
        is_any_tr<array_p, stack_t<typename array_p::unit_t, array_p::Capacity()>>;

    nkr_DEFINE_CONTAINER_TRAITS(stack, unit_t);

}}

namespace nkr { namespace array {

    /// @nosubgrouping
    /// @copydoc _eea2eeb3_2ca8_4bbf_bdd0_0eca56b1ebae
    template <any_type_tr unit_p, count_t capacity_p>
    class stack_t
    {
    public:
        /// @name aliases
        /// @copydoc 
        /// @{
        using unit_t            = unit_p;
        using writable_unit_t   = std::remove_const_t<unit_t>;
        using array_t           = unit_t[capacity_p];
        using writable_array_t  = writable_unit_t[capacity_p];
        /// @}

    protected:
        /// @name protected aliases
        /// @copydoc 
        /// @{
        using byte_array_t  = byte_t[capacity_p * sizeof(unit_t)];
        /// @}

    public:
        /// @name static functions
        /// @copydoc 
        /// @{
        static constexpr count_t        Capacity();
        static maybe_t<allocator_err>   Capacity(count_t new_capacity);
        /// @}

    private:
        static void_t                   Copy_Construct(is_any_non_const_tr<stack_t> auto& self,
                                                       const is_any_tr<stack_t> auto& other);
        static void_t                   Move_Construct(is_any_non_const_tr<stack_t> auto& self,
                                                       is_any_non_const_tr<stack_t> auto& other);
        static auto&                    Copy_Assign(is_any_non_const_tr<stack_t> auto& self,
                                                    const is_any_tr<stack_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<stack_t> auto& self,
                                                    is_any_non_const_tr<stack_t> auto& other);

        static auto&                    Array(is_any_tr<stack_t> auto& self);
        static auto&                    Writable_Array(is_any_non_const_tr<stack_t> auto& self);
        static count_t                  Count(const is_any_tr<stack_t> auto& self);

        static auto&                    At(is_any_tr<stack_t> auto& self, index_t index);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self,
                                             is_any_tr<unit_t> auto& ...units);
        static void_t                   Push_Recursively(is_any_non_const_tr<stack_t> auto& self,
                                                         is_any_tr<unit_t> auto& unit,
                                                         is_any_tr<unit_t> auto& ...more_units);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self,
                                             is_any_non_const_tr<unit_t> auto&& ...units);
        static void_t                   Push_Recursively(is_any_non_const_tr<stack_t> auto& self,
                                                         is_any_non_const_tr<unit_t> auto&& unit,
                                                         is_any_non_const_tr<unit_t> auto&& ...more_units);
        static auto                     Pop(is_any_non_const_tr<stack_t> auto& self);

        static maybe_t<allocator_err>   Copy_To(const is_any_tr<stack_t> auto& self,
                                                any_non_const_array_of_any_tr<unit_t> auto& other);
        static maybe_t<allocator_err>   Copy_From(is_any_non_const_tr<stack_t> auto& self,
                                                  const any_array_of_any_tr<unit_t> auto& other);
        static maybe_t<allocator_err>   Move_To(any_non_const_stack_of_any_non_const_tr<unit_t> auto& self,
                                                any_non_const_array_of_any_tr<unit_t> auto& other);
        static maybe_t<allocator_err>   Move_From(is_any_non_const_tr<stack_t> auto& self,
                                                  any_non_const_array_of_any_non_const_tr<unit_t> auto& other);

        static bool_t                   Is_Clear(const is_any_tr<stack_t> auto& self);
        static void_t                   Clear(is_any_non_const_tr<stack_t> auto& self);

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        count_t         unit_count;
        byte_array_t    byte_array;
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        stack_t();

        stack_t(is_any_tr<unit_t> auto& ...args);
        stack_t(is_any_non_const_tr<unit_t> auto&& ...args);

        stack_t(const stack_t& other);
        stack_t(const volatile stack_t& other);
        stack_t(stack_t&& other) noexcept;
        stack_t(volatile stack_t&& other) noexcept;

        stack_t&            operator =(const stack_t& other);
        volatile stack_t&   operator =(const stack_t& other) volatile;
        stack_t&            operator =(const volatile stack_t& other);
        volatile stack_t&   operator =(const volatile stack_t& other) volatile;
        stack_t&            operator =(stack_t&& other) noexcept;
        volatile stack_t&   operator =(stack_t&& other) volatile noexcept;
        stack_t&            operator =(is_just_volatile_tr<stack_t> auto&& other) noexcept;
        volatile stack_t&   operator =(is_just_volatile_tr<stack_t> auto&& other) volatile noexcept;

        ~stack_t();
        /// @}

    public:
        /// @name methods
        /// @copydoc 
        /// @{
        array_t&                Array();
        const array_t&          Array() const;
        volatile array_t&       Array() volatile;
        const volatile array_t& Array() const volatile;
        count_t                 Count() const;
        count_t                 Count() const volatile;

        unit_t&                 At(index_t index);
        const unit_t&           At(index_t index) const;
        volatile unit_t&        At(index_t index) volatile;
        const volatile unit_t&  At(index_t index) const volatile;
        maybe_t<allocator_err>  Push(is_any_tr<unit_t> auto& ...units);
        maybe_t<allocator_err>  Push(is_any_tr<unit_t> auto& ...units) volatile;
        maybe_t<allocator_err>  Push(not_is_any_tr<unit_t> auto& ...units) const volatile                                   = delete;
        maybe_t<allocator_err>  Push(is_any_non_const_tr<unit_t> auto&& ...units);
        maybe_t<allocator_err>  Push(is_any_non_const_tr<unit_t> auto&& ...units) volatile;
        maybe_t<allocator_err>  Push(not_is_any_non_const_tr<unit_t> auto&& ...units) const volatile                        = delete;
        unit_t                  Pop();
        volatile unit_t         Pop() volatile;

        maybe_t<allocator_err>  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        maybe_t<allocator_err>  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;
        maybe_t<allocator_err>  Copy_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        maybe_t<allocator_err>  Copy_From(const any_array_of_any_tr<unit_t> auto& other);
        maybe_t<allocator_err>  Copy_From(const any_array_of_any_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>  Copy_From(const not_any_array_of_any_tr<unit_t> auto& other) const volatile                 = delete;
        maybe_t<allocator_err>  Move_To(any_non_const_array_of_any_tr<unit_t> auto& other);
        maybe_t<allocator_err>  Move_To(any_non_const_array_of_any_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>  Move_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        maybe_t<allocator_err>  Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other);
        maybe_t<allocator_err>  Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>  Move_From(not_any_non_const_array_of_any_non_const_tr<unit_t> auto& other) const volatile   = delete;

        bool_t                  Is_Clear() const;
        bool_t                  Is_Clear() const volatile;
        void_t                  Clear();
        void_t                  Clear() volatile;
        /// @}

    public:
        /// @name operators
        /// @copydoc 
        /// @{
        unit_t&                 operator [](index_t index);
        const unit_t&           operator [](index_t index) const;
        volatile unit_t&        operator [](index_t index) volatile;
        const volatile unit_t&  operator [](index_t index) const volatile;
        /// @}
    };
    static_assert(array_i<stack_t<word_t, 64>>);
    static_assert(array_i<stack_t<const word_t, 64>>);
    static_assert(array_i<stack_t<volatile word_t, 64>>);
    static_assert(array_i<stack_t<const volatile word_t, 64>>);
    static_assert(array_i<const stack_t<word_t, 64>>);
    static_assert(array_i<const stack_t<const word_t, 64>>);
    static_assert(array_i<const stack_t<volatile word_t, 64>>);
    static_assert(array_i<const stack_t<const volatile word_t, 64>>);
    static_assert(array_i<volatile stack_t<word_t, 64>>);
    static_assert(array_i<volatile stack_t<const word_t, 64>>);
    static_assert(array_i<volatile stack_t<volatile word_t, 64>>);
    static_assert(array_i<volatile stack_t<const volatile word_t, 64>>);
    static_assert(array_i<const volatile stack_t<word_t, 64>>);
    static_assert(array_i<const volatile stack_t<const word_t, 64>>);
    static_assert(array_i<const volatile stack_t<volatile word_t, 64>>);
    static_assert(array_i<const volatile stack_t<const volatile word_t, 64>>);

}}
