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
#include "variables.h"

void Variables::SearchInt(std::string line, int line_number) {
  std::regex int_regex(R"((int)\s+(\w+)\s*(=)?\s*(\d+)?;)");
  std::smatch match;

  if (std::regex_search(line, match, int_regex)) {
    name_ = match[2];
    type_ = match[1];
    line_ = line_number;
    initialized_ = match[3] == "=";
    int_count_++;
    variables_.push_back(*this);
  }
}

void Variables::SearchDouble(std::string line, int line_number) {
  std::regex double_regex(R"((double)\s+(\w+)\s*(=)?\s*([\d.]+)?;)");
  std::smatch match;

  if (std::regex_search(line, match, double_regex)) {
    name_ = match[2];
    type_ = match[1];
    line_ = line_number;
    initialized_ = match[3] == "=";
    double_count_++;
    variables_.push_back(*this);
  }
}