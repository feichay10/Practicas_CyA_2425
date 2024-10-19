/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file automaton.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/automaton.h"

std::set<State> Automaton::GetStates() const {
  return states_;
}

Alphabet Automaton::GetAlphabet() const {
  return alphabet_;
}

const std::set<Transition>& Automaton::GetTransitions() const {
  return transitions_;
}

int Automaton::GetInitialState() const {
  return initial_state_;
}

std::set<State> Automaton::GetFinalStates() const {
  return final_states_;
}

bool Automaton::AlphabetComprobation(const Symbol& symbol) {
  if (alphabet_.GetAlphabet().find(symbol) == alphabet_.GetAlphabet().end()) {
    return false;
  }
  return true;
}

void Automaton::ReadStrings(const std::string& string) {
  bool is_accepted = false;

  if (string.at(0) == '&') {
    is_accepted = true;
  }

  auto it = states_.find(State(initial_state_));
  if (it == states_.end()) {
    std::cerr << "ERROR: Initial state not found in the set of states" << std::endl;
    exit(EXIT_FAILURE);
  }
  State current_state = *it;
  Transition next;
  Symbol symbol;

  for (int i = 0; i < string.size(); i++) {
    symbol = string.at(i);
    if (!AlphabetComprobation(symbol)) {
      std::cerr << "ERROR: The symbol " << symbol.GetSymbol() << " is not in the alphabet" << std::endl;
      exit(EXIT_FAILURE);
    }
    // next = current_state.GetTransitions(symbol);
  }
}
