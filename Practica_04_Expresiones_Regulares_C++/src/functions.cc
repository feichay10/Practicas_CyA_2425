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

bool check_file(std::string file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file" + file_name);
    return false;
  }
  file.close();
  return true;
}

bool check_parameters(int argc, char* argv[]) {
  if (argc == 1 || (std::string(argv[1]) == "--help" && argc == 2)) {
    std::cerr << (argc == 1 ? kHowUse : kHelp) << std::endl;
    return false;
  }

  if (argc < 3 || argc > 3) {
    std::cerr << kHowUse << std::endl;
    return false;
  }
  
  try {
    check_file(argv[1]);
    check_file(argv[2]);
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }
  

  return true;
}

void read_code(std::string file_name, Match_result& match_result) {
  std::ifstream file(file_name);
  std::string line;
  std::regex expresion_main("\\s*int\\s*main\\s*\\(.*\\).*");
  
  while (std::getline(file, line)) {
    match_result.main_found_ = match_result.main_found_ || std::regex_search(line, expresion_main);
    match_result.line_number_++;
    match_result.variable_.SearchVariable(line, match_result.line_number_ - 1);
    match_result.loop_.SearchLoops(line, match_result.line_number_ - 1);
    match_result.line_comment_.SearchComments(line, match_result.line_number_ - 1);
  }

  file.close();
}

void print_results(Match_result& match_result) {
  std::cout << "PROGRAM: " << match_result.program_name_ << std::endl;
  std::cout << "DESCRIPTION: " << std::endl;
  std::string description = match_result.line_comment_.PrintDescription();
  std::cout << (description.empty() ? "False" : description) << std::endl;
  std::cout << "\nVARIABLES: " << std::endl;
  std::cout << match_result.variable_;
  std::cout << "\nSTATEMENTS: " << std::endl;
  std::cout << match_result.loop_;
  std::cout << "\nMAIN FUNCTION:\n" << (match_result.main_found_ ? "True" : "False") << std::endl;
  std::cout << "\nCOMMENTS: " << std::endl;
  std::cout << match_result.line_comment_;
}

void write_results(std::string file_name, Match_result& match_result) {
  std::ofstream file(file_name);

  file << "PROGRAM: " << match_result.program_name_ << std::endl;
  file << "DESCRIPTION: " << std::endl;
  std::string description = match_result.line_comment_.PrintDescription();
  file << (description.empty() ? "False" : description) << std::endl;
  file << "\nVARIABLES: " << std::endl;
  file << match_result.variable_;
  file << "\nSTATEMENTS: " << std::endl;
  file << match_result.loop_;
  file << "\nMAIN FUNCTION:\n" << (match_result.main_found_ ? "True" : "False") << std::endl;
  file << "\nCOMMENTS: " << std::endl;
  file << match_result.line_comment_;

  file.close();
}