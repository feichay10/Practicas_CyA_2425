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
#include <unordered_map>

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
/**
 * @brief Constructs a Grammar object by reading grammar rules from a file.
 * 
 * This constructor reads a grammar definition from a specified file and initializes
 * the grammar's terminals, non-terminals, start symbol, and production rules.
 * 
 * @param file_name The name of the file containing the grammar definition.
 * 
 * @throws std::runtime_error If the file cannot be opened.
 * 
 * The file should have the following format:
 * - The first line contains the number of terminals.
 * - The next lines contain the terminal symbols.
 * - The next line contains the number of non-terminals.
 * - The next lines contain the non-terminal symbols.
 * - The next line contains the number of production rules.
 * - The next lines contain the production rules in the format "left_side right_side".
 */
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
    std::string symbol = non_terminal;
    non_terminals_.push_back(symbol);
    if (i == 0) {
      start_symbol_ = symbol;
    }
  }

  // Leer producciones
  int number_of_productions;
  file >> number_of_productions;
  for (int i = 0; i < number_of_productions; i++) {
    std::string left_side;
    std::string right_side;
    std::vector<std::string> right_symbols;
    file >> left_side >> right_side;
    right_symbols.push_back(right_side);
    if (non_terminals_.HasProduction(left_side)) {
      // std::cout << "\nAdding production to existing: " << left_side << " -> ";
      non_terminals_.AddToExistingProduction(left_side, right_symbols);
    } else {
      // std::cout << "\nAdding production: " << left_side << " -> ";
      non_terminals_.AddProduction(left_side, right_symbols);
    }
  }

  file.close();
}

bool Grammar::isTerminal(const std::string& value) const {
  return terminals_.find(value);
}


// bool Grammar::isNonTerminal(const std::string& value) const {
//   for (const auto& non_terminal : non_terminals_) {
//     if (non_terminal == symbol) {
//       return true;
//     }
//   }
//   return false;
// }


Grammar Grammar::Convert2CNF() const {
  // Usar hasUnitaryProductions() y hasEmptyProductions() para comprobar si la gramática esta optimizada para la conversión a CNF
  // if (hasUnitaryProductions() || hasEmptyProductions()) {
  //   std::cout << "La gramática no está optimizada para la conversión a CNF. No se puede continuar." << std::endl;
  //   exit(EXIT_FAILURE);
  // }

  Grammar cnf_grammar = *this;
  std::map<std::string, std::string> auxiliar_symbols_f1; // Mapa de símbolos auxiliares para la primera fase de la conversión
  std::multimap<std::string, std::vector<std::string>> aux_productions_1 = cnf_grammar.non_terminals_.GetProductions();

  // Primera parte del algoritmo:
  // la primera fase agrega símbolos auxiliares para las producciones con símbolos terminales
  // for all (A →X_1 X_2 ...X_n (con n ≥ 2, X_i ∈(Σ ∪ V)) do
  //   for all (X_i) do
  //     if (X_i = a ∈ Σ) then
  //       Add the production C_a →a;
  //       Replace Xi with C_a in A →X_1X_2 ...X_n;
  //     end if
  //   end for
  // end for
  for (auto& p : aux_productions_1) {
    // Si p tiene dos o más símbolos
    if (p.second.size() >= 2) {
      for (auto& s: p.second) {
        if (s.size() != 1){
          std::string new_right_side;
          for (char c : s) {
            std::string symbol(1, c);
            // Si el símbolo es terminal
            if (cnf_grammar.isTerminal(symbol)) {
              if (auxiliar_symbols_f1.find(symbol) == auxiliar_symbols_f1.end()) { // Si el símbolo no existe en el mapa
                std::vector<std::string> new_production;
                new_production.push_back(symbol);
                std::string auxiliar_symbol = "C_" + symbol;
                cnf_grammar.non_terminals_.push_back(auxiliar_symbol);
                aux_productions_1.insert(std::pair<std::string, std::vector<std::string>>(auxiliar_symbol, new_production));
                auxiliar_symbols_f1[symbol] = auxiliar_symbol;
              }
              // Reemplazar el símbolo terminal por el símbolo auxiliar
              new_right_side += auxiliar_symbols_f1[symbol];
            } else {
              new_right_side += symbol;
            }
          }
          s = new_right_side;
        }
      }
    }
  }

  cnf_grammar.non_terminals_.SetProductions(aux_productions_1);

  return cnf_grammar;
}

bool Grammar::hasUnitaryProductions() const {
  // for (auto& p : productions_) {
    // if (p.second.size() == 1 && isNonTerminal(p.second[0])) {
      // return true;
    // }
  // }
  // return false;
  return false;
}

bool Grammar::hasEmptyProductions() const {
  // for (auto& p : productions_) {
    // if (p.second.size() == 0) {
      // return true;
    // }
  // }
  // return false;
  return false;
}

std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  os << "Terminales: ";
  for (auto& t : grammar.terminals_.GetAlphabet()) {
    os << t << " ";
  }
  os << std::endl;
  os << "No terminales: ";
  for (const auto& nt : grammar.non_terminals_.GetNonTerminals()) {
    os << nt << " ";
  }
  os << std::endl;
  os << "Producciones: " << std::endl;
  for (const auto& non_terminal : grammar.non_terminals_.GetNonTerminals()) {
    os << " " << non_terminal << " -> ";
    for (const auto& p : grammar.non_terminals_.GetProductions()) {
      if (p.first == non_terminal) {
        for (const auto& s : p.second) {
          os << s;
          if (&s != &p.second.back()) {
            os << " | ";
          }
        }
      }
    }
    os << std::endl;
  }
  return os;
}