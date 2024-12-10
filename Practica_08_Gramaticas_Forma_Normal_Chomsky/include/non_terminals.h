/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 * @file non_terminals.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Class to represent the non terminals of a grammar
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef NON_PRODUCTIONS_H
#define NON_PRODUCTIONS_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "symbol.h"

/**
 * @class NonTerminals
 * @brief This class represents a collection of non-terminal symbols and their associated productions in a context-free grammar.
 * 
 * The NonTerminals class provides methods to manage non-terminal symbols and their productions.
 */
class NonTerminals {
 public:
  NonTerminals() = default;
  NonTerminals(const std::vector<std::string>& non_terminals, const std::multimap<std::string, std::vector<std::string>>& productions);

  std::multimap<std::string, std::vector<std::string>> GetProductions() const;
  void SetProductions(const std::multimap<std::string, std::vector<std::string>>& productions);
  void AddProduction(const std::string& left_symbol, const std::vector<std::string>& right_symbols);
  std::vector<std::string> GetNonTerminals() const;
  void SetNonTerminals(const std::vector<std::string>& non_terminals);

  void push_back(const std::string& non_terminal);
  int size() const;
  
 private:
  std::vector<std::string> non_terminals_;
  std::multimap<std::string, std::vector<std::string>> productions_;
};

#endif  // NON_PRODUCTIONS_H