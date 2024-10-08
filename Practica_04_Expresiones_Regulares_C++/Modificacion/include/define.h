/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file define.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DEFINE_H_
#define DEFINE_H_

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Define {
 public:
  Define() = default;
  ~Define() = default;

  void SearchDefine(std::string line, int line_number);

  friend std::ostream& operator<<(std::ostream& os, const Define& define_) {
    for (auto define_ : define_.defines_) {
      os << "[Line " << define_.line_ << "] DEFINE " << define_.define_name_ << " " << define_.define_value_ << std::endl;
    }
    return os;
  }

 private:
  int line_;
  std::string define_name_;
  std::string define_value_;
  std::vector<Define> defines_;
};

#endif  // DEFINE_H_