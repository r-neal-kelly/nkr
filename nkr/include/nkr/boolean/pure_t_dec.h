/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_07cfb079_b318_4775_a320_921a833b175e
#define nkr_INCLUDE_GUARD_07cfb079_b318_4775_a320_921a833b175e

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/boolean/deleted_operators_t_dec.h"
#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/interface/randomness/value_i_dec.h"
#include "nkr/tr_dec.h"

/*
    pure_t:
        - to remove the integer-like behavior of an nkr::boolean::cpp_t
*/

namespace nkr { namespace boolean {

    class   pure_t;

    struct  pure_tg { class tag_lb; };

    template <typename type_p>
    concept pure_tr =
        nkr::cpp::is_any_tr<type_p, pure_t>;

}}

namespace nkr { namespace boolean { namespace pure_t$ {

    template <nkr::boolean::pure_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::boolean::pure_tg> type_p>
    class type_i_tag_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_tag_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface {

    template <nkr::boolean::pure_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::boolean::pure_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::boolean::pure_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::boolean::pure_t$::type_i_tag_sp<type_p>;
    };

}}

namespace nkr { namespace boolean {

    class pure_t :
        public deleted_operators_t
    {
    public:
        using value_t   = nkr::boolean::cpp_t;

    private:
        static constexpr auto&  Assign(tr<any_non_const_tg, t<pure_t>> auto& self, const tr<any_tg, t<pure_t>> auto& other) noexcept;
        static constexpr auto&  Assign(tr<any_non_const_tg, t<pure_t>> auto& self, tr<any_non_const_tg, t<pure_t>> auto&& other) noexcept;

    private:
        static constexpr value_t    Value(const tr<any_tg, t<pure_t>> auto& self) noexcept;

    protected:
        value_t value;

    public:
        constexpr pure_t() noexcept;

        constexpr pure_t(tr<to_tg, t<value_t>> auto&& from) noexcept;

        constexpr pure_t(const pure_t& other) noexcept;
                  pure_t(const volatile pure_t& other) noexcept;
        constexpr pure_t(pure_t&& other) noexcept;
                  pure_t(volatile pure_t&& other) noexcept;

        constexpr pure_t&           operator =(const pure_t& other) noexcept;
                  volatile pure_t&  operator =(const pure_t& other) volatile noexcept;
                  pure_t&           operator =(const volatile pure_t& other) noexcept;
                  volatile pure_t&  operator =(const volatile pure_t& other) volatile noexcept;
        constexpr pure_t&           operator =(pure_t&& other) noexcept;
                  volatile pure_t&  operator =(pure_t&& other) volatile noexcept;
                  pure_t&           operator =(tr<just_volatile_tg, t<pure_t>> auto&& other) noexcept;
                  volatile pure_t&  operator =(tr<just_volatile_tg, t<pure_t>> auto&& other) volatile noexcept;

#if defined(nkr_IS_DEBUG)
        constexpr ~pure_t() noexcept;
#endif

    public:
        explicit constexpr operator nkr::boolean::pure_t::value_t() const noexcept;
        explicit           operator nkr::boolean::pure_t::value_t() const volatile noexcept;

    public:
        constexpr value_t   operator ()() const noexcept;
        constexpr value_t   operator ()() const volatile noexcept;
    };

}}

namespace nkr { namespace boolean { namespace pure_t$ {

    template <nkr::boolean::pure_tr type_p>
    class none_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        static constexpr value_t    Value() noexcept;

    public:
        template <typename ...>
        constexpr none_value_i_sp(...) noexcept = delete;
    };

}}}

namespace nkr { namespace interface { namespace none {

    template <nkr::boolean::pure_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::boolean::pure_t$::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace boolean { namespace pure_t$ {

    template <nkr::boolean::pure_tr type_p>
    class randomness_value_i_sp
    {
    public:
        using type_t    = type_p;
        using value_t   = nkr::cpp::just_non_qualified_t<type_t>;

    public:
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(nkr::negatable::real_t probability_for_true = 0.5) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              nkr::negatable::real_t probability_for_true = 0.5) noexcept;

        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(value_t min, value_t max) noexcept;
        template <typename unused_p = nkr::none::type_t>
        static value_t  Value(tr<any_non_const_tg, t<nkr::cpp::generic::randomness::generator_tg>> auto& generator,
                              value_t min, value_t max) noexcept;

    public:
        template <typename ...>
        constexpr randomness_value_i_sp(...) noexcept   = delete;
    };

}}}

namespace nkr { namespace interface { namespace randomness {

    template <nkr::boolean::pure_tr value_p>
    class value_i_sp<value_p>
    {
    public:
        using type_t    = nkr::boolean::pure_t$::randomness_value_i_sp<nkr::cpp::just_non_qualified_t<value_p>>;
    };

}}}

constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator ==(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto&& b) noexcept;

constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto& a, const auto&& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto& b) noexcept;
constexpr nkr::boolean::cpp_t   operator !=(const nkr::tr<nkr::any_tg, nkr::t<nkr::boolean::pure_t>> auto&& a, const auto&& b) noexcept;

#include "nkr/boolean/pure_t_dec_def.h"

#endif
