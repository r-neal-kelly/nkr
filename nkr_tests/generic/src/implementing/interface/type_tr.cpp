/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::implementing::interface::type_tg>);
    static_assert(generic::implementing::interface::template_ttr<generic::implementing::interface::type_ttg>);

}
