/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_13f7effa_4f5b_4c3a_8d1d_68b02fa72672
#define nkr_INCLUDE_GUARD_13f7effa_4f5b_4c3a_8d1d_68b02fa72672

#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/interface/forward_dec.h"
#include "nkr/reference/lvalue_t_dec.h"

namespace nkr { namespace constant { namespace reference {

    template <typename type_p, type_p& value_p>
    using lvalue_t =
        nkr::constant_t<type_p&, value_p>;

    template <typename type_p>
    concept lvalue_tr =
        nkr::constant_tr<type_p> &&
        nkr::reference::lvalue_tr<typename type_p::value_t>;

    class lvalue_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

}}}

namespace nkr { namespace constant { namespace reference { namespace lvalue_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::reference::lvalue_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::constant::reference::lvalue_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::constant::reference::lvalue_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/constant/reference/lvalue_t_dec_def.h"

#endif
