/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_intrinsics.h"
#include "nkr/z_maybe_t.h"
#include "nkr/z_some_i.h"
#include "nkr/z_traits.h"

namespace nkr {

    namespace $some_t {};

}

namespace nkr {

    template <some_i any_p>
    class some_t;

    struct                      some_tg     {};
    template <typename> struct  some_ttg    {};

}

namespace nkr { namespace $some_t {

    template <typename type_p>
    concept any_tr =
        is_any_tr<type_p, some_t<typename type_p::value_t>>;

}}

namespace nkr {

    template <>
    class type_traits_i<some_tg>
    {
    public:
        using of_t  = void_t;

    public:
        template <typename other_p>
        static constexpr c_bool_t   Is_Any();
    };

    template <$some_t::any_tr type_p>
    class type_traits_i<type_p> :
        public type_traits_i<some_tg>
    {
    public:
        using of_t  = type_p::value_t;
    };

    template <>
    class template_traits_i<some_ttg>
    {
    public:
        template <typename of_p>
        using type_t    = some_t<of_p>;

    public:
        static constexpr c_bool_t   Is_Implemented();
    };

    template <>
    class template_traits_i<some_t> :
        public template_traits_i<some_ttg>
    {
    public:
    };

}

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _fe4b1321_2470_4544_b8c0_0e93c38e7275
    template <some_i any_p>
    class some_t :
        public maybe_t<any_p>
    {
    public:
        /// @name aliases
        /// @copydoc _68e8ea24_c725_481e_96e2_83379ee8f177
        /// @{
        using value_t   = any_p;    ///< @copydoc _afe969ef_b9ff_4532_a311_5900ca7fba62
        /// @}

    private:
        using base_t    = maybe_t<any_p>;

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        nkr_DEFINE_INHERITANCE_WRAPPER_CTORS_AND_DTOR(some_t, base_t);
        /// @}

    public:
        /// @name none_t interface
        /// @copydoc _a9c2409d_1948_4a2d_a709_73323203c246
        /// @{
        some_t(none_t)                                  = delete;   ///< @copydoc _1d3fb757_fe58_4c5e_ba61_56a3ad52f3c1

        some_t&             operator =(none_t)          = delete;   ///< @copydoc _7e0c8790_9442_454e_aa96_8dd70e9e804e
        volatile some_t&    operator =(none_t) volatile = delete;   ///< @copydoc 
        /// @}
    };

    static_assert(some_i<c_bool_t>);
    static_assert(some_i<word_t>);
    static_assert(some_i<real_t>);
    static_assert(some_i<void_t*>);
    static_assert(some_i<bool_t>);

}

namespace nkr {

    bool_t  operator ==(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto& b);
    bool_t  operator ==(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto&& b);
    bool_t  operator ==(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto& b);
    bool_t  operator ==(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto&& b);

    bool_t  operator !=(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto& b);
    bool_t  operator !=(const tr1<any_tg, some_tg> auto& a, const tr0<any_tg> auto&& b);
    bool_t  operator !=(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto& b);
    bool_t  operator !=(const tr1<any_tg, some_tg> auto&& a, const tr0<any_tg> auto&& b);

}
