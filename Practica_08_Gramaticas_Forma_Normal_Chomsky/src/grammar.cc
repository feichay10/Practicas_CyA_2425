/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 8: Gramáticas en Forma Normal de Chomsky
 * @file grammar.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/grammar.h"

// Los ficheros de especificación de gramáticas son ficheros de texto plano con extensión  .gra que contienen los elementos definitorios de la gramática G ≡ (Σ, V, S, P) en este orden: símbolos terminales, símbolos no terminales, símbolo de arranque y producciones. El formato de cada uno de estos elementos en el fichero es el siguiente: 
// Símbolos terminales (alfabeto): una línea que contiene N, el número de símbolos  en el alfabeto seguida de N líneas, cada una de las cuales contiene un símbolo del alfabeto. Cada símbolo del alfabeto debe ser un único caracter imprimible.
// Símbolos no terminales: una línea que contiene V, el número de símbolos no  terminales, seguida de V líneas, cada una de las cuales contiene una cadena alfanumérica sin espacios. Se asumirá que el primero de los símbolos no terminales de esta lista será el símbolo de arranque.
// Producciones: una línea que contiene P, el número de producciones de la gramática, seguida por P líneas cada una de las cuales contiene una producción en el formato:
// A α
// siendo α ∈ (Σ ∪ V )^∗, es decir una secuencia de símbolos terminales y no terminales.  La cadena vacía, ϵ se representa mediante el carácter &. 
// Teniendo en cuenta la gramática utilizada para el ejemplo de conversión a forma normal  de Chomsky, la especificación en un formato .gra sería la siguiente: 
// 3
// a
// b
// c
// 3
// S
// X
// Y
// 13
// S aXbX
// S abX
// S aXb
// S ab
// X aY
// X bY
// X a
// X b
// Y aY
// Y bY
// Y a
// Y b
// Y c
Grammar::Grammar(const std::string& file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file " + file_name);
  }

  std::string line;
  int number_of_terminals;
  file >> number_of_terminals;
  for (int i = 0; i < number_of_terminals; i++) {
    char terminal;
    file >> terminal;
    terminals_.insert(Symbol(terminal));
  }

  int number_of_non_terminals;
  file >> number_of_non_terminals;
  for (int i = 0; i < number_of_non_terminals; i++) {
    std::string non_terminal;
    file >> non_terminal;
    Symbol symbol(non_terminal);
    non_terminals_.insert(symbol);
    if (i == 0) {
      start_symbol_ = symbol;
    }
  }

  int number_of_productions;
  file >> number_of_productions;
  std::getline(file, line);  // Consumir el salto de línea
  for (int i = 0; i < number_of_productions; i++) {
    std::getline(file, line);
    std::stringstream ss(line);
    std::string left_symbol;
    ss >> left_symbol;
    Symbol left(left_symbol);
    std::vector<std::string> right;
    std::string right_symbol;
    while (ss >> right_symbol) {
      right.push_back(right_symbol);
    }
    productions_.insert(std::pair<Symbol, std::vector<std::string>>(left, right));
  }
  file.close();
}

bool Grammar::isTerminal(const Symbol& symbol) const {
  return terminals_.find(symbol);
}

bool Grammar::isNonTerminal(const Symbol& symbol) const {
  return non_terminals_.find(symbol);
}

// /**
//  * @brief Convierte la gramática a Forma Normal de Chomsky, si es posible
//  *
//  * @return Grammar
//  */
// Grammar Grammar::Convert2CNF() const {
//   // Usar hasUnitaryProductions() y hasEmptyProductions() para comprobar si la
//   // gramática esta optimizada para la conversión a CNF
//   if (hasUnitaryProductions() || hasEmptyProductions()) {
//     std::cout << "La gramática no está optimizada para la conversión a CNF. No se puede continuar." << std::endl;
//     exit(EXIT_FAILURE);
//   }

//   Grammar result = *this;  // Creamos una copia de la gramática

//   std::map<Symbol, Symbol> auxiliar_symbols_f1;  // Mapa de símbolos auxiliares para la primera fase
//                             // de la conversión

//   // la primera fase agrega símbolos auxiliares para las producciones con
//   // símbolos terminales

//   // Para cada produccion de p:
//   for (auto& p : result.productions_) {
//     // Si p tiene dos o más símbolos
//     if (p.second.size() >= 2) {
//       // Para cada simbolo a de p:
//       for (auto& a : p.second) {
//         // Si a es terminal
//         if (result.isTerminal(a)) {
//           if (auxiliar_symbols_f1.find(a) == auxiliar_symbols_f1.end()) {
//             // Creo nueva produccion Ca -> a
//             std::vector<Symbol> new_production;
//             new_production.push_back(a);
//             Symbol new_symbol = Symbol("C_" + a.GetSymbol());
//             result.productions_.insert(std::pair<Symbol, std::vector<Symbol>>(new_symbol, new_production));
//             result.non_terminals_.insert(new_symbol);
//             auxiliar_symbols_f1[a] = new_symbol;
//           }
//           // Cambio a por Ca en p
//           a = auxiliar_symbols_f1[a];
//         }
//       }
//     }
//   }

//   std::map<std::vector<Symbol>, Symbol>auxiliar_productions_f2;  // Mapa de producciones auxiliares para la segunda fase de la conversión
//   int identifier = 0;

//   // La segunda fase descompone las producciones con más de dos símbolos en
//   // producciones más pequeñas con solo dos símbolos.

//   for (auto& p : result.productions_) {  // Para cada produccion de p:
//     while (p.second.size() > 2) {  // Mientras p tenga más de dos símbolos
//       std::vector<Symbol> new_production;  // Creo nueva produccion
//       new_production.push_back(p.second[p.second.size() - 2]);  // Añado los dos últimos símbolos de
//                                            // p a la nueva producción
//       new_production.push_back(p.second[p.second.size() - 1]);
//       if (auxiliar_productions_f2.find(new_production) == auxiliar_productions_f2.end()) {  // Si la nueva producción no existe
//         Symbol new_symbol = Symbol("D_" + std::to_string(identifier));  // Creo nuevo símbolo
//         identifier++;
//         result.productions_.insert(std::pair<Symbol, std::vector<Symbol>>(new_symbol, new_production));  // Inserto la nueva producción en el mapa
//         result.non_terminals_.insert(new_symbol);  // Añado el nuevo símbolo a los símbolos no terminales
//         auxiliar_productions_f2[new_production] = new_symbol;  // Añado la nueva producción al mapa de producciones auxiliares
//       }
//       p.second.pop_back();
//       p.second.pop_back();
//       p.second.push_back(auxiliar_productions_f2[new_production]);
//     }
//   }

//   return result;
// }

// bool Grammar::hasUnitaryProductions() const {
//   for (auto& p : productions_) {
//     if (p.second.size() == 1 && isNonTerminal(p.second[0])) {
//       return true;
//     }
//   }
//   return false;
// }

// bool Grammar::hasEmptyProductions() const {
//   for (auto& p : productions_) {
//     if (p.second.size() == 0) {
//       return true;
//     }
//   }
//   return false;
// }

std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  os << "Terminales: ";
  for (auto& t : grammar.terminals_.GetAlphabet()) {
    os << t << " ";
  }
  os << std::endl;

  os << "No terminales: ";
  for (auto& nt : grammar.non_terminals_.GetAlphabet()) {
    os << nt << " ";
  }
  os << std::endl;

  os << "Símbolo inicial: " << grammar.start_symbol_ << std::endl;

  os << "Producciones: " << std::endl;
  // Las producciones que se impriman de la forma A -> α1 | α2 | ... | αn
  for (auto& p : grammar.productions_) {
    os << p.first << " -> ";
    for (int i = 0; i < p.second.size(); i++) {
      os << p.second[i];
      if (i != p.second.size() - 1) {
        os << " | ";
      }
    }
    os << std::endl;
  }

  return os;
}