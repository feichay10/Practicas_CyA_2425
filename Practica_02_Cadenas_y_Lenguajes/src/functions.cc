/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

bool check_parameters(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << kHowUse << std::endl;
    return false;
  }

  if (std::string(argv[1]) == "--help") {
    std::cout << kHelp << std::endl;
    return false;
  }
  
  if (argc < 4) {
    std::cerr << kHowUse << std::endl;
    return false;
  }
  return true;
}

std::vector<std::string> read_file(std::string file_name) {
  std::vector<std::string> lines;
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }
  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(line);
    std::cout << line << std::endl;
  }
  file.close();
  return lines;
}