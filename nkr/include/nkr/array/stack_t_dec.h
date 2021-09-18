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

        static bool_t   Is_Clear(const same_as_any_tr<stack_array_t> auto& self);
        static void_t   Clear(same_as_any_tr<stack_array_t> auto& self);

    protected:
        count_t         unit_count;
        byte_array_t    byte_array;

    public:
        stack_array_t();

        stack_array_t(const same_as_any_tr<unit_t> auto& ...args);
        stack_array_t(same_as_any_writable_tr<unit_t> auto&& ...args);
        stack_array_t(same_as_any_unwritable_tr<unit_t> auto&& ...args) = delete;

        stack_array_t(const stack_array_t& other);
        stack_array_t(volatile const stack_array_t& other);
        stack_array_t(stack_array_t&& other) noexcept;
        stack_array_t(volatile stack_array_t&& other) noexcept;

        stack_array_t& operator =(const stack_array_t& other);
        volatile stack_array_t& operator =(volatile const stack_array_t& other) volatile;
        stack_array_t& operator =(stack_array_t&& other) noexcept;
        volatile stack_array_t& operator =(volatile stack_array_t&& other) volatile noexcept;

        ~stack_array_t();

    public:
        array_t& Array()
        {
            return reinterpret_cast<array_t&>(this->byte_array);
        }

        const array_t& Array() const
        {
            return reinterpret_cast<const array_t&>(this->byte_array);
        }

        count_t Count() const
        {
            return this->unit_count;
        }

        void_t Push(const unit_t& unit)
        {
            assert(this->unit_count < Capacity());

            Writable_Array()[this->unit_count] = unit;
            this->unit_count += 1;
        }

        void_t Push_Many(const std::same_as<unit_t> auto& unit, const std::same_as<unit_t> auto& ...tail)
        {
            Push(unit);
            if constexpr (sizeof...(tail) > 0) {
                Push_Many(tail...);
            }
        }

        void_t Push(writable_unit_t&& unit)
        {
            assert(this->unit_count < Capacity());

            Writable_Array()[this->unit_count] = std::move(unit);
            this->unit_count += 1;
        }

        void_t Push_Many(same_as_any_writable_tr<unit_t> auto&& unit, same_as_any_writable_tr<unit_t> auto&& ...tail)
        {
            Push(std::move(unit));
            if constexpr (sizeof...(tail) > 0) {
                Push_Many(std::move(tail)...);
            }
        }

        unit_t Pop()
        {
            assert(this->unit_count > 0);

            this->unit_count -= 1;
            if constexpr (built_in_tr<unit_t>) {
                return std::exchange(Writable_Array()[this->unit_count], std::remove_cv_t<unit_t>(0));
            } else {
                return std::move(Writable_Array()[this->unit_count]);
            }
        }

        void_t Copy_Into(push_copy_i<unit_t> auto& other) const
        {
            for (index_t idx = 0, end = this->unit_count; idx < end; idx += 1) {
                other.Push(Array()[idx]);
            }
        }

        void_t Move_Into(push_move_i<unit_t> auto& other)
        {
            for (index_t idx = 0, end = this->unit_count; idx < end; idx += 1) {
                if constexpr (built_in_tr<unit_t>) {
                    other.Push(std::exchange(Writable_Array()[idx], std::remove_cv_t<unit_t>(0)));
                } else {
                    other.Push(std::move(Writable_Array()[idx]));
                }
            }
            this->unit_count = 0;
        }

        bool_t  Is_Clear() const;
        bool_t  Is_Clear() volatile const;
        void_t  Clear();
        void_t  Clear() volatile;

    private:
        writable_array_t& Writable_Array()
        {
            return reinterpret_cast<writable_array_t&>(this->byte_array);
        }

    public:
        unit_t& operator [](index_t index)
        {
            assert(index < this->unit_count);

            return Array()[index];
        }

        const unit_t& operator [](index_t index) const
        {
            assert(index < this->unit_count);

            return Array()[index];
        }
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
