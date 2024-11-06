/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file alphabet.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
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
  void insert(const std::string& value);
  bool find(Symbol symbol) const;
  std::set<Symbol>::const_iterator end() const;

  int size() const;

  friend std::ostream &operator<<(std::ostream &os, const Alphabet &alphabet);

 private:
  std::set<Symbol> alphabet_;
};

#endif  // ALPHABET_H