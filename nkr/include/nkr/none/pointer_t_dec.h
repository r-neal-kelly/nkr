/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/none_tr_dec.h"
#include "nkr/trait/none/any_tr_dec.h"

namespace nkr { namespace none {

    struct  pointer_tg  {};

    template <typename type_p>
    concept pointer_tr =
        cpp::is_any_tr<type_p, pointer_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<none::pointer_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <none::pointer_tr type_p>
    class type_i<type_p> :
        public type_i<none::pointer_tg>
    {
    public:
    };

}}
