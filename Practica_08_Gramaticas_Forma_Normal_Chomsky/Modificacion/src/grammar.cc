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

  int number_of_productions;
  file >> number_of_productions;
  for (int i = 0; i < number_of_productions; i++) {
    std::string left_side;
    std::string right_side;
    file >> left_side >> right_side;
    std::string left_symbol = left_side;
    std::vector<std::string> right_symbols;
    for (char c : right_side) {
      right_symbols.push_back(std::string(1, c));
    }
    non_terminals_.AddProduction(left_symbol, right_symbols);
  }

  file.close();
}


/**
 * @brief Checks if a given symbol is a terminal.
 *
 * This function determines whether the provided symbol is part of the set of terminal symbols.
 *
 * @param symbol The symbol to be checked.
 * @return True if the symbol is a terminal, false otherwise.
 */
bool Grammar::isTerminal(const Symbol& symbol) const {
  return terminals_.find(symbol);
}


/**
 * @brief Checks if a given symbol is a non-terminal.
 *
 * This function iterates through the list of non-terminal symbols
 * and checks if the provided symbol matches any of the non-terminals.
 *
 * @param symbol The symbol to be checked.
 * @return true if the symbol is a non-terminal, false otherwise.
 */
bool Grammar::isNonTerminal(const Symbol& symbol) const {
  for (const auto& non_terminal : non_terminals_.GetNonTerminals()) {
    if (non_terminal == symbol) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Converts the current grammar to Chomsky Normal Form (CNF).
 * 
 * This function converts the current grammar to its equivalent Chomsky Normal Form (CNF).
 * The conversion process involves two main phases:
 * 
 * 1. Replacing terminal symbols in productions with auxiliary non-terminal symbols.
 * 2. Decomposing productions with more than two symbols into smaller productions with only two symbols.
 * 
 * The function first checks if the grammar has unitary or empty productions using the 
 * hasUnitaryProductions() and hasEmptyProductions() methods. If the grammar is not optimized 
 * for conversion to CNF, the function will print an error message and terminate the program.
 * 
 * @return Grammar The grammar converted to Chomsky Normal Form (CNF).
 */
Grammar Grammar::Convert2CNF() const {
  // Usar hasUnitaryProductions() y hasEmptyProductions() para comprobar si la gramática esta optimizada para la conversión a CNF
  if (hasUnitaryProductions() || hasEmptyProductions()) {
    throw std::runtime_error("The grammar is not optimized for conversion to CNF.");
  }

  std::string no_terminal_symbols_aux = "SABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Símbolos no terminales auxiliares
  Grammar cnf_grammar = *this;
  std::map<std::string, std::string> auxiliar_symbols_f1; // Mapa de símbolos auxiliares para la primera fase de la conversión
  std::multimap<std::string, std::vector<std::string>> aux_productions_1 = cnf_grammar.non_terminals_.GetProductions();

  // Primera parte del algoritmo:
  // La primera fase agrega símbolos auxiliares para las producciones con símbolos terminales
  // Recorrer todas las producciones de la gramática original
  // Para cada produccion de p:
  for (auto& p : aux_productions_1) {
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
            cnf_grammar.non_terminals_.push_back(auxiliar_symbol);
            aux_productions_1.insert(std::pair<std::string, std::vector<std::string>>(auxiliar_symbol, new_production));
            auxiliar_symbols_f1[s] = auxiliar_symbol;
          }
          // Reemplazar el símbolo terminal por el símbolo auxiliar
          s = auxiliar_symbols_f1[s];
        }
      }
    }
  }

  cnf_grammar.non_terminals_.SetProductions(aux_productions_1);

  // Segunda parte del algoritmo:
  // La segunda fase descompone las producciones con más de dos símbolos en producciones más pequeñas con solo dos símbolos.
  std::map<std::vector<std::string>, std::string> auxiliar_productions_f2; // Mapa de producciones auxiliares para la segunda fase de la conversión
  std::multimap<std::string, std::vector<std::string>> aux_productions_2 = cnf_grammar.non_terminals_.GetProductions();
  int identifier = 1;

  for (auto& p: aux_productions_2) { // Para cada produccion de p:
    while (p.second.size() > 2) { // Mientras p tenga más de dos símbolos
      std::vector<std::string> new_production; // Creo nueva produccion
      new_production.push_back(p.second[p.second.size() - 2]); // Añado los dos últimos símbolos de p a la nueva producción
      new_production.push_back(p.second[p.second.size() - 1]); 
      if (auxiliar_productions_f2.find(p.second) == auxiliar_productions_f2.end()) { // Si la nueva producción no existe
        std::string new_symbol = std::string(1, no_terminal_symbols_aux.front()) + "_" + std::to_string(identifier); // Creo nuevo símbolo
        no_terminal_symbols_aux.erase(std::remove(no_terminal_symbols_aux.begin(), no_terminal_symbols_aux.end(), new_symbol[0]), no_terminal_symbols_aux.end()); // Elimino el símbolo de la lista de símbolos no terminales auxiliares
        identifier++;
        aux_productions_2.insert(std::pair<std::string, std::vector<std::string>>(new_symbol, new_production)); // Inserto la nueva producción en el mapa
        cnf_grammar.non_terminals_.push_back(new_symbol);     // Añado el nuevo símbolo a los símbolos no terminales
        auxiliar_productions_f2[new_production] = new_symbol; // Añado la nueva producción al mapa de producciones auxiliares
      }
      p.second.pop_back(); 
      p.second.pop_back();
      p.second.push_back(auxiliar_productions_f2[new_production]);
    }
  }

  cnf_grammar.non_terminals_.SetProductions(aux_productions_2);

  return cnf_grammar;
}

/**
 * @brief Checks if the grammar has any unitary productions.
 * 
 * A unitary production is a production where a non-terminal produces exactly one non-terminal.
 * This function iterates through all the productions of the non-terminals and checks if there
 * exists any production that is unitary.
 * Example of a unitary production: A -> B
 * 
 * @return true if there is at least one unitary production, false otherwise.
 */
bool Grammar::hasUnitaryProductions() const {
  for (auto& p : non_terminals_.GetProductions()) {
    if (p.second.size() == 1 && isNonTerminal(p.second[0])) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Checks if the grammar has any empty productions.
 *
 * This function iterates through all the productions of the non-terminals
 * in the grammar and checks if any of them have an empty right-hand side.
 * Example of an empty production: A -> ε
 *
 * @return true if there is at least one empty production, false otherwise.
 */
bool Grammar::hasEmptyProductions() const {
  for (auto& p : non_terminals_.GetProductions()) {
    for (const auto& symbol : p.second) {
      if (symbol == "&") {
        return true;
      }
    }
  }  // file << grammar;
  return false;
}

/**
 * @brief Overloads the output stream operator to print the details of a Grammar object.
 *
 * This function prints the terminals, non-terminals, and productions of the given Grammar object
 * to the provided output stream.
 *
 * @param os The output stream to which the Grammar details will be printed.
 * @param grammar The Grammar object whose details are to be printed.
 * @return A reference to the output stream.
 */
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
  os << "Producciones:" << std::endl;
  for (const auto& p : grammar.non_terminals_.GetProductions()) {
    os << " " << p.first << " -> ";
    for (const auto& s : p.second) {
      os << s;
    }
    os << std::endl;
  }
  return os;
}

// Modificacion: Guardas todos los simbolos no terminales alcanzables desde el estado de arranque
void Grammar::ReachableNonTerminals() const {
  std::set<std::string> reachable_non_terminals;
  std::vector<std::string> non_terminals = non_terminals_.GetNonTerminals();
  std::multimap<std::string, std::vector<std::string>> productions = non_terminals_.GetProductions();
  std::vector<std::string> non_terminals_to_check;
  non_terminals_to_check.push_back(start_symbol_.ToString());

  while (!non_terminals_to_check.empty()) {
    std::string current_non_terminal = non_terminals_to_check.back();
    non_terminals_to_check.pop_back();
    reachable_non_terminals.insert(current_non_terminal);

    for (auto& p : productions) {
      if (p.first == current_non_terminal) {
        for (auto& s : p.second) {
          if (isNonTerminal(Symbol(s[0])) && reachable_non_terminals.find(s) == reachable_non_terminals.end()) {
            non_terminals_to_check.push_back(s);
          }
        }
      }
    }
  }

  std::cout << "No terminales alcanzables desde el estado de arranque: ";
  for (const auto& nt : reachable_non_terminals) {
    std::cout << nt << " ";
  }
  std::cout << std::endl;
}