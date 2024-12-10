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

// Modificacion: Guardas todos los no terminales alcanzables desde el estado de arranque

/**
 * @brief The main function of the program.
 *
 * This function is the entry point of the program. It takes command line arguments
 * and performs the following steps:
 * 1. Checks the parameters using the check_parameters function.
 * 2. Reads a grammar from a file specified by the first command line argument.
 * 3. Prints the original grammar.
 * 4. Converts the grammar to Chomsky Normal Form using the Convert2CNF function.
 * 5. Prints the grammar in Chomsky Normal Form.
 * 6. Writes the Chomsky Normal Form grammar to a file specified by the second command line argument.
 *
 * If the parameters are invalid, the program exits with a failure status.
 * If an error occurs during the execution, an error message is printed to the standard error stream.
 *
 * @param argc The number of command line arguments.
 * @param argv An  grammar.ccarray of strings containing the command line arguments.
 * @return 0 if the program executed successfully, a non-zero value otherwise.
 */
int main(int argc, char* argv[]) {
  try {
    if (check_parameters(argc, argv)) {
      Grammar grammar(argv[1]);
      std::cout << "Original Grammar: \n" << grammar << std::endl;
      grammar.ReachableNonTerminals();
      Grammar cnf_grammar = grammar.Convert2CNF();
      std::cout << "\nGrammar in Chomsky Normal Form: \n" << cnf_grammar << std::endl;
      cnf_grammar.ReachableNonTerminals();
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