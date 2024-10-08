/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file define.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/define.h"

void Define::SearchDefine(std::string line, int line_number) {
  std::regex define_regex(R"(^\s*#define\s*([a-zA-Z_]\w*)\s*(.*)\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, define_regex)) {
    Define define_;
    define_.line_ = line_number;
    define_.define_name_ = match.str(1);
    define_.define_value_ = match.str(2);
    defines_.push_back(define_);
  }
}