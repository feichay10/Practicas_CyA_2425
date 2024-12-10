/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
 * @file sub_tree.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 *
 * @version 0.1
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/sub_tree.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

namespace EMST {
  sub_tree::sub_tree(void) : arcs_(), points_(), cost_(0) {
    
  }

  sub_tree::~sub_tree(void) {
    arcs_.clear();
    points_.clear();
  }

  void sub_tree::add_arc(const CyA::arc &a) {
    arcs_.push_back(a);

    points_.insert(a.first);
    points_.insert(a.second);
  }

  void sub_tree::add_point(const CyA::point &p) { points_.insert(p); }

  bool sub_tree::contains(const CyA::point &p) const {
    return points_.find(p) != points_.end();
  }

  void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
    arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
    arcs_.push_back(a.second);

    points_.insert(st.points_.begin(), st.points_.end());

    cost_ += a.first + st.get_cost();
  }
}  // namespace EMST