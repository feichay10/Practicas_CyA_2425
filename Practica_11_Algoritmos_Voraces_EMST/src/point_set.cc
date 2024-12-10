/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
 * @file point_set.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 *
 * @version 0.1
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/point_set.h"
#include "../include/sub_tree.h"

point_set::point_set(const CyA::point_vector &points) : CyA::point_vector(points), emst_() {}

void point_set::EMST(void) {
  CyA::arc_vector av;
  compute_arc_vector(av);

  forest st;

  for (const CyA::point &p : *this) {
    EMST::sub_tree s;
    s.add_point(p);
    st.push_back(s);
  }

  for (const CyA::weigthed_arc &a : av) {
    int i, j;
    find_incident_subtrees(st, a.second, i, j);

    if (i != j) {
      merge_subtrees(st, a.second, i, j);
    }
  }

  emst_ = st[0].get_arcs();
}

// MODIFICACION
void point_set::multi_start(int n) {
  CyA::arc_vector av;
  compute_arc_vector(av);

  forest st;

  for (const CyA::point &p : *this) {
    EMST::sub_tree s;
    s.add_point(p);
    st.push_back(s);
  }

  for (int i = 0; i < n; ++i) {
    std::random_shuffle(av.begin(), av.end());
    for (const CyA::weigthed_arc &a : av) {
      int i, j;
      find_incident_subtrees(st, a.second, i, j);

      if (i != j) {
        merge_subtrees(st, a.second, i, j);
      }
    }
  }

  emst_ = st[0].get_arcs();
}

void point_set::compute_arc_vector(CyA::arc_vector &av) const {
  av.clear();
  const int n = size();
  for (int i = 0; i < n - 1; ++i) {
    const CyA::point &p_i = (*this)[i];
    for (int j = i + 1; j < n; ++j) {
      const CyA::point &p_j = (*this)[j];
      const double dist = euclidean_distance(std::make_pair(p_i, p_j));
      av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
    }
  }
  std::sort(av.begin(), av.end());
}

void point_set::find_incident_subtrees(const forest &st, const CyA::arc &a, int &i, int &j) const {
  i = j = -1;
  for (int tag{0}; tag < st.size(); ++tag) {
    if (st[tag].contains(a.first)) {
      i = tag;
    } if (st[tag].contains(a.second)) {
      j = tag;
    } if (i != -1 && j != -1) {
      break;
    }
  }
}

void point_set::merge_subtrees(forest &st, const CyA::arc &a, int i, int j) const {
  st[i].merge(st[j], std::make_pair(euclidean_distance(a), a));
  st.erase(st.begin() + j);
}

double point_set::compute_cost(void) const {
  double cost = 0.0;
  for (const CyA::arc &arcs : emst_) {
    cost += euclidean_distance(arcs);
  }
  return cost;
}

double point_set::euclidean_distance(const CyA::arc &a) const {
  const CyA::point &p1 = a.first;
  const CyA::point &p2 = a.second;
  return std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
}

void point_set::write(std::ostream &os) const {
  os << "Points:" << "\n";
  for (const CyA::point& point : *this) {
    os << "(" << point.first << ", " << point.second << ")" << std::endl;
  }
  os << std::endl;
}

void point_set::write_tree(std::ostream &os) const {
  os << "\nÁrbol mínimo:" << std::endl;
  for (const CyA::arc& arc : emst_) {
    auto it = std::find(begin(), end(), arc.first);
    int inx = it - begin();
    auto it2 = std::find(begin(), end(), arc.second);
    int inx2 = it2 - begin();
    os << "desde el punto " << inx << "(" << arc.first.first << ", " << arc.first.second << 
    ") --> al punto " << inx2 << "(" << arc.second.first << ", " << arc.second.second << ")"
    << " con coste: " << euclidean_distance(arc) << "\n";
  }
  os << std::endl;
}

void point_set::write_dot(std::ostream &os) const {
  os << "graph {\n";

  for (int i{0}; i < size(); ++i) {
    os << "    " <<  i << " [pos=\"" << at(i).first << "," << at(i).second << "!\"];\n";
  }

  for (const CyA::arc& arcs : emst_) {
    auto it = std::find(begin(), end(), arcs.first);
    int inx = it - begin();
    os << "    " << inx << " -- "; 
    auto it2 = std::find(begin(), end(), arcs.second);
    int inx2 = it2 - begin();
    os << inx2 << " " << "\n";
  }

  os << "  " << "}";
}