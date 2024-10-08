/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file include.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/include.h"

void Include::SearchInclude(std::string line, int line_number) {
  std::regex include_regex(R"(^\s*#include\s*["<](.*)[">]\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, include_regex)) {
    Include include_;
    include_.line_ = line_number;
    include_.include_name_ = match.str(1);
    includes_.push_back(include_);
  }
}