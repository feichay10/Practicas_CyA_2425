/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file state.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <set>

#include "symbol.h"

class Transition;

/**
 * @brief Class that represents a State
 * 
 */
class State {
 public:
  State();
  State(std::string name, bool start_state, bool aceptation_state);
  State(std::string name, bool start_state, bool aceptation_state, std::set<Transition>& transitions);
  ~State() = default;

  bool IsAceptationState() const;
  bool IsStartState() const;
  std::string GetStateId() const;
  std::set<Transition> GetTransitions(Symbol symbol);

  bool operator<(const State& state) const;
  bool operator==(const State& other) const;
  
 private:
  bool start_state_;
  bool aceptation_state_;
  std::string state_id_;
  int trasitions_number_;
  std::set<Transition> transitions_;
};