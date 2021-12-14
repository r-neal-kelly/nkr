/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/maybe_t.h"
#include "nkr/none_t.h"
#include "nkr/some_t.h"
#include "nkr/traits.h"

namespace nkr {

    template <typename value_p>
    class optional_t;

    struct                      optional_tg     {};
    template <typename> struct  optional_ttg    {};

}

namespace nkr { namespace $optional_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, optional_t<typename type_p::value_t>>;

}}

namespace nkr {

    template <>
    class type_traits_i<optional_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <$optional_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<optional_tg>
    {
    public:
        using of_t  = type_p::value_t;
    };

    template <>
    class template_traits_i<optional_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = optional_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<optional_t> :
        public template_traits_i<optional_ttg>
    {
    public:
    };

}

namespace nkr {

    template <typename value_p>
    class optional_t
    {
    public:
        optional_t()                                                                                        = delete;

        optional_t(const optional_t& other)                                                                 = delete;
        optional_t(const volatile optional_t& other)                                                        = delete;
        optional_t(optional_t&& other) noexcept                                                             = delete;
        optional_t(volatile optional_t&& other) noexcept                                                    = delete;

        optional_t&             operator =(const optional_t& other)                                         = delete;
        volatile optional_t&    operator =(const optional_t& other) volatile                                = delete;
        optional_t&             operator =(const volatile optional_t& other)                                = delete;
        volatile optional_t&    operator =(const volatile optional_t& other) volatile                       = delete;
        optional_t&             operator =(optional_t&& other) noexcept                                     = delete;
        volatile optional_t&    operator =(optional_t&& other) volatile noexcept                            = delete;
        optional_t&             operator =(is_just_volatile_tr<optional_t> auto&& other) noexcept           = delete;
        volatile optional_t&    operator =(is_just_volatile_tr<optional_t> auto&& other) volatile noexcept  = delete;

        ~optional_t()                                                                                       = delete;
    };

    template <any_type_tr value_p>
    class optional_t<value_p>
    {
    public:
        using value_t   = value_p;

    private:
        static auto&    Assign_Copy(tr1<any_non_const_tg, optional_t> auto& self, const tr1<any_tg, optional_t> auto& other);
        static auto&    Assign_Move(tr1<any_non_const_tg, optional_t> auto& self, tr1<any_non_const_tg, optional_t> auto&& other);

        static bool_t   Has_Value(const tr1<any_tg, optional_t> auto& self);

        static auto&    Value(tr1<any_tg, optional_t> auto& self);
        static void_t   Value(tr1<any_non_const_tg, optional_t> auto& self, const tr1<any_tg, value_t> auto& value);
        static void_t   Value(tr1<any_non_const_tg, optional_t> auto& self, tr1<any_non_const_tg, value_t> auto&& value);
        static void_t   Value(tr1<any_non_const_tg, optional_t> auto& self, const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value);
        static void_t   Value(tr1<any_non_const_tg, optional_t> auto& self, tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value);
        static void_t   Value(tr1<any_non_const_tg, optional_t> auto& self, const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value);
        static void_t   Value(tr1<any_non_const_tg, optional_t> auto& self, tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value);

        static void_t   Clear(const tr1<any_tg, optional_t> auto& self);

        static bool_t   Is_Equal_To(const tr1<any_tg, optional_t> auto& self, const tr0<any_tg> auto& other);

    protected:
        bool_t  has_value;
        value_t value;

    public:
        optional_t();

        optional_t(const tr1<any_tg, value_t> auto& value);
        optional_t(tr1<any_non_const_tg, value_t> auto&& value);
        optional_t(tr1<any_const_tg, value_t> auto&& value)                                             = delete;

        optional_t(const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value);
        optional_t(tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value);
        optional_t(tr2<any_tg, maybe_ttg, of_any_accessed_const_tg, value_t> auto&& maybe_value)        = delete;

        optional_t(const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value);
        optional_t(tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value);
        optional_t(tr2<any_tg, some_ttg, of_any_accessed_const_tg, value_t> auto&& some_value)          = delete;

        optional_t(const optional_t& other);
        optional_t(const volatile optional_t& other);
        optional_t(optional_t&& other) noexcept;
        optional_t(volatile optional_t&& other) noexcept;

        optional_t&             operator =(const optional_t& other);
        volatile optional_t&    operator =(const optional_t& other) volatile;
        optional_t&             operator =(const volatile optional_t& other);
        volatile optional_t&    operator =(const volatile optional_t& other) volatile;
        optional_t&             operator =(optional_t&& other) noexcept;
        volatile optional_t&    operator =(optional_t&& other) volatile noexcept;
        optional_t&             operator =(is_just_volatile_tr<optional_t> auto&& other) noexcept;
        volatile optional_t&    operator =(is_just_volatile_tr<optional_t> auto&& other) volatile noexcept;

        ~optional_t();

    public:
        bool_t                  Has_Value() const;
        bool_t                  Has_Value() const volatile;

        value_t&                Value();
        const value_t&          Value() const;
        volatile value_t&       Value() volatile;
        const volatile value_t& Value() const volatile;
        void_t                  Value(const tr1<any_tg, value_t> auto& value);
        void_t                  Value(const tr1<any_tg, value_t> auto& value) volatile;
        void_t                  Value(tr1<any_non_const_tg, value_t> auto&& value);
        void_t                  Value(tr1<any_non_const_tg, value_t> auto&& value) volatile;
        void_t                  Value(const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value);
        void_t                  Value(const tr2<any_tg, maybe_ttg, of_any_tg, value_t> auto& maybe_value) volatile;
        void_t                  Value(tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value);
        void_t                  Value(tr2<any_tg, maybe_ttg, of_any_accessed_non_const_tg, value_t> auto&& maybe_value) volatile;
        void_t                  Value(const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value);
        void_t                  Value(const tr2<any_tg, some_ttg, of_any_tg, value_t> auto& some_value) volatile;
        void_t                  Value(tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value);
        void_t                  Value(tr2<any_tg, some_ttg, of_any_accessed_non_const_tg, value_t> auto&& some_value) volatile;

        void_t                  Clear();
        void_t                  Clear() volatile;

    public:
        explicit operator   c_bool_t() const;
        explicit operator   c_bool_t() const volatile;

    public:
        bool_t  operator ==(const tr0<any_tg> auto& other) const;
        bool_t  operator ==(const tr0<any_tg> auto& other) const volatile;
        bool_t  operator ==(const tr0<any_tg> auto&& other) const;
        bool_t  operator ==(const tr0<any_tg> auto&& other) const volatile;

        bool_t  operator !=(const tr0<any_tg> auto& other) const;
        bool_t  operator !=(const tr0<any_tg> auto& other) const volatile;
        bool_t  operator !=(const tr0<any_tg> auto&& other) const;
        bool_t  operator !=(const tr0<any_tg> auto&& other) const volatile;

    public:
        optional_t(none_t);

        optional_t&             operator =(none_t);
        volatile optional_t&    operator =(none_t) volatile;

        bool_t                  operator ==(none_t) const;
        bool_t                  operator ==(none_t) const volatile;
        bool_t                  operator !=(none_t) const;
        bool_t                  operator !=(none_t) const volatile;
    };

}
