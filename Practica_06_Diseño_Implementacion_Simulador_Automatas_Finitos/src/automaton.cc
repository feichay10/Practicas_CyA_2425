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

std::set<Transition> Automaton::GetTransitions() const {
  return transitions_;
}

int Automaton::GetInitialState() const {
  return initial_state_;
}

std::set<State> Automaton::GetFinalStates() const {
  return final_states_;
}

bool Automaton::ReadStrings(const std::string& string) {
  // std::cout << "Reading string: " << string << std::endl;
  return false;
}

