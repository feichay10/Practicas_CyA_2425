#pragma once

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "sub_tree.h"

typedef std::vector<EMST::sub_tree> forest;

class point_set : public CyA::point_vector {
 private:
  CyA::tree emst_;

 public:
  point_set() = default;
  point_set(const CyA::point_vector& points);
  ~point_set(void) = default;

  void EMST(void);

  void write_tree(std::ostream& os) const;
  void write(std::ostream& os) const;
  void write_dot(std::ostream& os) const;

  inline const CyA::tree& get_tree(void) const { return emst_; }
  inline const CyA::point_vector& get_points(void) const { return *this; }
  inline const double get_cost(void) const { return compute_cost(); }

 private:
  void compute_arc_vector(CyA::arc_vector& av) const;
  void find_incident_subtrees(const forest& st, const CyA::arc& a, int& i, int& j) const;
  void merge_subtrees(forest& st, const CyA::arc& a, int i, int j) const;

  double compute_cost(void) const;

  double euclidean_distance(const CyA::arc& a) const;
};