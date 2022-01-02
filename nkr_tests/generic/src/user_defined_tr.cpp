/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/user_defined_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::user_defined_tg>);
    static_assert(generic::implementing::interface::template_ttr<generic::user_defined_ttg>);

}
