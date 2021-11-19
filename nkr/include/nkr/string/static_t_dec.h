/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array/static_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"
#include "nkr/string_itr_dec.h"
#include "nkr/string/stack_t_dec.h"

namespace nkr { namespace string {

    template <charcoder_i charcoder_p>
    class static_t;

    struct                      static_tg   {};
    template <typename> struct  static_ttg  {};

}}

namespace nkr { namespace string { namespace $static_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, static_t<typename type_p::qualified_charcoder_t>>;

}}}

namespace nkr {

    template <>
    class type_traits_i<string::static_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <string::$static_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<string::static_tg>
    {
    public:
        using of_t  = type_p::qualified_charcoder_t;
    };

    template <>
    class template_traits_i<string::static_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = string::static_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<string::static_t> :
        public template_traits_i<string::static_ttg>
    {
    public:
    };

}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p>
    class static_t
    {
    public:
        using charcoder_t           = std::remove_cv_t<charcoder_p>;
        using qualified_charcoder_t = charcoder_p;
        using unit_t                = same_qualification_as_t<typename charcoder_t::unit_t, qualified_charcoder_t>;
        using array_t               = array::static_t<unit_t>;

    public:
        static constexpr c_bool_t   Has_Guaranteed_Terminus();

    public:
        static const unit_t*    Empty_C_String();

    private:
        static void_t   Construct(is_any_non_const_tr<static_t> auto& self, tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string);

        static auto&    Copy_Assign(is_any_non_const_tr<static_t> auto& self, const is_any_tr<static_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<static_t> auto& self, is_any_non_const_tr<static_t> auto&& other);

        static bool_t   Has_Memory(const is_any_tr<static_t> auto& self);
        static bool_t   Has_Terminus(const is_any_tr<static_t> auto& self);

        static count_t  Unit_Count(const is_any_tr<static_t> auto& self);
        static count_t  Unit_Length(const is_any_tr<static_t> auto& self);

        static count_t  Point_Count(const is_any_tr<static_t> auto& self);
        static count_t  Point_Length(const is_any_tr<static_t> auto& self);

        static auto     C_String(const is_any_tr<static_t> auto& self);

        static auto&    Unit(is_any_tr<static_t> auto& self, index_t unit_index);

    protected:
        count_t point_count;
        array_t array;

    public:
        static_t();

        static_t(tr1<any_tg, unit_t*> auto c_string);
        static_t(tr1<any_tg, unit_t*> auto c_string, count_t unit_count, count_t point_count);
        static_t(tr2<any_tg, maybe_t, of_any_tg, unit_t*> auto maybe_c_string);
        static_t(tr2<any_tg, maybe_t, of_any_tg, unit_t*> auto maybe_c_string, count_t unit_count, count_t point_count);
        static_t(tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string);
        static_t(tr2<any_tg, some_t, of_any_tg, unit_t*> auto some_c_string, count_t unit_count, count_t point_count);

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
        bool_t                          Has_Memory() const;
        bool_t                          Has_Memory() const volatile;
        bool_t                          Has_Terminus() const;
        bool_t                          Has_Terminus() const volatile;

        count_t                         Unit_Count() const;
        count_t                         Unit_Count() const volatile;
        count_t                         Unit_Length() const;
        count_t                         Unit_Length() const volatile;

        count_t                         Point_Count() const;
        count_t                         Point_Count() const volatile;
        count_t                         Point_Length() const;
        count_t                         Point_Length() const volatile;

        some_t<const unit_t*>           C_String() const;
        some_t<const volatile unit_t*>  C_String() const volatile;

        unit_t&                         Unit(index_t unit_index);
        const unit_t&                   Unit(index_t unit_index) const;
        volatile unit_t&                Unit(index_t unit_index) volatile;
        const volatile unit_t&          Unit(index_t unit_index) const volatile;
    };
    static_assert(string_i<static_t<charcoder::utf_8_t>>);
    static_assert(string_i<const static_t<charcoder::utf_8_t>>);
    static_assert(string_i<volatile static_t<charcoder::utf_8_t>>);
    static_assert(string_i<const volatile static_t<charcoder::utf_8_t>>);

}}

namespace nkr { namespace string {

    template <
        charcoder_i charcoder_p,
        count_t                     min_point_count_p   = 1,
        count_t                     max_point_count_p   = 128
    > class random_static_t :
        public static_t<charcoder_p>
    {
    public:
        static_assert(min_point_count_p <= max_point_count_p);

    public:
        using base_t                = static_t<charcoder_p>;

        using charcoder_t           = base_t::charcoder_t;
        using qualified_charcoder_t = base_t::qualified_charcoder_t;
        using unit_t                = base_t::unit_t;
        using stack_t               = stack_t<qualified_charcoder_t, max_point_count_p * charcoder_t::Max_Unit_Count()>;

    private:
        static auto&    Copy_Assign(is_any_non_const_tr<random_static_t> auto& self, const is_any_tr<random_static_t> auto& other);
        static auto&    Move_Assign(is_any_non_const_tr<random_static_t> auto& self, is_any_non_const_tr<random_static_t> auto&& other);

    protected:
        stack_t random;

    public:
        random_static_t(bool_t use_erroneous_units = false);
        random_static_t(tr2<any_tg, c_pointer_ttg, of_any_tg, unit_t> auto c_string);

        random_static_t(const random_static_t& other);
        random_static_t(const volatile random_static_t& other);
        random_static_t(random_static_t&& other) noexcept;
        random_static_t(volatile random_static_t&& other) noexcept;

        random_static_t&            operator =(const random_static_t& other);
        volatile random_static_t&   operator =(const random_static_t& other) volatile;
        random_static_t&            operator =(const volatile random_static_t& other);
        volatile random_static_t&   operator =(const volatile random_static_t& other) volatile;
        random_static_t&            operator =(random_static_t&& other) noexcept;
        volatile random_static_t&   operator =(random_static_t&& other) volatile noexcept;
        random_static_t&            operator =(is_just_volatile_tr<random_static_t> auto&& other) noexcept;
        volatile random_static_t&   operator =(is_just_volatile_tr<random_static_t> auto&& other) volatile noexcept;

        ~random_static_t();
    };

}}

namespace nkr {

    template <
        tr1<any_tg, string::static_tg>  string_p,
        count_t                         min_point_count_p   = 1,
        count_t                         max_point_count_p   = 128
    > auto  Random(bool_t use_erroneous_units = false);

}
