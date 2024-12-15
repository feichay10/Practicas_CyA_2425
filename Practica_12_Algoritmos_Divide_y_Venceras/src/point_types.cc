/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer). Cálculo de la
 * envoltura convexa.
 * 
 * @file point_types.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 *
 * @version 0.1
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/point_types.h"

#include <iomanip>

/**
 * @brief Sobrecarga del operador de flujo de salida para imprimir un vector de
 * puntos.
 *
 * Esta función muestra el tamaño del vector de puntos seguido de cada punto
 * en el vector en una nueva línea.
 *
 * @param os El flujo de salida al que se escribirá el vector de puntos.
 * @param ps El vector de puntos que se escribirá en el flujo de salida.
 * @return Una referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
  os << ps.size() << std::endl;

  for (const CyA::point& p : ps) {
    os << p << std::endl;
  }

  return os;
}

/**
 * @brief Sobrecarga del operador de flujo de salida para el tipo CyA::point.
 *
 * Esta función formatea la salida de un objeto CyA::point estableciendo el
 * ancho, la precisión y la notación de punto fijo para ambos elementos, primero
 * y segundo, del punto.
 *
 * @param os El flujo de salida al que se escribirá el punto.
 * @param p El objeto CyA::point que se va a imprimir.
 * @return Una referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
  os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC)
     << p.first << "\t" << std::setw(MAX_SZ) << std::fixed
     << std::setprecision(MAX_PREC) << p.second;

  return os;
}

/**
 * @brief Sobrecarga del operador de extracción para leer un vector de puntos
 * desde un flujo de entrada.
 *
 * Esta función lee un entero desde el flujo de entrada, que representa el
 * número de puntos a leer. Luego, limpia el vector de puntos proporcionado y
 * lee el número especificado de puntos desde el flujo de entrada, agregando
 * cada punto al vector.
 *
 * @param is El flujo de entrada desde el cual leer.
 * @param ps El vector de puntos a poblar.
 * @return Una referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
  int n;
  is >> n;

  ps.clear();

  for (int i = 0; i < n; ++i) {
    CyA::point p;
    is >> p;

    ps.push_back(p);
  }

  return is;
}

/**
 * @brief Sobrecarga del operador de extracción para leer un punto desde un
 * flujo de entrada.
 *
 * Esta función lee dos valores desde el flujo de entrada y los asigna a los
 * miembros primero y segundo del objeto CyA::point.
 *
 * @param is El flujo de entrada desde el cual se leen los valores del punto.
 * @param p El objeto CyA::point donde se almacenarán los valores leídos.
 * @return Una referencia al flujo de entrada después de que se hayan leído los
 * valores.
 */
std::istream& operator>>(std::istream& is, CyA::point& p) {
  is >> p.first >> p.second;

  return is;
}