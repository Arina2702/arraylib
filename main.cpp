#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    const int data[] = {-5, 0, 3, 3, 8, -2};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    std::cout << "Array: ";
    for (std::size_t i = 0; i < n; ++i) {
        if (i != 0) std::cout << ' ';
        std::cout << data[i];
    }
    std::cout << '\n' << std::fixed << std::setprecision(2)
              << "Sum: " << arr_sum(data, n) << '\n'
              << "Max: " << arr_max(data, n) << '\n'
              << "Min: " << arr_min(data, n) << '\n'
              << "Average: " << arr_average(data, n) << '\n'
              << "Positive: " << arr_count_positive(data, n) << '\n'
              << "Negative: " << arr_count_negative(data, n) << '\n'
              << "Zero: " << arr_count_zero(data, n) << '\n'
              << "Product: " << arr_product(data, n) << '\n'
              << "Median: " << arr_median(data, n) << '\n';
    return 0;
}
