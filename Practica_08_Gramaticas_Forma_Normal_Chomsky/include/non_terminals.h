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

class NonTerminals {
 public:
  NonTerminals() = default;
  NonTerminals(const std::vector<std::string>& non_terminals);
  NonTerminals(const std::vector<std::string>& non_terminals, const std::multimap<std::string, std::vector<std::string>>& productions);

  // Getters and setters
  std::multimap<std::string, std::vector<std::string>> GetProductions() const;
  void SetProductions(const std::multimap<std::string, std::vector<std::string>>& productions);
  void AddProduction(const std::string& left_symbol, const std::vector<std::string>& right_symbols);  // New method
  std::vector<std::string> GetNonTerminals() const;
  void SetNonTerminals(const std::vector<std::string>& non_terminals);

  bool find(const Symbol& symbol) const;
  void push_back(const std::string& non_terminal);
  friend std::ostream& operator<<(std::ostream& os, const NonTerminals& non_terminals);

 private:
  std::vector<std::string> non_terminals_;
  std::multimap<std::string, std::vector<std::string>> productions_;
};

#endif  // NON_PRODUCTIONS_H