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


#include <iostream>
#include <fstream>

#include "../include/point_set.h"

using namespace CyA;

void printMenu() {
  std::cout << "Opciones:\n"
            << "  0. Salir\n"
            << "  1. Agregar punto (Formato: x y)\n"
            << "  2. Insertar mediante fichero\n"
            << "  3. Imprimir puntos\n"
            << "  4. Imprimir árbol de expansión mínima\n"
            << "  5. Imprimir el coste del árbol de expansión mínima\n"
            << "  6. Guardar el grafo en formato DOT\n"
            << "  7. Generar PDF del grafo\n"
            << "  8. Algoritmo original (EMST)\n"
            << "Seleccione una opción: ";
}

int main(int argc, char* argv[]) {
  point_set ps;
  CyA::point_vector points;
  bool isFile = false;
  bool isPoints = false;

  int option;
  do {
    printMenu();
    std::cin >> option;
    switch (option) {
      case 0:
        // Salir
        std::cout << "Saliendo del programa." << std::endl;
        exit(EXIT_SUCCESS);
        break;
      case 1: {
        // Agregar arista
        std::cout << "Introduce cuantos puntos quieres: ";
        std::cin >> points;
        ps = point_set(points);
        std::cout << std::endl;
        std::cout << "\nPuntos insertados correctamente." << std::endl << std::endl;
        isPoints = true;
        break;
      }
      case 2: {
        // Insertar mediante fichero
        std::string filename;
        std::cout << "Introduzca el nombre del fichero: ";
        std::cin >> filename;

        std::ifstream file(filename);
        if (!file.is_open()) {
          std::cerr << "Error: No se pudo abrir el fichero."<< std::endl << std::endl;
          break;
        }
        file >> points;
        ps = point_set(points);
        file.close();
        std::cout << "\nPuntos insertados correctamente." << std::endl << std::endl;
        isFile = true;
        break;
      }
      case 3: // Imprimir puntos
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl << std::endl;
        } else {
          ps.write(std::cout);
        }
        break;
      case 4: // Imprimir árbol de expansión mínima
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl << std::endl;
        } else {
          ps.write_tree(std::cout);
        }
        break;
      case 5: // Imprimir el coste del árbol de expansión mínima
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl << std::endl;
        } else {
          std::cout << "\nCoste del árbol de expansión mínima: " << ps.get_cost() << std::endl << std::endl;
        }
      case 6: { // Guardar el grafo en formato DOT
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl << std::endl;
        } else {
          std::ofstream dotFile("graph.dot");
          ps.write_dot(dotFile);
          dotFile.close();
          std::cout << "\nGrafo guardado en formato DOT en 'graph.dot'" << std::endl << std::endl;
        }
        break;
      }
      case 7: { // Generar PDF del grafo
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl << std::endl;
        } else {
          int result = system("neato graph.dot -Tpdf -o salida.pdf");
          if (result == 0) {
            std::cout << "\nPDF generado con éxito (ver 'salida.pdf')" << std::endl << std::endl;
          } else {
            std::cerr << "\nError al generar el PDF"<< std::endl;
          }
        }
        break;
      }
      case 8: // Algoritmo original (EMST)
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl << std::endl;
        } else {
          ps.EMST();
          std::cout << "\nÁrbol de expansión mínima generado con éxito." << std::endl << std::endl;
        }
        break;
      default:
        std::cerr << "Error: Opción no válida. Inténtelo de nuevo." << std::endl ;
    }

  } while (option != 0);

  return 0;
}