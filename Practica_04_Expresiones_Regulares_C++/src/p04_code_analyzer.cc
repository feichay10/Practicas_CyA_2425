/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file p04_code_analyzer.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../include/functions.h"
#include "../include/variables.h"

int main(int argc, char* argv[]) {
  Match_result match_result;

  try {
    if (check_parameters(argc, argv)) {
      read_code(argv[1], match_result);
      match_result.program_name_ = argv[1];
      print_results(match_result);
      write_results(argv[2], match_result);
    } else {
      exit(EXIT_FAILURE);
    }
  } catch (std::string message) {
    std::cerr << "ERROR: " << message << std::endl;
  } catch (std::runtime_error message) {
    std::cerr << "ERROR: " << message.what() << std::endl;
  }

  return 0;
}