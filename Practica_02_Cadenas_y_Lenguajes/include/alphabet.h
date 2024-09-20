/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <set>
#include <string>

#include "chain.h"
#include "symbol.h"

class Alphabet {
 public:
  Alphabet();
  Alphabet(std::string alphabet);

  // void SetAlphabet(std::string alphabet);
  std::set<Symbol> GetAlphabet() const;

  // Get the alphabet from a chain
  void GetAlphabetFromChain(Chain chain);

  // operator <<
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet) {
    os << "Alphabet: {";
    for (auto it = alphabet.alphabet_.begin(); it != alphabet.alphabet_.end(); ++it) {
      if (it != alphabet.alphabet_.begin()) {
        os << ", ";
      }
      os << *it;
    }
    os << "}" << std::flush;  // Forzando la escritura en el buffer
    return os;
  }

 private:
  std::set<Symbol> alphabet_;
};

#endif  // ALPHABET_H