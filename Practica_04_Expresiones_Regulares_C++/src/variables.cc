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

void Variables::SearchVariable(std::string line, int line_number) {
  std::regex variable_regex(R"(^\s*(int|double)\s+(\w+)\s*(=|\{)?\s*(\d+)?\s*[};]\s*$)");
  std::smatch match;

  if (std::regex_search(line, match, variable_regex)) {
    Variables variable;
    variable.type_ = match[1];
    variable.name_ = match[2];
    variable.line_ = line_number;
    variable.initialized_ = match[3] == "=" || match[3] == "{";
    variables_.push_back(variable);
  }
}
