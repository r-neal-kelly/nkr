/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/none/type_t_dec.h"

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

}}

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual {

    using   unary_t =
        std::mutex;

    struct  unary_tg    {};

    template <typename type_p>
    concept unary_tr =
        nkr::cpp::is_any_tr<type_p, unary_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::concurrency::lock::perpetual::unary_tg>
    {
    public:
        using type_t    = nkr::cpp::concurrency::lock::perpetual::unary_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/concurrency/lock/perpetual/unary_t_dec_def.h"
