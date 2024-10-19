/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file nfa.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/nfa.h"

NFA::NFA(std::vector<std::string> automaton_data) {
  // std::stringstream ss(automaton_data[0]); // Leer el alfabeto
  // Symbol symbol;
  // while (ss >> symbol) {
  //   alphabet_.insert(Symbol(symbol));
  // }
  
  // alphabet_.insert(Symbol('&')); // Añadir símbolo epsilon al alfabeto

  // num_states_ = std::stoi(automaton_data[1]); // Número de estados
  // initial_state_ = automaton_data[2];         // Estado inicial

  // // Leer los estados
  // for (int i = 3; i < automaton_data.size(); i++) {
  //   std::cout << "Linea: " << automaton_data[i] << std::endl;
  //   std::stringstream ss(automaton_data[i]);
  //   std::string state_id;
  //   bool aceptation_state;
  //   int transitions_number;
  //   ss >> state_id >> aceptation_state >> transitions_number;
    
  //   State state(state_id, state_id == initial_state_, aceptation_state);
    
  //   // Leer las transiciones
  //   for (int j = 0; j < transitions_number; j++) {
  //     std::string symbol;
  //     std::string to_state;
  //     ss >> symbol >> to_state;
      
  //     if (symbol == "&") { // Epsilon transiciones
  //       Transition transition(state, Symbol('&'), State(to_state, false, false));
  //       epsilon_transitions_[state_id].insert(to_state);
  //     } else {
  //       Transition transition(state, Symbol(symbol[0]), State(to_state, false, false));
  //       transitions_[state_id][Symbol(symbol)].insert(to_state);
  //     }
  //   }
    
  //   states_.insert(state);
  // }
}
