/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file String.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#include "symbol.h"

class Language;

/**
 * @brief Class that represents a String
 * 
 */
class String {
 public:
  String();
  String(std::string String);
  ~String() = default;

  std::vector<Symbol> GetString() const;
  void SetString(std::string String);

  void InsertSymbol(Symbol& symbol);

  int Length();
  String Reverse();
  Language Prefixes();
  Language Suffixes();
  Language Substrings();

  int CountSymbols();

  friend std::ostream& operator<<(std::ostream& os, const String& string) {
    for (Symbol symbol : string.GetString()) {
      os << symbol.GetSymbol();
    }
    return os;
  }

  friend bool operator<(const String& string1, const String& string2) {
    return string1.GetString().size() < string2.GetString().size();
  }

 private:
  std::vector<Symbol> string_;
};



#endif  // STRING_H