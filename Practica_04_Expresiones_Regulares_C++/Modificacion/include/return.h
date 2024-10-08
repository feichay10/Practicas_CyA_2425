/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file return.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef RETURN_H_
#define RETURN_H_

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Return {
 public:
  Return() = default;
  ~Return() = default;

  void SearchReturn(std::string line, int line_number);

  friend std::ostream& operator<<(std::ostream& os, const Return& return_) {
    for (auto return_ : return_.returns_) {
      os << "[Line " << return_.line_ << "] RETURN";
      if (return_.return_value_ != "") {
        os << " " << return_.return_value_;
      }
      os << std::endl;
    }
    return os;
  }

 private:
  int line_;
  std::string return_value_;
  std::vector<Return> returns_;
};

#endif  // RETURN_H_