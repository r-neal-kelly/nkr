/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "nkr/interface/template_i.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<interface::template_tg>);

}
