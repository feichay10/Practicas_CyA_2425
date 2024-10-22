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
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/automaton.h"

/**
 * @brief Get the States object
 * 
 * @return std::set<State> 
 */
std::set<State> Automaton::GetStates() const {
  return states_;
}

/**
 * @brief Get the Alphabet object
 * 
 * @return Alphabet 
 */
Alphabet Automaton::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief Get the Transitions object
 * 
 * @return const std::set<Transition>& 
 */
const std::set<Transition>& Automaton::GetTransitions() const {
  return transitions_;
}

/**
 * @brief Get the Initial State object
 * 
 * @return State 
 */
 State Automaton::GetInitialState() const {
  return initial_state_;
}

/**
 * @brief Get the Final States object
 * 
 * @return std::set<State> 
 */
std::set<State> Automaton::GetFinalStates() const {
  return final_states_;
}

/**
 * @brief Get the Num States object
 * 
 * @return int 
 */
int Automaton::GetNumStates() const {
  return num_states_;
}

/**
 * @brief Comprobation of the alphabet
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Automaton::AlphabetComprobation(const Symbol& symbol) {
  if (!alphabet_.find(Symbol(symbol))) {
    return false;
  } else {
    return true;
  }
}

/**
 * @brief Overload of the operator <<
 * 
 * @param os 
 * @param automaton 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Automaton& automaton) {
  os << "Alphabet: " << automaton.GetAlphabet() << std::endl;
  os << "Number of states: " << automaton.GetNumStates() << std::endl;
  std::set<State> states = automaton.GetStates();
  os << "States: ";
  for (auto it = states.begin(); it != states.end(); it++) {
    os << "\nState " << it->GetStateId() << ": " << std::endl;
    os << "  - Is start state: " << (it->IsStartState() ? "yes" : "no") << std::endl;
    os << "  - Is acceptance state: " << (it->IsAceptationState() ? "yes" : "no") << std::endl;
    os << "  - Transitions: " << std::endl;
    for (auto it2 = automaton.GetTransitions().begin(); it2 != automaton.GetTransitions().end(); it2++) {
    if (it2->GetFrom() == *it) {
      os << "    - " << it2->GetFrom().GetStateId() << " -> " << it2->GetSymbol() << " -> " << it2->GetTo().GetStateId() << std::endl;
    }
    }
  }
  return os;
}