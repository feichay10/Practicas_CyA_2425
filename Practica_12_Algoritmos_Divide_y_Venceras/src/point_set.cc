/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer). Cálculo de la
 * envoltura convexa.
 * @file point_set.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 *
 * @version 0.1
 * @date 2024-12-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/point_set.h"

using namespace CyA;

/**
 * @brief Construye un objeto point_set e inicializa con un vector dado de
 * puntos.
 *
 * Este constructor inicializa el objeto point_set con el vector de puntos
 * proporcionado y luego llama al método quickHull() para calcular la envoltura
 * convexa de los puntos.
 *
 * @param points Una referencia constante a un vector de objetos punto para
 * inicializar el point_set.
 */
point_set::point_set(const vector<point> &points) : point_vector(points) {
  quickHull();
}

/**
 * @brief Destructor de la clase point_set.
 *
 * Este destructor es responsable de liberar cualquier recurso
 * asignado por la clase point_set.
 */
point_set::~point_set(void) {}

/**
 * @brief Calcula la envoltura convexa de un conjunto de puntos utilizando el
 * algoritmo QuickHull.
 *
 * Esta función limpia la envoltura actual, encuentra los puntos con las
 * coordenadas x mínimas y máximas, y calcula recursivamente la envoltura
 * convexa para los lados izquierdo y derecho de la línea formada por estos
 * puntos. Finalmente, elimina cualquier punto duplicado de la envoltura.
 */
void point_set::quickHull(void) {
  hull_.clear();

  CyA::point min_x_point;
  CyA::point max_x_point;

  x_bounds(min_x_point, max_x_point);

  quickHull(CyA::line(min_x_point, max_x_point), side::LEFT);
  quickHull(CyA::line(min_x_point, max_x_point), side::RIGHT);

  std::sort(hull_.begin(), hull_.end());
  hull_.erase(std::unique(hull_.begin(), hull_.end()), hull_.end());
}

/**
 * @brief Escribe los puntos de la envoltura convexa en el flujo de salida
 * proporcionado.
 *
 * Esta función itera sobre los puntos en la envoltura convexa y escribe cada
 * punto en el flujo de salida proporcionado en el formato (x, y).
 *
 * @param os El flujo de salida donde se escribirán los puntos de la envoltura
 * convexa.
 */
void point_set::write_hull(std::ostream &os) const {
  for (const point &p : hull_) {
    os << "(" << p.first << ",  " << p.second << ")" << std::endl;
  }
}

/**
 * @brief Escribe el conjunto de puntos en el flujo de salida proporcionado.
 *
 * Esta función calcula el punto medio entre los puntos con las coordenadas x
 * mínimas y máximas y escribe el resultado en el flujo de salida proporcionado.
 *
 * @param os El flujo de salida donde se escribirá el punto medio.
 */
void point_set::write(std::ostream &os) const {
  for (const point &p : *this) {
    os << "(" << p.first << ",  " << p.second << ")" << std::endl;
  }
}

/**
 * @brief Escribe el conjunto de puntos en formato DOT en el flujo de salida
 * proporcionado.
 *
 * Esta función genera una representación en formato DOT del conjunto de puntos,
 * incluyendo los puntos y los bordes que forman la envoltura convexa. Cada
 * punto se etiqueta con una letra única comenzando desde 'a', y su posición se
 * especifica en el formato DOT. Los bordes de la envoltura convexa se
 * representan como conexiones entre estos puntos.
 *
 * @param os El flujo de salida donde se escribirá la representación en formato
 * DOT.
 */
void point_set::write_dot(std::ostream &os) const {
  char letter = 'a';
  os << "graph {" << std::endl;
  std::map<point, char> point_to_letter;
  for (const point &p : *this) {
    os << "    " << letter << " [pos=\"" << p.first << "," << p.second
       << "!\", fontsize=300]" << std::endl;
    point_to_letter[p] = letter;
    ++letter;
  }

  // Write the edges making up the convex hull
  for (size_t i = 0; i < hull_.size(); ++i) {
    os << "    " << point_to_letter[hull_[i]] << " -- "
       << point_to_letter[hull_[(i + 1) % hull_.size()]] << std::endl;
  }

  os << "}" << std::endl;
}

/**
 * @brief Calcula la envoltura convexa de un conjunto de puntos utilizando el
 * algoritmo QuickHull.
 *
 * Esta función encuentra recursivamente la envoltura convexa de un conjunto de
 * puntos dividiendo el problema en subproblemas más pequeños. Identifica el
 * punto más lejano de un segmento de línea dado y procesa recursivamente los
 * puntos en ambos lados del segmento de línea.
 *
 * @param l El segmento de línea utilizado para dividir el conjunto de puntos.
 * @param side El lado del segmento de línea a procesar (-1 para la izquierda, 1
 * para la derecha).
 */
void point_set::quickHull(const CyA::line &l, int side) {
  CyA::point farthest;

  if (farthest_point(l, side, farthest)) {
    quickHull(CyA::line(l.first, farthest),
              -find_side(CyA::line(l.first, farthest), l.second));
    quickHull(CyA::line(farthest, l.second),
              -find_side(CyA::line(farthest, l.second), l.first));
  } else {
    hull_.push_back(l.first);
    hull_.push_back(l.second);
  }
}

/**
 * @brief Calcula la distancia perpendicular desde un punto a una línea.
 *
 * Esta función calcula la distancia perpendicular absoluta desde un punto dado
 * a una línea especificada utilizando la función point_2_line.
 *
 * @param l La línea a la que se calcula la distancia.
 * @param p El punto desde el cual se calcula la distancia.
 * @return La distancia perpendicular desde el punto a la línea.
 */
double point_set::distance(const CyA::line &l, const CyA::point &p) const {
  return fabs(point_2_line(l, p));
}

/**
 * @brief Determina el lado de un punto en relación con una línea.
 *
 * Esta función calcula la posición de un punto en relación con una línea dada.
 * Devuelve si el punto está en el lado derecho, en el lado izquierdo o
 * exactamente en la línea.
 *
 * @param l La línea con la que se compara la posición del punto.
 * @param p El punto cuya posición en relación con la línea se va a determinar.
 * @return Un entero que representa el lado del punto:
 *         - side::RIGHT si el punto está en el lado derecho de la línea.
 *         - side::LEFT si el punto está en el lado izquierdo de la línea.
 *         - side::CENTER si el punto está exactamente en la línea.
 */
int point_set::find_side(const line &l, const point &p) const {
  double val = point_2_line(l, p);
  if (val > 0) {
    return side::RIGHT;
  } else if (val < 0) {
    return side::LEFT;
  } else {
    return side::CENTER;
  }
}

/**
 * @brief Encuentra los puntos con las coordenadas x mínimas y máximas en el
 * conjunto de puntos.
 *
 * Esta función itera a través de todos los puntos en el conjunto de puntos y
 * determina los puntos con las coordenadas x más pequeñas y más grandes. Los
 * resultados se almacenan en las referencias proporcionadas min_x y max_x.
 *
 * @param min_x Referencia a un objeto punto donde se almacenará el punto con la
 * coordenada x mínima.
 * @param max_x Referencia a un objeto punto donde se almacenará el punto con la
 * coordenada x máxima.
 */
void point_set::x_bounds(point &min_x, point &max_x) const {
  min_x = *this->begin();
  max_x = min_x;
  for (const point &p : *this) {
    if (p.first < min_x.first) {
      min_x = p;
    } else if (p.first > max_x.first) {
      max_x = p;
    }
  }
}

/**
 * @brief Calcula la distancia firmada desde un punto a una línea.
 *
 * Esta función calcula la distancia firmada desde un punto dado a una línea
 * definida por dos puntos. El resultado es positivo si el punto está a la
 * izquierda de la línea, negativo si el punto está a la derecha, y cero si el
 * punto está en la línea.
 *
 * @param l La línea definida por dos puntos (p1 y p2).
 * @param p El punto para el cual se calcula la distancia a la línea.
 * @return La distancia firmada desde el punto a la línea.
 */
double point_set::point_2_line(const CyA::line &l, const CyA::point &p) const {
  const CyA::point &p1 = l.first;
  const CyA::point &p2 = l.second;

  return (p.second - p1.second) * (p2.first - p1.first) -
         (p2.second - p1.second) * (p.first - p1.first);
}

/**
 * @brief Encuentra el punto más lejano desde una línea dada en un lado
 * especificado.
 *
 * Esta función itera a través de todos los puntos en el conjunto de puntos y
 * determina el punto que está más lejos de la línea dada `l` en el lado
 * especificado.
 *
 * @param l La línea desde la cual se mide la distancia.
 * @param side El lado de la línea a considerar (por ejemplo, izquierda o
 * derecha).
 * @param farthest Referencia a un objeto punto donde se almacenará el punto más
 * lejano.
 * @return true si se encuentra un punto en el lado especificado, false en caso
 * contrario.
 */
bool point_set::farthest_point(const CyA::line &l, int side,
                               CyA::point &farthest) const {
  farthest = CyA::point_vector::at(0);
  double max_dist = 0;
  bool found = false;

  for (const CyA::point &p : *this) {
    const double dist = distance(l, p);

    if (find_side(l, p) == side && dist > max_dist) {
      farthest = p;
      max_dist = dist;
      found = true;
    }
  }

  return found;
}

// // Modificacion: determinar el punto medio de los puntos mas altos y mas
// bajos del eje x void point_set::mid_point(std::ostream& os) const {
//   point min_x_point;
//   point max_x_point;

//   x_bounds(min_x_point, max_x_point);

//   double mid_x = (min_x_point.first + max_x_point.first) / 2;
//   double mid_y = (min_x_point.second + max_x_point.second) / 2;

//   os << "Punto medio: (" << mid_x << ", " << mid_y << ")" << std::endl;
// }