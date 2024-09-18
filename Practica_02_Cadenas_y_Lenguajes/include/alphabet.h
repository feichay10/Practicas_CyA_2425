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

#include "symbol.h"
#include "chain.h"

class Alphabet {
 public:
  Alphabet();

  void SetAlphabet(std::set<Symbol> alphabet);
  std::set<Symbol> GetAlphabet() const;

  // get the alphabet from a chain
  void GetAlphabetFromChain(Chain chain);

  // operator <<
  friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);

 private:
  std::set<Symbol> alphabet_;
};

#endif  // ALPHABET_H