/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/pointer_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

#include "nkr/allocator_err.h"

#include "nkr/array/stack_t.h"

#include "nkr/charcoder_i.h"
#include "nkr/charcoder/utf_8_t.h"

#include "nkr/string_i.h"

namespace nkr { namespace testing {

    template <typename type_p>
    class traits_i
    {
    public:
        using of_t          = void_t;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = void_t;

    public:
        template <typename other_p>
        struct is_any_tmpl :
            public std::false_type
        {
        };
    };

    template <typename subject_p, typename object_p>
    concept any__tr =
        traits_i<subject_p>::template is_any_tmpl<object_p>::value;

    template <typename subject_p, typename object_p>
    concept any_const__tr =
        any__tr<subject_p, object_p> &&
        any_const_tr<subject_p>;

    template <typename resolver_p>
    using of_t          = traits_i<resolver_p>::of_t;

    template <typename resolver_p, template <typename ...> typename resolvee_p, typename of_p>
    using resolved_t    = traits_i<resolver_p>::template resolved_t<resolvee_p, of_p>;

    template <typename subject_p, template <typename ...> typename object_p, typename of_p>
    concept any__of_any__tr =
        any__tr<subject_p, resolved_t<subject_p, object_p, of_p>> &&
        any__tr<of_t<subject_p>, of_t<resolved_t<subject_p, object_p, of_p>>>;

    template <typename subject_p, template <typename ...> typename object_p, template <typename ...> typename of_p, typename of_of_p>
    concept any__of_any__of_any__tr =
        any__of_any__tr<subject_p, object_p, resolved_t<of_t<subject_p>, of_p, of_of_p>> &&
        any__tr<of_t<of_t<subject_p>>, of_t<resolved_t<of_t<subject_p>, of_p, of_of_p>>>;

    template <integer_tr type_p>
    class traits_i<type_p>
    {
    public:
        using of_t          = void_t;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = void_t;

    public:
        template <typename other_p>
        struct is_any_tmpl :
            public std::false_type
        {
        };

        template <is_any_tr<type_p> other_p>
        struct is_any_tmpl<other_p> :
            public std::true_type
        {
        };
    };

    template <typename>
    class c_pointer_tg
    {
    public:
    };

    template <type_pointer_tr type_p>
    class traits_i<type_p>
    {
    public:
        using of_t          = std::remove_pointer_t<type_p>;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = of_p*;

    public:
        template <typename other_p>
        struct is_any_tmpl :
            public std::false_type
        {
        };

        template <type_pointer_tr other_p>
        struct is_any_tmpl<other_p> :
            public std::true_type
        {
        };
    };

    template <typename parameter_p>
    class test_t;

    namespace $test_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, test_t<typename type_p::parameter_t>>;

    }

    template <$test_t::any_tr type_p>
    class traits_i<type_p>
    {
    public:
        using of_t          = type_p::parameter_t;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = template_p<of_p>;

    public:
        template <typename other_p>
        struct is_any_tmpl :
            public std::false_type
        {
        };

        template <$test_t::any_tr other_p>
        struct is_any_tmpl<other_p> :
            public std::true_type
        {
        };
    };

    template <typename parameter_p>
    class test_t
    {
    public:
        using parameter_t   = parameter_p;
    };

    static_assert(any__tr<test_t<char>,
                  test_t<char>>);
    static_assert(any__tr<volatile test_t<const volatile char>,
                  test_t<char>>);

    static_assert(any_const__tr<const volatile test_t<char>,
                  test_t<char>>);

    static_assert(any__of_any__tr<volatile test_t<const volatile char>,
                  test_t, char>);
    static_assert(any__of_any__tr<test_t<volatile test_t<char>>,
                  test_t, test_t<char>>);

    static_assert(any__of_any__of_any__tr<test_t<test_t<char>>,
                  test_t, test_t, char>);

    static_assert(any__of_any__of_any__tr<test_t<char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<test_t<const volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const test_t<const volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<volatile test_t<const volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const volatile char*>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const volatile char* const>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const volatile char* volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);
    static_assert(any__of_any__of_any__tr<const volatile test_t<const volatile char* const volatile>,
                  test_t, c_pointer_tg, char>);

}}

namespace nkr {

    template <typename string_p>
    class string_itr;

}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, count_t unit_capacity_p>
    class stack_t;

    template <typename string_p>
    concept any_stack_tr =
        is_any_tr<string_p, stack_t<typename string_p::charcoder_t, string_p::Unit_Capacity()>>;

    nkr_DEFINE_CONTAINER_TRAITS(stack, charcoder_t);

}}

namespace nkr { namespace string {

    template <charcoder_i charcoder_p, count_t unit_capacity_p = 128>
    class stack_t
    {
    public:
        static_assert(unit_capacity_p >= 1, "string::stack_t must have at least a unit_capacity of 1 to fit the terminus.");

    public:
        using charcoder_t   = std::remove_cv_t<charcoder_p>;
        using unit_t        = charcoder_p::unit_t;
        using array_t       = array::stack_t<unit_t, unit_capacity_p>;

    public:
        template <charcoder_i charcoder_pp, count_t unit_capacity_pp>
        friend class stack_t;

    public:
        static constexpr count_t    Unit_Capacity();

    public:
        static const unit_t*    Empty_C_String();

    private:
        static auto&                    Copy_Assign(is_any_non_const_tr<stack_t> auto& self, const is_any_tr<stack_t> auto& other);
        static auto&                    Move_Assign(is_any_non_const_tr<stack_t> auto& self, is_any_non_const_tr<stack_t> auto& other);

        static bool_t                   Has_Terminus(const is_any_tr<stack_t> auto& self);

        static count_t                  Unit_Capacity(const is_any_tr<stack_t> auto& self);
        static maybe_t<allocator_err>   Unit_Capacity(is_any_non_const_tr<stack_t> auto& self, count_t unit_capacity_including_terminus);

        static count_t                  Unit_Count(const is_any_tr<stack_t> auto& self);
        static count_t                  Unit_Length(const is_any_tr<stack_t> auto& self);

        static count_t                  Point_Count(const is_any_tr<stack_t> auto& self);
        static count_t                  Point_Length(const is_any_tr<stack_t> auto& self);

        static auto                     C_String(const is_any_tr<stack_t> auto& self);

        static auto                     At(const is_any_tr<stack_t> auto& self, index_t point_index);
        static auto                     At_Prefix(const is_any_tr<stack_t> auto& self);
        static auto                     At_First(const is_any_tr<stack_t> auto& self);
        static auto                     At_Last(const is_any_tr<stack_t> auto& self);
        static auto                     At_Terminus(const is_any_tr<stack_t> auto& self);
        static auto                     At_Postfix(const is_any_tr<stack_t> auto& self);

        static void_t                   Push_Terminus(is_any_non_const_tr<stack_t> auto& self);
        static void_t                   Pop_Terminus(is_any_non_const_tr<stack_t> auto& self);

        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, point_t point);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const charcoder_t& charcoder);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, any_c_pointer_of_any_tr<unit_t> auto c_string);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, any_c_pointer_of_any_tr<unit_t> auto c_string, count_t unit_length);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, const any_string_tr auto& other);
        static maybe_t<allocator_err>   Push(is_any_non_const_tr<stack_t> auto& self, any_non_const_string_tr auto&& other);

        static auto&                    Unit(is_any_tr<stack_t> auto& self, index_t unit_index);

    protected:
        count_t point_count;
        array_t array;

    public:
        stack_t();

        stack_t(const charcoder_t& charcoder);
        stack_t(any_c_pointer_of_any_tr<unit_t> auto c_string);
        stack_t(any_maybe_of_any_c_pointer_of_any_tr<unit_t> auto maybe_c_string);
        stack_t(any_some_of_any_c_pointer_of_any_tr<unit_t> auto some_c_string);
        stack_t(some_t<pointer_t<unit_t>> some_pointer);

        stack_t(const any_string_tr auto& string);
        stack_t(any_non_const_string_tr auto&& string);
        stack_t(any_const_string_tr auto&& string)                                                      = delete;

        stack_t(const stack_t& other);
        stack_t(const volatile stack_t& other);
        stack_t(stack_t&& other) noexcept;
        stack_t(volatile stack_t&& other) noexcept;

        stack_t&            operator =(const stack_t& other);
        volatile stack_t&   operator =(const stack_t& other) volatile;
        stack_t&            operator =(const volatile stack_t& other);
        volatile stack_t&   operator =(const volatile stack_t& other) volatile;
        stack_t&            operator =(stack_t&& other) noexcept;
        volatile stack_t&   operator =(stack_t&& other) volatile noexcept;
        stack_t&            operator =(is_just_volatile_tr<stack_t> auto&& other) noexcept;
        volatile stack_t&   operator =(is_just_volatile_tr<stack_t> auto&& other) volatile noexcept;

        ~stack_t();

    public:
        bool_t                              Has_Terminus() const;
        bool_t                              Has_Terminus() const volatile;

        maybe_t<allocator_err>              Unit_Capacity(count_t unit_capacity_including_terminus);
        maybe_t<allocator_err>              Unit_Capacity(count_t unit_capacity_including_terminus) volatile;

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

        string_itr<const stack_t>           At(index_t point_index) const;
        string_itr<const volatile stack_t>  At(index_t point_index) const volatile;
        string_itr<const stack_t>           At_Prefix() const;
        string_itr<const volatile stack_t>  At_Prefix() const volatile;
        string_itr<const stack_t>           At_First() const;
        string_itr<const volatile stack_t>  At_First() const volatile;
        string_itr<const stack_t>           At_Last() const;
        string_itr<const volatile stack_t>  At_Last() const volatile;
        string_itr<const stack_t>           At_Terminus() const;
        string_itr<const volatile stack_t>  At_Terminus() const volatile;
        string_itr<const stack_t>           At_Postfix() const;
        string_itr<const volatile stack_t>  At_Postfix() const volatile;

        maybe_t<allocator_err>              Push(point_t point);
        maybe_t<allocator_err>              Push(point_t point) volatile;
        maybe_t<allocator_err>              Push(const charcoder_t& charcoder);
        maybe_t<allocator_err>              Push(const charcoder_t& charcoder) volatile;
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string);
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string) volatile;
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length);
        maybe_t<allocator_err>              Push(const is_any_tr<unit_t> auto* c_string, count_t unit_length) volatile;
        maybe_t<allocator_err>              Push(const any_string_tr auto& string);
        maybe_t<allocator_err>              Push(const any_string_tr auto& string) volatile;
        maybe_t<allocator_err>              Push(any_non_const_string_tr auto&& string);
        maybe_t<allocator_err>              Push(any_non_const_string_tr auto&& string) volatile;

        unit_t&                             Unit(index_t unit_index);
        const unit_t&                       Unit(index_t unit_index) const;
        volatile unit_t&                    Unit(index_t unit_index) volatile;
        const volatile unit_t&              Unit(index_t unit_index) const volatile;
    };
    static_assert(string_i<stack_t<charcoder::utf_8_t>>);
    static_assert(string_i<const stack_t<charcoder::utf_8_t>>);
    static_assert(string_i<volatile stack_t<charcoder::utf_8_t>>);
    static_assert(string_i<const volatile stack_t<charcoder::utf_8_t>>);

}}

namespace nkr {

    template <
        string::any_stack_tr    string_p,
        count_t                 min_point_count_p       = 1,
        count_t                 max_point_count_p       = string_p::Unit_Capacity() / string_p::charcoder_t::Max_Unit_Count()
    > auto  Random(bool_t use_errorneous_units = false);

}
