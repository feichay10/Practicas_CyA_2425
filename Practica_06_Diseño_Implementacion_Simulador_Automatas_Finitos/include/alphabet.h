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

#include "symbol.h"

class String;

/**
 * @brief Class that represents an alphabet
 * 
 */
class Alphabet {
 public:
  Alphabet();
  Alphabet(std::string alphabet);
  Alphabet(std::set<Symbol> alphabet);
  ~Alphabet() = default;

  std::set<Symbol> GetAlphabet() const;
  void insert(Symbol symbol);

  bool IsSymbolInAlphabet(Symbol symbol) const;

 private:
  std::set<Symbol> alphabet_;
};

std::ostream &operator<<(std::ostream &os, const Alphabet &alphabet);

#endif  // ALPHABET_H