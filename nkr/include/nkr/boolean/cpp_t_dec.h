/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/cpp_dec.h"
#include "nkr/intrinsics_dec.h"

#include "nkr/interface/type_i_dec.h"

namespace nkr { namespace boolean {

    using   cpp_t   = cpp::bool_t;

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
        static constexpr cpp::bool_t    Is_Any();
    };

    template <boolean::cpp_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::cpp_tg>
    {
    public:
    };

}}
