/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/math.h"
#include "nkr/maybe_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"
#include "nkr/allocator_i.h"
#include "nkr/allocator/heap_t.h"

#include "nkr/array/dynamic_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"

namespace nkr {

    template <typename string_p>
    class string_itr;

}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, allocator_i allocator_p, math::fraction_i grow_rate_p>
    class dynamic_t;

    template <typename string_p>
    concept any_dynamic_tr =
        is_any_tr<string_p, dynamic_t<typename string_p::charcoder_t, typename string_p::allocator_t, typename string_p::grow_rate_t>>;

    nkr_DEFINE_CONTAINER_TRAITS(dynamic, charcoder_t);

}}

namespace nkr { namespace string {

    // might it be worth adding an iterator to the string itself? that way we can allow things like the access operator to be more efficient
    // also, the we wouldn't necessarily have to use the stack for charcoders, unless we wanted to.

    template <
        charcoder_i         charcoder_p,
        allocator_i         allocator_p = allocator::heap_t<typename charcoder_p::unit_t>,
        math::fraction_i    grow_rate_p = math::fraction_t<17, 10>
    > class dynamic_t
    {
    public:
        static_assert(is_tr<charcoder_p::unit_t, allocator_p::unit_t>, "charcoder and allocator have different unit types");

    public:
        using charcoder_t   = charcoder_p;
        using unit_t        = charcoder_p::unit_t;
        using allocator_t   = allocator_p;
        using grow_rate_t   = grow_rate_p;
        using array_t       = array::dynamic_t<unit_t, allocator_p, grow_rate_p>;
        using iterator_t    = string_itr<dynamic_t>;

    public:
        static const unit_t*    Default_C_String();

    private:
        static auto&                    Copy_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                    const is_any_tr<dynamic_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<dynamic_t> auto& self,
                                                    is_any_non_const_tr<dynamic_t> auto& other);

        static bool_t                   Has_Memory(const is_any_tr<dynamic_t> auto& self);
        static bool_t                   Has_Terminus(const is_any_tr<dynamic_t> auto& self);

        static count_t                  Unit_Capacity(const is_any_tr<dynamic_t> auto& self);
        static maybe_t<allocator_err>   Unit_Capacity(is_any_tr<dynamic_t> auto& self, count_t unit_capacity_including_terminus);

        static count_t                  Unit_Count(const is_any_tr<dynamic_t> auto& self);
        static count_t                  Unit_Length(const is_any_tr<dynamic_t> auto& self);

        static count_t                  Point_Count(const is_any_tr<dynamic_t> auto& self);
        static count_t                  Point_Length(const is_any_tr<dynamic_t> auto& self);

        static some_t<const unit_t*>    C_String(const is_any_tr<dynamic_t> auto& self);

        static iterator_t               At(const is_any_tr<dynamic_t> auto& self, index_t point_index);
        static iterator_t               At_Prefix(const is_any_tr<dynamic_t> auto& self);
        static iterator_t               At_First(const is_any_tr<dynamic_t> auto& self);
        static iterator_t               At_Last(const is_any_tr<dynamic_t> auto& self);
        static iterator_t               At_Terminus(const is_any_tr<dynamic_t> auto& self);
        static iterator_t               At_Postfix(const is_any_tr<dynamic_t> auto& self);

        static void_t                   Push_Terminus(is_any_tr<dynamic_t> auto& self);
        static void_t                   Pop_Terminus(is_any_tr<dynamic_t> auto& self);

        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, point_t point);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const charcoder_t& charcoder);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const is_any_tr<unit_t> auto* c_string);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const is_any_tr<unit_t> auto* c_string, count_t unit_length);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, const any_string_tr auto& other);
        static maybe_t<allocator_err>   Push(is_any_tr<dynamic_t> auto& self, any_non_const_string_tr auto&& other);

        static auto&                    Unit(is_any_tr<dynamic_t> auto& self, index_t unit_index);

    protected:
        count_t point_count;
        array_t array;

    public:
        dynamic_t();

        dynamic_t(count_t unit_capacity_including_terminus);

        dynamic_t(const charcoder_t& charcoder);
        dynamic_t(const is_any_tr<unit_t> auto* c_string); // const is_any_some_of_any_tr<unit_t> auto*

        dynamic_t(const any_string_tr auto& string);
        dynamic_t(any_non_const_string_tr auto&& string);
        dynamic_t(any_const_string_tr auto&& string)                                                    = delete;

        dynamic_t(const dynamic_t& other);
        dynamic_t(const volatile dynamic_t& other);
        dynamic_t(dynamic_t&& other) noexcept;
        dynamic_t(volatile dynamic_t&& other) noexcept;

        dynamic_t&          operator =(const dynamic_t& other);
        volatile dynamic_t& operator =(const dynamic_t& other) volatile;
        dynamic_t&          operator =(const volatile dynamic_t& other);
        volatile dynamic_t& operator =(const volatile dynamic_t& other) volatile;
        dynamic_t&          operator =(dynamic_t&& other) noexcept;
        volatile dynamic_t& operator =(dynamic_t&& other) volatile noexcept;
        dynamic_t&          operator =(is_just_volatile_tr<dynamic_t> auto&& other) noexcept;
        volatile dynamic_t& operator =(is_just_volatile_tr<dynamic_t> auto&& other) volatile noexcept;

        ~dynamic_t();

    public:
        bool_t                  Has_Memory() const;
        bool_t                  Has_Memory() const volatile;
        bool_t                  Has_Terminus() const;
        bool_t                  Has_Terminus() const volatile;

        count_t                 Unit_Capacity() const;
        count_t                 Unit_Capacity() const volatile;
        maybe_t<allocator_err>  Unit_Capacity(count_t unit_capacity_including_terminus);
        maybe_t<allocator_err>  Unit_Capacity(count_t unit_capacity_including_terminus) volatile;

        count_t                 Unit_Count() const;
        count_t                 Unit_Count() const volatile;
        count_t                 Unit_Length() const;
        count_t                 Unit_Length() const volatile;

        count_t                 Point_Count() const;
        count_t                 Point_Count() const volatile;
        count_t                 Point_Length() const;
        count_t                 Point_Length() const volatile;

        some_t<const unit_t*>   C_String() const;
        some_t<const unit_t*>   C_String() const volatile;

        iterator_t              At(index_t point_index) const;
        iterator_t              At(index_t point_index) const volatile;
        iterator_t              At_Prefix() const;
        iterator_t              At_Prefix() const volatile;
        iterator_t              At_First() const;
        iterator_t              At_First() const volatile;
        iterator_t              At_Last() const;
        iterator_t              At_Last() const volatile;
        iterator_t              At_Terminus() const;
        iterator_t              At_Terminus() const volatile;
        iterator_t              At_Postfix() const;
        iterator_t              At_Postfix() const volatile;

        maybe_t<allocator_err>  Push(point_t point);
        maybe_t<allocator_err>  Push(point_t point) volatile;
        maybe_t<allocator_err>  Push(const charcoder_t& charcoder);
        maybe_t<allocator_err>  Push(const charcoder_t& charcoder) volatile;
        maybe_t<allocator_err>  Push(const is_any_tr<unit_t> auto* c_string);
        maybe_t<allocator_err>  Push(const is_any_tr<unit_t> auto* c_string) volatile;
        maybe_t<allocator_err>  Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length);
        maybe_t<allocator_err>  Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length) volatile;
        maybe_t<allocator_err>  Push(const any_string_tr auto& string);
        maybe_t<allocator_err>  Push(const any_string_tr auto& string) volatile;
        maybe_t<allocator_err>  Push(any_non_const_string_tr auto&& string);
        maybe_t<allocator_err>  Push(any_non_const_string_tr auto&& string) volatile;

        unit_t&                 Unit(index_t unit_index);
        const unit_t&           Unit(index_t unit_index) const;
        volatile unit_t&        Unit(index_t unit_index) volatile;
        const volatile unit_t&  Unit(index_t unit_index) const volatile;

        // Split and Join should return new strings without altering this one.
    };
    static_assert(string_i<dynamic_t<charcoder::utf_8_t>>);
    static_assert(string_i<const dynamic_t<charcoder::utf_8_t>>);
    static_assert(string_i<volatile dynamic_t<charcoder::utf_8_t>>);
    static_assert(string_i<const volatile dynamic_t<charcoder::utf_8_t>>);

}}

namespace nkr {

    template <
        string::any_dynamic_tr  string_p,
        count_t                 min_point_count_p       = 1,
        count_t                 max_point_count_p       = 128
    > auto  Random(bool_t use_errorneous_units = false);

}
