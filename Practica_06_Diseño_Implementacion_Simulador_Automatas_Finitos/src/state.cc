/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file state.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/state.h"
#include "../include/transition.h"

/**
 * @brief Construct a new State:: State object
 * 
 */
State::State() {
  state_id_ = "";
  start_state_ = false;
  aceptation_state_ = false;
  trasitions_number_ = 0;
}

/**
 * @brief Construct a new State:: State object
 * 
 * @param state_id 
 * @param start_state 
 * @param aceptation_state 
 */
State::State(std::string state_id, bool start_state, bool aceptation_state) {
  state_id_ = state_id;
  start_state_ = start_state;
  aceptation_state_ = aceptation_state;
  trasitions_number_ = 0;
}

/**
 * @brief Construct a new State:: State object
 * 
 * @param name 
 * @param start_state 
 * @param aceptation_state 
 * @param transitions 
 */
State::State(std::string name, bool start_state, bool aceptation_state, std::set<Transition>& transitions) {
  state_id_ = name;
  start_state_ = start_state;
  aceptation_state_ = aceptation_state;
  transitions_ = transitions;
  trasitions_number_ = transitions.size();
}

/**
 * @brief Indicates if the state is an aceptation state
 * 
 * @return true 
 * @return false 
 */
bool State::IsAceptationState() const { 
  return aceptation_state_; 
}

/**
 * @brief Indicates if the state is a start state
 * 
 * @return true 
 * @return false 
 */
bool State::IsStartState() const {
  return start_state_;
}

/**
 * @brief Get the State Id object
 * 
 * @return std::string 
 */
std::string State::GetStateId() const {
  return state_id_;
}

/**
 * @brief Get the Transitions object
 * 
 * @param symbol 
 * @return std::set<Transition> 
 */
std::set<Transition> State::GetTransitions(Symbol symbol) {
  std::set<Transition> transitions;
  for (auto it = transitions_.begin(); it != transitions_.end(); it++) {
    if (it->GetSymbol() == symbol) {
      transitions.insert(*it);
    }
  }
  return transitions;
}

/**
 * @brief Overload of the operator <
 * 
 * @param state 
 * @return true 
 * @return false 
 */
bool State::operator<(const State& state) const {
  return state_id_ < state.state_id_;
}

/**
 * @brief Overload of the operator ==
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool State::operator==(const State& other) const {
  return this->state_id_ == other.state_id_; 
}