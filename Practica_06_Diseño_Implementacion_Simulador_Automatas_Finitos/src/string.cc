/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file String.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/string.h"
#include "../include/language.h"
#include "string.h"

/**
 * @brief Construct a new String:: String object
 * 
 */
String::String() {}

/**
 * @brief Construct a new String:: String object
 * 
 * @param String 
 */
String::String(const std::string& string) {
  for (int i = 0; i < string.size(); i++) {
    string_.push_back(Symbol(string[i]));
  }
}

/**
 * @brief Get the String object
 * 
 * @return std::vector<Symbol> 
 */
std::vector<Symbol> String::GetString() const {
  return string_;
}

/**
 * @brief Set the String object
 * 
 * @param String 
 */
void String::SetString(const std::string& string) {
  string_.clear();
  for (int i = 0; i < string.size(); i++) {
    string_.push_back(Symbol(string[i]));
  }
}

std::string String::GetString() {
  std::string string;
  for (int i = 0; i < string_.size(); i++) {
    string += string_[i].GetSymbol();
  }
  return string;
}

/**
 * @brief Insert a Symbol object
 * 
 * @param symbol 
 */
void String::InsertSymbol(Symbol& symbol) {
  string_.push_back(symbol);
}

/**
 * @brief Get the Length object
 * 
 * @return int 
 */
int String::Length() {
  if (string_.size() == 1 && string_[0].GetSymbol() == '&') {
    return 0;
  }

  return string_.size();
}

/**
 * @brief Reverse the String object
 * 
 * @return Reverse String object
 */
String String::Reverse() {
  String reversed_string;
  for (int i = string_.size() - 1; i >= 0; i--) {
    reversed_string.string_.push_back(string_[i]);
  }
  return reversed_string;
}

/**
 * @brief Get the Prefixes from a String object
 * 
 * @return Language of chains of prefixes
 */
Language String::Prefixes() {
  std::set<String> prefixes;
  String prefix;
  for (int i = 0; i < string_.size(); i++) {
    prefix.InsertSymbol(string_[i]);
    prefixes.insert(prefix);
  }
  return Language(prefixes);
}

/**
 * @brief Get the Suffixes from a String object
 * 
 * @return Language of chains of suffixes
 */
Language String::Suffixes() {
  std::set<String> suffixes;
  for (int i = 0; i < string_.size(); i++) {
    String suffix;
    for (int j = i; j < string_.size(); j++) {
      suffix.string_.push_back(string_[j]);
    }
    suffixes.insert(suffix);
  }
  return Language(suffixes);
}

/**
 * @brief Get the SubStrings from a String object
 * 
 * @return Language of chains of substrings
 */
Language String::Substrings() {
  std::set<String> substrings;
  for (int i = 0; i < string_.size(); i++) {
    for (int j = i; j < string_.size(); j++) {
      String substring;
      for (int k = i; k <= j; k++) {
        substring.string_.push_back(string_[k]);
      }
      substrings.insert(substring);
    }
  }
  return Language(substrings);
}

/**
 * @brief Get the size object
 * 
 * @return int 
 */
int String::size() const {
  return string_.size() - 1;
}