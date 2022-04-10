/*
    Copyright 2022 r-neal-kelly
*/

#ifndef nkr_INCLUDE_GUARD_2864fe82_5ed3_4da8_a8ad_67ddd680b7d3
#define nkr_INCLUDE_GUARD_2864fe82_5ed3_4da8_a8ad_67ddd680b7d3

#include "nkr/array/local/static_t_dec.h"

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        Is_Any_General()
        noexcept
    {
        return
            nkr::array::local::static_tr<other_p> ||
            nkr::cpp::is_any_tr<other_p, nkr::array::local::static_tg>;
    }

    template <nkr::array::local::static_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::local::static_t$::Is_Any_General<other_p>();
    }

    template <nkr::array::local::static_tr type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_type_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

    template <nkr::cpp::is_any_tr<nkr::array::local::static_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_General()
        noexcept
    {
        return nkr::array::local::static_t$::Is_Any_General<other_p>();
    }

    template <nkr::cpp::is_any_tr<nkr::array::local::static_tg> type_p>
    template <typename other_p>
    inline constexpr nkr::boolean::cpp_t
        type_i_tag_sp<type_p>::Is_Any_Specific()
        noexcept
    {
        return nkr::cpp::is_any_tr<other_p, type_t>;
    }

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    class common_t
    {
    public:
        static inline constexpr auto&
            Assign(tr<any_non_const_tg, t<nkr::array::local::static_tg>> auto& self,
                   const tr<any_tg, t<nkr::array::local::static_tg>> auto& other)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using other_t = nkr::cpp::reference_value_t<decltype(other)>;

            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                self.units_or_bytes = other.units_or_bytes;
            }

            return self;
        }

        static inline constexpr auto&
            Assign(tr<any_non_const_tg, t<nkr::array::local::static_tg>> auto& self,
                   tr<any_non_const_tg, t<nkr::array::local::static_tg>> auto&& other)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;
            using other_t = nkr::cpp::reference_value_t<decltype(other)>;

            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                self.units_or_bytes = nkr::cpp::Move(other.units_or_bytes);
            }

            return self;
        }

        static inline constexpr auto&
            Units(tr<any_tg, t<nkr::array::local::static_tg>> auto& self)
            noexcept
        {
            return self.units_or_bytes.Units();
        }

        static inline constexpr auto
            Count(tr<any_tg, t<nkr::array::local::static_tg>> auto& self)
            noexcept
        {
            return Capacity(self);
        }

        static inline constexpr auto
            Capacity(tr<any_tg, t<nkr::array::local::static_tg>> auto& self)
            noexcept
        {
            using self_t = nkr::cpp::reference_value_t<decltype(self)>;

            return self_t::capacity_t::Value();
        }
    };

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr void
        units_or_bytes_u<unit_p, capacity_p>::common_t::Construct(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                                  const tr<any_tg, t<units_or_bytes_u>> auto& other)
        noexcept
    {
        for (nkr::positive::index_t idx = 0, end = capacity_t::Value(); idx < end; idx += 1) {
            self.units[idx] = other.units[idx];
        }
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr void
        units_or_bytes_u<unit_p, capacity_p>::common_t::Construct(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                                  tr<any_non_const_tg, t<units_or_bytes_u>> auto&& other)
        noexcept
    {
        for (nkr::positive::index_t idx = 0, end = capacity_t::Value(); idx < end; idx += 1) {
            self.units[idx] = nkr::cpp::Move(other.units[idx]);
        }
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr auto&
        units_or_bytes_u<unit_p, capacity_p>::common_t::Assign(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                               const tr<any_tg, t<units_or_bytes_u>> auto& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            for (nkr::positive::index_t idx = 0, end = capacity_t::Value(); idx < end; idx += 1) {
                self.units[idx].~unit_t();
                self.units[idx] = other.units[idx];
            }
        }

        return self;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr auto&
        units_or_bytes_u<unit_p, capacity_p>::common_t::Assign(tr<any_non_const_tg, t<units_or_bytes_u>> auto& self,
                                                               tr<any_non_const_tg, t<units_or_bytes_u>> auto&& other)
        noexcept
    {
        if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
            for (nkr::positive::index_t idx = 0, end = capacity_t::Value(); idx < end; idx += 1) {
                self.units[idx].~unit_t();
                self.units[idx] = nkr::cpp::Move(other.units[idx]);
            }
        }

        return self;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr void
        units_or_bytes_u<unit_p, capacity_p>::common_t::Destruct(tr<any_tg, t<units_or_bytes_u>> auto& self)
        noexcept
    {
        for (nkr::positive::index_t idx = 0, end = capacity_t::Value(); idx < end; idx += 1) {
            self.units[idx].~unit_t();
        }
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr auto&
        units_or_bytes_u<unit_p, capacity_p>::common_t::Units(tr<any_tg, t<units_or_bytes_u>> auto& self)
        noexcept
    {
        return self.units;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u() noexcept
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(tr<any_tg, t<default_units_t>> auto default_units) noexcept :
        units{}
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units{ units... }
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units{ nkr::cpp::Move(units)... }
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(const units_or_bytes_u& other) noexcept
    {
        common_t::Construct(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(const volatile units_or_bytes_u& other) noexcept
    {
        common_t::Construct(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(units_or_bytes_u&& other) noexcept
    {
        common_t::Construct(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline units_or_bytes_u<unit_p, capacity_p>::units_or_bytes_u(volatile units_or_bytes_u&& other) noexcept
    {
        common_t::Construct(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(const units_or_bytes_u& other)
        noexcept
    {
        return common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(const units_or_bytes_u& other)
        volatile noexcept
    {
        return common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(const volatile units_or_bytes_u& other)
        noexcept
    {
        return common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(const volatile units_or_bytes_u& other)
        volatile noexcept
    {
        return common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(units_or_bytes_u&& other)
        noexcept
    {
        return common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(units_or_bytes_u&& other)
        volatile noexcept
    {
        return common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(volatile units_or_bytes_u&& other)
        noexcept
    {
        return common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile units_or_bytes_u<unit_p, capacity_p>&
        units_or_bytes_u<unit_p, capacity_p>::operator =(volatile units_or_bytes_u&& other)
        volatile noexcept
    {
        return common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr units_or_bytes_u<unit_p, capacity_p>::~units_or_bytes_u() noexcept
    {
        common_t::Destruct(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr typename units_or_bytes_u<unit_p, capacity_p>::units_t&
        units_or_bytes_u<unit_p, capacity_p>::Units()
        noexcept
    {
        return common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const typename units_or_bytes_u<unit_p, capacity_p>::units_t&
        units_or_bytes_u<unit_p, capacity_p>::Units()
        const noexcept
    {
        return common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile typename units_or_bytes_u<unit_p, capacity_p>::units_t&
        units_or_bytes_u<unit_p, capacity_p>::Units()
        volatile noexcept
    {
        return common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const volatile typename units_or_bytes_u<unit_p, capacity_p>::units_t&
        units_or_bytes_u<unit_p, capacity_p>::Units()
        const volatile noexcept
    {
        return common_t::Units(*this);
    }

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr empty_sp<unit_p, capacity_p>::empty_sp() noexcept
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr empty_sp<unit_p, capacity_p>::empty_sp(const empty_sp& other) noexcept
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline empty_sp<unit_p, capacity_p>::empty_sp(const volatile empty_sp& other) noexcept
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr empty_sp<unit_p, capacity_p>::empty_sp(empty_sp&& other) noexcept
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline empty_sp<unit_p, capacity_p>::empty_sp(volatile empty_sp&& other) noexcept
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(const empty_sp& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(const empty_sp& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(const volatile empty_sp& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(const volatile empty_sp& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(empty_sp&& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(empty_sp&& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(volatile empty_sp&& other)
        noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile empty_sp<unit_p, capacity_p>&
        empty_sp<unit_p, capacity_p>::operator =(volatile empty_sp&& other)
        volatile noexcept
    {
        return *this;
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        empty_sp<unit_p, capacity_p>::Count()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        empty_sp<unit_p, capacity_p>::Count()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        empty_sp<unit_p, capacity_p>::Capacity()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        empty_sp<unit_p, capacity_p>::Capacity()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>::non_const_default_sp() noexcept :
        units_or_bytes(typename units_or_bytes_u::default_units_t())
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>::non_const_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units_or_bytes(units...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>::non_const_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units_or_bytes(nkr::cpp::Move(units)...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>::non_const_default_sp(const non_const_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_default_sp<unit_p, capacity_p>::non_const_default_sp(const volatile non_const_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>::non_const_default_sp(non_const_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_default_sp<unit_p, capacity_p>::non_const_default_sp(volatile non_const_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(const non_const_default_sp& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(const non_const_default_sp& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(const volatile non_const_default_sp& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(const volatile non_const_default_sp& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(non_const_default_sp&& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(non_const_default_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(volatile non_const_default_sp&& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_default_sp<unit_p, capacity_p>&
        non_const_default_sp<unit_p, capacity_p>::operator =(volatile non_const_default_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr typename non_const_default_sp<unit_p, capacity_p>::units_t&
        non_const_default_sp<unit_p, capacity_p>::Units()
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const typename non_const_default_sp<unit_p, capacity_p>::units_t&
        non_const_default_sp<unit_p, capacity_p>::Units()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile typename non_const_default_sp<unit_p, capacity_p>::units_t&
        non_const_default_sp<unit_p, capacity_p>::Units()
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const volatile typename non_const_default_sp<unit_p, capacity_p>::units_t&
        non_const_default_sp<unit_p, capacity_p>::Units()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        non_const_default_sp<unit_p, capacity_p>::Count()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        non_const_default_sp<unit_p, capacity_p>::Count()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        non_const_default_sp<unit_p, capacity_p>::Capacity()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        non_const_default_sp<unit_p, capacity_p>::Capacity()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_non_default_sp<unit_p, capacity_p>::non_const_non_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units_or_bytes(units...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_non_default_sp<unit_p, capacity_p>::non_const_non_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units_or_bytes(nkr::cpp::Move(units)...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_non_default_sp<unit_p, capacity_p>::non_const_non_default_sp(const non_const_non_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_non_default_sp<unit_p, capacity_p>::non_const_non_default_sp(const volatile non_const_non_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_non_default_sp<unit_p, capacity_p>::non_const_non_default_sp(non_const_non_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_non_default_sp<unit_p, capacity_p>::non_const_non_default_sp(volatile non_const_non_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(const non_const_non_default_sp& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(const non_const_non_default_sp& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(const volatile non_const_non_default_sp& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(const volatile non_const_non_default_sp& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(non_const_non_default_sp&& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(non_const_non_default_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(volatile non_const_non_default_sp&& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile non_const_non_default_sp<unit_p, capacity_p>&
        non_const_non_default_sp<unit_p, capacity_p>::operator =(volatile non_const_non_default_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr typename non_const_non_default_sp<unit_p, capacity_p>::units_t&
        non_const_non_default_sp<unit_p, capacity_p>::Units()
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const typename non_const_non_default_sp<unit_p, capacity_p>::units_t&
        non_const_non_default_sp<unit_p, capacity_p>::Units()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile typename non_const_non_default_sp<unit_p, capacity_p>::units_t&
        non_const_non_default_sp<unit_p, capacity_p>::Units()
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const volatile typename non_const_non_default_sp<unit_p, capacity_p>::units_t&
        non_const_non_default_sp<unit_p, capacity_p>::Units()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        non_const_non_default_sp<unit_p, capacity_p>::Count()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        non_const_non_default_sp<unit_p, capacity_p>::Count()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        non_const_non_default_sp<unit_p, capacity_p>::Capacity()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        non_const_non_default_sp<unit_p, capacity_p>::Capacity()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_default_sp<unit_p, capacity_p>::const_default_sp() noexcept :
        units_or_bytes(typename units_or_bytes_u::default_units_t())
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_default_sp<unit_p, capacity_p>::const_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units_or_bytes(units...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_default_sp<unit_p, capacity_p>::const_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units_or_bytes(nkr::cpp::Move(units)...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_default_sp<unit_p, capacity_p>::const_default_sp(const const_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const_default_sp<unit_p, capacity_p>::const_default_sp(const volatile const_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_default_sp<unit_p, capacity_p>::const_default_sp(const_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const_default_sp<unit_p, capacity_p>::const_default_sp(volatile const_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr typename const_default_sp<unit_p, capacity_p>::units_t&
        const_default_sp<unit_p, capacity_p>::Units()
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const typename const_default_sp<unit_p, capacity_p>::units_t&
        const_default_sp<unit_p, capacity_p>::Units()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile typename const_default_sp<unit_p, capacity_p>::units_t&
        const_default_sp<unit_p, capacity_p>::Units()
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const volatile typename const_default_sp<unit_p, capacity_p>::units_t&
        const_default_sp<unit_p, capacity_p>::Units()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        const_default_sp<unit_p, capacity_p>::Count()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        const_default_sp<unit_p, capacity_p>::Count()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        const_default_sp<unit_p, capacity_p>::Capacity()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        const_default_sp<unit_p, capacity_p>::Capacity()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_non_default_sp<unit_p, capacity_p>::const_non_default_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units_or_bytes(units...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_non_default_sp<unit_p, capacity_p>::const_non_default_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units_or_bytes(nkr::cpp::Move(units)...)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_non_default_sp<unit_p, capacity_p>::const_non_default_sp(const const_non_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const_non_default_sp<unit_p, capacity_p>::const_non_default_sp(const volatile const_non_default_sp& other) noexcept :
        units_or_bytes(other.units_or_bytes)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const_non_default_sp<unit_p, capacity_p>::const_non_default_sp(const_non_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const_non_default_sp<unit_p, capacity_p>::const_non_default_sp(volatile const_non_default_sp&& other) noexcept :
        units_or_bytes(nkr::cpp::Move(other.units_or_bytes))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr typename const_non_default_sp<unit_p, capacity_p>::units_t&
        const_non_default_sp<unit_p, capacity_p>::Units()
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr const typename const_non_default_sp<unit_p, capacity_p>::units_t&
        const_non_default_sp<unit_p, capacity_p>::Units()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline volatile typename const_non_default_sp<unit_p, capacity_p>::units_t&
        const_non_default_sp<unit_p, capacity_p>::Units()
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline const volatile typename const_non_default_sp<unit_p, capacity_p>::units_t&
        const_non_default_sp<unit_p, capacity_p>::Units()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        const_non_default_sp<unit_p, capacity_p>::Count()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        const_non_default_sp<unit_p, capacity_p>::Count()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline constexpr nkr::positive::count_t
        const_non_default_sp<unit_p, capacity_p>::Capacity()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
    inline nkr::positive::count_t
        const_non_default_sp<unit_p, capacity_p>::Capacity()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

}}}}

#endif
