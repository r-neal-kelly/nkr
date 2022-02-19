/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "nkr/interface/none/value_i.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<interface::none::value_tg>);
    static_assert(generic::implementing::interface::template_ttr<interface::none::value_ttg>);

}
