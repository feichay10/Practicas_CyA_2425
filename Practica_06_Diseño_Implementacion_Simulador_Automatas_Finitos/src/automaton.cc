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
void Automaton::ReadStrings(const std::string& string) {

}
