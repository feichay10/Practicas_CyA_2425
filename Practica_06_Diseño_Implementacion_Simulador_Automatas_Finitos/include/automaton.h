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

#include "alphabet.h"
#include "state.h"
#include "symbol.h"
#include "transition.h"

class Automaton {
 public:
  std::set<State> GetStates() const;
  Alphabet GetAlphabet() const;
  std::set<Transition> GetTransitions() const;
  State GetInitialState() const;
  std::set<State> GetFinalStates() const;

  void ReadStrings(std::string string);

  // friend std::ostream& operator<<(std::ostream& os, const Automaton& automaton) {
  //   os << "States: {";
  //   for (auto it = automaton.states_.begin(); it != automaton.states_.end(); ++it) {
  //     if (it != automaton.states_.begin()) {
  //       os << ", ";
  //     }
  //     os << *it;
  //   }
  //   os << "}\n";

  //   os << "Alphabet: " << automaton.alphabet_ << "\
  //   \nTransitions: {";
  //   for (auto it = automaton.transitions_.begin(); it != automaton.transitions_.end(); ++it) {
  //     if (it != automaton.transitions_.begin()) {
  //       os << ", ";
  //     }
  //     os << *it;
  //   }
  //   os << "}\n";

  //   os << "Initial state: " << automaton.initial_state_ << "\n";
  //   os << "Final states: {";
  //   for (auto it = automaton.final_states_.begin(); it != automaton.final_states_.end(); ++it) {
  //     if (it != automaton.final_states_.begin()) {
  //       os << ", ";
  //     }
  //     os << *it;
  //   }
  //   os << "}\n";

  //   return os;
  // }

 private:
  Alphabet alphabet_;
  std::set<State> states_;
  State initial_state_;
  std::set<State> final_states_;
  std::set<Transition> transitions_;
};

#endif  // AUTOMATON_H