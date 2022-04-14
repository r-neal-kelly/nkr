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

            new (&self.deferred.data.types) decltype(self.deferred.data.types)();
        #if defined(nkr_IS_DEBUG)
            new (&self.deferred.data.has_been_checked) decltype(self.deferred.data.has_been_checked)(false);
        #endif
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> self_p,
            tr<any_to_tg, typename self_p::any_usable_ts> other_p
        > static inline constexpr nkr::none::type_t
            Construct(self_p& self, other_p& other)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;
            using value_t = typename self_t::value_t;
            using other_t = other_p;

            if constexpr (tr<other_t, any_tg, t<self_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(other.deferred.data.types);
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_checked)
                    decltype(self.deferred.data.has_been_checked)(false);
            #endif
            } else if constexpr (tr<other_t, any_to_tg, t<integer_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(static_cast<integer_t>(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_checked)
                    decltype(self.deferred.data.has_been_checked)(false);
            #endif
            } else {
                [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Invalid type for construction."); }();
            }
        }

        template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> self_p,
            tr<any_non_const_to_tg, typename self_p::any_usable_ts> other_p
        > static inline constexpr nkr::none::type_t
            Construct(self_p& self, other_p&& other)
            noexcept
        {
            using self_t = self_p;
            using integer_t = typename self_t::integer_t;
            using value_t = typename self_t::value_t;
            using other_t = other_p;

            if constexpr (tr<other_t, any_non_const_tg, t<self_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(nkr::cpp::Move(other.deferred.data.types));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_checked)
                    decltype(self.deferred.data.has_been_checked)(nkr::cpp::Exchange(other.deferred.data.has_been_checked, true));
            #endif
            } else if constexpr (tr<other_t, any_non_const_to_tg, t<integer_t>>) {
                new (&self.deferred.data.types)
                    decltype(self.deferred.data.types)(static_cast<integer_t>(other));
            #if defined(nkr_IS_DEBUG)
                new (&self.deferred.data.has_been_checked)
                    decltype(self.deferred.data.has_been_checked)(false);
            #endif
            } else {
                [] <nkr::boolean::cpp_t _ = false>() { static_assert(_, "Invalid type for construction."); }();
            }
        }

        /*template <
            tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> self_p,
            tr<to_tg, t<typename self_p::integer_t>> to_integer_p
        >
            requires (tr<to_integer_p, not_any_tg, tt<nkr::enumeration::errors_t>>)
        static inline constexpr auto&
            Assign(self_p& self, const to_integer_p& to_integer)
            noexcept
        {
            printf("assigning to_integer\n");
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using integer_t = typename self_t::integer_t;

            self.types = static_cast<integer_t>(to_integer);
        #if defined(nkr_IS_DEBUG)
            self.has_been_checked = false;
        #endif

            return self;
        }

        static inline constexpr auto&
            Assign(tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> auto& self,
                   const tr<any_tg, tt<nkr::enumeration::errors_t>> auto& other)
            noexcept
        {
            printf("assigning lvalue other\n");
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using other_t = nkr::cpp::reference_value_t<decltype(other)>;

            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                self.types = other.types;
            #if defined(nkr_IS_DEBUG)
                self.has_been_checked = false;
            #endif
            }

            return self;
        }

        static inline constexpr auto&
            Assign(tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> auto& self,
                   tr<any_non_const_tg, tt<nkr::enumeration::errors_t>> auto&& other)
            noexcept
        {
            printf("assigning rvalue other\n");
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using other_t = nkr::cpp::reference_value_t<decltype(other)>;

            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                self.types = nkr::cpp::Move(other.types);
            #if defined(nkr_IS_DEBUG)
                self.has_been_checked = nkr::cpp::Exchange(other.has_been_checked, true);
            #endif
            }

            return self;
        }*/

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
            nkr_ASSERT_THAT(self.deferred.data.has_been_checked == true);
        #endif

            self.deferred.data.types.~decltype(self.deferred.data.types)();
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_checked.~decltype(self.deferred.data.has_been_checked)();
        #endif
        }

        static inline constexpr auto
            Boolean(const tr<any_tg, tt<nkr::enumeration::errors_t>> auto& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_checked = true;
        #endif

            return static_cast<nkr::boolean::cpp_t>(self.deferred.data.types);
        }

        static inline constexpr auto
            Integer(const tr<any_tg, tt<nkr::enumeration::errors_t>> auto& self)
            noexcept
        {
        #if defined(nkr_IS_DEBUG)
            self.deferred.data.has_been_checked = true;
        #endif

            return self.deferred.data.types.Integer();
        }
    };

}}}

namespace nkr { namespace enumeration { namespace errors_t$ {

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp() noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(tr<any_to_tg, any_usable_ts> auto& other) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, other);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::generic_sp(tr<any_non_const_to_tg, any_usable_ts> auto&& other) noexcept
    {
        nkr::enumeration::errors_t$::common_t::Construct(*this, nkr::cpp::Move(other));
    }

    /*
    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::operator =(const tr<to_tg, t<integer_t>> auto& to_integer)
        noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, to_integer);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::operator =(const tr<to_tg, t<integer_t>> auto& to_integer)
        volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Assign(*this, to_integer);
    }
    */

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::~generic_sp() noexcept
    {
        nkr::enumeration::errors_t$::common_t::Destruct(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr nkr::boolean::cpp_t
        generic_sp<value_p>::Boolean()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline nkr::boolean::cpp_t
        generic_sp<value_p>::Boolean()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr typename generic_sp<value_p>::integer_t
        generic_sp<value_p>::Integer()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline typename generic_sp<value_p>::integer_t
        generic_sp<value_p>::Integer()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Integer(const tr<to_tg, t<integer_t>> auto& to_integer)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Integer(const tr<to_tg, t<integer_t>> auto& to_integer)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr const typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline const volatile typename generic_sp<value_p>::value_t&
        generic_sp<value_p>::Value()
        const volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Value(const tr<any_tg, t<value_t>> auto& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>&
        generic_sp<value_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline volatile generic_sp<value_p>&
        generic_sp<value_p>::Value(tr<any_non_const_tg, t<value_t>> auto&& value)
        volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr nkr::none::type_t
        generic_sp<value_p>::Ignore()
        const noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline nkr::none::type_t
        generic_sp<value_p>::Ignore()
        const volatile noexcept;

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::operator generic_sp<value_p>::integer_t()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::operator generic_sp<value_p>::integer_t()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Integer(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline constexpr generic_sp<value_p>::operator nkr::boolean::cpp_t()
        const noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

    template <nkr::generic::implementing::interface::enumeration::types_tr value_p>
    inline generic_sp<value_p>::operator nkr::boolean::cpp_t()
        const volatile noexcept
    {
        return nkr::enumeration::errors_t$::common_t::Boolean(*this);
    }

}}}

#endif
