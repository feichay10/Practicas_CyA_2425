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
#include "../include/language.h"

Chain::Chain() {}

Chain::Chain(std::string chain) {
  for (int i = 0; i < chain.size(); i++) {
    chain_.push_back(Symbol(chain[i]));
  }
}

std::vector<Symbol> Chain::GetChain() const {
  return chain_;
}

void Chain::SetChain(std::string chain) {
  chain_.clear();
  for (int i = 0; i < chain.size(); i++) {
    chain_.push_back(Symbol(chain[i]));
  }
}

void Chain::InsertSymbol(Symbol& symbol) {
  chain_.push_back(symbol);
}

int Chain::Length() {
  return chain_.size();
}

Chain Chain::Reverse() {
  Chain reversed_chain;
  for (int i = chain_.size() - 1; i >= 0; i--) {
    reversed_chain.chain_.push_back(chain_[i]);
  }
  return reversed_chain;
}

Language Chain::Prefixes() {
  std::set<Chain> prefixes;
  Chain prefix;
  // prefixes.insert(Chain("&")); // Agregamos el símbolo "&"

  for (int i = 0; i < chain_.size(); i++) {
    prefix.InsertSymbol(chain_[i]);
    prefixes.insert(prefix);
  }

  return Language(prefixes);
}

Language Chain::Suffixes() {
  std::set<Chain> suffixes;
  Chain suffix;
  // suffixes.insert(Chain("&")); // Agregamos el símbolo "&"

  for (int i = chain_.size() - 1; i >= 0; i--) {
    suffix.InsertSymbol(chain_[i]);
    suffixes.insert(suffix);
  }

  return Language(suffixes);
}

Language Chain::Subchains() {
  std::set<Chain> subchains;
  for (int i = 0; i < chain_.size(); i++) {
    for (int j = i; j < chain_.size(); j++) {
      Chain subchain;
      for (int k = i; k <= j; k++) {
        subchain.chain_.push_back(chain_[k]);
      }
      subchains.insert(subchain);
    }
  }
  return Language(subchains);
}