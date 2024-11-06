/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file String.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
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
#include "alphabet.h"

class Language;

/**
 * @brief Class that represents a String
 * 
 */
class String {
 public:
  String();
  String(const std::string& string);
  ~String() = default;

  std::vector<Symbol> GetString() const;
  void SetString(const std::string& string);
  std::string GetString();

  void InsertSymbol(Symbol& symbol);
  int Length();
  int size() const;

  friend std::ostream& operator<<(std::ostream& os, const String& string);
  bool operator==(const String& other) const;
  friend bool operator<(const String& string1, const String& string2);

 private:
  std::vector<Symbol> string_;
};



#endif  // STRING_H