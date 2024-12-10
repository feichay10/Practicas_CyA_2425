/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 11: Algoritmos Voraces (Greedy). Euclidean Minimum Spanning Tree
 * @file main.cc
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief
 *
 * @version 0.1
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/functions.h"

bool check_arguments(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << kHowUse << std::endl;
    return false;
  }
  return true;
}

void printMenu() {
  std::cout << "Opciones:\n"
            << "1. Agregar punto (Formato: x y)\n"
            << "2. Insertar mediante fichero\n"
            << "3. Calcular el árbol de expansión mínima\n"
            << "4. Imprimir el coste del árbol de expansión mínima\n"
            << "5. Guardar el grafo en formato DOT (-d)\n"
            << "6. Generar PDF del grafo (-pdf)\n"
            << "7. Salir\n"
            << "8. Imprimir puntos\n"
            << "9. Imprimir árbol de expansión mínima\n"
            << "Seleccione una opción: ";
}