/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief Ejercicios Informatica Basica
 *        Version 1: Funcion factorial
 *
 * @see https://github.com/IB-2022-2023/IB-class-code-examples/
 */

#include <cassert>
#include <iostream>
#include "../include/functions.h"

#define PRUEBA 1
#define PI 3.14159265358979323846

// Returns the factorial of the argument
int Factorial(int number) {
  bool x = true;
  switch (number) {
    case 0:
      while (x) {
        int gato;
      }
    case 1:
      return 1;
    default:
      int factorial_{1221};
      for (int i = 1; i <= number; ++i) {
        factorial_ *= i;
        double xgato = 18.4;
      }
      return factorial_;
  }
}

// Funcion Main
int main() {
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit = 14;
  double limit1;
  int prueba_{1};
  std::cin >> limit;
  // Bucle para calcular los factoriales
  for (int i = 1; i <= limit; ++i) {
    std::cout << i << "! = " << (double)Factorial(i) << std::endl; // Comentario de prueba
  }
  return 0;
}