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
  std::stringstream ss(automaton_data[0]); // Leer el alfabeto
  Symbol symbol;
  while (ss >> symbol) {
    alphabet_.insert(Symbol(symbol)); 
  }

  num_states_ = std::stoi(automaton_data[1]); // Número de estados
  initial_state_ = automaton_data[2];         // Estado de arranque
  initial_state_.resize(initial_state_.size() - 1); // Eliminar el salto de linea

  // Leer los estados
  for (int i = 3; i < automaton_data.size(); i++) {
    std::stringstream ss(automaton_data[i]);
    std::string state_id;
    bool aceptation_state;
    bool start_state = false;
    int transitions_number;
    ss >> state_id >> aceptation_state >> transitions_number;
    if (state_id == initial_state_) {
      start_state = true;
    }
    State state(state_id, start_state, aceptation_state, transitions_);
    
    // Leer las transiciones
    // TODO: Comprobar que si en una transicion hay un simbolo que no esta en el alfabeto, lanzar excepcion
    for (int j = 0; j < transitions_number; j++) {
      std::string symbol;
      std::string to_state;
      ss >> symbol >> to_state;
      Transition transition(state, Symbol(symbol[0]), State(to_state, false, false));
      transitions_.insert(transition);
    }
    states_.insert(state);
  }
}