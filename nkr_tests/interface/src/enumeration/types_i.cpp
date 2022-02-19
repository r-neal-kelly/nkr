/*
    Copyright 2022 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"

#include "nkr/interface/enumeration/types_i.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<interface::enumeration::types_tg>);
    static_assert(generic::implementing::interface::template_ttr<interface::enumeration::types_ttg>);

}
