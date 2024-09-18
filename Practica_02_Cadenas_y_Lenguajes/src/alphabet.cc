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

void Alphabet::SetAlphabet(std::set<Symbol> alphabet) {
  alphabet_ = alphabet;
}

std::set<Symbol> Alphabet::GetAlphabet() const {
  return alphabet_;
}

void Alphabet::GetAlphabetFromChain(Chain chain) {
  std::set<Symbol> alphabet;
  for (Symbol symbol : chain.GetChain()) {
    alphabet.insert(symbol);
  }
  SetAlphabet(alphabet);
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
  os << "Alphabet: { ";
  for (Symbol symbol : alphabet.GetAlphabet()) {
    os << symbol.GetSymbol() << " ";
  }
  os << "}";
  return os;
}