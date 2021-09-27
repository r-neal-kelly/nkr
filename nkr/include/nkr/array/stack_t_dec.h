/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "nkr/array_i.h"

namespace nkr {

    template <any_type_tr unit_p, count_t capacity_p>
    class stack_array_t;

    template <typename array_p>
    concept any_stack_array_tr =
        is_any_tr<array_p, stack_array_t<typename array_p::unit_t, array_p::Capacity()>>;

    nkr_DEFINE_CONTAINER_TRAITS(stack_array, unit_t);

}

namespace nkr {

    template <any_type_tr unit_p, count_t capacity_p>
    class stack_array_t
    {
    public:
        using unit_t            = unit_p;
        using writable_unit_t   = std::remove_const_t<unit_t>;
        using array_t           = unit_t[capacity_p];
        using writable_array_t  = writable_unit_t[capacity_p];

    protected:
        using byte_array_t  = byte_t[capacity_p * sizeof(unit_t)];

    public:
        static constexpr count_t    Capacity();

    private:
        static void_t   Copy_Construct(is_any_non_const_tr<stack_array_t> auto& self,
                                       const is_any_tr<stack_array_t> auto& other);
        static void_t   Move_Construct(is_any_non_const_tr<stack_array_t> auto& self,
                                       is_any_non_const_tr<stack_array_t> auto& other);
        static void_t   Destruct(is_any_tr<stack_array_t> auto& self);

        static auto&    Array(is_any_tr<stack_array_t> auto& self);
        static auto&    Writable_Array(is_any_non_const_tr<stack_array_t> auto& self);
        static count_t  Count(const is_any_tr<stack_array_t> auto& self);

        static auto&    At(is_any_tr<stack_array_t> auto& self, index_t index);
        static void_t   Push(is_any_non_const_tr<stack_array_t> auto& self,
                             is_any_tr<unit_t> auto& unit,
                             is_any_tr<unit_t> auto& ...more_units);
        static void_t   Push(is_any_non_const_tr<stack_array_t> auto& self,
                             is_any_non_const_tr<unit_t> auto&& unit,
                             is_any_non_const_tr<unit_t> auto&& ...more_units);
        static auto     Pop(is_any_non_const_tr<stack_array_t> auto& self);

        static void_t   Copy_To(const is_any_tr<stack_array_t> auto& self,
                                any_non_const_array_of_any_tr<unit_t> auto& other);
        static void_t   Copy_From(is_any_non_const_tr<stack_array_t> auto& self,
                                  const any_array_of_any_tr<unit_t> auto& other);
        static void_t   Move_To(any_non_const_stack_array_of_any_non_const_tr<unit_t> auto& self,
                                any_non_const_array_of_any_tr<unit_t> auto& other);
        static void_t   Move_From(is_any_non_const_tr<stack_array_t> auto& self,
                                  any_non_const_array_of_any_non_const_tr<unit_t> auto& other);

        static bool_t   Is_Clear(const is_any_tr<stack_array_t> auto& self);
        static void_t   Clear(is_any_non_const_tr<stack_array_t> auto& self);

    protected:
        count_t         unit_count;
        byte_array_t    byte_array;

    public:
        stack_array_t();

        stack_array_t(is_any_tr<unit_t> auto& ...args);
        stack_array_t(is_any_non_const_tr<unit_t> auto&& ...args);

        stack_array_t(const stack_array_t& other);
        stack_array_t(const volatile stack_array_t& other);
        stack_array_t(stack_array_t&& other) noexcept;
        stack_array_t(volatile stack_array_t&& other) noexcept;

        stack_array_t&          operator =(const stack_array_t& other);
        volatile stack_array_t& operator =(const stack_array_t& other) volatile;
        stack_array_t&          operator =(const volatile stack_array_t& other);
        volatile stack_array_t& operator =(const volatile stack_array_t& other) volatile;
        stack_array_t&          operator =(stack_array_t&& other) noexcept;
        volatile stack_array_t& operator =(stack_array_t&& other) volatile noexcept;
        template <is_just_volatile_tr<stack_array_t<unit_p, capacity_p>> other_p>
        stack_array_t&          operator =(other_p&& other) noexcept;
        template <is_just_volatile_tr<stack_array_t<unit_p, capacity_p>> other_p>
        volatile stack_array_t& operator =(other_p&& other) volatile noexcept;

        ~stack_array_t();

    public:
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
        void_t                  Push(is_any_tr<unit_t> auto& ...units);
        void_t                  Push(is_any_tr<unit_t> auto& ...units) volatile;
        void_t                  Push(not_is_any_tr<unit_t> auto& ...units) const volatile                                   = delete;
        void_t                  Push(is_any_non_const_tr<unit_t> auto&& ...units);
        void_t                  Push(is_any_non_const_tr<unit_t> auto&& ...units) volatile;
        void_t                  Push(not_is_any_non_const_tr<unit_t> auto&& ...units) const volatile                        = delete;
        unit_t                  Pop();
        volatile unit_t         Pop() volatile;

        void_t                  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        void_t                  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;
        void_t                  Copy_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        void_t                  Copy_From(const any_array_of_any_tr<unit_t> auto& other);
        void_t                  Copy_From(const any_array_of_any_tr<unit_t> auto& other) volatile;
        void_t                  Copy_From(const not_any_array_of_any_tr<unit_t> auto& other) const volatile                 = delete;
        void_t                  Move_To(any_non_const_array_of_any_tr<unit_t> auto& other);
        void_t                  Move_To(any_non_const_array_of_any_tr<unit_t> auto& other) volatile;
        void_t                  Move_To(not_any_non_const_array_of_any_tr<unit_t> auto& other) const volatile               = delete;
        void_t                  Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other);
        void_t                  Move_From(any_non_const_array_of_any_non_const_tr<unit_t> auto& other) volatile;
        void_t                  Move_From(not_any_non_const_array_of_any_non_const_tr<unit_t> auto& other) const volatile   = delete;

        bool_t                  Is_Clear() const;
        bool_t                  Is_Clear() const volatile;
        void_t                  Clear();
        void_t                  Clear() volatile;

    private:
        writable_array_t&           Writable_Array();
        volatile writable_array_t&  Writable_Array() volatile;

    public:
        unit_t&                 operator [](index_t index);
        const unit_t&           operator [](index_t index) const;
        volatile unit_t&        operator [](index_t index) volatile;
        const volatile unit_t&  operator [](index_t index) const volatile;
    };
    static_assert(array_i<stack_array_t<word_t, 64>>);
    static_assert(array_i<stack_array_t<const word_t, 64>>);
    static_assert(array_i<stack_array_t<volatile word_t, 64>>);
    static_assert(array_i<stack_array_t<const volatile word_t, 64>>);
    static_assert(array_i<const stack_array_t<word_t, 64>>);
    static_assert(array_i<const stack_array_t<const word_t, 64>>);
    static_assert(array_i<const stack_array_t<volatile word_t, 64>>);
    static_assert(array_i<const stack_array_t<const volatile word_t, 64>>);
    static_assert(array_i<volatile stack_array_t<word_t, 64>>);
    static_assert(array_i<volatile stack_array_t<const word_t, 64>>);
    static_assert(array_i<volatile stack_array_t<volatile word_t, 64>>);
    static_assert(array_i<volatile stack_array_t<const volatile word_t, 64>>);
    static_assert(array_i<const volatile stack_array_t<word_t, 64>>);
    static_assert(array_i<const volatile stack_array_t<const word_t, 64>>);
    static_assert(array_i<const volatile stack_array_t<volatile word_t, 64>>);
    static_assert(array_i<const volatile stack_array_t<const volatile word_t, 64>>);

}

namespace nkr {

    template <any_non_const_tr head_p, is_tr<head_p> ...tail_p>
    class instant_array_t;

    template <typename type_p>
    concept any_instant_array_tr =
        type_p::Is_Instant_Array();

    nkr_DEFINE_CONTAINER_TRAITS(instant_array, unit_t);

}

namespace nkr {

    template <any_non_const_tr head_p, is_tr<head_p> ...tail_p>
    class instant_array_t :
        public stack_array_t<head_p, 1 + sizeof...(tail_p)>
    {
    public:
        using base_t    = stack_array_t<head_p, 1 + sizeof...(tail_p)>;

    public:
        static constexpr std_bool_t Is_Instant_Array()
        {
            return true;
        }

    public:
        // I don't know about the compiler's optimizer, but I don't like the param pack expansion
        // in the base. we can just write all the same funcs that we want here and just do the
        // optimal init with the acutal array type, rather than the byte_array.
        instant_array_t(head_p&& head, tail_p&& ...tail) :
            base_t(std::move(head), std::move(tail)...)
        {
        }
    };
    static_assert(array_i<instant_array_t<word_t>>);
    static_assert(array_i<instant_array_t<volatile word_t>>);
    static_assert(array_i<const instant_array_t<word_t>>);
    static_assert(array_i<const instant_array_t<volatile word_t>>);
    static_assert(array_i<volatile instant_array_t<word_t>>);
    static_assert(array_i<volatile instant_array_t<volatile word_t>>);
    static_assert(array_i<const volatile instant_array_t<word_t>>);
    static_assert(array_i<const volatile instant_array_t<volatile word_t>>);

}
