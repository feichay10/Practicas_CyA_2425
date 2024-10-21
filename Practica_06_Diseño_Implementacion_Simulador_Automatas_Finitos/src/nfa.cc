/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: Diseño e implementación de un simulador de autómatas finitos
 * @file nfa.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/nfa.h"
#include <set>
#include <queue>

NFA::NFA(std::vector<std::string> automaton_data) {
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
    for (int j = 0; j < transitions_number; j++) {
      std::string symbol;
      std::string to_state;
      ss >> symbol >> to_state;
      // if (!alphabet_.find(Symbol(symbol))) {
      //   throw std::runtime_error("Hay una transición con un símbolo que no está en el alfabeto");
      // }
      Transition transition(state, Symbol(symbol[0]), State(to_state, false, false));
      transitions_.insert(transition);
    }
    states_.insert(state);
  }
}

// bool NFA::ReadStrings(const String& string) {
//   // Conjunto de estados actuales, comenzamos con el estado inicial
//   std::set<State> current_states;
//   bool initial_state_found = false;
  
//   // Encuentra el estado inicial y añádelo a los estados actuales
//   for (const auto& state : states_) {
//     if (state.GetStateId() == initial_state_) {
//       current_states.insert(state);
//       initial_state_found = true;
//       break;
//     }
//   }

//   if (!initial_state_found) {
//     std::cout << "ERROR: Estado inicial no encontrado" << std::endl;
//     return false;
//   }

//   // Manejar la cadena vacía
//   if (string.GetString().size() == 1 && string.GetString()[0].GetSymbol() == '&') {
//     for (const auto& state : current_states) {
//       if (state.IsAceptationState()) {
//         return true;
//       }
//     }
//     return false;
//   }

//   // Procesar la cadena de entrada
//   for (int i = 0; i < string.GetString().size() - 1; i++) {
//     Symbol symbol = Symbol(string.GetString()[i]);
//     std::cout << "Current symbol: " << symbol << std::endl;

//     if (!AlphabetComprobation(symbol)) {
//       std::cout << "ERROR: El símbolo " << symbol.GetSymbol() << " no pertenece al alfabeto" << std::endl;
//       return false;
//     }

//     std::set<State> next_states;
    
//     // Para cada estado actual, buscar transiciones posibles
//     for (const auto& current_state : current_states) {
//       for (const auto& transition : transitions_) {
//         // Si la transición parte del estado actual y el símbolo coincide
//         if (transition.GetFrom().GetStateId() == current_state.GetStateId() && 
//             transition.GetSymbol().GetSymbol() == symbol.GetSymbol()) {
//           // Encontrar el estado de destino
//           for (const auto& state : states_) {
//             if (state.GetStateId() == transition.GetTo().GetStateId()) {
//               next_states.insert(state);
//             }
//           }
//         }
//       }
//     }

//     if (next_states.empty()) {
//       std::cout << "ERROR: No se ha encontrado una transición para el símbolo " << symbol.GetSymbol() << std::endl;
//       return false;
//     }

//     current_states = next_states;  // Actualiza los estados actuales con los nuevos posibles
//   }

//   // Verifica si alguno de los estados actuales es de aceptación
//   for (const auto& state : current_states) {
//     if (state.IsAceptationState()) {
//       return true;
//     }
//   }

//   return false;
// }

#include <set>
#include <queue>

bool NFA::ReadStrings(const String& string) {
  // Conjunto de estados actuales, comenzamos con el estado inicial
  std::set<State> current_states;
  bool initial_state_found = false;
  
  // Encuentra el estado inicial y añádelo a los estados actuales
  for (const auto& state : states_) {
    if (state.GetStateId() == initial_state_) {
      current_states.insert(state);
      initial_state_found = true;
      break;
    }
  }

  if (!initial_state_found) {
    std::cout << "ERROR: Estado inicial no encontrado" << std::endl;
    return false;
  }

  // Expandir las epsilon-transiciones desde los estados iniciales
  current_states = EpsilonClosure(current_states);

  // Manejar la cadena vacía (solo epsilon)
  if (string.GetString().size() == 1 && string.GetString()[0].GetSymbol() == '&') {
    for (const auto& state : current_states) {
      if (state.IsAceptationState()) {
        return true;
      }
    }
    return false;
  }

  // Procesar la cadena de entrada
  for (int i = 0; i < string.GetString().size() - 1; i++) {
    Symbol symbol = Symbol(string.GetString()[i]);
    std::cout << "Current symbol: " << symbol << std::endl;

    if (!AlphabetComprobation(symbol)) {
      std::cout << "ERROR: El símbolo " << symbol.GetSymbol() << " no pertenece al alfabeto" << std::endl;
      return false;
    }

    std::set<State> next_states;

    // Para cada estado actual, buscar transiciones posibles
    for (const auto& current_state : current_states) {
      for (const auto& transition : transitions_) {
        // Si la transición parte del estado actual y el símbolo coincide
        if (transition.GetFrom().GetStateId() == current_state.GetStateId() && 
            transition.GetSymbol().GetSymbol() == symbol.GetSymbol()) {
          // Encontrar el estado de destino
          for (const auto& state : states_) {
            if (state.GetStateId() == transition.GetTo().GetStateId()) {
              next_states.insert(state);
            }
          }
        }
      }
    }

    if (next_states.empty()) {
      std::cout << "ERROR: No se ha encontrado una transición para el símbolo " << symbol.GetSymbol() << std::endl;
      return false;
    }

    // Expandir las epsilon-transiciones desde los nuevos estados
    next_states = EpsilonClosure(next_states);

    current_states = next_states;  // Actualiza los estados actuales con los nuevos posibles
  }

  // Verifica si alguno de los estados actuales es de aceptación
  for (const auto& state : current_states) {
    if (state.IsAceptationState()) {
      return true;
    }
  }

  return false;
}

// Función para calcular el cierre epsilon (Epsilon Closure)
std::set<State> NFA::EpsilonClosure(const std::set<State>& states) {
  std::set<State> closure = states;  // El cierre contiene inicialmente los estados originales
  std::queue<State> to_process;      // Estados que procesaremos

  // Añadimos los estados iniciales a la cola
  for (const auto& state : states) {
    to_process.push(state);
  }

  // Mientras haya estados por procesar
  while (!to_process.empty()) {
    State current_state = to_process.front();
    to_process.pop();

    // Buscar transiciones epsilon (símbolo '&') desde el estado actual
    for (const auto& transition : transitions_) {
      if (transition.GetFrom().GetStateId() == current_state.GetStateId() && 
          transition.GetSymbol().GetSymbol() == '&') {
        // Encontrar el estado de destino
        for (const auto& state : states_) {
          if (state.GetStateId() == transition.GetTo().GetStateId() && closure.find(state) == closure.end()) {
            closure.insert(state);  // Añadimos al cierre
            to_process.push(state); // Lo procesaremos después para expandir su cierre
          }
        }
      }
    }
  }

  return closure;
}

