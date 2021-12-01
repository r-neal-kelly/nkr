/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/array/static_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<array::static_tg>::Is_Any()
    {
        return array::$static_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<array::static_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    inline auto&
        static_t<unit_p>::Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.pointer = other.pointer;
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline auto&
        static_t<unit_p>::Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto&& other)
    {
        if (&self != std::addressof(other)) {
            self.pointer = nkr::Move(other.pointer);
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline bool_t
        static_t<unit_p>::Has_Memory(const is_any_tr<static_t> auto& self)
    {
        return self.pointer;
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count(const is_any_tr<static_t> auto& self)
    {
        return self.pointer.Unit_Count();
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::At(const is_any_tr<static_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(index < Count(self));

        return self.pointer[index];
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t() :
        pointer()
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const maybe_t<pointer_t>& pointer) :
        pointer(pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(maybe_t<pointer_t>&& pointer) :
        pointer(nkr::Move(pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array) :
        pointer(maybe_t<pointer_t>(&array[0], array.Count()))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const static_t& other) :
        pointer(other.pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(const volatile static_t& other) :
        pointer(other.pointer)
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(static_t&& other) noexcept :
        pointer(nkr::Move(other.pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::static_t(volatile static_t&& other) noexcept :
        pointer(nkr::Move(other.pointer))
    {
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(const static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(const static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(const volatile static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(const volatile static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(static_t&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>&
        static_t<unit_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile static_t<unit_p>&
        static_t<unit_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline static_t<unit_p>::~static_t()
    {
    }

    template <any_type_tr unit_p>
    inline bool_t
        static_t<unit_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline bool_t
        static_t<unit_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count()
        const
    {
        return Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        static_t<unit_p>::Count()
        const volatile
    {
        return Count(*this);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::At(index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::At(index_t index)
        const volatile
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        const
    {
        return At(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename static_t<unit_p>::unit_t&
        static_t<unit_p>::operator [](index_t index)
        const volatile
    {
        return At(*this, index);
    }

}}

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<array::extra_static_tg>::Is_Any()
    {
        return array::$extra_static_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<array::extra_static_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    inline auto&
        extra_static_t<unit_p>::Copy_Assign(is_any_non_const_tr<extra_static_t> auto& self, const is_any_tr<extra_static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.static_array = other.static_array;
            self.total_unit_count = other.total_unit_count;
            self.extra_unit = other.extra_unit;
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline auto&
        extra_static_t<unit_p>::Move_Assign(is_any_non_const_tr<extra_static_t> auto& self, is_any_non_const_tr<extra_static_t> auto&& other)
    {
        if (&self != std::addressof(other)) {
            self.static_array = nkr::Move(other.static_array);
            self.total_unit_count = nkr::Move(other.total_unit_count);
            self.extra_unit = nkr::Move(other.extra_unit);
        }

        return self;
    }

    template <any_type_tr unit_p>
    inline bool_t
        extra_static_t<unit_p>::Has_Memory(const is_any_tr<extra_static_t> auto& self)
    {
        return self.static_array.Has_Memory();
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Unit_Count(const is_any_tr<extra_static_t> auto& self)
    {
        return self.total_unit_count;
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Actual_Unit_Count(const is_any_tr<extra_static_t> auto& self)
    {
        return self.static_array.Count();
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Extra_Unit_Count(const is_any_tr<extra_static_t> auto& self)
    {
        return self.total_unit_count - self.static_array.Count();
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Total_Unit_Count(const is_any_tr<extra_static_t> auto& self)
    {
        return self.total_unit_count;
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::Unit(const is_any_tr<extra_static_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(index < Count(self));

        if (index < Actual_Count(self)) {
            return self.static_array[index];
        } else {
            return Extra_Unit(self);
        }
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::Extra_Unit(const is_any_tr<extra_static_t> auto& self)
    {
        return self.extra_unit;
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t() :
        static_array(),
        total_unit_count(0),
        extra_unit()
    {
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array) :
        static_array(array),
        total_unit_count(this->static_array.Count()),
        extra_unit()
    {
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array,
                                                  count_t total_unit_count) :
        static_array(array),
        total_unit_count(total_unit_count),
        extra_unit()
    {
        nkr_ASSERT_THAT(Total_Unit_Count(*this) >= Actual_Unit_Count(*this));
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array,
                                                  count_t total_unit_count,
                                                  const tr1<any_tg, unit_t> auto& extra_unit) :
        static_array(array),
        total_unit_count(total_unit_count),
        extra_unit(extra_unit)
    {
        nkr_ASSERT_THAT(Total_Unit_Count(*this) >= Actual_Unit_Count(*this));
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array,
                                                  count_t total_unit_count,
                                                  tr1<any_non_const_tg, unit_t> auto&& extra_unit) :
        static_array(array),
        total_unit_count(total_unit_count),
        extra_unit(nkr::Move(extra_unit))
    {
        nkr_ASSERT_THAT(Total_Unit_Count(*this) >= Actual_Unit_Count(*this));
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(const extra_static_t& other) :
        static_array(other.static_array),
        total_unit_count(other.total_unit_count),
        extra_unit(other.extra_unit)
    {
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(const volatile extra_static_t& other) :
        static_array(other.static_array),
        total_unit_count(other.total_unit_count),
        extra_unit(other.extra_unit)
    {
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(extra_static_t&& other) noexcept :
        static_array(nkr::Move(other.static_array)),
        total_unit_count(nkr::Move(other.total_unit_count)),
        extra_unit(nkr::Move(other.extra_unit))
    {
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::extra_static_t(volatile extra_static_t&& other) noexcept :
        static_array(nkr::Move(other.static_array)),
        total_unit_count(nkr::Move(other.total_unit_count)),
        extra_unit(nkr::Move(other.extra_unit))
    {
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(const extra_static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(const extra_static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(const volatile extra_static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(const volatile extra_static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(extra_static_t&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(extra_static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(is_just_volatile_tr<extra_static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile extra_static_t<unit_p>&
        extra_static_t<unit_p>::operator =(is_just_volatile_tr<extra_static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline extra_static_t<unit_p>::~extra_static_t()
    {
        this->total_unit_count = 0;
        if constexpr (built_in_tr<unit_t>) {
            this->extra_unit = none_t();
        }
    }

    template <any_type_tr unit_p>
    inline bool_t
        extra_static_t<unit_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline bool_t
        extra_static_t<unit_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Count()
        const
    {
        return Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Count()
        const volatile
    {
        return Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Actual_Unit_Count()
        const
    {
        return Actual_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Actual_Unit_Count()
        const volatile
    {
        return Actual_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Extra_Unit_Count()
        const
    {
        return Extra_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Extra_Unit_Count()
        const volatile
    {
        return Extra_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Total_Unit_Count()
        const
    {
        return Total_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        extra_static_t<unit_p>::Total_Unit_Count()
        const volatile
    {
        return Total_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::Unit(index_t index)
        const
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::Unit(index_t index)
        const volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::Extra_Unit()
        const
    {
        return Extra_Unit(*this);
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::Extra_Unit()
        const volatile
    {
        return Extra_Unit(*this);
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::operator [](index_t index)
        const
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename extra_static_t<unit_p>::unit_t&
        extra_static_t<unit_p>::operator [](index_t index)
        const volatile
    {
        return Unit(*this, index);
    }

}}
