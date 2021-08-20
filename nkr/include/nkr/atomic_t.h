/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/intrinsics.h"
#include "nkr/traits.h"

namespace nkr {

    /// @nosubgrouping
    /// @copydoc _1eb34513_6d58_4671_bcfc_61834a0fa529
    template <typename integer_p = word_t>
    class atomic_t
    {
    public:
        static_assert(integer_tr<integer_p>, "invalid atomic value_t.");

    public:
        /// @name aliases
        /// @copydoc _3e2133e0_58a8_4588_befa_ae433363cf01
        /// @{
        using value_t   = integer_p;
        /// @}

    public:
        /// @name data
        /// @copydoc _67c3c408_1756_4f1e_a966_cc5ad1f3dfd2
        /// @{
        volatile value_t    value;  ///< @copydoc _93d24339_6dae_40f2_9f11_c9305ebb3816
        /// @}

    public:
        /// @name objects
        /// @copydoc _162f5a89_c587_40d2_ac4c_9b43659dfa9a
        /// @{
        atomic_t();
        atomic_t(value_t value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();
        /// @}

    public:
        /// @name methods
        /// @copydoc _ebe2958b_6231_481e_819f_84d882989f41
        /// @{
        value_t Access() const;
        value_t Access_Add(integer_tr auto value) const;
        value_t Access_Subtract(integer_tr auto value) const;
        value_t Access_Or(integer_tr auto value) const;
        value_t Access_And(integer_tr auto value) const;
        value_t Access_Xor(integer_tr auto value) const;

        value_t Assign(integer_tr auto value);
        value_t Assign_Add(integer_tr auto value);
        value_t Assign_Subtract(integer_tr auto value);
        value_t Assign_Or(integer_tr auto value);
        value_t Assign_And(integer_tr auto value);
        value_t Assign_Xor(integer_tr auto value);

        value_t Exchange(integer_tr auto value);
        value_t Exchange_If_Equals(integer_tr auto value, integer_tr auto target);
        value_t Exchange_Add(integer_tr auto value);
        value_t Exchange_Subtract(integer_tr auto value);
        value_t Exchange_Or(integer_tr auto value);
        value_t Exchange_And(integer_tr auto value);
        value_t Exchange_Xor(integer_tr auto value);
        /// @}

    public:
        /// @name casts
        /// @copydoc _473fc73c_71f3_4897_b548_32326ec7f8ca
        /// @{
        operator    value_t() const;
        /// @}

    public:
        /// @name operators
        /// @copydoc _ebf639ee_013e_4e27_adc1_1752df597ddf
        /// @{
        value_t operator ()() const;

        value_t operator =(integer_tr auto value);

        value_t operator +(integer_tr auto value) const;
        value_t operator -(integer_tr auto value) const;
        value_t operator +=(integer_tr auto value);
        value_t operator -=(integer_tr auto value);
        value_t operator ++();
        value_t operator ++(int);
        value_t operator --();
        value_t operator --(int);

        value_t operator ~() const;
        value_t operator |(integer_tr auto value) const;
        value_t operator &(integer_tr auto value) const;
        value_t operator ^(integer_tr auto value) const;
        value_t operator |=(integer_tr auto value);
        value_t operator &=(integer_tr auto value);
        value_t operator ^=(integer_tr auto value);
        /// @}
    };

    /// @nosubgrouping
    /// @copydoc _ec77c539_2ae5_4aa5_a156_d961c5ac098d
    template <>
    class atomic_t<bool_t>
    {
    public:
        using value_t   = bool_t;

    public:
        volatile value_t    value;  ///< @copydoc _93d24339_6dae_40f2_9f11_c9305ebb3816

    public:
        atomic_t();
        atomic_t(value_t value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t Access() const;

        value_t Assign(value_t value);

        value_t Exchange(value_t value);
        value_t Exchange_If_Equals(value_t value, value_t target);

    public:
        operator    value_t() const;

    public:
        value_t operator ()() const;

        value_t operator =(value_t value);
    };

    /// @nosubgrouping
    /// @copydoc _3a98b216_8b25_4340_96d3_01a5f49f336b
    template <typename any_p>
    class atomic_t<any_p*>
    {
    public:
        using value_t   = any_p;

    public:
        value_t* volatile   value;  ///< @copydoc _93d24339_6dae_40f2_9f11_c9305ebb3816

    public:
        atomic_t();
        atomic_t(value_t* value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t*    Access() const;
        value_t*    Access_Add(integer_tr auto value) const;
        value_t*    Access_Subtract(integer_tr auto value) const;

        value_t*    Assign(pointer_tr auto value);
        value_t*    Assign_Add(integer_tr auto value);
        value_t*    Assign_Subtract(integer_tr auto value);

        value_t*    Exchange(pointer_tr auto value);
        value_t*    Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target);
        value_t*    Exchange_Add(integer_tr auto value);
        value_t*    Exchange_Subtract(integer_tr auto value);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        value_t*    operator =(pointer_tr auto value);

        value_t*    operator +(integer_tr auto value) const;
        value_t*    operator -(integer_tr auto value) const;
        value_t*    operator +=(integer_tr auto value);
        value_t*    operator -=(integer_tr auto value);
        value_t*    operator ++();
        value_t*    operator ++(int);
        value_t*    operator --();
        value_t*    operator --(int);

        value_t*    operator ->() const;
        value_t&    operator *() const;
        value_t&    operator [](integer_tr auto index) const;
    };

    /// @nosubgrouping
    /// @copydoc _82a1e5b2_d82c_4a8e_b740_b84adc2a71ab
    template <>
    class atomic_t<void_t*>
    {
    public:
        using value_t   = void_t;

    public:
        value_t* volatile   value;  ///< @copydoc _93d24339_6dae_40f2_9f11_c9305ebb3816

    public:
        atomic_t();
        atomic_t(value_t* value);
        atomic_t(const atomic_t& other);
        atomic_t(atomic_t&& other) noexcept;
        atomic_t& operator =(const atomic_t& other);
        atomic_t& operator =(atomic_t&& other) noexcept;
        ~atomic_t();

    public:
        value_t*    Access() const;

        value_t*    Assign(pointer_tr auto value);

        value_t*    Exchange(pointer_tr auto value);
        value_t*    Exchange_If_Equals(pointer_tr auto value, pointer_tr auto target);

    public:
        operator    value_t*() const;

    public:
        value_t*    operator ()() const;

        value_t*    operator =(pointer_tr auto value);
    };

}

#include "nkr/atomic_t.inl"
