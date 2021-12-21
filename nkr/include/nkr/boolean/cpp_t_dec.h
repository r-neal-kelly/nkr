/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/interface/template_i_dec.h"
#include "nkr/interface/type_i_dec.h"

#include "nkr/trait/boolean_tr_dec.h"
#include "nkr/trait/boolean/any_tr_dec.h"
#include "nkr/trait/boolean/impure_tr_dec.h"

namespace nkr { namespace boolean {

    struct  cpp_tg  {};

    template <typename type_p>
    concept cpp_tr =
        cpp::is_any_tr<type_p, cpp_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<boolean::cpp_tg>
    {
    public:
        using of_t  = cpp::void_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <boolean::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::cpp_tg>
    {
    public:
    };

}}
