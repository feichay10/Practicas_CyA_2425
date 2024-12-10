#include <cstdio>
#include <iostream>
#include <iomanip>

#include "test_bench.hpp"

std::ostream &write_header(std::ostream &os)
{
    const size_t n_algorithms{4};

    os << std::setw(8) << " " << "\t";

    os << std::setw(34) << std::left << "Bubble sort" << "\t\t";
    os << std::setw(34) << std::left << "Merge sort"  << "\t\t";
    os << std::setw(34) << std::left << "Shell sort"  << "\t\t";
    os << std::setw(34) << std::left << "Quick sort"  << "\t\t";

    os << std::right << std::endl;

    os << std::setw(8) << "Size" << "\t";

    for (size_t i{0}; i < n_algorithms; ++i)
    {
        os << std::setw(10) << "#Comp" << "\t";
        os << std::setw(10) << "#Swap" << "\t";
        os << std::setw(14) << "Time (seconds)" << "\t";
    }

    os << std::endl;

    return os;
}

int main()
{

    const size_t base{100};
    const size_t limit{5000};
    const size_t step{100};

    const size_t n_tests{100};

    write_header(std::cout);

    for (size_t i{base}; i < limit; i += step)
    {
        ALGORITMIA::test_bench prueba(i);
        prueba.run_tests(std::cout, n_tests);
    }

    return 0;
}