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

std::string Automaton::GetInitialState() const {
  return initial_state_;
}

std::set<State> Automaton::GetFinalStates() const {
  return final_states_;
}

int Automaton::GetNumStates() const {
  return num_states_;
}

bool Automaton::AlphabetComprobation(const Symbol& symbol) {
  if (alphabet_.GetAlphabet().find(symbol) == alphabet_.GetAlphabet().end()) {
    return false;
  }
  return true;
}

// Funcion que lee las cadenas y comprueba si son aceptadas o no por el automata
// Ir simbolo a simbolo y comprobar si la transición existe
void Automaton::ReadStrings(const String& string) {
  State current_state = State(initial_state_, false, true);
  std::cout << "Estado actual: " << current_state.GetStateId() << std::endl;
  for (int i = 0; i < string.GetString().size(); i++) {
    Symbol symbol = Symbol(string.GetString()[i]);
    if (!AlphabetComprobation(symbol)) {
      std::cout << "ERROR: El simbolo " << symbol.GetSymbol() << " no pertenece al alfabeto" << std::endl;
      return;
    }
    bool found = false;
    for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
      if (it->GetFrom().GetStateId() == current_state.GetStateId() && it->GetSymbol().GetSymbol() == symbol.GetSymbol()) {
        current_state = it->GetTo();
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "ERROR: No se ha encontrado la transición " << current_state.GetStateId() << " -> " << symbol.GetSymbol() << std::endl;
      return;
    }
    std::cout << "Estado actual: " << current_state.GetStateId() << std::endl;
  }
  if (current_state.IsAceptationState()) {
    std::cout << "Accepted" << std::endl;
  } else {
    std::cout << "Rejected" << std::endl;
  }
}
