/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "colors.h"
#include "variables.h"
#include "loops.h"

const std::string kHowUse =
    RED_BOLD +
    std::string(
        "How to use: ./p04_code_analyzer code.cc codescheme.txt\n"
        "Try './p04_code_analyzer --help' for more information.") +
    RESET;

const std::string kHelp =
    BOLD + std::string(
        "This program reads a file with a list of strings and performs "
        "operations on them.\n"
        "Those operations are determined by the opcode. The Opcodes are:\n"
        "  1. Alphabet - Displays the alphabet of the strings.\n"
        "  2. Length - Calculates the length of each string.\n"
        "  3. Reverse - Reverses each string.\n"
        "  4. Prefixes - Lists all prefixes of each string.\n"
        "  5. Suffixes - Lists all suffixes of each string.\n\n"
        "Example: ./bin/p02_strings data/filein.txt data/fileout.txt 1") +
    RESET;

struct Match_result {
  Variables variable_;
  Loops loop_;
  bool main_found_ = false;
  int line_number_ = 1;
};

bool check_parameters(int argc, char* argv[]);
void read_code(std::string file_name, Match_result& match_result);
void print_results(Match_result& match_result);

#endif  // FUNCTIONS_H