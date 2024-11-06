/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file symbol.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
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
 * @brief Construct a new Symbol:: Symbol object
 * 
 * @param symbol 
 */
Symbol::Symbol(const std::string& symbol) {
  symbol_ = symbol[0];
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
 * @brief Insert a String object
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Symbol::operator<(const Symbol& other) const {
  return symbol_ < other.symbol_;
}

/**
 * @brief Insert a Symbol object
 * 
 * @param os 
 * @param symbol 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
  os << symbol.symbol_;
  return os;
}

/**
 * @brief Extract a Symbol object
 * 
 * @param is 
 * @param symbol 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Symbol& symbol) {
  is >> symbol.symbol_;
  return is;
}
