#include "test_bench.hpp"

#include <cstddef>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "bubble_sort.hpp"
#include "quick_sort.hpp"
#include "shell_sort.hpp"
#include "merge_sort.hpp"

namespace ALGORITMIA
{
    test_bench::test_bench(size_t sz) : sz(sz)
    {
        data = new int[sz];
        srand(static_cast<unsigned>(time(0)));
    }

    test_bench::~test_bench()
    {
        delete[] data;
    }

    void test_bench::run_tests(std::ostream &os, size_t n_tests)
    {
        for (size_t i{0}; i < n_tests; ++i)
        {
            fill_random_(data, sz);

            os << std::setw(8) << sz << "\t";

            // Prueba de Bubble Sort
            {
                size_t n_comp{0};
                size_t n_swap{0};
                run_and_print_(os, bubble_sort, data, sz, n_comp, n_swap);
            }

            // Prueba de Merge Sort
            {
                size_t n_comp{0};
                size_t n_swap{0};
                run_and_print_(os, merge_sort, data, sz, n_comp, n_swap);
            }

            // Prueba de Shell Sort
            {
                size_t n_comp{0};
                size_t n_swap{0};
                run_and_print_(os, shell_sort, data, sz, n_comp, n_swap);
            }

            // Prueba de Quick Sort
            {
                size_t n_comp{0};
                size_t n_swap{0};
                run_and_print_(os, quick_sort, data, sz, n_comp, n_swap);
            }

            os << std::endl;
        }
    }

    template <typename SortFunc>
    void test_bench::run_and_print_(std::ostream &os, SortFunc sort_func, int *v, size_t sz, size_t &n_comp, size_t &n_swap)
    {
        auto *v_copy = new int[sz];
        std::copy(v, v + sz, v_copy); // Copia para cada ejecución

        auto start = std::chrono::high_resolution_clock::now();
        sort_func(v_copy, sz, n_comp, n_swap);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;

        os << std::setw(10) << n_comp << "\t";
        os << std::setw(10) << n_swap << "\t";
        os << std::setw(14) << std::fixed << std::setprecision(10) << duration.count() << "\t";

        delete[] v_copy;
    }

    void test_bench::fill_random_(int *v, size_t sz, int min, int max)
    {
        for (size_t i = 0; i < sz; ++i)
        {
            v[i] = min + rand() % (max - min + 1);
        }
    }
}