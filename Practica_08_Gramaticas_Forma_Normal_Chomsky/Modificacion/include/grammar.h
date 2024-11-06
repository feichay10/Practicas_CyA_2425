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

  Alphabet GetTerminals() const { return terminals_; }
  Symbol GetStartSymbol() const { return start_symbol_; }
  NonTerminals GetNonTerminals() const { return non_terminals_; }
  void SetTerminals(const Alphabet& terminals) { terminals_ = terminals; }
  void SetStartSymbol(const Symbol& start_symbol) { start_symbol_ = start_symbol; }
  void SetNonTerminals(const NonTerminals& non_terminals) { non_terminals_ = non_terminals; }

  bool isTerminal(const Symbol& symbol) const;
  bool isNonTerminal(const Symbol& symbol) const;
  Grammar Convert2CNF() const;
  bool hasUnitaryProductions() const;
  bool hasEmptyProductions() const;
  friend std::ostream& operator<<(std::ostream& os, const Grammar& grammar);

  // Modificacion: Guardas todos los no terminales desde el estado de arranque
  void ReachableNonTerminals() const;

 private:
  Alphabet terminals_;
  Symbol start_symbol_;
  NonTerminals non_terminals_;
};

#endif  // GRAMMAR_H