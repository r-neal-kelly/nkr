/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/math.h"
#include "nkr/utils.h"

#include "nkr/string_itr_dec.h"
#include "nkr/string/stack_t_def.h"

namespace nkr {

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Has_String(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(self.string);

        return self.string->Has_Terminus();
    }

    template <typename string_p>
    inline const typename string_itr<string_p>::string_t&
        string_itr<string_p>::String(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return *self.string;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At(const is_any_tr<string_itr> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return !Is_At_Prefix(self) && self.point_index == point_index;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Prefix(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == 0 && self.is_prefix == true;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_First(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == 0 && self.is_prefix == false;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Last(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        count_t point_length = self.string->Point_Length();
        if (point_length > 0) {
            return self.point_index == point_length - 1 && self.is_prefix == false;
        } else {
            return Is_At_Prefix(self);
        }
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Terminus(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == self.string->Unit_Length() && self.is_prefix == false;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Postfix(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == self.string->Unit_Count() && self.is_prefix == false;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Error(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_At_Prefix(self) || Is_At_Postfix(self)) {
            return false;
        } else {
            count_t point_unit_count = Point_Unit_Count(self);
            if (point_unit_count != Substring_Unit_Count(self)) {
                return true;
            } else {
                for (index_t idx = 0, end = point_unit_count; idx < end; idx += 1) {
                    if (Point_Unit(self, idx) != Substring_Unit(self, idx)) {
                        return true;
                    }
                }

                return false;
            }
        }
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Replacement_Point(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return Point(self) == charcoder_t::Replacement_Point();
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Replacement_Substring(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return Is_At_Replacement_Point(self) && !Is_At_Error(self);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At(is_any_non_const_tr<string_itr> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(point_index <= self.string->Point_Count());

        if (self.point_index != point_index) {
            const count_t point_count = self.string->Point_Count();
            if (point_index == point_count) {
                At_Postfix(self);
            } else {
                if constexpr (charcoder_t::Max_Unit_Count() == 1) {
                    self.is_prefix = false;
                    self.unit_index = point_index;
                    self.point_index = point_index;
                    self.read_unit_count = self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
                } else {
                    constexpr const count_t THRESHOLD = 16;

                    if (Is_At_Prefix(self)) {
                        Next(self);
                    } else if (Is_At_Postfix(self)) {
                        Prior(self);
                    }

                    if (point_count > THRESHOLD) {
                        if (point_index > self.point_index) {
                            count_t difference_from_current = point_index - self.point_index;
                            count_t difference_from_terminus = point_count - 1 - point_index;
                            if (difference_from_current < difference_from_terminus) {
                                self += difference_from_current;
                            } else {
                                At_Terminus(self);
                                self -= difference_from_terminus;
                            }
                        } else {
                            count_t difference_from_current = self.point_index - point_index;
                            count_t difference_from_first = point_index - 0;
                            if (difference_from_current < difference_from_first) {
                                self -= difference_from_current;
                            } else {
                                At_First(self);
                                self += difference_from_first;
                            }
                        }
                    } else {
                        if (point_index > self.point_index) {
                            self += point_index - self.point_index;
                        } else {
                            self -= self.point_index - point_index;
                        }
                    }
                }
            }
        }
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Prefix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.is_prefix = true;
        self.unit_index = 0;
        self.point_index = 0;
        self.read_unit_count = 0;
        self.charcoder = none_t();
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_First(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.is_prefix = false;
        self.unit_index = 0;
        self.point_index = 0;
        self.read_unit_count = self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Last(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        At_Terminus(self);
        Prior(self);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Terminus(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.is_prefix = false;
        self.unit_index = self.string->Unit_Count() - 1;
        self.point_index = self.string->Point_Count() - 1;
        self.read_unit_count = self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.is_prefix = false;
        self.unit_index = self.string->Unit_Count();
        self.point_index = self.string->Point_Count();
        self.read_unit_count = 0;
        self.charcoder = none_t();
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Next(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_At_Prefix(self)) {
            At_First(self);

            return true;
        } else if (Is_At_Terminus(self)) {
            At_Postfix(self);

            return true;
        } else if (Is_At_Postfix(self)) {
            return false;
        } else {
            self.unit_index += self.read_unit_count;
            self.point_index += 1;
            self.read_unit_count = self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));

            return true;
        }
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Prior(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_At_Prefix(self)) {
            return false;
        } else if (Is_At_First(self)) {
            At_Prefix(self);

            return true;
        } else if (Is_At_Postfix(self)) {
            At_Terminus(self);

            return true;
        } else {
            self.read_unit_count = self.charcoder.Read_Reverse(&self.string->Unit(self.unit_index), &self.string->Unit(0));
            self.unit_index -= self.read_unit_count;
            self.point_index -= 1;

            return true;
        }
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Unit_Index(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_At_Prefix(self)) {
            return optional_t<index_t>(index_t(0), false);
        } else {
            return optional_t<index_t>(self.unit_index, true);
        }
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Point_Index(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_At_Prefix(self)) {
            return optional_t<index_t>(index_t(0), false);
        } else {
            return optional_t<index_t>(self.point_index, true);
        }
    }

    template <typename string_p>
    inline typename string_itr<string_p>::charcoder_t
        string_itr<string_p>::Charcoder(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.charcoder;
    }

    template <typename string_p>
    inline string::point_t
        string_itr<string_p>::Point(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.charcoder.Decode();
    }

    template <typename string_p>
    inline count_t
        string_itr<string_p>::Point_Unit_Count(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.charcoder.Unit_Count();
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Point_Unit(const is_any_tr<string_itr> auto& self, index_t point_unit_index)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(point_unit_index < Point_Unit_Count(self));

        return self.charcoder[point_unit_index];
    }

    template <typename string_p>
    inline typename string_itr<string_p>::substring_t
        string_itr<string_p>::Substring(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(Substring_Unit_Count(self) < substring_t::Unit_Capacity());

        substring_t substring;
        if (!Is_At_Prefix(self) && !Is_At_Postfix(self)) {
            substring.Push(&self.string->Unit(self.unit_index), Substring_Unit_Count(self)).Ignore_Error();
        }

        return substring;
    }

    template <typename string_p>
    inline count_t
        string_itr<string_p>::Substring_Unit_Count(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(self.read_unit_count <= charcoder_t::Max_Unit_Count());

        return self.read_unit_count;
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Substring_Unit(const is_any_tr<string_itr> auto& self, index_t substring_unit_index)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_At_Prefix(self));
        nkr_ASSERT_THAT(!Is_At_Postfix(self));
        nkr_ASSERT_THAT(substring_unit_index < Substring_Unit_Count(self));

        return self.string->Unit(Unit_Index(self).Value() + substring_unit_index);
    }

    template <typename string_p>
    inline auto&
        string_itr<string_p>::Operator_Plus_Equals(is_any_non_const_tr<string_itr> auto& self, count_t point_count)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!math::Will_Overflow_Add(self.point_index, point_count));
        nkr_ASSERT_THAT(self.point_index + point_count <= self.string->Point_Count());

        for (; point_count > 0; point_count -= 1) {
            Next(self);
        }

        return self;
    }

    template <typename string_p>
    inline auto&
        string_itr<string_p>::Operator_Minus_Equals(is_any_non_const_tr<string_itr> auto& self, count_t point_count)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(point_count > self.point_index ? point_count - self.point_index == 1 : true);

        for (; point_count > 0; point_count -= 1) {
            Prior(self);
        }

        return self;
    }

    template <typename string_p>
    inline auto&
        string_itr<string_p>::Operator_Increment_Prefix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_At_Postfix(self));

        Next(self);

        return self;
    }

    template <typename string_p>
    inline auto
        string_itr<string_p>::Operator_Increment_Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_At_Postfix(self));

        auto old = self;
        Next(self);

        return old;
    }

    template <typename string_p>
    inline auto&
        string_itr<string_p>::Operator_Decrement_Prefix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_At_Prefix(self));

        Prior(self);

        return self;
    }

    template <typename string_p>
    inline auto
        string_itr<string_p>::Operator_Decrement_Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_At_Prefix(self));

        auto old = self;
        Prior(self);

        return old;
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string) :
        string_itr(string, string::position_e::first_tg())
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string, index_t point_index) :
        string_itr(string, string::position_e::first_tg())
    {
        At(*this, point_index);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string, string::position_e::prefix_tg) :
        string(&string),
        is_prefix(false),
        unit_index(0),
        point_index(0),
        read_unit_count(0),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(this->string);
        nkr_ASSERT_THAT(Has_String(*this));

        At_Prefix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string, string::position_e::first_tg) :
        string(&string),
        is_prefix(false),
        unit_index(0),
        point_index(0),
        read_unit_count(0),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(this->string);
        nkr_ASSERT_THAT(Has_String(*this));

        At_First(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string, string::position_e::last_tg) :
        string(&string),
        is_prefix(false),
        unit_index(0),
        point_index(0),
        read_unit_count(0),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(this->string);
        nkr_ASSERT_THAT(Has_String(*this));

        At_Last(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string, string::position_e::terminus_tg) :
        string(&string),
        is_prefix(false),
        unit_index(0),
        point_index(0),
        read_unit_count(0),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(this->string);
        nkr_ASSERT_THAT(Has_String(*this));

        At_Terminus(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_t& string, string::position_e::postfix_tg) :
        string(&string),
        is_prefix(false),
        unit_index(0),
        point_index(0),
        read_unit_count(0),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(this->string);
        nkr_ASSERT_THAT(Has_String(*this));

        At_Postfix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_itr& other) :
        string(other.string),
        is_prefix(other.is_prefix),
        unit_index(other.unit_index),
        point_index(other.point_index),
        read_unit_count(other.read_unit_count),
        charcoder(other.charcoder)
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const volatile string_itr& other) :
        string(other.string),
        is_prefix(other.is_prefix),
        unit_index(other.unit_index),
        point_index(other.point_index),
        read_unit_count(other.read_unit_count),
        charcoder(other.charcoder)
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(string_itr&& other) noexcept :
        string(nkr::Move(other.string)),
        is_prefix(nkr::Move(other.is_prefix)),
        unit_index(nkr::Move(other.unit_index)),
        point_index(nkr::Move(other.point_index)),
        read_unit_count(nkr::Move(other.read_unit_count)),
        charcoder(nkr::Move(other.charcoder))
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(volatile string_itr&& other) noexcept :
        string(nkr::Move(other.string)),
        is_prefix(nkr::Move(other.is_prefix)),
        unit_index(nkr::Move(other.unit_index)),
        point_index(nkr::Move(other.point_index)),
        read_unit_count(nkr::Move(other.read_unit_count)),
        charcoder(nkr::Move(other.charcoder))
    {
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator =(const string_itr& other)
    {
        if (this != std::addressof(other)) {
            this->string = other.string;
            this->is_prefix = other.is_prefix;
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->read_unit_count = other.read_unit_count;
            this->charcoder = other.charcoder;
        }
        return *this;
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator =(const string_itr& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->string = other.string;
            this->is_prefix = other.is_prefix;
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->read_unit_count = other.read_unit_count;
            this->charcoder = other.charcoder;
        }
        return *this;
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator =(const volatile string_itr& other)
    {
        if (this != std::addressof(other)) {
            this->string = other.string;
            this->is_prefix = other.is_prefix;
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->read_unit_count = other.read_unit_count;
            this->charcoder = other.charcoder;
        }
        return *this;
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator =(const volatile string_itr& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->string = other.string;
            this->is_prefix = other.is_prefix;
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->read_unit_count = other.read_unit_count;
            this->charcoder = other.charcoder;
        }
        return *this;
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator =(string_itr&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->string = nkr::Move(other.string);
            this->is_prefix = nkr::Move(other.is_prefix);
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->read_unit_count = nkr::Move(other.read_unit_count);
            this->charcoder = nkr::Move(other.charcoder);
        }
        return *this;
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator =(string_itr&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->string = nkr::Move(other.string);
            this->is_prefix = nkr::Move(other.is_prefix);
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->read_unit_count = nkr::Move(other.read_unit_count);
            this->charcoder = nkr::Move(other.charcoder);
        }
        return *this;
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator =(is_just_volatile_tr<string_itr> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->string = nkr::Move(other.string);
            this->is_prefix = nkr::Move(other.is_prefix);
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->read_unit_count = nkr::Move(other.read_unit_count);
            this->charcoder = nkr::Move(other.charcoder);
        }
        return *this;
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator =(is_just_volatile_tr<string_itr> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->string = nkr::Move(other.string);
            this->is_prefix = nkr::Move(other.is_prefix);
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->read_unit_count = nkr::Move(other.read_unit_count);
            this->charcoder = nkr::Move(other.charcoder);
        }
        return *this;
    }

    template <typename string_p>
    inline string_itr<string_p>::~string_itr()
    {
        this->string = nullptr;
        this->is_prefix = false;
        this->unit_index = 0;
        this->point_index = 0;
        this->read_unit_count = 0;
    }

    template <typename string_p>
    inline const typename string_itr<string_p>::string_t&
        string_itr<string_p>::String()
        const
    {
        return String(*this);
    }

    template <typename string_p>
    inline const typename string_itr<string_p>::string_t&
        string_itr<string_p>::String()
        const volatile
    {
        return String(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At(index_t point_index) const
    {
        return Is_At(*this, point_index);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At(index_t point_index) const volatile
    {
        return Is_At(*this, point_index);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Prefix()
        const
    {
        return Is_At_Prefix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Prefix()
        const volatile
    {
        return Is_At_Prefix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_First()
        const
    {
        return Is_At_First(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_First()
        const volatile
    {
        return Is_At_First(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Last()
        const
    {
        return Is_At_Last(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Last()
        const volatile
    {
        return Is_At_Last(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Terminus()
        const
    {
        return Is_At_Terminus(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Terminus()
        const volatile
    {
        return Is_At_Terminus(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Postfix()
        const
    {
        return Is_At_Postfix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Postfix()
        const volatile
    {
        return Is_At_Postfix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Error()
        const
    {
        return Is_At_Error(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Error()
        const volatile
    {
        return Is_At_Error(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Replacement_Point()
        const
    {
        return Is_At_Replacement_Point(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Replacement_Point()
        const volatile
    {
        return Is_At_Replacement_Point(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Replacement_Substring()
        const
    {
        return Is_At_Replacement_Substring(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At_Replacement_Substring()
        const volatile
    {
        return Is_At_Replacement_Substring(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At(index_t point_index)
    {
        return At(*this, point_index);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At(index_t point_index)
        volatile
    {
        return At(*this, point_index);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Prefix()
    {
        return At_Prefix(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Prefix()
        volatile
    {
        return At_Prefix(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_First()
    {
        return At_First(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_First()
        volatile
    {
        return At_First(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Last()
    {
        return At_Last(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Last()
        volatile
    {
        return At_Last(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Terminus()
    {
        return At_Terminus(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Terminus()
        volatile
    {
        return At_Terminus(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Postfix()
    {
        return At_Postfix(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At_Postfix()
        volatile
    {
        return At_Postfix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Next()
    {
        return Next(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Next()
        volatile
    {
        return Next(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Prior()
    {
        return Prior(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Prior()
        volatile
    {
        return Prior(*this);
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Unit_Index()
        const
    {
        return Unit_Index(*this);
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Unit_Index()
        const volatile
    {
        return Unit_Index(*this);
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Point_Index()
        const
    {
        return Point_Index(*this);
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Point_Index()
        const volatile
    {
        return Point_Index(*this);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::charcoder_t
        string_itr<string_p>::Charcoder()
        const
    {
        return Charcoder(*this);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::charcoder_t
        string_itr<string_p>::Charcoder()
        const volatile
    {
        return Charcoder(*this);
    }

    template <typename string_p>
    inline string::point_t
        string_itr<string_p>::Point()
        const
    {
        return Point(*this);
    }

    template <typename string_p>
    inline string::point_t
        string_itr<string_p>::Point()
        const volatile
    {
        return Point(*this);
    }

    template <typename string_p>
    inline count_t
        string_itr<string_p>::Point_Unit_Count()
        const
    {
        return Point_Unit_Count(*this);
    }

    template <typename string_p>
    inline count_t
        string_itr<string_p>::Point_Unit_Count()
        const volatile
    {
        return Point_Unit_Count(*this);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Point_Unit(index_t point_unit_index)
        const
    {
        return Point_Unit(*this, point_unit_index);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Point_Unit(index_t point_unit_index)
        const volatile
    {
        return Point_Unit(*this, point_unit_index);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::substring_t
        string_itr<string_p>::Substring()
        const
    {
        return Substring(*this);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::substring_t
        string_itr<string_p>::Substring()
        const volatile
    {
        return Substring(*this);
    }

    template <typename string_p>
    inline count_t
        string_itr<string_p>::Substring_Unit_Count()
        const
    {
        return Substring_Unit_Count(*this);
    }

    template <typename string_p>
    inline count_t
        string_itr<string_p>::Substring_Unit_Count()
        const volatile
    {
        return Substring_Unit_Count(*this);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Substring_Unit(index_t substring_unit_index)
        const
    {
        return Substring_Unit(*this, substring_unit_index);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Substring_Unit(index_t substring_unit_index)
        const volatile
    {
        return Substring_Unit(*this, substring_unit_index);
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator +=(count_t point_count)
    {
        return Operator_Plus_Equals(*this, point_count);
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator +=(count_t point_count)
        volatile
    {
        return Operator_Plus_Equals(*this, point_count);
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator -=(count_t point_count)
    {
        return Operator_Minus_Equals(*this, point_count);
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator -=(count_t point_count)
        volatile
    {
        return Operator_Minus_Equals(*this, point_count);
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator ++()
    {
        return Operator_Increment_Prefix(*this);
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator ++()
        volatile
    {
        return Operator_Increment_Prefix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>
        string_itr<string_p>::operator ++(int)
    {
        return Operator_Increment_Postfix(*this);
    }

    template <typename string_p>
    inline volatile string_itr<string_p>
        string_itr<string_p>::operator ++(int)
        volatile
    {
        return Operator_Increment_Postfix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator --()
    {
        return Operator_Decrement_Prefix(*this);
    }

    template <typename string_p>
    inline volatile string_itr<string_p>&
        string_itr<string_p>::operator --()
        volatile
    {
        return Operator_Decrement_Prefix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>
        string_itr<string_p>::operator --(int)
    {
        return Operator_Decrement_Postfix(*this);
    }

    template <typename string_p>
    inline volatile string_itr<string_p>
        string_itr<string_p>::operator --(int)
        volatile
    {
        return Operator_Decrement_Postfix(*this);
    }

}
