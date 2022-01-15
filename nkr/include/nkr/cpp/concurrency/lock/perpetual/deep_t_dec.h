/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual {

    using   deep_t =
        std::recursive_mutex;

    struct  deep_tg {};

    template <typename type_p>
    concept deep_tr =
        nkr::cpp::is_any_tr<type_p, deep_t>;

}}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::concurrency::lock::perpetual::deep_tg>
    {
    public:
        using type_t    = nkr::cpp::concurrency::lock::perpetual::deep_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/concurrency/lock/perpetual/deep_t_dec_def.h"
