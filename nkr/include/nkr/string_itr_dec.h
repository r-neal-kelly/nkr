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
#include "nkr/some_t.h"

#include "nkr/charcoder_i.h"

#include "nkr/enumeration/types_t.h"

#include "nkr/string_i.h"

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
        // because we use this type in declarations on the string_p itself.
        static_assert(string_i<string_p>);

    public:
        using string_t      = string_p;
        using charcoder_t   = string_p::charcoder_t;
        using unit_t        = string_p::unit_t;

    private:
        static bool_t           Has_String(const is_any_tr<string_itr> auto& self);
        static const string_t&  String(const is_any_tr<string_itr> auto& self);

        static bool_t           Is_Prefix(const is_any_tr<string_itr> auto& self);
        static bool_t           Is_First(const is_any_tr<string_itr> auto& self);
        static bool_t           Is_Last(const is_any_tr<string_itr> auto& self);
        static bool_t           Is_Terminus(const is_any_tr<string_itr> auto& self);
        static bool_t           Is_Postfix(const is_any_tr<string_itr> auto& self);
        static bool_t           Is_At(const is_any_tr<string_itr> auto& self, index_t point_index);

        static void_t           Prefix(is_any_non_const_tr<string_itr> auto& self);
        static void_t           First(is_any_non_const_tr<string_itr> auto& self);
        static void_t           Last(is_any_non_const_tr<string_itr> auto& self);
        static void_t           Terminus(is_any_non_const_tr<string_itr> auto& self);
        static void_t           Postfix(is_any_non_const_tr<string_itr> auto& self);
        static void_t           At(is_any_non_const_tr<string_itr> auto& self, index_t point_index);

        static bool_t           Next(is_any_non_const_tr<string_itr> auto& self);
        static bool_t           Prior(is_any_non_const_tr<string_itr> auto& self);

        static index_t          Unit_Index(const is_any_tr<string_itr> auto& self);
        static index_t          Point_Index(const is_any_tr<string_itr> auto& self);

        static string::point_t  Point(const is_any_tr<string_itr> auto& self);
        static count_t          Point_Unit_Count(const is_any_tr<string_itr> auto& self);
        static unit_t           Point_Unit(const is_any_tr<string_itr> auto& self, index_t index);

        static auto&            Operator_Plus_Equals(is_any_non_const_tr<string_itr> auto& self, count_t point_count);
        static auto&            Operator_Minus_Equals(is_any_non_const_tr<string_itr> auto& self, count_t point_count);

        static auto&            Operator_Increment_Prefix(is_any_non_const_tr<string_itr> auto& self);
        static auto             Operator_Increment_Postfix(is_any_non_const_tr<string_itr> auto& self);
        static auto&            Operator_Decrement_Prefix(is_any_non_const_tr<string_itr> auto& self);
        static auto             Operator_Decrement_Postfix(is_any_non_const_tr<string_itr> auto& self);

    protected:
        some_t<const string_t*> string;
        index_t                 unit_index;
        index_t                 point_index;
        bool_t                  is_prefix;
        charcoder_t             charcoder;

    public:
        string_itr()                                                                                        = delete;

        string_itr(some_t<const string_t*> string, string::position_e::prefix_tg);
        string_itr(some_t<const string_t*> string, string::position_e::first_tg);
        string_itr(some_t<const string_t*> string, string::position_e::last_tg);
        string_itr(some_t<const string_t*> string, string::position_e::terminus_tg);
        string_itr(some_t<const string_t*> string, string::position_e::postfix_tg);
        string_itr(some_t<const string_t*> string, index_t point_index);

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
        bool_t          Has_String() const;
        bool_t          Has_String() const volatile;
        const string_t& String() const;
        const string_t& String() const volatile;

        bool_t          Is_Prefix() const;
        bool_t          Is_Prefix() const volatile;
        bool_t          Is_First() const;
        bool_t          Is_First() const volatile;
        bool_t          Is_Last() const;
        bool_t          Is_Last() const volatile;
        bool_t          Is_Terminus() const;
        bool_t          Is_Terminus() const volatile;
        bool_t          Is_Postfix() const;
        bool_t          Is_Postfix() const volatile;
        bool_t          Is_At(index_t point_index) const;
        bool_t          Is_At(index_t point_index) const volatile;

        void_t          Prefix();
        void_t          Prefix() volatile;
        void_t          First();
        void_t          First() volatile;
        void_t          Last();
        void_t          Last() volatile;
        void_t          Terminus();
        void_t          Terminus() volatile;
        void_t          Postfix();
        void_t          Postfix() volatile;
        void_t          At(index_t point_index);
        void_t          At(index_t point_index) volatile;

        bool_t          Next();
        bool_t          Next() volatile;
        bool_t          Prior();
        bool_t          Prior() volatile;

        index_t         Unit_Index() const;
        index_t         Unit_Index() const volatile;
        index_t         Point_Index() const;
        index_t         Point_Index() const volatile;

        string::point_t Point() const;
        string::point_t Point() const volatile;
        count_t         Point_Unit_Count() const;
        count_t         Point_Unit_Count() const volatile;
        unit_t          Point_Unit(index_t index) const;
        unit_t          Point_Unit(index_t index) const volatile;

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
