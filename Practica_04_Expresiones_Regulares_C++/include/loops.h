/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file loops.h
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

#ifndef LOOPS_H_
#define LOOPS_H_

#include <regex>
#include <string>
#include <vector>

class Loops {
 public:
  Loops() = default;
  ~Loops() = default;

 private:
  std::string type_;
  int line_;
  static int for_count_;
  static int while_count_;
  static std::vector<Loops> loops_;
};

#endif  // LOOPS_H_