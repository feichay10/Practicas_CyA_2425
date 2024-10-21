/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file transition.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/transition.h"

Transition::Transition(const State& from, const Symbol& symbol, const State& to) {
  from_ = from;
  symbol_ = symbol;
  to_ = to;
}

const State& Transition::GetFrom() const {
  return from_;
}

const Symbol& Transition::GetSymbol() const {
  return symbol_;
}

const State& Transition::GetTo() const {
  return to_;
}