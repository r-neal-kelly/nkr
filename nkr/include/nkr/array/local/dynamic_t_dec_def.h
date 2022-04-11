/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_8fdaa008_a319_43f5_b411_0559c765926e
#define nkr_INCLUDE_GUARD_8fdaa008_a319_43f5_b411_0559c765926e

#include "nkr/array/local/dynamic_t_dec.h"

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::array::local::dynamic_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::array::local::dynamic_tg>;
    }

    template <nkr::array::local::dynamic_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::local::dynamic_t$::Is_Any_General<other_p>();
    }

    template <nkr::array::local::dynamic_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::array::local::dynamic_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::local::dynamic_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::array::local::dynamic_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    class common_t
    {
    public:
        template <tr<any_non_const_tg, t<nkr::array::local::dynamic_tg>> self_p>
        static inline constexpr void
            Construct(self_p& self,
                      const tr<any_tg, t<typename self_p::unit_t>> auto& ...units)
            noexcept
        {
            using self_t = self_p;
            using unit_t = typename self_t::unit_t;
            using capacity_t = typename self_t::capacity_t;

            static_assert(sizeof...(units) <= capacity_t::Value());

            Count(self, sizeof...(units));
            new (&self.bytes) unit_t[sizeof...(units)]{ units... };
        }

        template <tr<any_non_const_tg, t<nkr::array::local::dynamic_tg>> self_p>
        static inline constexpr void
            Construct(self_p& self,
                      tr<any_non_const_tg, t<typename self_p::unit_t>> auto&& ...units)
            noexcept
        {
            using self_t = self_p;
            using unit_t = typename self_t::unit_t;
            using capacity_t = typename self_t::capacity_t;

            static_assert(sizeof...(units) <= capacity_t::Value());

            Count(self, sizeof...(units));
            new (&self.bytes) unit_t[sizeof...(units)]{ nkr::cpp::Move(units)... };
        }

        static inline constexpr auto&
            Assign(tr<any_non_const_tg, t<nkr::array::local::dynamic_tg>> auto& self,
                   const tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& other)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using other_t = nkr::cpp::reference_value_t<decltype(other)>;
            using self_non_const_unit_t = typename self_t::non_const_unit_t;

            // should change this to look at if the two unit_ts are compatible,
            // and if the capacity of self can take on the count of other.
            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                nkr::positive::count_t self_count = Count(self);
                nkr::positive::count_t other_count = Count(other);
                auto& self_non_const_units = Non_Const_Units(self);
                auto& other_units = Units(other);

                if (self_count > other_count) {
                    for (nkr::positive::index_t idx = 0, end = other_count; idx < end; idx += 1) {
                        self_non_const_units[idx].~self_non_const_unit_t();
                        self_non_const_units[idx] = other_units[idx];
                    }
                    for (nkr::positive::index_t idx = other_count, end = self_count; idx < end; idx += 1) {
                        self_non_const_units[idx].~self_non_const_unit_t();
                    }
                } else {
                    for (nkr::positive::index_t idx = 0, end = self_count; idx < end; idx += 1) {
                        self_non_const_units[idx].~self_non_const_unit_t();
                        self_non_const_units[idx] = other_units[idx];
                    }
                    for (nkr::positive::index_t idx = self_count, end = other_count; idx < end; idx += 1) {
                        self_non_const_units[idx] = other_units[idx];
                    }
                }

                Count(self, other_count);
            }

            return self;
        }

        static inline constexpr auto&
            Assign(tr<any_non_const_tg, t<nkr::array::local::dynamic_tg>> auto& self,
                   tr<any_non_const_tg, t<nkr::array::local::dynamic_tg>> auto&& other)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using other_t = nkr::cpp::reference_value_t<decltype(other)>;
            using self_non_const_unit_t = typename self_t::non_const_unit_t;
            using other_non_const_unit_t = typename other_t::non_const_unit_t;

            // should change this to look at if the two unit_ts are compatible,
            // and if the capacity of self can take on the count of other.
            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                nkr::positive::count_t self_count = Count(self);
                nkr::positive::count_t other_count = Count(other);
                auto& self_non_const_units = Non_Const_Units(self);
                auto& other_non_const_units = Non_Const_Units(other);

                if (self_count > other_count) {
                    for (nkr::positive::index_t idx = 0, end = other_count; idx < end; idx += 1) {
                        self_non_const_units[idx].~self_non_const_unit_t();
                        self_non_const_units[idx] = nkr::cpp::Move(other_non_const_units[idx]);
                        other_non_const_units[idx].~other_non_const_unit_t();
                    }
                    for (nkr::positive::index_t idx = other_count, end = self_count; idx < end; idx += 1) {
                        self_non_const_units[idx].~self_non_const_unit_t();
                    }
                } else {
                    for (nkr::positive::index_t idx = 0, end = self_count; idx < end; idx += 1) {
                        self_non_const_units[idx].~self_non_const_unit_t();
                        self_non_const_units[idx] = nkr::cpp::Move(other_non_const_units[idx]);
                        other_non_const_units[idx].~other_non_const_unit_t();
                    }
                    for (nkr::positive::index_t idx = self_count, end = other_count; idx < end; idx += 1) {
                        self_non_const_units[idx] = nkr::cpp::Move(other_non_const_units[idx]);
                        other_non_const_units[idx].~other_non_const_unit_t();
                    }
                }

                Count(self, other_count);
                Count(other, 0);
            }

            return self;
        }

        static inline constexpr void
            Destruct(tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using unit_t = typename self_t::unit_t;

            auto& units = Units(self);

            for (nkr::positive::index_t idx = 0, end = Count(self); idx < end; idx += 1) {
                units[idx].~unit_t();
            }

        #if defined(nkr_IS_DEBUG)
            Count(self, 0);
        #endif
        }

        static inline constexpr auto
            Capacity(const tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using capacity_t = typename self_t::capacity_t;

            return capacity_t::Value();
        }

        static inline constexpr auto
            Count(const tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self)
            noexcept
        {
            return self.count;
        }

        static inline constexpr auto
            Count(tr<any_non_const_tg, t<nkr::array::local::dynamic_tg>> auto& self, nkr::positive::count_t count)
            noexcept
        {
            return self.count = count;
        }

        static inline constexpr auto&
            Units(tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self)
            noexcept
        {
            using self_t =
                nkr::cpp::reference_value_t<decltype(self)>;
            using access_qualified_units_t =
                nkr::cpp::access_qualification_of_t<typename self_t::units_t, self_t>;

            return reinterpret_cast<access_qualified_units_t&>(self.bytes);
        }

        static inline constexpr auto&
            Non_Const_Units(tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self)
            noexcept
        {
            using self_t =
                nkr::cpp::reference_value_t<decltype(self)>;
            using access_qualified_non_const_units_t =
                nkr::cpp::access_qualification_of_t<typename self_t::non_const_units_t, self_t>;

            return reinterpret_cast<access_qualified_non_const_units_t&>(self.bytes);
        }

        static inline constexpr auto&
            Unit(tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self, nkr::positive::index_t index)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;

            nkr_ASSERT_THAT(index < Count(self));

            return Units(self)[index];
        }

        static inline constexpr auto&
            Non_Const_Unit(tr<any_tg, t<nkr::array::local::dynamic_tg>> auto& self, nkr::positive::index_t index)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;

            nkr_ASSERT_THAT(index < Count(self));

            return Non_Const_Units(self)[index];
        }
    };

}}}}

namespace nkr { namespace array { namespace local { namespace dynamic_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_empty_sp<unit_p, capacity_p>::non_empty_sp() noexcept :
        count(0)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_empty_sp<unit_p, capacity_p>::non_empty_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept
    {
        nkr::array::local::dynamic_t$::common_t::Construct(*this, units...);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_empty_sp<unit_p, capacity_p>::non_empty_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept
    {
        nkr::array::local::dynamic_t$::common_t::Construct(*this, nkr::cpp::Move(units)...);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(const non_empty_sp& other)
        noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(const non_empty_sp& other)
        volatile noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(const volatile non_empty_sp& other)
        noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(const volatile non_empty_sp& other)
        volatile noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(non_empty_sp&& other)
        noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(non_empty_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(volatile non_empty_sp&& other)
        noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_empty_sp<unit_p, capacity_p>&
        non_empty_sp<unit_p, capacity_p>::operator =(volatile non_empty_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::dynamic_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_empty_sp<unit_p, capacity_p>::~non_empty_sp() noexcept
    {
        nkr::array::local::dynamic_t$::common_t::Destruct(*this);
    }

}}}}

#endif
