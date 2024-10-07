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

void Comments::SearchComments(std::string line, int line_number) {
  std::regex single_comment("^//(.*)");
  std::regex start_description(R"(\s*\/\*.*\s*)");
  std::regex end_description(R"(\s*.*\*\/\s*)");
  std::smatch match;

  static bool in_description = false;
  static Comments description_comment;

  if (std::regex_search(line, match, single_comment)) {
    Comments comment;
    comment.type_ = "Single";
    comment.content_ = match.str(1);
    comment.line_start_ = line_number;
    comments_.push_back(comment);
  } else if (std::regex_search(line, match, start_description)) {
    in_description = true;
    if (line_number == 1) {
      description_comment.type_ = "Description";
    } else {
      description_comment.type_ = "Multiple";
    }
    description_comment.line_start_ = line_number;
    description_comment.content_lines_.push_back(match.str(1));
  } else if (in_description) {
    if (std::regex_search(line, match, end_description)) {
      in_description = false;
      description_comment.content_lines_.push_back(match.str(1));
      comments_.push_back(description_comment);
      description_comment.content_lines_.clear();
    } else {
      description_comment.content_lines_.push_back(line);
    }
  }

  if (in_description) {
    description_comment.line_end_ = line_number + 1;
  }
}

std::string Comments::PrintDescription() {
  std::string description;
  for (auto comment : comments_) {
    if (comment.type_ == "Description") {
      description += "/**";
      for (auto line : comment.content_lines_) {
        description += line + "\n";
      }
      description += "*/\n";
    }
  }

  return description;
}