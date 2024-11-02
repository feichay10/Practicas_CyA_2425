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
    // Symbol symbol(non_terminal);
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
    file >> left_side >> right_side;
    Symbol left_symbol(left_side);
    std::vector<std::string> right_symbols;
    for (char c : right_side) {
      right_symbols.push_back(std::string(1, c));
    }
    non_terminals_.AddProduction(left_symbol, right_symbols);
  }

  file.close();
}

bool Grammar::isTerminal(const Symbol& symbol) const {
  return terminals_.find(symbol);
}


// bool Grammar::isNonTerminal(const Symbol& symbol) const {
//   for (const auto& non_terminal : non_terminals_) {
//     if (non_terminal == symbol) {
//       return true;
//     }
//   }
//   return false;
// }

// El algoritmo de conversión a forma normal de Chomsky es el siguiente:
// for all (A →X1X2 ...Xn (con n ≥2, Xi ∈(Σ ∪V )) do
//   for all (Xi) do
//     if (Xi = a ∈Σ) then
//       Add the production Ca →a;
//       Replace Xi with Ca in A →X1X2 ...Xn;
//     end if
//   end for
// end for
// for all (A →B1B2 ...Bm (con m ≥3, Bi ∈V ) do
//   Add m −2 non-terminal symbols D1D2 ...Dm−2;
//   Replace the production A →B1B2 ...Bm with productions:
//     A →B1D1
//     D1 →B2D2
//     ...
//     Dm−2 →Bm−1Bm
// end for
Grammar Grammar::Convert2CNF() const {
  // Usar hasUnitaryProductions() y hasEmptyProductions() para comprobar si la gramática esta optimizada para la conversión a CNF
  // if (hasUnitaryProductions() || hasEmptyProductions()) {
  //   std::cout << "La gramática no está optimizada para la conversión a CNF. No se puede continuar." << std::endl;
  //   exit(EXIT_FAILURE);
  // }

  Grammar cnf_grammar = *this;
  std::map<Symbol, std::string> auxiliar_symbols_f1; // Mapa de símbolos auxiliares para la primera fase de la conversión

  // Primera parte del algoritmo:
  // la primera fase agrega símbolos auxiliares para las producciones con símbolos terminales
  // for all (A →X1X2 ...Xn (con n ≥2, Xi ∈(Σ ∪V )) do
  //   for all (Xi) do
  //     if (Xi = a ∈Σ) then
  //       Add the production Ca →a;
  //       Replace Xi with Ca in A →X1X2 ...Xn;
  //     end if
  //   end for
  // end for

  // Recorrer todas las producciones de la gramática original
  // Para cada produccion de p:
  for (auto& p : cnf_grammar.non_terminals_.GetProductions()) {
    // Si p tiene dos o más símbolos
    if (p.second.size() >= 2) {
      // Para cada símbolo de la producción
      for (auto& s: p.second) {
        // Si el símbolo es terminal
        if (cnf_grammar.isTerminal(s)) {
          if (auxiliar_symbols_f1.find(s) == auxiliar_symbols_f1.end()) {
            std::vector<std::string> new_production;
            new_production.push_back(s);
            std::string auxiliar_symbol = "C_" + s;
            // cnf_grammar.productions_.insert(std::pair<Symbol, std::vector<std::string>>(auxiliar_symbol, new_production));
            cnf_grammar.non_terminals_.AddProduction(Symbol(auxiliar_symbol), new_production);
            cnf_grammar.non_terminals_.push_back(auxiliar_symbol);
            auxiliar_symbols_f1[s] = auxiliar_symbol;
          }
          // Reemplazar el símbolo terminal por el símbolo auxiliar
          s = auxiliar_symbols_f1[s];
        }
      }
    }
  }

  return cnf_grammar;
}

bool Grammar::hasUnitaryProductions() const {
  // for (auto& p : productions_) {
    // if (p.second.size() == 1 && isNonTerminal(p.second[0])) {
      // return true;
    // }
  // }
  // return false;
}

bool Grammar::hasEmptyProductions() const {
  // for (auto& p : productions_) {
    // if (p.second.size() == 0) {
      // return true;
    // }
  // }
  // return false;
}

std::ostream& operator<<(std::ostream& os, const Grammar& grammar) {
  os << "Terminales: ";
  for (auto& t : grammar.terminals_.GetAlphabet()) {
    os << t << " ";
  }
  os << std::endl;
  os << "No terminales: ";
  os << grammar.non_terminals_ << std::endl;
  // for (auto& nt : grammar.non_terminals_.GetNonTerminals()) {
  //   os << nt << " ";
  // }
  // os << std::endl;
  // os << "Símbolo inicial: " << grammar.start_symbol_ << std::endl;
  // os << "Producciones: " << std::endl;
  // for (auto& p : grammar.non_terminals_.GetProductions()) {
  //   os << " " << p.first << " -> ";
  //   for (auto& s : p.second) {
  //     os << s;
  //   }
  //   os << std::endl;
  // }
  return os;
}