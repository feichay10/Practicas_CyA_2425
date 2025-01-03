/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file nfa.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef NFA_H
#define NFA_H

#include "automaton.h"

/**
 * @brief Class that represents a NFA
 * 
 */
class NFA : public Automaton {
 public:
  NFA(const std::vector<std::string>& automaton_data);
  ~NFA() = default;
  
  bool ReadStrings(const String& string) override;
  std::set<State> EpsilonClosure(const std::set<State>& states);
};

#endif  // NFA_H