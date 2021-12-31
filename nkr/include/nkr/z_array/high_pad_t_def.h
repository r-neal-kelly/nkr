/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_utils.h"

#include "nkr/z_array/high_pad_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<array::high_pad_tg>::Is_Any()
    {
        return array::$high_pad_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<array::high_pad_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    inline auto&
        high_pad_t<unit_p>::Copy_Assign(is_any_non_const_tr<high_pad_t> auto& self, const is_any_tr<high_pad_t> auto& other)
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
        high_pad_t<unit_p>::Move_Assign(is_any_non_const_tr<high_pad_t> auto& self, is_any_non_const_tr<high_pad_t> auto&& other)
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
        high_pad_t<unit_p>::Has_Memory(const is_any_tr<high_pad_t> auto& self)
    {
        return self.total_unit_count > 0 || self.static_array.Has_Memory();
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Unit_Count(const is_any_tr<high_pad_t> auto& self)
    {
        return self.total_unit_count;
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Non_Extra_Unit_Count(const is_any_tr<high_pad_t> auto& self)
    {
        count_t static_array_count = self.static_array.Count();

        return self.total_unit_count < static_array_count ? self.total_unit_count : static_array_count;
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Extra_Unit_Count(const is_any_tr<high_pad_t> auto& self)
    {
        count_t static_array_count = self.static_array.Count();

        return self.total_unit_count < static_array_count ? 0 : self.total_unit_count - static_array_count;
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Total_Unit_Count(const is_any_tr<high_pad_t> auto& self)
    {
        return self.total_unit_count;
    }

    template <any_type_tr unit_p>
    inline auto&
        high_pad_t<unit_p>::Unit(is_any_tr<high_pad_t> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(index < Unit_Count(self));

        if (index < Non_Extra_Unit_Count(self)) {
            return self.static_array[index];
        } else {
            return Extra_Unit(self);
        }
    }

    template <any_type_tr unit_p>
    inline auto&
        high_pad_t<unit_p>::Extra_Unit(is_any_tr<high_pad_t> auto& self)
    {
        return self.extra_unit;
    }

    template <any_type_tr unit_p>
    inline typename high_pad_t<unit_p>::split_t
        high_pad_t<unit_p>::Split(is_any_tr<high_pad_t> auto& self, index_t at_index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(at_index <= Unit_Count(self));

        count_t non_extra_unit_count = Non_Extra_Unit_Count(self);
        count_t extra_unit_count = Extra_Unit_Count(self);

        if (at_index < non_extra_unit_count) {
            auto static_split = self.static_array.Split(at_index);

            return {
                high_pad_t(static_split[0], static_split[0].Count(), Extra_Unit(self)),
                high_pad_t(static_split[1], static_split[1].Count() + extra_unit_count, Extra_Unit(self))
            };
        } else {
            count_t extra_unit_index = at_index - non_extra_unit_count;
            static_t static_array_copy(self.static_array);

            return {
                high_pad_t(static_array_copy, self.static_array.Count() + extra_unit_index, Extra_Unit(self)),
                high_pad_t(extra_unit_count - extra_unit_index, Extra_Unit(self))
            };
        }
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t() :
        static_array(),
        total_unit_count(0),
        extra_unit()
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array) :
        static_array(array),
        total_unit_count(this->static_array.Count()),
        extra_unit()
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array,
                                          count_t total_unit_count) :
        static_array(array),
        total_unit_count(total_unit_count),
        extra_unit()
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array,
                                          count_t total_unit_count,
                                          const tr1<any_tg, unit_t> auto& extra_unit) :
        static_array(array),
        total_unit_count(total_unit_count),
        extra_unit(extra_unit)
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array,
                                          count_t total_unit_count,
                                          tr1<any_non_const_tg, unit_t> auto&& extra_unit) :
        static_array(array),
        total_unit_count(total_unit_count),
        extra_unit(nkr::Move(extra_unit))
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(count_t total_unit_count) :
        static_array(),
        total_unit_count(total_unit_count),
        extra_unit()
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(count_t total_unit_count, const tr1<any_tg, unit_t> auto& extra_unit) :
        static_array(),
        total_unit_count(total_unit_count),
        extra_unit(extra_unit)
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(count_t total_unit_count, tr1<any_non_const_tg, unit_t> auto&& extra_unit) :
        static_array(),
        total_unit_count(total_unit_count),
        extra_unit(nkr::Move(extra_unit))
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(const high_pad_t& other) :
        static_array(other.static_array),
        total_unit_count(other.total_unit_count),
        extra_unit(other.extra_unit)
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(const volatile high_pad_t& other) :
        static_array(other.static_array),
        total_unit_count(other.total_unit_count),
        extra_unit(other.extra_unit)
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(high_pad_t&& other) noexcept :
        static_array(nkr::Move(other.static_array)),
        total_unit_count(nkr::Move(other.total_unit_count)),
        extra_unit(nkr::Move(other.extra_unit))
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::high_pad_t(volatile high_pad_t&& other) noexcept :
        static_array(nkr::Move(other.static_array)),
        total_unit_count(nkr::Move(other.total_unit_count)),
        extra_unit(nkr::Move(other.extra_unit))
    {
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(const high_pad_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(const high_pad_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(const volatile high_pad_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline volatile high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(const volatile high_pad_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(high_pad_t&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(high_pad_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(is_just_volatile_tr<high_pad_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline volatile high_pad_t<unit_p>&
        high_pad_t<unit_p>::operator =(is_just_volatile_tr<high_pad_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <any_type_tr unit_p>
    inline high_pad_t<unit_p>::~high_pad_t()
    {
        this->total_unit_count = 0;
        if constexpr (built_in_tr<unit_t>) {
            this->extra_unit = unit_t(0);
        }
    }

    template <any_type_tr unit_p>
    inline bool_t
        high_pad_t<unit_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline bool_t
        high_pad_t<unit_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Count()
        const
    {
        return Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Non_Extra_Unit_Count()
        const
    {
        return Non_Extra_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Non_Extra_Unit_Count()
        const volatile
    {
        return Non_Extra_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Extra_Unit_Count()
        const
    {
        return Extra_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Extra_Unit_Count()
        const volatile
    {
        return Extra_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Total_Unit_Count()
        const
    {
        return Total_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline count_t
        high_pad_t<unit_p>::Total_Unit_Count()
        const volatile
    {
        return Total_Unit_Count(*this);
    }

    template <any_type_tr unit_p>
    inline typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Unit(index_t index)
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Unit(index_t index)
        const
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline volatile typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Unit(index_t index)
        volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const volatile typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Unit(index_t index)
        const volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Extra_Unit()
    {
        return Extra_Unit(*this);
    }

    template <any_type_tr unit_p>
    inline const typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Extra_Unit()
        const
    {
        return Extra_Unit(*this);
    }

    template <any_type_tr unit_p>
    inline volatile typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Extra_Unit()
        volatile
    {
        return Extra_Unit(*this);
    }

    template <any_type_tr unit_p>
    inline const volatile typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::Extra_Unit()
        const volatile
    {
        return Extra_Unit(*this);
    }

    template <any_type_tr unit_p>
    inline typename high_pad_t<unit_p>::split_t
        high_pad_t<unit_p>::Split(index_t at_index)
        const
    {
        return Split(*this, at_index);
    }

    template <any_type_tr unit_p>
    inline typename high_pad_t<unit_p>::split_t
        high_pad_t<unit_p>::Split(index_t at_index)
        const volatile
    {
        return Split(*this, at_index);
    }

    template <any_type_tr unit_p>
    inline typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::operator [](index_t index)
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::operator [](index_t index)
        const
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline volatile typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::operator [](index_t index)
        volatile
    {
        return Unit(*this, index);
    }

    template <any_type_tr unit_p>
    inline const volatile typename high_pad_t<unit_p>::unit_t&
        high_pad_t<unit_p>::operator [](index_t index)
        const volatile
    {
        return Unit(*this, index);
    }

}}
