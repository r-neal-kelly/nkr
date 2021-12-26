/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/boolean/deleted_operators_t_dec.h"

#include "nkr/generic/boolean_tr_dec.h"
#include "nkr/generic/boolean/any_tr_dec.h"
#include "nkr/generic/boolean/pure_tr_dec.h"

namespace nkr { namespace boolean {

    class   safe_t;

    struct  safe_tg {};

    template <typename type_p>
    concept safe_tr =
        cpp::is_any_tr<type_p, safe_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<boolean::safe_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <boolean::safe_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::safe_tg>
    {
    public:
    };

}}

namespace nkr { namespace boolean {

    class safe_t :
        public deleted_operators_t
    {
    public:
        static constexpr boolean::cpp_t Is_Boolean_Type() noexcept;

    private:
        static constexpr auto&  Assign_Copy(tr1<any_non_const_tg, safe_t> auto& self, const tr1<any_tg, safe_t> auto& other) noexcept;
        static constexpr auto&  Assign_Move(tr1<any_non_const_tg, safe_t> auto& self, tr1<any_non_const_tg, safe_t> auto&& other) noexcept;

    protected:
        boolean::cpp_t  value;

    public:
        constexpr safe_t() noexcept;

        constexpr safe_t(const tr1<any_to_tg, boolean::cpp_t> auto& value) noexcept;

        constexpr safe_t(const safe_t& other) noexcept;
        constexpr safe_t(const volatile safe_t& other) noexcept;
        constexpr safe_t(safe_t&& other) noexcept;
        constexpr safe_t(volatile safe_t&& other) noexcept;

        constexpr safe_t&           operator =(const safe_t& other) noexcept;
        constexpr volatile safe_t&  operator =(const safe_t& other) volatile noexcept;
        constexpr safe_t&           operator =(const volatile safe_t& other) noexcept;
        constexpr volatile safe_t&  operator =(const volatile safe_t& other) volatile noexcept;
        constexpr safe_t&           operator =(safe_t&& other) noexcept;
        constexpr volatile safe_t&  operator =(safe_t&& other) volatile noexcept;
        constexpr safe_t&           operator =(tr1<just_volatile_tg, safe_t> auto&& other) noexcept;
        constexpr volatile safe_t&  operator =(tr1<just_volatile_tg, safe_t> auto&& other) volatile noexcept;

#if defined(nkr_IS_DEBUG)
        constexpr ~safe_t() noexcept;
#endif

    public:
        explicit constexpr operator boolean::cpp_t() const noexcept;
        explicit constexpr operator boolean::cpp_t() const volatile noexcept;
    };

}}

namespace nkr {

    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto&& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto&& b) noexcept;

    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto&& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto&& b) noexcept;

}

#include "nkr/boolean/safe_t_dec_def.h"

namespace nkr { namespace boolean {

    static_assert(sizeof(safe_t) == sizeof(cpp_t));

    static_assert(generic::boolean_tr<safe_t>);
    static_assert(generic::boolean_tr<const safe_t>);
    static_assert(generic::boolean_tr<volatile safe_t>);
    static_assert(generic::boolean_tr<const volatile safe_t>);

    static_assert(generic::boolean::any_tr<safe_t>);
    static_assert(generic::boolean::any_tr<const safe_t>);
    static_assert(generic::boolean::any_tr<volatile safe_t>);
    static_assert(generic::boolean::any_tr<const volatile safe_t>);

    static_assert(generic::boolean::pure_tr<safe_t>);
    static_assert(generic::boolean::pure_tr<const safe_t>);
    static_assert(generic::boolean::pure_tr<volatile safe_t>);
    static_assert(generic::boolean::pure_tr<const volatile safe_t>);

}}
