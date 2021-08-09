/*
    Copyright 2021 r-neal-kelly
*/

#include <fcntl.h>
#include <io.h>

#include "intrinsic.h"
#include "maybe_pointer_t.h"
#include "pointer_i.h"
#include "string_t.h"

int main(int argument_count, char* arguments[])
{
    if (_setmode(_fileno(stdin), _O_U16TEXT) == -1) {
        assert(0);
    }
    if (_setmode(_fileno(stdout), _O_U16TEXT) == -1) {
        assert(0);
    }

    nkr::test::test_pointer_i();
    nkr::test::test_string_t();

    wprintf(L"\npress any key to continue...\n");
    wchar_t unused = std::getwc(stdin);

    return 0;
}
