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

Language::Language() {}

Language::Language(std::set<Chain> language) {
  language_ = language;
}

std::set<Chain> Language::GetLanguage() const {
  return language_;
}

void Language::SetLanguage(std::set<Chain> language) {
  language_ = language;
}