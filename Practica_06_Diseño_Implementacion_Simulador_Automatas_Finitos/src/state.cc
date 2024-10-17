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

State::State() {
  state_id_ = "";
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