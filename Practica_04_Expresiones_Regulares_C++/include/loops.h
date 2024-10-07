/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file loops.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef LOOPS_H_
#define LOOPS_H_

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Loops {
 public:
  Loops() = default;
  ~Loops() = default;

  void SearchLoops(std::string line, int line_number);

  friend std::ostream& operator<<(std::ostream& os, const Loops& loop) {
    for (auto loop : loop.loops_) {
      os << "[Line " << loop.line_ << "] LOOP: " << loop.type_ << std::endl;
    }
    return os;
  }

 private:
  std::string type_;
  int line_;
  int for_count_ = 0;
  int while_count_ = 0;
  std::vector<Loops> loops_;
};

#endif  // LOOPS_H_