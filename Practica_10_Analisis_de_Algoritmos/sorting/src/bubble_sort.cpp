
#include "bubble_sort.hpp"

#include <utility>

namespace ALGORITMIA
{

    void bubble_sort(int *v, size_t sz, size_t &n_comp, size_t &n_swap)
    {
        n_comp = 0; // Inicializamos el contador de comparaciones
        n_swap = 0; // Inicializamos el contador de intercambios

        bool swapped{true};

        for (size_t i{0}; (i < sz - 1) && swapped; ++i)
        {
            swapped = false;
            for (size_t j{0}; j < sz - i - 1; ++j)
            {
                ++n_comp; // Contamos cada comparación
                if (v[j] > v[j + 1])
                {
                    std::swap(v[j], v[j + 1]);
                    ++n_swap; // Contamos cada intercambio
                    swapped = true;
                }
            }
        }
    }
}