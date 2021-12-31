/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_utils.h"

#include "nkr/z_string_itr_def.h"
#include "nkr/z_string/stack_t_def.h"
#include "nkr/z_string/static_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<string::static_tg>::Is_Any()
    {
        return string::$static_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<string::static_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p>
    inline constexpr c_bool_t
        static_t<charcoder_p>::Has_Guaranteed_Terminus()
    {
        return false;
    }

    template <charcoder_i charcoder_p>
    inline const typename static_t<charcoder_p>::unit_t*
        static_t<charcoder_p>::Empty_C_String()
    {
        static const unit_t default_c_string[1] = { 0 };

        return default_c_string;
    }

    template <charcoder_i charcoder_p>
    inline void_t
        static_t<charcoder_p>::Construct(is_any_non_const_tr<static_t> auto& self, tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string)
    {
        nkr_ASSERT_THAT(some_c_string);

        charcoder_t charcoder;
        count_t unit_count = 0;
        do {
            unit_count += charcoder.Read_Forward(some_c_string + unit_count);
            self.point_count += 1;
        } while (charcoder != none_t());

        self.array = maybe_t<pointer_t<unit_t>>(some_c_string, unit_count);
    }

    template <charcoder_i charcoder_p>
    inline auto&
        static_t<charcoder_p>::Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.point_count = other.point_count;
            self.array = other.array;
        }

        return self;
    }

    template <charcoder_i charcoder_p>
    inline auto&
        static_t<charcoder_p>::Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto&& other)
    {
        if (&self != std::addressof(other)) {
            self.point_count = nkr::Move(other.point_count);
            self.array = nkr::Move(other.array);
        }

        return self;
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Memory(const is_any_tr<static_t> auto& self)
    {
        return self.array.Has_Memory();
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Terminus(const is_any_tr<static_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);

        return unit_count > 0 && self.array[unit_count - 1] == 0;
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Count(const is_any_tr<static_t> auto& self)
    {
        return self.array.Count();
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Length(const is_any_tr<static_t> auto& self)
    {
        count_t unit_count = Unit_Count(self);
        if (unit_count > 0 && self.array[unit_count - 1] == 0) {
            return unit_count - 1;
        } else {
            return unit_count;
        }
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Count(const is_any_tr<static_t> auto& self)
    {
        return self.point_count;
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Length(const is_any_tr<static_t> auto& self)
    {
        count_t point_count = Point_Count(self);
        if (point_count > 0 && Has_Terminus(self)) {
            return point_count - 1;
        } else {
            return point_count;
        }
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::C_String(const is_any_tr<static_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));

        return &self.array[0];
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::At(const is_any_tr<static_t> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(point_index < Point_Count(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, point_index);
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::At_Prefix(const is_any_tr<static_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::prefix_tg());
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::At_First(const is_any_tr<static_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::first_tg());
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::At_Last(const is_any_tr<static_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::last_tg());
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::At_Terminus(const is_any_tr<static_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::terminus_tg());
    }

    template <charcoder_i charcoder_p>
    inline auto
        static_t<charcoder_p>::At_Postfix(const is_any_tr<static_t> auto& self)
    {
        nkr_ASSERT_THAT(Has_Memory(self));

        return string_itr<std::remove_reference_t<decltype(self)>>(self, position_e::postfix_tg());
    }

    template <charcoder_i charcoder_p>
    inline auto&
        static_t<charcoder_p>::Unit(is_any_tr<static_t> auto& self, index_t unit_index)
    {
        nkr_ASSERT_THAT(Has_Memory(self));
        nkr_ASSERT_THAT(self.array.Count() > unit_index);

        return self.array[unit_index];
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t() :
        point_count(0),
        array()
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(nullptr_t) :
        static_t()
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, unit_t*> auto c_string) :
        static_t(maybe_t<unit_t*>(c_string))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, unit_t*> auto c_string,
                                           count_t unit_count,
                                           count_t point_count) :
        static_t(maybe_t<unit_t*>(c_string), unit_count, point_count)
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr2<any_tg, maybe_t, of_any_tg, unit_t*> auto maybe_c_string) :
        static_t()
    {
        if (maybe_c_string) {
            Construct(*this, some_t<unit_t*>(maybe_c_string()));
        }
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr2<any_tg, maybe_t, of_any_tg, unit_t*> auto maybe_c_string,
                                           count_t unit_count,
                                           count_t point_count) :
        point_count(point_count),
        array(pointer_t<unit_t>(maybe_c_string, unit_count))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string) :
        static_t()
    {
        Construct(*this, some_c_string);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string,
                                           count_t unit_count,
                                           count_t point_count) :
        point_count(point_count),
        array(pointer_t<unit_t>(some_c_string, unit_count))
    {
        nkr_ASSERT_THAT(some_c_string);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, string_tg> auto& string) :
        static_t()
    {
        if (string.Has_Memory()) {
            this->point_count = string.Point_Count();
            this->array = maybe_t<pointer_t<unit_t>>(&string.Unit(0), string.Unit_Count());
        }
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, string_tg> auto& string, bool_t include_terminus) :
        static_t()
    {
        if (string.Has_Memory()) {
            if (include_terminus || !string.Has_Terminus()) {
                this->point_count = string.Point_Count();
                this->array = maybe_t<pointer_t<unit_t>>(&string.Unit(0), string.Unit_Count());
            } else {
                this->point_count = string.Point_Count() - 1;
                this->array = maybe_t<pointer_t<unit_t>>(&string.Unit(0), string.Unit_Count() - 1);
            }
        }
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(tr1<any_tg, string_tg> auto& string, index_t from_point_index, count_t point_count) :
        static_t()
    {
        nkr_ASSERT_THAT(string.Has_Memory());
        nkr_ASSERT_THAT(from_point_index < string.Point_Count());
        nkr_ASSERT_THAT(from_point_index + point_count <= string.Point_Count());

        auto itr = string.At(from_point_index);
        index_t from_unit_index = itr.Unit_Index().Value();
        itr.At(from_point_index + point_count);
        index_t to_unit_index = itr.Unit_Index().Value();

        this->point_count = point_count;
        this->array = maybe_t<pointer_t<unit_t>>(&string.Unit(from_unit_index), to_unit_index - from_unit_index);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(const static_t& other) :
        point_count(other.point_count),
        array(other.array)
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(const volatile static_t& other) :
        point_count(other.point_count),
        array(other.array)
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(static_t&& other) noexcept :
        point_count(nkr::Move(other.point_count)),
        array(nkr::Move(other.array))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::static_t(volatile static_t&& other) noexcept :
        point_count(nkr::Move(other.point_count)),
        array(nkr::Move(other.array))
    {
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const volatile static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(const volatile static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(static_t&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p>
    inline volatile static_t<charcoder_p>&
        static_t<charcoder_p>::operator =(is_just_volatile_tr<static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p>
    inline static_t<charcoder_p>::~static_t()
    {
        this->point_count = 0;
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Memory()
        const
    {
        return Has_Memory(*this);
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Memory()
        const volatile
    {
        return Has_Memory(*this);
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Terminus()
        const
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p>
    inline bool_t
        static_t<charcoder_p>::Has_Terminus()
        const volatile
    {
        return Has_Terminus(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Length()
        const
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Unit_Length()
        const volatile
    {
        return Unit_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Count()
        const
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Count()
        const volatile
    {
        return Point_Count(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Length()
        const
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline count_t
        static_t<charcoder_p>::Point_Length()
        const volatile
    {
        return Point_Length(*this);
    }

    template <charcoder_i charcoder_p>
    inline some_t<const typename static_t<charcoder_p>::unit_t*>
        static_t<charcoder_p>::C_String()
        const
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p>
    inline some_t<const volatile typename static_t<charcoder_p>::unit_t*>
        static_t<charcoder_p>::C_String()
        const volatile
    {
        return C_String(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const static_t<charcoder_p>>
        static_t<charcoder_p>::At(index_t point_index)
        const
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const volatile static_t<charcoder_p>>
        static_t<charcoder_p>::At(index_t point_index)
        const volatile
    {
        return At(*this, point_index);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const static_t<charcoder_p>>
        static_t<charcoder_p>::At_Prefix()
        const
    {
        return At_Prefix(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const volatile static_t<charcoder_p>>
        static_t<charcoder_p>::At_Prefix()
        const volatile
    {
        return At_Prefix(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const static_t<charcoder_p>>
        static_t<charcoder_p>::At_First()
        const
    {
        return At_First(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const volatile static_t<charcoder_p>>
        static_t<charcoder_p>::At_First()
        const volatile
    {
        return At_First(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const static_t<charcoder_p>>
        static_t<charcoder_p>::At_Last()
        const
    {
        return At_Last(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const volatile static_t<charcoder_p>>
        static_t<charcoder_p>::At_Last()
        const volatile
    {
        return At_Last(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const static_t<charcoder_p>>
        static_t<charcoder_p>::At_Terminus()
        const
    {
        return At_Terminus(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const volatile static_t<charcoder_p>>
        static_t<charcoder_p>::At_Terminus()
        const volatile
    {
        return At_Terminus(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const static_t<charcoder_p>>
        static_t<charcoder_p>::At_Postfix()
        const
    {
        return At_Postfix(*this);
    }

    template <charcoder_i charcoder_p>
    inline string_itr<const volatile static_t<charcoder_p>>
        static_t<charcoder_p>::At_Postfix()
        const volatile
    {
        return At_Postfix(*this);
    }

    template <charcoder_i charcoder_p>
    inline typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p>
    inline const typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
        const
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p>
    inline volatile typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
        volatile
    {
        return Unit(*this, unit_index);
    }

    template <charcoder_i charcoder_p>
    inline const volatile typename static_t<charcoder_p>::unit_t&
        static_t<charcoder_p>::Unit(index_t unit_index)
        const volatile
    {
        return Unit(*this, unit_index);
    }

}}

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<string::local_static_tg>::Is_Any()
    {
        return string::$local_static_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<string::local_static_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline constexpr count_t
        local_static_t<charcoder_p, unit_capacity_p>::Unit_Capacity()
    {
        return unit_capacity_p;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto&
        local_static_t<charcoder_p, unit_capacity_p>::Copy_Assign(is_any_non_const_tr<local_static_t> auto& self,
                                                                  const is_any_tr<local_static_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            if (other.Has_Memory()) {
                self.local_string = other.local_string;
                Enable_Memory(self, other.Has_Terminus());
            } else {
                Disable_Memory(self);
            }
        }

        return self;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline auto&
        local_static_t<charcoder_p, unit_capacity_p>::Move_Assign(is_any_non_const_tr<local_static_t> auto& self,
                                                                  is_any_non_const_tr<local_static_t> auto&& other)
    {
        if (&self != std::addressof(other)) {
            if (other.Has_Memory()) {
                bool_t has_terminus = other.Has_Terminus();
                self.local_string = nkr::Move(other.local_string);
                Enable_Memory(self, has_terminus);
            } else {
                Disable_Memory(self);
            }
        }

        return self;
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline void_t
        local_static_t<charcoder_p, unit_capacity_p>::Enable_Memory(is_any_non_const_tr<local_static_t> auto& self,
                                                                    bool_t has_terminus)
    {
        if (has_terminus) {
            self.point_count = self.local_string.Point_Count();
            self.array = maybe_t<pointer_t<unit_t>>(&self.local_string.Unit(0), self.local_string.Unit_Count());
        } else {
            self.point_count = self.local_string.Point_Count() - 1;
            self.array = maybe_t<pointer_t<unit_t>>(&self.local_string.Unit(0), self.local_string.Unit_Count() - 1);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline void_t
        local_static_t<charcoder_p, unit_capacity_p>::Disable_Memory(is_any_non_const_tr<local_static_t> auto& self)
    {
        self.point_count = 0;
        self.array = maybe_t<pointer_t<unit_t>>(nullptr, 0);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t() :
        base_t(),
        local_string()
    {
        Enable_Memory(*this, true);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(nullptr_t) :
        base_t(),
        local_string()
    {
        Disable_Memory(*this);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string) :
        base_t(),
        local_string(c_string)
    {
        if (c_string) {
            Enable_Memory(*this, true);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string,
                                                                        count_t unit_count_or_length) :
        base_t(),
        local_string()
    {
        nkr_ASSERT_THAT(unit_count_or_length > 0 ? c_string != nullptr : true);

        if (c_string) {
            maybe_t<allocator_err> error = this->local_string.Push(c_string, unit_count_or_length);
            if (error == allocator_err::NONE) {
                Enable_Memory(*this, unit_count_or_length > 0 && c_string[unit_count_or_length - 1] == 0);
            } else {
                Enable_Memory(*this, true);
            }
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr3<any_tg, maybe_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto maybe_c_string) :
        base_t(),
        local_string(maybe_c_string)
    {
        if (maybe_c_string) {
            Enable_Memory(*this, true);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr3<any_tg, maybe_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto maybe_c_string,
                                                                        count_t unit_count_or_length) :
        base_t(),
        local_string()
    {
        if (maybe_c_string) {
            maybe_t<allocator_err> error = this->local_string.Push(maybe_c_string(), unit_count_or_length);
            if (error == allocator_err::NONE) {
                Enable_Memory(*this, unit_count_or_length > 0 && maybe_c_string[unit_count_or_length - 1] == 0);
            } else {
                Enable_Memory(*this, true);
            }
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr3<any_tg, some_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto some_c_string) :
        base_t(),
        local_string((nkr_ASSERT_THAT(some_c_string), some_c_string))
    {
        Enable_Memory(*this, true);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr3<any_tg, some_t, of_any_tg, c_pointer_ttg, of_any_tg, unit_t> auto some_c_string,
                                                                        count_t unit_count_or_length) :
        base_t(),
        local_string()
    {
        nkr_ASSERT_THAT(some_c_string);

        maybe_t<allocator_err> error = this->local_string.Push(some_c_string(), unit_count_or_length);
        if (error == allocator_err::NONE) {
            Enable_Memory(*this, unit_count_or_length > 0 && some_c_string[unit_count_or_length - 1] == 0);
        } else {
            Enable_Memory(*this, true);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(const tr1<any_tg, string_tg> auto& string) :
        base_t(),
        local_string()
    {
        if (string.Has_Memory()) {
            this->local_string = string;
            Enable_Memory(*this, string.Has_Terminus());
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(const tr1<any_tg, string_tg> auto& string,
                                                                        bool_t use_terminus) :
        base_t(),
        local_string()
    {
        if (string.Has_Memory()) {
            this->local_string = string;
            Enable_Memory(*this, use_terminus);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr1<any_non_const_tg, aggregate_string_tg> auto&& string) :
        base_t(),
        local_string()
    {
        if (string.Has_Memory()) {
            bool_t has_terminus = string.Has_Terminus();
            this->local_string = nkr::Move(string);
            Enable_Memory(*this, has_terminus);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(tr1<any_non_const_tg, aggregate_string_tg> auto&& string,
                                                                        bool_t use_terminus) :
        base_t(),
        local_string()
    {
        if (string.Has_Memory()) {
            this->local_string = nkr::Move(string);
            Enable_Memory(*this, use_terminus);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(const local_static_t& other) :
        base_t(),
        local_string(other.local_string)
    {
        if (other.Has_Memory()) {
            Enable_Memory(*this, other.Has_Terminus());
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(const volatile local_static_t& other) :
        base_t(),
        local_string(other.local_string)
    {
        if (other.Has_Memory()) {
            Enable_Memory(*this, other.Has_Terminus());
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(local_static_t&& other) noexcept :
        base_t(),
        local_string()
    {
        if (other.Has_Memory()) {
            bool_t has_terminus = other.Has_Terminus();
            this->local_string = nkr::Move(other.local_string);
            Enable_Memory(*this, has_terminus);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::local_static_t(volatile local_static_t&& other) noexcept :
        base_t(),
        local_string()
    {
        if (other.Has_Memory()) {
            bool_t has_terminus = other.Has_Terminus();
            this->local_string = nkr::Move(other.local_string);
            Enable_Memory(*this, has_terminus);
        } else {
            Disable_Memory(*this);
        }
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(const local_static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(const local_static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(const volatile local_static_t& other)
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(const volatile local_static_t& other)
        volatile
    {
        return Copy_Assign(*this, other);
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(local_static_t&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(local_static_t&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(is_just_volatile_tr<local_static_t> auto&& other)
        noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline volatile local_static_t<charcoder_p, unit_capacity_p>&
        local_static_t<charcoder_p, unit_capacity_p>::operator =(is_just_volatile_tr<local_static_t> auto&& other)
        volatile noexcept
    {
        return Move_Assign(*this, nkr::Move(other));
    }

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    inline local_static_t<charcoder_p, unit_capacity_p>::~local_static_t()
    {
    }

}}

namespace nkr {

    template <tr1<any_tg, string::static_tg> string_p, count_t min_point_count_p, count_t max_point_count_p>
    inline auto
        Random(bool_t use_erroneous_units, bool_t use_terminus)
    {
        return Random<string::local_static_t<string_p::qualified_charcoder_t>, min_point_count_p, max_point_count_p>
            (use_erroneous_units, use_terminus);
    }

    template <tr1<any_tg, string::local_static_tg> string_p, count_t min_point_count_p, count_t max_point_count_p>
    inline auto
        Random(bool_t use_erroneous_units, bool_t use_terminus)
    {
        using string_t = string_p;
        using charcoder_t = string_t::charcoder_t;
        using qualified_charcoder_t = string_t::qualified_charcoder_t;

        static_assert(min_point_count_p <= max_point_count_p);

        if constexpr (max_point_count_p > 0) {
            constexpr count_t unit_capacity = max_point_count_p * charcoder_t::Max_Unit_Count();
            const count_t point_count = nkr::Random<count_t>(min_point_count_p, max_point_count_p);
            if (point_count > 0) {
                if constexpr (min_point_count_p > 0) {
                    return string::local_static_t<qualified_charcoder_t, unit_capacity>
                        (Random<string::stack_t<qualified_charcoder_t>, min_point_count_p, max_point_count_p>(use_erroneous_units), use_terminus);
                } else {
                    return string::local_static_t<qualified_charcoder_t, unit_capacity>
                        (Random<string::stack_t<qualified_charcoder_t>, 1, max_point_count_p>(use_erroneous_units), use_terminus);
                }
            } else {
                return string::local_static_t<qualified_charcoder_t, unit_capacity>(nullptr);
            }
        } else {
            return string::local_static_t<qualified_charcoder_t, 1>(nullptr);
        }
    }

}