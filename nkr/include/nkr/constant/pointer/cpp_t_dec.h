/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_6dbf883c_8589_433a_af9f_8901a021f8b6
#define nkr_INCLUDE_GUARD_6dbf883c_8589_433a_af9f_8901a021f8b6

#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/pointer/cpp_t_dec.h"

namespace nkr { namespace constant { namespace pointer {

    template <typename unit_p, unit_p* value_p>
    using cpp_t =
        nkr::constant_t<unit_p*, value_p>;

    template <typename type_p>
    concept cpp_tr =
        nkr::constant_tr<type_p> &&
        nkr::pointer::cpp_tr<typename type_p::value_t>;

    class cpp_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

}}}

namespace nkr { namespace constant { namespace pointer { namespace cpp_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::pointer::cpp_tg> type_p>
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

}}}}

namespace nkr { namespace interface {

    template <nkr::cpp::is_any_tr<nkr::constant::pointer::cpp_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::constant::pointer::cpp_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/constant/pointer/cpp_t_dec_def.h"

#endif
