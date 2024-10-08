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
#include "comments.h"
#include "loops.h"
#include "variables.h"
#include "return.h"
#include "include.h"
#include "define.h"

const std::string kHowUse =
    RED_BOLD +
    std::string(
        "How to use: ./p04_code_analyzer code.cc codescheme.txt\n"
        "Try './p04_code_analyzer --help' for more information.") +
    RESET;

const std::string kHelp =
    BOLD +
    std::string(
        "This program reads a C++ code and parses it using regular "
        "expressions. It will receive by command line the name of the input "
        "file (C++ code to be parsed) and the name of the output file "
        "(containing the parsed file). The information that this program will "
        "extract is the declaration of int and double variables, for and while "
        "loops, it will detect if it contains a main() function and the "
        "different comments of one line or multiple lines.") +
    RESET;

struct Match_result {
  std::string program_name_;
  Variables variable_;
  Loops loop_;
  bool main_found_ = false;
  int line_number_ = 1;
  Comments line_comment_;
  Comments multiple_comment_;
  Return return_;
  Include include_;
  Define define_;
};

bool check_file(std::string file_name);
bool check_parameters(int argc, char* argv[]);
void read_code(std::string file_name, Match_result& match_result);
void output_results(std::ostream& out, Match_result& match_result);
void print_results(Match_result& match_result);
void write_results(std::string file_name, Match_result& match_result);

#endif  // FUNCTIONS_H