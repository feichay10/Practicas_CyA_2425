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

const std::string kHowUse =
    "How to use: ./p02_strings filein.txt fileout.txt opcode\n"
    "Try './p02_strings --help' for more information.";

const std::string kHelp =
    "Los Opcodes son:\n"
    "  1. Longitud\n"
    "  2. Inversa\n"
    "  3. Prefijos\n"
    "  4. Sufijos\n"
    "  5. Subcadenas\n";

bool check_parameters(int argc, char *argv[]);
std::vector<std::string> read_file(std::string file_name);

#endif  // FUNCTIONS_H