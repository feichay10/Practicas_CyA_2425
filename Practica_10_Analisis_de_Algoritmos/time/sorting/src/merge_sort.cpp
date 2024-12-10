#include "merge_sort.hpp"

namespace ALGORITMIA
{
    // Función para mezclar(merge) dos subarreglos ordenados utilizando un vector auxiliar
        void merge(int *v, int *aux, int left, int mid, int right, size_t &n_comp, size_t &n_swap)
    {
        int i = left;    // Índice del subvector izquierdo
        int j = mid + 1; // Índice del subvetor derecho
        int k = left;    // Índice del vector auxiliar

        // Mezclar los subvectores ordenados
        while (i <= mid && j <= right)
        {
            ++n_comp; // Contar la comparación
            if (v[i] <= v[j])
            {
                aux[k++] = v[i++];
            }
            else
            {
                aux[k++] = v[j++];
            }
            ++n_swap; // Contar el movimiento
        }

        // Copiar los elementos restantes del subvector izquierdo
        while (i <= mid)
        {
            aux[k++] = v[i++];
            ++n_swap;
        }

        // Copiar los elementos restantes del subvector derecho
        while (j <= right)
        {
            aux[k++] = v[j++];
            ++n_swap;
        }

        // Copiar los elementos del vector auxiliar de vuelta al original
        for (k = left; k <= right; ++k)
        {
            v[k] = aux[k];
            ++n_swap; // Contar el movimiento
        }
    }

    // Función recursiva para Merge Sort
    void merge_sort(int *v, int *aux, int left, int right, size_t &n_comp, size_t &n_swap)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            // Ordenar la primera mitad
            merge_sort(v, aux, left, mid, n_comp, n_swap);
            // Ordenar la segunda mitad
            merge_sort(v, aux, mid + 1, right, n_comp, n_swap);
            // Mezclar las dos mitades
            merge(v, aux, left, mid, right, n_comp, n_swap);
        }
    }

    // Función principal para Merge Sort
    void merge_sort(int *v, size_t sz, size_t &n_comp, size_t &n_swap)
    {
        int *aux = new int[sz]; // Crear un vector auxiliar reutilizable
        n_comp = 0;             // Inicializar el contador de comparaciones
        n_swap = 0;             // Inicializar el contador de movimientos
        merge_sort(v, aux, 0, sz - 1, n_comp, n_swap);
        delete[] aux; // Liberar el vector auxiliar
    }
}