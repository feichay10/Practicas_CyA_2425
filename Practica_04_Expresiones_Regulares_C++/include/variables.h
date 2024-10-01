/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Para cada variable se almacenara, ademas de su tipo (int y double), 
 * su nombre, la linea en la que se declara y si se ha inicializado o no en la 
 * propia declaracíon. Se llevará un control de cuantas variables de cada tipo 
 * se han definido en el programa.
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include <regex>
#include <string>
#include <vector>

class Variables {
 public:
  Variables() = default;
  ~Variables() = default;

  void SearchInt(std::string line, int line_number);
  void SearchDouble(std::string line, int line_number);

 private:
  std::string name_;
  std::string type_;
  int line_;
  bool initialized_;
  static int int_count_;
  static int double_count_;
  static std::vector<Variables> variables_;
};

#endif  // VARIABLES_H_