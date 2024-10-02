/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief se detectar ́an las declaraciones de variables de tipo int
 * asi como las de tipo double. Se supondra que cada declaracion de variable se 
 * hara en una unica linea y que en cada linea tendremos una unica declaracion. 
 * Por lo tanto, no se declararan dos o m ́as variables en una misma linea ni 
 * se considerar ́an aquellas variables declaradas dentro de bloques como bucles 
 * for pues no se encuentran declaradas en una linea independiente.
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/variables.h"

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

void Variables::SearchInt(std::string line, int line_number) {
  std::regex int_regex(R"(^\s*int\s+(\w+)\s*(=|\{)?\s*(\d+)?\s*[};]\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, int_regex)) {
    Variables variable;
    variable.type_ = "int";
    variable.name_ = match[1];
    variable.line_ = line_number;
    variable.initialized_ = match[2] == "=" || match[2] == "{";
    variables_.push_back(variable);
    int_count_++;
  }
}

void Variables::SearchDouble(std::string line, int line_number) {
  std::regex double_regex(R"(^\s*double\s+(\w+)\s*(=|\{)?\s*(\d+)?\s*[};]\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, double_regex)) {
    Variables variable;
    variable.type_ = "double";
    variable.name_ = match[1];
    variable.line_ = line_number;
    variable.initialized_ = match[2] == "=" || match[2] == "{";
    variables_.push_back(variable);
    double_count_++;
  }
}

void Variables::PrintInt() {
  for (auto variable : variables_) {
    if (variable.type_ == "int") {
      std::cout << variable.type_ << " " << variable.name_ << " in line "
                << variable.line_ << " is "
                << (variable.initialized_ ? "initialized" : "not initialized")
                << std::endl;
    }
  }
}

void Variables::PrintDouble() {
  for (auto variable : variables_) {
    if (variable.type_ == "double") {
      std::cout << variable.type_ << " " << variable.name_ << " in line "
                << variable.line_ << " is "
                << (variable.initialized_ ? "initialized" : "not initialized")
                << std::endl;
    }
  }
}