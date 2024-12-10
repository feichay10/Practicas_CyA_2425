#include "quick_sort.hpp"

#include <utility>

namespace ALGORITMIA
{

    void quick_sort(int *v, int left, int right, size_t &n_comp, size_t &n_swap)
    {
        if (left < right)
        {
            int pivotIndex = left + (right - left) / 2; // Selección del pivote en el medio
            int pivot = v[pivotIndex];
            int i{left};
            int j{right};

            while (i <= j)
            {
                while (v[i] < pivot)
                {
                    ++n_comp; // Contamos cada comparación
                    ++i;
                }
                while (v[j] > pivot)
                {
                    ++n_comp; // Contamos cada comparación
                    --j;
                }

                if (i <= j)
                {
                    ++n_comp; // Contamos la comparación de `i <= j`
                    if (i != j)
                    {
                        std::swap(v[i], v[j]);
                        ++n_swap; // Contamos el intercambio solo si i y j no apuntan al mismo elemento
                    }
                    ++i;
                    --j;
                }
            }

            quick_sort(v, left, j, n_comp, n_swap);  // Llamada recursiva para el subvector izquierdo
            quick_sort(v, i, right, n_comp, n_swap); // Llamada recursiva para el subvector derecho
        }
    }

    void quick_sort(int *v, size_t sz, size_t &n_comp, size_t &n_swap)
    {
        n_comp = 0; // Inicializamos el contador de comparaciones
        n_swap = 0; // Inicializamos el contador de intercambios
        quick_sort(v, 0, sz - 1, n_comp, n_swap);
    }
}