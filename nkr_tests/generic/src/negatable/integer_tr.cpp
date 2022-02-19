/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/negatable/integer_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::negatable::integer_tg>);
    static_assert(generic::implementing::interface::template_ttr<generic::negatable::integer_ttg>);

}
