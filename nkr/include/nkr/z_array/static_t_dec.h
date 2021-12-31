/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/z_bool_t.h"
#include "nkr/z_intrinsics.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_pointer_t.h"
#include "nkr/z_some_t.h"
#include "nkr/z_traits.h"

#include "nkr/z_allocator_err.h"

#include "nkr/z_array_i.h"

namespace nkr { namespace array {

    template <typename unit_p, count_t capacity_p>
    class stack_t;

}}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class static_t;

    struct                      static_tg   {};
    template <typename> struct  static_ttg  {};

}}

namespace nkr { namespace array { namespace $static_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, static_t<typename type_p::unit_t>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<array::static_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <array::$static_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<array::static_tg>
    {
    public:
        using of_t  = type_p::unit_t;
    };

    template <>
    class template_traits_i<array::static_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = array::static_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<array::static_t> :
        public template_traits_i<array::static_ttg>
    {
    public:
    };

}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class static_t
    {
    public:
        using unit_t    = unit_p;
        using split_t   = stack_t<static_t, 2>;

    private:
        static auto&    Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto&& other);

        static bool_t   Has_Memory(const is_any_tr<static_t> auto& self);

        static auto     Pointer(is_any_tr<static_t> auto& self);
        static void_t   Pointer(is_any_non_const_tr<static_t> auto& self, maybe_t<pointer_t<unit_t>> new_pointer);

        static count_t  Count(const is_any_tr<static_t> auto& self);
        static void_t   Count(tr1<any_non_const_tg, static_t> auto& self, count_t new_unit_count);

        static auto&    Unit(is_any_tr<static_t> auto& self, index_t index);

        static split_t  Split(const is_any_tr<static_t> auto& self, index_t at_index);

    protected:
        maybe_t<pointer_t<unit_t>>  pointer;

    public:
        static_t();

        static_t(const maybe_t<pointer_t<unit_t>>& pointer);
        static_t(maybe_t<pointer_t<unit_t>>&& pointer);

        static_t(tr2<any_tg, pointable_array_ttg, of_just_accessed_tg, unit_t> auto& array);

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
        bool_t                                      Has_Memory() const;
        bool_t                                      Has_Memory() const volatile;

        maybe_t<pointer_t<unit_t>>                  Pointer();
        maybe_t<pointer_t<const unit_t>>            Pointer() const;
        maybe_t<pointer_t<volatile unit_t>>         Pointer() volatile;
        maybe_t<pointer_t<const volatile unit_t>>   Pointer() const volatile;
        void_t                                      Pointer(maybe_t<pointer_t<unit_t>> new_pointer);
        void_t                                      Pointer(maybe_t<pointer_t<unit_t>> new_pointer) volatile;

        count_t                                     Count() const;
        count_t                                     Count() const volatile;
        void_t                                      Count(count_t new_unit_count);
        void_t                                      Count(count_t new_unit_count) volatile;

        unit_t&                                     Unit(index_t index);
        const unit_t&                               Unit(index_t index) const;
        volatile unit_t&                            Unit(index_t index) volatile;
        const volatile unit_t&                      Unit(index_t index) const volatile;

        split_t                                     Split(index_t at_index) const;
        split_t                                     Split(index_t at_index) const volatile;

        maybe_t<allocator_err>                      Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        maybe_t<allocator_err>                      Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;

    public:
        unit_t&                 operator [](index_t index);
        const unit_t&           operator [](index_t index) const;
        volatile unit_t&        operator [](index_t index) volatile;
        const volatile unit_t&  operator [](index_t index) const volatile;
    };

    static_assert(array_i<static_t<word_t>>);
    static_assert(array_i<static_t<const word_t>>);
    static_assert(array_i<static_t<volatile word_t>>);
    static_assert(array_i<static_t<const volatile word_t>>);
    static_assert(array_i<const static_t<word_t>>);
    static_assert(array_i<const static_t<const word_t>>);
    static_assert(array_i<const static_t<volatile word_t>>);
    static_assert(array_i<const static_t<const volatile word_t>>);
    static_assert(array_i<volatile static_t<word_t>>);
    static_assert(array_i<volatile static_t<const word_t>>);
    static_assert(array_i<volatile static_t<volatile word_t>>);
    static_assert(array_i<volatile static_t<const volatile word_t>>);
    static_assert(array_i<const volatile static_t<word_t>>);
    static_assert(array_i<const volatile static_t<const word_t>>);
    static_assert(array_i<const volatile static_t<volatile word_t>>);
    static_assert(array_i<const volatile static_t<const volatile word_t>>);

    static_assert(non_aggregate_array_i<static_t<word_t>>);
    static_assert(non_aggregate_array_i<static_t<const word_t>>);
    static_assert(non_aggregate_array_i<static_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<static_t<const volatile word_t>>);
    static_assert(non_aggregate_array_i<const static_t<word_t>>);
    static_assert(non_aggregate_array_i<const static_t<const word_t>>);
    static_assert(non_aggregate_array_i<const static_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<const static_t<const volatile word_t>>);
    static_assert(non_aggregate_array_i<volatile static_t<word_t>>);
    static_assert(non_aggregate_array_i<volatile static_t<const word_t>>);
    static_assert(non_aggregate_array_i<volatile static_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<volatile static_t<const volatile word_t>>);
    static_assert(non_aggregate_array_i<const volatile static_t<word_t>>);
    static_assert(non_aggregate_array_i<const volatile static_t<const word_t>>);
    static_assert(non_aggregate_array_i<const volatile static_t<volatile word_t>>);
    static_assert(non_aggregate_array_i<const volatile static_t<const volatile word_t>>);

    static_assert(pointable_array_i<static_t<word_t>>);
    static_assert(pointable_array_i<static_t<const word_t>>);
    static_assert(pointable_array_i<static_t<volatile word_t>>);
    static_assert(pointable_array_i<static_t<const volatile word_t>>);
    static_assert(pointable_array_i<const static_t<word_t>>);
    static_assert(pointable_array_i<const static_t<const word_t>>);
    static_assert(pointable_array_i<const static_t<volatile word_t>>);
    static_assert(pointable_array_i<const static_t<const volatile word_t>>);
    static_assert(pointable_array_i<volatile static_t<word_t>>);
    static_assert(pointable_array_i<volatile static_t<const word_t>>);
    static_assert(pointable_array_i<volatile static_t<volatile word_t>>);
    static_assert(pointable_array_i<volatile static_t<const volatile word_t>>);
    static_assert(pointable_array_i<const volatile static_t<word_t>>);
    static_assert(pointable_array_i<const volatile static_t<const word_t>>);
    static_assert(pointable_array_i<const volatile static_t<volatile word_t>>);
    static_assert(pointable_array_i<const volatile static_t<const volatile word_t>>);

}}
