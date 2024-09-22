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
#include "chain.h"

class Language {
 public:
  Language();
  Language(std::set<Chain> language);
  ~Language() = default;

  std::set<Chain> GetLanguage() const;
  void SetLanguage(std::set<Chain> language);

  friend std::ostream& operator<<(std::ostream& os, const Language& language) {
    os << "{";
    bool first = true;
    for (const Chain& chain : language.GetLanguage()) {
      if (!first) {
        os << ", ";
      }
      os << chain;
      first = false;
    }
    os << "}";

    return os;
  }

 private:
  std::set<Chain> language_;
};

#endif  // LANGUAGE_H