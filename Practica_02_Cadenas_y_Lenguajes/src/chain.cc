/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file chain.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/chain.h"

Chain::Chain() {}

Chain::Chain(std::string chain) {
  for (char symbol : chain) {
    chain_.insert(Symbol(symbol));
  }
}

std::set<Symbol> Chain::GetChain() const {
  return chain_;
}

void Chain::SetChain(std::string chain) {
  chain_.clear();
  for (char symbol : chain) {
    chain_.insert(Symbol(symbol));
  }
}

int Chain::Length() {
  return chain_.size();
}

// Chain Chain::Reverse() {
//   std::set<Symbol> reversed_chain;
//   for (auto it = chain_.rbegin(); it != chain_.rend(); ++it) {
//     reversed_chain.insert(*it);
//   }
//   return Chain(reversed_chain);
// }

// Language Chain::Prefixes() {
//   std::set<Chain> prefixes;
//   std::set<Symbol> prefix;
//   for (Symbol symbol : chain_) {
//     prefix.insert(symbol);
//     prefixes.insert(Chain(prefix));
//   }
//   return Language(prefixes);
// }

// Language Chain::Suffixes() {
//   std::set<Chain> suffixes;
//   std::set<Symbol> suffix;
//   for (Symbol symbol : chain_) {
//     suffix.insert(symbol);
//     suffixes.insert(Chain(suffix));
//   }
//   return Language(suffixes);
// }