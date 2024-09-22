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

/**
 * @brief Check if the file exists and can be opened
 * 
 * @param file_name 
 * @return true 
 * @return false 
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
 * @return true 
 * @return false 
 */
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
    std::cerr << RED_BOLD << "Invalid opcode" << RESET << std::endl;
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

/**
 * @brief Read the file and store the lines in a vector
 * 
 * @param file_name 
 * @return std::vector<std::string> 
 */
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

/**
 * @brief Write the data in a file
 * 
 * @tparam T 
 * @param file_name 
 * @param data 
 */
template <typename T>
void write_file(std::string file_name, T& data) {
  std::ofstream file(file_name);
  for (int i = 0; i < data.size(); i++) {
    file << data[i] << std::endl;
  }
  file.close();
}

/**
 * @brief Manage the entry lines and store the strings in a vector
 * 
 * @param entry_lines 
 * @param strings 
 */
void manage_entry(std::vector<std::string>& entry_lines, std::vector<String>& strings) {
  String string;
  Alphabet alphabet;

  for (unsigned int i = 0; i < entry_lines.size(); i++) {      
    for (unsigned int j = 0; j < entry_lines[i].size(); j++) { 
      if (entry_lines[i][j] == SPACE) {
        std::string str_string = entry_lines[i].substr(0, j);
        std::string str_alphabet = entry_lines[i].substr(j + 1, entry_lines[i].size());
        alphabet = Alphabet(str_alphabet);

        bool valid_String = true;
        for (unsigned int k = 0; k < str_string.size(); ++k) {
          if (str_string[k] == '&') {
            std::cerr << "The String " << PURPLE_BOLD << str_string << RESET << " contains the symbol '&' and cannot be used." << std::endl << std::endl;
            valid_String = false;
            break;
          }
          if (!alphabet.IsSymbolInAlphabet(str_string[k])) {
            valid_String = false;
            break;
          }
        }

        if (valid_String) {
          string.SetString(str_string);
          strings.push_back(string);
          std::cout << "String: " << str_string << " - " << string.CountSymbols() << "/" << string.Length() << std::endl;
          std::cout << "Alphabet: " << str_alphabet << std::endl << std::endl;
        } else if (!str_string.empty() && str_string.find('&') == std::string::npos) {
          std::cerr << "The String " << PURPLE_BOLD << str_string << RESET << " does not belong to the alphabet " << CYAN_BOLD << str_alphabet << RESET << std::endl << std::endl;
        }
        break;
      }
    }
  }
}

/**
 * @brief Menu that performs the operations on the Strings deoending on the opcode
 * 
 * @param file_out 
 * @param opcode 
 * @param Strings 
 */
void menu(std::string file_out, int opcode, std::vector<String>& strings) {
  std::ofstream file(file_out);
  switch (opcode) {
    case 1: {
      Alphabet alphabet;
      std::vector<Alphabet> alphabets;
      std::cout << BOLD << "Alphabets:" << RESET << std::endl;
      for (int i = 0; i < strings.size(); i++) {
        alphabet.GetAlphabetFromString(strings[i]);
        alphabets.push_back(alphabet);
        std::cout << alphabet << std::endl;
      }
      write_file(file_out, alphabets);
    } break;
    case 2: {
      std::vector<int> lengths;
      std::cout << BOLD << "Lengths:" << RESET << std::endl;
      for (int i = 0; i < strings.size(); i++) {
        lengths.push_back(strings[i].Length());
        std::cout << strings[i].Length() << std::endl;
      }
      write_file(file_out, lengths);
    } break;
    case 3: {
      std::vector<String> reversed;
      std::cout << BOLD << "Reversed Strings:" << RESET << std::endl;
      for (int i = 0; i < strings.size(); i++) {
        reversed.push_back(strings[i].Reverse());
        std::cout << strings[i].Reverse() << std::endl;
      }
      write_file(file_out, reversed);
    }
      break;
    case 4: {
      Language prefixes;
      std::vector<Language> prefixes_vector;
      std::cout << BOLD << "Prefixes:" << RESET << std::endl;
      for (int i = 0; i < strings.size(); i++) {
        prefixes = strings[i].Prefixes();
        prefixes_vector.push_back(prefixes);
        std::cout << prefixes << std::endl;
      }
      write_file(file_out, prefixes_vector);
    } break;
    case 5: {
      Language suffixes;
      std::vector<Language> suffixes_vector;
      std::cout << BOLD << "Suffixes:" << RESET << std::endl;
      for (int i = 0; i < strings.size(); i++) {
        suffixes = strings[i].Suffixes();
        suffixes_vector.push_back(suffixes);
        std::cout << suffixes << std::endl;
      }
      write_file(file_out, suffixes_vector);
    } break;
    case 6: {
      Language subStrings;
      std::vector<Language> subStrings_vector;
      std::cout << BOLD << "SubStrings:" << RESET << std::endl;
      for (int i = 0; i < strings.size(); i++) {
        subStrings = strings[i].Substrings();
        subStrings_vector.push_back(subStrings);
        std::cout << subStrings << std::endl;
      }
      write_file(file_out, subStrings_vector);
    }
    default:
      break;
  }
}

