/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file dfa.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DFA_H
#define DFA_H

#include "automaton.h"

class DFA : public Automaton {
 public:
  DFA(std::vector<std::string> automaton_data);
  ~DFA() = default;
  bool ReadStrings(const String& string) override;
};

#endif  // DFA_H