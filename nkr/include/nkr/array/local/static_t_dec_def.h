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
            using unit_t = typename self_t::unit_t;

            static_assert(tr<other_t, any_tg, t<self_t>>);

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {
                for (nkr::positive::index_t idx = 0, end = self.Capacity(); idx < end; idx += 1) {
                    self.Units()[idx].~unit_t();
                    self.Units()[idx] = other.Units()[idx];
                }
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

            static_assert(self_t::capacity_t::Value() == other_t::capacity_t::Value());

            if (nkr::cpp::Address(self) != nkr::cpp::Address(other)) {

            }

            return self;
        }

        static inline constexpr auto&
            Units(tr<any_tg, t<nkr::array::local::static_tg>> auto& self)
            noexcept
        {
            return self.units;
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

    /*
    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::Copy_Assign(is_any_non_const_tr<stack_t> auto& self,
                                                 const is_any_tr<stack_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            Clear(self);
            maybe_t<allocator_err> err = Capacity(self, other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    Writable_Array(self)[idx] = Array(other)[idx];
                }
                self.unit_count = other.unit_count;
            }

        }
        return self;
    }

    template <any_type_tr unit_p, count_t capacity_p>
    inline auto&
        stack_t<unit_p, capacity_p>::Move_Assign(is_any_non_const_tr<stack_t> auto& self,
                                                 is_any_non_const_tr<stack_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            Clear(self);
            maybe_t<allocator_err> err = Capacity(self, other.unit_count);
            if (!err) {
                for (index_t idx = 0, end = other.unit_count; idx < end; idx += 1) {
                    Writable_Array(self)[idx] = nkr::Move(Writable_Array(other)[idx]);
                }
                self.unit_count = nkr::Move(other.unit_count);
            }
        }
        return self;
    }
    */

}}}}

namespace nkr { namespace array { namespace local { namespace static_t$ {

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr non_const_sp<unit_p, capacity_p>::non_const_sp(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units{ units... }
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr non_const_sp<unit_p, capacity_p>::non_const_sp(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units{ nkr::cpp::Move(units)... }
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr non_const_sp<unit_p, capacity_p>::non_const_sp(const non_const_sp& other) noexcept :
        units(other.units)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline non_const_sp<unit_p, capacity_p>::non_const_sp(const volatile non_const_sp& other) noexcept :
        units(other.units)
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr non_const_sp<unit_p, capacity_p>::non_const_sp(non_const_sp&& other) noexcept :
        units(nkr::cpp::Move(other.units))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline non_const_sp<unit_p, capacity_p>::non_const_sp(volatile non_const_sp&& other) noexcept :
        units(nkr::cpp::Move(other.units))
    {
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(const non_const_sp& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline volatile non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(const non_const_sp& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(const volatile non_const_sp& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline volatile non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(const volatile non_const_sp& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, other);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(non_const_sp&& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline volatile non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(non_const_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(volatile non_const_sp&& other)
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline volatile non_const_sp<unit_p, capacity_p>&
        non_const_sp<unit_p, capacity_p>::operator =(volatile non_const_sp&& other)
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Assign(*this, nkr::cpp::Move(other));
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr typename non_const_sp<unit_p, capacity_p>::units_t&
        non_const_sp<unit_p, capacity_p>::Units()
        noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr const typename non_const_sp<unit_p, capacity_p>::units_t&
        non_const_sp<unit_p, capacity_p>::Units()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline volatile typename non_const_sp<unit_p, capacity_p>::units_t&
        non_const_sp<unit_p, capacity_p>::Units()
        volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline const volatile typename non_const_sp<unit_p, capacity_p>::units_t&
        non_const_sp<unit_p, capacity_p>::Units()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Units(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr nkr::positive::count_t
        non_const_sp<unit_p, capacity_p>::Count()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline nkr::positive::count_t
        non_const_sp<unit_p, capacity_p>::Count()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Count(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline constexpr nkr::positive::count_t
        non_const_sp<unit_p, capacity_p>::Capacity()
        const noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

    template <nkr::generic::type_tr unit_p, typename capacity_p>
        requires (tr<unit_p, any_non_const_tg>&& capacity_p::Value() > 0)
    inline nkr::positive::count_t
        non_const_sp<unit_p, capacity_p>::Capacity()
        const volatile noexcept
    {
        return nkr::array::local::static_t$::common_t::Capacity(*this);
    }

}}}}

namespace nkr { namespace array { namespace local {

    /*template <tr<any_const_tg, t<nkr::generic::type_tg>> unit_p, typename capacity_p>
    inline constexpr static_t<unit_p, capacity_p>::static_t(const tr<any_tg, t<unit_t>> auto& ...units) noexcept :
        units{ units... }
    {
    }

    template <tr<any_const_tg, t<nkr::generic::type_tg>> unit_p, typename capacity_p>
    inline constexpr static_t<unit_p, capacity_p>::static_t(tr<any_non_const_tg, t<unit_t>> auto&& ...units) noexcept :
        units{ nkr::cpp::Move(units)... }
    {
    }

    template <tr<any_const_tg, t<nkr::generic::type_tg>> unit_p, typename capacity_p>
    inline constexpr static_t<unit_p, capacity_p>::static_t(const static_t& other) noexcept :
        units(other.units)
    {
    }

    template <tr<any_const_tg, t<nkr::generic::type_tg>> unit_p, typename capacity_p>
    inline static_t<unit_p, capacity_p>::static_t(const volatile static_t& other) noexcept :
        units(other.units)
    {
    }

    template <tr<any_const_tg, t<nkr::generic::type_tg>> unit_p, typename capacity_p>
    inline constexpr static_t<unit_p, capacity_p>::static_t(static_t&& other) noexcept :
        units(nkr::cpp::Move(other.units))
    {
    }

    template <tr<any_const_tg, t<nkr::generic::type_tg>> unit_p, typename capacity_p>
    inline static_t<unit_p, capacity_p>::static_t(volatile static_t&& other) noexcept :
        units(nkr::cpp::Move(other.units))
    {
    }*/

}}}

#endif
