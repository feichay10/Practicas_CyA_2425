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
  // if (argc == 1 || (std::string(argv[1]) == "--help" && argc == 2)) {
  //   std::cerr << (argc == 1 ? kHowUse : kHelp) << std::endl;
  //   return false;
  // }

  // if (argc < 4) {
  //   std::cerr << kHowUse << std::endl;
  //   return false;
  // }

  // int opcode = atoi(argv[3]);
  // if (opcode < 1 || opcode > 5) {
  //   std::cerr << RED_BOLD << "Invalid opcode" << RESET << std::endl;
  //   return false;
  // }

  // try {
  //   check_file(argv[1]);
  //   check_file(argv[2]);
  // } catch (const std::runtime_error& e) {
  //   std::cerr << e.what() << std::endl;
  //   return false;
  // }

  return true;
}

/**
 * @brief Read the file and store the lines in a vector
 * 
 * @param file_name 
 * @return A vector with the lines of the file
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
 * @param file_name The name of the file
 * @param data The data to be written 
 */
template <typename T>
void write_file(std::string file_name, T& data) {
  std::ofstream file(file_name);
  for (int i = 0; i < data.size(); i++) {
    file << data[i] << std::endl;
  }
  file.close();
}

// Comprobar si es un DFA o un NFA
bool check_automata(std::vector<std::string> data_automata) {
  // Leer el alfabeto
  std::stringstream ss(data_automata[0]);
  std::vector<std::string> alfabeto;
  std::string simbolo;
  while (ss >> simbolo) {
    alfabeto.push_back(simbolo);
  }

  int num_estados = std::stoi(data_automata[1]);     // Número de estados
  int estado_inicial = std::stoi(data_automata[2]);  // Estado inicial

  // Procesar los estados
  for (int i = 3; i < data_automata.size(); ++i) {
    std::stringstream ss_estado(data_automata[i]);
    int estado_id, es_aceptacion, num_transiciones;
    ss_estado >> estado_id >> es_aceptacion >> num_transiciones;

    std::unordered_map<std::string, std::set<int>> transiciones;  // Para cada simbolo, el set de estados destino

    for (int t = 0; t < num_transiciones; ++t) {
      std::string simbolo;
      int estado_destino;
      ss_estado >> simbolo >> estado_destino;

      // Si la transición es epsilon (&), ya es un NFA
      if (simbolo == "&") {
        return false;  // Es un NFA
      }

      // Añadir la transición al mapa de transiciones
      transiciones[simbolo].insert(estado_destino);

      // Si encontramos más de una transición para el mismo símbolo, es un NFA
      if (transiciones[simbolo].size() > 1) {
        return false;  // Es un NFA
      }
    }
  }

  return true;  // Si pasó todas las verificaciones, es un DFA
}

void check_strings_automata(Automaton& automaton, std::vector<std::string> strings_data) {
  for (size_t i = 0; i < strings_data.size(); ++i) {
    std::cout << "Reading string: " << strings_data[i] << std::flush;
    if (automaton.ReadStrings(strings_data[i])) {
      std::cout << " -> Accepted" << std::endl;
    } else {
      std::cout << " -> Rejected" << std::endl;
    }
  }
}