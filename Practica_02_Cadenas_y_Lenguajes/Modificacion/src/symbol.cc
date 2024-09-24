/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/symbol.h"

/**
 * @brief Construct a new Symbol:: Symbol object
 * 
 */
Symbol::Symbol() {}

/**
 * @brief Construct a new Symbol:: Symbol object
 * 
 * @param symbol 
 */
Symbol::Symbol(char symbol) {
  symbol_ = symbol;
}

/**
 * @brief Get the Symbol object
 * 
 * @return char 
 */
char Symbol::GetSymbol() const {
  return symbol_;
}

/**
 * @brief Overload the << operator
 * 
 * @param os 
 * @param symbol 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.GetSymbol();
  return os;
}