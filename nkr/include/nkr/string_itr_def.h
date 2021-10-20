/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/math.h"
#include "nkr/utils.h"

#include "nkr/string_itr_dec.h"

namespace nkr {

    // we should use the charcoder Max_Unit_Count func to determine if we can use
    // the simpler algorithm when it equals 1.

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
        string_itr<string_p>::Is_Prefix(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == 0 && self.is_prefix == true;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_First(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == 0 && self.is_prefix == false;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Last(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        count_t point_length = self.string->Point_Length();
        if (point_length > 0) {
            return self.point_index == point_length - 1 && self.is_prefix == false;
        } else {
            return Is_Prefix(self);
        }
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Terminus(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == self.string->Unit_Length() && self.is_prefix == false;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Postfix(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == self.string->Unit_Count() && self.is_prefix == false;
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_At(const is_any_tr<string_itr> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.point_index == point_index;
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Prefix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = 0;
        self.point_index = 0;
        self.is_prefix = true;
        self.charcoder = none_t();
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::First(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = 0;
        self.point_index = 0;
        self.is_prefix = false;
        self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Last(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        Terminus(self);
        Prior(self);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Terminus(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = self.string->Unit_Count() - 1;
        self.point_index = self.string->Point_Count() - 1;
        self.is_prefix = false;
        self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = self.string->Unit_Count();
        self.point_index = self.string->Point_Count();
        self.is_prefix = false;
        self.charcoder = none_t();
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::At(is_any_non_const_tr<string_itr> auto& self, index_t point_index)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(point_index < self.string->Point_Count());

        // kind of arbitrary until we do tests. also may not be as good for some charcoders as others.
        constexpr const count_t THRESHOLD = 16;

        // we can offer a quicker method if the charcoder always has a 1:1 unit to point ratio (like ascii_t utf_32_t), should constexpr if it

        if (self.point_index != point_index) {
            if (Is_Prefix(self)) {
                Next(self);
            } else if (Is_Postfix(self)) {
                Prior(self);
            }

            count_t point_count = self.string->Point_Count();
            if (point_count > THRESHOLD) {
                if (point_index > self.point_index) {
                    count_t difference_from_current = point_index - self.point_index;
                    count_t difference_from_terminus = point_count - 1 - point_index;
                    if (difference_from_current < difference_from_terminus) {
                        self += difference_from_current;
                    } else {
                        Terminus(self);
                        self -= difference_from_terminus;
                    }
                } else {
                    count_t difference_from_current = self.point_index - point_index;
                    count_t difference_from_first = point_index - 0;
                    if (difference_from_current < difference_from_first) {
                        self -= difference_from_current;
                    } else {
                        First(self);
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

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Next(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_Prefix(self)) {
            First(self);

            return true;
        } else if (Is_Terminus(self)) {
            Postfix(self);

            return true;
        } else if (Is_Postfix(self)) {
            return false;
        } else {
            self.unit_index += self.charcoder.Unit_Count();
            self.point_index += 1;
            self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));

            return true;
        }
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Prior(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_Prefix(self)) {
            return false;
        } else if (Is_First(self)) {
            Prefix(self);

            return true;
        } else if (Is_Postfix(self)) {
            Terminus(self);

            return true;
        } else {
            self.charcoder.Read_Reverse(&self.string->Unit(self.unit_index), &self.string->Unit(0));
            self.unit_index -= self.charcoder.Unit_Count();
            self.point_index -= 1;

            return true;
        }
    }

    template <typename string_p>
    inline optional_t<index_t>
        string_itr<string_p>::Unit_Index(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_Prefix(self)) {
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

        if (Is_Prefix(self)) {
            return optional_t<index_t>(index_t(0), false);
        } else {
            return optional_t<index_t>(self.point_index, true);
        }
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
        string_itr<string_p>::Point_Unit(const is_any_tr<string_itr> auto& self, index_t index)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(index < Point_Unit_Count(self));

        return self.charcoder[index];
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
        nkr_ASSERT_THAT(!Is_Postfix(self));

        Next(self);

        return self;
    }

    template <typename string_p>
    inline auto
        string_itr<string_p>::Operator_Increment_Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_Postfix(self));

        auto old = self;
        Next(self);

        return old;
    }

    template <typename string_p>
    inline auto&
        string_itr<string_p>::Operator_Decrement_Prefix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_Prefix(self));

        Prior(self);

        return self;
    }

    template <typename string_p>
    inline auto
        string_itr<string_p>::Operator_Decrement_Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));
        nkr_ASSERT_THAT(!Is_Prefix(self));

        auto old = self;
        Prior(self);

        return old;
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, string::position_e::prefix_tg) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(Has_String());

        Prefix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, string::position_e::first_tg) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(Has_String());

        First(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, string::position_e::last_tg) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(Has_String());

        Last(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, string::position_e::terminus_tg) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(Has_String());

        Terminus(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, string::position_e::postfix_tg) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(Has_String());

        Postfix(*this);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, index_t point_index) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(Has_String());

        First(*this);
        At(*this, point_index);
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const string_itr& other) :
        string(other.string),
        unit_index(other.unit_index),
        point_index(other.point_index),
        is_prefix(other.is_prefix),
        charcoder(other.charcoder)
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(const volatile string_itr& other) :
        string(other.string),
        unit_index(other.unit_index),
        point_index(other.point_index),
        is_prefix(other.is_prefix),
        charcoder(other.charcoder)
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(string_itr&& other) noexcept :
        string(nkr::Move(other.string)),
        unit_index(nkr::Move(other.unit_index)),
        point_index(nkr::Move(other.point_index)),
        is_prefix(nkr::Move(other.is_prefix)),
        charcoder(nkr::Move(other.charcoder))
    {
    }

    template <typename string_p>
    inline string_itr<string_p>::string_itr(volatile string_itr&& other) noexcept :
        string(nkr::Move(other.string)),
        unit_index(nkr::Move(other.unit_index)),
        point_index(nkr::Move(other.point_index)),
        is_prefix(nkr::Move(other.is_prefix)),
        charcoder(nkr::Move(other.charcoder))
    {
    }

    template <typename string_p>
    inline string_itr<string_p>&
        string_itr<string_p>::operator =(const string_itr& other)
    {
        if (this != std::addressof(other)) {
            this->string = other.string;
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->is_prefix = other.is_prefix;
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
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->is_prefix = other.is_prefix;
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
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->is_prefix = other.is_prefix;
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
            this->unit_index = other.unit_index;
            this->point_index = other.point_index;
            this->is_prefix = other.is_prefix;
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
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->is_prefix = nkr::Move(other.is_prefix);
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
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->is_prefix = nkr::Move(other.is_prefix);
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
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->is_prefix = nkr::Move(other.is_prefix);
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
            this->unit_index = nkr::Move(other.unit_index);
            this->point_index = nkr::Move(other.point_index);
            this->is_prefix = nkr::Move(other.is_prefix);
            this->charcoder = nkr::Move(other.charcoder);
        }
        return *this;
    }

    template <typename string_p>
    inline string_itr<string_p>::~string_itr()
    {
        this->string = nullptr;
        this->unit_index = 0;
        this->point_index = 0;
        this->is_prefix = false;
        this->charcoder = none_t();
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Has_String()
        const
    {
        return Has_String(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Has_String()
        const volatile
    {
        return Has_String(*this);
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
        string_itr<string_p>::Is_Prefix()
        const
    {
        return Is_Prefix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Prefix()
        const volatile
    {
        return Is_Prefix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_First()
        const
    {
        return Is_First(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_First()
        const volatile
    {
        return Is_First(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Last()
        const
    {
        return Is_Last(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Last()
        const volatile
    {
        return Is_Last(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Terminus()
        const
    {
        return Is_Terminus(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Terminus()
        const volatile
    {
        return Is_Terminus(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Postfix()
        const
    {
        return Is_Postfix(*this);
    }

    template <typename string_p>
    inline bool_t
        string_itr<string_p>::Is_Postfix()
        const volatile
    {
        return Is_Postfix(*this);
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
    inline void_t
        string_itr<string_p>::Prefix()
    {
        return Prefix(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Prefix()
        volatile
    {
        return Prefix(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::First()
    {
        return First(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::First()
        volatile
    {
        return First(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Last()
    {
        return Last(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Last()
        volatile
    {
        return Last(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Terminus()
    {
        return Terminus(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Terminus()
        volatile
    {
        return Terminus(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Postfix()
    {
        return Postfix(*this);
    }

    template <typename string_p>
    inline void_t
        string_itr<string_p>::Postfix()
        volatile
    {
        return Postfix(*this);
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
        string_itr<string_p>::Point_Unit(index_t index)
        const
    {
        return Point_Unit(*this, index);
    }

    template <typename string_p>
    inline typename string_itr<string_p>::unit_t
        string_itr<string_p>::Point_Unit(index_t index)
        const volatile
    {
        return Point_Unit(*this, index);
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
