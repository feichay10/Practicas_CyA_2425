#include "../include/point_set.h"

#include "../include/sub_tree.h"

point_set::point_set(const CyA::point_vector &points) : CyA::point_vector(points), emst_() {}

point_set::~point_set(void) {}

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

  for (int k = 0; k < st.size(); ++k) {
    const EMST::sub_tree &s = st[k];

    if (s.contains(a.first)) i = k;

    if (s.contains(a.second)) j = k;
  }
}

void point_set::merge_subtrees(forest &st, const CyA::arc &a, int i, int j) const {
  EMST::sub_tree s1 = st[i];
  EMST::sub_tree s2 = st[j];
  CyA::weigthed_arc wa = std::make_pair(euclidean_distance(a), a);

  s1.merge(s2, wa);

  st.erase(st.begin() + j);
}

double point_set::compute_cost(void) const {
  double cost = 0.0;

  for (const CyA::arc &a : emst_) {
    cost += euclidean_distance(a);
  }

  return cost;
}

double point_set::euclidean_distance(const CyA::arc &a) const {
  const CyA::point &p1 = a.first;
  const CyA::point &p2 = a.second;

  const double dx = p1.first - p2.first;
  const double dy = p1.second - p2.second;

  return std::sqrt(dx * dx + dy * dy);
}

void point_set::add_edge(const CyA::point &p1, const CyA::point &p2) {
  this->push_back(p1);
  this->push_back(p2);
}

void point_set::write_tree(std::ostream &os) const {
  os << "Minimum Tree:" << std::endl;
  for (const CyA::arc& arc : emst_) {
    auto it = std::find(begin(), end(), arc.first);
    int inx = it - begin();
    auto it2 = std::find(begin(), end(), arc.second);
    int inx2 = it2 - begin();
    os << "from point " << inx << "(" << arc.first.first << ", " << arc.first.second << 
    ") to point " << inx2 << "(" << arc.second.first << ", " << arc.second.second << ")"
    << " with cost: " << euclidean_distance(arc) << "\n";
  }
}

void point_set::write(std::ostream &os) const {
  os << "Points:" << "\n";
  for (const CyA::point& point : *this) {
    os << "(" << point.first << ", " << point.second << ")" << std::endl;
  }
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