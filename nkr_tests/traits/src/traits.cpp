/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/bool_t.h"
#include "nkr/intrinsics.h"
#include "nkr/traits.h"

#include "doctest.h"

namespace nkr {

    class testing_t
    {
    public:
        static bool_t Test(tr2<any_tg, c_pointer_ttg, of_any_const_tg, char> auto test)
        {
            return true;
        }
    };

    TEST_CASE("temp")
    {
        const char* const pointer = nullptr;
        const char array[5] = { 0 };

        using array_t = decltype(array);

        CHECK(testing_t::Test(array));
    }

    template <typename parameter_p>
    class test_t;

    namespace $test_t {

        template <typename type_p>
        concept any_tr =
            is_any_tr<type_p, test_t<typename type_p::parameter_t>>;

    }

    template <$test_t::any_tr subject_p>
    class traits_i<subject_p>
    {
    public:
        using of_t          = subject_p::parameter_t;

        template <template <typename ...> typename template_p, typename of_p>
        using resolved_t    = template_p<of_p>;

    public:
        template <typename other_p>
        static constexpr std_bool_t Is_Any()
        {
            return $test_t::any_tr<other_p>;
        };
    };

    template <typename parameter_p>
    class test_t
    {
    public:
        using parameter_t = parameter_p;
    };

    static_assert(tr3<
                  test_t<void_t*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, void_t>);

    static_assert(tr1<
                  test_t<char>,
                  any_tg, test_t<char>>);
    static_assert(tr1<
                  volatile test_t<const volatile char>,
                  any_tg, test_t<char>>);

    static_assert(tr1<
                  const volatile test_t<char>,
                  any_const_tg, test_t<char>>);

    static_assert(tr2<
                  volatile test_t<const volatile char>,
                  any_tg, test_t, of_any_tg, char>);
    static_assert(tr2<
                  const test_t<volatile test_t<char>>,
                  any_tg, test_t, of_any_tg, test_t<char>>);

    static_assert(tr3<
                  test_t<test_t<char>>,
                  any_tg, test_t, of_any_tg, test_t, of_any_tg, char>);

    static_assert(tr3<
                  test_t<char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  test_t<const volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const test_t<const volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  volatile test_t<const volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const volatile char*>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const volatile char* const>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const volatile char* volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);
    static_assert(tr3<
                  const volatile test_t<const volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, char>);

    static_assert(!tr3<
                  const volatile test_t<const volatile char* const volatile>,
                  any_tg, test_t, of_any_tg, c_pointer_ttg, of_any_tg, int>);

    static_assert(tr3<
                  test_t<const char* const volatile>,
                  any_tg, test_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);
    static_assert(!tr3<
                  test_t<char* const volatile>,
                  any_tg, test_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);
    static_assert(!tr3<
                  test_t<const char* volatile>,
                  any_tg, test_t, of_any_const_tg, c_pointer_ttg, of_any_const_tg, char>);

}
