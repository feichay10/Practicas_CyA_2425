/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file string.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/string.h"

/**
 * @brief Construct a new String:: String object
 * 
 */
String::String() {}

/**
 * @brief Construct a new String:: String object
 * 
 * @param String 
 */
String::String(const std::string& string) {
  for (int i = 0; i < string.size(); i++) {
    string_.push_back(Symbol(string[i]));
  }
}

/**
 * @brief Get the String object
 * 
 * @return std::vector<Symbol> 
 */
std::vector<Symbol> String::GetString() const {
  return string_;
}

/**
 * @brief Set the String object
 * 
 * @param String 
 */
void String::SetString(const std::string& string) {
  string_.clear();
  for (int i = 0; i < string.size(); i++) {
    string_.push_back(Symbol(string[i]));
  }
}

std::string String::GetString() {
  std::string string;
  for (int i = 0; i < string_.size(); i++) {
    string += string_[i].GetSymbol();
  }
  return string;
}

/**
 * @brief Insert a Symbol object
 * 
 * @param symbol 
 */
void String::InsertSymbol(Symbol& symbol) {
  string_.push_back(symbol);
}

/**
 * @brief Get the Length object
 * 
 * @return int 
 */
int String::Length() {
  if (string_.size() == 1 && string_[0].GetSymbol() == '&') {
    return 0;
  }

  return string_.size();
}

/**
 * @brief Get the size object
 * 
 * @return int 
 */
int String::size() const {
  return string_.size() - 1;
}

/**
 * @brief Overload the << operator
 * 
 * @param os 
 * @param string 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const String& string) {
  for (Symbol symbol : string.GetString()) {
    os << symbol.GetSymbol();
  }
  return os;
}

/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool String::operator==(const String& other) const {
  return this->string_ == other.string_;
}

/**
 * @brief Overload the < operator
 * 
 * @param string1 
 * @param string2 
 * @return true 
 * @return false 
 */
bool operator<(const String& string1, const String& string2) {
  return string1.GetString().size() < string2.GetString().size();
}