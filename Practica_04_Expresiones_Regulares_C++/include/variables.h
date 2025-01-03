/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Variables {
 public:
  Variables() = default;
  ~Variables() = default;

  void SearchVariable(std::string line, int line_number);

  friend std::ostream& operator<<(std::ostream& os, const Variables& variable) {
    for (auto variable : variable.variables_) {
      if (variable.type_ == "int") {
        os << "[Line " << variable.line_ << "] INT: " << variable.name_;
      } else {
        os << "[Line " << variable.line_ << "] DOUBLE: " << variable.name_;
      }
      if (variable.initialized_) {
        os << " = " << variable.initialized_value_;
      }
      os << std::endl;
    }
    return os;
  }

 private:
  std::string type_;
  std::string name_;
  int line_;
  bool initialized_;
  std::string initialized_value_;
  int int_count_ = 0;
  int double_count_ = 0;
  std::vector<Variables> variables_;
};

#endif  // VARIABLES_H_