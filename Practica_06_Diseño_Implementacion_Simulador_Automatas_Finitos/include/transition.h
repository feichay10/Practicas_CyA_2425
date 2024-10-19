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

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "state.h"
#include "symbol.h"

// class State;

class Transition {
 public:
  Transition() = default;
  Transition(State from, Symbol symbol, State to);
  ~Transition() = default;

  const State& GetFrom() const;
  const Symbol& GetSymbol() const;
  const State& GetTo() const;

  bool operator<(const Transition& transition) const {
    if (from_ < transition.from_) {
      return true;
    } else if (from_ == transition.from_) {
      if (symbol_ < transition.symbol_) {
        return true;
      } else if (symbol_ == transition.symbol_) {
        return to_ < transition.to_;
      }
    }
    return false;
  }

 private:
  State from_;
  Symbol symbol_;
  State to_;
};