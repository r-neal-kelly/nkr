/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "nkr/array_i.h"

namespace nkr {

    template <type_tr unit_p, count_t capacity_p>
    class stack_array_t
    {
    public:
        using unit_t            = unit_p;
        using writable_unit_t   = std::remove_const_t<unit_t>;
        using array_t           = unit_t[capacity_p];
        using writable_array_t  = writable_unit_t[capacity_p];
        using byte_array_t      = byte_t[capacity_p * sizeof(unit_t)];

    public:
        static constexpr count_t    Capacity();

    private:
        static void_t   Copy(const same_as_any_tr<stack_array_t> auto& from,
                             same_as_any_tr<stack_array_t> auto& to);
        static void_t   Move(const same_as_any_tr<stack_array_t> auto& from,
                             same_as_any_tr<stack_array_t> auto& to);
        static void_t   Destroy(same_as_any_tr<stack_array_t> auto& self);

        static auto&    Array(same_as_any_tr<stack_array_t> auto& self);
        static auto&    Writable_Array(same_as_any_writable_tr<stack_array_t> auto& self);
        static count_t  Count(const same_as_any_tr<stack_array_t> auto& self);

        static auto&    At(same_as_any_tr<stack_array_t> auto& self, index_t index);
        static void_t   Push(same_as_any_writable_tr<stack_array_t> auto& self,
                             const same_as_any_tr<unit_t> auto& unit,
                             const same_as_any_tr<unit_t> auto& ...more_units);
        static void_t   Push(same_as_any_writable_tr<stack_array_t> auto& self,
                             same_as_any_writable_tr<unit_t> auto&& unit,
                             same_as_any_writable_tr<unit_t> auto&& ...more_units);
        static auto     Pop(same_as_any_writable_tr<stack_array_t> auto& self);

        static void_t   Copy_Into(const same_as_any_tr<stack_array_t> auto& self,
                                  push_copy_i<unit_t> auto& other);
        static void_t   Move_Into(same_as_any_writable_tr<stack_array_t> auto& self,
                                  push_move_i<unit_t> auto& other);

        static bool_t   Is_Clear(const same_as_any_tr<stack_array_t> auto& self);
        static void_t   Clear(same_as_any_writable_tr<stack_array_t> auto& self);

    protected:
        count_t         unit_count;
        byte_array_t    byte_array;

    public:
        stack_array_t();

        stack_array_t(const same_as_any_tr<unit_t> auto& ...args);
        stack_array_t(same_as_any_writable_tr<unit_t> auto&& ...args);
        stack_array_t(same_as_any_unwritable_tr<unit_t> auto&& ...args) = delete;

        stack_array_t(const stack_array_t& other);
        stack_array_t(const volatile stack_array_t& other);
        stack_array_t(stack_array_t&& other) noexcept;
        stack_array_t(volatile stack_array_t&& other) noexcept;

        stack_array_t& operator =(const stack_array_t& other);
        volatile stack_array_t& operator =(const volatile stack_array_t& other) volatile;
        stack_array_t& operator =(stack_array_t&& other) noexcept;
        volatile stack_array_t& operator =(volatile stack_array_t&& other) volatile noexcept;

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
        void_t                  Push(const same_as_any_tr<unit_t> auto& ...units);
        void_t                  Push(const same_as_any_tr<unit_t> auto& ...units) volatile;
        void_t                  Push(same_as_any_writable_tr<unit_t> auto&& ...units);
        void_t                  Push(same_as_any_writable_tr<unit_t> auto&& ...units) volatile;
        unit_t                  Pop();
        volatile unit_t         Pop() volatile;

        void_t                  Copy_Into(push_copy_i<unit_t> auto& other) const;
        void_t                  Copy_Into(push_copy_i<unit_t> auto& other) const volatile;
        void_t                  Move_Into(push_move_i<unit_t> auto& other);
        void_t                  Move_Into(push_move_i<volatile unit_t> auto& other) volatile;

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

    template <typename type_p>
    concept stack_array_tr =
        std::same_as<type_p, stack_array_t<typename type_p::unit_t, type_p::Capacity()>>;

    template <typename type_p, typename unit_p>
    concept stack_array_of_tr =
        stack_array_tr<type_p> &&
        std::same_as<unit_p, typename type_p::unit_t>;

    template <typename type_p, typename unit_p>
    concept stack_array_of_any_tr =
        stack_array_tr<type_p> &&
        same_as_any_tr<unit_p, typename type_p::unit_t>;

    template <typename type_p, typename unit_p>
    concept stack_array_of_any_writable_tr =
        stack_array_of_any_tr<type_p, unit_p> &&
        writable_tr<typename type_p::unit_t>;

    template <typename type_p, typename unit_p>
    concept stack_array_of_any_unwritable_tr =
        stack_array_of_any_tr<type_p, unit_p> &&
        unwritable_tr<typename type_p::unit_t>;

    template <writable_tr head_p, std::same_as<head_p> ...tail_p>
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
        // I don't know about the compiler's optimizer, but I hate the param pack expansion
        // in the base. we can just write all the same funcs that we want here and just do the
        // optimal init with the acutal array type, rather than the byte_array.
        instant_array_t(head_p&& head, tail_p&& ...tail) :
            base_t(std::move(head), std::move(tail)...)
        {
        }
    };

    template <typename type_p>
    concept instant_array_tr =
        type_p::Is_Instant_Array();

    template <typename type_p, typename unit_p>
    concept instant_array_of_tr =
        instant_array_tr<type_p> &&
        std::same_as<unit_p, typename type_p::unit_t>;

    template <typename type_p, typename unit_p>
    concept instant_array_of_any_tr =
        instant_array_tr<type_p> &&
        same_as_any_tr<unit_p, typename type_p::unit_t>;

    template <typename type_p, typename unit_p>
    concept instant_array_of_any_writable_tr =
        instant_array_of_any_tr<type_p, unit_p> &&
        writable_tr<typename type_p::unit_t>;

    template <typename type_p, typename unit_p>
    concept instant_array_of_any_unwritable_tr =
        instant_array_of_any_tr<type_p, unit_p> &&
        unwritable_tr<typename type_p::unit_t>;

}
