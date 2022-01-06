/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"
#include "nkr/generic/implementing/interface/type_tr.h"
#include "nkr/generic/random/generator_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::type_tr<generic::random::generator_tg>);
    static_assert(generic::implementing::interface::template_ttr<generic::random::generator_ttg>);

}
