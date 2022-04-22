/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_8932856c_a4b8_4fd1_a679_3e687e4f1f5f
#define nkr_INCLUDE_GUARD_8932856c_a4b8_4fd1_a679_3e687e4f1f5f

#include "nkr/enumeration/errors_t_dec.h"

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::enumeration::errors_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::enumeration::errors_tg>;
    }

    template <nkr::enumeration::errors_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::enumeration::errors_t$::Is_Any_General<other_p>();
    }

    template <nkr::enumeration::errors_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::enumeration::errors_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::enumeration::errors_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    class common_t
    {
    public:
        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_tg, t<nkr::enumeration::cpp_tg>>                 other_p
        > static inline constexpr auto&
            Assign(self_p& self, other_p other)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;

            Integer(self, integer_t(other));

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_tg, t<self_p>>                                   other_p
        > static inline constexpr auto&
            Assign(self_p& self, other_p& other)
            noexcept
        {
            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                self.types = other.types;
            #if defined(nkr_IS_DEBUG)
                self.has_been_read = false;
                Disarm(other);
            #endif
            }

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_tg, t<self_p>>                         other_p
        > static inline constexpr auto&
            Assign(self_p& self, other_p&& other)
            noexcept
        {
            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                self.types = nkr::cpp::Move(other.types);
            #if defined(nkr_IS_DEBUG)
                self.has_been_read = false;
                Disarm(other);
            #endif
            }

            return self;
        }

    #if defined(nkr_IS_DEBUG)
        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr nkr::none::type_t
            Destruct(self_p& self)
            noexcept
        {
            // You need to check your potential error before it destructs.
            // This assert acts like an exception, except it's way cheaper.
            // It helps you identify where you might not be handling an error correctly.
            // Follow the stack frames before this one to find the exact error in question.
            // These asserts are completely removed from release builds.
            nkr_ASSERT_THAT(!Is_Armed(self));
        }
    #endif

    public:
        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr auto
            Boolean(const self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.has_been_read = true;
        #endif

            return static_cast<nkr::boolean::cpp_t>(self.types);
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr auto
            Integer(const self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.has_been_read = true;
        #endif

            return self.types.Integer();
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_to_tg, t<typename self_p::integer_t>>            from_p
        > static inline constexpr auto&
            Integer(self_p& self, from_p& from)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;

        #if defined(nkr_IS_DEBUG)
            self.has_been_read = false;
        #endif

            self.types.Integer(integer_t(from));

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_to_tg, t<typename self_p::integer_t>>  from_p
        > static inline constexpr auto&
            Integer(self_p& self, from_p&& from)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;

        #if defined(nkr_IS_DEBUG)
            self.has_been_read = false;
        #endif

            self.types.Integer(integer_t(from));

            return self;
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr auto&
            Value(self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.has_been_read = true;
        #endif

            return self.types.Value();
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_tg, t<typename self_p::value_t>>                 value_p
        > static inline constexpr auto&
            Value(self_p& self, const value_p& value)
            noexcept
        {
            using self_t = self_p;

        #if defined(nkr_IS_DEBUG)
            self.has_been_read = false;
        #endif

            self.types.Value(value);

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_tg, t<typename self_p::value_t>>       value_p
        > static inline constexpr auto&
            Value(self_p& self, value_p&& value)
            noexcept
        {
            using self_t = self_p;
            using value_t = value_p;

        #if defined(nkr_IS_DEBUG)
            self.has_been_read = false;
        #endif

            self.types.Value(nkr::cpp::Move(value));

            return self;
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr nkr::boolean::cpp_t
            Is_Armed(const self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            return !self.has_been_read;
        #else
            return false;
        #endif
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr nkr::none::type_t
            Arm(self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.has_been_read = false;
        #endif
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr nkr::none::type_t
            Disarm(self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.has_been_read = true;
        #endif
        }

    public:
        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr auto
            Logical_Not(const self_p& self)
            noexcept
        {
            return !Boolean(self);
        }
    };

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp() noexcept :
        types()
    #if defined(nkr_IS_DEBUG)
        , has_been_read(false)
    #endif
    {
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(tr<any_tg, t<nkr::enumeration::cpp_tg>> auto enumeration) noexcept :
        types(integer_t(enumeration))
    #if defined(nkr_IS_DEBUG)
        , has_been_read(false)
    #endif
    {
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(const generic_sp& other) noexcept :
        types(other.types)
    #if defined(nkr_IS_DEBUG)
        , has_been_read(false)
    #endif
    {
    #if defined(nkr_IS_DEBUG)
        other.Disarm();
    #endif
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>::generic_sp(const volatile generic_sp& other) noexcept :
        types(other.types)
    #if defined(nkr_IS_DEBUG)
        , has_been_read(false)
    #endif
    {
    #if defined(nkr_IS_DEBUG)
        other.Disarm();
    #endif
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(generic_sp&& other) noexcept :
        types(nkr::cpp::Move(other.types))
    #if defined(nkr_IS_DEBUG)
        , has_been_read(false)
    #endif
    {
    #if defined(nkr_IS_DEBUG)
        other.Disarm();
    #endif
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>::generic_sp(volatile generic_sp&& other) noexcept :
        types(nkr::cpp::Move(other.types))
    #if defined(nkr_IS_DEBUG)
        , has_been_read(false)
    #endif
    {
    #if defined(nkr_IS_DEBUG)
        other.Disarm();
    #endif
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(tr<any_tg, t<nkr::enumeration::cpp_tg>> auto enumeration)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, enumeration);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(tr<any_tg, t<nkr::enumeration::cpp_tg>> auto enumeration)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, enumeration);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(const generic_sp& other)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(const generic_sp& other)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>& generic_sp<type_p, none_p>::operator =(const volatile generic_sp& other)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(const volatile generic_sp& other)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(generic_sp&& other)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(generic_sp&& other)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(volatile generic_sp&& other)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(volatile generic_sp&& other)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

#if defined(nkr_IS_DEBUG)
    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::~generic_sp() noexcept
    {
        nkr::enumeration::errors_t$::common_t::Destruct(*this);
    }
#endif

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr nkr::boolean::cpp_t
        generic_sp<type_p, none_p>::Boolean()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline nkr::boolean::cpp_t
        generic_sp<type_p, none_p>::Boolean()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr typename generic_sp<type_p, none_p>::integer_t
        generic_sp<type_p, none_p>::Integer()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline typename generic_sp<type_p, none_p>::integer_t
        generic_sp<type_p, none_p>::Integer()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Integer(tr<any_to_tg, t<integer_t>> auto& from)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Integer(tr<any_to_tg, t<integer_t>> auto& from)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Integer(tr<any_non_const_to_tg, t<integer_t>> auto&& from)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this, nkr::cpp::Move(from));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Integer(tr<any_non_const_to_tg, t<integer_t>> auto&& from)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this, nkr::cpp::Move(from));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr typename generic_sp<type_p, none_p>::value_t&
        generic_sp<type_p, none_p>::Value()
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr const typename generic_sp<type_p, none_p>::value_t&
        generic_sp<type_p, none_p>::Value()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile typename generic_sp<type_p, none_p>::value_t&
        generic_sp<type_p, none_p>::Value()
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline const volatile typename generic_sp<type_p, none_p>::value_t&
        generic_sp<type_p, none_p>::Value()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, value);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, value);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, nkr::cpp::Move(value));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr nkr::boolean::cpp_t
        generic_sp<type_p, none_p>::Is_Armed()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Is_Armed(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline nkr::boolean::cpp_t
        generic_sp<type_p, none_p>::Is_Armed()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Is_Armed(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr nkr::none::type_t
        generic_sp<type_p, none_p>::Arm()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Arm(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline nkr::none::type_t
        generic_sp<type_p, none_p>::Arm()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Arm(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr nkr::none::type_t
        generic_sp<type_p, none_p>::Disarm()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Disarm(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline nkr::none::type_t
        generic_sp<type_p, none_p>::Disarm()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Disarm(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::operator nkr::boolean::cpp_t()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>::operator nkr::boolean::cpp_t()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::operator generic_sp<type_p, none_p>::integer_t()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>::operator generic_sp<type_p, none_p>::integer_t()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr typename generic_sp<type_p, none_p>::integer_t
        generic_sp<type_p, none_p>::operator ()()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline typename generic_sp<type_p, none_p>::integer_t
        generic_sp<type_p, none_p>::operator ()()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr nkr::boolean::cpp_t
        generic_sp<type_p, none_p>::operator !()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Logical_Not(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline nkr::boolean::cpp_t
        generic_sp<type_p, none_p>::operator !()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Logical_Not(*this);
    }
}}}

inline constexpr nkr::boolean::cpp_t
    operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;
    using integer_t = typename a_t::integer_t;

    if constexpr (nkr::cpp::is_any_tr<a_t, b_t>) {
        return a() == b();
    } else if constexpr (nkr::enumeration::cpp_tr<b_t>) {
        return a.Integer() == integer_t(b);
    } else if constexpr (nkr::cpp::is_any_tr<b_t, nkr::boolean::cpp_t>) {
        return a.Boolean() == b;
    } else if constexpr (nkr::cpp::is_any_tr<b_t, typename a_t::integer_t>) {
        return a.Integer() == b;
    } else if constexpr (nkr::cpp::is_any_tr<b_t, typename a_t::value_t>) {
        return a.Value() == b;
    } else if constexpr (nkr::cpp::to_tr<a_t, nkr::cpp::just_non_qualified_t<b_t>>) {
        return nkr::cpp::just_non_qualified_t<b_t>(a) == b;
    } else if constexpr (nkr::cpp::to_tr<b_t, nkr::cpp::just_non_qualified_t<a_t>>) {
        return a == nkr::cpp::just_non_qualified_t<a_t>(b);
    } else {
        [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "these two values can not be compared."); }();
    }
}

inline constexpr nkr::boolean::cpp_t
    operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto&& b)
    noexcept
{
    return operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto& b)
    noexcept
{
    return !operator ==(a, b);
}

inline constexpr nkr::boolean::cpp_t
    operator !=(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto&& a, auto&& b)
    noexcept
{
    return !operator ==(a, b);
}

#endif
