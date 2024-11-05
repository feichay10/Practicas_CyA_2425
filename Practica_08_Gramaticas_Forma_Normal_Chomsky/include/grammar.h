/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 * @file grammar.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "symbol.h"
#include "non_terminals.h"

/**
 * @class Grammar
 * @brief Represents a context-free grammar.
 * 
 * This class provides functionalities to handle context-free grammars,
 * including checking for terminal and non-terminal symbols, converting
 * the grammar to Chomsky Normal Form (CNF), and checking for unitary
 * and empty productions.
 */
class Grammar {
 public:
  Grammar() = default;
  Grammar(const std::string& file_name);

  bool isTerminal(const Symbol& symbol) const;
  bool isNonTerminal(const Symbol& symbol) const;
  Grammar Convert2CNF() const;
  bool hasUnitaryProductions() const;
  bool hasEmptyProductions() const;
  friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar);

 private:
  Alphabet terminals_;
  Symbol start_symbol_;
  NonTerminals non_terminals_;
};

#endif  // GRAMMAR_H