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


/**
 * @brief Constructs a NonTerminals object.
 * 
 * @param non_terminals A vector of strings representing the non-terminal symbols.
 * @param productions A multimap where each key is a non-terminal symbol and the value is a vector of strings representing the production rules.
 */
NonTerminals::NonTerminals(const std::vector<std::string>& non_terminals, const std::multimap<std::string, std::vector<std::string>>& productions) {
  non_terminals_ = non_terminals;
  productions_ = productions;
}

/**
 * @brief Retrieves the productions associated with non-terminals.
 *
 * This function returns a multimap where each key is a non-terminal symbol
 * and the corresponding value is a vector of strings representing the 
 * productions for that non-terminal.
 *
 * @return A multimap containing the non-terminal symbols and their associated productions.
 */
std::multimap<std::string, std::vector<std::string>> NonTerminals::GetProductions() const {
  return productions_;
}

/**
 * @brief Sets the productions for the non-terminals.
 * 
 * This function assigns the given productions to the internal
 * productions map of the NonTerminals class.
 * 
 * @param productions A multimap where the key is a string representing
 *                    a non-terminal symbol and the value is a vector
 *                    of strings representing the production rules.
 */
void NonTerminals::SetProductions(const std::multimap<std::string, std::vector<std::string>>& productions) {
  productions_ = productions;
}

/**
 * @brief Adds a production to the set of productions.
 *
 * This function inserts a new production into the productions set. 
 * A production consists of a left-hand side non-terminal symbol and 
 * a right-hand side vector of symbols (which can be terminals or non-terminals).
 *
 * @param left_symbol The non-terminal symbol on the left-hand side of the production.
 * @param right_symbols A vector of symbols on the right-hand side of the production.
 */
void NonTerminals::AddProduction(const std::string& left_symbol, const std::vector<std::string>& right_symbols) {
  productions_.insert(std::pair<std::string, std::vector<std::string>>(left_symbol, right_symbols));
}

/**
 * @brief Retrieves the list of non-terminal symbols.
 * 
 * This function returns a vector containing all the non-terminal symbols
 * stored in the NonTerminals object.
 * 
 * @return std::vector<std::string> A vector of non-terminal symbols.
 */
std::vector<std::string> NonTerminals::GetNonTerminals() const {
  return non_terminals_;
}

/**
 * @brief Sets the non-terminal symbols for the grammar.
 * 
 * This function assigns a list of non-terminal symbols to the 
 * non_terminals_ member variable of the NonTerminals class.
 * 
 * @param non_terminals A vector of strings representing the non-terminal symbols.
 */
void NonTerminals::SetNonTerminals(const std::vector<std::string>& non_terminals) {
  non_terminals_ = non_terminals;
}

/**
 * @brief Adds a non-terminal symbol to the collection.
 * 
 * This function appends the given non-terminal symbol to the end of the 
 * non_terminals_ vector.
 * 
 * @param non_terminal The non-terminal symbol to be added.
 */
void NonTerminals::push_back(const std::string& non_terminal) {
  non_terminals_.push_back(non_terminal);
}

int NonTerminals::size() const { 
  return non_terminals_.size();
}