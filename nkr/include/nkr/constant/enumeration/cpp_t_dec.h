/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_c44f1dda_e11e_49b2_bdb7_97a31700d64e
#define nkr_INCLUDE_GUARD_c44f1dda_e11e_49b2_bdb7_97a31700d64e

#include "nkr/constant_t_dec.h"
#include "nkr/cpp_dec.h"
#include "nkr/enumeration/cpp_t_dec.h"
#include "nkr/interface/forward_dec.h"

namespace nkr { namespace constant { namespace enumeration {

    template <nkr::enumeration::cpp_tr enumeration_p, enumeration_p value_p>
    using cpp_t =
        nkr::constant_t<enumeration_p, value_p>;

    template <typename type_p>
    concept cpp_tr =
        nkr::constant_tr<type_p> &&
        nkr::enumeration::cpp_tr<typename type_p::value_t>;

    class cpp_tg
    {
    public:
        class   tag_lb      {};
        class   type_lb     {};
        class   identity_lb {};
    };

}}}

namespace nkr { namespace constant { namespace enumeration { namespace cpp_t$ {

    template <nkr::cpp::is_any_tr<nkr::constant::enumeration::cpp_tg> type_p>
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

    template <nkr::cpp::is_any_tr<nkr::constant::enumeration::cpp_tg> type_p>
    class type_i_sp<type_p>
    {
    public:
        using type_t    = nkr::constant::enumeration::cpp_t$::type_i_tag_sp<type_p>;
    };

}}

#include "nkr/constant/enumeration/cpp_t_dec_def.h"

#endif
