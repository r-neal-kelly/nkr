/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"

#include "nkr/allocator_err.h"

#include "nkr/array/static_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"

namespace nkr {

    template <typename string_p>
    class string_itr;

}

namespace nkr { namespace string {

    // I feel that a string::static_t should not have to have the terminus,
    // that way it's easier to just make a partition with an already existing string.
    // our string interfaces will need to be able to handle this type's unique case.

    // the trick to using this with the string_itr is to basically pretend that there is a terminus
    // even when there may not be. So, if the itr requests a unit_t& reference to the terminus,
    // we may need to return a static reference to terminus that is far removed from the string.
    // although dangerous if the itr presumes that it can get the rest of the string from there,
    // I'm not sure if there's a better way to do it without directly interfering with the quite complex
    // code of the itr itself, which may end up being the most robust option. but try to do as much here
    // first.

    template <charcoder_i charcoder_p>
    class static_t
    {
    public:
        using charcoder_t   = charcoder_p;
        using unit_t        = charcoder_p::unit_t;
        using array_t       = array::static_t<unit_t>;

    protected:
        count_t point_count;
        array_t array;

    public:
        static_t();

        // not yet sure what to pass here yet.

        static_t(const static_t& other);
        static_t(const volatile static_t& other);
        static_t(static_t&& other) noexcept;
        static_t(volatile static_t&& other) noexcept;

        static_t&           operator =(const static_t& other);
        volatile static_t&  operator =(const static_t& other) volatile;
        static_t&           operator =(const volatile static_t& other);
        volatile static_t&  operator =(const volatile static_t& other) volatile;
        static_t&           operator =(static_t&& other) noexcept;
        volatile static_t&  operator =(static_t&& other) volatile noexcept;
        static_t&           operator =(is_just_volatile_tr<static_t> auto&& other) noexcept;
        volatile static_t&  operator =(is_just_volatile_tr<static_t> auto&& other) volatile noexcept;

        ~static_t();

    public:
        bool_t                              Has_Terminus() const; // always return true, because it abstractly does, even if literally not
        bool_t                              Has_Terminus() const volatile;

        count_t                             Unit_Count() const;
        count_t                             Unit_Count() const volatile;
        count_t                             Unit_Length() const;
        count_t                             Unit_Length() const volatile;

        count_t                             Point_Count() const;
        count_t                             Point_Count() const volatile;
        count_t                             Point_Length() const;
        count_t                             Point_Length() const volatile;

        some_t<const unit_t*>               C_String() const;
        some_t<const volatile unit_t*>      C_String() const volatile;
    };

}}
