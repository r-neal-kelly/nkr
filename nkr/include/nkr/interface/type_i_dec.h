/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/trait/implementing/constructor/default_tr_dec.h"

namespace nkr { namespace interface { namespace $type_i {

    template <typename type_p>
    concept aliases_i = requires
    {
        typename type_p::type_t;
        typename type_p::of_t;
    };

    template <typename type_p>
    concept static_constexpr_functions_i = requires
    {
        { type_p::template Is_Any<typename type_p::type_t>() }  -> cpp::is_tr<boolean::cpp_t>;
    };

    template <typename type_p>
    concept objects_i =
        !trait::implementing::constructor::default_tr<type_p>;

}}}

namespace nkr { namespace interface {

    template <typename type_p>
    class   type_i;

    struct  type_tg     {};

    template <typename type_p>
    struct  type_ttg    {};

    template <typename type_p>
    concept type_tr =
        cpp::is_any_tr<type_p, type_i<typename type_p::type_t>> &&
        $type_i::aliases_i<type_p> &&
        $type_i::static_constexpr_functions_i<type_p> &&
        $type_i::objects_i<type_p>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::interface::type_tg>
    {
    public:
        using type_t    = nkr::interface::type_tg;
        using of_t      = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;

    public:
        template <typename ...>
        constexpr type_i(...) noexcept  = delete;
    };

    template <nkr::interface::type_tr type_p>
    class type_i<type_p> :
        public type_i<nkr::interface::type_tg>
    {
    public:
        using type_t    = type_p;
        using of_t      = type_t::type_t;
    };

}}

namespace nkr { namespace interface {

    // implement the template_i for this interface
    // pretty sure we will no longer need the Is_Implemented func!

}}

#include "nkr/interface/type_i_dec_def.h"
