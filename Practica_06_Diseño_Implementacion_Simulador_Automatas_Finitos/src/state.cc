/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file state.c
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/state.h"
#include "../include/transition.h"
// #include "state.h"

State::State() {
  state_id_ = "";
  start_state_ = false;
  aceptation_state_ = false;
  trasitions_number_ = 0;

}

State::State(int state_id) {
  state_id_ = std::to_string(state_id);
  start_state_ = false;
  aceptation_state_ = false;
  trasitions_number_ = 0;
}

State::State(std::string state_id, bool start_state, bool aceptation_state) {
  state_id_ = state_id;
  start_state_ = start_state;
  aceptation_state_ = aceptation_state;
  trasitions_number_ = 0;
}

State::State(std::string name, bool start_state, bool aceptation_state, std::set<Transition>& transitions) {
  state_id_ = name;
  start_state_ = start_state;
  aceptation_state_ = aceptation_state;
  transitions_ = transitions;
  trasitions_number_ = transitions.size();
}


bool State::IsAceptationState() const { 
  return aceptation_state_; 
}

bool State::IsStartState() const {
  return start_state_;
}

std::string State::GetStateId() const {
  return state_id_;
}

std::set<Transition> State::GetTransitions(Symbol symbol) {
  std::set<Transition> transitions;
  for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
    if (it->GetSymbol() == symbol) {
      transitions.insert(*it);
    }
  }
  return transitions;
}

