/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file transition.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"
#include "state.h"

// class State;

class Transition {
 public:
  Transition() = default;
  Transition(State from, Symbol symbol, State to);
  ~Transition() = default;

  State GetFrom() const;
  Symbol GetSymbol() const;
  State GetTo() const;

 private:
  State from_;
  Symbol symbol_;
  State to_;
};

#endif  // TRANSITION_H