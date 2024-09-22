/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file chain.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/chain.h"
#include "../include/language.h"

/**
 * @brief Construct a new Chain:: Chain object
 * 
 */
Chain::Chain() {}

/**
 * @brief Construct a new Chain:: Chain object
 * 
 * @param chain 
 */
Chain::Chain(std::string chain) {
  for (int i = 0; i < chain.size(); i++) {
    chain_.push_back(Symbol(chain[i]));
  }
}

/**
 * @brief Get the Chain object
 * 
 * @return std::vector<Symbol> 
 */
std::vector<Symbol> Chain::GetChain() const {
  return chain_;
}

/**
 * @brief Set the Chain object
 * 
 * @param chain 
 */
void Chain::SetChain(std::string chain) {
  chain_.clear();
  for (int i = 0; i < chain.size(); i++) {
    chain_.push_back(Symbol(chain[i]));
  }
}

/**
 * @brief Insert a Symbol object
 * 
 * @param symbol 
 */
void Chain::InsertSymbol(Symbol& symbol) {
  chain_.push_back(symbol);
}

/**
 * @brief Get the Length object
 * 
 * @return int 
 */
int Chain::Length() {
  return chain_.size();
}

/**
 * @brief Reverse the Chain object
 * 
 * @return Chain 
 */
Chain Chain::Reverse() {
  Chain reversed_chain;
  for (int i = chain_.size() - 1; i >= 0; i--) {
    reversed_chain.chain_.push_back(chain_[i]);
  }
  return reversed_chain;
}

/**
 * @brief Get the Prefixes from a Chain object
 * 
 * @return Language 
 */
Language Chain::Prefixes() {
  std::set<Chain> prefixes;
  Chain prefix;

  for (int i = 0; i < chain_.size(); i++) {
    prefix.InsertSymbol(chain_[i]);
    prefixes.insert(prefix);
  }

  return Language(prefixes);
}

/**
 * @brief Get the Suffixes from a Chain object
 * 
 * @return Language 
 */
Language Chain::Suffixes() {
  std::set<Chain> suffixes;
  Chain suffix; 

  for (int i = chain_.size() - 1; i >= 0; i--) {
    suffix.InsertSymbol(chain_[i]);
    suffixes.insert(suffix);
  }

  return Language(suffixes);
}

/**
 * @brief Get the Subchains from a Chain object
 * 
 * @return Language 
 */
Language Chain::Subchains() {
  std::set<Chain> subchains;
  for (int i = 0; i < chain_.size(); i++) {
    for (int j = i; j < chain_.size(); j++) {
      Chain subchain;
      for (int k = i; k <= j; k++) {
        subchain.chain_.push_back(chain_[k]);
      }
      subchains.insert(subchain);
    }
  }
  return Language(subchains);
}

// Contar el numero de simbolos diferentes en una cadena -> aba = 2/3 (numero de simbolos diferentes/longitud de la cadena)
/**
 * @brief Count the number of different symbols in a Chain object
 * 
 * @return int 
 */
int Chain::CountSymbols() {
  std::set<Symbol> symbols;
  for (int i = 0; i < chain_.size(); i++) {
    symbols.insert(chain_[i]);
  }
  return symbols.size();
}