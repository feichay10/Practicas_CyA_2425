/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 * @file non_terminals.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Class to represent the non terminals of a grammar
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/non_terminals.h"

// Definitions

NonTerminals::NonTerminals(const std::vector<std::string>& non_terminals) {
  non_terminals_ = non_terminals;
}

NonTerminals::NonTerminals(const std::vector<std::string>& non_terminals, const std::multimap<Symbol, std::vector<std::string>>& productions) {
  non_terminals_ = non_terminals;
  productions_ = productions;
}

std::multimap<Symbol, std::vector<std::string>> NonTerminals::GetProductions() const {
  return productions_;
}

void NonTerminals::SetProductions(const std::multimap<Symbol, std::vector<std::string>>& productions) {
  productions_ = productions;
}

void NonTerminals::AddProduction(const Symbol& left_symbol, const std::vector<std::string>& right_symbols) {
  productions_.emplace(left_symbol, right_symbols);
}

std::vector<std::string> NonTerminals::GetNonTerminals() const {
  return non_terminals_;
}

void NonTerminals::SetNonTerminals(const std::vector<std::string>& non_terminals) {
  non_terminals_ = non_terminals;
}

bool NonTerminals::find(const Symbol& symbol) const {
  for (const auto& non_terminal : non_terminals_) {
    if (non_terminal == symbol) {
      return true;
    }
  }
  return false;
}

void NonTerminals::push_back(const std::string& non_terminal) {
  non_terminals_.push_back(non_terminal);
}

std::ostream& operator<<(std::ostream& os, const NonTerminals& non_terminals) {
  for (const auto& nt : non_terminals.non_terminals_) {
    os << nt << " ";
  }
  os << std::endl;
  for (const auto& p : non_terminals.productions_) {
    os << " " << p.first << " -> ";
    for (const auto& s : p.second) {
      os << s;
    }
    os << std::endl;
  }
  return os;
}