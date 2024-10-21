/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file dfa.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/dfa.h"

/**
 * @brief Construct a new DFA::DFA object from a vector of strings
 * 
 * @param automaton_data 
 */
DFA::DFA(const std::vector<std::string>& automaton_data) {
  std::stringstream ss(automaton_data[0]); // Leer el alfabeto
  Symbol symbol;
  while (ss >> symbol) {
    alphabet_.insert(Symbol(symbol)); 
  }

  num_states_ = std::stoi(automaton_data[1]); // Número de estados
  initial_state_ = automaton_data[2];         // Estado de arranque
  initial_state_.resize(initial_state_.size() - 1); // Eliminar el salto de linea

  // Leer los estados
  for (int i = 3; i < automaton_data.size(); i++) {
    std::stringstream ss(automaton_data[i]);
    std::string state_id;
    bool aceptation_state;
    bool start_state = false;
    int transitions_number;
    ss >> state_id >> aceptation_state >> transitions_number;
    if (state_id == initial_state_) {
      start_state = true;
    }
    State state(state_id, start_state, aceptation_state, transitions_);
    
    // Leer las transiciones
    for (int j = 0; j < transitions_number; j++) {
      std::string symbol;
      std::string to_state;
      ss >> symbol >> to_state;
      if (!alphabet_.find(Symbol(symbol))) {
        throw std::runtime_error("Hay una transición con un símbolo que no está en el alfabeto");
      }
      Transition transition(state, Symbol(symbol[0]), State(to_state, false, false));
      transitions_.insert(transition);
    }
    states_.insert(state);
  }
}

/**
 * @brief Read the strings on the automaton
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool DFA::ReadStrings(const String& string) {
  State current_state;
  bool initial_state_found = false;
  for (const auto& state : states_) {
    if (state.GetStateId() == initial_state_) {
      current_state = state;
      initial_state_found = true;
      break;
    }
  }

  if (string.GetString().size() - 1 == 1 && string.GetString()[0].GetSymbol() == '&') {
    if (current_state.IsAceptationState()) {
      return true;
    } else {
      return false;
    }
  }

  if (!initial_state_found) {
    throw std::runtime_error("ERROR: Estado inicial no encontrado");
  }
  
  for (int i = 0; i < string.GetString().size() - 1; i++) {
    Symbol symbol = Symbol(string.GetString()[i]);
    #ifdef TRACE
      std::cout << "Current symbol: " << symbol << " - ";
      std::cout << "Current state: " << current_state.GetStateId() << std::endl;
    #endif
    if (!AlphabetComprobation(symbol)) {
      #ifdef TRACE
        std::cout << "ERROR: El simbolo " << symbol.GetSymbol() << " no pertenece al alfabeto" << std::endl;
      #endif
      return false;
    }
    
    bool found = false;
    for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
      if (it->GetFrom().GetStateId() == current_state.GetStateId() && it->GetSymbol().GetSymbol() == symbol.GetSymbol()) {
        auto next_state_it = states_.end();
        for (auto state_it = states_.begin(); state_it != states_.end(); ++state_it) {
          if (state_it->GetStateId() == it->GetTo().GetStateId()) {
            next_state_it = state_it;
            break;
          }
        }
        if (next_state_it != states_.end()) {
          current_state = *next_state_it;
          found = true;
          break;
        }
      }
    }
    
    if (!found) {
      #ifdef TRACE
        std::cout << "ERROR: No se ha encontrado la transición " << current_state.GetStateId() << " -> " << symbol.GetSymbol() << std::endl;
      #endif
      return false;
    }
  }
  
  if (current_state.IsAceptationState()) {
    return true;
  } else {
    return false;
  }
}