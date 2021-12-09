/*
    Copyright 2021 r-neal-kelly
*/

#pragma once

#include "nkr/bool_t_def.h"
#include "nkr/intrinsics_def.h"
#include "nkr/math_def.h"
#include "nkr/maybe_t_def.h"
#include "nkr/optional_t_def.h"
#include "nkr/utils_def.h"

#include "nkr/array/stack_t_def.h"

#include "nkr/tree/binary_search_t_dec.h"

namespace nkr {

    template <typename other_p>
    inline constexpr c_bool_t
        type_traits_i<tree::stack::binary_search_tg>::Is_Any()
    {
        return tree::stack::$binary_search_t::any_tr<other_p>;
    }

    inline constexpr c_bool_t
        template_traits_i<tree::stack::binary_search_ttg>::Is_Implemented()
    {
        return true;
    }

}

namespace nkr { namespace tree { namespace stack {

    template <node_i node_p, count_t max_node_count_p>
    inline constexpr count_t
        binary_search_t<node_p, max_node_count_p>::Max_Node_Count()
    {
        return max_node_count_p;
    }

    template <node_i node_p, count_t max_node_count_p>
    inline binary_search_t<node_p, max_node_count_p>::binary_search_t() :
        nodes()
    {
        for (index_t idx = 0, end = nodes.Capacity(); idx < end; idx += 1) {
            nodes.Push(node_t()).Ignore_Error();
        }
    }

    template <node_i node_p, count_t max_node_count_p>
    inline binary_search_t<node_p, max_node_count_p>::binary_search_t(const node_t& sentinel) :
        nodes()
    {
        for (index_t idx = 0, end = nodes.Capacity() - 1; idx < end; idx += 1) {
            nodes.Push(node_t()).Ignore_Error();
        }
        nodes.Push(sentinel).Ignore_Error();
    }

    template <node_i node_p, count_t max_node_count_p>
    inline binary_search_t<node_p, max_node_count_p>::binary_search_t(node_t&& sentinel) :
        nodes()
    {
        for (index_t idx = 0, end = nodes.Capacity() - 1; idx < end; idx += 1) {
            nodes.Push(node_t()).Ignore_Error();
        }
        nodes.Push(nkr::Move(sentinel)).Ignore_Error();
    }

    template <node_i node_p, count_t max_node_count_p>
    inline binary_search_t<node_p, max_node_count_p>::~binary_search_t()
    {
    }

}}}
