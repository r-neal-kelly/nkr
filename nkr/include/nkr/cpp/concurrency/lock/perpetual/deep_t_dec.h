/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_73ef0752_68d4_487a_801b_816c98f7c50e
#define nkr_INCLUDE_GUARD_73ef0752_68d4_487a_801b_816c98f7c50e

#include "nkr/built_in/forward_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual {

    using   deep_t =
        std::recursive_mutex;

    struct  deep_tg { class tag_lb; };

    template <typename type_p>
    concept deep_tr =
        nkr::cpp::is_any_tr<type_p, deep_t>;

}}}}}

namespace nkr { namespace cpp { namespace concurrency { namespace lock { namespace perpetual { namespace deep_t$ {

    template <nkr::cpp::concurrency::lock::perpetual::deep_tr type_p>
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

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::perpetual::deep_tg> type_p>
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

    template <nkr::cpp::concurrency::lock::perpetual::deep_tr type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::lock::perpetual::deep_t$::type_i_type_sp<type_p>;
    };

    template <nkr::cpp::is_any_tr<nkr::cpp::concurrency::lock::perpetual::deep_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::cpp::concurrency::lock::perpetual::deep_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/cpp/concurrency/lock/perpetual/deep_t_dec_def.h"

#endif
