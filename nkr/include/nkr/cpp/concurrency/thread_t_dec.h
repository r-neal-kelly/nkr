/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace concurrency {

    using   thread_t =
        std::jthread;

    struct  thread_tg   {};

    template <typename type_p>
    concept thread_tr =
        nkr::cpp::is_any_tr<type_p, thread_t>;

}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::concurrency::thread_tg>
    {
    public:
        using type_t    = nkr::cpp::concurrency::thread_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

}}

#include "nkr/cpp/concurrency/thread_t_dec_def.h"
