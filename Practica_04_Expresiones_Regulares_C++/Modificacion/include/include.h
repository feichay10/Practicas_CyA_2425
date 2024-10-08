/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file include.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Include {
 public:
  Include() = default;
  ~Include() = default;

  void SearchInclude(std::string line, int line_number);

  friend std::ostream& operator<<(std::ostream& os, const Include& include_) {
    for (auto include_ : include_.includes_) {
      os << "[Line " << include_.line_ << "] INCLUDE " << include_.include_name_ << std::endl;
    }
    return os;
  }

 private:
  int line_;
  std::string include_name_;
  std::vector<Include> includes_;
};

#endif  // INCLUDE_H_