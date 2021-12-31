/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_pointer_t.h"
#include "nkr/z_traits.h"

#include "nkr/z_allocator_err.h"

#include "nkr/z_array_i.h"

namespace nkr { namespace array {

    template <typename unit_p, count_t capacity_p>
    class stack_t;

    struct                      stack_tg    {};
    template <typename> struct  stack_ttg   {};

}}

namespace nkr { namespace array { namespace $stack_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, stack_t<typename type_p::unit_t, type_p::Capacity()>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<array::stack_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <array::$stack_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<array::stack_tg>
    {
    public:
        using of_t  = type_p::unit_t;
    };

    template <>
    class template_traits_i<array::stack_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = array::stack_t<of_p, 1>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

}

// to be deleted
namespace nkr { namespace array {

    template <typename array_p>
    concept any_stack_tr =
        is_any_tr<array_p, stack_t<typename array_p::unit_t, array_p::Capacity()>>;

    nkr_DEFINE_CONTAINER_TRAITS(stack, unit_t);

}}
//

namespace nkr { namespace array {

    template <typename unit_p, count_t capacity_p = Default_Unit_Count()>
    class stack_t
    {
    public:
        stack_t()                                                                                   = delete;

        stack_t(const stack_t& other)                                                               = delete;
        stack_t(const volatile stack_t& other)                                                      = delete;
        stack_t(stack_t&& other) noexcept                                                           = delete;
        stack_t(volatile stack_t&& other) noexcept                                                  = delete;

        stack_t&            operator =(const stack_t& other)                                        = delete;
        volatile stack_t&   operator =(const stack_t& other) volatile                               = delete;
        stack_t&            operator =(const volatile stack_t& other)                               = delete;
        volatile stack_t&   operator =(const volatile stack_t& other) volatile                      = delete;
        stack_t&            operator =(stack_t&& other) noexcept                                    = delete;
        volatile stack_t&   operator =(stack_t&& other) volatile noexcept                           = delete;
        stack_t&            operator =(is_just_volatile_tr<stack_t> auto&& other) noexcept          = delete;
        volatile stack_t&   operator =(is_just_volatile_tr<stack_t> auto&& other) volatile noexcept = delete;

        ~stack_t()                                                                                  = delete;
    };

    /// @nosubgrouping
    /// @copydoc _eea2eeb3_2ca8_4bbf_bdd0_0eca56b1ebae
    template <any_type_tr unit_p, count_t capacity_p>
    class stack_t<unit_p, capacity_p>
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
        /// @name static constexpr functions
        /// @copydoc 
        /// @{
        static constexpr count_t    Capacity();
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

        static bool_t                   Has_Memory(const is_any_tr<stack_t> auto& self);

        static auto&                    Array(is_any_tr<stack_t> auto& self);
        static auto&                    Writable_Array(is_any_non_const_tr<stack_t> auto& self);

        static auto                     Pointer(tr1<any_tg, stack_t> auto& self);

        static count_t                  Capacity(const is_any_tr<stack_t> auto& self);
        static maybe_t<allocator_err>   Capacity(is_any_non_const_tr<stack_t> auto& self, count_t new_capacity);
        static maybe_t<allocator_err>   Reserve(tr1<any_non_const_tg, stack_tg> auto& self, count_t capacity_to_reserve);

        static count_t                  Count(const is_any_tr<stack_t> auto& self);
        static maybe_t<allocator_err>   Count(tr1<any_non_const_tg, stack_tg> auto& self, count_t new_unit_count);

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
        bool_t                                      Has_Memory() const;
        bool_t                                      Has_Memory() const volatile;
        
        array_t&                                    Array();
        const array_t&                              Array() const;
        volatile array_t&                           Array() volatile;
        const volatile array_t&                     Array() const volatile;

        maybe_t<pointer_t<unit_t>>                  Pointer();
        maybe_t<pointer_t<const unit_t>>            Pointer() const;
        maybe_t<pointer_t<volatile unit_t>>         Pointer() volatile;
        maybe_t<pointer_t<const volatile unit_t>>   Pointer() const volatile;

        maybe_t<allocator_err>                      Capacity(count_t new_capacity);
        maybe_t<allocator_err>                      Capacity(count_t new_capacity) volatile;
        maybe_t<allocator_err>                      Reserve(count_t capacity_to_reserve);
        maybe_t<allocator_err>                      Reserve(count_t capacity_to_reserve) volatile;

        count_t                                     Count() const;
        count_t                                     Count() const volatile;
        maybe_t<allocator_err>                      Count(count_t new_unit_count);
        maybe_t<allocator_err>                      Count(count_t new_unit_count) volatile;

        unit_t&                                     At(index_t index);
        const unit_t&                               At(index_t index) const;
        volatile unit_t&                            At(index_t index) volatile;
        const volatile unit_t&                      At(index_t index) const volatile;
        maybe_t<allocator_err>                      Push(is_any_tr<unit_t> auto& ...units);
        maybe_t<allocator_err>                      Push(is_any_tr<unit_t> auto& ...units) volatile;
        maybe_t<allocator_err>                      Push(not_is_any_tr<unit_t> auto& ...units) const volatile                                   = delete;
        maybe_t<allocator_err>                      Push(is_any_non_const_tr<unit_t> auto&& ...units);
        maybe_t<allocator_err>                      Push(is_any_non_const_tr<unit_t> auto&& ...units) volatile;
        maybe_t<allocator_err>                      Push(not_is_any_non_const_tr<unit_t> auto&& ...units) const volatile                        = delete;
        unit_t                                      Pop();
        volatile unit_t                             Pop() volatile;

        maybe_t<allocator_err>                      Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        maybe_t<allocator_err>                      Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;
        maybe_t<allocator_err>                      Copy_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        maybe_t<allocator_err>                      Copy_From(const any_array_of_any_tr<unit_t> auto& other);
        maybe_t<allocator_err>                      Copy_From(const any_array_of_any_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>                      Copy_From(const not_any_array_of_any_tr<unit_t> auto& other) const volatile                 = delete;
        maybe_t<allocator_err>                      Move_To(any_non_const_array_of_any_tr<unit_t> auto& other);
        maybe_t<allocator_err>                      Move_To(any_non_const_array_of_any_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>                      Move_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        maybe_t<allocator_err>                      Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other);
        maybe_t<allocator_err>                      Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other) volatile;
        maybe_t<allocator_err>                      Move_From(not_any_non_const_array_of_any_non_const_tr<unit_t> auto& other) const volatile   = delete;

        bool_t                                      Is_Clear() const;
        bool_t                                      Is_Clear() const volatile;
        void_t                                      Clear();
        void_t                                      Clear() volatile;
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

    static_assert(array_i<stack_t<word_t>>);
    static_assert(array_i<stack_t<const word_t>>);
    static_assert(array_i<stack_t<volatile word_t>>);
    static_assert(array_i<stack_t<const volatile word_t>>);
    static_assert(array_i<const stack_t<word_t>>);
    static_assert(array_i<const stack_t<const word_t>>);
    static_assert(array_i<const stack_t<volatile word_t>>);
    static_assert(array_i<const stack_t<const volatile word_t>>);
    static_assert(array_i<volatile stack_t<word_t>>);
    static_assert(array_i<volatile stack_t<const word_t>>);
    static_assert(array_i<volatile stack_t<volatile word_t>>);
    static_assert(array_i<volatile stack_t<const volatile word_t>>);
    static_assert(array_i<const volatile stack_t<word_t>>);
    static_assert(array_i<const volatile stack_t<const word_t>>);
    static_assert(array_i<const volatile stack_t<volatile word_t>>);
    static_assert(array_i<const volatile stack_t<const volatile word_t>>);

    static_assert(aggregate_array_i<stack_t<word_t>>);
    static_assert(aggregate_array_i<stack_t<const word_t>>);
    static_assert(aggregate_array_i<stack_t<volatile word_t>>);
    static_assert(aggregate_array_i<stack_t<const volatile word_t>>);
    static_assert(aggregate_array_i<const stack_t<word_t>>);
    static_assert(aggregate_array_i<const stack_t<const word_t>>);
    static_assert(aggregate_array_i<const stack_t<volatile word_t>>);
    static_assert(aggregate_array_i<const stack_t<const volatile word_t>>);
    static_assert(aggregate_array_i<volatile stack_t<word_t>>);
    static_assert(aggregate_array_i<volatile stack_t<const word_t>>);
    static_assert(aggregate_array_i<volatile stack_t<volatile word_t>>);
    static_assert(aggregate_array_i<volatile stack_t<const volatile word_t>>);
    static_assert(aggregate_array_i<const volatile stack_t<word_t>>);
    static_assert(aggregate_array_i<const volatile stack_t<const word_t>>);
    static_assert(aggregate_array_i<const volatile stack_t<volatile word_t>>);
    static_assert(aggregate_array_i<const volatile stack_t<const volatile word_t>>);

    static_assert(pointable_array_i<stack_t<word_t>>);
    static_assert(pointable_array_i<stack_t<const word_t>>);
    static_assert(pointable_array_i<stack_t<volatile word_t>>);
    static_assert(pointable_array_i<stack_t<const volatile word_t>>);
    static_assert(pointable_array_i<const stack_t<word_t>>);
    static_assert(pointable_array_i<const stack_t<const word_t>>);
    static_assert(pointable_array_i<const stack_t<volatile word_t>>);
    static_assert(pointable_array_i<const stack_t<const volatile word_t>>);
    static_assert(pointable_array_i<volatile stack_t<word_t>>);
    static_assert(pointable_array_i<volatile stack_t<const word_t>>);
    static_assert(pointable_array_i<volatile stack_t<volatile word_t>>);
    static_assert(pointable_array_i<volatile stack_t<const volatile word_t>>);
    static_assert(pointable_array_i<const volatile stack_t<word_t>>);
    static_assert(pointable_array_i<const volatile stack_t<const word_t>>);
    static_assert(pointable_array_i<const volatile stack_t<volatile word_t>>);
    static_assert(pointable_array_i<const volatile stack_t<const volatile word_t>>);

}}

namespace nkr {

    template <
        tr1<any_tg, array::stack_tg>    array_p,
        count_t                         min_unit_count_p    = array::Default_Min_Unit_Count(),
        count_t                         max_unit_count_p    = array::Default_Max_Unit_Count(min_unit_count_p)
    > auto  Random();

}
