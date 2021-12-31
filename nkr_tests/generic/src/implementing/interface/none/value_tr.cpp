/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/none/value_tr.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::implementing::interface::none::value_tg>);
    static_assert(generic::implementing::interface::template_ttr<generic::implementing::interface::none::value_ttg>);

}
