/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file loops.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/loops.h"

void Loops::SearchLoops(std::string line, int line_number) {
  std::regex loop_regex(R"(^\s*(for\s*\(\s*.*\s*;\s*.*\s*;\s*.*\s*\)|while\s*\(\s*.*\s*\))\s*\{)");
  std::smatch match;

  if (std::regex_search(line, match, loop_regex)) {
    Loops loop;
    if (line.find("for") != std::string::npos) {
      loop.type_ = "for";
      for_count_++;
    } else if (line.find("while") != std::string::npos) {
      loop.type_ = "while";
      while_count_++;
    }
    loop.line_ = line_number;
    loops_.push_back(loop);
  }
}
