/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "nkr/interface/type_i.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<interface::type_tg>);
    static_assert(generic::implementing::interface::template_tr<interface::type_ttg>);

}
