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
  for (int i = 0; i < chain_.size(); i++) {
    Chain prefix;
    for (int j = 0; j <= i; j++) {
      prefix.chain_.push_back(chain_[j]);
    }
    prefixes.insert(prefix);
  }
  return Language(prefixes);
}

Language Chain::Suffixes() {
  std::set<Chain> suffixes;
  for (int i = 0; i < chain_.size(); i++) {
    Chain suffix;
    for (int j = i; j < chain_.size(); j++) {
      suffix.chain_.push_back(chain_[j]);
    }
    suffixes.insert(suffix);
  }
  return Language(suffixes);
}