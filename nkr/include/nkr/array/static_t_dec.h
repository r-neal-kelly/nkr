/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array_i.h"

namespace nkr { namespace array {

    // needs to assert when missing its pointer. I can't imagine the use of having a nullptr static_t.
    // may added ctors that take a stack_t and a dynamic_t directly, but for now we just do a pointer.

    template <any_type_tr unit_p>
    class static_t
    {
    public:
        using unit_t    = unit_p;
        using pointer_t = nkr::pointer_t<unit_p>;

    protected:
        pointer_t   pointer;

    public:
        static_t();

        static_t(const pointer_t& pointer);
        static_t(pointer_t&& pointer);

        static_t(const static_t& other);
        static_t(const volatile static_t& other);
        static_t(static_t&& other) noexcept;
        static_t(volatile static_t&& other) noexcept;

        static_t&           operator =(const static_t& other);
        volatile static_t&  operator =(const static_t& other) volatile;
        static_t&           operator =(const volatile static_t& other);
        volatile static_t&  operator =(const volatile static_t& other) volatile;
        static_t&           operator =(static_t&& other) noexcept;
        volatile static_t&  operator =(static_t&& other) volatile noexcept;
        static_t&           operator =(is_just_volatile_tr<static_t> auto&& other) noexcept;
        volatile static_t&  operator =(is_just_volatile_tr<static_t> auto&& other) volatile noexcept;

        ~static_t();

    public:
        pointer_t               Pointer() const;
        pointer_t               Pointer() const volatile;
        void_t                  Pointer(pointer_t new_pointer);
        void_t                  Pointer(pointer_t new_pointer) volatile;

        count_t                 Count() const;
        count_t                 Count() const volatile;

        unit_t&                 At(index_t index) const;
        unit_t&                 At(index_t index) const volatile;

        maybe_t<allocator_err>  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        maybe_t<allocator_err>  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;

    public:
        unit_t& operator [](index_t index) const;
        unit_t& operator [](index_t index) const volatile;
    };
    static_assert(array_i<static_t<word_t>>);
    static_assert(array_i<static_t<const word_t>>);
    static_assert(array_i<static_t<volatile word_t>>);
    static_assert(array_i<static_t<const volatile word_t>>);
    static_assert(array_i<const static_t<word_t>>);
    static_assert(array_i<const static_t<const word_t>>);
    static_assert(array_i<const static_t<volatile word_t>>);
    static_assert(array_i<const static_t<const volatile word_t>>);
    static_assert(array_i<volatile static_t<word_t>>);
    static_assert(array_i<volatile static_t<const word_t>>);
    static_assert(array_i<volatile static_t<volatile word_t>>);
    static_assert(array_i<volatile static_t<const volatile word_t>>);
    static_assert(array_i<const volatile static_t<word_t>>);
    static_assert(array_i<const volatile static_t<const word_t>>);
    static_assert(array_i<const volatile static_t<volatile word_t>>);
    static_assert(array_i<const volatile static_t<const volatile word_t>>);

}}
