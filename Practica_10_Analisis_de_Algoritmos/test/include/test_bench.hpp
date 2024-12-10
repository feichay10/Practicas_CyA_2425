#pragma once

#include <cstddef>
#include <iostream>
#include <string>

#define L_LIMIT 1
#define U_LIMIT 9999

namespace ALGORITMIA
{

    // Función para inicializar un vector con números aleatorios entre 1 y 99

    // Clase TestBench para gestionar las pruebas de ordenación
    class test_bench
    {
    public:
        test_bench(size_t sz); 
        ~test_bench();
        void run_tests(std::ostream& os, size_t n_tests);

    private:
        int *data;
        size_t sz;

        template <typename SortFunc>
        void run_and_print_(std::ostream& os, SortFunc sortFunc, int *v, size_t sz, size_t &n_comp, size_t &n_swap);
        void fill_random_(int *v, size_t sz, int min = L_LIMIT, int max = U_LIMIT);        
    };

}