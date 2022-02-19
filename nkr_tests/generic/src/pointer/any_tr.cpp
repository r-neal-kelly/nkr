/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/pointer/any_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::pointer::any_tg>);
    static_assert(generic::implementing::interface::template_ttr<generic::pointer::any_ttg>);

}
