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
      int factorial{1};
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
        double xgato = 2;
      }
      return factorial;
  }
}

// Funcion Main
int main() {
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit;
  double limit1;
  std::cin >> limit;
  // Bucle para calcular los factoriales
  for (int i = 1; i <= limit; ++i) {
    // Comentario de prueba
    std::cout << i << "! = " << (double)Factorial(i) << std::endl;
  }
  return 0;
}