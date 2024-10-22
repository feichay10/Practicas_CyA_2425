/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file language.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/language.h"

/**
 * @brief Construct a new Language:: Language object
 * 
 */
Language::Language() {}

/**
 * @brief Construct a new Language:: Language object
 * 
 * @param language 
 */
Language::Language(std::set<String> language) {
  language_ = language;
}

/**
 * @brief Get the Language object
 * 
 * @return std::set<String> 
 */
std::set<String> Language::GetLanguage() const {
  return language_;
}

/**
 * @brief Set the Language object
 * 
 * @param language 
 */
void Language::SetLanguage(std::set<String> language) {
  language_ = language;
}

/**
 * @brief Overloaded operator<< to output the language
 * 
 * @param os 
 * @param language 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Language& language) {
  os << "{&, ";
  bool first = true;
  for (const String& string : language.GetLanguage()) {
    if (!first) {
      os << ", ";
    }
    os << string;
    first = false;
  }
  os << "}";

  return os;
}