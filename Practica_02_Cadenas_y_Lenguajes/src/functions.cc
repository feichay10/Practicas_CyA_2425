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

  if (atoi(argv[3]) < 1 || atoi(argv[3]) > 6) {
    std::cerr << "Invalid opcode" << std::endl;
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

void manage_entry(std::vector<std::string>& entry_lines, std::vector<Chain>& chains) {
  Chain chain;
  Alphabet alphabet;

  for (unsigned int i = 0; i < entry_lines.size(); i++) {      // Bucle que recorre las líneas de entrada, cada pos del vector es una línea
    for (unsigned int j = 0; j < entry_lines[i].size(); j++) { // Bucle que recorre los caracteres de la línea
      if (entry_lines[i][j] == SPACE) {
        std::string str_chain = entry_lines[i].substr(0, j);
        chain.SetChain(str_chain);
        chains.push_back(chain);
        std::string str_alphabet = entry_lines[i].substr(j + 1, entry_lines[i].size());
        alphabet = Alphabet(str_alphabet);
        std::cout << "Chain: " << str_chain << std::endl;
        std::cout << "Alphabet: " << str_alphabet << std::endl << std::endl;
        break;
      }
    }
  }
}

void menu(std::string file_out, int opcode, std::vector<Chain>& chains) {
  std::ofstream file(file_out);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  switch (opcode) {
    case 1: {
      Alphabet alphabet;
      for (int i = 0; i < chains.size(); i++) {
        alphabet.GetAlphabetFromChain(chains[i]);
        std::cout << alphabet << std::endl;
        file << alphabet << std::endl;
      }
    } break;
    case 2:
      for (int i = 0; i < chains.size(); i++) {
        std::cout << chains[i].Length() << std::endl;
        file << chains[i].Length() << std::endl;
      }
      break;
    case 3:
      for (int i = 0; i < chains.size(); i++) {
        std::cout << chains[i].Reverse() << std::endl;
        file << chains[i].Reverse() << std::endl;
      }
      break;
    case 4: {
      Language prefixes;
      for (int i = 0; i < chains.size(); i++) {
        prefixes = chains[i].Prefixes();
        std::cout << prefixes << std::endl;
        file << prefixes << std::endl;
      }
    } break;
    case 5: {
      Language suffixes;
      for (int i = 0; i < chains.size(); i++) {
        suffixes = chains[i].Suffixes();
        std::cout << suffixes << std::endl;
        file << suffixes << std::endl;
      }
    } break;
    case 6: {
      Language subchains;
      for (int i = 0; i < chains.size(); i++) {
        subchains = chains[i].Subchains();
        std::cout << subchains << std::endl;
        file << subchains << std::endl;
      }
    } break;
    default:
      break;
  }
}