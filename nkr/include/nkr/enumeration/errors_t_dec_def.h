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
        static inline constexpr nkr::none::type_t
            Construct(tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> auto& self)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;

            new (&self.deferred.data.types)
                decltype(self.deferred.data.types)();
        #if defined(nkr_IS_DEBUG)
            new (&self.deferred.data.has_been_read)
                decltype(self.deferred.data.has_been_read)(false);
        #endif
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_tg>                                              other_p
        > static inline constexpr nkr::none::type_t
            Construct(self_p& self, other_p& other)
            noexcept
        {
            using self_t = self_p;
            using other_t = other_p;
            using value_t = typename self_t::value_t;
            using integer_t = typename self_t::integer_t;

            if constexpr (tr<other_t, any_tg, t<self_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(other.deferred.data.types);
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
                other.deferred.data.has_been_read = true;
            #endif
            } else if constexpr (tr<other_t, any_tg, t<value_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(other);
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<integer_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(integer_t(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<value_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(value_t(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<self_t>>) {
                Construct(self, self_t(other));
            } else {
                [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Invalid type for lvalue construction."); }();
            }
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_tg>                                    other_p
        > static inline constexpr nkr::none::type_t
            Construct(self_p& self, other_p&& other)
            noexcept
        {
            using self_t = self_p;
            using other_t = other_p;
            using value_t = typename self_t::value_t;
            using integer_t = typename self_t::integer_t;

            if constexpr (tr<other_t, any_non_const_tg, t<self_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(nkr::cpp::Move(other.deferred.data.types));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
                other.deferred.data.has_been_read = true;
            #endif
            } else if constexpr (tr<other_t, any_non_const_tg, t<value_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(nkr::cpp::Move(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
            #endif
            } else if constexpr (tr<other_t, any_non_const_to_tg, t<integer_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(integer_t(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
            #endif
            } else if constexpr (tr<other_t, any_non_const_to_tg, t<value_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(value_t(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_read)
                    decltype(self.deferred.data.has_been_read)(false);
            #endif
            } else if constexpr (tr<other_t, any_non_const_to_tg, t<self_t>>) {
                Construct(self, self_t(other));
            } else {
                [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Invalid type for rvalue construction."); }();
            }
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_tg>                                              other_p
        > static inline constexpr auto&
            Assign(self_p& self, other_p& other)
            noexcept
        {
            using self_t = self_p;
            using other_t = other_p;
            using value_t = typename self_t::value_t;
            using integer_t = typename self_t::integer_t;

            if constexpr (tr<other_t, any_tg, t<self_t>>) {
                if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                    self.deferred.data.types = other.deferred.data.types;
                #if defined(nkr_IS_DEBUG)
                    self.deferred.data.has_been_read = false;
                    other.deferred.data.has_been_read = true;
                #endif
                }
            } else if constexpr (tr<other_t, any_tg, t<value_t>>) {
                self.deferred.data.types = other;
            #if defined(nkr_IS_DEBUG)
                self.deferred.data.has_been_read = false;
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<integer_t>>) {
                self.deferred.data.types = integer_t(other);
            #if defined(nkr_IS_DEBUG)
                self.deferred.data.has_been_read = false;
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<value_t>>) {
                self.deferred.data.types = value_t(other);
            #if defined(nkr_IS_DEBUG)
                self.deferred.data.has_been_read = false;
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<self_t>>) {
                Assign(self, self_t(other));
            } else {
                [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Invalid type for lvalue assignment."); }();
            }

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_tg>                                    other_p
        > static inline constexpr auto&
            Assign(self_p& self, other_p&& other)
            noexcept
        {
            using self_t = self_p;
            using other_t = other_p;
            using value_t = typename self_t::value_t;
            using integer_t = typename self_t::integer_t;

            if constexpr (tr<other_t, any_tg, t<self_t>>) {
                if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                    self.deferred.data.types = nkr::cpp::Move(other.deferred.data.types);
                #if defined(nkr_IS_DEBUG)
                    self.deferred.data.has_been_read = false;
                    other.deferred.data.has_been_read = true;
                #endif
                }
            } else if constexpr (tr<other_t, any_tg, t<value_t>>) {
                self.deferred.data.types = nkr::cpp::Move(other);
            #if defined(nkr_IS_DEBUG)
                self.deferred.data.has_been_read = false;
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<integer_t>>) {
                self.deferred.data.types = integer_t(other);
            #if defined(nkr_IS_DEBUG)
                self.deferred.data.has_been_read = false;
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<value_t>>) {
                self.deferred.data.types = value_t(other);
            #if defined(nkr_IS_DEBUG)
                self.deferred.data.has_been_read = false;
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<self_t>>) {
                Assign(self, self_t(other));
            } else {
                [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Invalid type for rvalue assignment."); }();
            }

            return self;
        }

        static inline constexpr nkr::none::type_t
            Destruct(tr<any_tg, tt<nkr::enumeration::errors_t>> auto& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            // You need to check your potential error before it destructs.
            // This assert acts like an exception, except it's way cheaper.
            // It helps you identify where you might not be handling an error correctly.
            // Follow the stack frames before this one to find the exact error in question.
            // These asserts are completely removed from release builds.
            nkr_ASSERT_THAT(self.deferred.data.has_been_read == true);
        #endif

            self.deferred.data.types.~decltype(self.deferred.data.types)();
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read.~decltype(self.deferred.data.has_been_read)();
        #endif
        }

        static inline constexpr auto
            Boolean(const tr<any_tg, tt<nkr::enumeration::errors_t>> auto& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = true;
        #endif

            return static_cast<nkr::boolean::cpp_t>(self.deferred.data.types);
        }

        static inline constexpr auto
            Integer(const tr<any_tg, tt<nkr::enumeration::errors_t>> auto& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = true;
        #endif

            return self.deferred.data.types.Integer();
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_to_tg, t<typename self_p::integer_t>>            from_p
        > static inline constexpr auto
            Integer(self_p& self, from_p& from)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;

        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = false;
        #endif

            self.deferred.data.types.Integer(integer_t(from));

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_to_tg, t<typename self_p::integer_t>>  from_p
        > static inline constexpr auto
            Integer(self_p& self, from_p&& from)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;

        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = false;
        #endif

            self.deferred.data.types.Integer(integer_t(from));

            return self;
        }

        template <tr<any_tg, tt<nkr::enumeration::errors_t>> self_p>
        static inline constexpr auto&
            Value(self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = true;
        #endif

            return self.deferred.data.types.Value();
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_to_tg, t<typename self_p::value_t>>              from_p
        > static inline constexpr auto&
            Value(self_p& self, from_p& from)
            noexcept
        {
            using self_t = self_p;
            using from_t = from_p;
            using value_t = typename self_t::value_t;

        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = false;
        #endif

            if constexpr (tr<from_t, any_tg, t<value_t>>) {
                self.deferred.data.types.Value(from);
            } else {
                self.deferred.data.types.Value(value_t(from));
            }

            return self;
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>>    self_p,
            tr<any_non_const_to_tg, t<typename self_p::value_t>>    from_p
        > static inline constexpr auto&
            Value(self_p& self, from_p&& from)
            noexcept
        {
            using self_t = self_p;
            using from_t = from_p;
            using value_t = typename self_t::value_t;

        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = false;
        #endif

            if constexpr (tr<from_t, any_non_const_tg, t<value_t>>) {
                self.deferred.data.types.Value(nkr::cpp::Move(from));
            } else {
                self.deferred.data.types.Value(value_t(from));
            }

            return self;
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr nkr::boolean::cpp_t
            Is_Armed(self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            return !self.deferred.data.has_been_read;
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
            self.deferred.data.has_been_read = false;
        #endif
        }

        template <
            tr<any_tg, tt<nkr::enumeration::errors_t>>  self_p
        > static inline constexpr nkr::none::type_t
            Disarm(self_p& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_read = true;
        #endif
        }
    };

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp() noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(const generic_sp& other) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>::generic_sp(const volatile generic_sp& other) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(generic_sp&& other) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline generic_sp<type_p, none_p>::generic_sp(volatile generic_sp&& other) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(tr<any_to_tg, any_usable_ts> auto& from) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::generic_sp(tr<any_non_const_to_tg, any_usable_ts> auto&& from) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, nkr::cpp::Move(from));
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

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(tr<any_to_tg, any_usable_ts> auto& from)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(tr<any_to_tg, any_usable_ts> auto& from)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(tr<any_non_const_to_tg, any_usable_ts> auto&& from)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, nkr::cpp::Move(from));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::operator =(tr<any_non_const_to_tg, any_usable_ts> auto&& from)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, nkr::cpp::Move(from));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>::~generic_sp() noexcept
    {
        nkr::enumeration::errors_t$::common_t::Destruct(*this);
    }

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
        generic_sp<type_p, none_p>::Value(tr<any_to_tg, t<value_t>> auto& from)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(tr<any_to_tg, t<value_t>> auto& from)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, from);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline constexpr generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(tr<any_non_const_to_tg, t<value_t>> auto&& from)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, nkr::cpp::Move(from));
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr type_p, nkr::constant_tr none_p>
    inline volatile generic_sp<type_p, none_p>&
        generic_sp<type_p, none_p>::Value(tr<any_non_const_to_tg, t<value_t>> auto&& from)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Value(*this, nkr::cpp::Move(from));
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
}}}

inline constexpr nkr::boolean::cpp_t
    operator ==(nkr::tr<nkr::any_tg, nkr::tt<nkr::enumeration::errors_t>> auto& a, auto& b)
    noexcept
{
    using a_t = nkr::cpp::reference_value_t<decltype(a)>;
    using b_t = nkr::cpp::reference_value_t<decltype(b)>;

    if constexpr (nkr::cpp::is_any_tr<a_t, b_t>) {
        return a() == b();
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
