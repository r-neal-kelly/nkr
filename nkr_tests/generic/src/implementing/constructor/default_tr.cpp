/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/constructor/default_tr.h"
#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::implementing::constructor::default_tg>);
    static_assert(generic::implementing::interface::template_tr<generic::implementing::constructor::default_ttg>);

}
