#include "shell_sort.hpp"

#include <utility>

namespace ALGORITMIA
{

    void shell_sort(int *v, size_t sz, size_t &n_comp, size_t &n_swap)
    {
        n_comp = 0; // Inicializamos el contador de comparaciones
        n_swap = 0; // Inicializamos el contador de intercambios

        // Usamos una secuencia de intervalos decrecientes (gap sequence)
        for (size_t gap = sz / 2; gap > 0; gap /= 2)
        {
            for (size_t i = gap; i < sz; ++i)
            {
                int temp = v[i];
                size_t j = i;

                // Inserción de `v[i]` en el subarreglo con el intervalo `gap`
                while (j >= gap && v[j - gap] > temp)
                {
                    ++n_comp; // Contamos la comparación en cada iteración del while
                    v[j] = v[j - gap];
                    ++n_swap; // Contamos cada movimiento como un "intercambio"
                    j -= gap;
                }

                // Colocamos `temp` en su posición final
                if (j != i)
                {
                    ++n_comp; // Comparación final para verificar si j != i
                    v[j] = temp;
                    ++n_swap; // Cuenta el intercambio al colocar `temp` en su lugar
                }
            }
        }
    }
}