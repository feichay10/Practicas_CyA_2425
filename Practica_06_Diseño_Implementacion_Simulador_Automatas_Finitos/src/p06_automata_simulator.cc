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
  std::vector<std::string> strings_data;
  Automaton* automaton = nullptr;

  try {
    if (check_parameters(argc, argv)) {
      automaton_data = read_file(argv[1]);
      strings_data = read_file(argv[2]);
      if (check_automata(automaton_data)) {
        std::cout << "Es un DFA" << std::endl;
        automaton = new DFA(automaton_data);
      } else {
        std::cout << "Es un NFA" << std::endl;
        automaton = new NFA(automaton_data);
      }
      // for (int i = 0; i < strings_data.size(); i++) {
      //   automaton->ReadStrings(strings_data[i]);
      // }

      // Obtener los estados del autómata
      std::cout << "========================================" << std::endl;
      if (automaton != nullptr) {
        std::set<State> states = automaton->GetStates();
        std::cout << "Estados: ";
        for (auto it = states.begin(); it != states.end(); it++) {
          std::cout << "\nEl estado " << it->GetStateId() << ": " << std::endl;
          std::cout << "  - Es estado de arranque: " << it->IsStartState() << std::endl;
          std::cout << "  - Es estado de aceptación: " << it->IsAceptationState() << std::endl;
          // Imprimir solo las transiciones asociadas a este estado
          std::cout << "  - Transiciones: " << std::endl;
          for (auto it2 = automaton->GetTransitions().begin(); it2 != automaton->GetTransitions().end(); it2++) {
            if (it2->GetFrom() == *it) {
              std::cout << "    - De " << it2->GetFrom().GetStateId() << " a " << it2->GetTo().GetStateId() << " con el símbolo " << it2->GetSymbol() << std::endl;
            }
          }
        }
      }
      

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