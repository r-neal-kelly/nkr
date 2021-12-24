/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

namespace nkr { namespace interface { namespace none {

    using namespace nkr::none;

}}}

namespace nkr { namespace interface { namespace none {

    template <tr0<just_non_qualified_tg> type_p>
    class value_i
    {
    public:
        using type_t    = type_p;

    public:
        static constexpr type_t Value() noexcept;
    };

}}}

#include "nkr/interface/none/value_i_dec_def.h"
