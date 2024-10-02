/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../include/functions.h"

bool check_parameters(int argc, char* argv[]) {
  if (argc == 1 || (std::string(argv[1]) == "--help" && argc == 2)) {
    std::cerr << (argc == 1 ? kHowUse : kHelp) << std::endl;
    return false;
  }

  return true;
}

void read_code(std::string file_name, Match_result& match_result) {
  std::ifstream file(file_name);
  std::string line;

  if (!file.is_open()) {
    throw std::string("File not found.");
  }
  
  while (std::getline(file, line)) {
    std::cout << match_result.line_number_++ << ": " << line << std::endl;
    match_result.variable_.SearchInt(line, match_result.line_number_ - 1);
    match_result.variable_.SearchDouble(line, match_result.line_number_ - 1);
  }

  file.close();
}

void print_results(Match_result& match_result) {
  std::cout << "\nVARIABLES: " << std::endl;
  match_result.variable_.PrintInt();
  match_result.variable_.PrintDouble();
}