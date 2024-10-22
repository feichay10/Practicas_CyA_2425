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
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/transition.h"

/**
 * @brief Construct a new Transition:: Transition object
 * 
 * @param from 
 * @param symbol 
 * @param to 
 */
Transition::Transition(const State& from, const Symbol& symbol, const State& to) {
  from_ = from;
  symbol_ = symbol;
  to_ = to;
}

/**
 * @brief Get the From object
 * 
 * @return const State& 
 */
const State& Transition::GetFrom() const {
  return from_;
}

/**
 * @brief Get the Symbol object
 * 
 * @return const Symbol& 
 */
const Symbol& Transition::GetSymbol() const {
  return symbol_;
}

/**
 * @brief Get the To object
 * 
 * @return const State& 
 */
const State& Transition::GetTo() const {
  return to_;
}

/**
 * @brief Overload of the operator <
 * 
 * @param transition 
 * @return true 
 * @return false 
 */
bool Transition::operator<(const Transition& transition) const {
  if (from_ < transition.from_) {
    return true;
  } else if (from_ == transition.from_) {
    if (symbol_ < transition.symbol_) {
      return true;
    } else if (symbol_ == transition.symbol_) {
      return to_ < transition.to_;
    }
  }
  return false;
}