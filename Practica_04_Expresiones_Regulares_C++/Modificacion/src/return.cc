/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file return.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/return.h"

void Return::SearchReturn(std::string line, int line_number) {
  std::regex return_regex(R"(^\s*return\s*([a-zA-Z_]\w*|\d+(\.\d+)?)?\s*;\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, return_regex)) {
    Return return_;
    return_.line_ = line_number;
    if (match.str(1) != "") {
      return_.return_value_ = match.str(1);
    }
    returns_.push_back(return_);
  }
}