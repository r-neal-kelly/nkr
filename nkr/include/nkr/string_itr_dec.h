/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/macros.h"
#include "nkr/maybe_t.h"
#include "nkr/none_i.h"
#include "nkr/none_t.h"
#include "nkr/optional_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

#include "nkr/charcoder_i.h"

#include "nkr/enumeration/types_t.h"

#include "nkr/string_i.h"
#include "nkr/string/stack_t_dec.h"

namespace nkr { namespace string {

    class position_e :
        public enumeration::types_t<signed_word_t>
    {
    public:
        using base_t    = enumeration::types_t<signed_word_t>;

    public:
        struct none_tg      {};

        struct prefix_tg    {};
        struct first_tg     {};
        struct last_tg      {};
        struct terminus_tg  {};
        struct postfix_tg   {};

    public:
        enum : value_t
        {
            NONE = base_t::NONE,

            PREFIX,
            FIRST,
            LAST,
            TERMINUS,
            POSTFIX,
        };

    public:
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(position_e, base_t);
        nkr_DEFINE_ENUMERATION_TYPES_BOOL_AND_NOT_AND_NONE(this->value >= PREFIX && this->value <= POSTFIX);
    };

}}

namespace nkr {

    template <typename string_p>
    class string_itr
    {
    private:
        // annoyingly, we can't use this in the type constraint directly
        // because we use this type in declarations on the string_p, and
        // that causes a recursive compiler error.
        static_assert(string_i<string_p>);

    public:
        using string_t      = string_p;
        using charcoder_t   = string_p::charcoder_t;
        using unit_t        = string_p::unit_t;
        using substring_t   = string::stack_t<charcoder_t, charcoder_t::Max_Unit_Count() + 1>;

    private:
        static bool_t               Has_String(const is_any_tr<string_itr> auto& self);
        static const string_t&      String(const is_any_tr<string_itr> auto& self);

        static bool_t               Is_At(const is_any_tr<string_itr> auto& self, index_t point_index);
        static bool_t               Is_At_Prefix(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_First(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_Last(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_Terminus(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_Postfix(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_Error(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_Replacement_Point(const is_any_tr<string_itr> auto& self);
        static bool_t               Is_At_Replacement_Substring(const is_any_tr<string_itr> auto& self);

        static void_t               At(is_any_non_const_tr<string_itr> auto& self, index_t point_index);
        static void_t               At_Prefix(is_any_non_const_tr<string_itr> auto& self);
        static void_t               At_First(is_any_non_const_tr<string_itr> auto& self);
        static void_t               At_Last(is_any_non_const_tr<string_itr> auto& self);
        static void_t               At_Terminus(is_any_non_const_tr<string_itr> auto& self);
        static void_t               At_Postfix(is_any_non_const_tr<string_itr> auto& self);

        static bool_t               Next(is_any_non_const_tr<string_itr> auto& self);
        static bool_t               Prior(is_any_non_const_tr<string_itr> auto& self);

        static optional_t<index_t>  Unit_Index(const is_any_tr<string_itr> auto& self);
        static optional_t<index_t>  Point_Index(const is_any_tr<string_itr> auto& self);

        static auto&                Charcoder(const is_any_tr<string_itr> auto& self);

        static string::point_t      Point(const is_any_tr<string_itr> auto& self);
        static count_t              Point_Unit_Count(const is_any_tr<string_itr> auto& self);
        static unit_t               Point_Unit(const is_any_tr<string_itr> auto& self, index_t point_unit_index);

        static substring_t          Substring(const is_any_tr<string_itr> auto& self);
        static count_t              Substring_Unit_Length(const is_any_tr<string_itr> auto& self);
        static unit_t               Substring_Unit(const is_any_tr<string_itr> auto& self, index_t substring_unit_index);

        static auto&                Operator_Plus_Equals(is_any_non_const_tr<string_itr> auto& self, count_t point_count);
        static auto&                Operator_Minus_Equals(is_any_non_const_tr<string_itr> auto& self, count_t point_count);

        static auto&                Operator_Increment_Prefix(is_any_non_const_tr<string_itr> auto& self);
        static auto                 Operator_Increment_Postfix(is_any_non_const_tr<string_itr> auto& self);
        static auto&                Operator_Decrement_Prefix(is_any_non_const_tr<string_itr> auto& self);
        static auto                 Operator_Decrement_Postfix(is_any_non_const_tr<string_itr> auto& self);

    protected:
        some_t<const string_t*> string;
        bool_t                  is_prefix;
        index_t                 unit_index;
        index_t                 point_index;
        count_t                 read_unit_count;
        charcoder_t             charcoder;

    public:
        string_itr()                                                                                        = delete;

        string_itr(const string_t& string);
        string_itr(const string_t& string, index_t point_index);
        string_itr(const string_t& string, string::position_e::prefix_tg);
        string_itr(const string_t& string, string::position_e::first_tg);
        string_itr(const string_t& string, string::position_e::last_tg);
        string_itr(const string_t& string, string::position_e::terminus_tg);
        string_itr(const string_t& string, string::position_e::postfix_tg);

        string_itr(const string_itr& other);
        string_itr(const volatile string_itr& other);
        string_itr(string_itr&& other) noexcept;
        string_itr(volatile string_itr&& other) noexcept;

        string_itr&             operator =(const string_itr& other);
        volatile string_itr&    operator =(const string_itr& other) volatile;
        string_itr&             operator =(const volatile string_itr& other);
        volatile string_itr&    operator =(const volatile string_itr& other) volatile;
        string_itr&             operator =(string_itr&& other) noexcept;
        volatile string_itr&    operator =(string_itr&& other) volatile noexcept;
        string_itr&             operator =(is_just_volatile_tr<string_itr> auto&& other) noexcept;
        volatile string_itr&    operator =(is_just_volatile_tr<string_itr> auto&& other) volatile noexcept;

        ~string_itr();

    public:
        const string_t&             String() const;
        const string_t&             String() const volatile;

        bool_t                      Is_At(index_t point_index) const;
        bool_t                      Is_At(index_t point_index) const volatile;
        bool_t                      Is_At_Prefix() const;
        bool_t                      Is_At_Prefix() const volatile;
        bool_t                      Is_At_First() const;
        bool_t                      Is_At_First() const volatile;
        bool_t                      Is_At_Last() const;
        bool_t                      Is_At_Last() const volatile;
        bool_t                      Is_At_Terminus() const;
        bool_t                      Is_At_Terminus() const volatile;
        bool_t                      Is_At_Postfix() const;
        bool_t                      Is_At_Postfix() const volatile;
        bool_t                      Is_At_Error() const;
        bool_t                      Is_At_Error() const volatile;
        bool_t                      Is_At_Replacement_Point() const;
        bool_t                      Is_At_Replacement_Point() const volatile;
        bool_t                      Is_At_Replacement_Substring() const;
        bool_t                      Is_At_Replacement_Substring() const volatile;

        void_t                      At(index_t point_index);
        void_t                      At(index_t point_index) volatile;
        void_t                      At_Prefix();
        void_t                      At_Prefix() volatile;
        void_t                      At_First();
        void_t                      At_First() volatile;
        void_t                      At_Last();
        void_t                      At_Last() volatile;
        void_t                      At_Terminus();
        void_t                      At_Terminus() volatile;
        void_t                      At_Postfix();
        void_t                      At_Postfix() volatile;

        bool_t                      Next();
        bool_t                      Next() volatile;
        bool_t                      Prior();
        bool_t                      Prior() volatile;

        optional_t<index_t>         Unit_Index() const;
        optional_t<index_t>         Unit_Index() const volatile;
        optional_t<index_t>         Point_Index() const;
        optional_t<index_t>         Point_Index() const volatile;

        const charcoder_t&          Charcoder() const;
        const volatile charcoder_t& Charcoder() const volatile;

        string::point_t             Point() const;
        string::point_t             Point() const volatile;
        count_t                     Point_Unit_Count() const;
        count_t                     Point_Unit_Count() const volatile;
        unit_t                      Point_Unit(index_t point_unit_index) const;
        unit_t                      Point_Unit(index_t point_unit_index) const volatile;

        substring_t                 Substring() const;
        substring_t                 Substring() const volatile;
        count_t                     Substring_Unit_Length() const;
        count_t                     Substring_Unit_Length() const volatile;
        unit_t                      Substring_Unit(index_t substring_unit_index) const;
        unit_t                      Substring_Unit(index_t substring_unit_index) const volatile;

    public:
        string_itr&             operator +=(count_t point_count);
        volatile string_itr&    operator +=(count_t point_count) volatile;
        string_itr&             operator -=(count_t point_count);
        volatile string_itr&    operator -=(count_t point_count) volatile;

        string_itr&             operator ++();
        volatile string_itr&    operator ++() volatile;
        string_itr              operator ++(int);
        volatile string_itr     operator ++(int) volatile;
        string_itr&             operator --();
        volatile string_itr&    operator --() volatile;
        string_itr              operator --(int);
        volatile string_itr     operator --(int) volatile;
    };

}
