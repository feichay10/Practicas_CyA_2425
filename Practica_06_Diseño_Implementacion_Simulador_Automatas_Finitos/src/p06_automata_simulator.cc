/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file p06_automata_simulator.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../include/functions.h"
#include "../include/automaton.h"
#include "../include/dfa.h"
#include "../include/nfa.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> automaton_data;
  std::vector<String> strings_data;
  Automaton* automaton = nullptr;

  try {
    if (check_parameters(argc, argv)) {
      automaton_data = read_file<std::string>(argv[1]);
      strings_data = read_file<String>(argv[2]);
      if (check_automaton(automaton_data)) {
        std::cout << " ==== Es un DFA ==== " << std::endl;
        automaton = new DFA(automaton_data);
      } else {
        std::cout << " ==== Es un NFA ==== " << std::endl;
        automaton = new NFA(automaton_data);
      }
      print_automaton_data(automaton);
      std::cout << "\n ==== Strings to check ==== " << strings_data.size() << std::endl;
      print_strings_on_automata(automaton, strings_data);
    } else {
      exit(EXIT_FAILURE);
    }
  } catch (std::string message) {
    std::cerr << "ERROR: " << message << std::endl;
  } catch (std::runtime_error message) {
    std::cerr << "ERROR: " << message.what() << std::endl;
  }

  delete automaton;

  return 0;
}