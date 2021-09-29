/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/utils.h"

#include "nkr/charcoder/utf_8_t_dec.h"
#include "nkr/charcoder/utf_32_t.h"

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
    */

    inline utf_8_t::utf_8_t()
    {
        this->unit_count = 1;
        this->units[0] = 0;
        this->units[1] = 0;
        this->units[2] = 0;
        this->units[3] = 0;
    }

    inline utf_8_t::utf_8_t(const utf_8_t& other)
    {
        this->unit_count = other.unit_count;
        this->units[0] = other.units[0];
        this->units[1] = other.units[1];
        this->units[2] = other.units[2];
        this->units[3] = other.units[3];
    }

    inline utf_8_t::utf_8_t(const volatile utf_8_t& other)
    {
        this->unit_count = other.unit_count;
        this->units[0] = other.units[0];
        this->units[1] = other.units[1];
        this->units[2] = other.units[2];
        this->units[3] = other.units[3];
    }

    inline utf_8_t::utf_8_t(utf_8_t&& other) noexcept
    {
        this->unit_count = nkr::Exchange(other.unit_count, 1);
        this->units[0] = nkr::Move(other.units[0]);
        this->units[1] = nkr::Move(other.units[1]);
        this->units[2] = nkr::Move(other.units[2]);
        this->units[3] = nkr::Move(other.units[3]);
    }

    inline utf_8_t::utf_8_t(volatile utf_8_t&& other) noexcept
    {
        this->unit_count = nkr::Exchange(other.unit_count, 1);
        this->units[0] = nkr::Move(other.units[0]);
        this->units[1] = nkr::Move(other.units[1]);
        this->units[2] = nkr::Move(other.units[2]);
        this->units[3] = nkr::Move(other.units[3]);
    }

    inline utf_8_t&
        utf_8_t::operator =(const utf_8_t& other)
    {
        if (this != std::addressof(other)) {
            this->unit_count = other.unit_count;
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->units[2] = other.units[2];
            this->units[3] = other.units[3];
        }
        return *this;
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(const utf_8_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->unit_count = other.unit_count;
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->units[2] = other.units[2];
            this->units[3] = other.units[3];
        }
        return *this;
    }

    inline utf_8_t&
        utf_8_t::operator =(const volatile utf_8_t& other)
    {
        if (this != std::addressof(other)) {
            this->unit_count = other.unit_count;
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->units[2] = other.units[2];
            this->units[3] = other.units[3];
        }
        return *this;
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(const volatile utf_8_t& other)
        volatile
    {
        if (this != std::addressof(other)) {
            this->unit_count = other.unit_count;
            this->units[0] = other.units[0];
            this->units[1] = other.units[1];
            this->units[2] = other.units[2];
            this->units[3] = other.units[3];
        }
        return *this;
    }

    inline utf_8_t&
        utf_8_t::operator =(utf_8_t&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->unit_count = nkr::Exchange(other.unit_count, 1);
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->units[2] = nkr::Move(other.units[2]);
            this->units[3] = nkr::Move(other.units[3]);
        }
        return *this;
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(utf_8_t&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->unit_count = nkr::Exchange(other.unit_count, 1);
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->units[2] = nkr::Move(other.units[2]);
            this->units[3] = nkr::Move(other.units[3]);
        }
        return *this;
    }

    inline utf_8_t&
        utf_8_t::operator =(is_just_volatile_tr<utf_8_t> auto&& other)
        noexcept
    {
        if (this != std::addressof(other)) {
            this->unit_count = nkr::Exchange(other.unit_count, 1);
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->units[2] = nkr::Move(other.units[2]);
            this->units[3] = nkr::Move(other.units[3]);
        }
        return *this;
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(is_just_volatile_tr<utf_8_t> auto&& other)
        volatile noexcept
    {
        if (this != std::addressof(other)) {
            this->unit_count = nkr::Exchange(other.unit_count, 1);
            this->units[0] = nkr::Move(other.units[0]);
            this->units[1] = nkr::Move(other.units[1]);
            this->units[2] = nkr::Move(other.units[2]);
            this->units[3] = nkr::Move(other.units[3]);
        }
        return *this;
    }

    inline utf_8_t::~utf_8_t()
    {
        this->unit_count = 1;
        this->units[0] = 0;
        this->units[1] = 0;
        this->units[2] = 0;
        this->units[3] = 0;
    }

    inline bool_t
        utf_8_t::Is_Well_Formed()
        const
    {
        if (this->unit_count == 1) {
            if (this->units[0] >= 0x00 && this->units[0] <= 0x7F) {
                return true;
            } else {
                return false;
            }
        } else if (this->unit_count == 2) {
            if (this->units[0] >= 0xC2 && this->units[0] <= 0xDF &&
                this->units[1] >= 0x80 && this->units[1] <= 0xBF) {
                return true;
            } else {
                return false;
            }
        } else if (this->unit_count == 3) {
            if (this->units[0] == 0xE0 &&
                this->units[1] >= 0xA0 && this->units[1] <= 0xBF &&
                this->units[2] >= 0x80 && this->units[2] <= 0xBF) {
                return true;
            } else if (this->units[0] >= 0xE1 && this->units[0] <= 0xEC &&
                       this->units[1] >= 0x80 && this->units[1] <= 0xBF &&
                       this->units[2] >= 0x80 && this->units[2] <= 0xBF) {
                return true;
            } else if (this->units[0] == 0xED &&
                       this->units[1] >= 0x80 && this->units[1] <= 0x9F &&
                       this->units[2] >= 0x80 && this->units[2] <= 0xBF) {
                return true;
            } else if (this->units[0] >= 0xEE && this->units[0] <= 0xEF &&
                       this->units[1] >= 0x80 && this->units[1] <= 0xBF &&
                       this->units[2] >= 0x80 && this->units[2] <= 0xBF) {
                return true;
            } else {
                return false;
            }
        } else if (this->unit_count == 4) {
            if (this->units[0] == 0xF0 &&
                this->units[1] >= 0x90 && this->units[1] <= 0xBF &&
                this->units[2] >= 0x80 && this->units[2] <= 0xBF &&
                this->units[3] >= 0x80 && this->units[3] <= 0xBF) {
                return true;
            } else if (this->units[0] >= 0xF1 && this->units[0] <= 0xF3 &&
                       this->units[1] >= 0x80 && this->units[1] <= 0xBF &&
                       this->units[2] >= 0x80 && this->units[2] <= 0xBF &&
                       this->units[3] >= 0x80 && this->units[3] <= 0xBF) {
                return true;
            } else if (this->units[0] == 0xF4 &&
                       this->units[1] >= 0x80 && this->units[1] <= 0x8F &&
                       this->units[2] >= 0x80 && this->units[2] <= 0xBF &&
                       this->units[3] >= 0x80 && this->units[3] <= 0xBF) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    inline void_t
        utf_8_t::Encode(point_t point)
    {
        if (utf_32_t::Is_Scalar(point)) {
            if (point <= 0x7F) {
                this->units[0] = static_cast<unit_t>(point);
                this->unit_count = 1;
            } else if (point <= 0x7FF) {
                this->units[0] = static_cast<unit_t>(((point >> 6) & 0x1F) | 0xC0);
                this->units[1] = static_cast<unit_t>((point & 0x3F) | 0x80);
                this->unit_count = 2;
            } else if (point <= 0xFFFF) {
                this->units[0] = static_cast<unit_t>(((point >> 12) & 0x0F) | 0xE0);
                this->units[1] = static_cast<unit_t>(((point >> 6) & 0x3F) | 0x80);
                this->units[2] = static_cast<unit_t>((point & 0x3F) | 0x80);
                this->unit_count = 3;
            } else {
                this->units[0] = static_cast<unit_t>(((point >> 18) & 0x07) | 0xF0);
                this->units[1] = static_cast<unit_t>(((point >> 12) & 0x3F) | 0x80);
                this->units[2] = static_cast<unit_t>(((point >> 6) & 0x3F) | 0x80);
                this->units[3] = static_cast<unit_t>((point & 0x3F) | 0x80);
                this->unit_count = 4;
            }
        } else {
            this->units[0] = 0xEF;
            this->units[1] = 0xBF;
            this->units[2] = 0xBD;
            this->unit_count = 3;
        }

        assert(Is_Well_Formed());
    }

    inline point_t
        utf_8_t::Decode()
        const
    {
        assert(Is_Well_Formed());

        if (this->unit_count == 1) {
            return
                static_cast<u32_t>(this->units[0]);
        } else if (this->unit_count == 2) {
            return
                ((static_cast<u32_t>(this->units[0]) & 0x1F) << 6) |
                (static_cast<u32_t>(this->units[1]) & 0x3F);
        } else if (this->unit_count == 3) {
            return
                ((static_cast<u32_t>(this->units[0]) & 0x0F) << 12) |
                ((static_cast<u32_t>(this->units[1]) & 0x3F) << 6) |
                (static_cast<u32_t>(this->units[2]) & 0x3F);
        } else {
            return
                ((static_cast<u32_t>(this->units[0]) & 0x07) << 18) |
                ((static_cast<u32_t>(this->units[1]) & 0x3F) << 12) |
                ((static_cast<u32_t>(this->units[2]) & 0x3F) << 6) |
                (static_cast<u32_t>(this->units[3]) & 0x3F);
        }
    }

    inline count_t
        utf_8_t::Read_Forward(const unit_t* from)
    {
        assert(from);

    #define read_1()                    \
    {                                   \
        this->units[0] = *(from + 0);   \
        this->unit_count = 1;           \
                                        \
        return 1;                       \
    }

    #define read_2()                    \
    {                                   \
        this->units[0] = *(from + 0);   \
        this->units[1] = *(from + 1);   \
        this->unit_count = 2;           \
                                        \
        return 2;                       \
    }

    #define read_3()                    \
    {                                   \
        this->units[0] = *(from + 0);   \
        this->units[1] = *(from + 1);   \
        this->units[2] = *(from + 2);   \
        this->unit_count = 3;           \
                                        \
        return 3;                       \
    }

    #define read_4()                    \
    {                                   \
        this->units[0] = *(from + 0);   \
        this->units[1] = *(from + 1);   \
        this->units[2] = *(from + 2);   \
        this->units[3] = *(from + 3);   \
        this->unit_count = 4;           \
                                        \
        return 4;                       \
    }

    #define replace(READ_UNIT_COUNT_p)  \
    {                                   \
        this->units[0] = 0xEF;          \
        this->units[1] = 0xBF;          \
        this->units[2] = 0xBD;          \
        this->unit_count = 3;           \
                                        \
        return READ_UNIT_COUNT_p;       \
    }

        if (*(from + 0) >= 0x00 && *(from + 0) <= 0x7F) {
            read_1();
        } else if (*(from + 0) >= 0xC2 && *(from + 0) <= 0xDF) {
            if (*(from + 1) >= 0x80 && *(from + 1) <= 0xBF) {
                read_2();
            } else {
                replace(1);
            }
        } else if (*(from + 0) == 0xE0) {
            if (*(from + 1) >= 0xA0 && *(from + 1) <= 0xBF) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    read_3();
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else if (*(from + 0) >= 0xE1 && *(from + 0) <= 0xEC) {
            if (*(from + 1) >= 0x80 && *(from + 1) <= 0xBF) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    read_3();
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else if (*(from + 0) == 0xED) {
            if (*(from + 1) >= 0x80 && *(from + 1) <= 0x9F) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    read_3();
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else if (*(from + 0) >= 0xEE && *(from + 0) <= 0xEF) {
            if (*(from + 1) >= 0x80 && *(from + 1) <= 0xBF) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    read_3();
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else if (*(from + 0) == 0xF0) {
            if (*(from + 1) >= 0x90 && *(from + 1) <= 0xBF) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    if (*(from + 3) >= 0x80 && *(from + 3) <= 0xBF) {
                        read_4();
                    } else {
                        replace(3);
                    }
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else if (*(from + 0) >= 0xF1 && *(from + 0) <= 0xF3) {
            if (*(from + 1) >= 0x80 && *(from + 1) <= 0xBF) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    if (*(from + 3) >= 0x80 && *(from + 3) <= 0xBF) {
                        read_4();
                    } else {
                        replace(3);
                    }
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else if (*(from + 0) == 0xF4) {
            if (*(from + 1) >= 0x80 && *(from + 1) <= 0x8F) {
                if (*(from + 2) >= 0x80 && *(from + 2) <= 0xBF) {
                    if (*(from + 3) >= 0x80 && *(from + 3) <= 0xBF) {
                        read_4();
                    } else {
                        replace(3);
                    }
                } else {
                    replace(2);
                }
            } else {
                replace(1);
            }
        } else {
            replace(1);
        }

    #undef read_1
    #undef read_2
    #undef read_3
    #undef read_4
    #undef replace
    }

    inline count_t
        utf_8_t::Read_Reverse(const unit_t* from, const unit_t* first)
    {
        assert(from);
        assert(first);
        assert(from > first);

    #define read_1()                    \
    {                                   \
        this->units[0] = *(from - 1);   \
        this->unit_count = 1;           \
                                        \
        return 1;                       \
    }

    #define read_2()                    \
    {                                   \
        this->units[0] = *(from - 2);   \
        this->units[1] = *(from - 1);   \
        this->unit_count = 2;           \
                                        \
        return 2;                       \
    }

    #define read_3()                    \
    {                                   \
        this->units[0] = *(from - 3);   \
        this->units[1] = *(from - 2);   \
        this->units[2] = *(from - 1);   \
        this->unit_count = 3;           \
                                        \
        return 3;                       \
    }

    #define read_4()                    \
    {                                   \
        this->units[0] = *(from - 4);   \
        this->units[1] = *(from - 3);   \
        this->units[2] = *(from - 2);   \
        this->units[3] = *(from - 1);   \
        this->unit_count = 4;           \
                                        \
        return 4;                       \
    }

    #define replace(READ_UNIT_COUNT_p)  \
    {                                   \
        this->units[0] = 0xEF;          \
        this->units[1] = 0xBF;          \
        this->units[2] = 0xBD;          \
        this->unit_count = 3;           \
                                        \
        return READ_UNIT_COUNT_p;       \
    }

        if (*(from - 1) >= 0x00 && *(from - 1) <= 0x7F) {
            read_1(); // w[00..7F]
        } else if (*(from - 1) >= 0x80 && *(from - 1) <= 0xBF) {
            if (from - 2 >= first) {
                if (*(from - 2) >= 0xC2 && *(from - 2) <= 0xDF) {
                    read_2(); // w[C2..DF, 80..BF]
                } else if (*(from - 2) >= 0xA0 && *(from - 2) <= 0xBF) {
                    if (from - 3 >= first) {
                        if (*(from - 3) == 0xE0) {
                            read_3(); // w[E0, A0..BF, 80..BF]
                        }
                    }
                } else if (*(from - 2) >= 0x80 && *(from - 2) <= 0xBF) {
                    if (from - 3 >= first) {
                        if (*(from - 3) >= 0xE1 && *(from - 3) <= 0xEC) {
                            read_3(); // w[E1..EC, 80..BF, 80..BF]
                        } else if (*(from - 3) >= 0xEE && *(from - 3) <= 0xEF) {
                            read_3(); // w[EE..EF, 80..BF, 80..BF]
                        } else if (*(from - 3) >= 0x90 && *(from - 3) <= 0xBF) {
                            if (from - 4 >= first) {
                                if (*(from - 4) == 0xF0) {
                                    read_4(); // w[F0, 90..BF, 80..BF, 80..BF]
                                }
                            }
                        } else if (*(from - 3) >= 0x80 && *(from - 3) <= 0xBF) {
                            if (from - 4 >= first) {
                                if (*(from - 4) >= 0xF1 && *(from - 4) <= 0xF3) {
                                    read_4(); // w[F1..F3, 80..BF, 80..BF, 80..BF]
                                }
                            }
                        } else if (*(from - 3) >= 0x80 && *(from - 3) <= 0x8F) {
                            if (from - 4 >= first) {
                                if (*(from - 4) == 0xF4) {
                                    read_4(); // w[F4, 80..8F, 80..BF, 80..BF]
                                }
                            }
                        } else if (*(from - 3) >= 0xF1 && *(from - 3) <= 0xF3) {
                            replace(3); // i[F1..F3, 80..BF, 80..BF]
                        }
                    }
                } else if (*(from - 2) >= 0x80 && *(from - 2) <= 0x9F) {
                    if (from - 3 >= first) {
                        if (*(from - 3) == 0xED) {
                            read_3(); // w[ED, 80..9F, 80..BF]
                        }
                    }
                } else if (*(from - 2) >= 0xE1 && *(from - 2) <= 0xEC) {
                    replace(2); // i[E1..EC, 80..BF]
                } else if (*(from - 2) >= 0xEE && *(from - 2) <= 0xEF) {
                    replace(2); // i[EE..EF, 80..BF]
                } else if (*(from - 2) >= 0xF1 && *(from - 2) <= 0xF3) {
                    replace(2); // i[F1..F3, 80..BF]
                } else if (*(from - 2) >= 0x90 && *(from - 2) <= 0xBF) {
                    if (from - 3 >= first) {
                        if (*(from - 3) == 0xF0) {
                            replace(3); // i[F0, 90..BF, 80..BF]
                        }
                    }
                } else if (*(from - 2) >= 0x80 && *(from - 2) <= 0x8F) {
                    if (from - 3 >= first) {
                        if (*(from - 3) == 0xF4) {
                            replace(3); // i[F4, 80..8F, 80..BF]
                        }
                    }
                }
            }
        } else if (*(from - 1) >= 0xA0 && *(from - 1) <= 0xBF) {
            if (from - 2 >= first) {
                if (*(from - 2) == 0xE0) {
                    replace(2); // i[E0, A0..BF]
                }
            }
        } else if (*(from - 1) >= 0x80 && *(from - 1) <= 0x9F) {
            if (from - 2 >= first) {
                if (*(from - 2) == 0xED) {
                    replace(2); // i[ED, 80..9F]
                }
            }
        } else if (*(from - 1) >= 0x90 && *(from - 1) <= 0xBF) {
            if (from - 2 >= first) {
                if (*(from - 2) == 0xF0) {
                    replace(2); // i[F0, 90..BF]
                }
            }
        } else if (*(from - 1) >= 0x80 && *(from - 1) <= 0x8F) {
            if (from - 2 >= first) {
                if (*(from - 2) == 0xF4) {
                    replace(2); // i[F4, 80..8F]
                }
            }
        } else {
            replace(1); // i[C2..DF], i[E0], i[E1..EC], i[ED], i[EE..EF], i[F0], i[F1..F3], i[F4], i[.]
        }

        replace(1); // i[.]

    #undef read_1
    #undef read_2
    #undef read_3
    #undef read_4
    #undef replace
    }

    inline count_t
        utf_8_t::Unit_Count()
        const
    {
        return this->unit_count;
    }

    inline typename utf_8_t::unit_t
        utf_8_t::operator [](index_t index)
        const
    {
        assert(index < this->unit_count);

        return this->units[index];
    }

    inline utf_8_t::utf_8_t(none_t)
    {
        this->unit_count = 1;
        this->units[0] = 0;
        this->units[1] = 0;
        this->units[2] = 0;
        this->units[3] = 0;
    }

    inline utf_8_t&
        utf_8_t::operator =(none_t)
    {
        this->unit_count = 1;
        this->units[0] = 0;
        this->units[1] = 0;
        this->units[2] = 0;
        this->units[3] = 0;
        return *this;
    }

    inline volatile utf_8_t&
        utf_8_t::operator =(none_t)
        volatile
    {
        this->unit_count = 1;
        this->units[0] = 0;
        this->units[1] = 0;
        this->units[2] = 0;
        this->units[3] = 0;
        return *this;
    }

    inline bool_t
        utf_8_t::operator ==(none_t)
        const
    {
        return this->unit_count == 1 && this->units[0] == 0;
    }

    inline bool_t
        utf_8_t::operator ==(none_t)
        const volatile
    {
        return this->unit_count == 1 && this->units[0] == 0;
    }

    inline bool_t
        utf_8_t::operator !=(none_t)
        const
    {
        return !operator ==(none_t());
    }

    inline bool_t
        utf_8_t::operator !=(none_t)
        const volatile
    {
        return !operator ==(none_t());
    }

}}
