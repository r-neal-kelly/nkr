/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_d00ae44f_17d2_4946_8a64_344b6b9abe57
#define nkr_INCLUDE_GUARD_d00ae44f_17d2_4946_8a64_344b6b9abe57

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace temporal {

    using   unary_t =
        std::timed_mutex;

    struct  unary_tg    { class tag_lb; };

    template <typename type_p>
    concept unary_tr =
        nkr::cpp::is_any_tr<type_p, unary_t>;

}}}}}

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace temporal { namespace unary_t$ {

    template <nkr::cpp::concurrency::lock::temporal::unary_tr type_p>
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

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::temporal::unary_tg> type_p>
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

}}}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::concurrency::lock::temporal::unary_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::lock::temporal::unary_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::temporal::unary_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::lock::temporal::unary_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/cpp/concurrency/lock/temporal/unary_t_dec_def.h"

#endif
