/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file alphabet.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/alphabet.h"

Alphabet::Alphabet() {}

Alphabet::Alphabet(std::string alphabet) {
  std::set<Symbol> alphabet_set;
  for (int i = 0; i < alphabet.size(); i++) {
    alphabet_set.insert(Symbol(alphabet[i]));
  }
  alphabet_ = alphabet_set;
}

std::set<Symbol> Alphabet::GetAlphabet() const {
  return alphabet_;
}

void Alphabet::GetAlphabetFromChain(Chain chain) {
  std::set<Symbol> alphabet;
  for (int i = 0; i < chain.GetChain().size(); i++) {
    alphabet.insert(chain.GetChain()[i]);
  }
  alphabet_ = alphabet;
}

bool Alphabet::IsSymbolInAlphabet(Symbol symbol) const {
  return alphabet_.find(symbol) != alphabet_.end();
}