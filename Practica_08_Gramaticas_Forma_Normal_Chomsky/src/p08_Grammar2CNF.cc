/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 * @file p08_Grammar2CNF.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../include/functions.h"
#include "../include/grammar.h"

int main(int argc, char* argv[]) {
  try {
    if (check_parameters(argc, argv)) {
      std::cout << "Original Grammar: \n";
      Grammar grammar(argv[1]);
      std::cout << grammar << std::endl;
      std::cout << "Grammar in Chomsky Normal Form: \n";
      Grammar cnf_grammar = grammar.Convert2CNF();
      std::cout << cnf_grammar << std::endl;
      write_file(argv[2], cnf_grammar);
    } else {
      exit(EXIT_FAILURE);
    }
  } catch (std::string message) {
    std::cerr << "ERROR: " << message << std::endl;
  } catch (std::runtime_error message) {
    std::cerr << "ERROR: " << message.what() << std::endl;
  }

  return 0;
}