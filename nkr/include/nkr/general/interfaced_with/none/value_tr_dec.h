/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/built_ins_dec.h"

#include "nkr/interface/none/value_i_dec.h"

namespace nkr { namespace general { namespace interfaced_with { namespace none {

    struct  value_tg    {};

    template <typename>
    struct  value_ttg   {};

    template <typename type_p>
    concept value_tr =
        nkr::interface::none::value_tr<nkr::interface::none::value_i<type_p>>;

}}}}

namespace nkr { namespace interface {

    template <>
    class type_i<nkr::general::interfaced_with::none::value_tg>
    {
    public:
        using of_t  = nkr::none::type_t;

    public:
        template <typename other_p>
        static constexpr nkr::boolean::cpp_t    Is_Any() noexcept;
    };

    template <>
    class template_i<nkr::general::interfaced_with::none::value_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = nkr::general::interfaced_with::none::value_tg;

    public:
        static constexpr nkr::boolean::cpp_t    Is_Implemented() noexcept;
    };

}}

#include "nkr/general/interfaced_with/none/value_tr_dec_def.h"
