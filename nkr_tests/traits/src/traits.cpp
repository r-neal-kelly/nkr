/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "doctest.h"

namespace nkr {

    static_assert(tr1<
                  const char*,
                  any_non_const_tg, c_pointer_tg>);
    static_assert(tr1<
                  const char* const,
                  any_const_tg, c_pointer_tg>);

    static_assert(tr2<
                  char**,
                  any_tg, c_pointer_ttg, of_any_tg, c_pointer_tg>);
    static_assert(tr2<
                  std::add_pointer_t<char[3]>,
                  any_tg, c_pointer_ttg, of_any_tg, c_array_tg>);

    class testing_t
    {
    public:
        static bool_t Test(tr1<any_non_const_tg, c_pointer_tg> auto& test)
        {
            return true;
        }

        static bool_t Test(tr1<any_const_tg, c_pointer_tg> auto& test)
        {
            return false;
        }
    };

    class testing_2_t
    {
    public:
        static bool_t Test(tr1<any_tg, c_array_tg> auto& array)
        {
            static_assert(std_array_tr<std::remove_reference_t<decltype(array)>>);

            printf("sizeof array: %zu\n", sizeof(array));

            return true;
        }
    };

    TEST_CASE("temp")
    {
        const char* a = nullptr;
        CHECK(testing_t::Test(a));
        const char* volatile b = nullptr;
        CHECK(testing_t::Test(b));
        const volatile char* c = nullptr;
        CHECK(testing_t::Test(c));
        const volatile char* volatile d = nullptr;
        CHECK(testing_t::Test(d));

        const char* const e = nullptr;
        CHECK(!testing_t::Test(e));
        const char* const volatile f = nullptr;
        CHECK(!testing_t::Test(f));
        const volatile char* const g = nullptr;
        CHECK(!testing_t::Test(g));
        const volatile char* const volatile h = nullptr;
        CHECK(!testing_t::Test(h));

        const char array[5] = { 0 };
        CHECK(testing_2_t::Test(array));
    }

    template <typename parameter_p>
    class subject_t;

    namespace $subject_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, subject_t<typename type_p::parameter_t>>;

    }

    template <$subject_t::any_tr subject_p>
    class traits_i<subject_p>
    {
    public:
        using of_t          = subject_p::parameter_t;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = template_p<of_p>;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any_Subject()
        {
            return $subject_t::any_tr<other_p>;
        };
    };

    template <typename parameter_p>
    class subject_t
    {
    public:
        using parameter_t   = parameter_p;
    };

    template <typename parameter_p>
    class other_subject_t;

    namespace $other_subject_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, other_subject_t<typename type_p::parameter_t>>;

    }

    template <$other_subject_t::any_tr subject_p>
    class traits_i<subject_p>
    {
    public:
        using of_t          = subject_p::parameter_t;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = template_p<of_p>;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any_Subject()
        {
            return $other_subject_t::any_tr<other_p>;
        };
    };

    template <typename parameter_p>
    class other_subject_t
    {
    public:
        using parameter_t   = parameter_p;
    };

    static_assert(!tr2<
                  volatile subject_t<const volatile word_t*>,
                  any_tg, other_subject_t, of_any_tg, word_t*>);

    static_assert(tr3<
                  volatile subject_t<const volatile word_t*>,
                  just_volatile_tg, subject_t, of_just_non_qualified_tg, c_pointer_ttg, of_any_const_tg, word_t>);

    static_assert(tr3<
                  subject_t<void_t*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, void_t>);

    static_assert(tr1<
                  subject_t<char>,
                  any_tg, subject_t<char>>);
    static_assert(tr1<
                  volatile subject_t<const volatile char>,
                  any_tg, subject_t<char>>);

    static_assert(tr1<
                  const volatile subject_t<char>,
                  any_const_tg, subject_t<char>>);

    static_assert(tr2<
                  volatile subject_t<const volatile char>,
                  any_tg, subject_t, of_any_tg, char>);
    static_assert(tr2<
                  const subject_t<volatile subject_t<char>>,
                  any_tg, subject_t, of_any_tg, subject_t<char>>);

    static_assert(tr3<
                  subject_t<subject_t<char>>,
                  any_tg, subject_t, of_any_tg, subject_t, of_any_tg, char>);

    static_assert(tr3<
                  subject_t<char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  subject_t<const volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const subject_t<const volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile subject_t<const volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const volatile char*>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const volatile char* const>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const volatile char* volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile subject_t<const volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);

    static_assert(!tr3<
                  const volatile subject_t<const volatile char* const volatile>,
                  any_tg, subject_t, of_any_tg, c_pointer_ttg, of_any_tg, int>);

    static_assert(tr3<
                  subject_t<const char* const volatile>,
                  any_tg, subject_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);
    static_assert(!tr3<
                  subject_t<char* const volatile>,
                  any_tg, subject_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);
    static_assert(!tr3<
                  subject_t<const char* volatile>,
                  any_tg, subject_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);

}
