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

namespace nkr { namespace cpp { namespace randomness { namespace distributor {

    using   bernoulli_t =
        std::bernoulli_distribution;

    struct  bernoulli_tg    {};

    template <typename type_p>
    concept bernoulli_tr =
        nkr::cpp::is_any_tr<type_p, bernoulli_t>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::cpp::randomness::distributor::bernoulli_tg>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::bernoulli_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::cpp::randomness::distributor::bernoulli_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::cpp::randomness::distributor::bernoulli_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_p::result_type;
    };

}}

#include "nkr/cpp/randomness/distributor/bernoulli_t_dec_def.h"
