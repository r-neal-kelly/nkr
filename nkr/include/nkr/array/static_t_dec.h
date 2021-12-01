/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array_i.h"

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
        using pointer_t = nkr::pointer_t<unit_p>;

    private:
        static auto&    Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto&& other);

        static bool_t   Has_Memory(const is_any_tr<static_t> auto& self);

        static count_t  Count(const is_any_tr<static_t> auto& self);

        static unit_t&  At(const is_any_tr<static_t> auto& self, index_t index);

    protected:
        maybe_t<pointer_t>  pointer;

    public:
        static_t();

        static_t(const maybe_t<pointer_t>& pointer);
        static_t(maybe_t<pointer_t>&& pointer);

        static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array);

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
        bool_t                  Has_Memory() const;
        bool_t                  Has_Memory() const volatile;

        maybe_t<pointer_t>      Pointer() const;
        maybe_t<pointer_t>      Pointer() const volatile;
        void_t                  Pointer(maybe_t<pointer_t> new_pointer);
        void_t                  Pointer(maybe_t<pointer_t> new_pointer) volatile;

        count_t                 Count() const;
        count_t                 Count() const volatile;

        unit_t&                 At(index_t index) const;
        unit_t&                 At(index_t index) const volatile;

        maybe_t<allocator_err>  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const;
        maybe_t<allocator_err>  Copy_To(any_non_const_array_of_any_tr<unit_t> auto& other) const volatile;

    public:
        unit_t& operator [](index_t index) const;
        unit_t& operator [](index_t index) const volatile;
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

}}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class extra_static_t;

    struct                      extra_static_tg     {};
    template <typename> struct  extra_static_ttg    {};

}}

namespace nkr { namespace array { namespace $extra_static_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, extra_static_t<typename type_p::unit_t>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<array::extra_static_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <array::$extra_static_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<array::extra_static_tg>
    {
    public:
        using of_t  = type_p::unit_t;
    };

    template <>
    class template_traits_i<array::extra_static_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = array::extra_static_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<array::extra_static_t> :
        public template_traits_i<array::extra_static_ttg>
    {
    public:
    };

}

namespace nkr { namespace array {

    template <any_type_tr unit_p>
    class extra_static_t
    {
    public:
        using unit_t    = unit_p;
        using static_t  = static_t<unit_t>;
        using pointer_t = static_t::pointer_t;

    private:
        static auto&    Copy_Assign(is_any_non_const_tr<extra_static_t> auto& self, const is_any_tr<extra_static_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<extra_static_t> auto& self, is_any_non_const_tr<extra_static_t> auto&& other);

        static bool_t   Has_Memory(const is_any_tr<extra_static_t> auto& self);

        static count_t  Unit_Count(const is_any_tr<extra_static_t> auto& self);
        static count_t  Actual_Unit_Count(const is_any_tr<extra_static_t> auto& self);
        static count_t  Extra_Unit_Count(const is_any_tr<extra_static_t> auto& self);
        static count_t  Total_Unit_Count(const is_any_tr<extra_static_t> auto& self);

        static unit_t&  Unit(const is_any_tr<extra_static_t> auto& self, index_t index);
        static unit_t&  Extra_Unit(const is_any_tr<extra_static_t> auto& self);

    protected:
        static_t        static_array;
        count_t         total_unit_count;
        mutable unit_t  extra_unit;

    public:
        extra_static_t();

        extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array);
        extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array, count_t total_unit_count);
        extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array, count_t total_unit_count, const tr1<any_tg, unit_t> auto& extra_unit);
        extra_static_t(tr2<any_tg, array_ttg, of_just_tg, unit_t> auto& array, count_t total_unit_count, tr1<any_non_const_tg, unit_t> auto&& extra_unit);

        extra_static_t(const extra_static_t& other);
        extra_static_t(const volatile extra_static_t& other);
        extra_static_t(extra_static_t&& other) noexcept;
        extra_static_t(volatile extra_static_t&& other) noexcept;

        extra_static_t&             operator =(const extra_static_t& other);
        volatile extra_static_t&    operator =(const extra_static_t& other) volatile;
        extra_static_t&             operator =(const volatile extra_static_t& other);
        volatile extra_static_t&    operator =(const volatile extra_static_t& other) volatile;
        extra_static_t&             operator =(extra_static_t&& other) noexcept;
        volatile extra_static_t&    operator =(extra_static_t&& other) volatile noexcept;
        extra_static_t&             operator =(is_just_volatile_tr<extra_static_t> auto&& other) noexcept;
        volatile extra_static_t&    operator =(is_just_volatile_tr<extra_static_t> auto&& other) volatile noexcept;

        ~extra_static_t();

    public:
        bool_t  Has_Memory() const;
        bool_t  Has_Memory() const volatile;

        count_t Count() const;
        count_t Count() const volatile;
        count_t Unit_Count() const;
        count_t Unit_Count() const volatile;
        count_t Actual_Unit_Count() const;
        count_t Actual_Unit_Count() const volatile;
        count_t Extra_Unit_Count() const;
        count_t Extra_Unit_Count() const volatile;
        count_t Total_Unit_Count() const;
        count_t Total_Unit_Count() const volatile;

        unit_t& Unit(index_t index) const;
        unit_t& Unit(index_t index) const volatile;
        unit_t& Extra_Unit() const;
        unit_t& Extra_Unit() const volatile;

    public:
        unit_t& operator [](index_t index) const;
        unit_t& operator [](index_t index) const volatile;
    };

}}
