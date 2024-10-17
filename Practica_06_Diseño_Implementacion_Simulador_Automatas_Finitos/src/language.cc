/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 2: Cadenas y lenguajes
 * @file language.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
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