/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/array/stack_t.h"

namespace nkr {

    template <type_tr unit_p, count_t capacity_p>
    inline constexpr count_t
        stack_array_t<unit_p, capacity_p>::Capacity()
    {
        return capacity_p;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Copy(const same_as_any_tr<stack_array_t> auto& from,
                                                same_as_any_tr<stack_array_t> auto& to)
    {
        assert(to.unit_count == 0);

        for (index_t idx = 0, end = from.unit_count; idx < end; idx += 1) {
            to.Writable_Array()[idx] = from.Array()[idx];
        }
        to.unit_count = from.unit_count;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Move(const same_as_any_tr<stack_array_t> auto& from,
                                                same_as_any_tr<stack_array_t> auto& to)
    {
        assert(to.unit_count == 0);

        for (index_t idx = 0, end = from.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                to.Writable_Array()[idx] = std::exchange(from.Writable_Array()[idx], std::remove_cv_t<unit_t>(0));
            } else {
                to.Writable_Array()[idx] = std::move(from.Writable_Array()[idx]);
            }
        }
        to.unit_count = from.unit_count;
        from.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Destroy(same_as_any_tr<stack_array_t> auto& self)
    {
        self.Clear();
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear(const same_as_any_tr<stack_array_t> auto& self)
    {
        return self.unit_count == 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear(same_as_any_tr<stack_array_t> auto& self)
    {
        for (index_t idx = 0, end = self.unit_count; idx < end; idx += 1) {
            if constexpr (built_in_tr<unit_t>) {
                self.Writable_Array()[idx] = std::remove_cv_t<unit_t>(0);
            } else {
                self.Writable_Array()[idx].~unit_t();
            }
        }
        self.unit_count = 0;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t() :
        unit_count(0)
    {
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(const same_as_any_tr<unit_t> auto& ...args) :
        unit_count(0)
    {
        assert(sizeof...(args) <= Capacity());

        Push_Many(args...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(same_as_any_writable_tr<unit_t> auto&& ...args) :
        unit_count(0)
    {
        assert(sizeof...(args) <= Capacity());

        Push_Many(std::move(args)...);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(const stack_array_t& other) :
        unit_count(0)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(volatile const stack_array_t& other) :
        unit_count(0)
    {
        Copy(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(stack_array_t&& other) noexcept :
        unit_count(0)
    {
        Move(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::stack_array_t(volatile stack_array_t&& other) noexcept :
        unit_count(0)
    {
        Move(other, *this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(const stack_array_t& other)
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(volatile const stack_array_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Copy(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(stack_array_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Move(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline typename volatile stack_array_t<unit_p, capacity_p>&
        stack_array_t<unit_p, capacity_p>::operator =(volatile stack_array_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            Destroy(*this);
            Move(other, *this);
        }
        return *this;
    }

    template <type_tr unit_p, count_t capacity_p>
    inline stack_array_t<unit_p, capacity_p>::~stack_array_t()
    {
        Destroy(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear()
        const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline bool_t
        stack_array_t<unit_p, capacity_p>::Is_Clear()
        volatile const
    {
        return Is_Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear()
    {
        return Clear(*this);
    }

    template <type_tr unit_p, count_t capacity_p>
    inline void_t
        stack_array_t<unit_p, capacity_p>::Clear()
        volatile
    {
        return Clear(*this);
    }

}
