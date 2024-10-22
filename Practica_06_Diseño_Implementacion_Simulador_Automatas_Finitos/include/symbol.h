/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file symbol.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>

/**
 * @brief Class that represents a symbol
 * 
 */
class Symbol {
 public:
  Symbol();
  Symbol(char symbol);
  Symbol(std::string symbol);
  ~Symbol() = default;

  char GetSymbol() const;

  bool operator<(const Symbol& other) const;
  friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
  friend std::istream& operator>>(std::istream& is, Symbol& symbol);
  bool operator==(const Symbol& other) const;

 private:
  char symbol_;
};

#endif  // SYMBOL_H