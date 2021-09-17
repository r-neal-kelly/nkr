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

namespace nkr {

    template <typename type_p, typename unit_p>
    concept push_copy_i = requires(type_p instance, unit_p unit)
    {
        instance.Push(unit);
    };

    template <typename type_p, typename unit_p>
    concept push_move_i = requires(type_p instance, unit_p unit)
    {
        instance.Push(std::move(unit));
    };

    // we'll need to make the array be of byte_ts to stop default ctors, I think.
    // check to make sure because it's going to add complications.
    template <type_tr unit_p, count_t capacity_p>
    class stack_array_t
    {
    public:
        using unit_t    = unit_p;
        using array_t   = unit_t[capacity_p];

    public:
        static constexpr std_bool_t Is_Stack_Array()
        {
            return true;
        }

    public:
        array_t array;
        count_t count;

    public:
        stack_array_t() :
            array{ 0 },
            count(0)
        {
        }

        stack_array_t(const std::same_as<unit_t> auto& ...args) :
            array{ args... },
            count(sizeof...(args))
        {
        }

        stack_array_t(same_as_writable_plain_tr<unit_t> auto&& ...args) :
            array{ std::move(args)... },
            count(sizeof...(args))
        {
        }

        stack_array_t(const stack_array_t& other) :
            array{},
            count(other.count)
        {
            for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                this->array[idx] = other[idx];
            }
        }

        stack_array_t(volatile const stack_array_t& other) :
            array{},
            count(other.count)
        {
            for (index_t idx = 0, end = other.Count(); idx < end; idx += 1) {
                this->array[idx] = other[idx];
            }
        }

    public:
        array_t& Array()
        {
            return this->array;
        }

        count_t Count() const
        {
            return this->count;
        }

        constexpr count_t Capacity() const
        {
            return capacity_p;
        }

        unit_t Pop()
        {
            assert(this->count > 0);

            this->count -= 1;
            if constexpr (built_in_tr<unit_t>) {
                return std::exchange(this->array[this->count], std::remove_cv_t<unit_t>(0));
            } else {
                return std::move(this->array[this->count]);
            }
        }

        void_t Copy_Into(push_copy_i<unit_t> auto& other) const
        {
            for (index_t idx = 0, end = Count(); idx < end; idx += 1) {
                other.Push(this->array[idx]);
            }
        }

        void_t Move_Into(push_move_i<unit_t> auto& other)
        {
            for (index_t idx = 0, end = this->count; idx < end; idx += 1) {
                if constexpr (built_in_tr<unit_t>) {
                    other.Push(std::exchange(this->array[idx], std::remove_cv_t<unit_t>(0)));
                } else {
                    other.Push(std::move(this->array[idx]));
                }
            }
            this->count = 0;
        }

    public:
        unit_t& operator [](index_t index)
        {
            assert(index < this->count);

            return this->array[index];
        }

        const unit_t& operator [](index_t index) const
        {
            assert(index < this->count);

            return this->array[index];
        }
    };

    template <typename type_p>
    concept stack_array_tr =
        type_p::Is_Stack_Array();

    template <typename type_p, typename unit_p>
    concept stack_array_of_tr =
        stack_array_tr<type_p> &&
        std::same_as<unit_p, typename type_p::unit_t>;

    template <writable_tr head_p, std::same_as<head_p> ...tail_p>
    class instant_array_t :
        public stack_array_t<head_p, 1 + sizeof...(tail_p)>
    {
    public:
        using stack_array_t = stack_array_t<head_p, 1 + sizeof...(tail_p)>;

    public:
        instant_array_t(head_p&& head, tail_p&& ...tail) :
            stack_array_t(std::move(head), std::move(tail)...)
        {
        }
    };

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
        static auto&                Units(same_as_plain_tr<dynamic_array_t> auto& self);

        static void_t               Copy(const same_as_plain_tr<dynamic_array_t> auto& from,
                                         same_as_plain_tr<dynamic_array_t> auto& to);
        static void_t               Destroy(same_as_plain_tr<dynamic_array_t> auto& self);

        static pointer_t            Pointer(const same_as_plain_tr<dynamic_array_t> auto& self);
        static count_t              Count(const same_as_plain_tr<dynamic_array_t> auto& self);
        static const allocator_t&   Allocator(const same_as_plain_tr<dynamic_array_t> auto& self);

        static count_t              Capacity(const same_as_plain_tr<dynamic_array_t> auto& self);
        static bool_t               Capacity(same_as_plain_tr<dynamic_array_t> auto& self, count_t new_capacity);

        static bool_t               Should_Grow(const same_as_plain_tr<dynamic_array_t> auto& self);
        static bool_t               Grow(same_as_plain_tr<dynamic_array_t> auto& self);

        static unit_t&              At(const same_as_plain_tr<dynamic_array_t> auto& self, index_t index);
        static bool_t               Push(same_as_plain_tr<dynamic_array_t> auto& self, const unit_t& unit);
        static bool_t               Push(same_as_plain_tr<dynamic_array_t> auto& self, writable_unit_t&& unit);
        static unit_t               Pop(same_as_plain_tr<dynamic_array_t> auto& self);

        static bool_t               Is_Fit(const same_as_plain_tr<dynamic_array_t> auto& self);
        static bool_t               Fit(same_as_plain_tr<dynamic_array_t> auto& self);

        static bool_t               Is_Clear(const same_as_plain_tr<dynamic_array_t> auto& self);
        static void_t               Clear(same_as_plain_tr<dynamic_array_t> auto& self);

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
        dynamic_array_t(volatile const unit_t&& filler, count_t count, const allocator_t& allocator = allocator_t())            = delete;
        dynamic_array_t(volatile const unit_t&& filler, count_t count, allocator_t&& allocator)                                 = delete;

        dynamic_array_t(const array_of_tr<writable_unit_t> auto& array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(const array_of_tr<writable_unit_t> auto& array, allocator_t&& allocator);
        dynamic_array_t(array_of_tr<writable_unit_t> auto&& array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(array_of_tr<writable_unit_t> auto&& array, allocator_t&& allocator);
        dynamic_array_t(volatile const array_of_tr<writable_unit_t> auto&& array, const allocator_t& allocator = allocator_t()) = delete;
        dynamic_array_t(volatile const array_of_tr<writable_unit_t> auto&& array, allocator_t&& allocator)                      = delete;

        dynamic_array_t(const stack_array_of_tr<unit_t> auto& stack_array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(const stack_array_of_tr<unit_t> auto& stack_array, allocator_t&& allocator);
        dynamic_array_t(stack_array_of_tr<writable_unit_t> auto&& stack_array, const allocator_t& allocator = allocator_t());
        dynamic_array_t(stack_array_of_tr<writable_unit_t> auto&& stack_array, allocator_t&& allocator);

        template <same_as_plain_tr<dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t> ...units_p>
        dynamic_array_t(const instant_array_t<units_p...>& instant_array, const allocator_t& allocator = allocator_t());
        template <same_as_plain_tr<dynamic_array_t<unit_p, allocator_p, grow_rate_p>::unit_t> ...units_p>
        dynamic_array_t(const instant_array_t<units_p...>& instant_array, allocator_t&& allocator);
        template <same_as_plain_tr<dynamic_array_t<unit_p, allocator_p, grow_rate_p>::writable_unit_t> ...writable_units_p>
        dynamic_array_t(instant_array_t<writable_units_p...>&& instant_array, const allocator_t& allocator = allocator_t());
        template <same_as_plain_tr<dynamic_array_t<unit_p, allocator_p, grow_rate_p>::writable_unit_t> ...writable_units_p>
        dynamic_array_t(instant_array_t<writable_units_p...>&& instant_array, allocator_t&& allocator);

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
        pointer_t           Pointer() const;
        pointer_t           Pointer() volatile const;
        count_t             Count() const;
        count_t             Count() volatile const;
        const allocator_t&  Allocator() const;
        const allocator_t&  Allocator() volatile const;

        count_t             Capacity() const;
        count_t             Capacity() volatile const;
        bool_t              Capacity(count_t new_capacity);
        bool_t              Capacity(count_t new_capacity) volatile;

        unit_t&             At(index_t index) const;
        unit_t&             At(index_t index) volatile const;
        bool_t              Push(const unit_t& unit);
        bool_t              Push(const unit_t& unit) volatile;
        bool_t              Push(writable_unit_t&& unit);
        bool_t              Push(writable_unit_t&& unit) volatile;
        bool_t              Push(volatile const unit_t&& unit)          = delete;
        bool_t              Push(volatile const unit_t&& unit) volatile = delete;
        unit_t              Pop();
        unit_t              Pop() volatile;

        bool_t              Is_Fit() const;
        bool_t              Is_Fit() volatile const;
        bool_t              Fit();
        bool_t              Fit() volatile;

        bool_t              Is_Clear() const;
        bool_t              Is_Clear() volatile const;
        void_t              Clear();
        void_t              Clear() volatile;

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
