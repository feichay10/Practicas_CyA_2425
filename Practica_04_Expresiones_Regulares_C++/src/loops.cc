/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file loops.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Se detectar ́an los bucles de tipo for y los bucles de tipo while. Para 
 * cada bucle detectado se almacenara el tipo de bucle y la l ́ınea del codigo
 * en la que se ha encontrado. Ademas, se llevara un control del numero de 
 * bucles de cada tipo que se han utilizado en el programa.
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/loops.h"

int Loops::for_count_ = 0;
int Loops::while_count_ = 0;
std::vector<Loops> Loops::loops_;

void Loops::SearchFor(std::string line, int line_number) {
  std::regex for_regex(R"(^\s*for\s*\(\s*.*\s*;\s*.*\s*;\s*.*\s*\)\s*\{)");
  std::smatch match;

  if (std::regex_search(line, match, for_regex)) {
    Loops loop;
    loop.type_ = "for";
    loop.line_ = line_number;
    loops_.push_back(loop);
    for_count_++;
  }
}

void Loops::SearchWhile(std::string line, int line_number) {
  std::regex while_regex(R"(^\s*while\s*\(\s*.*\s*\)\s*\{)");
  std::smatch match;

  if (std::regex_search(line, match, while_regex)) {
    Loops loop;
    loop.type_ = "while";
    loop.line_ = line_number;
    loops_.push_back(loop);
    while_count_++;
  }
}

void Loops::PrintFor() {
  for (auto loop : loops_) {
    if (loop.type_ == "for") {
      std::cout << "For loop found at line " << loop.line_ << std::endl;
    }
  }
}

void Loops::PrintWhile() {
  for (auto loop : loops_) {
    if (loop.type_ == "while") {
      std::cout << "While loop found at line " << loop.line_ << std::endl;
    }
  }
}