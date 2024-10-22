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
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "state.h"
#include "symbol.h"

/**
 * @brief Class that represents a Transition
 * 
 */
class Transition {
 public:
  Transition(const State& from, const Symbol& symbol, const State& to);
  ~Transition() = default;

  const State& GetFrom() const;
  const Symbol& GetSymbol() const;
  const State& GetTo() const;

  bool operator<(const Transition& transition) const;

 private:
  State from_;
  Symbol symbol_;
  State to_;
};