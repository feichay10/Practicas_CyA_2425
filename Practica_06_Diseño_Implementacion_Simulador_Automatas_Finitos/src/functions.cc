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
bool check_automaton(const std::vector<std::string>& automaton_data) {
  std::stringstream ss(automaton_data[0]);
  Alphabet alphabet;
  Symbol symbol;
  while (ss >> symbol) {
    alphabet.insert(Symbol(symbol));
  }

  int num_states = std::stoi(automaton_data[1]);  // Number of states
  std::string initial_state = automaton_data[2];  // Initial state

  // Process the states
  for (int i = 3; i < automaton_data.size(); ++i) {
    std::stringstream ss_state(automaton_data[i]);
    int state_id, is_acceptance, num_transitions;
    ss_state >> state_id >> is_acceptance >> num_transitions;

    std::unordered_map<std::string, std::set<int>> transitions;  // For each symbol, the set of destination states

    for (int t = 0; t < num_transitions; ++t) {
      std::string symbol;
      int destination_state;
      ss_state >> symbol >> destination_state;

      // If the transition is epsilon (&), it is already an NFA
      if (symbol == "&") {
        return false;  // It is an NFA
      }

      // Add the transition to the map of transitions
      transitions[symbol].insert(destination_state);

      // If we find more than one transition for the same symbol, it is an NFA
      if (transitions[symbol].size() > 1) {
        return false;  // It is an NFA
      }
    }
  }

  return true;  // If it passed all checks, it is a DFA
}

void print_automaton_data(Automaton* automaton) {
  if (automaton != nullptr) {
    std::cout << "Alfabeto: ";
    // for (auto it = automaton->GetAlphabet().GetAlphabet().begin();
    //      it != automaton->GetAlphabet().GetAlphabet().end(); it++) {
    //   std::cout << *it << " ";
    // }
    std::cout << std::endl;
    std::cout << "Numero de estados: " << automaton->GetNumStates() << std::endl;
    std::set<State> states = automaton->GetStates();
    std::cout << "Estados: ";
    for (auto it = states.begin(); it != states.end(); it++) {
      std::cout << "\nEl estado " << it->GetStateId() << ": " << std::endl;
      std::cout << "  - Es estado de arranque: " << (it->IsStartState() ? "si" : "no") << std::endl;
      std::cout << "  - Es estado de aceptación: " << (it->IsAceptationState() ? "si" : "no") << std::endl;
      std::cout << "  - Transiciones: " << std::endl;
      for (auto it2 = automaton->GetTransitions().begin(); it2 != automaton->GetTransitions().end(); it2++) {
        if (it2->GetFrom() == *it) {
          std::cout << "    - " << it2->GetFrom().GetStateId() << " -> " << it2->GetSymbol() << " -> " << it2->GetTo().GetStateId() << std::endl;
        }
      }
    }
  }
}