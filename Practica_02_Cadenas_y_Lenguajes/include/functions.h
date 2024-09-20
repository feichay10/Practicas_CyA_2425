/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "chain.h"
#include "alphabet.h"
#include "language.h"

const char SPACE = ' ';

const std::string kHowUse =
    "How to use: ./p02_strings filein.txt fileout.txt opcode\n"
    "Try './p02_strings --help' for more information.";

const std::string kHelp =
    "The Opcodes are:\n"
    "  1. Alphabet\n"
    "  2. Length\n"
    "  3. Reverse\n"
    "  4. Prefixes\n"
    "  5. Suffixes\n"
    "  6. Substrings\n";

bool check_parameters(int argc, char *argv[]);
std::vector<std::string> read_file(std::string file_name);
void manage_entry(std::vector<std::string>& entry_lines, std::vector<Chain>& chains);
void menu(std::string file_out, int opcode, std::vector<Chain>& chains);

#endif  // FUNCTIONS_H