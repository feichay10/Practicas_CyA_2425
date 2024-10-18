/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file dfa.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/dfa.h"

// Constructor, contruye un DFA a partir de los datos del fichero
// Linea 1: Simbolos del alfabeto separados por espacios
// Linea 2: Numero total de estados del automata
// Linea 3: Estado de arranque
// A continuación figurará una línea para cada uno de los estados. Cada linea 
// contendra los siguientes numeros, separados entre si por espacios en blanco:
//    - Numero identificador del estado. Los estados del automata se representaran
//      mediante numeros naturales. La numeracion de los estados corresponderan
//      a los primeros numeros naturales empezando por 0.
//    - Un 1 si se trata de un estado de aceptacion y un 0 en caso contrario.
//    - Numero de transiciones que posee el estado.
//    - A continuación, para cada una de las transiciones, y utilizando espacios
//      en blanco como separador, se detallará la información siguiente:
//        - Simbolo de entrada necesario que se produzca la transición. Para 
//          representar la cadena vacia (el no consumir simbolo de la entrada) se
//          utilizará el simbolo &.
//        - Estado destino de la transición.
// Ejemplo de fichero que se especifica un DFA:
// 0  1  -> Alfabeto
// 4     -> Numero total de estados
// 0     -> Estado de arranque (inicial)
// 0 0 2 0 2 1 1
// 1 1 2 0 1 1 1
// 2 0 2 0 1 1 3
// 3 0 2 0 2 1 3
DFA::DFA(std::vector<std::string> automaton_data) {
  // Leer el alfabeto
  std::stringstream ss(automaton_data[0]);
  Symbol symbol;
  while (ss >> symbol) {
    alphabet_.insert(Symbol(symbol));
  }
  std::cout << "Alfabeto: " << alphabet_ << std::endl;
  
  // Leer el número de estados
  num_states_ = std::stoi(automaton_data[1]);
  std::cout << "Número de estados: " << num_states_ << std::endl;

  // Leer el estado inicial
  initial_state_ = std::stoi(automaton_data[2]);
  std::cout << "Estado inicial: q" << initial_state_ << std::endl;

  // Leer los estados
  for (int i = 3; i < automaton_data.size() - 1; i++) {
    std::stringstream ss(automaton_data[i]);
    int state_id;
    bool aceptation_state;
    int transitions_number;
    ss >> state_id >> aceptation_state >> transitions_number;
    std::string state_id_string = "q" + std::to_string(state_id);
    std::cout << "Estado q" << state_id << ": ";
    if (aceptation_state) {
      std::cout << "aceptación";
    } else {
      std::cout << "no aceptación";
    }
    std::cout << std::endl;


    State state(state_id_string, state_id == initial_state_, aceptation_state, transitions_);
    
    // Leer las transiciones
    for (int j = 0; j < transitions_number; j++) {
      std::string symbol;
      int to_state;
      ss >> symbol >> to_state;
      Transition transition(state, Symbol(symbol[0]), State("q" + std::to_string(to_state), false, false));
      transitions_.insert(transition);
      std::cout << "  Transición: " << state_id_string << " -> " << symbol << " -> q" << to_state << std::endl;
    }
    
    states_.insert(state);
  }

    // State state(state_id_string, state_id == initial_state_, aceptation_state); // TODO: Insertar todas las transiciones - MODIFICAR CONSTRUCTOR
    // states_.insert(state);

  
}