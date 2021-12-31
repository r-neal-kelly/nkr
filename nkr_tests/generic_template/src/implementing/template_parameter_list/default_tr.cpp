/*
    Copyright 2021 r-neal-kelly
*/

#include "nkr/generic/implementing/interface/template_tr.h"

#include "nkr/generic_template/implementing/template_parameter_list/default_tr.h"

#include "doctest.h"

namespace nkr {

    static_assert(generic::implementing::interface::template_ttr<generic_template::implementing::template_parameter_list::default_ttg>);

}
