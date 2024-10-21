/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file automaton.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <sstream>

#include "alphabet.h"
#include "state.h"
#include "symbol.h"
#include "transition.h"
#include "string.h"

class Automaton {
 public:
  std::set<State> GetStates() const;
  Alphabet GetAlphabet() const;
  const std::set<Transition>& GetTransitions() const;
  std::string GetInitialState() const;
  std::set<State> GetFinalStates() const;
  int GetNumStates() const;

  bool AlphabetComprobation(const Symbol& symbol); // TODO: FIX
  virtual bool ReadStrings(const String& string) = 0;

 protected:
  Alphabet alphabet_;
  std::set<State> states_;
  std::string initial_state_;
  std::set<State> final_states_;
  std::set<Transition> transitions_;
  int num_states_;
};

#endif  // AUTOMATON_H