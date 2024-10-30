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
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "alphabet.h"
#include "symbol.h"

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
  Alphabet non_terminals_;
  Symbol start_symbol_;
  // Las producciones son una secuencia de símbolos terminales y no terminales
  std::map<Symbol, std::vector<std::string>> productions_;
};

#endif  // GRAMMAR_H