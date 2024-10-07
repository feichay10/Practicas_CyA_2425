/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares en C++
 * @file variables.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief 
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

  void SearchComments(std::string line, int line_number);
  std::string PrintDescription();

  friend std::ostream& operator<<(std::ostream& os, const Comments& comments) {
    for (auto comment : comments.comments_) {
      if (comment.type_ == "Single") {
        os << "[Line " << comment.line_start_ << "] //" << comment.content_ << std::endl;
      } else if (comment.type_ == "Description") {
        os << "[Line " << comment.line_start_ << "-" << comment.line_end_ << "] DESCRIPTION "<< std::endl;
      } else if (comment.type_ == "Multiple") {
        os << "[Line " << comment.line_start_ << "-" << comment.line_end_ << "] MULTIPLE" << std::endl;
      }
    }
    return os;
  }

 private:
  std::string type_;
  int line_start_;
  int line_end_;
  std::string content_;
  std::vector<std::string> content_lines_;
  std::vector<Comments> comments_; 
};

#endif  // COMMENTS_H_