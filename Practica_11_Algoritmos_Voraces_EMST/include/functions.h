/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
 * @file functions.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "colors.h"

const std::string kHowUse =
    RED_BOLD +
    std::string(
        "How to use: ./main <input_file>\n "
        "Try './main --help || -h' for more information.") +
    RESET;

const std::string kHelp =
    BOLD +
    std::string(
        "Usage: ./p06_automata_simulator [OPTIONS] automaton_file strings_file\n"
        "\n"
        "Simulate the behavior of a finite automaton for given input strings.\n"
        "\n"
        "Options:\n"
        "  -h, --help    Show this help message and exit\n"
        "\n"
        "Arguments:\n"
        "  automaton_file    File containing the automaton data\n"
        "  strings_file      File containing the strings to check\n"
        "\n"
        "Trace Mode:\n"
        "  If compiled with 'make trace', the program will run in trace mode, providing detailed\n"
        "  step-by-step output of the automaton's state transitions and processing of input strings.\n"
        "\n"
        "Description:\n"
        "  This program allows you to simulate any finite automaton specified by an input file.\n"
        "  The program will read from a file the characteristics of a finite automaton and then\n"
        "  simulate the automaton's behavior for the strings given as input (also through an input file).\n"
        "\n"
        "  The automaton data file should have the following format:\n"
        "    Line 1: Alphabet symbols separated by spaces\n"
        "    Line 2: Total number of states of the automaton\n"
        "    Line 3: Start state\n"
        "    Next, there will be a line for each of the states. Each line will contain the following numbers,\n"
        "    separated by spaces:\n"
        "      - State identifier number. The states of the automaton will be represented by natural numbers.\n"
        "        The numbering of the states will correspond to the first natural numbers starting from 0.\n"
        "      - A 1 if it is an acceptance state and a 0 otherwise.\n"
        "      - Number of transitions the state has.\n"
        "      - Next, for each of the transitions, and using spaces as a separator, the following information\n"
        "        will be detailed:\n"
        "          - Input symbol required for the transition to occur. To represent the empty string (not\n"
        "            consuming a symbol from the input), the symbol & will be used.\n"
        "          - Destination state of the transition.\n"
        "\n"
        "Example of a file specifying a DFA:\n"
        "  0  1  -> Alphabet\n"
        "  4     -> Total number of states\n"
        "  0     -> Start state (initial)\n"
        "  0 0 2 0 2 1 1\n"
        "  1 1 2 0 1 1 1\n"
        "  2 0 2 0 1 1 3\n"
        "  3 0 2 0 2 1 3\n") + RESET;
    
bool check_parameters(int argc, char* argv[]);
bool check_file(std::string file_name);
void read_file(std::string file_name);
void printMenu();

#endif  // FUNCTIONS_H