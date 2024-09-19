/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file symbol.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

class Symbol {
 public:
  Symbol();
  Symbol(char symbol);

  char GetSymbol() const;

  bool operator<(const Symbol& other) const {
    return symbol_ < other.symbol_;
  }

  // operator << 
  friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
    os << symbol.GetSymbol();
    return os;
  }

 private:
  char symbol_;
};

#endif  // SYMBOL_H