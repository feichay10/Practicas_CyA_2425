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

#include "alphabet.h"
#include "string.h"
#include "colors.h"
#include "language.h"

const char SPACE = ' ';

const std::string kHowUse =
    RED_BOLD +
    std::string(
        "How to use: ./p02_strings filein.txt fileout.txt opcode\n"
        "Try './p02_strings --help' for more information.") +
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
        "  5. Suffixes - Lists all suffixes of each string.\n"
        "  6. Palindrome - Lists yes if a string is palindrome or no if not.\n\n"
        "Example: ./bin/p02_strings data/filein.txt data/fileout.txt 1") +
    RESET;

bool check_parameters(int argc, char* argv[]);
bool check_file(std::string file_name);
std::vector<std::string> read_file(std::string file_name);
template <typename T>
void write_file(std::string file_name, T& data, int opcode);
void write_file_palindrome(std::string file_name, std::vector<bool>& data);
void manage_entry(std::vector<std::string>& entry_lines,
                  std::vector<String>& strings);
void menu(std::string file_out, int opcode, std::vector<String>& strings);

#endif  // FUNCTIONS_H