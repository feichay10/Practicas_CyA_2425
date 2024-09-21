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

  if (argc < 4) {
    std::cerr << kHowUse << std::endl;
    return false;
  }

  int opcode = atoi(argv[3]);
  if (opcode < 1 || opcode > 6) {
    std::cerr << "Invalid opcode" << std::endl;
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

std::vector<std::string> read_file(std::string file_name) {
  std::vector<std::string> lines;
  std::ifstream file(file_name);

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

template <typename T>
void write_file(std::string file_name, T& data) {
  std::ofstream file(file_name);
  for (int i = 0; i < data.size(); i++) {
    file << data[i] << std::endl;
  }
  file.close();
}

void menu(std::string file_out, int opcode, std::vector<Chain>& chains) {
  std::ofstream file(file_out);

  switch (opcode) {
    case 1: {
      Alphabet alphabet;
      std::vector<Alphabet> alphabets;
      for (int i = 0; i < chains.size(); i++) {
        alphabet.GetAlphabetFromChain(chains[i]);
        alphabets.push_back(alphabet);
        std::cout << alphabet << std::endl;
      }
      write_file(file_out, alphabets);
    } break;
    case 2: {
      std::vector<int> lengths;
      for (int i = 0; i < chains.size(); i++) {
        lengths.push_back(chains[i].Length());
        std::cout << chains[i].Length() << std::endl;
      }
      write_file(file_out, lengths);
    } break;
    case 3: {
      std::vector<Chain> reversed;
      for (int i = 0; i < chains.size(); i++) {
        reversed.push_back(chains[i].Reverse());
        std::cout << chains[i].Reverse() << std::endl;
      }
      write_file(file_out, reversed);
    }
      break;
    case 4: {
      Language prefixes;
      std::vector<Language> prefixes_vector;
      for (int i = 0; i < chains.size(); i++) {
        prefixes = chains[i].Prefixes();
        prefixes_vector.push_back(prefixes);
        std::cout << prefixes << std::endl;
      }
      write_file(file_out, prefixes_vector);
    } break;
    case 5: {
      Language suffixes;
      std::vector<Language> suffixes_vector;
      for (int i = 0; i < chains.size(); i++) {
        suffixes = chains[i].Suffixes();
        suffixes_vector.push_back(suffixes);
        std::cout << suffixes << std::endl;
      }
      write_file(file_out, suffixes_vector);
    } break;
    case 6: {
      Language subchains;
      std::vector<Language> subchains_vector;
      for (int i = 0; i < chains.size(); i++) {
        subchains = chains[i].Subchains();
        subchains_vector.push_back(subchains);
        std::cout << subchains << std::endl;
      }
      write_file(file_out, subchains_vector);
    } break;
    default:
      break;
  }
}

