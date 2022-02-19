/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

#include "nkr/z_macros_def.h"
#include "nkr/z_utils.h"

#include "nkr/z_charcoder/utf_8_t_dec.h"
#include "nkr/z_charcoder/utf_32_t.h"

namespace nkr { namespace charcoder {

    /*
    Well-formed UTF-8 Subsequences:
        00..7F
        C2..DF  80..BF
        E0      A0..BF  80..BF
        E1..EC  80..BF  80..BF
        ED      80..9F  80..BF
        EE..EF  80..BF  80..BF
        F0      90..BF  80..BF  80..BF
        F1..F3  80..BF  80..BF  80..BF
        F4      80..8F  80..BF  80..BF
    */

    /*
    Ill-formed Truncated UTF-8 Subsequences:
        C2..DF
        E0
        E0      A0..BF
        E1..EC
        E1..EC  80..BF
        ED
        ED      80..9F
        EE..EF
        EE..EF  80..BF
        F0
        F0      90..BF
        F0      90..BF  80..BF
        F1..F3
        F1..F3  80..BF
        F1..F3  80..BF  80..BF
        F4
        F4      80..8F
        F4      80..8F  80..BF
    */

    /*
        Each invalid byte in an ill-formed UTF-8 sequence is replaced with a REPLACEMENT_CHARACTER
        except truncated UTF-8 subsequences, which are replaced with a single REPLACEMENT_CHARACTER.
        This holds true when reading a UTF-8 sequence backwards or forwards.

        See Unicode Standard: 3.9 Unicode Encoding Forms
    */

    inline constexpr point_t
        utf_8_t::Last_Point()
    {
        return utf_32_t::POINT_LAST;
    }

    inline constexpr point_t
        utf_8_t::Replacement_Point()
    {
        return utf_32_t::REPLACEMENT_CHARACTER;
    }

    inline constexpr count_t
        utf_8_t::Max_Unit_Count()
    {
        return 4;
    }

    inline auto&
        utf_8_t::Assign_Copy(is_any_non_const_tr<utf_8_t> auto& self, const is_any_tr<utf_8_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.units = other.units;
        }
        return self;
    }

    inline auto&
        utf_8_t::Assign_Move(is_any_non_const_tr<utf_8_t> auto& self, is_any_non_const_tr<utf_8_t> auto& other)
    {
        if (&self != std::addressof(other)) {
            self.units = nkr::Exchange(other.units, units_t{ unit_t(0) });
        }
        return self;
    }

    inline bool_t
        utf_8_t::Is_Well_Formed(const is_any_tr<utf_8_t> auto& self)
    {
        const count_t unit_count = self.units.Count();

        if (unit_count == 1) {
            if (self.units[0] >= 0x00 && self.units[0] <= 0x7F) {
                return true;
            } else {
                return false;
            }
        } else if (unit_count == 2) {
            if (self.units[0] >= 0xC2 && self.units[0] <= 0xDF &&
                self.units[1] >= 0x80 && self.units[1] <= 0xBF) {
                return true;
            } else {
                return false;
            }
        } else if (unit_count == 3) {
            if (self.units[0] == 0xE0 &&
                self.units[1] >= 0xA0 && self.units[1] <= 0xBF &&
                self.units[2] >= 0x80 && self.units[2] <= 0xBF) {
                return true;
            } else if (self.units[0] >= 0xE1 && self.units[0] <= 0xEC &&
                       self.units[1] >= 0x80 && self.units[1] <= 0xBF &&
                       self.units[2] >= 0x80 && self.units[2] <= 0xBF) {
                return true;
            } else if (self.units[0] == 0xED &&
                       self.units[1] >= 0x80 && self.units[1] <= 0x9F &&
                       self.units[2] >= 0x80 && self.units[2] <= 0xBF) {
                return true;
            } else if (self.units[0] >= 0xEE && self.units[0] <= 0xEF &&
                       self.units[1] >= 0x80 && self.units[1] <= 0xBF &&
                       self.units[2] >= 0x80 && self.units[2] <= 0xBF) {
                return true;
            } else {
                return false;
            }
        } else if (unit_count == 4) {
            if (self.units[0] == 0xF0 &&
                self.units[1] >= 0x90 && self.units[1] <= 0xBF &&
                self.units[2] >= 0x80 && self.units[2] <= 0xBF &&
                self.units[3] >= 0x80 && self.units[3] <= 0xBF) {
                return true;
            } else if (self.units[0] >= 0xF1 && self.units[0] <= 0xF3 &&
                       self.units[1] >= 0x80 && self.units[1] <= 0xBF &&
                       self.units[2] >= 0x80 && self.units[2] <= 0xBF &&
                       self.units[3] >= 0x80 && self.units[3] <= 0xBF) {
                return true;
            } else if (self.units[0] == 0xF4 &&
                       self.units[1] >= 0x80 && self.units[1] <= 0x8F &&
                       self.units[2] >= 0x80 && self.units[2] <= 0xBF &&
                       self.units[3] >= 0x80 && self.units[3] <= 0xBF) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    inline void_t
        utf_8_t::Encode(is_any_non_const_tr<utf_8_t> auto& self, point_t point)
    {
        self.units.Clear();

        if (utf_32_t::Is_Scalar(point)) {
            if (point <= 0x7F) {
                self.units = {
                    unit_t(point),
                };
            } else if (point <= 0x7FF) {
                self.units = {
                    unit_t(((point >> 6) & 0x1F) | 0xC0),
                    unit_t((point & 0x3F) | 0x80),
                };
            } else if (point <= 0xFFFF) {
                self.units = {
                    unit_t(((point >> 12) & 0x0F) | 0xE0),
                    unit_t(((point >> 6) & 0x3F) | 0x80),
                    unit_t((point & 0x3F) | 0x80),
                };
            } else {
                self.units = {
                    unit_t(((point >> 18) & 0x07) | 0xF0),
                    unit_t(((point >> 12) & 0x3F) | 0x80),
                    unit_t(((point >> 6) & 0x3F) | 0x80),
                    unit_t((point & 0x3F) | 0x80),
                };
            }
        } else {
            self.units = {
                unit_t(0xEF),
                unit_t(0xBF),
                unit_t(0xBD),
            };
        }

        nkr_ASSERT_THAT(Is_Well_Formed(self));
    }

    inline point_t
        utf_8_t::Decode(const is_any_tr<utf_8_t> auto& self)
    {
        nkr_ASSERT_THAT(Is_Well_Formed(self));

        const count_t unit_count = self.units.Count();

        if (unit_count == 1) {
            return
                u32_t(self.units[0]);
        } else if (unit_count == 2) {
            return
                ((u32_t(self.units[0]) & 0x1F) << 6) |
                (u32_t(self.units[1]) & 0x3F);
        } else if (unit_count == 3) {
            return
                ((u32_t(self.units[0]) & 0x0F) << 12) |
                ((u32_t(self.units[1]) & 0x3F) << 6) |
                (u32_t(self.units[2]) & 0x3F);
        } else {
            return
                ((u32_t(self.units[0]) & 0x07) << 18) |
                ((u32_t(self.units[1]) & 0x3F) << 12) |
                ((u32_t(self.units[2]) & 0x3F) << 6) |
                (u32_t(self.units[3]) & 0x3F);
        }
    }

    inline count_t
        utf_8_t::Read_Forward(is_any_non_const_tr<utf_8_t> auto& self, const is_any_tr<unit_t> auto* from)
    {
        nkr_ASSERT_THAT(from);

        auto& raw_units = self.units.Array();

        if (*(from + 0) >= 0x00 && *(from + 0) <= 0x7F) {
            raw_units[0] = *(from + 0);
            self.units.Count(1).Ignore_Error();
            return 1;
        } else if (*(from + 0) >= 0xC2 && *(from + 0) <= 0xDF &&
                   *(from + 1) >= 0x80 && *(from + 1) <= 0xBF) {
            raw_units[0] = *(from + 0);
            raw_units[1] = *(from + 1);
            self.units.Count(2).Ignore_Error();
            return 2;
        } else if (*(from + 0) == 0xE0 &&
                   *(from + 1) >= 0xA0 && *(from + 1) <= 0xBF &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF ||

                   *(from + 0) >= 0xE1 && *(from + 0) <= 0xEC &&
                   *(from + 1) >= 0x80 && *(from + 1) <= 0xBF &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF ||

                   *(from + 0) == 0xED &&
                   *(from + 1) >= 0x80 && *(from + 1) <= 0x9F &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF ||

                   *(from + 0) >= 0xEE && *(from + 0) <= 0xEF &&
                   *(from + 1) >= 0x80 && *(from + 1) <= 0xBF &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
            raw_units[0] = *(from + 0);
            raw_units[1] = *(from + 1);
            raw_units[2] = *(from + 2);
            self.units.Count(3).Ignore_Error();
            return 3;
        } else if (*(from + 0) == 0xF0 &&
                   *(from + 1) >= 0x90 && *(from + 1) <= 0xBF &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF &&
                   *(from + 3) >= 0x80 && *(from + 3) <= 0xBF ||

                   *(from + 0) >= 0xF1 && *(from + 0) <= 0xF3 &&
                   *(from + 1) >= 0x80 && *(from + 1) <= 0xBF &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF &&
                   *(from + 3) >= 0x80 && *(from + 3) <= 0xBF ||

                   *(from + 0) == 0xF4 &&
                   *(from + 1) >= 0x80 && *(from + 1) <= 0x8F &&
                   *(from + 2) >= 0x80 && *(from + 2) <= 0xBF &&
                   *(from + 3) >= 0x80 && *(from + 3) <= 0xBF) {
            raw_units[0] = *(from + 0);
            raw_units[1] = *(from + 1);
            raw_units[2] = *(from + 2);
            raw_units[3] = *(from + 3);
            self.units.Count(4).Ignore_Error();
            return 4;
        } else {
            if (*(from + 0) == 0xF0 &&
                *(from + 1) >= 0x90 && *(from + 1) <= 0xBF &&
                *(from + 2) >= 0x80 && *(from + 2) <= 0xBF ||

                *(from + 0) >= 0xF1 && *(from + 0) <= 0xF3 &&
                *(from + 1) >= 0x80 && *(from + 1) <= 0xBF &&
                *(from + 2) >= 0x80 && *(from + 2) <= 0xBF ||

                *(from + 0) == 0xF4 &&
                *(from + 1) >= 0x80 && *(from + 1) <= 0x8F &&
                *(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                raw_units[0] = unit_t(0xEF);
                raw_units[1] = unit_t(0xBF);
                raw_units[2] = unit_t(0xBD);
                self.units.Count(3).Ignore_Error();
                return 3;
            } else if (*(from + 0) >= 0xE0 &&
                       *(from + 1) >= 0xA0 && *(from + 1) <= 0xBF ||

                       *(from + 0) >= 0xE1 && *(from + 0) <= 0xEC &&
                       *(from + 1) >= 0x80 && *(from + 1) <= 0xBF ||

                       *(from + 0) >= 0xED &&
                       *(from + 1) >= 0x80 && *(from + 1) <= 0x9F ||

                       *(from + 0) >= 0xEE && *(from + 0) <= 0xEF &&
                       *(from + 1) >= 0x80 && *(from + 1) <= 0xBF ||

                       *(from + 0) >= 0xF0 &&
                       *(from + 1) >= 0x90 && *(from + 1) <= 0xBF ||

                       *(from + 0) >= 0xF1 && *(from + 0) <= 0xF3 &&
                       *(from + 1) >= 0x80 && *(from + 1) <= 0xBF ||

                       *(from + 0) >= 0xF4 &&
                       *(from + 1) >= 0x80 && *(from + 1) <= 0x8F) {
                raw_units[0] = unit_t(0xEF);
                raw_units[1] = unit_t(0xBF);
                raw_units[2] = unit_t(0xBD);
                self.units.Count(3).Ignore_Error();
                return 2;
            } else {
                raw_units[0] = unit_t(0xEF);
                raw_units[1] = unit_t(0xBF);
                raw_units[2] = unit_t(0xBD);
                self.units.Count(3).Ignore_Error();
                return 1;
            }
        }
    }

    inline count_t
        utf_8_t::Read_Reverse(is_any_non_const_tr<utf_8_t> auto& self, const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first)
    {
        nkr_ASSERT_THAT(from);
        nkr_ASSERT_THAT(first);
        nkr_ASSERT_THAT(from > first);

        auto& raw_units = self.units.Array();

        if (*(from - 1) >= 0x00 && *(from - 1) <= 0x7F) {
            raw_units[0] = *(from - 1);
            self.units.Count(1).Ignore_Error();
            return 1;
        } else if (from - first >= 2 &&

                   (*(from - 2) >= 0xC2 && *(from - 2) <= 0xDF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF)) {
            raw_units[0] = *(from - 2);
            raw_units[1] = *(from - 1);
            self.units.Count(2).Ignore_Error();
            return 2;
        } else if (from - first >= 3 &&

                   (*(from - 3) == 0xE0 &&
                    *(from - 2) >= 0xA0 && *(from - 2) <= 0xBF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                    *(from - 3) >= 0xE1 && *(from - 3) <= 0xEC &&
                    *(from - 2) >= 0x80 && *(from - 2) <= 0xBF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                    *(from - 3) == 0xED &&
                    *(from - 2) >= 0x80 && *(from - 2) <= 0x9F &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                    *(from - 3) >= 0xEE && *(from - 3) <= 0xEF &&
                    *(from - 2) >= 0x80 && *(from - 2) <= 0xBF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF)) {
            raw_units[0] = *(from - 3);
            raw_units[1] = *(from - 2);
            raw_units[2] = *(from - 1);
            self.units.Count(3).Ignore_Error();
            return 3;
        } else if (from - first >= 4 &&

                   (*(from - 4) == 0xF0 &&
                    *(from - 3) >= 0x90 && *(from - 3) <= 0xBF &&
                    *(from - 2) >= 0x80 && *(from - 2) <= 0xBF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                    *(from - 4) >= 0xF1 && *(from - 4) <= 0xF3 &&
                    *(from - 3) >= 0x80 && *(from - 3) <= 0xBF &&
                    *(from - 2) >= 0x80 && *(from - 2) <= 0xBF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                    *(from - 4) == 0xF4 &&
                    *(from - 3) >= 0x80 && *(from - 3) <= 0x8F &&
                    *(from - 2) >= 0x80 && *(from - 2) <= 0xBF &&
                    *(from - 1) >= 0x80 && *(from - 1) <= 0xBF)) {
            raw_units[0] = *(from - 4);
            raw_units[1] = *(from - 3);
            raw_units[2] = *(from - 2);
            raw_units[3] = *(from - 1);
            self.units.Count(4).Ignore_Error();
            return 4;
        } else {
            if (from - first >= 3 &&

                (*(from - 3) == 0xF0 &&
                 *(from - 2) >= 0x90 && *(from - 2) <= 0xBF &&
                 *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                 *(from - 3) >= 0xF1 && *(from - 3) <= 0xF3 &&
                 *(from - 2) >= 0x80 && *(from - 2) <= 0xBF &&
                 *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                 *(from - 3) == 0xF4 &&
                 *(from - 2) >= 0x80 && *(from - 2) <= 0x8F &&
                 *(from - 1) >= 0x80 && *(from - 1) <= 0xBF)) {
                raw_units[0] = unit_t(0xEF);
                raw_units[1] = unit_t(0xBF);
                raw_units[2] = unit_t(0xBD);
                self.units.Count(3).Ignore_Error();
                return 3;
            } else if (from - first >= 2 &&

                       (*(from - 2) >= 0xE0 &&
                        *(from - 1) >= 0xA0 && *(from - 1) <= 0xBF ||

                        *(from - 2) >= 0xE1 && *(from - 2) <= 0xEC &&
                        *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                        *(from - 2) >= 0xED &&
                        *(from - 1) >= 0x80 && *(from - 1) <= 0x9F ||

                        *(from - 2) >= 0xEE && *(from - 2) <= 0xEF &&
                        *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                        *(from - 2) >= 0xF0 &&
                        *(from - 1) >= 0x90 && *(from - 1) <= 0xBF ||

                        *(from - 2) >= 0xF1 && *(from - 2) <= 0xF3 &&
                        *(from - 1) >= 0x80 && *(from - 1) <= 0xBF ||

                        *(from - 2) >= 0xF4 &&
                        *(from - 1) >= 0x80 && *(from - 1) <= 0x8F)) {
                raw_units[0] = unit_t(0xEF);
                raw_units[1] = unit_t(0xBF);
                raw_units[2] = unit_t(0xBD);
                self.units.Count(3).Ignore_Error();
                return 2;
            } else {
                raw_units[0] = unit_t(0xEF);
                raw_units[1] = unit_t(0xBF);
                raw_units[2] = unit_t(0xBD);
                self.units.Count(3).Ignore_Error();
                return 1;
            }
        }
    }

    inline count_t
        utf_8_t::Unit_Count(const is_any_tr<utf_8_t> auto& self)
    {
        return self.units.Count();
    }

    inline typename utf_8_t::unit_t
        utf_8_t::Unit(const is_any_tr<utf_8_t> auto& self, index_t unit_index)
    {
        nkr_ASSERT_THAT(unit_index < self.units.Count());

        return self.units[unit_index];
    }

    inline auto&
        utf_8_t::Assign_None(is_any_non_const_tr<utf_8_t> auto& self)
    {
        self.units = {
            unit_t(0),
        };

        return self;
    }

    inline bool_t
        utf_8_t::Is_Equal_To_None(const is_any_tr<utf_8_t> auto& self)
    {
        return self.units.Count() == 1 && self.units[0] == 0;
    }

    inline utf_8_t::utf_8_t() :
        units{ unit_t(0) }
    {
    }

    inline utf_8_t::utf_8_t(point_t point) :
        utf_8_t()
    {
        Encode(*this, point);
    }

    inline utf_8_t::utf_8_t(const utf_8_t& other) :
        units(other.units)
    {
    }

    inline utf_8_t::utf_8_t(const volatile utf_8_t& other) :
        units(other.units)
    {
    }

    inline utf_8_t::utf_8_t(utf_8_t&& other) noexcept :
        units(nkr::Exchange(other.units, units_t{ unit_t(0) }))
    {
    }

    inline utf_8_t::utf_8_t(volatile utf_8_t&& other) noexcept :
        units(nkr::Exchange(other.units, units_t{ unit_t(0) }))
    {
    }

    inline utf_8_t&
        utf_8_t::operator =(const utf_8_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(const utf_8_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline utf_8_t&
        utf_8_t::operator =(const volatile utf_8_t& other)
    {
        return Assign_Copy(*this, other);
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(const volatile utf_8_t& other)
        volatile
    {
        return Assign_Copy(*this, other);
    }

    inline utf_8_t&
        utf_8_t::operator =(utf_8_t&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(utf_8_t&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline utf_8_t&
        utf_8_t::operator =(is_just_volatile_tr<utf_8_t> auto&& other)
        noexcept
    {
        return Assign_Move(*this, other);
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(is_just_volatile_tr<utf_8_t> auto&& other)
        volatile noexcept
    {
        return Assign_Move(*this, other);
    }

    inline bool_t
        utf_8_t::Is_Well_Formed()
        const
    {
        return Is_Well_Formed(*this);
    }

    inline bool_t
        utf_8_t::Is_Well_Formed()
        const volatile
    {
        return Is_Well_Formed(*this);
    }

    inline void_t
        utf_8_t::Encode(point_t point)
    {
        return Encode(*this, point);
    }

    inline void_t
        utf_8_t::Encode(point_t point)
        volatile
    {
        return Encode(*this, point);
    }

    inline point_t
        utf_8_t::Decode()
        const
    {
        return Decode(*this);
    }

    inline point_t
        utf_8_t::Decode()
        const volatile
    {
        return Decode(*this);
    }

    inline count_t
        utf_8_t::Read_Forward(const is_any_tr<unit_t> auto* from)
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_8_t::Read_Forward(const is_any_tr<unit_t> auto* from)
        volatile
    {
        return Read_Forward(*this, from);
    }

    inline count_t
        utf_8_t::Read_Reverse(const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first)
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        utf_8_t::Read_Reverse(const is_any_tr<unit_t> auto* from, const is_any_tr<unit_t> auto* first)
        volatile
    {
        return Read_Reverse(*this, from, first);
    }

    inline count_t
        utf_8_t::Unit_Count()
        const
    {
        return Unit_Count(*this);
    }

    inline count_t
        utf_8_t::Unit_Count()
        const volatile
    {
        return Unit_Count(*this);
    }

    inline typename utf_8_t::unit_t
        utf_8_t::Unit(index_t unit_index)
        const
    {
        return Unit(*this, unit_index);
    }

    inline typename utf_8_t::unit_t
        utf_8_t::Unit(index_t unit_index)
        const volatile
    {
        return Unit(*this, unit_index);
    }

    inline typename utf_8_t::unit_t
        utf_8_t::operator [](index_t unit_index)
        const
    {
        return Unit(*this, unit_index);
    }

    inline typename utf_8_t::unit_t
        utf_8_t::operator [](index_t unit_index)
        const volatile
    {
        return Unit(*this, unit_index);
    }

    inline utf_8_t::utf_8_t(none_t) :
        utf_8_t()
    {
    }

    inline utf_8_t&
        utf_8_t::operator =(none_t)
    {
        return Assign_None(*this);
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(none_t)
        volatile
    {
        return Assign_None(*this);
    }

    inline bool_t
        utf_8_t::operator ==(none_t)
        const
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_8_t::operator ==(none_t)
        const volatile
    {
        return Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_8_t::operator !=(none_t)
        const
    {
        return !Is_Equal_To_None(*this);
    }

    inline bool_t
        utf_8_t::operator !=(none_t)
        const volatile
    {
        return !Is_Equal_To_None(*this);
    }

}}
