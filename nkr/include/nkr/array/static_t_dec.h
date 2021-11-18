/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array_i.h"

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class static_t
    {
    public:
        using unit_t    = unit_p;
        using pointer_t = nkr::pointer_t<unit_p>;

    private:
        static auto&    Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto& other);

        static count_t  Count(const is_any_tr<static_t> auto& self);

        static unit_t&  At(const is_any_tr<static_t> auto& self, index_t index);

    protected:
        some_t<pointer_t>   pointer;

    public:
        // may want to accept other types of arrays

        static_t(const some_t<pointer_t>& pointer);
        static_t(some_t<pointer_t>&& pointer);

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
        some_t<pointer_t>       Pointer() const;
        some_t<pointer_t>       Pointer() const volatile;
        void_t                  Pointer(some_t<pointer_t> new_pointer);
        void_t                  Pointer(some_t<pointer_t> new_pointer) volatile;

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
