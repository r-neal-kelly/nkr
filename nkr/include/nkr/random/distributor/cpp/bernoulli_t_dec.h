/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace random { namespace distributor { namespace cpp {

    using   bernoulli_t =
        nkr::cpp::random::distributor::bernoulli_t;

    struct  bernoulli_tg    {};

    template <typename type_p>
    concept bernoulli_tr =
        nkr::cpp::random::distributor::bernoulli_tr<type_p>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::random::distributor::cpp::bernoulli_tg>
    {
    public:
        using type_t    = nkr::random::distributor::cpp::bernoulli_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::random::distributor::cpp::bernoulli_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::random::distributor::cpp::bernoulli_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::result_type;
    };

}}

#include "nkr/random/distributor/cpp/bernoulli_t_dec_def.h"
