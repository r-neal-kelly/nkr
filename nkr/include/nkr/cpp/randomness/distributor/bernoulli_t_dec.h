/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_b2fc4ea0_1c21_4895_9d82_5d2186e18ac2
#define nkr_INCLUDE_GUARD_b2fc4ea0_1c21_4895_9d82_5d2186e18ac2

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace randomness { namespace distributor {

    using   bernoulli_t =
        std::bernoulli_distribution;

    struct  bernoulli_tg    { class tag_lb; };

    template <typename type_p>
    concept bernoulli_tr =
        nkr::cpp::is_any_tr<type_p, bernoulli_t>;

}}}}

namespace nkr { namespace cpp { namespace randomness { namespace distributor { namespace bernoulli_t$ {

    template <nkr::cpp::randomness::distributor::bernoulli_tr type_p>
    class type_i_type_sp
    {
    public:
        using type_t    = type_p;
        using of_t      = typename type_t::result_type;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_General() noexcept;
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any_Specific() noexcept;

    public:
        template <typename ...>
        constexpr type_i_type_sp(...) noexcept  = delete;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::bernoulli_tg> type_p>
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

}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::randomness::distributor::bernoulli_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::bernoulli_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::randomness::distributor::bernoulli_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::randomness::distributor::bernoulli_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/cpp/randomness/distributor/bernoulli_t_dec_def.h"

#endif
