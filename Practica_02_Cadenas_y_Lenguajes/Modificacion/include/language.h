/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file language.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>
#include <set>

#include "symbol.h"
#include "string.h"

/**
 * @brief Class that represents a language
 * 
 */
class Language {
 public:
  Language();
  Language(std::set<String> language);
  ~Language() = default;

  std::set<String> GetLanguage() const;
  void SetLanguage(std::set<String> language);

  friend std::ostream& operator<<(std::ostream& os, const Language& language) {
    String empty_string("&");
    for (const String& string : language.GetLanguage()) {
      if (string.GetString() == empty_string.GetString()) {
        os << "{&}";
        return os;
      }
    }

    os << "{&, ";
    bool first = true;
    for (const String& string : language.GetLanguage()) {
      if (!first) {
        os << ", ";
      }
      os << string;
      first = false;
    }
    os << "}";

    return os;
  }

 private:
  std::set<String> language_;
};

#endif  // LANGUAGE_H