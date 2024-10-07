/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief Se detectaran todos los comentarios de una linea (//) y de mútliples
 * lineas (/* *\) presentes en el fichero. Se almacenar ́a el tipo de cada
 * comentario, la/s linea/s en la que se encuentra cada uno asi como el
 * contenido del propio comentario. Adem ́as, se tendr ́a en cuenta que si al
 * comienzo del fichero se encuentra un comentario, ese comentario se tomara por
 * defecto como descripci ́on del programa.
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COMMENTS_H_
#define COMMENTS_H_

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Comments {
 public:
  Comments() = default;
  ~Comments() = default;

  void SearchSingle(std::string line, int line_number);
  void SearchMultiple(std::string line, int line_number);
  void PrintSingle();
  void PrintMultiple();

 private:
  std::string type_;
  std::string content_;
  int line_start_;
  int line_end_;
  static std::vector<Comments> comments_;
};

#endif  // COMMENTS_H_