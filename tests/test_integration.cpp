#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

static bool close(double a, double b) {
    return std::fabs(a - b) < 1e-9;
}

int main() {
    int data[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    const std::size_t n = sizeof(data) / sizeof(data[0]);
    assert(arr_sum(data, n) == 45);
    assert(arr_max(data, n) == 9);
    assert(arr_min(data, n) == 1);
    assert(close(arr_average(data, n), 5.0));
    assert(arr_average(data, n) >= arr_min(data, n));
    assert(arr_average(data, n) <= arr_max(data, n));

    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    assert(close(arr_median(sorted, 7), 4.0));

    // End-to-end assertions for variant 07 data.
    int grades[] = {4, 5, 3, 4, 5, 5, 4, 3, 4, 5};
    assert(close(arr_average(grades, 10), 4.2));
    assert(arr_min(grades, 10) == 3);
    assert(arr_max(grades, 10) == 5);
    assert(close(arr_median(grades, 10), 4.0));

    std::cout << "[integration] All tests passed\n";
    return 0;
}
