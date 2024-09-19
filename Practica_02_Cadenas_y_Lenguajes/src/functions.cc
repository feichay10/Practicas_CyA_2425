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

// std::ostream& operator<<(std::ostream& os, const std::set<Symbol>& symbolSet) {
//     os << "{ ";
//     for (const auto& symbol : symbolSet) {
//         os << symbol << " "; // Usamos el operador << ya sobrecargado para Symbol
//     }
//     os << "}";
//     return os;
// }

bool check_parameters(int argc, char* argv[]) {
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
  }
  file.close();
  return lines;
}

void manage_entry(std::vector<std::string>& entry_lines, int opcode) {
  Chain chain;
  Alphabet alphabet;

  // Example entry lines:
  // abbab ab
  // 6793836 123456789
  // hola ahlo
  // chain = abbab, alphabet = {a, b}
  // chain = 6793836, alphabet = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
  // chain = hola, alphabet = {a, h, l, o}
  for (unsigned int i = 0; i < entry_lines.size(); i++) {
    for (int i = entry_lines.size() - 1; i >= 0; i--) {
      for (int j = 0; j < entry_lines[i].size(); j++) {
        if (entry_lines[i][j] == SPACE) {
          std::string entry_chain = entry_lines[i].substr(i + 1, entry_lines[i].size() - 1);
          chain.SetChain(entry_chain);
          alphabet.GetAlphabetFromChain(chain);
          break;
        }
      }
    }
  }

  std::cout << chain << std::endl;
  std::cout << alphabet << std::endl;
}