/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @brief Ejercicios de programacion
 * Version 1: Funcion factorial
 *
 * @see https :// github.com/IB -2023 -2024/IB-class -code -examples/
 */

#include <cassert>
#include <iostream>

// Returns the factorial of the argument
int Factorial(int number) {
  switch (number) {
    case 0:
    case 1:
      return 1;
    default:
      int factorial = 1;
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
      }
      return factorial; // Returns the factorial 
  }
}

/*
Prueba comentario multilinea
Hola
pepe
*/
int main() {
  std::cout << "Introduzca el numero de factoriales a calcular: ";
  int limit;
  std::cin >> limit;
  for (int i = 1; i <= limit; ++i) {
    std::cout << i << "! = " << (double)Factorial(i) << std::endl;
  }
  return 0;
}