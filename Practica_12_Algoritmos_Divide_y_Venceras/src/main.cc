/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 12: Algoritmos Divide y Vencerás (Divide & Conquer). Cálculo de la
 * envoltura convexa.
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

#include <fstream>
#include <iostream>

#include "../include/point_set.h"
#include "../include/point_types.h"

using namespace CyA;

/**
 * @brief Imprime las opciones del menú en la salida estándar.
 *
 * Esta función muestra una lista de opciones que el usuario puede seleccionar.
 * Las opciones incluyen:
 *   0. Salir del programa.
 *   1. Agregar un punto con el formato: x y.
 *   2. Insertar puntos desde un archivo.
 *   3. Imprimir todos los puntos.
 *   4. Imprimir la envoltura convexa.
 *   5. Guardar el grafo en formato DOT.
 *   6. Generar un PDF del grafo.
 * Se le pide al usuario que seleccione una de estas opciones.
 */
void printMenu() {
  std::cout << "Opciones:\n"
            << "  0. Salir\n"
            << "  1. Agregar punto (Formato: x y)\n"
            << "  2. Insertar mediante fichero\n"
            << "  3. Imprimir puntos\n"
            << "  4. Imprimir envoltura convexa\n"
            << "  5. Guardar el grafo en formato DOT\n"
            << "  6. Generar PDF del grafo\n"
            // << "  7. Algoritmo original (EMST)\n"
            << "Seleccione una opción: ";
}

/**
 * @file main.cc
 * @brief Programa principal para gestionar un conjunto de puntos y realizar
 * varias operaciones sobre ellos.
 *
 * Este programa permite al usuario:
 * - Agregar puntos manualmente.
 * - Insertar puntos desde un archivo.
 * - Imprimir los puntos.
 * - Imprimir la envoltura convexa de los puntos.
 * - Guardar el grafo en formato DOT.
 * - Generar un PDF del grafo usando el archivo DOT.
 *
 * El programa proporciona una interfaz basada en menús para que el usuario
 * seleccione la operación deseada.
 *
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Array de argumentos de la línea de comandos.
 * @return int Estado de salida del programa.
 */
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
        std::cout << "\nPuntos insertados correctamente." << std::endl
                  << std::endl;
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
          std::cerr << "Error: No se pudo abrir el fichero." << std::endl
                    << std::endl;
          break;
        }
        file >> points;
        ps = point_set(points);
        file.close();
        std::cout << "\nPuntos insertados correctamente." << std::endl
                  << std::endl;
        isFile = true;
        break;
      }
      case 3:  // Imprimir puntos
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl
                    << std::endl;
        } else {
          ps.write(std::cout);
        }
        break;
      case 4:  // Imprimir
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl
                    << std::endl;
        } else {
          ps.write_hull(std::cout);
        }
        break;
      case 5: {  // Guardar el grafo en formato DOT
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl
                    << std::endl;
        } else {
          std::ofstream dotFile("graph.dot");
          ps.write_dot(dotFile);
          dotFile.close();
          std::cout << "\nGrafo guardado en formato DOT en 'graph.dot'"
                    << std::endl
                    << std::endl;
        }
        break;
      }
      case 6: {  // Generar PDF del grafo
        if (!isPoints && !isFile) {
          std::cerr << "Error: No hay puntos insertados." << std::endl
                    << std::endl;
        } else {
          int result = system("neato graph.dot -Tpdf -o salida.pdf");
          if (result == 0) {
            std::cout << "\nPDF generado con éxito (ver 'salida.pdf')"
                      << std::endl
                      << std::endl;
          } else {
            std::cerr << "\nError al generar el PDF" << std::endl << std::endl;
          }
        }
        break;
      }
      // case 7:
      //   if (!isPoints && !isFile) {
      //     std::cerr << "Error: No hay puntos insertados." << std::endl <<
      //     std::endl;
      //   } else {
      //     ps.quickHull();
      //     std::cout << "\nÁrbol de expansión mínima generado con éxito." <<
      //     std::endl << std::endl;
      //   }
      //   break;
      default:
        std::cerr << "\nError: Opción no válida. Inténtelo de nuevo."
                  << std::endl
                  << std::endl;
    }

  } while (option != 0);

  return 0;
}
