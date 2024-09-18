/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file chain.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <set>
#include <string>

#include "symbol.h"

class Chain {
 public:
  Chain();
  Chain(std::string chain);

  void SetChain(std::string chain);
  std::string GetChain() const;

  // Chain operations
  int Length();
  Chain Reverse();
  std::set<Chain> Prefixes();
  std::set<Chain> Suffixes();

 private:
  std::set<Symbol> chain_;
};

#endif  // CHAIN_H