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

#include "../include/functions.h"
#include "../include/point_set.h"
#include "../include/point_types.h"
#include "../include/sub_tree.h"

// Formato de fichero de lectura:
// 10         -> Número de puntos
//  68	-21   -> Coordenadas de los puntos
//  57	 60
//  82	-60
// -33	 54
// -44	 11
//  -5	 26
// -27	  3
//  90	 83
//  27	 43
// -72	 21
int main(int argc, char* argv[]) {
  point_set ps;

  int option;
  do {
    printMenu();
    std::cin >> option;

    switch (option) {
      case 1: {
        // Agregar arista
        double x, y;
        std::cout << "Ingrese las coordenadas de los puntos (x y): ";
        std::cin >> x >> y;
        ps.push_back(std::make_pair(x, y));
        std::cout << "Punto insertado correctamente." << std::endl << std::endl;
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

        CyA::point_vector points;
        file >> points;
        ps = point_set(points);
        file.close();
        std::cout << "Puntos insertados correctamente." << std::endl << std::endl;
        break;
      }
      case 3:
        // Calcular el árbol de expansión mínima
        ps.EMST();
        std::cout << "Árbol de expansión mínima calculado." << std::endl << std::endl;
        break;
      case 4:
        // Imprimir el coste del árbol de expansión mínima
        std::cout << "Coste del árbol de expansión mínima: " << ps.get_cost() << std::endl << std::endl;
        break;
      case 5: {
        // Guardar el grafo en formato DOT
        std::ofstream dotFile("graph.dot");
        ps.write_dot(dotFile);
        dotFile.close();
        std::cout << "Grafo guardado en formato DOT en 'graph.dot'" << std::endl << std::endl;
        break;
      }
      case 6: {
        // Generar PDF del grafo
        int result = system("neato graph.dot -Tpdf -o salida.pdf");
        if (result == 0) {
          std::cout << "PDF generado con éxito (ver 'salida.pdf')" << std::endl << std::endl;
        } else {
          std::cerr << "Error al generar el PDF"<< std::endl;
        }
        break;
      }
      case 7:
        // Salir
        std::cout << "Saliendo del programa." << std::endl;
        exit(EXIT_SUCCESS);
        break;
      case 8:
        // Imprimir puntos
        ps.write(std::cout);
        break;
      case 9:
        // Imprimir árbol de expansión mínima
        ps.write_tree(std::cout);
        break;
      default:
        std::cerr << "Error: Opción no válida. Inténtelo de nuevo." << std::endl ;
    }

  } while (option != 6);

  return 0;
}