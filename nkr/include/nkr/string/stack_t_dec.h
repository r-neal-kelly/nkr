/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array/stack_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"
#include "nkr/string_itr.h"

namespace nkr { namespace string {

    template <count_t capacity_p, charcoder_i charcoder_p>
    class stack_t;

    template <typename string_p>
    concept any_stack_tr =
        is_any_tr<string_p, stack_t<string_p::Capacity(), typename string_p::charcoder_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(stack, charcoder_t);

}}

namespace nkr { namespace string {

    // should we reverse this or keep it so it's easy to have a default charcoder?

    template <count_t capacity_p, charcoder_i charcoder_p = charcoder::utf_8_t>
    class stack_t
    {
    public:
        static_assert(capacity_p >= 1, "string::stack_t must have at least a capacity of 1 to fit the terminus");

    public:
        using charcoder_t   = charcoder_p;
        using unit_t        = charcoder_p::unit_t;
        using array_t       = array::stack_t<unit_t, capacity_p>;
        using iterator_t    = string_itr<stack_t>;

    public:
        static const unit_t*            Default_C_String();

    private:
        static auto&                    Copy_Assign(is_any_non_const_tr<stack_t> auto& self, const is_any_tr<stack_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<stack_t> auto& self, is_any_non_const_tr<stack_t> auto& other);

        static bool_t                   Has_Terminus(const is_any_tr<stack_t> auto& self);

        static count_t                  Unit_Capacity(const is_any_tr<stack_t> auto& self);
        static maybe_t<allocator_err>   Unit_Capacity(is_any_non_const_tr<stack_t> auto& self, count_t unit_capacity_including_terminus);

        static count_t                  Unit_Count(const is_any_tr<stack_t> auto& self);
        static count_t                  Unit_Length(const is_any_tr<stack_t> auto& self);

        static count_t                  Point_Count(const is_any_tr<stack_t> auto& self);
        static count_t                  Point_Length(const is_any_tr<stack_t> auto& self);

        static void_t                   Push_Terminus(is_any_non_const_tr<stack_t> auto& self);
        static void_t                   Pop_Terminus(is_any_non_const_tr<stack_t> auto& self);

        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, point_t point);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const charcoder_t& charcoder);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const is_any_tr<unit_t> auto* c_string);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const any_string_tr auto& other);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, any_non_const_string_tr auto&& other);

    protected:
        count_t point_count;
        array_t array;

    public:
        stack_t();

        stack_t(const is_any_tr<unit_t> auto* c_string); // const is_any_some_of_any_tr<unit_t> auto*

        stack_t(const any_string_tr auto& string);
        stack_t(any_non_const_string_tr auto&& string);
        stack_t(any_const_string_tr auto&& string)                                                      = delete;

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

    public:
        bool_t                  Has_Terminus() const;
        bool_t                  Has_Terminus() const volatile;

        count_t                 Unit_Capacity() const;
        count_t                 Unit_Capacity() const volatile;
        maybe_t<allocator_err>  Unit_Capacity(count_t unit_capacity_including_terminus);
        maybe_t<allocator_err>  Unit_Capacity(count_t unit_capacity_including_terminus) volatile;

        count_t                 Unit_Count() const;
        count_t                 Unit_Count() const volatile;
        count_t                 Unit_Length() const;
        count_t                 Unit_Length() const volatile;

        count_t                 Point_Count() const;
        count_t                 Point_Count() const volatile;
        count_t                 Point_Length() const;
        count_t                 Point_Length() const volatile;

        maybe_t<allocator_err>  Push(point_t point);
        maybe_t<allocator_err>  Push(point_t point) volatile;
        maybe_t<allocator_err>  Push(const charcoder_t& charcoder);
        maybe_t<allocator_err>  Push(const charcoder_t& charcoder) volatile;
        maybe_t<allocator_err>  Push(const is_any_tr<unit_t> auto* c_string);
        maybe_t<allocator_err>  Push(const is_any_tr<unit_t> auto* c_string) volatile;
        maybe_t<allocator_err>  Push(const any_string_tr auto& string);
        maybe_t<allocator_err>  Push(const any_string_tr auto& string) volatile;
        maybe_t<allocator_err>  Push(any_non_const_string_tr auto&& string);
        maybe_t<allocator_err>  Push(any_non_const_string_tr auto&& string) volatile;
    };
    static_assert(string_i<stack_t<64>>);
    static_assert(string_i<const stack_t<64>>);
    static_assert(string_i<volatile stack_t<64>>);
    static_assert(string_i<const volatile stack_t<64>>);

}}
