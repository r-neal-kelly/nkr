/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"
#include "nkr/tr_dec.h"

#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/boolean_tr_dec.h"
#include "nkr/trait/boolean/impure_tr_dec.h"

namespace nkr { namespace boolean {

    class   cpp_t;

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        cpp::is_any_tr<type_p, cpp_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<boolean::cpp_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr cpp::bool_t    Is_Any();
    };

    template <boolean::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::cpp_tg>
    {
    public:
    };

}}

namespace nkr { namespace boolean {

    class cpp_t
    {
    public:
        using value_t   = cpp::bool_t;

    public:
        static constexpr cpp_t  Is_Boolean_Type();

    private:
        static constexpr auto&  Assign_Copy(tr1<any_non_const_tg, cpp_t> auto& self, const tr1<any_tg, cpp_t> auto& other);
        static constexpr auto&  Assign_Move(tr1<any_non_const_tg, cpp_t> auto& self, tr1<any_non_const_tg, cpp_t> auto&& other);

        static constexpr auto&  Value(tr1<any_tg, cpp_t> auto& self);

    protected:
        value_t value;

    public:
        constexpr cpp_t();

        constexpr cpp_t(value_t value);

        constexpr cpp_t(const cpp_t& other);
        constexpr cpp_t(const volatile cpp_t& other);
        constexpr cpp_t(cpp_t&& other) noexcept;
        constexpr cpp_t(volatile cpp_t&& other) noexcept;

        constexpr cpp_t&            operator =(const cpp_t& other);
        constexpr volatile cpp_t&   operator =(const cpp_t& other) volatile;
        constexpr cpp_t&            operator =(const volatile cpp_t& other);
        constexpr volatile cpp_t&   operator =(const volatile cpp_t& other) volatile;
        constexpr cpp_t&            operator =(cpp_t&& other) noexcept;
        constexpr volatile cpp_t&   operator =(cpp_t&& other) volatile noexcept;
        constexpr cpp_t&            operator =(tr1<just_volatile_tg, cpp_t> auto&& other) noexcept;
        constexpr volatile cpp_t&   operator =(tr1<just_volatile_tg, cpp_t> auto&& other) volatile noexcept;

        constexpr ~cpp_t();

    public:
        constexpr operator  value_t&();
        constexpr operator  const value_t&() const;
        constexpr operator  volatile value_t&() volatile;
        constexpr operator  const volatile value_t&() const volatile;

    public:
        constexpr value_t&                  operator ()();
        constexpr const value_t&            operator ()() const;
        constexpr volatile value_t&         operator ()() volatile;
        constexpr const volatile value_t&   operator ()() const volatile;
    };

}}
