/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.cc
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

#include "../include/comments.h"

std::vector<Comments> Comments::comments_;

void Comments::SearchSingle(std::string line, int line_number) {
  std::regex single_comment("//(.*)");
  std::smatch match;

  if (std::regex_search(line, match, single_comment)) {
    Comments comment;
    comment.type_ = "Single";
    comment.content_ = match.str(1);
    comment.line_start_ = line_number;
    comments_.push_back(comment);
  }
}

void Comments::SearchMultiple(std::string line, int line_number) {
  std::regex multiple_comment_start("/\\*");
  std::regex multiple_comment_end("\\*/");
  std::smatch match;

  if (std::regex_search(line, match, multiple_comment_start)) {
    Comments comment;
    comment.type_ = "Multiple";
    comment.content_ = match.str(1);
    comment.line_start_ = line_number;
    comments_.push_back(comment);
  }

  if (std::regex_search(line, match, multiple_comment_end)) {
    comments_.back().line_end_ = line_number;
  }
}

void Comments::PrintSingle() {
  for (auto comment : comments_) {
    if (comment.type_ == "Single") {
      std::cout << "Single comment: " << comment.content_ << " at line " << comment.line_start_ << std::endl;
    }
  }
}

void Comments::PrintMultiple() {
  for (auto comment : comments_) {
    if (comment.type_ == "Multiple") {
      std::cout << "Multiple comment: " << comment.content_ << " from line " << comment.line_start_ << " to line " << comment.line_end_ << std::endl;
    }
  }
}