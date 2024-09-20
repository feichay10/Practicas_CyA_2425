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
#include <vector>
#include <algorithm>

#include "symbol.h"

class Language;

class Chain {
 public:
  Chain();
  Chain(std::string chain);

  std::vector<Symbol> GetChain() const;
  void SetChain(std::string chain);

  // Chain operations
  int Length();
  Chain Reverse();
  Language Prefixes();
  Language Suffixes();

  // operator << 
  friend std::ostream& operator<<(std::ostream& os, const Chain& chain) {
    for (Symbol symbol : chain.GetChain()) {
      os << symbol.GetSymbol();
    }
    return os;
  }

  // operator <
  friend bool operator<(const Chain& chain1, const Chain& chain2) {
    return chain1.GetChain() < chain2.GetChain();
  }

  friend struct CompareByLength;

 private:
  std::vector<Symbol> chain_;
};



#endif  // CHAIN_H