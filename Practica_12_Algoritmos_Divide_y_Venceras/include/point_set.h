/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer). Cálculo de la
 * envoltura convexa.
 * @file point_set.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 *
 * @version 0.1
 * @date 2024-12-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

namespace CyA {
  typedef std::pair<double, double> point;
  typedef std::pair<point, point> line;
  typedef std::vector<point> point_vector;

  enum side { 
    LEFT = -1, 
    CENTER, 
    RIGHT 
  };

  class point_set : public point_vector {
   private:
    point_vector hull_;

   public:
    point_set() = default;
    point_set(const vector<point> &points);
    ~point_set(void);

    void quickHull(void);

    void write_hull(std::ostream &os) const;
    void write(std::ostream &os) const;

    inline const point_vector &get_hull(void) const { return hull_; }
    inline const point_vector &get_points(void) const { return *this; }

   private:
    void quickHull(const line &l, int side);

    double distance(const line &l, const point &p) const;
    int find_side(const line &l, const point &p) const;
    void x_bounds(point &min_x, point &max_x) const;
    double point_2_line(const line &l, const point &p) const;
    bool farthest_point(const line &l, int side, point &farthest) const;
  };
}  // namespace CyA