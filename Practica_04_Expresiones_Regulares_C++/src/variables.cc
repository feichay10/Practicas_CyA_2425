/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/variables.h"

void Variables::SearchVariable(std::string line, int line_number) {
  std::regex variable_regex(R"(^\s*(int|double)\s+(\w+)\s*(=\s*(\d+(\.\d+)?)|\{\s*(\d+(\.\d+)?)\s*\})?\s*;\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, variable_regex)) {
    Variables variable;
    variable.type_ = match.str(1);
    variable.name_ = match.str(2);
    variable.line_ = line_number;
    if (match.str(3) != "") {
      variable.initialized_ = true;
      if (match.str(4) != "") {
        variable.initialized_value_ = match.str(4);
      } else if (match.str(6) != "") {
        variable.initialized_value_ = match.str(6);
      }
    }
    if (variable.type_ == "int") {
      int_count_++;
    } else {
      double_count_++;
    }
    variables_.push_back(variable);
  }
}
