/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/cpp/generic/randomness/generator_tr_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/tr_dec.h"

namespace nkr { namespace boolean {

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        nkr::cpp::is_any_tr<type_p, cpp_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::boolean::cpp_tg>
    {
    public:
        using type_t    = nkr::boolean::cpp_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::boolean::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::boolean::cpp_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = nkr::none::type_t;
    };

}}

namespace nkr { namespace boolean { namespace $cpp_t {

    template <nkr::boolean::cpp_tr type_p>
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

    template <nkr::boolean::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::boolean::$cpp_t::none_value_i_sp<type_p>;
    };

}}}

namespace nkr { namespace boolean { namespace $cpp_t {

    template <nkr::boolean::cpp_tr type_p>
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

    template <nkr::boolean::cpp_tr type_p>
    class value_i_sp<type_p>
    {
    public:
        using type_t    = nkr::boolean::$cpp_t::randomness_value_i_sp<type_p>;
    };

}}}

#include "nkr/boolean/cpp_t_dec_def.h"
