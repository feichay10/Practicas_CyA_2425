/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file functions.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

/**
 * @brief Check if the file exists and can be opened
 *
 * @param file_name
 * @return True if the file exists and can be opened
 */
bool check_file(std::string file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file" + file_name);
    return false;
  }
  file.close();
  return true;
}

/**
 * @brief Check if the parameters are correct
 *
 * @param argc
 * @param argv
 * @return True if the parameters are correct
 */
bool check_parameters(int argc, char* argv[]) {
  if (argc == 1 || (std::string(argv[1]) == "--help" && argc == 2) || (std::string(argv[1]) == "-h" && argc == 2)) {
    std::cerr << (argc == 1 ? kHowUse : kHelp) << std::endl;
    return false;
  }

  if (argc < 3 || argc > 3) {
    std::cerr << kHowUse << std::endl;
    return false;
  }

  try {
    check_file(argv[1]);
    // check_file(argv[2]);
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return false;
  }

  return true;
}

/**
 * @brief Read the file and store the lines in a vector
 *
 * @param file_name
 * @return A vector with the lines of the file
 */
template <typename T>
std::vector<T> read_file(const std::string& file_name) {
  std::vector<T> lines;
  std::ifstream file(file_name);

  std::string line;
  while (std::getline(file, line)) {
    lines.push_back(T(line));
  }
  file.close();
  return lines;
}

/**
 * @brief Writes the given grammar to a file.
 *
 * This function opens a file with the specified name and writes the contents
 * of the provided Grammar object to it. The file is closed after writing.
 *
 * @param file_name The name of the file to write to.
 * @param grammar The Grammar object to be written to the file.
 */
void write_file(const std::string& file_name, const Grammar& grammar) {
  std::ofstream file(file_name);

  file << grammar.GetNonTerminals().size() << std::endl;
  for (const auto& non_terminal : grammar.GetNonTerminals().GetNonTerminals()) {
    file << non_terminal << std::endl;
  }
  file << grammar.GetTerminals().size() << std::endl;
  for (const auto& terminal : grammar.GetTerminals().GetAlphabet()) {
    file << terminal.GetSymbol() << std::endl;
  }
  file << grammar.GetNonTerminals().GetProductions().size() << std::endl;
  for (const auto& production : grammar.GetNonTerminals().GetProductions()) {
    file << production.first << " ";
    for (const auto& symbol : production.second) {
      file << symbol;
    }
    file << std::endl;
  }

  file.close();
}