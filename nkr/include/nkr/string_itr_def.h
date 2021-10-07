/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/string_itr_dec.h"

namespace nkr {

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Has_String(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(self.string);

        return self.string->Has_Null();
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Prefix(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == 0 && self.is_prefix == true;
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_First(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == 0 && self.is_prefix == false;
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Last(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        count_t unit_length = self.string->Unit_Length();
        if (unit_length > 0) {
            return self.unit_index == unit_length - 1 && self.is_prefix == false;
        } else {
            return self.unit_index == 0 && self.is_prefix == false;
        }
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Null(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == self.string->Unit_Length() && self.is_prefix == false;
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Postfix(const is_any_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        return self.unit_index == self.string->Unit_Count() && self.is_prefix == false;
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Prefix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = 0;
        self.point_index = 0;
        self.is_prefix = true;
        self.charcoder = none_t();
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::First(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = 0;
        self.point_index = 0;
        self.is_prefix = false;
        self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Last(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        count_t unit_length = self.string->Unit_Length();
        if (unit_length > 0) {
            self.unit_index = unit_length - 1;
            self.point_index = self.string->Point_Length() - 1;
            self.is_prefix = false;
            self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
        } else {
            self.unit_index = 0;
            self.point_index = 0;
            self.is_prefix = false;
            self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
        }
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Null(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = self.string->Unit_Count() - 1;
        self.point_index = self.string->Point_Count() - 1;
        self.is_prefix = false;
        self.charcoder.Read_Forward(&self.string->Unit(self.unit_index));
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Postfix(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        self.unit_index = self.string->Unit_Count();
        self.point_index = self.string->Point_Count();
        self.is_prefix = false;
        self.charcoder = none_t();
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Next(is_any_non_const_tr<string_itr> auto& self)
    {
        nkr_ASSERT_THAT(Has_String(self));

        if (Is_Prefix(self)) {
            First(self);

            return true;
        } else if (Is_Null(self)) {
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

    template <string_i string_p>
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
            Null(self);

            return true;
        } else {
            self.charcoder.Read_Reverse(&self.string->Unit(self.unit_index));
            self.unit_index -= self.charcoder.Unit_Count();
            self.point_index -= 1;

            return true;
        }
    }

    template <string_i string_p>
    inline index_t
        string_itr<string_p>::Unit_Index(const is_any_tr<string_itr> auto& self)
    {
        return self.unit_index;
    }

    template <string_i string_p>
    inline index_t
        string_itr<string_p>::Point_Index(const is_any_tr<string_itr> auto& self)
    {
        return self.point_index;
    }

    template <string_i string_p>
    inline string::point_t
        string_itr<string_p>::Point(const is_any_tr<string_itr> auto& self)
    {
        return self.charcoder.Decode();
    }

    template <string_i string_p>
    inline string_itr<string_p>::string_itr(some_t<const string_t*> string, some_t<string::position_e> position) :
        string(string),
        unit_index(0),
        point_index(0),
        is_prefix(false),
        charcoder(none_t())
    {
        nkr_ASSERT_THAT(string);
        nkr_ASSERT_THAT(position);
        nkr_ASSERT_THAT(Has_String());

        if (position == string::position_e::PREFIX) {
            Prefix();
        } else if (position == string::position_e::FIRST) {
            First();
        } else if (position == string::position_e::LAST) {
            Last();
        } else if (position == string::position_e::NULL) {
            Null();
        } else if (position == string::position_e::POSTFIX) {
            Postfix();
        } else {
            nkr_ASSERT_THAT(false);
        }
    }

    template <string_i string_p>
    inline string_itr<string_p>::string_itr(const string_itr& other) :
        string(other.string),
        unit_index(other.unit_index),
        point_index(other.point_index),
        is_prefix(other.is_prefix),
        charcoder(other.charcoder)
    {
    }

    template <string_i string_p>
    inline string_itr<string_p>::string_itr(const volatile string_itr& other) :
        string(other.string),
        unit_index(other.unit_index),
        point_index(other.point_index),
        is_prefix(other.is_prefix),
        charcoder(other.charcoder)
    {
    }

    template <string_i string_p>
    inline string_itr<string_p>::string_itr(string_itr&& other) noexcept :
        string(nkr::Move(other.string)),
        unit_index(nkr::Move(other.unit_index)),
        point_index(nkr::Move(other.point_index)),
        is_prefix(nkr::Move(other.is_prefix)),
        charcoder(nkr::Move(other.charcoder))
    {
    }

    template <string_i string_p>
    inline string_itr<string_p>::string_itr(volatile string_itr&& other) noexcept :
        string(nkr::Move(other.string)),
        unit_index(nkr::Move(other.unit_index)),
        point_index(nkr::Move(other.point_index)),
        is_prefix(nkr::Move(other.is_prefix)),
        charcoder(nkr::Move(other.charcoder))
    {
    }

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
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

    template <string_i string_p>
    inline string_itr<string_p>::~string_itr()
    {
        this->string = nullptr;
        this->unit_index = 0;
        this->point_index = 0;
        this->is_prefix = false;
        this->charcoder = none_t();
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Has_String()
        const
    {
        return Has_String(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Has_String()
        const volatile
    {
        return Has_String(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Prefix()
        const
    {
        return Is_Prefix(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Prefix()
        const volatile
    {
        return Is_Prefix(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_First()
        const
    {
        return Is_First(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_First()
        const volatile
    {
        return Is_First(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Last()
        const
    {
        return Is_Last(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Last()
        const volatile
    {
        return Is_Last(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Null()
        const
    {
        return Is_Null(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Null()
        const volatile
    {
        return Is_Null(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Postfix()
        const
    {
        return Is_Postfix(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Is_Postfix()
        const volatile
    {
        return Is_Postfix(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Prefix()
    {
        return Prefix(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Prefix()
        volatile
    {
        return Prefix(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::First()
    {
        return First(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::First()
        volatile
    {
        return First(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Last()
    {
        return Last(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Last()
        volatile
    {
        return Last(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Null()
    {
        return Null(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Null()
        volatile
    {
        return Null(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Postfix()
    {
        return Postfix(*this);
    }

    template <string_i string_p>
    inline void_t
        string_itr<string_p>::Postfix()
        volatile
    {
        return Postfix(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Next()
    {
        return Next(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Next()
        volatile
    {
        return Next(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Prior()
    {
        return Prior(*this);
    }

    template <string_i string_p>
    inline bool_t
        string_itr<string_p>::Prior()
        volatile
    {
        return Prior(*this);
    }

    template <string_i string_p>
    inline index_t
        string_itr<string_p>::Unit_Index()
        const
    {
        return Unit_Index(*this);
    }

    template <string_i string_p>
    inline index_t
        string_itr<string_p>::Unit_Index()
        const volatile
    {
        return Unit_Index(*this);
    }

    template <string_i string_p>
    inline index_t
        string_itr<string_p>::Point_Index()
        const
    {
        return Point_Index(*this);
    }

    template <string_i string_p>
    inline index_t
        string_itr<string_p>::Point_Index()
        const volatile
    {
        return Point_Index(*this);
    }

    template <string_i string_p>
    inline string::point_t
        string_itr<string_p>::Point()
        const
    {
        return Point(*this);
    }

    template <string_i string_p>
    inline string::point_t
        string_itr<string_p>::Point()
        const volatile
    {
        return Point(*this);
    }

}
