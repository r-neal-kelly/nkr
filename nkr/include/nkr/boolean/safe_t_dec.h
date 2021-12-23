/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/tr_dec.h"

#include "nkr/boolean/cpp_t_dec.h"
#include "nkr/boolean/deleted_operators_t_dec.h"

#include "nkr/trait/boolean_tr_dec.h"
#include "nkr/trait/boolean/any_tr_dec.h"
#include "nkr/trait/boolean/pure_tr_dec.h"

namespace nkr { namespace boolean {

    class   safe_t;

    struct  safe_tg {};

    template <typename type_p>
    concept safe_tr =
        cpp::is_any_tr<type_p, safe_t>;

}}

namespace nkr { namespace interface {

    template <>
    class type_i<boolean::safe_tg>
    {
    public:
        using of_t  = none::type_t;

    public:
        template <typename other_p>
        static constexpr boolean::cpp_t Is_Any() noexcept;
    };

    template <boolean::safe_tr type_p>
    class type_i<type_p> :
        public type_i<boolean::safe_tg>
    {
    public:
    };

}}

namespace nkr { namespace boolean {

    /// @nosubgrouping
    /// @copydoc _2add9928_e370_4943_ba5b_2950d9e1da99
    class safe_t :
        public deleted_operators_t
    {
    public:
        static constexpr boolean::cpp_t Is_Boolean_Type() noexcept;

    private:
        static constexpr auto&  Assign_Copy(tr1<any_non_const_tg, safe_t> auto& self, const tr1<any_tg, safe_t> auto& other) noexcept;
        static constexpr auto&  Assign_Move(tr1<any_non_const_tg, safe_t> auto& self, tr1<any_non_const_tg, safe_t> auto&& other) noexcept;

    protected:
        /// @name object data
        /// @copydoc 
        /// @{
        boolean::cpp_t  value;  ///< @copydoc 
        /// @}

    public:
        /// @name objects
        /// @copydoc 
        /// @{
        constexpr safe_t() noexcept;                                                                            ///< @copydoc 

        constexpr safe_t(const tr1<any_to_tg, boolean::cpp_t> auto& value) noexcept;                            ///< @copydoc 

        constexpr safe_t(const safe_t& other) noexcept;                                                         ///< @copydoc 
        constexpr safe_t(const volatile safe_t& other) noexcept;                                                ///< @copydoc 
        constexpr safe_t(safe_t&& other) noexcept;                                                              ///< @copydoc 
        constexpr safe_t(volatile safe_t&& other) noexcept;                                                     ///< @copydoc 

        constexpr safe_t&           operator =(const safe_t& other) noexcept;                                   ///< @copydoc 
        constexpr volatile safe_t&  operator =(const safe_t& other) volatile noexcept;                          ///< @copydoc 
        constexpr safe_t&           operator =(const volatile safe_t& other) noexcept;                          ///< @copydoc 
        constexpr volatile safe_t&  operator =(const volatile safe_t& other) volatile noexcept;                 ///< @copydoc 
        constexpr safe_t&           operator =(safe_t&& other) noexcept;                                        ///< @copydoc 
        constexpr volatile safe_t&  operator =(safe_t&& other) volatile noexcept;                               ///< @copydoc 
        constexpr safe_t&           operator =(tr1<just_volatile_tg, safe_t> auto&& other) noexcept;            ///< @copydoc 
        constexpr volatile safe_t&  operator =(tr1<just_volatile_tg, safe_t> auto&& other) volatile noexcept;   ///< @copydoc 

#if defined(nkr_IS_DEBUG)
        constexpr ~safe_t() noexcept;                                                                           ///< @copydoc 
#endif
        /// @}

    public:
        /// @name casts
        /// @copydoc 
        /// @{
        explicit constexpr operator boolean::cpp_t() const noexcept;            ///< @copydoc 
        explicit constexpr operator boolean::cpp_t() const volatile noexcept;   ///< @copydoc 
        /// @}
    };

}}

namespace nkr {

    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto&& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator ==(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto&& b) noexcept;

    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto& a, const tr0<any_tg> auto&& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto& b) noexcept;
    constexpr boolean::cpp_t    operator !=(const tr1<any_tg, boolean::safe_t> auto&& a, const tr0<any_tg> auto&& b) noexcept;

}
