/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/interface/randomness/distributor/uniform_i_dec.h"

namespace nkr { namespace interface {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i<nkr::interface::randomness::distributor::uniform_tg>::Is_Any()
        noexcept
    {
        return nkr::interface::randomness::distributor::uniform_tr<other_p>;
    }

}}

namespace nkr { namespace interface {

    template <template <typename ...> typename other_p>
    inline constexpr nkr::boolean::cpp_t
        template_i<nkr::interface::randomness::distributor::uniform_ttg>::Is_Any()
        noexcept
    {
        return nkr::interface::randomness::distributor::uniform_ttr<other_p>;
    }

}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::boolean_tr type_p>
    inline constexpr boolean_sp<type_p>::type_t
        boolean_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<type_t>();
    }

    template <nkr::generic::built_in::boolean_tr type_p>
    inline constexpr boolean_sp<type_p>::type_t
        boolean_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<type_t>();
    }

    template <nkr::generic::built_in::boolean_tr type_p>
    inline constexpr boolean_sp<type_p>::number_t
        boolean_sp<type_p>::To_Number(type_t object)
        noexcept
    {
        return static_cast<number_t>(object);
    }

    template <nkr::generic::built_in::boolean_tr type_p>
    inline constexpr boolean_sp<type_p>::type_t
        boolean_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return static_cast<type_t>(number);
    }

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr enumeration_limited_sp<type_p>::type_t
        enumeration_limited_sp<type_p>::Default_Min()
        noexcept
    {
        return type_t::MIN_tg;
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr enumeration_limited_sp<type_p>::type_t
        enumeration_limited_sp<type_p>::Default_Max()
        noexcept
    {
        return type_t::MAX_tg;
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr enumeration_limited_sp<type_p>::number_t
        enumeration_limited_sp<type_p>::To_Number(type_t object)
        noexcept
    {
        return static_cast<number_t>(object);
    }

    template <nkr::generic::built_in::number::enumeration::limited_tr type_p>
    inline constexpr enumeration_limited_sp<type_p>::type_t
        enumeration_limited_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return static_cast<type_t>(number);
    }

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::number::integer_tr type_p>
    inline constexpr integer_sp<type_p>::type_t
        integer_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<type_t>();
    }

    template <nkr::generic::built_in::number::integer_tr type_p>
    inline constexpr integer_sp<type_p>::type_t
        integer_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<type_t>();
    }

    template <nkr::generic::built_in::number::integer_tr type_p>
    inline constexpr integer_sp<type_p>::number_t
        integer_sp<type_p>::To_Number(type_t object)
        noexcept
    {
        return object;
    }

    template <nkr::generic::built_in::number::integer_tr type_p>
    inline constexpr integer_sp<type_p>::type_t
        integer_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return number;
    }

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::number::real_tr type_p>
    inline constexpr real_sp<type_p>::type_t
        real_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<type_t>();
    }

    template <nkr::generic::built_in::number::real_tr type_p>
    inline constexpr real_sp<type_p>::type_t
        real_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<type_t>();
    }

    template <nkr::generic::built_in::number::real_tr type_p>
    inline constexpr real_sp<type_p>::number_t
        real_sp<type_p>::To_Number(type_t object)
        noexcept
    {
        return object;
    }

    template <nkr::generic::built_in::number::real_tr type_p>
    inline constexpr real_sp<type_p>::type_t
        real_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return number;
    }

}}}}}

namespace nkr { namespace interface { namespace randomness { namespace distributor { namespace $uniform_i {

    template <nkr::generic::built_in::pointer_tr type_p>
    inline constexpr pointer_sp<type_p>::type_t
        pointer_sp<type_p>::Default_Min()
        noexcept
    {
        return nkr::cpp::Default_Min<type_t>();
    }

    template <nkr::generic::built_in::pointer_tr type_p>
    inline constexpr pointer_sp<type_p>::type_t
        pointer_sp<type_p>::Default_Max()
        noexcept
    {
        return nkr::cpp::Default_Max<type_t>();
    }

    template <nkr::generic::built_in::pointer_tr type_p>
    inline constexpr pointer_sp<type_p>::number_t
        pointer_sp<type_p>::To_Number(type_t object)
        noexcept
    {
        static_assert(sizeof(type_t) == sizeof(number_t));

        return *reinterpret_cast<number_t*>(&object);
    }

    template <nkr::generic::built_in::pointer_tr type_p>
    inline constexpr pointer_sp<type_p>::type_t
        pointer_sp<type_p>::From_Number(number_t number)
        noexcept
    {
        return *reinterpret_cast<type_t*>(&number);
    }

}}}}}
